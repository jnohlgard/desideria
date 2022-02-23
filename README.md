Experiments in bare metal code.

RISC-V is the only architecture currently implemented.

Building
========

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

Supported boards
================

Working:

 - Seeedstudio GD32VF1 development board
 - Sipeed Longan Nano
 - Sparkfun Red-V Redboard

In progress:

 - Bouffalo Labs BL702 (XT-ZB1 dev board)
 - Bouffalo Labs BL602
 - Hosted environment (running as a Linux executable)

Future:

 - ARM?
 - ESP32-C3

Repository layout
=================

The repository directory tree is organized as follows:

- `arch/` contains code for a specific CPU architecture, such as thread context switching code.
- `bsp/` contains code specific to each particular board, primarily pin configurations and onboard devices.
- `core/` contains platform-independent code for the core kernel features
- `dev/` contains device drivers
- `examples/` contains code usage examples
- `include/` contains some useful header files that are usable without anything from `core` or other Desideria code
- `lib/` contains third-party libraries
- `soc/` code specific to a chip or chip family, but that can be shared across all boards with that chip
- `svd/` contains hardware descriptions used for generating the MMIO headers
- `sys/` contains libraries that are useful to applications but not required by the core kernel
- `test/` contains automated tests to run on devices
- `tools/` contains host side tools
