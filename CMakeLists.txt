cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
project(server)
pico_sdk_init()


add_executable(server
    ${CMAKE_CURRENT_LIST_DIR}
    src/bluetooth.c src/local_hid.c src/server.c src/server_common.c src/usb_descriptors.c src/main.c
)

# In addition to pico_stdlib required for common PicoSDK functionality, add dependency on tinyusb_device
# for TinyUSB device support and tinyusb_board for the additional board support library used by the example
target_link_libraries(server PUBLIC 
    pico_btstack_ble pico_btstack_cyw43 pico_cyw43_arch_none hardware_adc
    pico_stdlib pico_unique_id tinyusb_device tinyusb_board 
)


# target_sources(server PUBLIC
#         ${CMAKE_CURRENT_LIST_DIR}/src/main.c
#         ${CMAKE_CURRENT_LIST_DIR}/src/usb_descriptors.c
#         ${CMAKE_CURRENT_LIST_DIR}/src/hid.c
#         )

# Make sure TinyUSB can find tusb_config.h
target_include_directories(server PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

# Uncomment this line to enable fix for Errata RP2040-E5 (the fix requires use of GPIO 15)
#target_compile_definitions(server PUBLIC PICO_RP2040_USB_DEVICE_ENUMERATION_FIX=1)

pico_add_extra_outputs(server)
