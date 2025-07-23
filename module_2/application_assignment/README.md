# Week 2 Application Assignment  
**Makefile and Build System for Cross-Platform Compilation**

This project is the second assignment of Module 2 in the *Introduction to Embedded Systems Software and Development Environments* course (Coursera – University of Colorado Boulder, Prof. Alex Fosdick).

The goal of the assignment is to create a command-line build system using GNU tools like GCC and Make, enabling compilation for both the host platform and the embedded MSP432 platform.

## What the Program Does

The program sets up a build environment that:

- **Compiles multiple C source files** using GCC.
- **Supports two platforms**: the native host system and the embedded MSP432 system.
- **Generates various output files**, including object (`.o`), dependency (`.d`), preprocessed (`.i`), assembly (`.asm`), executable (`.out`), and map (`.map`) files.
- **Implements build targets** such as `compile-all`, `build`, `clean`, and pattern rules like `%.i`, `%.asm`, and `%.o`.
- **Conditionally switches build behavior** based on the `PLATFORM` macro (`HOST` or `MSP432`) for native or cross compilation.
- **Generates code size reports** using the appropriate `size` tool.
- **Produces a final executable named `c1m2.out`**, which can be run natively with `./c1m2.out` on the host platform.

## Files Included

- `include/`
  - `CMSIS/` – ARM architecture headers.
  - `common/` – Shared header files including `memory.h`, `platform.h`, etc.
  - `msp432/` – MSP432 platform-specific headers.

- `src/`
  - `interrupts_msp432p401r_gcc.c` – MSP432-specific interrupt vector implementation.
  - `main.c` – Main application logic.
  - `Makefile` – Main Make configuration for building the project.
  - `memory.c` – Memory management and I/O abstraction.
  - `sources.mk` – Lists the source files and directories per platform.
  - `startup_msp432p401r_gcc.c` – MSP432 startup code.
  - `system_msp432p401r.c` – System-level MSP432 initialization.

- `msp432p401r.lds` – Linker script used for MSP432 target builds.
- `README.md` – Project description and metadata (this file).

## Author

Developed by **Oriol Escolà Serra** as part of the course requirements.
