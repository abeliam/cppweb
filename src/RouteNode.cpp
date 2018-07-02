#include "cppweb/RouteNode.hpp"

cppweb::RouteNode::RouteNode():
    route(NULL) {

}

cppweb::RouteNode::RouteNode(Route * route):
    route(route) {

}

void
cppweb::RouteNode::addChild(std::string path, RouteNode * node) {
    children[path] = node;
}

bool
cppweb::RouteNode::hasChild(std::string path) {
    return children.find(path) != children.end();
}

cppweb::RouteNode *
cppweb::RouteNode::child(std::string& path) {
    return children[path];
}
