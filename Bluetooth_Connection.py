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

from bleak import BleakClient, BleakScanner
from bleak.exc import BleakError

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

N0 = 0xff
D0 = 0xff
X0 = 0xff
D1 = 0xff
N1 = 0xff
N2 = 0xff
read_value = 0xff

# ID_dec = 0        # ID value of the data (byte) sent
# Timer_dec =     # Timer value in milliseconds
# Temp_dec =      # Temperature value
# ADC_dec =       # Glucose concentration value

class Ec_flex_data:
        def __init__(self, id_value: int, timer_value: float, temperature_value: float, cg: float):
                self.id=id_value
                self.timer=timer_value
                self.temp=temperature_value
                self.cg=cg

def read_callback(sender, read_value):
    read_value = struct.unpack('<4H', read_value)      # Convert bytesarray readed into bytes (for each line). '<' shows le sens de lecture
    id_value = read_value[0]
    timer_value = round(read_value[1] / 10**3, 1)
    temperature_value = read_value[2] / 10
    V0 = N0/D0 * read_value[3] - X0                # V0 is the voltage readout
    I = -V0 * N1/D1                                # Current
    cg = I/N2                                      # Glucose concentration

    print("ID: ", id_value, "| Timer: ", timer_value, "s ", "| Temperature: ", temperature_value, "°F ", "| Glucose concentration: ", Cg, "µMol")


    return Ec_flex_data(id_value, timer_value, temperature_value, cg)

async def main(mac_addr: str):

    device = await BleakScanner.find_device_by_address(mac_addr, timeout=10.0)      # Scan BLE and try to find the ec-Flex during 10 secondes
    if not device:
        raise BleakError(f"The device with address {mac_addr} could not be found.")

    async with BleakClient(device) as client:    # Async with allows 

        await client.start_notify(handle17, read_callback)    # Notify function se déclenche quand réception d'une data et lance la fonction read_callback.
        # read_value = await client.read_gatt_char(handle17)       # ADC reference voltage
        N0 = await client.read_gatt_char(handle24)       # ADC reference voltage
        D0 = await client.read_gatt_char(handle21)       # ADC resolution
        X0 = await client.read_gatt_char(handle27)       # Virtual ground level
        D1 = await client.read_gatt_char(handle30)       # Current-to-voltage amplification
        N1 = await client.read_gatt_char(handle96)       # Scale factor for current
        N2 = await client.read_gatt_char(handle99)       # Scale-factor for non-offset linear conversion
        print("D0*100: ", struct.unpack('f', bytes(D0)))
        print("X0*100: ", struct.unpack('f', bytes(X0)))
        print("D1*100: ", struct.unpack('f', bytes(D1)))
        print("N2: ", struct.unpack('f', bytes(N2)))

        await asyncio.sleep(10.0)                          # Notify function
        await client.stop_notify(handle17)             # Notify function

if __name__ == "__main__":
   asyncio.run(main(mac_addr))

# while True:           # Infinite loop
#     data = '' 
#     new_read_value = True
#     while True:

#         # Counter readout (bytes 1-2)
#         Counter_dec = int(data[1] << 8) + int(data[0])       # Value counter
        
#         # Timer readout (bytes 3-4)
#         Timer_dec = int(data[3] << 8) + int(data[2])    # Timer value in milliseconds
#         # Delta_t_dec = int(data[3] << 8) + int(data[2]) - Timer_dec
#         # TimeVal = Delta_t_dec * Counter_dec / 1000           # in seconds

#         #Temperature readout (bytes 5-6)
#         Temp_dec = int(data[5] << 8) + int(data[4])
#         Temp_dec = Temp_dec / 10                       # Convert the temperature in °C

        # #Sensor readout (bytes 7-8)
        # ADC_dec = int(data[7] << 8) + int(data[6])     # Glucose concentration value
        # V0 = N0/D0 * ADC_dec - X0                      # V0 is the voltage readout
        # I = -V0 * N1/D1                                # Current
        # Cg = I/N2                                      # Glucose concentration
       
        # print("Byte receive: ", data)
        # print("Counter value: ", Counter_dec)
        # print("Temperature: ", Temp_dec)
        # print("Glucose concentration: ", Cg)

        # new_data = False






# Listen the data sent by the server
#s.listen(5)
#while True:
#    clientsocket, adress = s.accept()
#    print(f"connection from {address} has been established.")

# Double client, la smartwatch devrait venir se connecter à mon PC
# ecFlex_idx = (Unit16)(data[1])