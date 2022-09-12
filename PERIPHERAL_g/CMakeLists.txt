# MAKE WITH:
#   INSIDE BUILD DIR
#   Windows:
#   cmake -G "MinGW Makefiles" ..

#   Linux:
#   cmake ..
cmake_minimum_required(VERSION 3.12)

# Pico SDK Path
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set allowed languages and versions
# First arg is project name
project(SPI_PERIPHERAL C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# create SDK subdirectory in project libraries
pico_sdk_init()

# Direct towards source
add_executable(${PROJECT_NAME} 
    main.c
)

# Generate map/bin/hex/uf2
pico_add_extra_outputs(${PROJECT_NAME})

# Link to pico stdlib
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_spi
)

# For USB printf, disable UART
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)