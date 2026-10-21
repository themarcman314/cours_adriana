#!/bin/bash
ARDUINO_DIR="$HOME/.platformio/packages/framework-arduinoststm32"
CMSIS_DIR="$HOME/.platformio/packages/framework-cmsis"

arm-none-eabi-gcc \
-mcpu=cortex-m4 -mthumb \
-D STM32L476xx \
-DVARIANT_H="variant_NUCLEO_L476RG.h" \
-I "$ARDUINO_DIR/system/Drivers/CMSIS/Device/ST/STM32L4xx/Include/" \
-I "$ARDUINO_DIR/system/Drivers/STM32L4xx_HAL_Driver/Inc/" \
-I "$ARDUINO_DIR/cores/arduino/" \
-I "$ARDUINO_DIR/variants/STM32L4xx/L476R(C-E-G)T_L486RG(T-P)" \
-I "$ARDUINO_DIR/system/STM32L4xx/" \
-I "$CMSIS_DIR/CMSIS/Core/Include/" \
-I "./src/" \
--specs=nosys.specs \
src/main.c \
src/uart.c
