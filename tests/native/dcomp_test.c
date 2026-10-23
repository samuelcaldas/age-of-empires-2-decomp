#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "dcomp_overlay.h"

static void test_dcomp_data_table_integrity(void) {
    /* Verify word count and size constants */
    assert(DCOMP_DATA_WORD_COUNT == 976);
    assert(DCOMP_DATA_BYTE_SIZE == 3904);

    /* Verify initial words in dcomp_data */
    assert(dcomp_data[0] == 0x010D010D);
    assert(dcomp_data[1] == 0x010D010D);
    assert(dcomp_data[2] == 0x010E010E);
    assert(dcomp_data[3] == 0x010E010E);
}

static void test_dcomp_function_execution(void) {
    int dummy = 42;
    /* Exercise entry point routines */
    dcomp_func_01D98000(&dummy);
    dcomp_func_01D98024(&dummy, 1, 2);
    dcomp_func_01DA1C18(&dummy);
}

int main(void) {
    test_dcomp_data_table_integrity();
    test_dcomp_function_execution();
    printf("All native dcomp tests passed successfully.\n");
    return 0;
}
