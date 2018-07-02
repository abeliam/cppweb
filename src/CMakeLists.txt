add_library(cppweb SHARED
    Server.cpp ../include/cppweb/Server.hpp
    HttpRequest.cpp ../include/cppweb/HttpRequest.hpp
    HttpRequestFactory.cpp ../include/cppweb/HttpRequestFactory.hpp
    HttpResponse.cpp ../include/cppweb/HttpResponse.hpp
    Router.cpp ../include/cppweb/Router.hpp
    Route.cpp ../include/cppweb/Route.hpp
    RouteCollection.cpp ../include/cppweb/RouteCollection.hpp
    RouteTree.cpp ../include/cppweb/RouteTree.hpp
    RouteNode.cpp ../include/cppweb/RouteNode.hpp
)
