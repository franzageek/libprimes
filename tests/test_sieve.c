#include "../include/primes.h"
#include <stdio.h>

void assert_cmp(uint64_t n1, uint64_t n2, int* exitCode)
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
    u16 limit = 18;
    u16 test18[] = {2,3,5,7,11,13,17};
    size_t count = 0;
    u64* primes = generate_primes(limit, &count);
    assert_cmp(count, 7, &exitCode);
    for (size_t i = 0; i < count; ++i)
        assert_cmp(primes[i], test18[i], &exitCode);

    free(primes);

    limit = 100;
    u16 test100[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    count = 0;
    primes = generate_primes(limit, &count);
    assert_cmp(count, 25, &exitCode);
    for (size_t i = 0; i < count; ++i)
        assert_cmp(primes[i], test100[i], &exitCode);

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
