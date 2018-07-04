#include "cppweb/RouteNode.hpp"

cppweb::Node::Node():
    route(NULL) {

}

cppweb::Node::Node(Route * route):
    route(route) {

}

void
cppweb::Node::addChild(std::string path, Node * node) {
    children[path] = node;
}

bool
cppweb::Node::hasChild(std::string path) {
    return children.find(path) != children.end();
}

cppweb::Node *
cppweb::Node::child(std::string& path) {
    return children[path];
}
