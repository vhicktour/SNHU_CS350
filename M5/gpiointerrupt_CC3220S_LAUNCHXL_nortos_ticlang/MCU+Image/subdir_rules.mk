################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1280/ccs/tools/compiler/ti-cgt-armllvm_3.2.1.LTS/bin/tiarmclang" -c -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=none -mlittle-endian -mthumb -Oz -I"/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang" -I"/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image" -I"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/source" -I"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/kernel/nortos" -I"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/kernel/nortos/posix" -DDeviceFamily_CC3220 -DNORTOS_SUPPORT -gdwarf-3 -march=armv7e-m -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1582625247: ../gpiointerrupt.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"/Users/victor/ti/sysconfig_1.20.0/sysconfig_cli.sh" --script "/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/gpiointerrupt.syscfg" -o "syscfg" -s "/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/.metadata/product.json" -s "/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-1582625247 ../gpiointerrupt.syscfg
syscfg/ti_drivers_config.h: build-1582625247
syscfg/ti_utils_build_linker.cmd.genlibs: build-1582625247
syscfg/syscfg_c.rov.xs: build-1582625247
syscfg: build-1582625247

syscfg/%.o: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1280/ccs/tools/compiler/ti-cgt-armllvm_3.2.1.LTS/bin/tiarmclang" -c -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=none -mlittle-endian -mthumb -Oz -I"/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang" -I"/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image" -I"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/source" -I"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/kernel/nortos" -I"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/kernel/nortos/posix" -DDeviceFamily_CC3220 -DNORTOS_SUPPORT -gdwarf-3 -march=armv7e-m -MMD -MP -MF"syscfg/$(basename $(<F)).d_raw" -MT"$(@)" -I"/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-164008369: ../image.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"/Users/victor/ti/sysconfig_1.20.0/sysconfig_cli.sh" --script "/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/image.syscfg" -o "syscfg" -s "/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/.metadata/product.json" -s "/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_net_wifi_config.json: build-164008369 ../image.syscfg
syscfg: build-164008369


