import socket

host = '127.0.0.1'
port = 50000

s = socket.socket()
s.connect((host,port))

while True:
    message = raw_input("Message: ")
    bytes = message.encode()
    s.send(bytes)
    response = s.recv(1024)
    print "Remote Server: ",response.decode()

s.close()
