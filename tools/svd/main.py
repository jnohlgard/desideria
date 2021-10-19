import argparse
import os
import re
import sys

import xml.etree.ElementTree as ET

import pysvd

indent_step = '  '

"""
Create header files for use in Desideria based on an SVD file for a microcontroller

Resulting namespace design:

deri::mmio {
  class GPIO_regs
  class UART_regs  
  class ADC_regs
  ...
  GPIO_regs GPIOA
  GPIO_regs GPIOB
  UART_regs UART0
  UART_regs UART1
  ADC_regs ADC0
  ...
}

file layout:

svd-out/
 |- {CPU.name}_mmio.ld
 |- include/deri/mmio/
 |   |- bits/
 |   |   |- ADC_bits.hpp // Register bitmasks for the ADC peripheral
 |   |   |- GPIO_bits.hpp
 |   |   |- UART_bits.hpp
 |   |- ADC.hpp // Struct definitions for the ADC peripheral
 |   |- GPIO.hpp
 |   |- UART.hpp
 |   |- peripherals.hpp // extern declarations of all MMIO peripherals
 |   '- ...
 |- 


The xyz.hpp files provide the struct definitions so that drivers can inherit from that
The xyz_bits.hpp files are only needed for drivers interacting directly with the register bitfields.
"""


def increase_indent(indent):
    return indent + indent_step


def decrease_indent(indent):
    return indent[:-len(indent_step)]


def strip_instance_numbering(name):
    """Removing instance numbering or array notations from the end of a name"""
    name = re.sub(r'(\[\d*\])|(\d*)$', r'', name)
    return name


def strip_array_dimensions(name):
    """Removing instance numbering or array notations from the end of a name"""
    name = re.sub(r'(\[\d*\])$', r'', name)
    return name


def periph_struct(name):
    """Provide the struct type name for the given peripheral"""
    return f'{strip_array_dimensions(name)}_regs'


def reg_enum(name):
    """Provide the enum type name for the given register"""
    return f'{strip_array_dimensions(name)}_bits'


def reg_type_name(periph_type_names):
    """Provide the full type name for the given nested struct names"""
    return "::".join([periph_struct(name) for name in periph_type_names])


def write_heading_comment(output):
    output.write(f"/* *** Generated with Desideria SVD converter *** */\n")


def write_ldscript(output, device):
    """
    Create a linker script for the base addresses of the hardware modules in the given SVD

    :param device: Hardware description
    :param output: Writable for the formatted text output
    """
    write_heading_comment(output)
    output.write(f"/* Hardware module map for {device.name} */\n")
    output.write(f"/* {device.description} */\n")
    for peripheral in device.peripherals:
        output.write(f"PROVIDE({f'{peripheral.name}$':10}= {peripheral.baseAddress:#08x})\n")


def write_enum_definitions(output, periph, periph_type_names, indent=''):
    """
    Generate all bit masks for a given peripheral

    :param output: Writable for the formatted text output
    :param periph: device peripheral description
    """
    for reg in sorted(periph.registers + periph.clusters, key=lambda obj: obj.addressOffset):
        if hasattr(reg, 'registers'):
            write_enum_definitions(output, reg, periph_type_names + [strip_array_dimensions(reg.name)])
            continue
        enum_type_name = f'{reg_type_name(periph_type_names)}::{reg_enum(reg.name)}'
        output.write(f'{indent}/**\n')
        output.write(f'{indent} * Bitmasks for {"_".join(periph_type_names)} {reg.name}\n')
        if len(reg.description) > 0:
            output.write(f'{indent} *\n')
            output.write(f'{indent} * {reg.description}\n')
        output.write(f'{indent} */\n')
        output.write(f'{indent}enum class {enum_type_name} : uint{reg.size}_t {{\n')
        indent = increase_indent(indent)
        reserved_mask = (1 << reg.size) - 1
        for field in reg.fields:
            bitmask = '1'
            field_name = field.name
            if field.bitWidth > 1:
                bitmask = f'{(1 << field.bitWidth) - 1:#x}'
                field_name = f'{field.name}_mask'
            # reflow description text to remove newlines and indentation
            description = ' '.join([s.strip() for s in field.description.splitlines()])
            output.write(f'{indent}{field_name:<10} = ({bitmask} << {field.bitOffset:>2}), ///< {description}\n')
            reserved_mask &= ~(int(bitmask, 0) << field.bitOffset)
        if reserved_mask != 0:
            output.write(
                f'{indent}Reserved_mask = {format(reserved_mask, f"#0{reg.size // 4 + 2}x")} ///< All reserved bits\n')
        indent = decrease_indent(indent)
        output.write(f'{indent}}};\n')
        output.write(f'{indent}void HasBitwiseOperators({enum_type_name});\n\n')


