#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_mode_update.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(SystemManager, m_mode) == 0x1C8, "mode");
static_assert(offsetof(SystemManager, m_subtype) == 0x1CC, "subtype");
static_assert(offsetof(CombatSubsystemMeshInstance, m_active) == 0x17C, "active");
static_assert(offsetof(MeshInstanceVtable, func_118) == 0x118, "vtable_118");
static_assert(offsetof(MeshInstanceVtable, func_11C) == 0x11C, "vtable_11C");
static_assert(offsetof(MeshInstanceVtable, func_120) == 0x120, "vtable_120");

static SystemSub28 s_sub28;
static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_disable_calls = 0;
static int s_reset_calls = 0;
static int s_status_ret = 1;
static int s_gate_ret = 1;
static int s_v118_calls = 0;
static int s_v11C_calls = 0;
static int s_v120_calls = 0;

static int mock_v118(void *, int, int) { s_v118_calls++; return 1; }
static void mock_v11C(void *, int, int) { s_v11C_calls++; }
static void mock_v120(void *, int, int) { s_v120_calls++; }

static MeshInstanceVtable s_vtable;

extern "C" {
    int func_185DC0(void *, int) { return s_status_ret; }
    void func_1A5390(void *) { s_disable_calls++; }
    void func_1F65A0(void *) { s_reset_calls++; }
    int func_1A5010(void *, int, int, short *, short *, int *) { return s_gate_ret; }
}

static void test_active_and_mode_guards() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;

    s_mgr.m_mode = 0;
    inst.m_active = 1;
    assert(func_00328930(&inst, 0, 0) == 0);

    s_mgr.m_mode = 4;
    inst.m_active = 1;
    s_disable_calls = 0;
    assert(func_00328930(&inst, 0, 0) == 1);
    assert(s_disable_calls == 1);
}

static void test_status_and_gate_rejection() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;
    s_mgr.m_mode = 6;
    inst.m_active = 0;

    s_status_ret = 0;
    assert(func_00328930(&inst, 0, 0) == 0);

    s_status_ret = 1;
    s_gate_ret = 0;
    assert(func_00328930(&inst, 0, 0) == 0);
}

static void test_vtable_subtypes() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_vtable, 0, sizeof(s_vtable));
    s_vtable.func_118 = mock_v118;
    s_vtable.func_11C = mock_v11C;
    s_vtable.func_120 = mock_v120;
    inst.m_vtable = &s_vtable;

    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;
    s_mgr.m_mode = 7;
    s_status_ret = 1;
    s_gate_ret = 1;

    s_mgr.m_subtype = 4;
    s_v11C_calls = 0;
    assert(func_00328930(&inst, 10, 20) == 1);
    assert(s_v11C_calls == 1);

    s_mgr.m_subtype = 5;
    s_v120_calls = 0;
    assert(func_00328930(&inst, 10, 20) == 1);
    assert(s_v120_calls == 1);

    s_mgr.m_subtype = 0;
    s_sub28.m_state = 2;
    s_v118_calls = 0;
    assert(func_00328930(&inst, 10, 20) == 1);
    assert(s_v118_calls == 1);
}

int main() {
    test_active_and_mode_guards();
    test_status_and_gate_rejection();
    test_vtable_subtypes();
    return 0;
}
