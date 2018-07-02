#include <cstdlib>
#include <functional>
#include <iostream>
#include "cppweb/Router.hpp"
#include "cppweb/Route.hpp"
#include "cppweb/RouteCollection.hpp"
#include "cppweb/HttpRequest.hpp"
#include "cppweb/HttpResponse.hpp"

using namespace cppweb;

int main() {
    std::cout << "testing router ...." << std::endl;

    std::function<HttpResponse (HttpRequest)> sayHello = [](HttpRequest request) {
        return HttpResponse(200, "hello world");
    };

    RouteCollection routes {
        Route(HttpMethod::GET, "foo/bar", sayHello),
        Route(HttpMethod::GET, "foo/baz", sayHello),
        Route(HttpMethod::GET, "hello", sayHello)
    };

    Router router(routes);

    router.match("hello");
    router.match("foo/bar");
    router.match("foo/baz");

    return EXIT_SUCCESS;
}
