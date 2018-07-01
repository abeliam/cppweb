#ifndef CPPWEB__HTTP_REQUEST__HPP
#define CPPWEB__HTTP_REQUEST__HPP

#include <map>
#include <string>

namespace cppweb {
    typedef std::map<std::string, std::string> HttpRequestHeadersMap;

    enum class HttpMethod {
        GET,
        HEAD,
        POST,
        PUT,
        DELETE,
        CONNECT,
        OPTIONS,
        TRACE,
        PATCH
    };

    struct HttpRequestParameters {
        HttpMethod method;
        HttpRequestHeadersMap headers;
        std::string uri;
    };

    class HttpRequest {
    public:
        HttpRequest();
        HttpRequest(HttpRequestParameters parameters);
        HttpRequest(HttpMethod method, HttpRequestHeadersMap headers);
        HttpMethod method;
        std::string uri;
    };
}

#endif