def write_field_accessors(output, enum_type_name, field, indent=''):
    underlying_type = f'uint{field.parent.size}_t'
    output.write(
        f'{indent}static {enum_type_name} {strip_instance_numbering(field.parent.name)}_{field.name}({underlying_type} val) {{\n')
    indent = increase_indent(indent)
    output.write(
        f'{indent}return static_cast<{enum_type_name}>((val << {field.bitOffset}) & static_cast<{underlying_type}>({enum_type_name}::{field.name}));\n')
    indent = decrease_indent(indent)
    output.write(f'{indent}}}\n')


def write_element_padding(output, offset_from, offset_to, word_size, step_size, indent, reserved_count):
    offset = offset_from
    word_size_bytes = (word_size + 7) // 8
    if offset // word_size_bytes < offset_to // word_size_bytes:
        while offset % word_size_bytes != 0:
            alignment_missing = offset % word_size_bytes
            reserved_bytes = 1
            if alignment_missing & -alignment_missing == alignment_missing:
                # alignment_missing is a power of two
                reserved_bytes = alignment_missing
            output.write(f'{indent}const Reserved<uint{reserved_bytes * 8}_t> reserved_{reserved_count};\n')
            offset += reserved_bytes
            reserved_count += 1

        padding_length = offset_to // word_size_bytes - offset // word_size_bytes
        if padding_length > 0:
            output.write(
                f'{indent}const Reserved<uint{word_size}_t> reserved_{reserved_count}{f"[{padding_length}]" if padding_length > 1 else ""};\n')
            offset += padding_length * word_size_bytes
            reserved_count += 1
        output.write(f'{indent}// Base + {offset:#x}\n')

    while offset < offset_to:
        output.write(f'{indent}const Reserved<uint{step_size}_t> reserved_{reserved_count};\n')
        offset += step_size // 8
        reserved_count += 1

    return (offset, reserved_count)


def write_periph_class(output, periph, name=None, indent=''):
    """
    Generate a struct definition for the given peripheral

    :param periph: device peripheral description
    :param output: Writable for the formatted text output
    :param name: Name of the struct, default={periph_typename(periph)}'
    :param indent: current indentation
    """
    if name is None:
        name = periph_struct(periph.name)
    output.write(f'{indent}struct {name} {{\n')
    indent = increase_indent(indent)
    periph_size_bytes = (periph.size + 7) // 8
    offset = 0
    reserved_count = 0
    for reg in sorted(periph.registers, key=lambda obj: obj.addressOffset):
        write_enum_declaration(output, reg, indent)
    output.write('\n')
    for reg in sorted(periph.registers + periph.clusters, key=lambda obj: obj.addressOffset):
        constness = 'const ' if reg.access == reg.access.read_only else ''
        (offset, reserved_count) = write_element_padding(output, offset, reg.addressOffset, periph.size, reg.size,
                                                         indent, reserved_count)

        if hasattr(reg, 'registers'):
            cluster_type_name = periph_struct(strip_array_dimensions(reg.name))
            write_periph_class(output, reg, cluster_type_name, indent)
            output.write(f'{indent}{constness}{cluster_type_name} {reg.name};\n')
        else:
            output.write(f'{indent}{constness}Register<{reg_enum(reg.name)}> {reg.name};\n')

        offset += reg.size // 8

    indent = decrease_indent(indent)
    output.write(f'{indent}}};\n')


def write_periph_declaration(output, type_name, instance_name):
    """Generate a declaration for a peripheral"""
    output.write(f'extern {type_name}_regs {instance_name};\n')


def write_regs_declaration(output, type_name):
    """Generate a declaration for a peripheral struct"""
    output.write(f'struct {type_name}_regs;\n')


def write_enum_declaration(output, reg, indent=''):
    """Generate a declaration for a register"""
    output.write(f'{indent}enum class {reg.name}_bits : uint{reg.size}_t;\n')


def write_struct_offsetof_static_asserts(output, periph, periph_type_names):
    """Generate static asserts for ensuring the correct offset of each member element of a peripheral"""
    for reg in periph.registers + periph.clusters:
        output.write(
            f'static_assert(offsetof({reg_type_name(periph_type_names)}, {strip_array_dimensions(reg.name)}) == {reg.addressOffset:#x};\n')
    for cluster in periph.clusters:
        cluster_type_name = periph_struct(strip_array_dimensions(cluster.name))
        write_struct_offsetof_static_asserts(output, cluster, periph_type_names + [strip_array_dimensions(reg.name)])


