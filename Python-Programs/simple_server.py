from socket import *


def createServer():
    someSocket = socket(AF_INET, SOCK_STREAM)

    try:
        someSocket.bind(("localhost", 9000))
        someSocket.listen(5)

        while 1:
            (clientSocket, address) = someSocket.accept()

            res = clientSocket.recv(5000).decode()
            pieces = res.split("\n")

            if len(pieces) > 0:
                print(pieces)

            data = "HTTP/1.1 200 OK\r\n"
            data += "Content-Type : text/html; charset=utf-8\r\n"
            data += "\r\n"
            data += "<html><body> <h1> The Server is Up and Your request was received </h2> </body></html>\r\n\r\n"

            clientSocket.sendall(data.encode())
            clientSocket.shutdown(SHUT_WR)

    except KeyboardInterrupt:
        print(" Server Shutting Down !! ")
    except Exception as e:
        print("Exception :")
        print(e)

    someSocket.close()


print("Server Up and Running : ")
print("Listening @ http://localhost:9000")
createServer()
