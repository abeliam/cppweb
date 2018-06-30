#include "cppweb/HttpRequestFactory.hpp"
#include <iostream>
#include <regex>

cppweb::HttpRequestFactory::HttpRequestFactory() {

}

cppweb::HttpRequest cppweb::HttpRequestFactory::fromRaw(std::string buffer, int bufferLength) {

//    RequestFactoryState state = RequestFactoryState::VERSION_LINE;

// 0 : full match
// 1 : method
// 2 : url
// 3 : header name
// 4 : header value


    std::regex requestPattern(
        "^(GET|HEAD|POST|PUT|DELETE|CONNECT|OPTIONS|TRACE|PATCH) (.+) HTTP/1.1(\n|\r\n)"
        "([a-zA-Z0-9]*(\n|\r\n))*"
    );
    std::cout << "buf" << std::endl;
    std::cout << buffer << std::endl;

    std::smatch results;
    if (regex_search(buffer, results, requestPattern)) {
        std::cout << "mathc ok " << std::endl;
        for (size_t i = 0; i < results.size(); ++i) {
            std::cout << i << ": '" << results[i].str() << "'\n";
        }
    }
    else {
        std::cout << "pas ok " << std::endl;
    }

    HttpRequestHeadersMap headers;


    HttpRequest request(HttpMethod::GET, headers);

    return request;
}
