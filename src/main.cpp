#include <iostream>
#include "cppweb/Server.hpp"

int
main(int argc, char * argv[]) {
    cppweb::Server * server = new cppweb::Server();

    server->listen();

    delete server;
    return 0;
}
