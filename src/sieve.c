/***************************************************************************
 *      libprimes v1.0.1 - The C Library for Prime Numbers                 *
 *      sieve.c                                                            *
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
#include <stdlib.h>
#include "../include/primes.h"

bool* generate_primes(u32 limit)
{
    bool* sieve = calloc((limit+1), sizeof(bool));
    if (!sieve || limit < 2 || sieve == NULL) return (bool*)NULL;
    
    memset(sieve, true, limit+1);
    for (u64 i = 2; i*i <= limit; ++i)
    {
        if (sieve[i])
        {
            for(u64 j = i*i; j <= limit; j+=i)
                sieve[j] = false;
        }
    }
    sieve[0] = sieve[1] = 0;
    return sieve;
}
