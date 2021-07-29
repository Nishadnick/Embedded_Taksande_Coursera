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

# Add your Source files to this variable
#SOURCES = \m2\src\interrupts_msp432p401r_gcc.c/
#\m2\src\main.c/
#\m2\src\Makefile/
#\m2\src\memory.c/
#\m2\src\sources.mk/
#\m2\src\startup_msp432p401r_gcc.c/
#\m2\src\system_msp432p401r.c

# Add your include paths to this variable
#INCLUDES = \m2\include\CMSIS\cmsis_gcc.h/
#\m2\include\CMSIS\core_cm4.h/
#\m2\include\CMSIS\core_cmFunc.h/
#\m2\include\CMSIS\core_cmInstr.h/
#\m2\include\CMSIS\core_cmSimd.h/

#m2\include\common\memory.h/
#m2\include\common\platform.h/

#m2\include\msp432\msp_compatibility.h/
#m2\include\msp432\msp432p401r.h/
#m2\include\msp432\system_msp432p401r.h


#echo "Please specify the Platform..[HOST or MSP432]"

ifeq ($(PLATFORM),MSP432)
	SOURCES = ../src/interrupts_msp432p401r_gcc.c \
		../src/main.c \
		../src/Makefile \
		../src/memory.c \
		../src/sources.mk \
		../src/startup_msp432p401r_gcc.c \
		../src/system_msp432p401r.c

	INCLUDES = ../include/CMSIS/cmsis_gcc.h \
		../include/CMSIS/core_cm4.h \
		../include/CMSIS/core_cmFunc.h \
		../include/CMSIS/core_cmInstr.h \
		../include/CMSIS/core_cmSimd.h \
		../include/common/memory.h \
		../include/common/platform.h \
		../include/msp432/msp_compatibility.h \
		../include/msp432/msp432p401r.h \
		../include/msp432/system_msp432p401r.h

else ifeq ($(PLATFORM), HOST)
	SOURCES=../src/main.c \
		../src/Makefile \
		../src/memory.c \
		../src/sources.mk

	INCLUDES=../include/common/memory.h \
		../include/common/platform.h
else
	"Please Provide an available PLATFORM "
endif