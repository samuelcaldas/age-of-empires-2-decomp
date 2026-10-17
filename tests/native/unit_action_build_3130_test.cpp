// Tests for func_00273130 — Milestone 72 (488B)
// Verifies savegame stream deserialization via func_00226D90,
// flag configurations, and virtual method dispatches.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_3130.h"

static int g_stream_read_calls = 0;
static int g_v374_calls = 0;
static int g_owner_calls = 0;
static int g_flags_calls = 0;

extern "C" void func_0026AD60(void *, int) {
    g_flags_calls++;
}

extern "C" void func_00194F00(void *, void *, void *) {}
extern "C" void func_0026AD30(void *, int) {}

extern "C" void func_00226D90(void *, void *, int) {
    g_stream_read_calls++;
}

static void mock_v374(void *) { g_v374_calls++; }
static void mock_owner_fn(void *) { g_owner_calls++; }

static void test_deserialization_success() {
    unsigned char self[512] = {};
    unsigned char owner[256] = {};
    void *self_vtbl[256] = {};
    void *owner_vtbl[64] = {};

    self_vtbl[221] = (void *)mock_v374;
    owner_vtbl[34] = (void *)mock_owner_fn;

    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif

    void *owner_vtbl_ptr = owner_vtbl;
    std::memcpy(owner, &owner_vtbl_ptr, sizeof(void *));

    g_stream_read_calls = 0;
    g_v374_calls = 0;
    g_owner_calls = 0;
    g_flags_calls = 0;

    int res = func_00273130(self, (void *)0x1234, (void *)0x5678);

    assert(res == 1);
    assert(g_stream_read_calls == 14);
    assert(g_v374_calls == 1);
    assert(g_owner_calls == 1);
    assert(g_flags_calls == 1);

    printf("PASS test_deserialization_success\n");
}

int main() {
    test_deserialization_success();
    printf("All unit_action_build_3130 tests passed!\n");
    return 0;
}
