import asyncio
from bleak import BleakScanner

UUID = '0000181a-0000-1000-8000-00805f9b34fb'

async def main():
    devices = await BleakScanner.discover()
    for d in devices:
        print(d.details)

asyncio.run(main())