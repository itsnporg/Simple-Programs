# Basic Socket Program

It's a basic socket program where server continously listen for a message and when it receives it will response with ok.
Whereas client can only send a single message after that it will close the connection. The purpose of this program is to demonstrate
how to create socket, bind address, listen for new connection and accept it.

# Usage

## Compile both server and client by running `./build.sh`

## Run server

While running the server pass the port number as argument

```bash
./server 2058
```

## Run client

While running client pass the host and port number where server is listening

```bash
./client 127.0.0.1 2058
```
