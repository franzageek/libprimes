#include "../include/primes.h"
#include <stdio.h>

void assert_cmp(u64 n1, u64 n2, int* exitCode)
{
    if (n1 != n2)
    {
        printf("\e[0;31mTEST FAILED\e[0m: %" PRIu64 " should match with %" PRIu64 "\n", n1, n2);
        *exitCode = 1;
    }
    else
        printf("\e[0;32mTEST PASSED\e[0m: %" PRIu64 " should match with %" PRIu64 "\n", n1, n2);
}

int test_generate_primes()
{
    int exitCode = 0;
    u32 limit = 18;
    u8 test18[] = {0,0,2,3,0,5,0,7,0,0,0,11,0,13,0,0,0,17};
    bool* sieve = generate_primes(limit);
    printf("\e[0;32m**NOTICE:**\e[0m: done generating primes up to %u\n", limit);
    u32 count = 0;
    for (size_t i = 0; i <= limit; ++i)
    {
        if (sieve[i]) 
        {
            ++count;
            assert_cmp(i, test18[i], &exitCode);
        }
    }
    assert_cmp(count, 7, &exitCode);
    free(sieve);

    limit = 0xFFFFF;
    count = 0;
    size_t _count = 0;
    sieve = generate_primes(limit);
    printf("\e[0;32m**NOTICE:**\e[0m: done generating primes up to %u\n", limit);
    for (size_t i = 0; i <= limit; ++i)
    {
        if (sieve[i] && !is_prime(i))
        {
            printf("\e[0;31mTEST FAILED\e[0m: %lu should be prime\n", i);
            exitCode = 1;
        }
    }
        
    free(sieve);
    return exitCode;
}

int main()
{
    int exitCode = 0;
    printf("Testing \"generate_primes()\"...\n");
    exitCode = test_generate_primes();
    printf("Test exit code: \e[0;36m%d\e[0m\n", exitCode);
    exit(exitCode);
}
