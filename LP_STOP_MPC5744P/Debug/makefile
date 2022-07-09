################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 8
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LP_STOP_MPC5744P.elf \

EXECUTABLES_QUOTED += \
"LP_STOP_MPC5744P.elf" \

EXECUTABLES_OS_FORMAT += \
LP_STOP_MPC5744P.elf \


# All Target
all: warning-messages explicit-dependencies LP_STOP_MPC5744P.elf secondary-outputs

# Tool invocations
LP_STOP_MPC5744P.elf: $(OBJS) C:/Users/nxa14584/Documents/Auto\ Apps/PPC\ Products/MPC5744P\ -\ Panther/Quick\ Start\ Package/QSP\ Raw\ Material/Code\ Project\ Examples\ for\ MPC574xP/LP_STOP_MPC5744P/Project_Settings/Linker_Files/57xx_flash.ld C:/Users/nxa14584/Documents/Auto\ Apps/PPC\ Products/MPC5744P\ -\ Panther/Quick\ Start\ Package/QSP\ Raw\ Material/Code\ Project\ Examples\ for\ MPC574xP/LP_STOP_MPC5744P/Project_Settings/Linker_Files/libs.ld $(OSPT) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #9 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "LP_STOP_MPC5744P.elf" "@LP_STOP_MPC5744P.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED) $(OSPT)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d  ./*/*.o ./*/*/*.o  $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs:

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

