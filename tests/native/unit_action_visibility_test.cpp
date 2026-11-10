#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "unit_action_visibility.h"

// Define ActionRebind virtual methods
#define DEF_STUB(name) void* ActionRebind::name() { return 0; }
#define DEF_STUB_10(base) \
    DEF_STUB(v##base##0) DEF_STUB(v##base##1) DEF_STUB(v##base##2) DEF_STUB(v##base##3) DEF_STUB(v##base##4) \
    DEF_STUB(v##base##5) DEF_STUB(v##base##6) DEF_STUB(v##base##7) DEF_STUB(v##base##8) DEF_STUB(v##base##9)

DEF_STUB_10(0)
void* ActionRebind::v10() { return 0; }
void* ActionRebind::v11() { return 0; }
void* ActionRebind::v12() { return 0; }
void* ActionRebind::Method13() { return 0; }
void* ActionRebind::v14() { return 0; }
void ActionRebind::Method15(float, float, float) {}
void* ActionRebind::v16() { return 0; }
void ActionRebind::Method19(int) {}
void* ActionRebind::v18() { return 0; }
void* ActionRebind::v19() { return 0; }
void* ActionRebind::v20() { return 0; }
void* ActionRebind::v21() { return 0; }
void* ActionRebind::v22() { return 0; }
void* ActionRebind::v23() { return 0; }
void* ActionRebind::v24() { return 0; }
void* ActionRebind::v25() { return 0; }
void ActionRebind::Method28(int) {}
void ActionRebind::Method29() {}
void ActionRebind::Method30() {}
void* ActionRebind::v29() { return 0; }
void* ActionRebind::v30() { return 0; }
void ActionRebind::v31() {}
float ActionRebind::Method32() { return 0.0f; }
void* ActionRebind::v33() { return 0; }
void ActionRebind::Method34(int) {}
void* ActionRebind::v35() { return 0; }
void* ActionRebind::v36() { return 0; }
void* ActionRebind::v37() { return 0; }
void* ActionRebind::v38() { return 0; }
void* ActionRebind::v39() { return 0; }
DEF_STUB_10(4)
void* ActionRebind::v50() { return 0; }
void* ActionRebind::v51() { return 0; }
void* ActionRebind::v52() { return 0; }
void* ActionRebind::v53() { return 0; }
void* ActionRebind::v54() { return 0; }
void* ActionRebind::v55() { return 0; }
void ActionRebind::Method58() {}
void* ActionRebind::v57() { return 0; }
void* ActionRebind::v58() { return 0; }
void ActionRebind::Method61(void*, int, int, int) {}
void ActionRebind::Method62(void*, int, int, int) {}
void* ActionRebind::v61() { return 0; }
void* ActionRebind::v62() { return 0; }
void* ActionRebind::v63() { return 0; }
void* ActionRebind::v64() { return 0; }
void* ActionRebind::v65() { return 0; }
void* ActionRebind::v66() { return 0; }
void* ActionRebind::v67() { return 0; }
void* ActionRebind::v68() { return 0; }
void* ActionRebind::v69() { return 0; }
DEF_STUB_10(7)
void* ActionRebind::v80() { return 0; }
void* ActionRebind::v81() { return 0; }
void* ActionRebind::v82() { return 0; }
void* ActionRebind::v83() { return 0; }
void* ActionRebind::v84() { return 0; }
void* ActionRebind::v85() { return 0; }
void* ActionRebind::v86() { return 0; }
int ActionRebind::Method87() { return 0; }
void* ActionRebind::v88() { return 0; }
void* ActionRebind::v89() { return 0; }
void ActionRebind::Method90(short, short, int, void*, int, int) {}

// Globals and mocks
static int s_grid_row0[8] = {0};
int *D_50A5A0[8] = {s_grid_row0};

static int s_func_205F70_called = 0;
static int s_func_26A540_called = 0;
static int s_func_328300_called = 0;
static int s_func_1EBA00_called = 0;
static int s_func_1ECD00_called = 0;
static int s_func_1ECBF0_called = 0;
static int s_notify_called = 0;

static void mock_notify(void *comp, void *player, void *action, float x, float y, float z) {
    (void)comp; (void)player; (void)action; (void)x; (void)y; (void)z;
    s_notify_called++;
}

extern "C" {
void func_205F70(void *world, void *action) {
    (void)world; (void)action;
    s_func_205F70_called++;
}

void func_26A540(void *action, int flag) {
    (void)action; (void)flag;
    s_func_26A540_called++;
}

int func_123350(float val) {
    return (int)val;
}

void func_328300(void *obj, short val, unsigned char flag) {
    (void)obj; (void)val; (void)flag;
    s_func_328300_called++;
}

int func_1EBA00(void *obj) {
    (void)obj;
    s_func_1EBA00_called++;
    return 0; // Not visible/hidden -> triggers notify
}

void func_1ECD00(void *field98, void *action) {
    (void)field98; (void)action;
    s_func_1ECD00_called++;
}

void func_1ECBF0(void *field98, void *action, void *sight) {
    (void)field98; (void)action; (void)sight;
    s_func_1ECBF0_called++;
}
}

int main() {
    ActionRebind action;
    std::memset((void*)&action, 0, sizeof(action));

    // Test 1: func_00267E60
    action.m_field36 = 1;
    action.m_field30 = 5.0f;
    func_00267E60(&action);
    assert(s_func_205F70_called == 1);
    assert(s_func_26A540_called == 1);
    assert(action.m_field30 == 0.0f);

    // Setup world and structures for func_00267EB0 and func_00268070
    char world_buf[4000];
    std::memset(world_buf, 0, sizeof(world_buf));
    char world_sub_buf[512];
    std::memset(world_sub_buf, 0, sizeof(world_sub_buf));

    *(void**)(world_buf + 2968) = (void*)world_sub_buf;
    world_sub_buf[49] = 0; // flag == 0

    char player_buf[4000];
    std::memset(player_buf, 0, sizeof(player_buf));
    void *player_ptrs[4] = {player_buf, player_buf, player_buf, player_buf};
    *(void**)(world_sub_buf + 84) = (void*)player_ptrs;

    char player_sub[2048];
    std::memset(player_sub, 0, sizeof(player_sub));
    *(void**)(player_buf + 112) = (void*)player_sub;

    char comp_buf[512];
    std::memset(comp_buf, 0, sizeof(comp_buf));
    *(void**)(player_sub + 972) = (void*)comp_buf;

    char comp_sub[256];
    std::memset(comp_sub, 0, sizeof(comp_sub));
    *(void**)(comp_buf + 160) = (void*)comp_sub;
    *(NotifyLOSFn*)(comp_sub + 116) = mock_notify;

    char field4_buf[256];
    std::memset(field4_buf, 0, sizeof(field4_buf));
    field4_buf[144] = 2; // type 2
    field4_buf[3] = 1;

    action.m_world = (WorldExtended*)world_buf;
    action.m_field4 = (void*)field4_buf;
    action.m_field24 = 10;
    action.m_x = 0.0f;
    action.m_y = 0.0f;
    action.m_z = 0.0f;

    // Sight bitmask: player 1 visible
    // s1 = sight >> 16
    // s4 = sight & 0xFFFF
    s_grid_row0[0] = (2 << 16) | 0; // s1 has bit 1 set (player 1), s4 has bit 1 clear

    // Test 2: func_00267EB0
    func_00267EB0(&action);
    assert(s_func_328300_called == 1);
    assert(s_func_1ECD00_called == 1);

    // Test 3: func_00268070
    func_00268070(&action);
    assert(s_notify_called == 1);
    assert(s_func_1ECBF0_called == 1);

    return 0;
}
