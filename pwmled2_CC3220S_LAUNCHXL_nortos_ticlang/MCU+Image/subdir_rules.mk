################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
build-1125048193: ../image.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"/Applications/ti/ccs1280/ccs/utils/sysconfig_1.21.0/sysconfig_cli.sh" --script "/Users/victor/Desktop/CS350/pwmled2_CC3220S_LAUNCHXL_nortos_ticlang/image.syscfg" -o "syscfg" -s "/Applications/ti/simplelink_cc32xx_sdk_7_10_00_13/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/error.h: build-1125048193 ../image.syscfg
syscfg: build-1125048193

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1280/ccs/tools/compiler/ti-cgt-armllvm_3.2.1.LTS/bin/tiarmclang" -c -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=none -mlittle-endian -mthumb -Oz -I"/Users/victor/Desktop/CS350/pwmled2_CC3220S_LAUNCHXL_nortos_ticlang" -I"/Users/victor/Desktop/CS350/pwmled2_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image" -I"/Applications/ti/simplelink_cc32xx_sdk_7_10_00_13/source" -I"/Applications/ti/simplelink_cc32xx_sdk_7_10_00_13/kernel/nortos" -I"/Applications/ti/simplelink_cc32xx_sdk_7_10_00_13/kernel/nortos/posix" -DDeviceFamily_CC3220 -DNORTOS_SUPPORT -gdwarf-3 -march=armv7e-m -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"/Users/victor/Desktop/CS350/pwmled2_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-133772385: ../pwmled2.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"/Applications/ti/ccs1280/ccs/utils/sysconfig_1.21.0/sysconfig_cli.sh" --script "/Users/victor/Desktop/CS350/pwmled2_CC3220S_LAUNCHXL_nortos_ticlang/pwmled2.syscfg" -o "syscfg" -s "/Applications/ti/simplelink_cc32xx_sdk_7_10_00_13/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/error.h: build-133772385 ../pwmled2.syscfg
syscfg: build-133772385


