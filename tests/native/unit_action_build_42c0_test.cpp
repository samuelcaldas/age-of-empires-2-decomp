// Tests for func_002742C0 — Milestone 77 (96B)
// Verifies entity prototype type check, flag 0x200 configuration,
// and virtual method dispatch at vtable[32] (offset 0x80).
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_42c0.h"

static int g_f80_calls = 0;
static int g_flags_calls = 0;
static int g_last_flag = 0;

extern "C" void func_0026AD30(void *, int flag) {
    g_flags_calls++;
    g_last_flag = flag;
}

static void mock_v80(void *) {
    g_f80_calls++;
}

static void setup_test(unsigned char *self, unsigned char *proto, void **vtbl) {
    std::memset(self, 0, 128);
    std::memset(proto, 0, 64);
    std::memset(vtbl, 0, 64 * sizeof(void *));

    vtbl[32] = (void *)mock_v80;
    void *vtbl_ptr = vtbl;
    std::memcpy(self, &vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif
}

static void test_non_matching_type_triggers_method() {
    unsigned char self[128], proto[64];
    void *vtbl[64];
    setup_test(self, proto, vtbl);

    g_f80_calls = 0;
    g_flags_calls = 0;
    short type = 0x10;
    std::memcpy(proto + 0xE, &type, sizeof(short));

    func_002742C0(self);
    assert(g_f80_calls == 1);
    assert(g_flags_calls == 1);
    assert(g_last_flag == 0x200);
    printf("PASS test_non_matching_type_triggers_method\n");
}

static void test_excluded_types_skipped() {
    unsigned char self[128], proto[64];
    void *vtbl[64];
    setup_test(self, proto, vtbl);

    short types[] = {0x3A, 0x1, 0x2A};
    for (int i = 0; i < 3; ++i) {
        g_f80_calls = 0;
        g_flags_calls = 0;
        std::memcpy(proto + 0xE, &types[i], sizeof(short));
        func_002742C0(self);
        assert(g_f80_calls == 0);
        assert(g_flags_calls == 0);
    }
    printf("PASS test_excluded_types_skipped\n");
}

int main() {
    test_non_matching_type_triggers_method();
    test_excluded_types_skipped();
    printf("All unit_action_build_42c0 tests passed!\n");
    return 0;
}
