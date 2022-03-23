#################################################################################
###     A python script to send the data to the client (the WeMos) by WiFi    ###
#################################################################################

import socket
import time
from commons import *

# My IP address on DVIC WiFi network: 172.21.72.191
def run_tcp_server(data: EcFlexValues):

     port = 1234
     host = socket.gethostname()
     address = (host, port)

     server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
     server_socket.bind(address)
     server_socket.listen(5)

     print ("Listening for client...")
     conn, address = server_socket.accept()
     print ("Connected to client at ", address)
                              
     clientsocket, address = server_socket.accept()
     print(f"Connection from {address} has been established")
     val = None
     while True:
          time.sleep(.5)
          clientsocket.send(data.to_bytes())
          val = Value.value
          print ("Value ", Value.value, "has been sent to the client")



