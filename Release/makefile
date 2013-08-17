################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 1Wire/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
miniTEMP.lss \

FLASH_IMAGE += \
miniTEMP.hex \

EEPROM_IMAGE += \
miniTEMP.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: miniTEMP.elf secondary-outputs

# Tool invocations
miniTEMP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,miniTEMP.map -mmcu=attiny24 -o "miniTEMP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

miniTEMP.lss: miniTEMP.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S miniTEMP.elf  >"miniTEMP.lss"
	@echo 'Finished building: $@'
	@echo ' '

miniTEMP.hex: miniTEMP.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex miniTEMP.elf  "miniTEMP.hex"
	@echo 'Finished building: $@'
	@echo ' '

miniTEMP.eep: miniTEMP.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex miniTEMP.elf  "miniTEMP.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: miniTEMP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=attiny24 miniTEMP.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) miniTEMP.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
