cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
pico_sdk_init()

project(server)

# Standalone example that reads from the on board temperature sensor and sends notifications via BLE
# Flashes slowly each second to show it's running
add_executable(server
    server.c server_common.c
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
    )
pico_btstack_make_gatt_header(server PRIVATE "${CMAKE_CURRENT_LIST_DIR}/server.gatt")

pico_add_extra_outputs(server)


# # Standalone example that connects to server and reads the temperature 
# # Flahes once quickly each second when it's running but not connected to another device
# # Flashes twice quickly each second when connected to another device and reading it's temperature
# add_executable(picow_ble_temp_reader
#     client.c
#     )
# target_link_libraries(picow_ble_temp_reader
#     pico_stdlib
#     pico_btstack_ble
#     pico_btstack_cyw43
#     pico_cyw43_arch_none
#     hardware_adc
#     )
# target_include_directories(picow_ble_temp_reader PRIVATE
#     ${CMAKE_CURRENT_LIST_DIR} # For btstack config
#     )
# target_compile_definitions(picow_ble_temp_reader PRIVATE
#     RUNNING_AS_CLIENT=1
# )

# pico_add_extra_outputs(picow_ble_temp_reader)

