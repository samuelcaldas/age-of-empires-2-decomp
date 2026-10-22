#include <assert.h>
#include <stdio.h>

void msl_srand(unsigned int seed);
int msl_rand(void);

int main(int argc, char **argv) {
    /* Test deterministic linear congruential generator */
    msl_srand(1);
    int r1 = msl_rand();
    int r2 = msl_rand();
    int r3 = msl_rand();

    /* Using LCG: next = next * 1103515245 + 12345; return next & 0x7FFFFFFF; */
    unsigned int expected1 = (1U * 1103515245U + 12345U) & 0x7FFFFFFFU;
    unsigned int expected2 = (expected1 * 1103515245U + 12345U) & 0x7FFFFFFFU;
    unsigned int expected3 = (expected2 * 1103515245U + 12345U) & 0x7FFFFFFFU;

    assert((unsigned int)r1 == expected1);
    assert((unsigned int)r2 == expected2);
    assert((unsigned int)r3 == expected3);

    /* Reset seed and check repeatable sequence */
    msl_srand(1);
    assert(msl_rand() == r1);
    assert(msl_rand() == r2);

    /* Check with seed 0 */
    msl_srand(0);
    int r_zero = msl_rand();
    assert((unsigned int)r_zero == (12345U & 0x7FFFFFFFU));

    printf("MSL_RAND_SRAND_TEST_PASSED\n");
    return 0;
}
