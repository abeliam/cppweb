add_library(cppweb SHARED
    Server.cpp ../include/cppweb/Server.hpp
)

add_executable(server main.cpp)

target_link_libraries(server cppweb)
