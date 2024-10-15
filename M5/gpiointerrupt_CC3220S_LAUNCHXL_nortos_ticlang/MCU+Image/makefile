################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /Applications/ti/ccs1280/ccs/tools/compiler/ti-cgt-armllvm_3.2.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./gpiointerrupt.o" \
"./syscfg/ti_drivers_config.o" \
"./main_nortos.o" \
"../cc32xxs_nortos.cmd" \
$(GEN_CMDS__FLAG) \
-Wl,-lti_utils_build_linker.cmd.genlibs \
-Wl,-l"ti/devices/cc32xx/driverlib/ticlang/Release/driverlib.a" \
-Wl,-llibc.a \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.out 

EXE_OUTPUTS__QUOTED += \
"gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.out" 

CUSTOM_TOOL_OUTPUTS_2079012191 += \
gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.bin 

CUSTOM_TOOL_OUTPUTS_2079012191__QUOTED += \
"gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.bin" 

CUSTOM_TOOL_OUTPUTS_921960926 += \
syscfg/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.sli 

CUSTOM_TOOL_OUTPUTS_921960926__QUOTED += \
"syscfg/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.sli" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.out" secondary-outputs

# Tool invocations
gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"/Applications/ti/ccs1280/ccs/tools/compiler/ti-cgt-armllvm_3.2.1.LTS/bin/tiarmclang" -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=none -mlittle-endian -mthumb -Oz -DDeviceFamily_CC3220 -DNORTOS_SUPPORT -gdwarf-3 -march=armv7e-m -Wl,-m"gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.map" -Wl,-i"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/source" -Wl,-i"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/kernel/nortos" -Wl,-i"/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/syscfg" -Wl,-i"/Applications/ti/ccs1280/ccs/tools/compiler/ti-cgt-armllvm_3.2.1.LTS/lib" -Wl,--diag_wrap=off -Wl,--display_error_number -Wl,--warn_sections -Wl,--xml_link_info="gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang_linkInfo.xml" -Wl,--rom_model -o "gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.bin: $(EXE_OUTPUTS) gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.out
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: TI Arm ObjCopy'
	"/Applications/ti/ccs1280/ccs/tools/compiler/ti-cgt-armllvm_3.2.1.LTS/bin/tiarmobjcopy" -O binary --only-section .text --only-section .const --only-section .cinit --only-section .rodata --only-section .resetVecs "gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.out" "gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.bin"
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

syscfg/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.sli: $(EXE_OUTPUTS) gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.bin syscfg/ti_drivers_net_wifi_config.json
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: Image Creator'
	"/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13/source/ti/drivers/net/imagecreator/bin/SLImageCreator" syscfg create_image --sdk_path "/Users/victor/ti/simplelink_cc32xx_sdk_7_10_00_13" --json "/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/syscfg/ti_drivers_net_wifi_config.json" --file "/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/syscfg/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.sli" --mcu "/Users/victor/Desktop/CS350/M5/M5 milestone3/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang.bin"
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CUSTOM_TOOL_OUTPUTS_921960926__QUOTED)$(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(CUSTOM_TOOL_OUTPUTS_2079012191__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "gpiointerrupt.o" "syscfg/ti_drivers_config.o" "main_nortos.o" 
	-$(RM) "gpiointerrupt.d" "syscfg/ti_drivers_config.d" "main_nortos.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(CUSTOM_TOOL_OUTPUTS_2079012191) $(CUSTOM_TOOL_OUTPUTS_921960926)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

