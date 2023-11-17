################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/ACKM_canmsg.c \
../source/AddFilterBridge_J1939.c \
../source/AddFilter_J1939.c \
../source/AddressClaim_J1939.c \
../source/CS_canmsg.c \
../source/DequeueMessage_J1939.c \
../source/EnqueueMessage_J1939.c \
../source/OnPgn_J1939.c \
../source/Open_J1939.c \
../source/Output_J1939.c \
../source/Processor_J1939.c \
../source/ReceiveMessages_J1939.c \
../source/TPCM_canmsg.c \
../source/TPDT_canmsg.c \
../source/TimerEvent_J1939.c \
../source/TransmitMessages_J1939.c 

C_DEPS += \
./source/ACKM_canmsg.d \
./source/AddFilterBridge_J1939.d \
./source/AddFilter_J1939.d \
./source/AddressClaim_J1939.d \
./source/CS_canmsg.d \
./source/DequeueMessage_J1939.d \
./source/EnqueueMessage_J1939.d \
./source/OnPgn_J1939.d \
./source/Open_J1939.d \
./source/Output_J1939.d \
./source/Processor_J1939.d \
./source/ReceiveMessages_J1939.d \
./source/TPCM_canmsg.d \
./source/TPDT_canmsg.d \
./source/TimerEvent_J1939.d \
./source/TransmitMessages_J1939.d 

OBJS += \
./source/ACKM_canmsg.o \
./source/AddFilterBridge_J1939.o \
./source/AddFilter_J1939.o \
./source/AddressClaim_J1939.o \
./source/CS_canmsg.o \
./source/DequeueMessage_J1939.o \
./source/EnqueueMessage_J1939.o \
./source/OnPgn_J1939.o \
./source/Open_J1939.o \
./source/Output_J1939.o \
./source/Processor_J1939.o \
./source/ReceiveMessages_J1939.o \
./source/TPCM_canmsg.o \
./source/TPDT_canmsg.o \
./source/TimerEvent_J1939.o \
./source/TransmitMessages_J1939.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MIMXRT1064DVL6A -DCPU_MIMXRT1064DVL6A_cm7 -DSDK_OS_BAREMETAL -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\board" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\source" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\drivers" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\xip" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\device" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\CMSIS" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\component\serial_manager" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\component\uart" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\utilities" -I"C:\Users\PLANTIUM\Documents\MCUXpressoIDE_11.8.0_1165\workspace\j1939_STEER_LIB\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/ACKM_canmsg.d ./source/ACKM_canmsg.o ./source/AddFilterBridge_J1939.d ./source/AddFilterBridge_J1939.o ./source/AddFilter_J1939.d ./source/AddFilter_J1939.o ./source/AddressClaim_J1939.d ./source/AddressClaim_J1939.o ./source/CS_canmsg.d ./source/CS_canmsg.o ./source/DequeueMessage_J1939.d ./source/DequeueMessage_J1939.o ./source/EnqueueMessage_J1939.d ./source/EnqueueMessage_J1939.o ./source/OnPgn_J1939.d ./source/OnPgn_J1939.o ./source/Open_J1939.d ./source/Open_J1939.o ./source/Output_J1939.d ./source/Output_J1939.o ./source/Processor_J1939.d ./source/Processor_J1939.o ./source/ReceiveMessages_J1939.d ./source/ReceiveMessages_J1939.o ./source/TPCM_canmsg.d ./source/TPCM_canmsg.o ./source/TPDT_canmsg.d ./source/TPDT_canmsg.o ./source/TimerEvent_J1939.d ./source/TimerEvent_J1939.o ./source/TransmitMessages_J1939.d ./source/TransmitMessages_J1939.o

.PHONY: clean-source

