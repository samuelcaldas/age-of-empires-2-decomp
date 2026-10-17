// Tests for func_273330 — Milestone 73 (448B)
// Verifies ActionBuild stream serialization via func_00226F70,
// flag reads via func_0026AD20, and conditional target object serialization.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_3330.h"

static int g_base_calls = 0;
static int g_write_calls = 0;
static int g_vtable_calls = 0;

extern "C" void func_00195000(void *, void *) {
    g_base_calls++;
}

extern "C" void func_00226F70(void *, void *, int) {
    g_write_calls++;
}

extern "C" int func_0026AD20(void *, int flag) {
    return (flag == 0x100) ? 1 : 0;
}

typedef void (*Vtable10Method)(void *self, void *stream);

static void mock_v10(void *, void *) {
    g_vtable_calls++;
}

static void test_serialization_c8_null() {
    unsigned char self[512] = {};
    void *stream = (void *)0xBEEF;

    g_base_calls = 0;
    g_write_calls = 0;
    g_vtable_calls = 0;

    func_273330(self, stream);
    assert(g_base_calls == 1);
    assert(g_write_calls == 19);
    assert(g_vtable_calls == 0);
    printf("PASS test_serialization_c8_null\n");
}

static void test_serialization_c8_active() {
    unsigned char self[512] = {};
    void *stream = (void *)0xBEEF;

    g_base_calls = 0;
    g_write_calls = 0;
    g_vtable_calls = 0;

    void *vtbl[8] = {};
    vtbl[4] = (void *)mock_v10;
    void *vtbl_ptr = vtbl;
    void *obj_slot = &vtbl_ptr;
    void *c8_val = &obj_slot;
    std::memcpy(self + 0xC8, &c8_val, sizeof(void *));

    func_273330(self, stream);
    assert(g_base_calls == 1);
    assert(g_write_calls == 19);
    assert(g_vtable_calls == 1);
    printf("PASS test_serialization_c8_active\n");
}

int main() {
    test_serialization_c8_null();
    test_serialization_c8_active();
    printf("All unit_action_build_3330 tests passed!\n");
    return 0;
}
