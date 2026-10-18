// Tests for func_0027B700 — Milestone 136 (272B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7b700.h"

static unsigned char g_free_entry[64];
static int g_func_27B6B0_called = 0;
static void *g_return_entry = g_free_entry;

static int g_func_117CAC_called = 0;
static int g_func_27B950_called = 0;
static void *g_last_dispatched_entry = 0;

static unsigned char g_world_data[0x1000];
static unsigned char g_world_sub[0x100];
static void *g_world_sub_ptr = g_world_sub;
void *D_004E3180 = g_world_data;

extern "C" {
    void *func_27B6B0(void *) {
        g_func_27B6B0_called++;
        return g_return_entry;
    }
    void *func_117CAC(void *dest, int val, unsigned int size) {
        g_func_117CAC_called++;
        return std::memset(dest, val, size);
    }
    void func_27B950(void *, void *entry) {
        g_func_27B950_called++;
        g_last_dispatched_entry = entry;
    }
}

static void test_zero_count() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));
    int count = 0;
    std::memcpy(self + 0x5DC, &count, sizeof(int));

    g_func_27B6B0_called = 0;
    func_0027B700(self, 0xB, 5, 1.0f, 2.0f);
    assert(g_func_27B6B0_called == 0);
    printf("PASS test_zero_count\n");
}

static void test_no_free_slot() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));
    int count = 10;
    std::memcpy(self + 0x5DC, &count, sizeof(int));

    g_func_27B6B0_called = 0;
    g_return_entry = 0; // Simulate full pool
    func_0027B700(self, 0xB, 5, 1.0f, 2.0f);
    assert(g_func_27B6B0_called == 1);
    assert(*(void **)(self + 0x1E0) == 0);
    printf("PASS test_no_free_slot\n");
}

static void test_successful_event_insertion_and_dispatch() {
    unsigned char self[0x1000];
    std::memset(self, 0, sizeof(self));
    std::memset(g_free_entry, 0xAA, sizeof(g_free_entry));
    std::memset(g_world_data, 0, sizeof(g_world_data));
    std::memset(g_world_sub, 0, sizeof(g_world_sub));

    // Setup world timestamp at *(int *)(*(char **)(D_004E3180 + 0x404) + 0x18)
    void *sub_ptr = g_world_sub;
    std::memcpy(g_world_data + 0x404, &sub_ptr, sizeof(void *));
    int expected_timestamp = 12345;
    std::memcpy(g_world_sub + 0x18, &expected_timestamp, sizeof(int));

    int count = 7;
    std::memcpy(self + 0x5DC, &count, sizeof(int));
    void *old_head = (void *)0x11223344;
    std::memcpy(self + 0x1E0, &old_head, sizeof(void *));

    g_return_entry = g_free_entry;
    g_func_27B950_called = 0;

    // Test with type 0xB (11) -> should trigger func_27B950
    func_0027B700(self, 0xB, 42, 10.5f, 20.5f);

    // Verify linked list
    assert(*(void **)(self + 0x1E0) == (void *)g_free_entry);
    assert(*(void **)(g_free_entry + 0x18) == old_head);

    // Verify fields
    assert(*(char *)(g_free_entry + 0x0) == 0xB);
    assert(*(int *)(g_free_entry + 0x4) == 7);
    assert(*(int *)(g_free_entry + 0x8) == expected_timestamp);
    assert(*(float *)(g_free_entry + 0xC) == 10.5f);
    assert(*(float *)(g_free_entry + 0x10) == 20.5f);
    assert(*(float *)(g_free_entry + 0x14) == 42.0f);

    assert(g_func_27B950_called == 1);
    assert(g_last_dispatched_entry == (void *)g_free_entry);

    // Test with type 0xC (12) -> should NOT trigger func_27B950
    g_func_27B950_called = 0;
    func_0027B700(self, 0xC, 99, 1.0f, 2.0f);
    assert(g_func_27B950_called == 0);

    printf("PASS test_successful_event_insertion_and_dispatch\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) test_zero_count();
        else if (case_num == 1) test_no_free_slot();
        else if (case_num == 2) test_successful_event_insertion_and_dispatch();
        return 0;
    }
    test_zero_count();
    test_no_free_slot();
    test_successful_event_insertion_and_dispatch();
    printf("All unit_action_build_7b700 tests passed!\n");
    return 0;
}
