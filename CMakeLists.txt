cmake_minimum_required(VERSION 3.13)
project(brent)

add_executable(brent main.cpp brent.h)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(brent PRIVATE fmt::fmt fmt::fmt-header-only)

set(CMAKE_CXX_STANDARD 17)