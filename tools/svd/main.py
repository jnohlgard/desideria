import argparse
import re
import sys

import xml.etree.ElementTree as ET

import pysvd

indent_step = '  '


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


def periph_typename(periph):
    """Provide the struct type name for the given peripheral"""
    return f'{strip_instance_numbering(periph.name)}_periph'


def write_ldscript(output, device):
    """
    Create a linker script for the base addresses of the hardware modules in the given SVD

    :param device: Hardware description
    :param output: Writable for the formatted text output
    """
    output.write(f"/* *** Generated with Desideria SVD converter *** */\n")
    output.write(f"/* Hardware module map for {device.name} */\n")
    output.write(f"/* {device.description} */\n")
    for peripheral in device.peripherals:
        output.write(f"PROVIDE({peripheral.name}$ = {peripheral.baseAddress:#08x})\n")


def write_enum_values(output, reg, indent=''):
    """
    Generate all bit masks for a given register

    :param reg: device register description
    :param output: Writable for the formatted text output
    """
    enum_type_name = f'{reg.name}_bits'
    output.write(f'{indent}/** {strip_instance_numbering(reg.name)} {reg.name} */\n')
    output.write(f'{indent}enum class {enum_type_name} : uint{reg.size}_t {{\n')
    indent = increase_indent(indent)
    for field in reg.fields:
        bitmask = '1'
        field_name = field.name
        if field.bitWidth > 1:
            bitmask = f'{(1 << field.bitWidth) - 1:#x}'
            field_name = f'{field.name}_mask'
        # reflow description text to remove newlines and indentation
        description = ' '.join([s.strip() for s in field.description.splitlines()])
        output.write(f'{indent}{field_name:<10} = ({bitmask} << {field.bitOffset:>2}), ///< {description}\n')
    indent = decrease_indent(indent)
    output.write(f'{indent}}};\n')
    output.write(f'{indent}void HasBitwiseOperators({enum_type_name});\n')


def write_field_accessors(output, enum_type_name, field, indent=''):
    underlying_type = f'uint{field.parent.size}_t'
    output.write(
        f'{indent}static {enum_type_name} {strip_instance_numbering(field.parent.name)}_{field.name}({underlying_type} val) {{\n')
    indent = increase_indent(indent)
    output.write(
        f'{indent}return static_cast<{enum_type_name}>((val << {field.bitOffset}) & static_cast<{underlying_type}>({enum_type_name}::{field.name}));\n')
    indent = decrease_indent(indent)
    output.write(f'{indent}}}\n')


def write_periph_class(output, periph, name=None, indent=''):
    """
    Generate a struct definition for the given peripheral

    :param periph: device peripheral description
    :param output: Writable for the formatted text output
    :param name: Name of the struct, default={periph_typename(periph)}'
    :param indent: current indentation
    """
    if name is None:
        name = periph_typename(periph)
    output.write(f'{indent}struct {name} {{\n')
    indent = increase_indent(indent)
    periph_size_bytes = (periph.size + 7) // 8
    offset = 0
    reserved_count = 0
    for reg in sorted(periph.registers + periph.clusters, key=lambda obj: obj.addressOffset):
        constness = 'const ' if reg.access == reg.access.read_only else ''
        if offset // periph_size_bytes < reg.addressOffset // periph_size_bytes:
            while offset % periph_size_bytes != 0:
                output.write(f'{indent}const Reserved<uint8_t> reserved_{reserved_count};\n')
                offset += 1
                reserved_count += 1

            padding_length = reg.addressOffset // periph_size_bytes - offset // periph_size_bytes
            if padding_length > 0:
                output.write(
                    f'{indent}const Reserved<uint{periph.size}_t> reserved_{reserved_count}[{padding_length}];\n')
                offset += padding_length * periph_size_bytes
                reserved_count += 1
            output.write(f'{indent}// Base + {offset:#x}\n')

        while offset < reg.addressOffset:
            output.write(f'{indent}const Reserved<uint{reg.size}_t> reserved_{reserved_count};\n')
            offset += reg.size // 8
            reserved_count += 1

        if hasattr(reg, 'clusters'):
            cluster_type_name = f'{strip_instance_numbering(reg.name)}_cluster'
            write_periph_class(output, reg, cluster_type_name, indent)
            output.write(f'{indent}{constness}{cluster_type_name} {reg.name};\n')
        else:
            output.write(f'{indent}{constness}Register<{strip_instance_numbering(reg.name)}_bits> {reg.name};\n')

        offset += reg.size // 8
    indent = decrease_indent(indent)
    output.write(f'{indent}}};\n')


def write_periph_declaration(output, periph):
    """Generate a declaration for a peripheral"""
    output.write(f'extern {periph_typename(periph)} {periph.name};\n')


def write_struct_offsetof_static_asserts(output, periph):
    """Generate static asserts for ensuring the correct offset of each member element of a peripheral"""
    for reg in periph.registers + periph.clusters:
        output.write(f'static_assert(offsetof({periph_typename(periph)}, {strip_array_dimensions(reg.name)}) == {reg.addressOffset:#x};\n')


def main(argv):
    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument('-i', '--input', type=argparse.FileType('r'),
                        default=(None if sys.stdin.isatty() else sys.stdin), required=sys.stdin.isatty())
    parser.add_argument('-o', '--output', type=argparse.FileType('w'),
                        default=sys.stdout)
    args = parser.parse_args(argv[1:])

    node = ET.parse(args.input).getroot()
    device = pysvd.element.Device(node)
    write_periph_class(args.output, device.find('ECLIC'))
    write_struct_offsetof_static_asserts(args.output, device.find('ECLIC'))

    write_ldscript(args.output, device)

    for reg in sorted(device.find('ECLIC').registers,
                      key=lambda obj: obj.addressOffset):
        write_enum_values(args.output, reg)

    return 0

    for periph in sorted(device.peripherals, key=lambda peripheral: peripheral.baseAddress):
        for reg in periph.registers:
            write_enum_values(args.output, reg)
    for periph in sorted(device.peripherals, key=lambda peripheral: peripheral.baseAddress):
        write_periph_class(args.output, periph)

    for periph in sorted(device.peripherals, key=lambda peripheral: peripheral.baseAddress):
        write_periph_declaration(args.output, periph)

    # for reg in parser.get_device().peripherals[22].registers:
    #     write_enum_values(args.output, reg)

    # write_periph_class(args.output, parser.get_device().peripherals[36])
    write_struct_offsetof_static_asserts(args.output, device.find('CAN0'))

    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
