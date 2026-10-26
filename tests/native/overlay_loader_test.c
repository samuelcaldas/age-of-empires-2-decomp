// tests/native/overlay_loader_test.c
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "overlay_loader.h"

static int s_poll_counts[8] = {0};
static const char *s_last_files[8] = {NULL};
static void *s_last_dests[8] = {NULL};

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
    if (strcmp(filename, "mo_ov_cd.bin") == 0) {
        s_poll_counts[3]++;
        s_last_files[3] = filename;
        s_last_dests[3] = dest;
        return (s_poll_counts[3] >= 2) ? 1 : 0;
    }
    if (strcmp(filename, "rmmmemcd.bin") == 0) {
        s_poll_counts[4]++;
        s_last_files[4] = filename;
        s_last_dests[4] = dest;
        return (s_poll_counts[4] >= 2) ? 1 : 0;
    }
    if (strcmp(filename, "hist_cd.bin") == 0) {
        s_poll_counts[5]++;
        s_last_files[5] = filename;
        s_last_dests[5] = dest;
        return (s_poll_counts[5] >= 2) ? 1 : 0;
    }
    if (strcmp(filename, "dcomp_cd.bin") == 0) {
        s_poll_counts[6]++;
        s_last_files[6] = filename;
        s_last_dests[6] = dest;
        return (s_poll_counts[6] >= 2) ? 1 : 0;
    }
    return 1;
}

/* Mock entry points and helper functions */
static int s_mo_ov_entry_called = 0;
static void *s_last_36cc40_handle = NULL;
static int s_rmmmem_entry_called = 0;
static int s_hist_entry_called = 0;
static int s_func_257e40_called = 0;

static int s_dcomp_init_called = 0;
static int s_dcomp_dispatch_called = 0;

void *mock_mo_ov_entry(void) {
    s_mo_ov_entry_called++;
    return (void *)0x55AA55AA;
}

void func_0036CC40(void *handle) {
    s_last_36cc40_handle = handle;
}

void mock_rmmmem_entry(void) {
    s_rmmmem_entry_called++;
}

void mock_hist_entry(void) {
    s_hist_entry_called++;
}

void func_257E40(void *ctx) {
    (void)ctx;
    s_func_257e40_called++;
}

void mock_dcomp_init(void) {
    s_dcomp_init_called++;
}

void mock_dcomp_dispatch(void) {
    s_dcomp_dispatch_called++;
}

void test_standalone_streamers(void) {
    int res = func_00300C90();
    assert(res == 1);
    assert(s_poll_counts[0] == 2);
    assert(s_last_dests[0] == (void *)0x01D98000);

    res = func_00300C60();
    assert(res == 1);
    assert(s_poll_counts[1] == 2);
    assert(s_last_dests[1] == (void *)0x01D98000);

    res = func_003800F0();
    assert(res == 1);
    assert(s_poll_counts[2] == 2);
    assert(s_last_dests[2] == (void *)0x01F68000);

    printf("PASS: test_standalone_streamers\n");
}

void test_dynamic_invokers(void) {
    g_mo_ov_entry = mock_mo_ov_entry;
    g_rmmmem_entry = mock_rmmmem_entry;
    g_hist_entry = mock_hist_entry;

    // 1. mo_ov_cd.bin -> 0x01ED7000
    s_mo_ov_entry_called = 0;
    s_last_36cc40_handle = NULL;
    func_0036C350();
    assert(s_poll_counts[3] == 2);
    assert(s_last_dests[3] == (void *)0x01ED7000);
    assert(g_mo_ov_handle == (void *)0x55AA55AA);
    assert(s_last_36cc40_handle == (void *)0x55AA55AA);

    // 2. rmmmemcd.bin -> 0x01D98000 when field_13C == 0
    char screen_obj[0x200] = {0};
    *(int *)(screen_obj + 0x13C) = 0;
    s_rmmmem_entry_called = 0;
    int res = func_0022F550(screen_obj);
    assert(res == 1);
    assert(s_poll_counts[4] == 2);
    assert(s_last_dests[4] == (void *)0x01D98000);
    assert(s_rmmmem_entry_called == 1);

    // 2b. rmmmemcd.bin skipped when field_13C != 0
    *(int *)(screen_obj + 0x13C) = 1;
    res = func_0022F550(screen_obj);
    assert(res == 0);
    assert(s_poll_counts[4] == 2); // unchanged

    // 3. hist_cd.bin -> 0x01D98000
    s_hist_entry_called = 0;
    s_func_257e40_called = 0;
    res = func_00258E40(NULL);
    assert(res == 1);
    assert(s_poll_counts[5] == 2);
    assert(s_last_dests[5] == (void *)0x01D98000);
    assert(s_func_257e40_called == 1);
    assert(s_hist_entry_called == 1);

    printf("PASS: test_dynamic_invokers\n");
}

void test_dcomp_loaders(void) {
    g_dcomp_init = mock_dcomp_init;
    g_dcomp_dispatch = mock_dcomp_dispatch;

    // 1. func_00226DE0
    g_dcomp_ptr = NULL;
    s_poll_counts[6] = 0;
    func_00226DE0();
    assert(s_poll_counts[6] == 2);
    assert(s_last_dests[6] == (void *)0x01D98000);
    assert(g_dcomp_ptr == (void *)DCOMP_OVERLAY_PTR);

    // 2. func_00226FA0 with g_dcomp_loaded == 0
    g_dcomp_loaded = 0;
    g_dcomp_ptr = NULL;
    s_poll_counts[6] = 0;
    s_dcomp_init_called = 0;
    s_dcomp_dispatch_called = 0;

    func_00226FA0();
    assert(s_poll_counts[6] == 2);
    assert(g_dcomp_loaded == 1);
    assert(g_dcomp_ptr == (void *)DCOMP_OVERLAY_PTR);
    assert(s_dcomp_init_called == 1);
    assert(s_dcomp_dispatch_called == 1);

    // 3. func_00226FA0 with g_dcomp_loaded == 1 (cached, skips func_002240B0)
    func_00226FA0();
    assert(s_poll_counts[6] == 2); // unchanged, no reload
    assert(s_dcomp_init_called == 1); // init not called again
    assert(s_dcomp_dispatch_called == 2); // dispatch called

    printf("PASS: test_dcomp_loaders\n");
}

int main(void) {
    test_standalone_streamers();
    test_dynamic_invokers();
    test_dcomp_loaders();
    return 0;
}
