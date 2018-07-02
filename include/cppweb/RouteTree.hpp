#ifndef CPPWEB__ROUTE_TREE__HPP
#define CPPWEB__ROUTE_TREE__HPP

#include "cppweb/RouteCollection.hpp"
#include "cppweb/RouteNode.hpp"

namespace cppweb {
    class RouteTree {
    public:
        RouteTree();
        RouteTree(RouteCollection routes);
        RouteNode root;
    };
}

#endif
