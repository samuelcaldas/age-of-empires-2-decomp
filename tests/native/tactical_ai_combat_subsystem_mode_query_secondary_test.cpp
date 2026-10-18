#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_mode_query_secondary.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(CombatSubsystemMeshInstance, m_obj_120) == 0x120, "obj_120");
static_assert(offsetof(Object120, m_vtable) == 0x1B30, "obj_vtable");
static_assert(offsetof(Object120Vtable, func_B4) == 0xB4, "func_B4");
static_assert(offsetof(SystemManagerVtable, func_18) == 0x18, "func_18");

int D_004E2EA0 = 0;
static SystemManager s_mgr;
static SystemManagerVtable s_mgr_vtable;
SystemManager *D_004E3180 = &s_mgr;

static int s_gate_ret = 0;
static int s_gate_calls = 0;
static int s_vB4_calls = 0;
static int s_v18_calls = 0;
static void *s_last_b4_self = 0;
static int s_last_b4_flag = -1;
static float s_last_b4_x = 0;
static float s_last_b4_y = 0;

static unsigned char mock_vB4(void *self, int flag, float x, float y) {
    s_vB4_calls++;
    s_last_b4_self = self;
    s_last_b4_flag = flag;
    s_last_b4_x = x;
    s_last_b4_y = y;
    return 42;
}

static void mock_v18(void *, int, int) {
    s_v18_calls++;
}

static Object120Vtable s_obj_vtable;
static Object120 s_obj;

extern "C" {
    int func_1A5010(void *, int, int, short *s_3C, short *s_3E, int *) {
        s_gate_calls++;
        *s_3C = 16;
        *s_3E = 32;
        return s_gate_ret;
    }
}

static void test_disabled_global() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    D_004E2EA0 = 0;
    s_gate_calls = 0;
    assert(func_00329070(&inst, 10, 20) == 0);
    assert(s_gate_calls == 0);
}

static void test_gate_rejection() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    D_004E2EA0 = 1;
    s_gate_calls = 0;
    s_gate_ret = 0;
    s_vB4_calls = 0;
    s_v18_calls = 0;

    assert(func_00329070(&inst, 10, 20) == 0);
    assert(s_gate_calls == 1);
    assert(s_vB4_calls == 0);
    assert(s_v18_calls == 0);
}

static void test_query_and_manager_dispatch() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_obj_vtable, 0, sizeof(s_obj_vtable));
    s_obj_vtable.func_B4 = mock_vB4;
    s_obj.m_vtable = &s_obj_vtable;
    inst.m_obj_120 = &s_obj;

    std::memset(&s_mgr_vtable, 0, sizeof(s_mgr_vtable));
    s_mgr_vtable.func_18 = mock_v18;
    s_mgr.m_vtable = &s_mgr_vtable;

    D_004E2EA0 = 1;
    s_gate_calls = 0;
    s_gate_ret = 1;
    s_vB4_calls = 0;
    s_v18_calls = 0;

    int res = func_00329070(&inst, 100, 200);

    assert(res == 42);
    assert(s_gate_calls == 1);
    assert(s_vB4_calls == 1);
    assert(s_v18_calls == 1);
    assert(s_last_b4_self == &s_obj);
    assert(s_last_b4_flag == 0);
    assert(std::abs(s_last_b4_x - 16.5f) < 0.001f);
    assert(std::abs(s_last_b4_y - 32.5f) < 0.001f);
}

int main() {
    test_disabled_global();
    test_gate_rejection();
    test_query_and_manager_dispatch();
    return 0;
}
