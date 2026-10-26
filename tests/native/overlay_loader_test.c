// tests/native/overlay_loader_test.c
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "overlay_loader.h"

static int s_poll_counts[4] = {0};
static const char *s_last_files[4] = {NULL};
static void *s_last_dests[4] = {NULL};

int func_002240B0(const char *filename, void *dest) {
    if (strcmp(filename, "smenu_cd.bin") == 0) {
        s_poll_counts[0]++;
        s_last_files[0] = filename;
        s_last_dests[0] = dest;
        return (s_poll_counts[0] >= 2) ? 1 : 0;
    }
    if (strcmp(filename, "multimcd.bin") == 0) {
        s_poll_counts[1]++;
        s_last_files[1] = filename;
        s_last_dests[1] = dest;
        return (s_poll_counts[1] >= 2) ? 1 : 0;
    }
    if (strcmp(filename, "thelp_cd.bin") == 0) {
        s_poll_counts[2]++;
        s_last_files[2] = filename;
        s_last_dests[2] = dest;
        return (s_poll_counts[2] >= 2) ? 1 : 0;
    }
    return 1;
}

void test_standalone_streamers(void) {
    // 1. smenu_cd.bin -> 0x01D98000
    int res = func_00300C90();
    assert(res == 1);
    assert(s_poll_counts[0] == 2);
    assert(s_last_dests[0] == (void *)0x01D98000);

    // 2. multimcd.bin -> 0x01D98000
    res = func_00300C60();
    assert(res == 1);
    assert(s_poll_counts[1] == 2);
    assert(s_last_dests[1] == (void *)0x01D98000);

    // 3. thelp_cd.bin -> 0x01F68000
    res = func_003800F0();
    assert(res == 1);
    assert(s_poll_counts[2] == 2);
    assert(s_last_dests[2] == (void *)0x01F68000);

    printf("PASS: test_standalone_streamers\n");
}

int main(void) {
    test_standalone_streamers();
    return 0;
}
