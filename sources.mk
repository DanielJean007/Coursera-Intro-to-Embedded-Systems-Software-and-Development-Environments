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

# General source files used by both platforms
GSRC = 	src/main.c \
		src/memory.c \
		src/course1.c \
		src/data.c \
		src/stats.c

# Add your Source files to this variable
ifeq ($(PLATFORM), HOST)
	SOURCES = 	$(GSRC)
else
	SOURCES = 	$(GSRC) \
				src/interrupts_msp432p401r_gcc.c \
				src/startup_msp432p401r_gcc.c \
				src/system_msp432p401r.c
endif

# Add your include paths to this variable
ifeq ($(PLATFORM), HOST)
	INCLUDES =	-I./include/common/
else
	INCLUDES = 	-I./include/common/ \
				-I./include/CMSIS/ \
				-I./include/msp432/ 
endif

