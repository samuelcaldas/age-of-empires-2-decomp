#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Declarations for MSL atoi and atol */
int msl_atoi(const char *str);
long msl_atol(const char *str);

int main(int argc, char **argv) {
    /* Test basic positive numbers */
    assert(msl_atoi("0") == 0);
    assert(msl_atoi("1") == 1);
    assert(msl_atoi("12345") == 12345);
    assert(msl_atol("0") == 0L);
    assert(msl_atol("1") == 1L);
    assert(msl_atol("12345") == 12345L);

    /* Test negative numbers */
    assert(msl_atoi("-1") == -1);
    assert(msl_atoi("-9876") == -9876);
    assert(msl_atol("-1") == -1L);
    assert(msl_atol("-9876") == -9876L);

    /* Test leading whitespace */
    assert(msl_atoi("   42") == 42);
    assert(msl_atoi("\t\n  -99") == -99);
    assert(msl_atol("   42") == 42L);
    assert(msl_atol("\t\n  -99") == -99L);

    /* Test trailing non-digits */
    assert(msl_atoi("100px") == 100);
    assert(msl_atoi("-50xyz") == -50);
    assert(msl_atol("100px") == 100L);
    assert(msl_atol("-50xyz") == -50L);

    /* Test 32-bit limits */
    assert(msl_atoi("2147483647") == 2147483647);
    assert(msl_atoi("-2147483648") == (-2147483647 - 1));

    printf("MSL_ATOI_ATOL_TEST_PASSED\n");
    return 0;
}
