################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Job.cpp \
../src/algoritmo_guloso_interval_scheduling.cpp 

OBJS += \
./src/Job.o \
./src/algoritmo_guloso_interval_scheduling.o 

CPP_DEPS += \
./src/Job.d \
./src/algoritmo_guloso_interval_scheduling.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


