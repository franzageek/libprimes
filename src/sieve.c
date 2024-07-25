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
    bool* sieve;
    u64 start;
    u64 end;
    u64 limit;
    size_t prime_count;
}
thread_data;

void* mark_primes(void* _data)
{
    thread_data* data = (thread_data*)_data;
    bool* sieve = data->sieve;
    u64 start = data->start;
    u64 end = data->end;
    u64 limit = data->limit;

    for (u64 i = start; i <= end; ++i)
    {
        if (sieve[i])
        {
            for(u64 j = i*i; j <= limit; j+=i)
                sieve[j] = false;
        }
    }

    return NULL;
}

void* count_primes(void* _data)
{
    thread_data* data = (thread_data*)_data;
    bool* sieve = data->sieve;
    u64 start = data->start;
    u64 end = data->end;

    for (u64 i = start; i <= end; ++i)
    {
        if (sieve[i])
            ++data->prime_count;
        
    }
    return NULL;
}

u32* generate_primes(u32 limit, size_t* count)
{
    bool* sieve = calloc((limit+1), sizeof(bool));
    if (!sieve || limit < 2 || sieve == NULL) return (u32*)NULL;
    
    memset(sieve, true, limit+1);
    *count = 0;
    if (limit <= 0xFF)
    {
        for (u32 i = 2; i <= limit; ++i)
        {
            if (sieve[i])
            {
                ++*count;
                for(u64 j = i*i; j <= limit; j+=i)
                    sieve[j] = false;
            }
        }
    }
    else
    {
        pthread_t threads[LIBPRIMES_THREAD_NUM];
        thread_data data[LIBPRIMES_THREAD_NUM];

        u32 range = limit/LIBPRIMES_THREAD_NUM;
        for (u16 i = 0; i < LIBPRIMES_THREAD_NUM; ++i)
        {
            data[i].sieve = sieve;
            data[i].start = i * range+2;
            data[i].end = (i == LIBPRIMES_THREAD_NUM-1) ? limit : (i+1) * range+1;
            data[i].limit = limit;
            pthread_create(&threads[i], NULL, mark_primes, &data[i]);
        }

        for (u16 i = 0; i < LIBPRIMES_THREAD_NUM; ++i)
            pthread_join(threads[i], NULL);
        
        for (u16 i = 0; i < LIBPRIMES_THREAD_NUM; ++i)
        {
            data[i].start = i * range+2;
            data[i].end = (i == LIBPRIMES_THREAD_NUM-1) ? limit : (i+1) * range+1;
            data[i].prime_count = 0;
            pthread_create(&threads[i], NULL, count_primes, &data[i]);
        }

        for (u16 i = 0; i < LIBPRIMES_THREAD_NUM; ++i)
        {
            pthread_join(threads[i], NULL);
            *count += data[i].prime_count; 
        }
    }
    

    u32* primes = calloc(*count, sizeof(u32));
    if (!primes || primes == NULL) return (u32*)NULL;
    size_t index = 0;
    for (u32 i = 2; i <= limit && index < *count; ++i)
    {
        if (sieve[i])
            primes[index++] = i;

    }
    free(sieve);
    return primes;
}
