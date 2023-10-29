################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Port/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXT_INT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD2/subdir.mk
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
Little_Story.lss \

FLASH_IMAGE += \
Little_Story.hex \

EEPROM_IMAGE += \
Little_Story.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Little_Story.elf secondary-outputs

# Tool invocations
Little_Story.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Little_Story.map -mmcu=atmega32 -o "Little_Story.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Little_Story.lss: Little_Story.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Little_Story.elf  >"Little_Story.lss"
	@echo 'Finished building: $@'
	@echo ' '

Little_Story.hex: Little_Story.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Little_Story.elf  "Little_Story.hex"
	@echo 'Finished building: $@'
	@echo ' '

Little_Story.eep: Little_Story.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Little_Story.elf  "Little_Story.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Little_Story.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Little_Story.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Little_Story.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
