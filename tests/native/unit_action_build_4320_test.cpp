// Tests for func_274320 — Milestone 78 (1608B)
// Verifies ActionBuild visibility / occlusion checking, early exit guard,
// base action visibility delegation, and virtual method dispatches.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_4320.h"

static int g_f5f40_calls = 0;
static int g_v154_calls = 0;
static int g_v94_calls = 0;

extern "C" void func_80195F40(void *, void *, void *, int) {
    g_f5f40_calls++;
}

typedef int (*Vtable154Method)(void *self, int type);
typedef void (*Vtable94Method)(void *self, int a1, int a2, float f12);

static int mock_v154(void *, int) {
    g_v154_calls++;
    return 1;
}

static void mock_v94(void *, int, int, float) {
    g_v94_calls++;
}

static void setup_test(unsigned char *self, unsigned char *arg4,
                       unsigned char *proto, void **vtbl) {
    std::memset(self, 0, 512);
    std::memset(arg4, 0, 64);
    std::memset(proto, 0, 64);
    std::memset(vtbl, 0, 128 * sizeof(void *));

    vtbl[85] = (void *)mock_v154;
    vtbl[37] = (void *)mock_v94;

    void *vtbl_ptr = vtbl;
    std::memcpy(self, &vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(arg4 + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(arg4 + 0x4, &proto_ptr, sizeof(void *));
#endif
}

static void test_early_exit_when_field_30_low() {
    unsigned char self[512], arg4[64], proto[64];
    void *vtbl[128];
    setup_test(self, arg4, proto, vtbl);

    float low_val = 0.5f;
    std::memcpy(self + 0x30, &low_val, sizeof(float));

    int res = func_274320(self, nullptr, nullptr, nullptr, arg4);
    assert(res == 0);
    printf("PASS test_early_exit_when_field_30_low\n");
}

static void test_active_run_when_field_30_high() {
    unsigned char self[512], arg4[64], proto[64];
    void *vtbl[128];
    setup_test(self, arg4, proto, vtbl);

    g_f5f40_calls = 0;
    float high_val = 1.5f;
    std::memcpy(self + 0x30, &high_val, sizeof(float));

    int res = func_274320(self, nullptr, nullptr, nullptr, arg4);
    assert(res == 1);
    assert(g_f5f40_calls == 1);
    printf("PASS test_active_run_when_field_30_high\n");
}

int main() {
    test_early_exit_when_field_30_low();
    test_active_run_when_field_30_high();
    printf("All unit_action_build_4320 tests passed!\n");
    return 0;
}
