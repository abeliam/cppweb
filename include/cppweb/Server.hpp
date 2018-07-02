#ifndef CPPWEB__SERVER__HPP
#define CPPWEB__SERVER__HPP

#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#include "cppweb/HttpRequest.hpp"
#include "cppweb/HttpResponse.hpp"
#include "cppweb/Router.hpp"

#define DEFAULT_PORT 8080
#define VIEW_PATH "../resources/"

namespace cppweb {
    class Server {
    public:
        Server();
        Server(Router& router);
        Server(int port, Router & router);
        void listen();
        HttpResponse handle(HttpRequest request);
    private:
        Router router;
        int port;
        int bufferLength;
        int server_socket_fd;
        struct sockaddr_in server_address;
    };
}

#endif
