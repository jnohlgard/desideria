# RISC-V control and status register definitions

Source: https://github.com/riscv/riscv-opcodes

Use the parse-opcodes script to generate the CSR definitions without
all the opcode encoding bloat.

    cp encoding.h ...vendor/encoding.h
    echo | ./parse-opcodes -c >> ...vendor/encoding.h
