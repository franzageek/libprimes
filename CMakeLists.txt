cmake_minimum_required(VERSION 3.10)
project(libprimes VERSION 1.0.1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS_RELEASE "-O2 -g -DNDEBUG -Os")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -ggdb -Wall -Wextra -pedantic")

option(BUILD_TESTS "Build tests" ON)

add_library(primes STATIC src/primes.c src/sieve.c)
target_include_directories(primes PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(primes PRIVATE pthread m)

install(TARGETS primes DESTINATION lib)
install(FILES include/primes.h DESTINATION include)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

target_compile_options(primes PRIVATE -Wall -Wextra)
