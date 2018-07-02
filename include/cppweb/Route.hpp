#ifndef CPPWEB__ROUTE__HPP
#define CPPWEB__ROUTE__HPP

#include "cppweb/HttpRequest.hpp"
#include "cppweb/HttpResponse.hpp"
#include <string>
#include <functional>

namespace cppweb {
    class Route {
    public:
        Route();
        Route(HttpMethod method, std::string path);
        Route(HttpMethod method, std::string path, std::function<HttpResponse (HttpRequest)> handler);
        std::string path;
        HttpResponse handle(HttpRequest);
    protected:
        HttpMethod method;
        std::function<HttpResponse (HttpRequest)> handler;
    };
}

#endif
