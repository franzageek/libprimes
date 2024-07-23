/***************************************************************************
 *      libprimes v1.0.0 - The C Library for Prime Numbers                 *
 *      primes.h                                                           *
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

#ifndef PRIMES_H
#define PRIMES_H
#include <stdio.h>
#include <stdlib.h>
#define bool _Bool
#define true 1
#define false 0
#ifndef LIBPRIMES_THREADS_NUM
#define LIBPRIMES_THREADS_NUM 8
#endif
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

bool is_prime(u64 num);
u32* get_prime_fact(u32 num, u16 size);
u64* get_prime_fact_ull(u64 num, u32 size);

#endif
