#include "../include/primes.h"
#include <stdio.h>

void assert_cmp(u64 n1, u64 n2, int* exitCode)
{
    if (n1 != n2)
    {
        printf("\e[0;31mTEST FAILED\e[0m: %llu should match with %llu\n", n1, n2);
        *exitCode = 1;
    }
    else
        printf("\e[0;32mTEST PASSED\e[0m: %llu should match with %llu\n", n1, n2);
}

int test_generate_primes()
{
    int exitCode = 0;
    u32 limit = 18;
    u8 test18[] = {2,3,5,7,11,13,17};
    size_t count = 0;
    u32* primes = generate_primes(limit, &count);
    printf("\e[0;32m**NOTICE:**\e[0m: done generating %zu primes\n", count);
    assert_cmp(count, 7, &exitCode);
    for (size_t i = 0; i < count; ++i)
        assert_cmp(primes[i], test18[i], &exitCode);

    free(primes);

    limit = 0xFFFFF;
    count = 0;
    size_t _count = 0;
    primes = generate_primes(limit, &count);
    printf("\e[0;32m**NOTICE:**\e[0m: done generating %zu primes\n", count);
    for (size_t i = 0; i < count; ++i)
    {
        if (is_prime(primes[i]))
            ++_count;
    }
        
    assert_cmp((u64)count, (u64)_count, &exitCode);
    free(primes);
    return exitCode;
}

int main()
{
    int exitCode = 0;
    printf("Testing \"generate_primes()\"...\n");
    exitCode = test_generate_primes();
    printf("Test exit code: \e[0;36m%d\e[0m (Threads used: \e[0;36m%d\e[0m) \n", exitCode, LIBPRIMES_THREAD_NUM);
    exit(exitCode);
}
