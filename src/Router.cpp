#include "cppweb/Router.hpp"
#include <iostream>

cppweb::Router::Router() {

}

cppweb::Router::Router(RouteCollection routes):
    routes(routes) {

}

std::string
cppweb::Router::normalize(std::string uri) {
    while(uri[0] == '/')
        uri.erase(0, 1);

    while(uri[uri.size() - 1] == '/')
        uri.erase(uri.size() - 1, 1);

    std::vector<char> nuri;

    bool ls = false;
    for(auto it = uri.begin(); it != uri.end(); ++it) {
        if (!(ls && *it == '/'))
            nuri.push_back(*it);
        if (*it == '/') {
            ls = true;
        }
        else {
            ls = false;
        }
    }
    return std::string(nuri.begin(), nuri.end());
}

cppweb::Route *
cppweb::Router::match(std::string uri) {
    uri = normalize(uri);
    std::vector<char> buffer;
    Node * node = &routes.root;
    Route * route;
    for(auto uri_it = uri.begin(); uri_it != uri.end(); ++uri_it) {
        if (*uri_it != '/') {
            buffer.push_back(*uri_it);
        }
        if (*uri_it == '/' || &(*uri_it) == &uri[uri.size()-1]) {
            std::string subpath(buffer.begin(), buffer.end());
            if (node->hasChild(subpath)) {
                node = node->child(subpath);
                // if (&(*uri_it) == &uri[uri.size()-1] && node->route != NULL) {
                    // route = node->route;
                    // break;
                // }
            }
            else {
                throw "UnmatchableURI";
            }
            buffer.clear();
        }
    }
    return route;
}
