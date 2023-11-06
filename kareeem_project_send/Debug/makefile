################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
kareeem_project_send.lss \

FLASH_IMAGE += \
kareeem_project_send.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: kareeem_project_send.elf secondary-outputs

# Tool invocations
kareeem_project_send.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,kareeem_project_send.map -mmcu=atmega16 -o "kareeem_project_send.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

kareeem_project_send.lss: kareeem_project_send.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S kareeem_project_send.elf  >"kareeem_project_send.lss"
	@echo 'Finished building: $@'
	@echo ' '

kareeem_project_send.hex: kareeem_project_send.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex kareeem_project_send.elf  "kareeem_project_send.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: kareeem_project_send.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 kareeem_project_send.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) kareeem_project_send.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
