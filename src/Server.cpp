#include <iostream>
#include "cppweb/Server.hpp"

char response[] = "HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<h1>Hello world!</h1>";

cppweb::Server::Server():
    cppweb::Server::Server(8080) {

}

cppweb::Server::Server(int port) {
    this->server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (this->server_socket_fd < 0) {
       perror("ERROR opening socket");
       exit(1);
    }

    bzero((char *) &this->server_address, sizeof(this->server_address));
    this->server_address.sin_family = AF_INET;
    this->server_address.sin_addr.s_addr = INADDR_ANY;
    this->server_address.sin_port = htons(port);

    if (bind(this->server_socket_fd, (struct sockaddr *) &this->server_address, sizeof(this->server_address)) < 0) {
       perror("ERROR on binding");
       exit(1);
    }
}

void
cppweb::Server::listen() {
    int client_socket_fd, n;
    struct sockaddr_in client_address;
    unsigned int client_len = sizeof(struct sockaddr_in);
    ::listen(this->server_socket_fd, 5);
    char buffer[8092];
    bzero(buffer, 8092);
    while(1) {
        client_socket_fd = accept(this->server_socket_fd, (struct sockaddr *)&client_address, &client_len);

        if (client_socket_fd < 0) {
            std::cout << "error" << std::endl;
            exit(1);
        }

        n = read(client_socket_fd, buffer, 8091);

        if (n < 0) {
            std::cout << "error" << std::endl;
            exit(1);
        }

        printf("request: %s\n", buffer);
        bzero(buffer, 8091);

        n = write(client_socket_fd, response, sizeof(response)-1);

        if (n < 0) {
            std::cout << "error" << std::endl;
            exit(1);
        }
        close(client_socket_fd);
     }
}

cppweb::Server::~Server() {

}
