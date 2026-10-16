#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include "unit_action_rebind.h"

static int mock_func_123350_ret = 0;
extern "C" {
    int func_123350(float val) {
        return mock_func_123350_ret;
    }
    void func_207AB0(void *world, short id, int delta) {}
    void func_207C30(void *world, short id, int delta) {}
    void func_1EDF20(void *obj, void *action) {}
    void func_1EDA80(void *obj, void *action) {}
    void func_264330(void *action) {}
    void func_2643C0(void *action) {}
    void func_205F70(void *world, void *action) {}
    void func_26A540(void *action, int flag) {}
    void *D_004E3244 = nullptr;
}

static int last_method19_target = 0;
static float field30_at_method19 = 0.0f;

struct ActionMock;
static void mock_method19(void *self, int target);

static void poison_trap_slot18(void *self, int target) {
    (void)self; (void)target;
    assert(!"Wrong vtable slot 18 executed instead of slot 17");
}

static void poison_trap_slot19(void *self, int target) {
    (void)self; (void)target;
    assert(!"Wrong vtable slot 19 executed instead of slot 17");
}

static void poison_trap_generic(void *self, ...) {
    (void)self;
    assert(!"Unintended vtable slot executed in ActionMock");
}

static void* dummy_vtable[120] = {nullptr};

static void init_vtable() {
    for (int i = 0; i < 120; i++) {
        dummy_vtable[i] = (void*)poison_trap_generic;
    }
    dummy_vtable[17] = (void*)mock_method19;
    dummy_vtable[18] = (void*)poison_trap_slot18;
    dummy_vtable[19] = (void*)poison_trap_slot19;
}

struct ActionMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    char pad_20[0x4];
    short m_field24;
    short m_field26;
    short m_field28;
    short m_field2A;
    short m_field2C;
    short m_field2E;
    float m_field30;
    char m_field34;
    char m_field35;
    unsigned char m_field36;
    unsigned char m_field37;
    unsigned char m_field38;
    unsigned char m_field39;

    ActionMock() {
        init_vtable();
        vtable = dummy_vtable;
        m_field4 = nullptr;
        m_world = nullptr;
        m_fieldC = nullptr;
        m_field10 = 0;
        m_field14 = 0;
        m_field18 = 0;
        m_field1C = 0;
        m_field30 = 0.0f;
        m_field39 = 0;
    }
};

static void mock_method19(void *self, int target) {
    ActionMock *act = (ActionMock*)self;
    last_method19_target = target;
    field30_at_method19 = act->m_field30;
}

struct alignas(4) DummyEntity {
    char pad_00[16];
    int m_target1;   // offset 16 (0x10)
    char pad_14[4];  // offset 20 (0x14)
    int m_target2;   // offset 24 (0x18)
    char pad_1C[34]; // offset 28..61
    short m_val62;   // offset 62 (0x3E)
    char pad_40[2];  // alignment
};

static_assert(offsetof(DummyEntity, m_target1) == 16, "DummyEntity offset m_target1");
static_assert(offsetof(DummyEntity, m_target2) == 24, "DummyEntity offset m_target2");
static_assert(offsetof(DummyEntity, m_val62) == 62, "DummyEntity offset m_val62");

static void test_normal_scaling() {
    ActionMock action = {};
    init_vtable();
    action.vtable = dummy_vtable;
    DummyEntity old_ent = {};
    DummyEntity new_ent = {};
    old_ent.m_val62 = 25;
    new_ent.m_val62 = 50;

    action.m_field39 = 0;
    action.m_field18 = 0;
    action.m_field4 = &old_ent;
    action.m_field30 = 100.0f;
    mock_func_123350_ret = 100;

    func_00267C20((ActionRebind*)&action, &new_ent);

    // scaled = (100 * 50) / 25 = 200
    assert(action.m_field30 == 200.0f);
}

static void test_16bit_sign_extended_multiply() {
    ActionMock action = {};
    init_vtable();
    action.vtable = dummy_vtable;
    DummyEntity old_ent = {};
    DummyEntity new_ent = {};
    old_ent.m_val62 = 1;
    new_ent.m_val62 = 30000;

    action.m_field39 = 0;
    action.m_field18 = 0;
    action.m_field4 = &old_ent;
    action.m_field30 = 100000.0f;
    mock_func_123350_ret = 100000;

    func_00267C20((ActionRebind*)&action, &new_ent);

    // (short)100000 == -31072, -31072 * 30000 == -932160000
    // -932160000 / 1 == -932160000
    assert(action.m_field30 == -932160000.0f);
}

static void test_16bit_max_boundary() {
    ActionMock action = {};
    init_vtable();
    action.vtable = dummy_vtable;
    DummyEntity old_ent = {};
    DummyEntity new_ent = {};
    old_ent.m_val62 = 1;
    new_ent.m_val62 = -1;

    action.m_field39 = 0;
    action.m_field18 = 0;
    action.m_field4 = &old_ent;
    action.m_field30 = 0.0f;
    mock_func_123350_ret = -32768; // SHRT_MIN

    // (short)-32768 * -1 == 32768, 32768 / 1 == 32768
    func_00267C20((ActionRebind*)&action, &new_ent);

    assert(action.m_field30 == 32768.0f);
}

static void test_target_id_callback_ordering() {
    ActionMock action = {};
    init_vtable();
    action.vtable = dummy_vtable;

    DummyEntity old_ent = {};
    DummyEntity new_ent = {};
    old_ent.m_val62 = 20;
    old_ent.m_target1 = 42;
    new_ent.m_val62 = 40;
    new_ent.m_target1 = 84;

    action.m_field39 = 0;
    action.m_field18 = 0;
    action.m_field4 = &old_ent;
    action.m_field10 = 42; // matches old_ent.m_target1
    action.m_field30 = 50.0f;
    mock_func_123350_ret = 50;
    last_method19_target = 0;
    field30_at_method19 = 0.0f;

    func_00267C20((ActionRebind*)&action, &new_ent);

    // scaled = (50 * 40) / 20 = 100
    // Method19 must be called on slot 17 with new target 84
    assert(last_method19_target == 84);
    // AND m_field30 must have already been updated to scaled value (100.0f) BEFORE Method19 ran
    assert(field30_at_method19 == 100.0f);
    assert(action.m_field30 == 100.0f);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int case_id = argv[1][0] - '0';
    switch (case_id) {
    case 0: test_normal_scaling(); break;
    case 1: test_16bit_sign_extended_multiply(); break;
    case 2: test_16bit_max_boundary(); break;
    case 3: test_target_id_callback_ordering(); break;
    default: return 1;
    }
    return 0;
}
