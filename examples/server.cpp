#include <iostream>
#include <cstdlib>
#include "cppweb/Server.hpp"
#include "cppweb/Router.hpp"
#include "cppweb/HttpRequest.hpp"

using cppweb::RouteCollection;
using cppweb::HttpResponse;
using cppweb::HttpRequest;
using cppweb::HttpMethod;
using cppweb::Server;
using cppweb::Router;
using cppweb::Route;

int main(int argc, char * argv[]) {
    RouteCollection routes {
        Route(HttpMethod::GET, "/", [](HttpRequest request) {
            return HttpResponse::view("index.html");
        }),
        Route(HttpMethod::GET, "/foo/bar", [](HttpRequest request) {
            return HttpResponse(200, "foobar");
        }),
        Route(HttpMethod::GET, "/foo/baz", [](HttpRequest request) {
            return HttpResponse(200, "foobaz");
        })
    };

    Router router(routes);

    Server server(router);
    server.listen();
    return EXIT_SUCCESS;
}
