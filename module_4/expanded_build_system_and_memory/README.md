# Course 1 Final Project
**Expanded Build System and Memory Manipulation**

This project is the **final assessment** for *Course 1: Introduction to Embedded Systems Software and Development Environments* (Coursera – University of Colorado Boulder, Prof. Alex Fosdick).

The assignment builds upon the work completed in Modules 1 and 2. It focuses on writing low-level C functions for memory and data manipulation, extending the build system, and simulating the application on the host machine. The repository structure is reorganized, and Git version control is used throughout.

## What the Program Does

The program implements and tests a series of memory and data manipulation functions written in C. These functions are integrated into a GCC and Make-based build system supporting both native (host) and embedded (MSP432) platforms.

Key features:

- **Memory manipulation functions**, such as `my_memmove`, `my_memcopy`, `my_memset`, `my_memzero`, and `my_reverse`, implemented using pointer arithmetic only.
- **Dynamic memory management** via `reserve_words()` and `free_words()`.
- **Data conversion utilities**, including `my_itoa()` and `my_atoi()` for integer-to-ASCII and ASCII-to-integer conversion in bases 2 to 16.
- **Conditional compilation** using flags like `COURSE1` and `VERBOSE` for platform-specific behavior and debug printing.
- **Unit testing functions** (e.g. `test_data1`, `test_memmove1`, etc.) that validate each feature through the `course1()` entry point.
- **Simulation on host machine** using the Makefile, with platform-agnostic compilation supported.

## Files Included

- `include/`
  - `CMSIS/` – ARM Cortex-M4 architecture headers used for low-level hardware access.
  - `common/` – Shared header files for platform abstraction and application logic.
    - `course1.h` – Header for the main course1 test runner functions.
    - `data.h` – Interface for integer-to-ASCII and ASCII-to-integer conversion functions.
    - `memory.h` – Interface for memory manipulation functions.
    - `platform.h` – Platform abstraction definitions and macros like `PRINTF`.
    - `stats.h` – Interface for basic statistical analysis and array functions.
  - `msp432/` – MSP432-specific headers required for embedded target compilation.

- `src/` – Source files implementing all core logic and platform-specific behavior.
  - `course1.c` – Final assessment entry point and test driver for memory/data functions.
  - `data.c` – Implementation of `my_itoa()` and `my_atoi()` conversions.
  - `interrupts_msp432p401r_gcc.c` – Interrupt vector table for the MSP432 platform.
  - `main.c` – Main entry point, conditionally calling `course1()`.
  - `memory.c` – Implementation of `my_memmove`, `my_memset`, `my_reverse`, etc.
  - `startup_msp432p401r_gcc.c` – Startup file for MSP432 platform initialization.
  - `stats.c` – Statistical calculations and debug-printable array utilities.
  - `system_msp432p401r.c` – System-level initialization for MSP432 platform.

- Root directory:
  - `Makefile` – Build system using GCC with support for `HOST` and `MSP432` platforms.
  - `msp432p401r.lds` – Linker script used when targeting the MSP432.
  - `sources.mk` – Source mapping file, organizes C files per platform for compilation.
  - `README.md` – Project description and metadata (this file).

## Author

Developed by **Oriol Escolà Serra** as part of the final project for the Coursera Embedded Systems course.
