import socket
from os import stat, path
print("You can type [exit] at any time to quit! \n \n")

s = socket.socket()
host = socket.gethostname()
print(f"Host Name: {host} \n")

while True:
    port = input("\nPlease Enter Port Number Of Your Server: ")
    if port.lower() == "exit":
        quit(0)
    try:
        int(port)
        break
    except Exception as e:
        print(e)
        print("\nPort Number should Be a Integer! \n")
        continue

size = 1024
s.bind((host, int(port)))
s.listen(1)
print("Waiting for clients to join connection!\n")
conn, address = s.accept()
print("\n", address, "is connected to the server!\n")
while True:
    file_location = input("Enter file name of the file to be sent!\n")
    if file_location.lower() == "exit":
        conn.close()
        quit(0)
    try:
        file_size = str(stat(file_location).st_size)
        filename = str(path.basename(file_location))
    except Exception as e:
        print(e)
        print(f"\nCould't found file named: '{file_location}'! \n")
        continue
    print("Waiting form client permission... \n")
    while True:
        conn.send(bytes(r"{}".format(f"{filename}@{file_size}"), 'utf-8'))
        permission = conn.recv(size)
        if permission.decode("utf-8") == '1':
            file = open(filename, 'rb')
            file_data = file.read(int(file_size)+1024)
            conn.send(file_data)
            file.close()
            print("file sent successfully!\n")
            break
        else:
            print(f"Client had refused the file: '{filename}'... To resend it press 1 \n")
            inp1 = input()
            if inp1.lower() == "exit":
                conn.close()
                quit(0)
            conn.send(bytes(inp1, 'utf-8'))
            if inp1 == '1':
                continue
            elif inp1 != '1':
                break
    a = input("Press 1 to restart!\n")
    if a.lower() == "exit":
        conn.close()
        quit(0)
    if a == '1':
        continue
    else:
        conn.close()
        break
