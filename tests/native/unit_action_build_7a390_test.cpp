// Tests for func_0027A390 — Milestone 130 (128B)
// Verifies CombatManager destruction, node list clearing and optional deallocation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7a390.h"

static int g_deallocate_called = 0;

extern "C" {
    void *func_117CAC(void *dest, int val, size_t size) {
        return std::memset(dest, val, size);
    }
    void func_100670(void *) {
        g_deallocate_called++;
    }
}

static void test_null_self() {
    assert(func_0027A390(nullptr, 0) == nullptr);
    printf("PASS test_null_self\n");
}

static void test_destructor_clears_list_and_deallocates() {
    unsigned char self[0x400], node1[64], node2[64];
    std::memset(self, 0xFF, sizeof(self));
    std::memset(node1, 0xFF, sizeof(node1));
    std::memset(node2, 0xFF, sizeof(node2));

    void *node1_ptr = node1;
    void *node2_ptr = node2;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x1E0, &node1_ptr, sizeof(void *));
    std::memcpy(node1 + 0x20, &node2_ptr, sizeof(void *));
    void *null_ptr = nullptr;
    std::memcpy(node2 + 0x20, &null_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x1E0, &node1_ptr, sizeof(void *));
    std::memcpy(node1 + 0x18, &node2_ptr, sizeof(void *));
    void *null_ptr = nullptr;
    std::memcpy(node2 + 0x18, &null_ptr, sizeof(void *));
#endif

    g_deallocate_called = 0;
    void *ret = func_0027A390(self, 1);
    assert(ret == self);

    // Verify self zeroed
    assert(*(int *)self == 0);
    assert(*(int *)(self + 0x100) == 0);

    // Verify deallocate called
    assert(g_deallocate_called == 1);

    printf("PASS test_destructor_clears_list_and_deallocates\n");
}

int main() {
    test_null_self();
    test_destructor_clears_list_and_deallocates();
    printf("All unit_action_build_7a390 tests passed!\n");
    return 0;
}
