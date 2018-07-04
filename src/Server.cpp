#include <iostream>

#include "cppweb/Server.hpp"
#include "cppweb/HttpRequestFactory.hpp"

cppweb::Server::Server() {

}

cppweb::Server::Server(Router & router):
    cppweb::Server::Server(DEFAULT_PORT, router) {

}

cppweb::Server::Server(int port, Router & router):
    bufferLength(8092)
    {
    this->port = port;
    this->server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    int enable = 1;
    if (setsockopt(this->server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");

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

    std::string buffer(this->bufferLength, '\0');


    std::cout << "server listenning on port " << port << std::endl;

    HttpRequestFactory requestFactory;

    while(1) {
        client_socket_fd = accept(this->server_socket_fd, (struct sockaddr *)&client_address, &client_len);

        if (client_socket_fd < 0) {
            std::cout << "error" << std::endl;
            exit(1);
        }

        n = read(client_socket_fd, &buffer[0], this->bufferLength - 1);

        if (n < 0) {
            std::cout << "error" << std::endl;
            exit(1);
        }

        HttpRequest request = requestFactory.fromRaw(buffer, this->bufferLength);
        HttpResponse response = handle(request);

        response.write(client_socket_fd);

        if (n < 0) {
            std::cout << "error" << std::endl;
            exit(1);
        }
        close(client_socket_fd);
     }
}

cppweb::HttpResponse cppweb::Server::handle(HttpRequest request) {
    // try {
    //     Route * route = router.match(request.uri.erase(0,1));
    //     return route->handle(request);
    // }
    // catch(char * e) {
    //     std::cout << e << std::endl;
    // }
    return HttpResponse(404, "<h1>Not found</h1> ");
}
