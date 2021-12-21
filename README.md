Experiments in bare metal code.

RISC-V is the only architecture currently implemented.

Building
========

Only Longan Nano and Seeedstudio GD32VF1 dev board are working right now.

The preferred toolchain is the Sifive GNU embedded toolchain from https://www.sifive.com/software

Tested with CMake 3.21, might still work with 3.19 but not tested anymore.

```
cd desideria
cmake -S . -B build -G Ninja -DBOARD=longan -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-gnu-riscv64.cmake
cmake --build build
```

Flash using whatever tools you normally use. The binaries will be found under `./build/path/to/project`,
e.g. `./build/examples/hello_libc/example_hello_libc.elf`

There are .bin and .hex files as well for flash tools that do not support loading .elf files.
