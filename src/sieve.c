/***************************************************************************
 *      libprimes v1.0.1 - The C Library for Prime Numbers                 *
 *      sieve.c                                                           *
 *      Copyright (C) 2020->2024 <franzageek> - all rights reserved        *
 *                                                                         *
 *      This file is part of the primes library.                           *
 *                                                                         *
 *      libprimes is a free & open-source project developed & maintained   *
 *      by <franzageek>. You're welcome to join it & contribute.           *
 *      You can discover it at the following link:                         *
 *      [https://github.com/franzageek/libprimes]                          *
 *                                                                         *
 *      The primes library is free software: you can redistribute it       *
 *      and/or modify it under the terms the MIT License.                  *
 *      libprimes is distributed "as is", in the hope of being             *
 *      useful, but WITHOUT ANY WARRANTY. See license info to know more.   *
 *                                                                         *
 *      The code is licensed to you under the terms stated inside of the   *
 *      MIT License (https://mit-license.org/).                            *
 ***************************************************************************/

#include <string.h>
#include <pthread.h>
#include "../include/primes.h"

typedef struct
{
    bool* is_prime;
    u64 start;
    u64 end;
    u64 limit;
    size_t prime_count;
}
thread_data;

void* mark_primes(void* _data)
{
    thread_data* data = (thread_data*)_data;
    bool* is_prime = data->is_prime;
    u64 start = data->start;
    u64 end = data->end;
    u64 limit = data->limit;

    for (u64 i = start; i <= end; ++i)
    {
        if (is_prime[i])
        {
            ++data->prime_count;
            for(u64 j = i*i; j <= limit; j+=i)
                is_prime[j] = false;

        }
    }

    return NULL;
}

u64* generate_primes(u64 limit, size_t* count)
{
    bool* is_prime = malloc((limit+1) * sizeof(bool));
    memset(is_prime, true, limit+1);

    pthread_t threads[LIBPRIMES_THREAD_NUM];
    thread_data data[LIBPRIMES_THREAD_NUM];

    u64 range = limit/LIBPRIMES_THREAD_NUM;
    for (u16 i = 0; i < LIBPRIMES_THREAD_NUM; ++i)
    {
        data[i].is_prime = is_prime;
        data[i].start = i * range+2;
        data[i].end = (i == LIBPRIMES_THREAD_NUM-1) ? limit : (i+1) * range+1;
        data[i].limit = limit;
        data[i].prime_count = 0;
        pthread_create(&threads[i], NULL, mark_primes, &data[i]);
    }

    for (u16 i = 0; i < LIBPRIMES_THREAD_NUM; ++i)
    {
        pthread_join(threads[i], NULL);
        *count += data[i].prime_count;
    }

    u64* primes = malloc(*count * sizeof(u64));
    size_t index = 0;
    for (u64 i = 2; i <= limit && index < *count; ++i, ++*count)
    {
        if (is_prime[i])
            primes[index++] = i;

    }
    free(is_prime);
    return primes;
}
