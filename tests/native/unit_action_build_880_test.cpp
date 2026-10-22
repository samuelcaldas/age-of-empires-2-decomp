// Tests for func_00272880 — Milestone 65 (328B)
// Verifies 4-corner bounding-box probe traversal, target vtable[15] dispatch,
// and output coordinate assignment upon the first successful probe.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_880.h"

static int g_query_count = 0;
static int g_succeed_on_step = -1;

static int mock_corner_query(void *, void *, int, int, int, int, int, void *) {
    int current_step = g_query_count++;
    if (current_step == g_succeed_on_step) {
        return 1;
    }
    return 0;
}

static void setup_test(unsigned char *self, unsigned char *target, void **vtbl) {
    std::memset(self, 0, 64);
    std::memset(target, 0, 256);
    std::memset(vtbl, 0, 16 * sizeof(void *));

    vtbl[15] = (void *)mock_corner_query;
    void *vtbl_ptr = vtbl;
    std::memcpy(target + 0xA0, &vtbl_ptr, sizeof(void *));

    void *owner_ptr = (void *)0x87654321;
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
}

static void test_corner_0_succeeds() {
    unsigned char self[64], target[256];
    void *vtbl[16];
    setup_test(self, target, vtbl);

    float out_x = 0, out_y = 0;
    g_query_count = 0;
    g_succeed_on_step = 0;

    int r = func_00272880(self, target, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(r == 1 && out_x == 10.0f && out_y == 20.0f);
    assert(g_query_count == 1);
    printf("PASS test_corner_0_succeeds\n");
}

static void test_corner_1_succeeds() {
    unsigned char self[64], target[256];
    void *vtbl[16];
    setup_test(self, target, vtbl);

    float out_x = 0, out_y = 0;
    g_query_count = 0;
    g_succeed_on_step = 1;

    int r = func_00272880(self, target, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(r == 1 && out_x == 10.0f && out_y == 17.0f);
    assert(g_query_count == 2);
    printf("PASS test_corner_1_succeeds\n");
}

static void test_corner_2_succeeds() {
    unsigned char self[64], target[256];
    void *vtbl[16];
    setup_test(self, target, vtbl);

    float out_x = 0, out_y = 0;
    g_query_count = 0;
    g_succeed_on_step = 2;

    int r = func_00272880(self, target, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(r == 1 && out_x == 12.0f && out_y == 17.0f);
    assert(g_query_count == 3);
    printf("PASS test_corner_2_succeeds\n");
}

static void test_corner_3_succeeds() {
    unsigned char self[64], target[256];
    void *vtbl[16];
    setup_test(self, target, vtbl);

    float out_x = 0, out_y = 0;
    g_query_count = 0;
    g_succeed_on_step = 3;

    int r = func_00272880(self, target, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(r == 1 && out_x == 12.0f && out_y == 20.0f);
    assert(g_query_count == 4);
    printf("PASS test_corner_3_succeeds\n");
}

static void test_all_corners_fail() {
    unsigned char self[64], target[256];
    void *vtbl[16];
    setup_test(self, target, vtbl);

    float out_x = -99.0f, out_y = -99.0f;
    g_query_count = 0;
    g_succeed_on_step = -1;

    int r = func_00272880(self, target, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(r == 0 && out_x == -99.0f && out_y == -99.0f);
    assert(g_query_count == 4);
    printf("PASS test_all_corners_fail\n");
}

int main() {
    test_corner_0_succeeds();
    test_corner_1_succeeds();
    test_corner_2_succeeds();
    test_corner_3_succeeds();
    test_all_corners_fail();
    printf("All unit_action_build_880 tests passed!\n");
    return 0;
}
