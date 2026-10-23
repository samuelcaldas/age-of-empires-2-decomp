#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "lobby_overlay.h"

static void test_lobby_data_table_integrity(void) {
    /* Verify word count and size constants */
    assert(LOBBY_DATA_WORD_COUNT == 30224);
    assert(LOBBY_DATA_BYTE_SIZE == 120896);

    /* Verify magic/header words in lobby_data */
    assert(lobby_data[0] == 0x83BF0000);
    assert(lobby_data[1] == 0x83C183C0);
    assert(lobby_data[2] == 0x83C383C2);
    assert(lobby_data[3] == 0x83C583C4);
}

static void test_lobby_function_execution(void) {
    int dummy = 42;
    /* Exercise entry point routines */
    lobby_func_01D98000(&dummy);
    lobby_func_01D98010(&dummy, 1, 2);
    lobby_func_01DEA5B0(&dummy);
}

int main(void) {
    test_lobby_data_table_integrity();
    test_lobby_function_execution();
    printf("All native lobby tests passed successfully.\n");
    return 0;
}
