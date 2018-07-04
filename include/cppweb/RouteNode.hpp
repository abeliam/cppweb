#ifndef CPPWEB__ROUTE_NODE__HPP
#define CPPWEB__ROUTE_NODE__HPP

#include <map>
#include "cppweb/Route.hpp"

namespace cppweb {
    class Node {
    public:
        Node();
        Node * child(std::string& path);
        void addChild(std::string path, Node * node);
        bool hasChild(std::string path);
    protected:
        std::map<std::string , Node *> children;
    };


    class RouteNode : public Node {
    public:
        RouteNode();
        RouteNode(Route * route);
        Route * route;
    };

    class PathNode : public Node {
    public:
        PathNode();
    };

    class PatternNode : public Node {
    public:
        PatternNode();
    };
}

#endif
