#ifndef PRIMES_H
#define PRIMES_H
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

_Bool is_prime(u_int32_t num);
_Bool is_prime_ull(u_int64_t num);
u_int32_t* get_prime_fact(u_int32_t* num, int size);
u_int64_t* get_prime_fact_ull(u_int64_t* num, int size);

#endif