def write_interrupts_enum(output, device):
    interrupt_map = {}
    indent = ''
    for periph in device.peripherals:
        for irq in periph.interrupts:
            if irq.value in interrupt_map and interrupt_map[irq.value].name != irq.name:
                raise RuntimeError(f'Duplicate IRQ {irq.value} {interrupt_map[irq.value].name} <-> {irq.name}')
            interrupt_map[irq.value] = irq
    output.write(f'{indent}enum class IRQ {{\n')
    indent = increase_indent(indent)
    for num, irq in sorted(interrupt_map.items(), key=lambda item: item[0] ):
        output.write(f'{indent}{irq.name} = {num},\n')
    indent = decrease_indent(indent)
    output.write(f'{indent}}};\n')


def generate_all_files(device, basedir):
    ld_path = os.path.join(basedir, 'ld')
    include_path = os.path.join(basedir, 'include', 'deri', 'mmio')
    bits_path = os.path.join(include_path, 'bits')
    os.makedirs(ld_path, exist_ok=True)
    with open(os.path.join(ld_path, f'{device.name}_mmio.ld'), 'w') as fd:
        write_ldscript(fd, device)

    periph_types = {}
    for periph in filter(lambda periph: periph.derivedFrom is None, device.peripherals):
        name = strip_instance_numbering(periph.name)
        periph_types.setdefault(name, periph)
        periph.deri_typename = name
    for periph in filter(lambda periph: periph.derivedFrom is not None, device.peripherals):
        # TODO: detect if a derived peripheral is not an exact copy, i.e. when there are overrides outside of the name property
        baseperiph = periph.derivedFrom
        name = strip_instance_numbering(baseperiph.name)
        if name == baseperiph.name:
            # Ugly attempt to strip letter instance indices, like GPIOA, PORTB etc.
            if len(name) > 1:
                name = name[:-1]
        if baseperiph.name in periph_types and name not in periph_types:
            # Remap to a better name
            del periph_types[baseperiph.name]
        # only assign if the key does not exist
        periph_types.setdefault(name, baseperiph)
        baseperiph.deri_typename = name

    os.makedirs(include_path, exist_ok=True)
    os.makedirs(bits_path, exist_ok=True)
    for name, periph in periph_types.items():
        print(f'Generating class definition for {name} from {periph.name}')
        with open(os.path.join(include_path, f'{name}.hpp'), 'w') as fd:
            write_heading_comment(fd)
            fd.write(f'#include "deri/registers.h"\n')
            fd.write(f'#include <cstdint>\n')
            fd.write(f'\nnamespace deri::mmio {{\n')
            write_periph_class(fd, periph)
            fd.write(f'}}\n')
        with open(os.path.join(bits_path, f'{name}_bits.hpp'), 'w') as fd:
            write_heading_comment(fd)
            fd.write(f'#include "deri/mmio/{name}.hpp"\n')
            fd.write(f'#include <cstdint>\n')
            fd.write(f'\nnamespace deri::mmio {{\n')
            write_enum_definitions(fd, periph, [name])
            write_struct_offsetof_static_asserts(fd, periph, [name])
            fd.write(f'}}\n')

    with open(os.path.join(include_path, f'peripherals.hpp'), 'w') as fd:
        write_heading_comment(fd)
        fd.write(f'\n// Forward declarations of MMIO peripheral register maps\n')
        for name, periph in periph_types.items():
            write_regs_declaration(fd, name)
        fd.write(f'\n// MMIO peripheral instances\n')
        fd.write(f'// These symbols need to be provided by the linker scripts\n')
        for periph in device.peripherals:
            basename = periph.derivedFrom.deri_typename if periph.derivedFrom is not None else periph.deri_typename
            write_periph_declaration(fd, basename, periph.name)

    with open(os.path.join(include_path, f'interrupts.hpp'), 'w') as fd:
        write_heading_comment(fd)
        fd.write(f'\nnamespace deri::mmio {{\n')
        write_interrupts_enum(fd, device)
        fd.write(f'}}\n')


def dir_argument(path):
    """Argparse helper for specifying an output directory"""
    if os.path.isdir(path):
        return path
    elif not os.path.exists(path):
        # try to create the directory
        os.mkdir(path)
        return path
    else:
        raise argparse.ArgumentTypeError(f"{path} is not a directory")


def main(argv):
    parser = argparse.ArgumentParser(description='Generate C++ headers from an SVD file.')
    parser.add_argument('-i', '--input', type=argparse.FileType('r'),
                        default=(None if sys.stdin.isatty() else sys.stdin), required=sys.stdin.isatty())
    parser.add_argument('-p', '--path', type=dir_argument,
                        default='./svd-out')
    args = parser.parse_args(argv[1:])

    node = ET.parse(args.input).getroot()
    device = pysvd.element.Device(node)

    generate_all_files(device, args.path)
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
