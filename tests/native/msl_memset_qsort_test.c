#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *msl_memset(void *dest, int c, size_t n);
void msl_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));

static int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main(int argc, char **argv) {
    /* --- memset tests --- */
    char buf[256];
    void *ret;

    /* Zero length */
    buf[0] = 42;
    ret = msl_memset(buf, 0, 0);
    assert(ret == buf);
    assert(buf[0] == 42);

    /* Small size (1 byte) */
    ret = msl_memset(buf, 0x5A, 1);
    assert(ret == buf);
    assert((unsigned char)buf[0] == 0x5A);

    /* 7 bytes (under 8-byte threshold) */
    ret = msl_memset(buf, 0x11, 7);
    assert(ret == buf);
    for (int i = 0; i < 7; i++) {
        assert((unsigned char)buf[i] == 0x11);
    }

    /* 25 bytes (between 8 and 32 bytes) */
    ret = msl_memset(buf, 0x22, 25);
    assert(ret == buf);
    for (int i = 0; i < 25; i++) {
        assert((unsigned char)buf[i] == 0x22);
    }

    /* 128 bytes (multiple 32-byte chunks) */
    ret = msl_memset(buf, 0x7F, 128);
    assert(ret == buf);
    for (int i = 0; i < 128; i++) {
        assert((unsigned char)buf[i] == 0x7F);
    }

    /* Unaligned destination */
    ret = msl_memset(buf + 3, 0x33, 40);
    assert(ret == buf + 3);
    for (int i = 0; i < 40; i++) {
        assert((unsigned char)buf[3 + i] == 0x33);
    }

    /* --- qsort tests --- */
    /* Empty array */
    int empty_arr[1] = {0};
    msl_qsort(empty_arr, 0, sizeof(int), compare_ints);

    /* Single element */
    int single_arr[1] = {42};
    msl_qsort(single_arr, 1, sizeof(int), compare_ints);
    assert(single_arr[0] == 42);

    /* Already sorted */
    int sorted_arr[5] = {1, 2, 3, 4, 5};
    msl_qsort(sorted_arr, 5, sizeof(int), compare_ints);
    for (int i = 0; i < 5; i++) {
        assert(sorted_arr[i] == i + 1);
    }

    /* Reverse sorted */
    int rev_arr[5] = {5, 4, 3, 2, 1};
    msl_qsort(rev_arr, 5, sizeof(int), compare_ints);
    for (int i = 0; i < 5; i++) {
        assert(rev_arr[i] == i + 1);
    }

    /* Larger array with duplicates and negatives */
    int test_arr[] = {10, -5, 3, 10, 0, -20, 8, 3, 99, -1};
    size_t n_items = sizeof(test_arr) / sizeof(test_arr[0]);
    msl_qsort(test_arr, n_items, sizeof(int), compare_ints);
    for (size_t i = 1; i < n_items; i++) {
        assert(test_arr[i - 1] <= test_arr[i]);
    }

    printf("MSL_MEMSET_QSORT_TEST_PASSED\n");
    return 0;
}
