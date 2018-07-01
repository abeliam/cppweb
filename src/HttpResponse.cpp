#include "cppweb/HttpResponse.hpp"
#include <unistd.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <streambuf>

cppweb::HttpResponse::HttpResponse() :
    HttpResponse(200, "it works") {

}

cppweb::HttpResponse::HttpResponse(int status, std::string body) {
    this->status = status;
    this->body = body;
    this->contentType = "text/html; charset=UTF-8";
}

void cppweb::HttpResponse::write(int fd) {
    std::ostringstream oss;
    oss << "HTTP/1.1 " << status << "OK\r\n" << "Content-Type: text/html; charset=UTF-8\r\n\r\n" << body;
    std::string response = oss.str();
    ::write(fd, &response[0], response.size()-1);
}

cppweb::HttpResponse
cppweb::HttpResponse::view(std::string filename) {
    std::ifstream view(filename);
    std::string body((std::istreambuf_iterator<char>(view)), std::istreambuf_iterator<char>());
    HttpResponse response(200, body);

    return response;
}
