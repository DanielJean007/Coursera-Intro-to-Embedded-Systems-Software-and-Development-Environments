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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      	You can basically create any intermidiate file in the building process.
# 	  	That is, you can create preprocessor files (*.i), assembly files (*.asm),
# 	   	dependency files (*.d), object files (*.o) and the fully built *.out file
# 	   	
# 		<FILE>.o - Builds <FILE>.o object file
# 		<FILE>.i - Generate the preprocessed output of the <FILE>.i
# 		<FILE>.asm - Generate assembly output of <FILE>.asm	
# 		compile-all : Compiles all files, but doesn't build them
# 		build: Compile all object files and link into a final executable
# 		clean: removes all generated files.
#
# Platform Overrides:
#      	In addition, you can create all those files for 2 difference platform.
# 
#		HOST 	- Generates for the virtual machine
# 		MSP432  - Generates for the arm microcontroller
#------------------------------------------------------------------------------
PLATFORM = HOST
VERBOSE_MODE = VERBOSE
COURSE_MODE = COURSE1

include sources.mk


# Platform Overrides
ifeq ($(PLATFORM), HOST)
	CC = gcc
	SIZE = size
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LINKER_FILE = msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CPU = cortex-m4
	ARCH = 	thumb
	SPECS = nosys.specs
	FPU = fpv4-sp-d16
	ARMFLAGS = 	-mcpu=$(CPU) \
				-m$(ARCH) \
				--specs=$(SPECS) \
				-march=armv7e-m \
				-mfloat-abi=hard \
				-mfpu=$(FPU)
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size
endif

# General definitions
TARGET = src/course1
CFLAGS = 	-Wall -Werror -g -O0 -std=c99 \
			-D$(PLATFORM) $(ARMFLAGS) \
			-D$(VERBOSE_MODE) -D$(COURSE_MODE)
CPPFLAGS = -E
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

# Recipes
%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out  $(TARGET).asm

$(TARGET).out: $(OBJS) $(DEPS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	rm -f src/*.o src/*.out src/*.asm src/*.d src/*.i src/*.map