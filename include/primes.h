/***************************************************************************
 *      libprimes v1.0.1 - The C Library for Prime Numbers                 *
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
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#define LIBPRIMES_MAJOR_VERSION 1
#define LIBPRIMES_MINOR_VERSION 0
#define LIBPRIMES_PATCH_VERSION 1
#define LIBPRIMES_THREAD_NUM 16
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

bool is_prime(u64 num);
u32* get_prime_fact(u32 num, u16 size);
u64* get_prime_fact_64(u64 num, u32 size);
bool* generate_sieve(u32 limit);
u32* generate_primes(bool* sieve, u32 limit, u32* count);

#ifdef __cplusplus
}
#endif
#endif
