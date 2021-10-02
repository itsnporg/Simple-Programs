
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "server.h"

void error(char *message)
{
    perror(message);
    exit(1);
}

/*
   struct server {
   int socket;
   struct sockaddr_in address;
   };*/

struct Server setup_server(int domain,
                           int type,
                           int protocol,
                           int port,
                           int backlog)
{
    struct Server server;

    server.socket = socket(domain, type, protocol);

    if (server.socket < 0)
    {
        error("ERROR creating socket connection");
    }

    int option_value = 0;

    // set socket descriptor to reusable
    if(setsockopt(server.socket, SOL_SOCKET, SO_REUSEADDR, (char *)&option_value, sizeof(option_value)) < 0) {
        error("ERROR failed to set socket option");
    }

    // set socket to non blocking
    if (ioctl(server.socket, FIONBIO, (char *)&option_value) < 0) {
        error("ERROR setting socket to non blocking");
    }

    memset(&server.address, 0, sizeof(server.address));
    server.address.sin_family = AF_INET;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(INADDR_ANY);

    struct sockaddr *socket_address = (struct sockaddr *)&server.address;
    int address_length = sizeof(server.address);

    if ((bind(server.socket, socket_address, address_length)) < 0)
    {
        error("ERROR binding socket address");
    }

    if ((listen(server.socket, backlog)) < 0)
    {
        error("ERROR on listening connection");
    }

    printf("Listening.....\n");

    return server;
}

int accept_connection(struct Server *server)
{
    memset(&server->client_address, 0, sizeof(server->client_address));

    struct sockaddr *address = (struct sockaddr *)&server->client_address;
    socklen_t address_length = sizeof(server->client_address);

    int new_client_socket = accept(server->socket, address, &address_length);

    if (new_client_socket < 0)
    {
        error("ERROR accepting connection");
    }

    printf("\n%s joined the swarm\n\n", inet_ntoa(server->client_address.sin_addr));

    return new_client_socket;
}
