#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>

struct Server {
    int socket;
    struct sockaddr_in address;
    struct sockaddr_in client_address;
};

struct Server setup_server(int domain,
                           int type,
                           int protocol,
                           int port,
                           int backlog);

void prepare_for_accepting(struct Server *server);

int accept_connection(struct Server *server);
#endif
