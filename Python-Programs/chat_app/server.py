import socket

host = ""
port = 50000

s = socket.socket()
s.bind((host, port))
s.listen(1)
conn, addr = s.accept()

print("Connected by : ", addr)

while True:
    data = conn.recv(2000)
    print(data.decode())
    response = raw_input("Response : ")
    bytes = response.encode()
    conn.send(bytes)

s.close()
