/***************************************************************************
 *      libprimes v1.0.1 - The C Library for Prime Numbers                 *
 *      primes.c                                                           *
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

#include <math.h>
#include <pthread.h>
#include "../include/primes.h"

typedef struct 
{
    u64 num;
    u64 start;
    u64 end;
    bool is_prime;  
} 
thread_data;

void* trial_division(void* _data)
{
    thread_data* data = (thread_data*)_data;
    u64 num = data->num;
    for (u64 i = data->start; i <= data->end; i += 6) 
    {
        if (num % i == 0 || num % (i + 2) == 0) 
        {
            data->is_prime = false;
            return NULL;
        }
    }
        
    data->is_prime = true;
    return NULL;
}

bool is_prime(u64 num) 
{
    if (num <= 1) return false;
    if (num <= 3 || num == 5 || num == 7) return true;
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0) return false;

    if (num <= 0xFFFFFFFF)
    {
        for (u64 i = 5; i*i <= num; i += 6) 
            if (num % i == 0 || num % (i + 2) == 0) return false;
        
        return true;
    }
    else
    {
        #if LIBPRIMES_THREAD_NUM < 2
            #undef LIBPRIMES_THREAD_NUM
            #define LIBPRIMES_THREAD_NUM 8
        #endif

        bool is_prime = false;
        pthread_t threads[LIBPRIMES_THREAD_NUM];
        thread_data data[LIBPRIMES_THREAD_NUM];
        u64 sqrt_num = sqrt(num);
        u64 range = (sqrt_num - 5) / LIBPRIMES_THREAD_NUM +1;
        
        for (u16 i = 0; i < LIBPRIMES_THREAD_NUM; ++i)
        {
            data[i].num = num;
            data[i].start = 5 + i * range;
            data[i].end = (i == LIBPRIMES_THREAD_NUM-1) ? sqrt_num : (5 + (i+1) * range - 1);
            data[i].is_prime = false;
            pthread_create(&threads[i], NULL, trial_division, &data[i]);
        }
        for (u16 i = 0; i < LIBPRIMES_THREAD_NUM; ++i)
        {
            pthread_join(threads[i], NULL);
            is_prime |= data[i].is_prime;
        }
        return is_prime;
    }
}

u32* get_prime_fact(u32 num, u16 size)
{
    u32* queue = calloc(size, sizeof(u32));
    if (is_prime(num) || size <= 10 || queue == NULL) return queue;

    u32 result = num;
    u16 curr_size = 0;

    while (result % 2 == 0 && curr_size < size)
    {
        result /= 2;
        queue[curr_size++] = 2;
    }

    for (u32 i = 3; i * i <= result && curr_size < size; i+=2)
    {
        while (result % i == 0 && curr_size < size)
        {
            result /= i;
            queue[curr_size++] = i;
        }
    }
    if (result != 1 && curr_size < size) queue[curr_size++] = result;
    return queue;
}

u64* get_prime_fact_64(u64 num, u32 size)
{
    u64* queue = calloc(size, sizeof(u64));
    if (is_prime(num) || size <= 20 || queue == NULL) return queue;

    u64 result = num;
    u32 curr_size = 0;

    while (result % 2 == 0 && curr_size < size)
    {
        result /= 2;
        queue[curr_size++] = 2;
    }

    for (u64 i = 3; i * i <= result && curr_size < size; i+=2)
    {
        while (result % i == 0 && curr_size < size)
        {
            result /= i;
            queue[curr_size++] = i;
        }
    }
    if (result != 1 && curr_size < size) queue[curr_size++] = result;
    return queue;
}
