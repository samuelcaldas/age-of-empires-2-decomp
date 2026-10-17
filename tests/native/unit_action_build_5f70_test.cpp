// Tests for func_275F70 — Milestone 88 (148B)
// Verifies ActionBuild construction capacity and completion checks.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_5f70.h"

static int g_f87c0_result = 1;
static int g_f8530_result = 5;

extern "C" int func_002687C0(void *) { return g_f87c0_result; }
extern "C" int func_00268530(void *) { return g_f8530_result; }
extern "C" int func_123350(float val) { return (int)std::round(val); }

static void setup_test(unsigned char *self, unsigned char *proto) {
    std::memset(self, 0, 256);
    std::memset(proto, 0, 256);

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
}

static void test_f87c0_false() {
    unsigned char self[256], proto[256];
    setup_test(self, proto);
    g_f87c0_result = 0;
    assert(func_275F70(self) == 0);
    printf("PASS test_f87c0_false\n");
}

static void test_field_3c_not_9() {
    unsigned char self[256], proto[256];
    setup_test(self, proto);
    g_f87c0_result = 1;
    short f3c = 4;
    std::memcpy(self + 0x3C, &f3c, sizeof(short));
    assert(func_275F70(self) == 1);
    printf("PASS test_field_3c_not_9\n");
}

static void test_reaches_limit() {
    unsigned char self[256], proto[256];
    setup_test(self, proto);
    g_f87c0_result = 1;
    short f3c = 9;
    std::memcpy(self + 0x3C, &f3c, sizeof(short));
    proto[0] = 0x10;
    proto[1] = 20;
    float prog = 15.0f;
    std::memcpy(self + 0x40, &prog, sizeof(float));
    g_f8530_result = 5;
    assert(func_275F70(self) == 1);
    printf("PASS test_reaches_limit\n");
}

int main() {
    test_f87c0_false();
    test_field_3c_not_9();
    test_reaches_limit();
    printf("All unit_action_build_5f70 tests passed!\n");
    return 0;
}
