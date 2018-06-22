#ifndef CPPWEB_SERVER_HPP
#define CPPWEB_SERVER_HPP

#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

namespace cppweb {
    class Server {
    public:
        Server();
        Server(int port);
        void listen();
        ~Server();
    private:
        int server_socket_fd;
        struct sockaddr_in server_address;
    };
}

#endif
