# Copyright (c) 2022 Joseph Russell.
# Licensed as BSD-3-Clause, see LICENSE for details.

cmake_minimum_required(VERSION 3.12)

# Pico SDK build tools
include(pico_sdk_import.cmake)

# Project metadata
project(rpi_pico_test_input C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Create pico-sdk subdirectory
pico_sdk_init()

add_executable(${PROJECT_NAME}
    main.cpp

    internal_temp.h
    internal_temp.cpp
)

# set print outputs
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

target_link_libraries(${PROJECT_NAME}
    # RPi SDK libraries
    pico_stdlib
    hardware_adc
)

# Create additional output files
pico_add_extra_outputs(${PROJECT_NAME})
