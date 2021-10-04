#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
//#include <netinet/in.h>
#include <arpa/inet.h>

#include "server.h"

extern void error(char *message);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "ERROR no port provided");
        exit(1);
    }

    int port_number = atoi(argv[1]);

    struct Server server = setup_server(AF_INET, SOCK_STREAM, 0, port_number, 5);

    while(1)
    {
        int client = accept_connection(&server);

        char buffer[256];
        memset(buffer, 0, 256);

        int buffer_bytes = 0;

        buffer_bytes = read(client, buffer, 255);
        if (buffer_bytes < 0)
        {
            error("ERROR receiving data");
        }

        printf("%s: %s\n", inet_ntoa(server.client_address.sin_addr), buffer);

        buffer_bytes = write(client, "ok", 3);
        if (buffer_bytes < 0)
        {
            error("ERROR sending data");
        }

        close(client);
    }
    return 0;
}

