cmake_minimum_required(VERSION 3.10)
project(libprimes VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)
include_directories(${CMAKE_SOURCE_DIR})
add_library(primes STATIC primes.c)
install(TARGETS primes DESTINATION lib)
install(FILES primes.h DESTINATION include)
