cmake_minimum_required(VERSION 3.27)
project(StringClient)

set(CMAKE_CXX_STANDARD 17)

include_directories("../StringLibrary")

add_executable(StringClient main.cpp)

link_directories("../StringLibrary/cmake-build-release")

target_link_libraries(StringClient PRIVATE StringLibrary)
