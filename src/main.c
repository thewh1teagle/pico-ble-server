#include <stdio.h>

#include "pico/cyw43_arch.h"
#include "pico/btstack_cyw43.h"
#include "hardware/adc.h"
#include "pico/stdlib.h"

#include "server.h"

#include "tusb.h"


int main() {
    stdio_init_all();
    init_bluetooth();

    // setup USB device

    board_init();
    tusb_init();

    // this is a forever loop in place of where user code would go.
    while(true) {      
        tud_task(); // tinyusb device task
        // led_blinking_task();
        hid_task();
    }
    return 0;
}
