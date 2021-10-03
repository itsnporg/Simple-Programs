import socket

s = socket.socket()
server_host = "127.0.0.1"
server_port = 50000

s.bind((server_host, server_port))
s.listen(1)

print("Waiting to hear from incoming connections..")

conn, addr = s.accept()
print("At this I am connected to ", addr)

import os

fp = open("data.txt", "rb")
sizeoffile = os.path.getsize("data.txt")
file_data = fp.read(sizeoffile)

conn.send(file_data)
print("File transmitted successfully..")

s.close()
