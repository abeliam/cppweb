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

    class HttpRequest {
    public:
        HttpRequest();
        HttpRequest(HttpMethod method, HttpRequestHeadersMap headers);
    };
}

#endif
