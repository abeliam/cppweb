#include "cppweb/Router.hpp"
#include <iostream>

cppweb::Router::Router() {

}

cppweb::Router::Router(RouteCollection routes):
    routes(routes) {

}

cppweb::Route *
cppweb::Router::match(std::string uri) {
    std::vector<char> buffer;
    RouteNode * node = &routes.root;
    for(auto uri_it = uri.begin(); uri_it != uri.end(); ++uri_it) {
        if (*uri_it != '/') {
            buffer.push_back(*uri_it);
        }
        if (*uri_it == '/' || &(*uri_it) == &uri[uri.size()-1]) {
            std::string subpath(buffer.begin(), buffer.end());
            if (node->hasChild(subpath)) {
                node = node->child(subpath);
                if (&(*uri_it) == &uri[uri.size()-1] && node->route != NULL) {
                    return node->route;
                }
            }
            else {
                throw "UnmatchableURI";
            }
            buffer.clear();
        }
    }
}
