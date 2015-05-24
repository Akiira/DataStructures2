################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LinkedList/Tests/Test.cpp \
../src/LinkedList/Tests/TestSuite_FixedLinkedList.cpp 

OBJS += \
./src/LinkedList/Tests/Test.o \
./src/LinkedList/Tests/TestSuite_FixedLinkedList.o 

CPP_DEPS += \
./src/LinkedList/Tests/Test.d \
./src/LinkedList/Tests/TestSuite_FixedLinkedList.d 


# Each subdirectory must supply rules for building sources it contributes
src/LinkedList/Tests/%.o: ../src/LinkedList/Tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++11 -I"C:\cygwin64\usr\include\boost" -I"C:\Users\Kitty\workspace\C++ Workspace\TestSuiteTest\cute" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


