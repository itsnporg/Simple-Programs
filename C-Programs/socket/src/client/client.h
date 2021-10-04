#ifndef CLIENT_H
#define CLIENT_H

struct Client {
    int socket;
    int domain;
    char *host_address;
    int host_portno;
};

void error(char *message);
struct Client setup_client(int domain,
                           int type,
                           int protocol,
                           char *host_address,
                           int host_portno);

void connect_to_server(struct Client *client);

void handle_connection(int client_socket);

#endif
