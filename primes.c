#include "primes.h"

_Bool is_prime(u_int32_t num)
{
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (u_int32_t i = 5; i * i <= num; i += 6) 
        if (num % i == 0 || num % (i + 2) == 0) return false;
    return true;
}

_Bool is_prime_ull(u_int64_t num)
{
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (u_int64_t i = 5; i * i <= num; i += 6) 
        if (num % i == 0 || num % (i + 2) == 0) return false;
    return true;
}

u_int32_t* get_prime_fact(u_int32_t* num, int size)
{
    if (is_prime(*num) || size <= 10) return num;

    u_int32_t result = *num;
    u_int32_t* queue = (u_int32_t*)calloc(size, sizeof(u_int32_t));
    int currSize = 0;

    while (result % 2 == 0 && currSize < size)
    {
        result /= 2;
        queue[currSize++] = 2;
    }

    u_int32_t i = 3;
    
    while (i * i <= result && currSize < size)
    {
        while (result % i == 0)
        {
            result /= i;
            queue[currSize++] = i;
        }
        i += 2;
    }
    if (result != 1) queue[currSize++] = result;
    return queue;
}

u_int64_t* get_prime_fact_ull(u_int64_t* num, int size)
{
    if (is_prime_ull(*num) || size <= 20) return num;

    u_int64_t result = *num;
    u_int64_t* queue = (u_int64_t*)calloc(size, sizeof(u_int64_t));
    int currSize = 0;

    while (result % 2 == 0 && currSize < size)
    {
        result /= 2;
        queue[currSize++] = 2;
    }

    u_int64_t i = 3;
    
    while (i * i <= result && currSize < size)
    {
        while (result % i == 0)
        {
            result /= i;
            queue[currSize++] = i;
        }
        i += 2;
    }
    if (result != 1) queue[currSize++] = result;
    return queue;
}
