import asyncio
from bleak import BleakScanner, BleakClient, BleakGATTServiceCollection
import struct

UUID = '0000181a-0000-1000-8000-00805f9b34fb'

async def find_address():
    devices = await BleakScanner.discover()
    for d in devices:
        details = d.details
        if UUID in details['props']['UUIDs']:
            return d

async def find_char(services: BleakGATTServiceCollection):  
    for id, handle in services.characteristics.items():
        desc = handle.description
        if desc == 'Temperature':
            return handle
        
async def main():
    device = await find_address()
    async with BleakClient(device) as client:
        services = client.services
        char = await find_char(services)
        while True:
            packet = await client.read_gatt_char(char)
            temp, = struct.unpack('<H', packet) # uint16_t
            # Convert the uint16_t to a float
            temp = temp / 100.0
            print(f'Temp is {temp}')
            await asyncio.sleep(1)

asyncio.run(main())
