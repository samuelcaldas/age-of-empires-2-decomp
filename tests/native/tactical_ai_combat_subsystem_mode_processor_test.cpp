#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_mode_processor.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(CombatSubsystemMeshInstance, m_type_108) == 0x108, "type_108");
static_assert(offsetof(CombatSubsystemMeshInstance, m_obj_120) == 0x120, "obj_120");
static_assert(offsetof(CombatSubsystemMeshInstance, m_active) == 0x17C, "active");
static_assert(offsetof(Object120, m_vtable) == 0x1B30, "obj_vtable");
static_assert(offsetof(Object120Vtable, func_DC) == 0xDC, "func_DC");
static_assert(offsetof(SystemManagerVtable, func_18) == 0x18, "func_18");

static SystemSub28 s_sub28;
static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_disable_calls = 0;
static int s_reset_calls = 0;
static int s_status_ret = 1;
static int s_gate_ret = 1;
static int s_v118_calls = 0;
static int s_v18_calls = 0;
static int s_vDC_calls = 0;
static int s_cleanup_calls = 0;

static float s_last_dc_x = 0;
static float s_last_dc_y = 0;
static float s_last_dc_z = 0;

static int mock_v118(void *, int, int) { s_v118_calls++; return 1; }
static void mock_v18(void *, int, int) { s_v18_calls++; }
static void mock_vDC(void *, float x, float y, float z) {
    s_vDC_calls++;
    s_last_dc_x = x;
    s_last_dc_y = y;
    s_last_dc_z = z;
}

static MeshInstanceVtable s_mesh_vtable;
static SystemManagerVtable s_mgr_vtable;
static Object120Vtable s_obj_vtable;
static Object120 s_obj;

extern "C" {
    int func_185DC0(void *, int) { return s_status_ret; }
    void func_1A5390(void *) { s_disable_calls++; }
    void func_1F65A0(void *) { s_reset_calls++; }
    int func_1A5010(void *, int, int, short *s_5C, short *s_5E, int *) {
        *s_5C = 10;
        *s_5E = 20;
        return s_gate_ret;
    }
    void func_205EE0(void *) { s_cleanup_calls++; }
}

static void test_guards() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_mgr, 0, sizeof(s_mgr));

    s_mgr.m_mode = 0;
    inst.m_active = 1;
    assert(func_00328D50(&inst, 0, 0, 0, 0) == 0);

    s_mgr.m_mode = 4;
    inst.m_active = 1;
    s_disable_calls = 0;
    assert(func_00328D50(&inst, 0, 0, 0, 0) == 1);
    assert(s_disable_calls == 1);

    inst.m_active = 0;
    s_status_ret = 0;
    assert(func_00328D50(&inst, 0, 0, 0, 0) == 0);

    s_status_ret = 1;
    inst.m_type_108 = 3;
    assert(func_00328D50(&inst, 0, 0, 0, 0) == 0);
}

static void test_state_2_dispatch() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_type_108 = 1;
    inst.m_vtable = &s_mesh_vtable;
    s_mesh_vtable.func_118 = mock_v118;

    s_obj.m_vtable = &s_obj_vtable;
    s_obj_vtable.func_DC = mock_vDC;
    inst.m_obj_120 = &s_obj;

    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;
    s_mgr.m_mode = 6;
    s_sub28.m_state = 2;
    s_status_ret = 1;

    s_v118_calls = 0;
    assert(func_00328D50(&inst, 10, 20, 0, 0) == 1);
    assert(s_v118_calls == 1);

    s_vDC_calls = 0;
    s_gate_ret = 1;
    assert(func_00328D50(&inst, 10, 20, 0, 1) == 1);
    assert(s_vDC_calls == 1);
    assert(std::abs(s_last_dc_x - 10.5f) < 0.001f);
    assert(std::abs(s_last_dc_y - 20.5f) < 0.001f);
    assert(std::abs(s_last_dc_z - 1.0f) < 0.001f);
}

static void test_fallback_cleanup() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_type_108 = 2;
    inst.m_obj_120 = &s_obj;

    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;
    s_mgr.m_vtable = &s_mgr_vtable;
    s_mgr_vtable.func_18 = mock_v18;
    s_mgr.m_mode = 4;
    s_mgr.m_subtype = 1;
    s_sub28.m_state = 0;
    s_status_ret = 1;

    s_v18_calls = 0;
    s_cleanup_calls = 0;
    assert(func_00328D50(&inst, 0, 0, 0, 0) == 0);
    assert(s_v18_calls == 1);
    assert(s_cleanup_calls == 1);
}

int main() {
    test_guards();
    test_state_2_dispatch();
    test_fallback_cleanup();
    return 0;
}
