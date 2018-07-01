#include "cppweb/HttpRequestFactory.hpp"
#include <iostream>
#include <vector>

class Ascii {
public:
    const static char SP = ' ';
    const static char CR = '\r';
    const static char LF = '\n';
    const static char NLL = '\0';
};

cppweb::HttpRequestFactory::HttpRequestFactory() {

}

cppweb::HttpMethod
cppweb::method(std::string method) {
    if (method == "GET")
        return cppweb::HttpMethod::GET;
    if (method == "HEAD")
        return cppweb::HttpMethod::HEAD;
    if (method == "POST")
        return cppweb::HttpMethod::POST;
    if (method == "PUT")
        return cppweb::HttpMethod::PUT;
    if (method == "DELETE")
        return cppweb::HttpMethod::DELETE;
    if (method == "CONNECT")
        return cppweb::HttpMethod::CONNECT;
    if (method == "OPTIONS")
        return cppweb::HttpMethod::OPTIONS;
    if (method == "TRACE")
        return cppweb::HttpMethod::TRACE;
    if (method == "PATCH")
        return cppweb::HttpMethod::PATCH;
    throw "InvalidMethodName";
}

std::string
cppweb::methodName(cppweb::HttpMethod method) {
    if (method == cppweb::HttpMethod::GET)
        return "GET";
    if (method == cppweb::HttpMethod::HEAD)
        return "HEAD";
    if (method == cppweb::HttpMethod::POST)
        return "POST";
    if (method == cppweb::HttpMethod::PUT)
        return "PUT";
    if (method == cppweb::HttpMethod::DELETE)
        return "DELETE";
    if (method == cppweb::HttpMethod::CONNECT)
        return "CONNECT";
    if (method == cppweb::HttpMethod::OPTIONS)
        return "OPTIONs";
    if (method == cppweb::HttpMethod::TRACE)
        return "TRACE";
    if (method == cppweb::HttpMethod::PATCH)
        return "PATCH";
    throw "InvalidMethodName";
}

cppweb::HttpRequest
cppweb::HttpRequestFactory::fromRaw(std::string data, int dataLength) {
    HttpRequestFactoryState state = HttpRequestFactoryState::READ_HTTP_METHOD_NAME;
    HttpRequestParameters parameters;
    std::vector<char> buffer1;
    std::vector<char> buffer2;

    for(std::string::iterator it = data.begin(); (it != data.end()) && (*it != Ascii::NLL); ++it)
        state = process(state, buffer1, buffer2, *it, parameters);

    HttpRequest request(parameters);

    return request;
}

cppweb::HttpRequestFactoryState
cppweb::HttpRequestFactory::process(HttpRequestFactoryState state, std::vector<char> &buffer1, std::vector<char> &buffer2, char t, HttpRequestParameters &parameters) {
    HttpRequestFactoryState nextState = state;
    switch(state) {
        case HttpRequestFactoryState::READ_HTTP_METHOD_NAME:
            if(t == Ascii::SP) {
                std::string methodName(buffer1.begin(), buffer1.end());
                parameters.method = method(methodName);
                buffer1.clear();
                nextState = HttpRequestFactoryState::READ_URI;
            }
            else {
                buffer1.push_back(t);
            }
            break;
        case HttpRequestFactoryState::READ_URI:
            if (t == Ascii::SP) {
                std::string uri(buffer1.begin(), buffer1.end());
                parameters.uri = uri;
                buffer1.clear();
                nextState = HttpRequestFactoryState::READ_REQUEST_LINE_END;
            }
            else {
                buffer1.push_back(t);
            }
            break;
        case HttpRequestFactoryState::READ_REQUEST_LINE_END:
            if (t == Ascii::LF) {
                nextState = HttpRequestFactoryState::READ_HEADER_NAME;
            }
            break;
        case HttpRequestFactoryState::READ_HEADER_NAME:
            if (t == ':') {
                nextState = HttpRequestFactoryState::READ_HEADER_VALUE;
            }
            else {
                buffer1.push_back(t);
            }
            break;
        case HttpRequestFactoryState::READ_HEADER_VALUE:
            if (t == Ascii::CR || t == Ascii::LF) {
                std::string headerName(buffer1.begin(), buffer1.end());
                std::string headerValue(buffer2.begin(), buffer2.end());
                parameters.headers[headerName] = headerValue;
                buffer1.clear();
                buffer2.clear();
                nextState = HttpRequestFactoryState::READ_HEADER_NAME;
            }
            else {
                if(t != ' ' || buffer2.size() > 0)
                    buffer2.push_back(t);
            }
            break;
    }
    return nextState;
}
