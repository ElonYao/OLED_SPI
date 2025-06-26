################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-510346847: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.24.0/sysconfig_cli.bat" --script "C:/Users/elony/workspace_v12/OLED_SPI/c2000.syscfg" -o "syscfg" -s "C:/ti/c2000/C2000Ware_5_05_00_00/.metadata/sdk.json" -d "F28003x" --package 100PZ --part F28003x_100PZ --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-510346847 ../c2000.syscfg
syscfg/board.h: build-510346847
syscfg/board.cmd.genlibs: build-510346847
syscfg/board.opt: build-510346847
syscfg/board.json: build-510346847
syscfg/pinmux.csv: build-510346847
syscfg/c2000ware_libraries.cmd.genlibs: build-510346847
syscfg/c2000ware_libraries.opt: build-510346847
syscfg/c2000ware_libraries.c: build-510346847
syscfg/c2000ware_libraries.h: build-510346847
syscfg/c2000_freertos.c: build-510346847
syscfg/c2000_freertos.h: build-510346847
syscfg/FreeRTOSConfig.h: build-510346847
syscfg/c2000_freertos.cmd.genlibs: build-510346847
syscfg/c2000_freertos.opt: build-510346847
syscfg/syscfg_c.rov.xs: build-510346847
syscfg/clocktree.h: build-510346847
syscfg: build-510346847

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

tasks.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/tasks.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

queue.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/queue.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

list.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/list.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

timers.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/timers.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

event_groups.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/event_groups.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

stream_buffer.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/stream_buffer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

port.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/CCS/C2000_C28x/port.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

portasm.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/CCS/C2000_C28x/portasm.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

heap_4.obj: C:/ti/c2000/C2000Ware_5_05_00_00/kernel/FreeRTOS/Source/portable/MemMang/heap_4.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/RotaryEncoder" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/user" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_05_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


