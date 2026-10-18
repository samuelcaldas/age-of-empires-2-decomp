// Tests for func_0027BA90, func_0027BAC0, func_0027BAD0 — Milestone 139 (448B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7ba90.h"

static int g_func_1C0F30_called = 0;
static int g_func_1C1520_called = 0;
static int g_func_1C13C0_called = 0;
static int g_func_27C390_called = 0;
static int g_func_27BC50_called = 0;

static int g_last_offsets[14];
static int g_last_ids[14];
static int g_last_sizes[14];

static int g_last_indices[14];
static int g_last_codes[14];

extern "C" {
    void *func_1C0F30(void *self) {
        g_func_1C0F30_called++;
        return self;
    }
    void func_1C1520(void *, int id, int size, int offset) {
        if (g_func_1C1520_called < 14) {
            g_last_ids[g_func_1C1520_called] = id;
            g_last_sizes[g_func_1C1520_called] = size;
            g_last_offsets[g_func_1C1520_called] = offset;
        }
        g_func_1C1520_called++;
    }
    void func_1C13C0(void *, int index, int code) {
        if (g_func_1C13C0_called < 14) {
            g_last_indices[g_func_1C13C0_called] = index;
            g_last_codes[g_func_1C13C0_called] = code;
        }
        g_func_1C13C0_called++;
    }
    void func_27C390(void *) {
        g_func_27C390_called++;
    }
    void func_27BC50(void *) {
        g_func_27BC50_called++;
    }
}

static void test_ctor_7ba90() {
    unsigned char self[64];
    g_func_1C0F30_called = 0;

    void *ret = func_0027BA90(self);
    assert(ret == self);
    assert(g_func_1C0F30_called == 1);

    // Test alias
    ret = func_0027BAB0(self);
    assert(ret == self);
    assert(g_func_1C0F30_called == 2);

    printf("PASS test_ctor_7ba90\n");
}

static void test_init_table_7bad0() {
    unsigned char self[64];
    g_func_1C1520_called = 0;
    g_func_1C13C0_called = 0;
    g_func_27C390_called = 0;
    g_func_27BC50_called = 0;

    func_0027BAD0(self);

    assert(g_func_1C1520_called == 14);
    assert(g_func_1C13C0_called == 14);
    assert(g_func_27C390_called == 1);
    assert(g_func_27BC50_called == 1);

    // Verify first 3 descriptors
    assert(g_last_ids[0] == 0 && g_last_sizes[0] == 15 && g_last_offsets[0] == 0);
    assert(g_last_ids[1] == 1 && g_last_sizes[1] == 56 && g_last_offsets[1] == 15);
    assert(g_last_ids[2] == 2 && g_last_sizes[2] == 16 && g_last_offsets[2] == 71);

    // Verify total accumulated offset at the end
    int total_offset = 0;
    for (int i = 0; i < 14; ++i) {
        assert(g_last_offsets[i] == total_offset);
        total_offset += g_last_sizes[i];
    }
    assert(total_offset == 161);

    // Verify codes
    assert(g_last_codes[0] == 0x4E20);
    assert(g_last_codes[4] == 0x4E24);
    assert(g_last_codes[5] == 0x4E27);
    assert(g_last_codes[13] == 0x4E2F);

    printf("PASS test_init_table_7bad0\n");
}

static void test_tail_call_7bac0() {
    unsigned char self[64];
    g_func_1C1520_called = 0;
    g_func_1C13C0_called = 0;
    g_func_27C390_called = 0;
    g_func_27BC50_called = 0;

    func_0027BAC0(self);

    assert(g_func_1C1520_called == 14);
    assert(g_func_1C13C0_called == 14);
    assert(g_func_27C390_called == 1);
    assert(g_func_27BC50_called == 1);

    // Test alias
    func_0027BAE0(self);
    assert(g_func_1C1520_called == 28);

    printf("PASS test_tail_call_7bac0\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) test_ctor_7ba90();
        else if (case_num == 1) test_init_table_7bad0();
        else if (case_num == 2) test_tail_call_7bac0();
        return 0;
    }
    test_ctor_7ba90();
    test_init_table_7bad0();
    test_tail_call_7bac0();
    printf("All unit_action_build_7ba90 tests passed!\n");
    return 0;
}
