#ifndef CPPWEB__ROUTE_COLLECTION_HPP
#define CPPWEB__ROUTE_COLLECTION_HPP

#include <vector>
#include "cppweb/Route.hpp"

namespace cppweb {
    class RouteCollection {
    public:
        RouteCollection();
        RouteCollection(std::initializer_list<Route> l);
        std::vector<Route>::iterator begin();
        std::vector<Route>::iterator end();
    protected:
        std::vector<Route> routes;
    };
}

#endif
