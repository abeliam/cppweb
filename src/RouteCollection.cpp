#include "cppweb/RouteCollection.hpp"

cppweb::RouteCollection::RouteCollection() {

}

cppweb::RouteCollection::RouteCollection(std::initializer_list<Route> l) {
    for (auto it = l.begin(); it != l.end(); ++it)
        routes.push_back(*it);
}

std::vector<cppweb::Route>::iterator
cppweb::RouteCollection::begin() {
    return routes.begin();
}

std::vector<cppweb::Route>::iterator
cppweb::RouteCollection::end() {
    return routes.end();
}
