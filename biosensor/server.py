#####################################################################
###     A python script to send the data to the client by WiFi    ###
#####################################################################

# import socket
# import time
from commons import *


# def run_tcp_server(data: EcFlexValues):

#      port = 1234
#      host = socket.gethostname()
#      address = (host, port)

#      server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#      server_socket.bind(address)
#      server_socket.listen(5)

#      print ("Listening for client...")
#      clientsocket, address = server_socket.accept()
#      print(f"Connection from {address} has been established")
     
#      while True:
#           time.sleep(.5)
#           clientsocket.send(data.to_bytes())
#           print ("Value ", data.value, "has been sent to the client")



from flask import Flask

app = Flask(__name__)        # Set the app/ the server

data = b''
@app.route("/get_data")     # Define what happened dès que la montre envoie get data | @app.route est un decorateur de la fonction send_data
def send_data():
     return data.to_string()

def run_tcp_server(buffer: EcFlexValues):   # 
     global data
     data = buffer
     print("Starting server")
     app.run(host = '0.0.0.0', port = 1235)   # Accept all IP addresses 

























