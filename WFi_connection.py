import socketio
import Bluetooth_Connection as bc

bc.Cglucose
bc.Temp_dec

sio = socketio.AsyncClient()

@sio.event
def connect():
    print('connection established')

@sio.event
def my_message(data):
    print('message received with ', data)
    sio.emit('my response', {'response': 'my response'})

@sio.event
def disconnect():
    print('disconnected from server')

sio.connect('http://localhost:5000')
sio.wait()

# Send data


def mysend(sock, Cglucose, temperature):
    totalsent = 0
    while totalsent < MSGLEN:
        sent1 = sock.send(Cglucose[totalsent:])
        sent2 = sock.send(temperature[totalsent:])
        if sent1 == 0:
            raise RuntimeError("socket connection broken")
        totalsent = totalsent + sent

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect()

port = 2
mysend(s, str(port))

