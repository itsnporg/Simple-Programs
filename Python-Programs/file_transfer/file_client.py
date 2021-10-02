import socket

s = socket.socket()

server_host = "127.0.0.1"
server_port = 50000

s.connect((server_host, server_port))
print("Connection has been established")

fp = open("receiveddata.txt", "wb")
file_data = s.recv(2048)
fp.write(file_data)
fp.close()

print("File successfully received")

s.close()
