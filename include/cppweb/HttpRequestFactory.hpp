#ifndef CPPWEB__REQUEST_FACTORY__HPP
#define CPPWEB__REQUEST_FACTORY__HPP

#include "cppweb/HttpRequest.hpp"
#include <string>
#include <vector>

namespace cppweb {

    enum class HttpRequestFactoryState {
        READ_HTTP_METHOD_NAME,
        READ_URI,
        READ_REQUEST_LINE_END,
        READ_HEADER_NAME,
        READ_HEADER_VALUE
    };


    HttpMethod method(std::string method);

    std::string methodName(HttpMethod method);

    class HttpRequestFactory {
    public:
        HttpRequestFactory();
        HttpRequest fromRaw(std::string buffer, int bufferLength);
    private:
        HttpRequestFactoryState process(HttpRequestFactoryState state, std::vector<char> &buffer1, std::vector<char> &buffer2, char t, HttpRequestParameters &parameters);
    };
}

#endif
