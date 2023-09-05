# NicOS
## What is NicOS?
NicOS is a simple x86 command line operating system that I am making for fun and to learn new things. 

## Building
Building the source code can be done with a gcc cross compiler, the compiler toolchain can be built from source code found [here](https://wiki.osdev.org/GCC_Cross-Compiler), or a prebuilt compiler can be found on the same page.
### Linux
To Build the source code on linux, just run `make`.
### Other OS's
No idea you can figure it out yourself.

## Running
To run the OS I recommend using [QEMU](https://www.qemu.org/), simply run `qemu-system-x86_64 -fda os-image.bin`
