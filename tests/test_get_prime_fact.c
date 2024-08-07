#include "../include/primes.h"

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

int test_get_prime_factors()
{
    int exitCode = 0;
    const int queue_size = 25;
    int i = 0;
    uint32_t num = (uint32_t)2*2*11*97*97;
    uint64_t result = 1;
    uint32_t* queue = get_prime_fact(num, queue_size);
    while (queue[i] != 0)
        result *= queue[i++];

    assert_cmp(result, num, &exitCode);
    free(queue);
    queue = NULL;

    i = 0;
    num = (uint32_t)3*3*11*13*13*97*163;
    result = 1;
    queue = get_prime_fact(num, queue_size);
    while (queue[i] != 0)
        result *= queue[i++];

    assert_cmp(result, num, &exitCode);
    free(queue);
    queue = NULL;

    i = 0;
    uint64_t num64 = (uint64_t)2*3*7*17*3301*60601*20573039ull;
    result = 1;
    uint64_t* queue64 = get_prime_fact_ull(num64, queue_size);
    while (queue64[i] != 0)
        result *= queue64[i++];

    assert_cmp(result, num64, &exitCode);
    free(queue64);
    queue64 = NULL;

    i = 0;
    num64 = (uint64_t)17*3301*5156897456*4762379911ull;
    result = 1;
    queue64 = get_prime_fact_ull(num64, queue_size);
    while (queue64[i] != 0)
        result *= queue64[i++];

    assert_cmp(result, num64, &exitCode);
    free(queue64);
    queue64 = NULL;

    i = 0;
    num64 = (uint64_t)3*3*3*5*5*11*16993*36073*807379ull;
    result = 1;
    queue64 = get_prime_fact_ull(num64, queue_size);
    while (queue64[i] != 0)
        result *= queue64[i++];

    assert_cmp(result, num64, &exitCode);
    free(queue64);
    queue64 = NULL;

    num64 = 3;
    queue64 = get_prime_fact_ull(num64, 10); 
    assert_cmp(*queue64, 0, &exitCode);
    free(queue64);
    return exitCode;
}

int main()
{
    int exitCode = 0;
    printf("Testing \"get_prime_fact()\"...\n");
    exitCode = test_get_prime_factors();
    printf("Test exit code: \e[0;36m%d\e[0m (Threads used: \e[0;36m%d\e[0m) \n", exitCode, LIBPRIMES_THREADS_NUM);
    exit(exitCode);
}
