#ifndef CPPWEB__ROUTE_NODE__HPP
#define CPPWEB__ROUTE_NODE__HPP

#include <map>
#include "cppweb/Route.hpp"

namespace cppweb {
    class RouteNode {
    public:
        RouteNode();
        RouteNode(Route * route);
        RouteNode * child(std::string& path);
        void addChild(std::string path, RouteNode * node);
        bool hasChild(std::string path);
        Route * route;
    private:
        std::map<std::string , RouteNode *> children;
    };
}

#endif
