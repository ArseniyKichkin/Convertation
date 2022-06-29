cmake_minimum_required(VERSION 3.22)
project(Kepler)

set(CMAKE_CXX_STANDARD 17)


enable_testing()


add_subdirectory(tests)
add_executable(Kepler1 main.cpp)
add_library(Kepler STATIC Kepler.cpp Kepler.hpp)
target_link_libraries(Kepler1 Kepler)