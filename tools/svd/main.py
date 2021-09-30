import argparse
import sys

from cmsis_svd.parser import SVDParser


def periph_typename(periph):
    """Provide the struct type name for the given peripheral"""
    return f'{periph.group_name}_periph'


def write_ldscript(output, svd):
    """
    Create a linker script for the base addresses of the hardware modules in the given SVD

    :param svd: Hardware description
    :param output: Writable for the formatted text output
    """
    dev = svd.get_device()
    output.write(f"/* *** Generated with Desideria SVD converter *** */\n")
    output.write(f"/* Hardware module map for {dev.name} */\n")
    output.write(f"/* {dev.description} */\n")
    for peripheral in dev.peripherals:
        output.write(f"PROVIDE({peripheral.name}$ = {peripheral.base_address:#08x})\n")


def write_enum_values(output, reg):
    """
    Generate all bit masks for a given register

    :param reg: device register description
    :param output: Writable for the formatted text output
    """
    output.write(f'/** {reg.parent.group_name} {reg.name} */\n')
    output.write(f'enum class {reg.name}_bits : uint{reg.size}_t {{\n')
    for field in reg.fields:
        bitmask = '1'
        if field.bit_width > 1:
            bitmask = f'{(1 << field.bit_width) - 1:#x}'
        # reflow description text to remove newlines and indentation
        description = ' '.join([s.strip() for s in field.description.splitlines()])
        output.write(f'  {field.name:<10} = ({bitmask} << {field.bit_offset:>2}); ///< {description}\n')
    output.write('};\n')
    output.write(f'void HasBitwiseOperators({reg.name}_bits);\n\n')


def write_periph_class(output, periph):
    """
    Generate a struct definition for the given peripheral

    :param periph: device peripheral description
    :param output: Writable for the formatted text output
    """
    output.write(f'class {periph_typename(periph)} {{\n')
    for reg in periph.registers:
        output.write(f'  Register<{reg.name}_bits> {reg.name};\n')
    output.write('};\n')


def write_periph_declaration(output, periph):
    """Generate a declaration for a peripheral"""
    output.write(f'extern {periph_typename(periph)} {periph.name};\n')


def write_struct_offsetof_static_asserts(output, periph):
    """Generate static asserts for ensuring the correct offset of each member element of a peripheral"""
    for reg in periph.registers:
        output.write(f'static_assert(offsetof({periph_typename(periph)}, {reg.name}) == {reg.address_offset};\n')


def create_register_map(periph):
    memory = {}
    # The cmsis_svd generator approach does not work well when we want to define proper C arrays
    for reg in periph._registers:
        if reg.address_offset in memory:
            raise KeyError(f'Duplicate register at address {reg.address_offset}')
        memory[reg.address_offset] = reg
    for reg in periph._register_arrays:
        pass

def main(argv):
    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument('-i', '--input', type=argparse.FileType('r'),
                        default=(None if sys.stdin.isatty() else sys.stdin))
    parser.add_argument('-o', '--output', type=argparse.FileType('w'),
                        default=sys.stdout)
    args = parser.parse_args(argv[1:])

    parser = SVDParser.for_xml_file(args.input)
    write_ldscript(args.output, parser)

    peripheral_group_map = {}
    peripheral_map = {}
    for periph in parser.get_device().peripherals:
        if periph.group_name != '':
            peripheral_group_map[periph.group_name] = periph
        peripheral_map[periph.name] = periph

    write_struct_offsetof_static_asserts(args.output, peripheral_group_map['ECLIC'])
    return 0

    del peripheral_group_map['ECLIC']
    for periph in peripheral_group_map.values():
        for reg in periph.registers:
            write_enum_values(args.output, reg)
    for periph in peripheral_group_map.values():
        write_periph_class(args.output, periph)

    for periph in peripheral_map.values():
        write_periph_declaration(args.output, periph)

    # for reg in parser.get_device().peripherals[22].registers:
    #     write_enum_values(args.output, reg)

    # write_periph_class(args.output, parser.get_device().peripherals[36])
    write_struct_offsetof_static_asserts(args.output, parser.get_device().peripherals[36])

    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
