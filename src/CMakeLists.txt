add_library(cppweb SHARED
    Server.cpp ../include/cppweb/Server.hpp
    HttpRequest.cpp ../include/cppweb/HttpRequest.hpp
    HttpRequestFactory.cpp ../include/cppweb/HttpRequestFactory.hpp
)

add_executable(server main.cpp)

target_link_libraries(server cppweb)
