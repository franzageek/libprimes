#include "../include/primes.h"

void assert(bool condition, const char* message, int* exitCode)
{
    if (!condition)
    {
        printf("\e[0;31mTEST FAILED\e[0m: %s\n", message);
        *exitCode = 1;
    }
    else
        printf("\e[0;32mTEST PASSED\e[0m: %s\n", message);
}

int test_is_prime()
{
    int exitCode = 0;
    assert(!is_prime(0), "0 should not be prime", &exitCode);
    assert(!is_prime(1), "1 should not be prime", &exitCode);
    assert(is_prime(2), "2 should be prime", &exitCode);
    assert(is_prime(3), "3 should be prime", &exitCode);
    assert(!is_prime(4), "4 should not be prime", &exitCode);
    assert(is_prime(5), "5 should be prime", &exitCode);
    assert(!is_prime(6), "6 should not be prime", &exitCode);
    assert(is_prime(7), "7 should be prime", &exitCode);
    assert(!is_prime(8), "8 should not be prime", &exitCode);
    assert(!is_prime(9), "9 should not be prime", &exitCode);
    assert(is_prime(13), "13 should be prime", &exitCode);
    assert(!is_prime(5876), "5876 should not be prime", &exitCode);
    assert(!is_prime(4294967295), "4294967295 should not be prime", &exitCode);
    assert(!is_prime(83895438ull), "83895438 should not be prime", &exitCode);
    assert(!is_prime(89896589ull), "89896589 should not be prime", &exitCode);
    assert(!is_prime(5156897456ull), "5156897456 should not be prime", &exitCode);
    assert(!is_prime(84956278ull), "84956278 should not be prime", &exitCode);
    assert(!is_prime(799546ull), "799546 should not be prime", &exitCode);
    assert(!is_prime(62484268246ull), "62484268246 should not be prime", &exitCode);
    assert(!is_prime(249249872677624ull), "249249872677624 should not be prime", &exitCode);
    assert(!is_prime(5246864286262454513ull), "5246864286262454513 should not be prime", &exitCode);
    assert(!is_prime(3674736696957957675ull), "3674736696957957675 should not be prime", &exitCode);
    assert(!is_prime(6745374783527282545ull), "6745374783527282545 should not be prime", &exitCode);
    assert(is_prime(347849), "347849 should be prime", &exitCode);
    assert(is_prime(7845367), "7845367 should be prime", &exitCode);
    assert(is_prime(4294967291), "4294967291 should be prime", &exitCode);
    assert(is_prime(2345831), "2345831 should be prime", &exitCode);
    assert(is_prime(6081247ull), "6081247 should be prime", &exitCode);
    assert(is_prime(529527697ull), "529527697 should be prime", &exitCode);
    assert(is_prime(132140563ull), "132140563 should be prime", &exitCode);
    assert(is_prime(142325857ull), "142325857 should be prime", &exitCode);
    assert(is_prime(1142320561ull), "1142320561 should be prime", &exitCode);
    assert(is_prime(1942331359ull), "1942331359 should be prime", &exitCode);
    assert(is_prime(3142327021ull), "3142327021 should be prime", &exitCode);
    assert(is_prime(4762378771ull), "4762378771 should be prime", &exitCode);
    assert(is_prime(4762379683ull), "4762379683 should be prime", &exitCode);
    assert(is_prime(4762379911ull), "4762379911 should be prime", &exitCode);
    assert(is_prime(4762380097ull), "4762380097 should be prime", &exitCode);
    assert(is_prime(4762380473ull), "4762380473 should be prime", &exitCode);
    assert(is_prime(4762366787ull),  "4762366787 should be prime", &exitCode);
    assert(is_prime(4762366789ull),  "4762366789 should be prime", &exitCode);
    assert(is_prime(4762366793ull),  "4762366793 should be prime", &exitCode);
    assert(is_prime(4762366841ull),  "4762366841 should be prime", &exitCode);
    assert(is_prime(4762367039ull),  "4762367039 should be prime", &exitCode);
    assert(is_prime(4762367053ull),  "4762367053 should be prime", &exitCode);
    assert(is_prime(4762367083ull),  "4762367083 should be prime", &exitCode);
    assert(is_prime(4762367087ull),  "4762367087 should be prime", &exitCode);
    assert(is_prime(4762367227ull),  "4762367227 should be prime", &exitCode);
    assert(is_prime(4762367231ull),  "4762367231 should be prime", &exitCode);
    assert(is_prime(4762367237ull),  "4762367237 should be prime", &exitCode);
    assert(is_prime(4762367243ull),  "4762367243 should be prime", &exitCode);
    assert(is_prime(4762367377ull),  "4762367377 should be prime", &exitCode);
    assert(is_prime(4762367399ull),  "4762367399 should be prime", &exitCode);
    assert(is_prime(4762367413ull),  "4762367413 should be prime", &exitCode);
    assert(is_prime(4762367429ull),  "4762367429 should be prime", &exitCode);
    assert(is_prime(4762367683ull),  "4762367683 should be prime", &exitCode);
    assert(is_prime(4762367713ull),  "4762367713 should be prime", &exitCode);
    assert(is_prime(4762367719ull),  "4762367719 should be prime", &exitCode);
    assert(is_prime(4762367737ull),  "4762367737 should be prime", &exitCode);
    assert(is_prime(4762367807ull),  "4762367807 should be prime", &exitCode);
    assert(is_prime(4762367809ull),  "4762367809 should be prime", &exitCode);
    assert(is_prime(4762367837ull),  "4762367837 should be prime", &exitCode);
    assert(is_prime(4762367887ull),  "4762367887 should be prime", &exitCode);
    assert(is_prime(4762368181ull),  "4762368181 should be prime", &exitCode);
    assert(is_prime(4762368217ull),  "4762368217 should be prime", &exitCode);
    assert(is_prime(4762381277ull), "4762381277 should be prime", &exitCode);
    assert(is_prime(4762381469ull), "4762381469 should be prime", &exitCode);
    assert(is_prime(4762381669ull), "4762381669 should be prime", &exitCode);
    assert(is_prime(4762381867ull), "4762381867 should be prime", &exitCode);
    assert(is_prime(4762382137ull), "4762382137 should be prime", &exitCode);
    assert(is_prime(4762382411ull), "4762382411 should be prime", &exitCode);
    assert(is_prime(4762382689ull), "4762382689 should be prime", &exitCode);
    assert(is_prime(4762382957ull), "4762382957 should be prime", &exitCode);
    assert(is_prime(4762383217ull), "4762383217 should be prime", &exitCode);
    assert(is_prime(6242330639ull), "6242330639 should be prime", &exitCode);
    assert(is_prime(7942330229ull), "7942330229 should be prime", &exitCode);
    assert(is_prime(11142329981ull), "11142329981 should be prime", &exitCode);
    assert(is_prime(23942328271ull), "23942328271 should be prime", &exitCode);
    assert(is_prime(65442330901ull), "65442330901 should be prime", &exitCode);
    assert(is_prime(85342319009ull), "85342319009 should be prime", &exitCode);
    assert(is_prime(97142320871ull), "97142320871 should be prime", &exitCode);
    assert(is_prime(113942321917ull), "113942321917 should be prime", &exitCode);
    assert(is_prime(284942325203ull), "284942325203 should be prime", &exitCode);
    assert(is_prime(458942332283ull), "458942332283 should be prime", &exitCode);
    assert(is_prime(572942322833ull), "572942322833 should be prime", &exitCode);
    assert(is_prime(677942319629ull), "677942319629 should be prime", &exitCode);
    assert(is_prime(714942322841ull), "714942322841 should be prime", &exitCode);
    assert(is_prime(855942323807ull), "855942323807 should be prime", &exitCode);
    assert(is_prime(985642334539ull), "985642334539 should be prime", &exitCode);
    assert(is_prime(6827329655557ull), "6827329655557 should be prime", &exitCode);
    assert(is_prime(115610426419ull), "115610426419 should be prime", &exitCode);
    assert(is_prime(662663925631ull), "662663925631 should be prime", &exitCode);
    assert(is_prime(165176138713ull), "165176138713 should be prime", &exitCode);
    assert(is_prime(12745876947092693ull), "12745876947092693 should be prime", &exitCode);
    assert(is_prime(20840247074946023ull), "20840247074946023 should be prime", &exitCode);
    assert(is_prime(114576338131ull), "114576338131 should be prime", &exitCode);
    assert(is_prime(8162430104353859ull), "8162430104353859 should be prime", &exitCode);
    assert(is_prime(1000000016531ull), "1000000016531 should be prime", &exitCode);
    assert(is_prime(18446744073709551557ull), "18446744073709551557 should be prime", &exitCode);
    return exitCode;
}

int main()
{
    int exitCode = 0;
    printf("Testing \"is_prime()\"...\n");
    exitCode = test_is_prime();
    printf("Test exit code: \e[0;36m%d\e[0m (Threads: \e[0;36m%d\e[0m) \n", exitCode, LIBPRIMES_THREADS_NUM);
    exit(exitCode);
}
