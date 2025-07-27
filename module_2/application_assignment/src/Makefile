#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Build system for compiling and linking multiple source files for
# both HOST and MSP432 platforms using GCC and GNU Make.
#
# File: Makefile
# Author: Oriol Escolà Serra
# Date: 27/07/2025
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.i           - Generate preprocessed output from C source files
#      %.asm         - Generate assembly output from C source files
#      %.o           - Compile individual C source files to object files
#      compile-all   - Compile all object files without linking
#      build         - Compile and link all source files into the final 
#                      executable ($<EXECUTABLE>)
#      clean         - Remove all generated output and build files
#
# Platform Overrides:
#      PLATFORM=HOST     - Use native GCC compiler for host platform
#      PLATFORM=MSP432   - Use ARM cross-compiler for MSP432 target platform
#------------------------------------------------------------------------------

include sources.mk

# Executable
EXECUTABLE := c1m2.out
MAPFILE := c1m2.map

# Clean files
CLEANFILES := *.map *.out *.asm *.i *.d *.s *.o

ifeq ($(PLATFORM), MSP432)

# Architectures Specific Flags
LINKER_FILE = -T ../msp432p401r.lds                       # Linker script
CPU         = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH        = -march=armv7e-m                             # Architecture
SPECS       = -specs=nosys.specs                          # No system specs

# Compiler Flags and Defines
CC          = arm-none-eabi-gcc                            # Compiler
LD          = arm-none-eabi-gcc                            # Linker
LDFLAGS     = $(LINKER_FILE) $(CPU) $(ARCH) $(SPECS) -Wl-Map=$(MAPFILE)
CFLAGS      = -Wall -g -O0 -std=c99 $(CPU) $(ARCH) -MMD -MP # Compiler flags
CPPFLAGS    = -D$(PLATFORM) $(INCLUDES)                    # Preprocessor flags

# Tools
SIZE        = arm-none-eabi-size						   # Size command

else

# Compiler Flags and Defines
CC          = gcc                                          # Compiler
LD          = gcc                                          # Linker
LDFLAGS     =                                              # Linker flags
CFLAGS      = -Wall -Werror -g -O0 -std=c99 -MMD -MP       # Compiler flags
CPPFLAGS    = -D$(PLATFORM) $(INCLUDES)                    # Preprocessor flags

# Tools
SIZE        = size										   # Size command

endif

OBJS = $(SOURCES:.c=.o)

# Preprocessing
%.i : %.c
	$(CC) $(CPPFLAGS) -E $< -o $@

# Assembly
%.asm : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@

# Object files
%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Compile all
.PHONY: compile-all
compile-all: $(OBJS)

# Build
.PHONY: build
build: $(EXECUTABLE)
	@echo "\nMemory utilization for $(EXECUTABLE):"
	@$(SIZE) $(EXECUTABLE)
	@echo

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Clean
.PHONY: clean
clean:
	rm -f $(CLEANFILES)