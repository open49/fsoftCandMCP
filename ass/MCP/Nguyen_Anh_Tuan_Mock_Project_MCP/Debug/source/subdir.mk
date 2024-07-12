################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Flash.c \
../source/Nguyen_Anh_Tuan_Mock_Project.c \
../source/function.c \
../source/mtb.c 

C_DEPS += \
./source/Flash.d \
./source/Nguyen_Anh_Tuan_Mock_Project.d \
./source/function.d \
./source/mtb.d 

OBJS += \
./source/Flash.o \
./source/Nguyen_Anh_Tuan_Mock_Project.o \
./source/function.o \
./source/mtb.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\nguye\Documents\MCUXpressoIDE_11.7.1_9221\workspace\Nguyen_Anh_Tuan_Mock_Project\source" -I"C:\Users\nguye\Documents\MCUXpressoIDE_11.7.1_9221\workspace\Nguyen_Anh_Tuan_Mock_Project" -I"C:\Users\nguye\Documents\MCUXpressoIDE_11.7.1_9221\workspace\Nguyen_Anh_Tuan_Mock_Project\CMSIS" -I"C:\Users\nguye\Documents\MCUXpressoIDE_11.7.1_9221\workspace\Nguyen_Anh_Tuan_Mock_Project\startup" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Flash.d ./source/Flash.o ./source/Nguyen_Anh_Tuan_Mock_Project.d ./source/Nguyen_Anh_Tuan_Mock_Project.o ./source/function.d ./source/function.o ./source/mtb.d ./source/mtb.o

.PHONY: clean-source

