# Biosensor-to-smartwatch wireless communication
This project presents a wireless communication solution between an ec-Flex from Zimmer&Peacock and a homemade smartwatch. An on-skin glucose biosensor is connected to the ec-Flex. A laptop receives the data by BLE and sends it in real-time to the smartwatch microcontroller by Wi-Fi.

***

# Quickstart

**1. Download the project.** 

**2. In in the [get_ecflex_charac.py](https://github.com/DeVinci-Innovation-Center/Smartwatch/blob/main/get_ecflex_charac.py) script:**
* Enter the MAC address of the ec-Flex device.
* Run the code.
* Recover the addresses of handles 17, 21, 24, 27, 30, 96, and 99 in the vendor service. 

**3. In the [get_ecflex_data.py](https://github.com/DeVinci-Innovation-Center/Smartwatch/blob/main/get_ecflex_data.py) script:**
* Enter the handles addresses.
* Fill the access path of the database.db and schema.sql files.
* Run the code.

# Functional diagram

<p align="center">
  <img src=https://github.com/DeVinci-Innovation-Center/Biosensor-to-smartwatch_wireless_communication/blob/main/images/functional_diagram.png?raw=true "Functional diagram">
</p>

# Deployment diagram

<p align="center">
  <img src=https://github.com/DeVinci-Innovation-Center/Biosensor-to-smartwatch_wireless_communication/blob/main/images/deployment_diagramV2.png?raw=true "Deployment diagram">
</p>

# Requierments

### Hardware
You need an ec-Flex board, an ec-Flex battery and a glucose biosensor from [Zimmer&Peacock products website](https://www.zimmerpeacocktech.com/products/). A tutorial to build the smartwatch is available [here](https://dvic.devinci.fr/tutorial/smartwatch). You have to replace the Arduino Uno by a WeMos D1 mini. 

### Software
To run the programs, you need bleak, asyncio, sqlite3, multiprocessing, struct, os, socket, and time Python modules. The PyBluez Python extension module is also requiered.

# Project advancement
All the scripts are working and successfully transmit the data from the ec-Flex to the laptop to the smartwatch. The data storage on a local database is still under development.

### Software future works
* Write a python script to read the database.
* Write an Arduino script using the GFX library that displays time, glucose concentration, and temperature (numerical values) on the GC9A01 screen.
* Write an Arduino script using the GFX library that displays a curve representing the glucose concentration evolution on the GC9A01 screen.

<p align="center">
  <img src=https://github.com/DeVinci-Innovation-Center/Biosensor-to-smartwatch_wireless_communication/blob/main/images/wearable_biosensing_system.jpg?raw=true "ec-Flex with glucose biosensor, sweat patch and Li-Po battery">
</p>
