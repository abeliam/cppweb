#ifndef CPPWEB__ROUTER__HPP
#define CPPWEB__ROUTER__HPP

#include <string>
#include <vector>
#include "cppweb/HttpRequest.hpp"
#include "cppweb/Route.hpp"
#include "cppweb/RouteCollection.hpp"
#include "cppweb/RouteTree.hpp"

namespace cppweb {
    class Router {
    public:
        Router();
        Router(RouteCollection routes);
        Route * match(std::string uri);
    protected:
        RouteTree routes;
    };
}

#endif
