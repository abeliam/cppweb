#ifndef CPPWEB__HTTP_RESPONSE__HPP
#define CPPWEB__HTTP_RESPONSE__HPP

#include <map>
#include <string>

namespace cppweb {
    class HttpResponse {
    public:
        HttpResponse();
        HttpResponse(int status, std::string body);
        static HttpResponse view(std::string filename);
        void write(int fd);
    private:
        int status;
        std::string contentType;
        std::string body;
    };
}

#endif
