import socket
print("You can type [exit] at any time to quit! \n \n")
while True:
    try:
        s = socket.socket()
        host = input("Enter Host Name (Shown on the server): ", )
        if host.lower() == "exit":
            quit(0)
        while True:
            port = input("\nPlease Enter Port Number (Same as the server): ")
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
        s.connect((host, int(port)))
        break
    except Exception as e:
        print(e)
        print(" \nPlease enter a valid sender address! \n")
        continue
print("Connected to the server:", host, "\n")
while True:
    print("Waiting for the host to send a file... \n")
    while True:
        file_details_raw = s.recv(size)
        file_details = file_details_raw.decode('utf-8').split("@")
        filename = str(file_details[0])
        file_size = int(file_details[1])
        print("Waiting for the host to send a file... \n")
        client_permission = input(f"File named: '{filename}' "
                                  f"is coming from the host \nTo accept it...Press 1 \n")
        if client_permission.lower() == "exit":
            s.close()
            quit(0)
        s.send(bytes(str(client_permission), 'utf-8'))
        if client_permission == '1':
            print("Getting file... \n")
            file = open(filename, 'wb')
            file_data = s.recv(file_size+1024)
            file.write(file_data)
            file.close()
            print("File received! \n")
            break
        else:
            print("Waiting for server response... \n")
            inp2 = s.recv(1024)
            if str(inp2.decode('utf-8')) == '1':
                continue
            else:
                break

    a = input("Press 1 to restart!")
    if a.lower() == "exit":
        s.close()
        quit(0)
    if a == 1:
        continue
    else:
        s.close()
        break
