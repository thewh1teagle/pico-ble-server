#!/bin/bash
cmake -B .build -G "Ninja" -DPICO_BOARD=pico_w -DPICO_PLATFORM=rp2040
cmake --build .build -- -j16

# reboot pico to bootloader
if ! picotool info > /dev/null; then
    echo "Device in application mode"
    echo "Reboot..."
    picotool reboot -u -f
    sleep 2
fi
picotool load -x .build/app.uf2
sleep 2 # wait for load
# open serial if serust command available
command -v serust &> /dev/null && serust --product-id 000a -b 115200 # 00a is default pico USB PID
