#ifndef CPPWEB__REQUEST_FACTORY__HPP
#define CPPWEB__REQUEST_FACTORY__HPP

#include "cppweb/HttpRequest.hpp"
#include <string>

namespace cppweb {
    class HttpRequestFactory {
    public:
        HttpRequestFactory();
        static HttpRequest fromRaw(std::string buffer, int bufferLength);
    };
}

#endif
