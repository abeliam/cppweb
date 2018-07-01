#include "cppweb/HttpRequest.hpp"
#include <iostream>

cppweb::HttpRequest::HttpRequest() {

}

cppweb::HttpRequest::HttpRequest(HttpMethod method, HttpRequestHeadersMap headers) {

}

cppweb::HttpRequest::HttpRequest(HttpRequestParameters parameters) {
    method = parameters.method;
    uri = parameters.uri;
}
