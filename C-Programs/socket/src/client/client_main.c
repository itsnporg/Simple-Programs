#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

#include "client.h"

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "ERROR, address and port are not provided");
        exit(1);
    }

    int port_no = atoi(argv[2]);
    struct Client client = setup_client(AF_INET, SOCK_STREAM, 0, argv[1], port_no);

    connect_to_server(&client);
    handle_connection(client.socket);
}

