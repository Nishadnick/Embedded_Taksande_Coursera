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
# The Second Assignment where we populate the Sources.MK file and then Write a proper MakeFile. Makefile is a standard instructions file with the main aim of reducing redundant effort of supplying the same commands and options over and over for similar files with different funtions
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#	.o
#	.i				these are the files created 
#	.asm			at different stages of the process, 
#	.d 				their description is provided as per my 
#	.map 			understanding
#
#	.phony is used as virtual reference, i.e. the file doesn't exist
#	really but will be used to create other files with its refernece
# Platform Overrides:
#      build: thi will build all the files and connect it to the 
#	executable file that runs a program. i.e. c1m2.out
#	Compile: This will connect and replace elemens and variables,
#	 but will not link the file to the linker 

#		HOST = Variable for Native system
#		MSP432 = variable for ARM embedded target
#------------------------------------------------------------------------------

include sources.mk
# Platform Overrides/
#// ?= notation can be used to take input argument, so we could prompt it through 'echo'/
#PLATFORM ?= /
TARGET=c1m2

# Architectures Specific Flags/
#LINKER_FILE = msp432p401r.lds/

FLOAT-ABI = hard
FPU = fpv4-sp-d16
#//Size Tool
SIZE_TOOL = arm-none-eabi-size
#//Object Dump	
OBJ-DUMP = arm-none-eabi-objdump


# Compiler Flags and Defines
#CC = arm-none-eabi-gcc
#LD = arm-none-eabi-ld

CPPFLAG = -D$(PLATFORM) -M $(INCLUDES)
GEN_FLAGS =-Wall\
-Werror\
-g\
-O0\
-std=c99

ifeq ($(PLATFORM),MSP432)
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs	
#//we can use nosys.specs or none.specs or both here
	CC = arm-none-eabi-gcc
#//Complier of Targer machine
	LD = arm-none-eabi-ld
	LINKER_FILE = msp432p401r.lds
#//This will create Map file and link it to linker
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
#// CFLAGS will have all the necessary flags( even the General and Architecture specific ones)
	CFLAGS = $(GEN_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) \
	-mfloat-abi=$(FLOAT-ABI) -mfpu=$(FPU) -mthumb
#//PLAT_FLAGS = -DMSP432		#//using -D<MACRO-NAME>
	
else
	#//Native Compiler
	CC = gcc
	LD = ld
	ARCH := $(shell arch)
#//#//  $(shell command) is run to gather information of current system we're compiling on [it works outside of makefile!]
#// not sure if CPU and SPECS will run with this
	CPU := $(shell CPU)
	SPECS := $(shell SPECS)
	CFLAGS = -$(GEN_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
#//in case of NATIVE the linker file might not work (-T $(LINKER_FILE))
	LDFLAGS = -Wl,-Map=$(TARGET).map
#//	PLAT_FLAGS = -DHOST
endif



OBJS = $(SOURCES:.c=.o)
PREPRO_FILES = $(SOURCES:.c=.i)
ASM_FILES = $(SOURCES:.c=.asm)
DEPENDENT_FILE = $(SOURCES:.c=.dep)
MAP_FILE = $(SOURCES:.c=.map)

## Reference for Flags
##// https://gcc.gnu.org/onlinedocs/gcc-2.95.3/gcc_2.html#SEC4

#// this for Object files (but without linking) 
#// Question: should i use $(OBJS) here or is $(SOURCES) fine??
%.o : $(SOURCES)
	$(CC) -c $< $(CPPFLAG) $(CFLAGS) -o $@
	
#// this for preprocessed files, it does not move forward 
#// Question: should i use $(PREPRO_FILES) here or is $(SOURCES) fine??
%.i : $(SOURCES)
	$(CC) -E $< $(CPPFLAG) $(CFLAGS) -o $@
	
#// Question: should i use $(ASM_FILES) here or is $(SOURCES) fine??
%.asm : $(SOURCES)
	$(CC) -S $< $(CPPFLAG) $(CFLAGS) -o $@
#// we had to ise objectDump tool with the assembly file, hence..
	$(CC) $(OBJ-DUMP) -S -MD $< $(CPPFLAG) $(CFLAGS) -o $@
	
#// Question: should i use $(DEPENDENT_FILE) here or is $(SOURCES) fine??
%.d : $(SOURCES)
	$(CC) -c $< $(CPPFLAG) $(CFLAGS) -MD -o $@
	
#// Question: should i use $(MAP_FILE) here or is $(SOURCES) fine??
%.map : $(SOURCES)
	$(CC) -c $< $(CPPFLAG) $(CFLAGS) -o $@
	

#// This would create virtual file
.PHONY: build
build: all
#// This virtual file will be used to create the target output file i.e. (c1m2.out)..please let me know if this understanding is correct
.PHONY: all
all: $(TARGET).out
#//should this be $(OBJS) or $(SOURCES)
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAG) $(CFLAGS) $(LDFLAGS) -o $@ $(SIZE_TOOL)

#// i figured that cleaning every file that was created is only done to save the space, zc they can be 'created' again, right?
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.o *.i *.asm *.d *.map
	
	
#// If you could answer some of my queries then it'll be lifesaving deed
#// cz, i really want to understand this whole process but even after 
#//going through  the documents i am not able to just get it.
#
#When we are trying to creat a certain type of file, eg. preprocessed 
#file (*.i) or assembly file (*.asm) or Map file (*.map) etc.
#then how can we find out what files are needed to create any of these 
#above single files. i.e. how to find the dependencies of the above 
#mentioned files (*.i, *.asm, *.map, *.d etc)?
#
#if there is a simple explaination for the purpose of the above 
#files ((*.i, *.asm, *.map, *.d, *.o etc)) ? 
#why is it needed to create these files?
#
#How to know what flags to use for which kind of file? 
#and what in perticular a flag will do in a command? 
#
#does it matter if we order or position for the files and flags? 
#do they follow a specific order?