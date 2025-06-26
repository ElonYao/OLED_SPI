################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../28003x_generic_ram_lnk.cmd 

SYSCFG_SRCS += \
../c2000.syscfg 

LIB_SRCS += \
C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib/ccs/Debug/driverlib.lib 

ASM_SRCS += \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/CCS/C2000_C28x/portasm.asm 

C_SRCS += \
../OLED_SPI.c \
./syscfg/board.c \
./syscfg/c2000ware_libraries.c \
./syscfg/c2000_freertos.c \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/tasks.c \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/queue.c \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/list.c \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/timers.c \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/event_groups.c \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/stream_buffer.c \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/CCS/C2000_C28x/port.c \
C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/MemMang/heap_4.c 

GEN_FILES += \
./syscfg/board.c \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt \
./syscfg/c2000ware_libraries.c \
./syscfg/c2000_freertos.c \
./syscfg/c2000_freertos.opt 

GEN_MISC_DIRS += \
./syscfg 

C_DEPS += \
./OLED_SPI.d \
./syscfg/board.d \
./syscfg/c2000ware_libraries.d \
./syscfg/c2000_freertos.d \
./tasks.d \
./queue.d \
./list.d \
./timers.d \
./event_groups.d \
./stream_buffer.d \
./port.d \
./heap_4.d 

GEN_OPTS += \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt \
./syscfg/c2000_freertos.opt 

OBJS += \
./OLED_SPI.obj \
./syscfg/board.obj \
./syscfg/c2000ware_libraries.obj \
./syscfg/c2000_freertos.obj \
./tasks.obj \
./queue.obj \
./list.obj \
./timers.obj \
./event_groups.obj \
./stream_buffer.obj \
./port.obj \
./portasm.obj \
./heap_4.obj 

ASM_DEPS += \
./portasm.d 

GEN_MISC_FILES += \
./syscfg/board.h \
./syscfg/board.cmd.genlibs \
./syscfg/board.json \
./syscfg/pinmux.csv \
./syscfg/c2000ware_libraries.cmd.genlibs \
./syscfg/c2000ware_libraries.h \
./syscfg/c2000_freertos.h \
./syscfg/FreeRTOSConfig.h \
./syscfg/c2000_freertos.cmd.genlibs \
./syscfg/syscfg_c.rov.xs \
./syscfg/clocktree.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg" 

OBJS__QUOTED += \
"OLED_SPI.obj" \
"syscfg\board.obj" \
"syscfg\c2000ware_libraries.obj" \
"syscfg\c2000_freertos.obj" \
"tasks.obj" \
"queue.obj" \
"list.obj" \
"timers.obj" \
"event_groups.obj" \
"stream_buffer.obj" \
"port.obj" \
"portasm.obj" \
"heap_4.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\board.h" \
"syscfg\board.cmd.genlibs" \
"syscfg\board.json" \
"syscfg\pinmux.csv" \
"syscfg\c2000ware_libraries.cmd.genlibs" \
"syscfg\c2000ware_libraries.h" \
"syscfg\c2000_freertos.h" \
"syscfg\FreeRTOSConfig.h" \
"syscfg\c2000_freertos.cmd.genlibs" \
"syscfg\syscfg_c.rov.xs" \
"syscfg\clocktree.h" 

C_DEPS__QUOTED += \
"OLED_SPI.d" \
"syscfg\board.d" \
"syscfg\c2000ware_libraries.d" \
"syscfg\c2000_freertos.d" \
"tasks.d" \
"queue.d" \
"list.d" \
"timers.d" \
"event_groups.d" \
"stream_buffer.d" \
"port.d" \
"heap_4.d" 

GEN_FILES__QUOTED += \
"syscfg\board.c" \
"syscfg\board.opt" \
"syscfg\c2000ware_libraries.opt" \
"syscfg\c2000ware_libraries.c" \
"syscfg\c2000_freertos.c" \
"syscfg\c2000_freertos.opt" 

ASM_DEPS__QUOTED += \
"portasm.d" 

C_SRCS__QUOTED += \
"../OLED_SPI.c" \
"./syscfg/board.c" \
"./syscfg/c2000ware_libraries.c" \
"./syscfg/c2000_freertos.c" \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/tasks.c" \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/queue.c" \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/list.c" \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/timers.c" \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/event_groups.c" \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/stream_buffer.c" \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/CCS/C2000_C28x/port.c" \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/MemMang/heap_4.c" 

SYSCFG_SRCS__QUOTED += \
"../c2000.syscfg" 

ASM_SRCS__QUOTED += \
"C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/CCS/C2000_C28x/portasm.asm" 


