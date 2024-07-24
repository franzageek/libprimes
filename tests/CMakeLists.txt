add_executable(test_sieve test_sieve.c)
add_executable(test_get_prime_fact test_get_prime_fact.c)
add_executable(test_is_prime test_is_prime.c)

target_link_libraries(test_sieve PRIVATE primes pthread)
target_link_libraries(test_get_prime_fact PRIVATE primes pthread)
target_link_libraries(test_is_prime PRIVATE primes pthread)

add_test(NAME test_sieve COMMAND test_sieve)
add_test(NAME test_get_prime_fact COMMAND test_get_prime_fact)
add_test(NAME test_is_prime COMMAND test_is_prime)

target_compile_options(test_sieve PRIVATE -O2)
target_compile_options(test_get_prime_fact PRIVATE -O2)
target_compile_options(test_is_prime PRIVATE -O2)