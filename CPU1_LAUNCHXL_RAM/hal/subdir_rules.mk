################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
hal/%.obj: ../hal/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/elony/workspace_v12/OLED_SPI/hal" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/oled" --include_path="C:/Users/elony/workspace_v12/OLED_SPI" --include_path="C:/ti/c2000/C2000Ware_5_04_00_00" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/device" --include_path="C:/ti/c2000/C2000Ware_5_04_00_00/driverlib/f28003x/driverlib" --include_path="C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="hal/$(basename $(<F)).d_raw" --include_path="C:/Users/elony/workspace_v12/OLED_SPI/CPU1_LAUNCHXL_RAM/syscfg" --obj_directory="hal" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


