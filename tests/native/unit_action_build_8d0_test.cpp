// Tests for func_002718D0 — ActionBuild factory (0x2718D0, 180B)
// Verifies slot check, type-70 allocation, vtable[3] dispatch, and return value.
#include <cassert>
#include <cstdio>
#include "unit_action_build_8d0.h"

// --- Stubs ---

static void   *g_slot_arg      = nullptr;
static void   *g_eba00_result  = nullptr;
static int     g_alloc_type    = -1;
static void   *g_alloc_result  = nullptr;

struct VtableState {
    void        *this_arg;
    ActionRebind *self_arg;
    void        *other_arg;
    int          flag_arg;
    float        x_arg;
    float        y_arg;
    float        z_arg;
    int          call_count;
};
static VtableState g_vt = {};

static void vtable_stub(void *obj, ActionRebind *self, void *other,
                        int flag, float x, float y, float z) {
    g_vt.this_arg  = obj;
    g_vt.self_arg  = self;
    g_vt.other_arg = other;
    g_vt.flag_arg  = flag;
    g_vt.x_arg     = x;
    g_vt.y_arg     = y;
    g_vt.z_arg     = z;
    g_vt.call_count++;
}

// vtable layout: [0][1][2][3] — index 3 = offset 12
typedef void (*VtableMethod)(void *, ActionRebind *, void *,
                              int, float, float, float);
static VtableMethod g_vtable[4] = {nullptr, nullptr, nullptr, vtable_stub};
static VtableMethod *g_vtable_ptr = g_vtable;

// Fake object: first word is pointer to vtable pointer
static void *g_fake_obj_storage = nullptr;

static void reset_stubs() {
    g_slot_arg     = nullptr;
    g_eba00_result = nullptr;
    g_alloc_type   = -1;
    g_alloc_result = nullptr;
    g_vt           = {};
    g_fake_obj_storage = nullptr;
}

extern "C" void *func_001EBA00(void *slot) {
    g_slot_arg = slot;
    return g_eba00_result;
}

extern "C" void *func_00367230(int type) {
    g_alloc_type = type;
    return g_alloc_result;
}

// --- Tests ---

static void test_slot_occupied_returns_null() {
    reset_stubs();
    unsigned char other_buf[256] = {};
    ActionRebind *dummy_self = (ActionRebind *)0xABCD;
    g_eba00_result = (void *)0x1;   // non-null = occupied

    void *result = func_002718D0(dummy_self, (void *)other_buf, 1.f, 2.f, 3.f);

    assert(result == nullptr);
    assert(g_slot_arg == (void *)(other_buf + 116));
    assert(g_alloc_type == -1);     // alloc must not have been called
    assert(g_vt.call_count == 0);
    printf("PASS test_slot_occupied_returns_null\n");
}

static void test_alloc_fail_returns_null() {
    reset_stubs();
    unsigned char other_buf[256] = {};
    ActionRebind *dummy_self = (ActionRebind *)0xABCD;
    g_eba00_result = nullptr;       // slot empty
    g_alloc_result = nullptr;       // alloc fails

    void *result = func_002718D0(dummy_self, (void *)other_buf, 1.f, 2.f, 3.f);

    assert(result == nullptr);
    assert(g_alloc_type == 70);
    assert(g_vt.call_count == 0);   // vtable must not have been called
    printf("PASS test_alloc_fail_returns_null\n");
}

static void test_success_calls_vtable_and_returns_obj() {
    reset_stubs();
    unsigned char other_buf[256] = {};
    ActionRebind *dummy_self = (ActionRebind *)0xBEEF;

    // Build a fake object whose first 4 bytes point to g_vtable_ptr
    unsigned char fake_obj[16] = {};
    void **obj_head = (void **)fake_obj;
    *obj_head = (void *)g_vtable_ptr;   // obj->vtable = &g_vtable[0]
    g_fake_obj_storage = (void *)fake_obj;

    g_eba00_result = nullptr;           // slot empty
    g_alloc_result = (void *)fake_obj;  // alloc returns fake_obj

    void *result = func_002718D0(dummy_self, (void *)other_buf,
                                  1.5f, 2.5f, 3.5f);

    assert(result == (void *)fake_obj);
    assert(g_alloc_type == 70);
    assert(g_vt.call_count == 1);
    assert(g_vt.this_arg  == (void *)fake_obj);
    assert(g_vt.self_arg  == dummy_self);
    assert(g_vt.other_arg == (void *)other_buf);
    assert(g_vt.flag_arg  == 1);
    assert(g_vt.x_arg     == 1.5f);
    assert(g_vt.y_arg     == 2.5f);
    assert(g_vt.z_arg     == 3.5f);
    printf("PASS test_success_calls_vtable_and_returns_obj\n");
}

static void test_slot_arg_is_other_plus_116() {
    reset_stubs();
    unsigned char other_buf[256] = {};
    g_eba00_result = nullptr;
    g_alloc_result = nullptr;   // keep alloc null so vtable not invoked

    func_002718D0((ActionRebind *)0x1, (void *)other_buf, 0.f, 0.f, 0.f);

    assert(g_slot_arg == (void *)(other_buf + 116));
    printf("PASS test_slot_arg_is_other_plus_116\n");
}

int main() {
    test_slot_occupied_returns_null();
    test_alloc_fail_returns_null();
    test_success_calls_vtable_and_returns_obj();
    test_slot_arg_is_other_plus_116();
    printf("All unit_action_build_8d0 tests passed\n");
    return 0;
}
