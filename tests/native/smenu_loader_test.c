// tests/native/smenu_loader_test.c
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "smenu_loader.h"

static int s_overlay_read_count = 0;
static const char *s_last_filename = NULL;
static void *s_last_dest = NULL;

int func_002240B0(const char *filename, void *dest) {
    s_overlay_read_count++;
    s_last_filename = filename;
    s_last_dest = dest;
    return (s_overlay_read_count >= 2) ? 1 : 0; // Succeed on second poll
}

void test_smenu_loader(void) {
    s_overlay_read_count = 0;
    int res = func_00300C90();
    assert(res == 1);
    assert(s_overlay_read_count == 2);
    assert(strcmp(s_last_filename, "smenu_cd.bin") == 0);
    assert(s_last_dest == (void *)0x01D98000);
    printf("PASS: test_smenu_loader\n");
}

int main(void) {
    test_smenu_loader();
    return 0;
}
