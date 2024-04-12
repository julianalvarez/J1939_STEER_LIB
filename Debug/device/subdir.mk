################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MIMXRT1064.c 

C_DEPS += \
./device/system_MIMXRT1064.d 

OBJS += \
./device/system_MIMXRT1064.o 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DSYSTEM_STEER -DCPU_MIMXRT1064DVL6A -DCPU_MIMXRT1064DVL6A_cm7 -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\Include" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\Include\canmsg" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\device" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\CMSIS" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\common_package\include" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-device

clean-device:
	-$(RM) ./device/system_MIMXRT1064.d ./device/system_MIMXRT1064.o

.PHONY: clean-device

