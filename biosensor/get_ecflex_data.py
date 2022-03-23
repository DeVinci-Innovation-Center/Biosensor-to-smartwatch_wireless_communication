#############################################################################
###   A python script to recover the data from the server (the ec-Flex)   ###
###                     and print user-friendly values                    ###
#############################################################################

import asyncio
import struct

from commons import *

from bleak import BleakClient, BleakScanner
from bleak.exc import BleakError
from multiprocessing import Value

from server import run_tcp_server


MULTIPROCES_VALUES = EcFlexValues()

# from bleak.uuids import uuid16_dict
### Create a dictionnary
#characteristics = {}
#characteristics["ecFlex_data"] = #"00002d8d-0000-1000-8000-00805f9b34fb"
# uuid16_dict = {v: k for k, v in uuid16_dict.items()}

mac_addr = "00:35:ff:0b:ae:4c"                            # Mac address of the ec-Flex
vendor_service = "00002d8d-0000-1000-8000-00805f9b34fb"   # Vendor sevice 

handle17 = "00002da7-0000-1000-8000-00805f9b34fb"         # Handle 17 | from Vendor service
handle24 = "00002da9-0000-1000-8000-00805f9b34fb"         # Handle 24 | n0 | ADC reference voltage
handle21 = "00002da8-0000-1000-8000-00805f9b34fb"         # Handle 21 | d0 | ADC resolution
handle27 = "00002daa-0000-1000-8000-00805f9b34fb"         # Handle 27 | x0 | Virtual ground level
handle30 = "00002dab-0000-1000-8000-00805f9b34fb"         # Handle 30 | d1 | Current-to-voltage amplification
handle96 = "00002e01-0000-1000-8000-00805f9b34fb"         # Handle 96 | n1 | Scale factor for current
handle99 = "00002e02-0000-1000-8000-00805f9b34fb"         # Handle 99 | n2 | Scale-factor for non-offset linear conversion

def update_value(**kwargs):
    global MULTIPROCES_VALUES
    
    for k in kwargs:
        v = kwargs[k]
        t = EcFlexTypes.from_name(k)
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
    read_value = struct.unpack('<4H', read_value)      # Convert bytesarray readed into bytes (for each line). '<' shows reading direction
    id_value = read_value[0]                           # ID value of the byte sent
    timer_value = round(read_value[1] / 10**3, 1)      # Timer value in milliseconds
    temperature_value = read_value[2] / 10             # Temperature value
    v0 = n0/d0 * read_value[3] - x0                    # v0 is the voltage readout
    i = -v0 * n1/d1                                    # Current
    cg = i/n2                                          # Glucose concentration

    print("ID: ", id_value, "| Timer: ", timer_value, "s ", "| Temperature: ", temperature_value, "°F ", "| Glucose concentration: ", cg, "µMol")

    update_value(id=id_value, timer=timer_value, temperature=temperature_value, glucose_concentration=cg)


async def main(mac_addr: str):
    global d0, n0, x0, d1, n1, n2            # Global variables

    device = await BleakScanner.find_device_by_address(mac_addr, timeout=10.0)      # Scan BLE and try to find the ec-Flex during 10 secondes
    if not device:
        raise BleakError(f"The device with address {mac_addr} could not be found.")

    async with BleakClient(device) as client:    # Async with allows 

        await client.start_notify(handle17, read_callback)    # Notify function se déclenche quand réception d'une data et lance la fonction read_callback.
        # read_value = await client.read_gatt_char(handle17)       # ADC reference voltage
        print("n0: ", struct.unpack('i', bytes(await client.read_gatt_char(handle24))))
        print("d0: ", struct.unpack('i', bytes(await client.read_gatt_char(handle21))))
        print("x0: ", struct.unpack('i', bytes(await client.read_gatt_char(handle27))))
        print("d1: ", struct.unpack('i', bytes(await client.read_gatt_char(handle30))))
        print("n1: ", struct.unpack('i', bytes(await client.read_gatt_char(handle96))))
        print("n2: ", struct.unpack('i', bytes(await client.read_gatt_char(handle99))))

        n0 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle24)))[0])      # ADC reference voltage
        d0 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle21)))[0])      # ADC resolution
        x0 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle27)))[0])      # Virtual ground level
        d1 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle30)))[0])      # Current-to-voltage amplification
        n1 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle96)))[0])      # Scale factor for current
        n2 = int(struct.unpack('i', bytes(await client.read_gatt_char(handle99)))[0])      # Scale-factor for non-offset linear conversion

        print("d0*100: ", d0)
        print("x0*100: ", x0)
        print("d1*100: ", d1)
        print("n2: ", n2)

        await asyncio.sleep(1000.0)                # Suspend the task for 1 second
        await client.stop_notify(handle17)         # Notify function

if __name__ == "__main__":
   print("Start bluetooth scanning")
   asyncio.run(main(mac_addr))                     # Execute the coroutine and return the result
   run_tcp_server(MULTIPROCES_VALUES)


