#############################################################################
###   A python script to recover the data from the server (the ec-Flex)   ###
#############################################################################

"""
Connect by BLEDevice
"""

import asyncio
import platform
import sys
import struct

from Biosensor.commons import *

from bleak import BleakClient, BleakScanner
from bleak.exc import BleakError
from multiprocessing import Value

from Biosensor.Server import run_tcp_server


MULTIPROCES_VALUES = ECFlexValues()

# from bleak.uuids import uuid16_dict
### Create a dictionnary
#characteristics = {}
#characteristics["ecFlex_data"] = #"00002d8d-0000-1000-8000-00805f9b34fb"
# uuid16_dict = {v: k for k, v in uuid16_dict.items()}

mac_addr = "00:35:ff:0b:ae:4c"                         # Mac address of the ec-Flex
vendor_service = "00002d8d-0000-1000-8000-00805f9b34fb"   # Vendor sevice 

handle17 = "00002da7-0000-1000-8000-00805f9b34fb"      # Handle 17 | from Vendor service
handle24 = "00002da9-0000-1000-8000-00805f9b34fb"      # Handle 24 | N0 | ADC reference voltage
handle21 = "00002da8-0000-1000-8000-00805f9b34fb"      # Handle 21 | D0 | ADC resolution
handle27 = "00002daa-0000-1000-8000-00805f9b34fb"      # Handle 27 | X0 | Virtual ground level
handle30 = "00002dab-0000-1000-8000-00805f9b34fb"      # Handle 30 | D1 | Current-to-voltage amplification
handle96 = "00002e01-0000-1000-8000-00805f9b34fb"      # Handle 97 | N1 | Scale factor for current
handle99 = "00002e02-0000-1000-8000-00805f9b34fb"      # Handle 99 | N2 | Scale-factor for non-offset linear conversion

N0 = 255
D0 = 0xff
X0 = 0xff
D1 = 0xff
N1 = 0xff
N2 = 0xff
read_value = 0xff
V0 = 0

# ID_dec = 0        # ID value of the data (byte) sent
# Timer_dec =     # Timer value in milliseconds
# Temp_dec =      # Temperature value
# ADC_dec =       # Glucose concentration value

def update_value(**kwargs):
    global MULTIPROCES_VALUES
    
    for k in kwargs:
        v = kwargs[k]
        t = ECFlexTypes.from_name(k)
        if t is None:
            print("NO ATTRIBUTE ", k)
            continue
        MULTIPROCES_VALUES[t] = v
    print("Values Updated")
    print(MULTIPROCES_VALUES.to_bytes())

# class Ec_flex_data:
#         def __init__(self, id_value: int, timer_value: float, temperature_value: float, cg: float):
#                 self.id=id_value
#                 self.timer=timer_value
#                 self.temp=temperature_value
#                 self.cg=cg

def read_callback(sender, read_value):
    read_value = struct.unpack('<4H', read_value)      # Convert bytesarray readed into bytes (for each line). '<' shows le sens de lecture
    id_value = read_value[0]
    timer_value = round(read_value[1] / 10**3, 1)
    temperature_value = read_value[2] / 10
    print(id_value, timer_value, temperature_value)
    V0 = N0/D0 * read_value[3] - X0                # V0 is the voltage readout
    I = -V0 * N1/D1                                # Current
    cg = I/N2                                      # Glucose concentration

    print("ID: ", id_value, "| Timer: ", timer_value, "s ", "| Temperature: ", temperature_value, "°F ", "| Glucose concentration: ", cg, "µMol")

    update_value(id=id_value, timer=timer_value, temperature=temperature_value, glucose_concentration=cg)


async def main(mac_addr: str):
    global D0, N0, X0, D1, N1, N2            # Global variables

    device = await BleakScanner.find_device_by_address(mac_addr, timeout=10.0)      # Scan BLE and try to find the ec-Flex during 10 secondes
    if not device:
        raise BleakError(f"The device with address {mac_addr} could not be found.")

    async with BleakClient(device) as client:    # Async with allows 

        await client.start_notify(handle17, read_callback)    # Notify function se déclenche quand réception d'une data et lance la fonction read_callback.
        # read_value = await client.read_gatt_char(handle17)       # ADC reference voltage
        print("N0: ", struct.unpack('i', bytes(await client.read_gatt_char(handle24))))
        print("D0: ", struct.unpack('i', bytes(await client.read_gatt_char(handle21))))
        print("X0: ", struct.unpack('i', bytes(await client.read_gatt_char(handle27))))
        print("D1: ", struct.unpack('i', bytes(await client.read_gatt_char(handle30))))
        print("N1: ", struct.unpack('i', bytes(await client.read_gatt_char(handle96))))
        print("N2: ", struct.unpack('i', bytes(await client.read_gatt_char(handle99))))

        N0 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle24)))[0])
        D0 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle21)))[0])
        X0 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle27)))[0])
        D1 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle30)))[0])
        N1 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle96)))[0])
        N2 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle99)))[0])

        # N0 = float(struct.unpack('f', bytes(await client.read_gatt_char(handle24)))[0])       # ADC reference voltage
        # D0 = struct.unpack('f', bytes(await client.read_gatt_char(handle21[0])))       # ADC resolution
        # X0 = float(struct.unpack('f', bytes(await client.read_gatt_char(handle27[0]))))       # Virtual ground level
        # D1 = float(struct.unpack('f', bytes(await client.read_gatt_char(handle30[0]))))       # Current-to-voltage amplification
        # N1 = float(struct.unpack('f', bytes(await client.read_gatt_char(handle96[0]))))       # Scale factor for current
        # N2 = float(struct.unpack('f', bytes(await client.read_gatt_char(handle99[0]))))       # Scale-factor for non-offset linear conversion

        print("D0*100: ", D0)
        print("X0*100: ", X0)
        print("D1*100: ", D1)
        print("N2: ", N2)

        await asyncio.sleep(1000.0)                          # Notify function
        await client.stop_notify(handle17)             # Notify function

if __name__ == "__main__":
   asyncio.run(main(mac_addr))
   run_tcp_server(MULTIPROCES_VALUES)


