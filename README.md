# Pico W Bluetooth Stack

# Setup Stack
[getting-started-with-pico.pdf](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)

```console
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential

git clone https://github.com/raspberrypi/pico-sdk.git --branch master ~/pico-sdk
cd pico-sdk
git submodule update --init
cd ..
git clone https://github.com/raspberrypi/pico-examples.git --branch master ~/pico-examples

git clone https://github.com/raspberrypi/picotool.git ~/picotool
cd ~/picotool
mkdir build && cd build
cmake ..
make -j16
sudo cp picotool /usr/bin/
```

# Build
```console
export PICO_SDK_PATH=/home/user/pico-sdk
mkdir -p build
cd build
cmake .. -DPICO_BOARD=pico_w -DPICO_PLATFORM=rp2040
make -j16
picotool load -x server.uf2 -f
```