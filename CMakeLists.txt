cmake_minimum_required(VERSION 3.13)
project(rootApproximation)

add_executable(rootApproximation main.cpp iteration.h bisection.h secant.h newton.h brent.h dekker.h)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(rootApproximation PRIVATE fmt::fmt fmt::fmt-header-only)

set(CMAKE_CXX_STANDARD 17)