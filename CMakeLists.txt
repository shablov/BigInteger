cmake_minimum_required(VERSION 3.13)
project(BigInteger)

set(CMAKE_CXX_STANDARD 17)

add_library(BigInteger SHARED BigInteger.cpp BigInteger.h)

add_executable(BigIntegerTest main.cpp)
target_link_libraries(BigIntegerTest BigInteger)
