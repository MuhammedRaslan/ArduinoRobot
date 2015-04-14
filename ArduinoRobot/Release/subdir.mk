################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ArduinoRobot.cpp 

OBJS += \
./ArduinoRobot.o 

CPP_DEPS += \
./ArduinoRobot.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"D:\Arduino\hardware\arduino\cores\arduino" -I"D:\Arduino\hardware\arduino\variants\standard" -I"C:\Users\Ulrik1\workspace\ArduinoRobot" -I"D:\Arduino\libraries\NewPing" -D__IN_ECLIPSE__=1 -DUSB_VID= -DUSB_PID= -DARDUINO=106 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


