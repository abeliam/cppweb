#include "cppweb/Route.hpp"

cppweb::Route::Route() {

}

cppweb::Route::Route(HttpMethod method, std::string path) {
    this->method = method;
    this->path = path;
}

cppweb::Route::Route(HttpMethod method, std::string path, std::function<HttpResponse (HttpRequest)> handler):
    method(method),
    path(path),
    handler(handler) {

}

cppweb::HttpResponse
cppweb::Route::handle(HttpRequest request) {
    return handler(request);
}
