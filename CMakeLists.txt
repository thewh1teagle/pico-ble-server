cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
pico_sdk_init()

project(server)

# Standalone example that reads from the on board temperature sensor and sends notifications via BLE
# Flashes slowly each second to show it's running
add_executable(server
    src/server.c src/server_common.c
    )
target_link_libraries(server
    pico_stdlib
    pico_btstack_ble
    pico_btstack_cyw43
    pico_cyw43_arch_none
    hardware_adc
    )
    
target_include_directories(server PRIVATE
    ${CMAKE_CURRENT_LIST_DIR} # For btstack config
    ${CMAKE_CURRENT_LIST_DIR}/include
    )
pico_btstack_make_gatt_header(server PRIVATE "${CMAKE_CURRENT_LIST_DIR}/server.gatt")
pico_enable_stdio_usb(server 1) # enable usb output to serial com port
pico_add_extra_outputs(server)
