cmake_minimum_required(VERSION 3.1)

project(cppweb)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)
