#ifndef CPPWEB__SERVER__HPP
#define CPPWEB__SERVER__HPP

#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define DEFAULT_PORT 8080

namespace cppweb {
    class Server {
    public:
        Server();
        Server(int port);
        void listen();
        ~Server();
    private:
        int port;
        int bufferLength;
        int server_socket_fd;
        struct sockaddr_in server_address;
    };
}

#endif
