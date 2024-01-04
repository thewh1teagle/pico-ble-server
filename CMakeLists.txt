cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(app)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

set(PICO_CYW43_SUPPORTED 1)

add_executable(app
  src/main.c
  src/ble_common.c
)


target_link_libraries(app 
  pico_stdlib
  pico_cyw43_arch_none
  hardware_pio

  pico_stdlib
  pico_btstack_ble
  pico_btstack_cyw43
hardware_adc
)


target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_LIST_DIR} # For btstack config
    ${CMAKE_CURRENT_LIST_DIR}/include
)
pico_btstack_make_gatt_header(app PRIVATE "${CMAKE_CURRENT_LIST_DIR}/server.gatt") # add server.gatt for ble
pico_enable_stdio_usb(app 1) # enable usb cdc (serial output over usb)
pico_add_extra_outputs(app)