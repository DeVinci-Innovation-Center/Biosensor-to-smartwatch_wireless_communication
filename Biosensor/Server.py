import socket
import Bluetooth_Connection

# My IP address on DVIC WiFi network: 172.21.72.191

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(), 1234))
s.listen(1)

while True:
     clientsocket, address = s.accept()
     print(f"Connection from{address} has been established")
     clientsocket.send(bytes(Bluetooth_Connection.read_value, "utf-8"))


