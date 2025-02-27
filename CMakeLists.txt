
cmake_minimum_required(VERSION 3.10)
project(PDF_GRAPHS)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(myLib SHARED src/Wrapper.cpp)

add_executable(PDF_GRAPHS src/main.cpp src/CSV.cpp)
