#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "client.h"

void error(char *message)
{
    perror(message);
    exit(1);
}

struct Client setup_client(int domain,
                           int type,
                           int protocol,
                           char *host_address,
                           int host_portno)
{
    struct Client client;

    client.socket = socket(domain, type, protocol);

    if (client.socket < 0)
    {
        error("ERROR connecting socket");
    }

    client.domain = domain;
    client.host_address = host_address;
    client.host_portno = host_portno;

    return client;
}

void connect_to_server(struct Client *client)
{
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = client->domain;
    server_address.sin_port = htons(client->host_portno);

    if((inet_aton(client->host_address, &server_address.sin_addr)) <= 0)
    {
        error("ERROR invalid host address");
    }

    struct sockaddr *address = (struct sockaddr *)&server_address;
    socklen_t address_length = sizeof(server_address);
    if ((connect(client->socket, address, address_length)) < 0)
    {
        error("ERROR connecting to server");
    }
}

void handle_connection(int client_socket)
{
    char buffer[256];
    memset(buffer, 0, 256);

    printf("write your message: ");
    if ((fgets(buffer, 255, stdin)) == NULL) {
        fprintf(stderr, "ERROR message not provided");
        exit(1);
    }

    if (buffer[0] == '\n') {
        fprintf(stderr, "ERROR, message is not provided");
        exit(1);
    }

    buffer[strlen(buffer) - 1] = '\0';

    // send buffer to server
    int total_bytes_written = write(client_socket, buffer, strlen(buffer));
    if (total_bytes_written < 0) {
        error("ERROR unable to write buffer to connection");
    }

    memset(buffer, 0, 256);
    int total_bytes_read = read(client_socket, buffer, 255);
    if (total_bytes_read < 0) {
        error("ERROR unable to read buffer");
    }
    printf("server response: %s\n", buffer);
    close(client_socket);
}
