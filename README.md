# Biosensor-to-smartwatch wireless communication
This project presents a wireless communication solution between a wearable glucose biosensor from Zeammer&Peacock and an home-made smartwatch.

# Quickstart

Download the code. Enter the MAC address of your ec-Flex device in the [Get_charac.py](https://github.com/DeVinci-Innovation-Center/Smartwatch/blob/main/Get_charac.py) program. Run the code and recover the addresses of handles 17, 21, 24, 27, 30, 96 and 99 in the vendor service. Open the [Bluetooth_Connection.py](https://github.com/DeVinci-Innovation-Center/Smartwatch/blob/main/Bluetooth_Connection.py) file and enter the handles addresses.
Run ```sh main.sh``` in your terminal.

# Functional diagram

<p align="center">
  <img src=https://github.com/DeVinci-Innovation-Center/Biosensor-to-smartwatch_wireless_communication/blob/main/images/functional_diagram.png?raw=true "Functional diagram">
</p>

# Deployment diagram

<p align="center">
  <img src=https://github.com/DeVinci-Innovation-Center/Biosensor-to-smartwatch_wireless_communication/blob/main/images/deployment_diagram.png?raw=true "Demployment diagram">
</p>

# Requierments

### Hardware
You need an ec-Flex board, an ec-Flex battery and a glucose biosensor from [Zeammer&Peacock](https://www.zimmerpeacocktech.com/products/). A tutorial to build the smartwatch is available [here](https://dvic.devinci.fr/tutorial/smartwatch). You have to replace the Arduino Uno by a WeMos D1 mini. 

### Software
You need bleak, asyncio, sqlite3, multiprocessing, struct, os, socket, time modules to run the programs.

# Project advancement
The ec-Flex data are successfully collected and interpreting. The TCP server-client communication with the WeMos is still under development, as well as the database management.

