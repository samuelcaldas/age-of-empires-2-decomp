// Tests for func_0027A1D0 — Milestone 129 (440B)
// Verifies CombatManager initialization and property copying.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_7a1d0.h"

static int g_func_27A810_called = 0;
extern "C" {
    void *func_117CAC(void *dest, int val, size_t size) {
        return std::memset(dest, val, size);
    }
    int func_123350(float val) {
        return (int)std::floor(val);
    }
    void func_27A810(void *, int) {
        g_func_27A810_called++;
    }
}

static void test_manager_initialization() {
    unsigned char self[0x1000], owner[0x2000], props[0x1000];
    std::memset(self, 0xFF, sizeof(self)); // Pre-fill with non-zero
    std::memset(owner, 0, sizeof(owner));
    std::memset(props, 0, sizeof(props));

    void *props_ptr = props;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(owner + 0x1758, &props_ptr, sizeof(void *));
#else
    std::memcpy(owner + 0xBAC, &props_ptr, sizeof(void *));
#endif

    float p50 = 10.5f, p2a8 = 20.2f, pac = 30.8f, p2b0 = 40.1f;
    float p268 = 50.4f, p260 = 60.9f, p26c = 70.3f, p264 = 80.7f;
    std::memcpy(props + 0x50, &p50, sizeof(float));
    std::memcpy(props + 0x2A8, &p2a8, sizeof(float));
    std::memcpy(props + 0xAC, &pac, sizeof(float));
    std::memcpy(props + 0x2B0, &p2b0, sizeof(float));
    std::memcpy(props + 0x268, &p268, sizeof(float));
    std::memcpy(props + 0x260, &p260, sizeof(float));
    std::memcpy(props + 0x26C, &p26c, sizeof(float));
    std::memcpy(props + 0x264, &p264, sizeof(float));

    g_func_27A810_called = 0;
    void *ret = func_0027A1D0(self, owner, 5);
    assert(ret == self);

    // Verify fields cleared
    assert(*(int *)(self + 0x1E0) == 0);
    assert(*(int *)(self + 0x200) == 0);
    assert(*(int *)(self + 0x500) == 0);

    // Verify rounded props copied
    assert(*(int *)(self + 0x5FC) == 10);
    assert(*(int *)(self + 0x600) == 20);
    assert(*(int *)(self + 0x5EC) == 30);
    assert(*(int *)(self + 0x5F0) == 40);
    assert(*(int *)(self + 0x604) == 50);
    assert(*(int *)(self + 0x608) == 60);
    assert(*(int *)(self + 0x5F4) == 70);
    assert(*(int *)(self + 0x5F8) == 80);

    // Verify func_27A810 called for param_s0 >= 0
    assert(g_func_27A810_called == 1);

    printf("PASS test_manager_initialization\n");
}

int main() {
    test_manager_initialization();
    printf("All unit_action_build_7a1d0 tests passed!\n");
    return 0;
}
