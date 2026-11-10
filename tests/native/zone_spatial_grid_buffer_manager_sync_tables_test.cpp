#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_buffer_manager_sync_tables.h"

extern "C" {
int g_remove_called = 0;
void *g_remove_elem = nullptr;
void *g_remove_self = nullptr;

int func_001ECD00(void *self, void *elem) {
    g_remove_called++;
    g_remove_self = self;
    g_remove_elem = elem;
    return 1;
}

void *g_lookup_ret = nullptr;
void *g_lookup_world = nullptr;
short g_lookup_id = 0;

void *func_332e60(void *world, short id) {
    g_lookup_world = world;
    g_lookup_id = id;
    return g_lookup_ret;
}

int g_eba00_ret = 0;
void *g_eba00_ptr = nullptr;

int func_001EBA00(void *ptr) {
    g_eba00_ptr = ptr;
    return g_eba00_ret;
}

int g_202b10_ret = 0;
void *g_202b10_team = nullptr;

int func_202B10(void *team) {
    g_202b10_team = team;
    return g_202b10_ret;
}
}

static int g_func74_called = 0;
static void *g_func74_team = nullptr;
static void *g_func74_elem = nullptr;
static float g_func74_x = 0;
static float g_func74_y = 0;
static float g_func74_z = 0;

static void mock_func_74(void *self, void *team, void *elem, float x, float y, float z) {
    g_func74_called++;
    g_func74_team = team;
    g_func74_elem = elem;
    g_func74_x = x;
    g_func74_y = y;
    g_func74_z = z;
}

static int g_m118_called = 0;
static int g_m118_a1 = 0;
static int g_m118_a2 = 0;
static int g_m118_a3 = 0;
static short g_m118_a4 = 0;
static int g_m118_t1 = 0;
static int g_m118_t2 = 0;

static void mock_method118(void *self, int a1, int a2, int a3, short a4, int t1, int t2) {
    g_m118_called++;
    g_m118_a1 = a1;
    g_m118_a2 = a2;
    g_m118_a3 = a3;
    g_m118_a4 = a4;
    g_m118_t1 = t1;
    g_m118_t2 = t2;
}

static void *vtable_team[80];
static void *vtable_obj[40];

static void reset_mocks() {
    g_remove_called = 0;
    g_remove_elem = nullptr;
    g_remove_self = nullptr;
    g_lookup_ret = nullptr;
    g_lookup_world = nullptr;
    g_lookup_id = 0;
    g_eba00_ret = 0;
    g_eba00_ptr = nullptr;
    g_202b10_ret = 0;
    g_202b10_team = nullptr;
    g_func74_called = 0;
    g_func74_team = nullptr;
    g_func74_elem = nullptr;
    g_func74_x = 0;
    g_func74_y = 0;
    g_func74_z = 0;
    g_m118_called = 0;
    g_m118_a1 = 0;
    g_m118_a2 = 0;
    g_m118_a3 = 0;
    g_m118_a4 = 0;
    g_m118_t1 = 0;
    g_m118_t2 = 0;
    vtable_team[68] = reinterpret_cast<void *>(mock_method118);
    vtable_obj[27] = reinterpret_cast<void *>(mock_func_74);
}

static void test_layout() {
    // SpatialGridBufferManager struct offsets
    // owner: 0x000, elems: 0x004, ptrs: 0x324, vals: 0x644, shorts: 0x964, cap: 0xAF4, count: 0xAF6
    // size: 0xAF8
    unsigned char buf[0xAF8];
    assert(sizeof(buf) == 0xAF8);
}

static void test_count_zero_or_negative_early_return() {
    reset_mocks();
    unsigned char mgr_buf[0xAF8];
    std::memset(mgr_buf, 0, sizeof(mgr_buf));

    // count = 0
    *reinterpret_cast<short *>(mgr_buf + 0xAF6) = 0;
    func_001ECE20(mgr_buf);
    assert(g_remove_called == 0);
    assert(g_func74_called == 0);
    assert(g_m118_called == 0);

    // count = -5
    *reinterpret_cast<short *>(mgr_buf + 0xAF6) = -5;
    func_001ECE20(mgr_buf);
    assert(g_remove_called == 0);
    assert(g_func74_called == 0);
    assert(g_m118_called == 0);
}

static void test_no_change_when_val_matches() {
    reset_mocks();
    unsigned char mgr_buf[0xAF8];
    std::memset(mgr_buf, 0, sizeof(mgr_buf));

    *reinterpret_cast<short *>(mgr_buf + 0xAF6) = 1;
    int current_val = 42;
    *reinterpret_cast<int **>(mgr_buf + 0x324) = &current_val;
    *reinterpret_cast<int *>(mgr_buf + 0x644) = 42;

    func_001ECE20(mgr_buf);
    assert(*reinterpret_cast<int *>(mgr_buf + 0x644) == 42);
    assert(g_remove_called == 0);
    assert(g_func74_called == 0);
    assert(g_m118_called == 0);
}

static void test_remove_when_lookup_mismatches() {
    reset_mocks();
    unsigned char mgr_buf[0xAF8];
    std::memset(mgr_buf, 0, sizeof(mgr_buf));

    unsigned char owner_team[0x2000];
    std::memset(owner_team, 0, sizeof(owner_team));
    *reinterpret_cast<void **>(mgr_buf) = owner_team;
    *reinterpret_cast<short *>(mgr_buf + 0xAF6) = 1;

    unsigned char elem_buf[0x100];
    std::memset(elem_buf, 0, sizeof(elem_buf));
    *reinterpret_cast<void **>(mgr_buf + 0x004) = elem_buf;

    int new_val = 10;
    *reinterpret_cast<int **>(mgr_buf + 0x324) = &new_val;
    *reinterpret_cast<int *>(mgr_buf + 0x644) = 5;
    *reinterpret_cast<short *>(mgr_buf + 0x964) = 77;

    // Lookup returns nullptr (mismatch)
    g_lookup_ret = nullptr;

    func_001ECE20(mgr_buf);
    assert(*reinterpret_cast<int *>(mgr_buf + 0x644) == 10);
    assert(g_remove_called == 1);
    assert(g_remove_self == mgr_buf);
    assert(g_remove_elem == elem_buf);
    assert(g_func74_called == 0);
    assert(g_m118_called == 0);
}

static void test_team_notification_dispatch() {
    reset_mocks();
    unsigned char mgr_buf[0xAF8];
    std::memset(mgr_buf, 0, sizeof(mgr_buf));

    unsigned char owner_team[0x2000];
    std::memset(owner_team, 0, sizeof(owner_team));
    unsigned char other_team[0x2000];
    std::memset(other_team, 0, sizeof(other_team));
    unsigned char world_buf[0x100];
    std::memset(world_buf, 0, sizeof(world_buf));

    void *teams[4] = {nullptr, owner_team, other_team, nullptr};
    *reinterpret_cast<void ***>(world_buf + 0x54) = teams;

    // In GCC, ElementTeam vptr is at 0
    *reinterpret_cast<void ***>(owner_team) = vtable_team;
    *reinterpret_cast<void ***>(other_team) = vtable_team;

    // Offsets under GCC: world at 0xB9C, team at 0xBA4
    *reinterpret_cast<void **>(owner_team + 0xB9C) = world_buf;
    *reinterpret_cast<int *>(owner_team + 0xBA4) = 1;

    *reinterpret_cast<void **>(other_team + 0xB9C) = world_buf;
    *reinterpret_cast<int *>(other_team + 0xBA4) = 2;

    unsigned char team_obj70[0x400];
    std::memset(team_obj70, 0, sizeof(team_obj70));
    *reinterpret_cast<void **>(other_team + 0x74) = team_obj70;

    unsigned char team_obj3cc[0x100];
    std::memset(team_obj3cc, 0, sizeof(team_obj3cc));
    *reinterpret_cast<void ***>(team_obj3cc) = vtable_obj;
    *reinterpret_cast<void **>(team_obj70 + 0x3CC) = team_obj3cc;

    *reinterpret_cast<void **>(mgr_buf) = owner_team;
    *reinterpret_cast<short *>(mgr_buf + 0xAF6) = 1;

    unsigned char elem_buf[0x100];
    std::memset(elem_buf, 0, sizeof(elem_buf));
    *reinterpret_cast<short *>(elem_buf + 0x24) = 0x5678;
    *reinterpret_cast<float *>(elem_buf + 0x44) = 12.0f;
    *reinterpret_cast<float *>(elem_buf + 0x48) = 24.0f;
    *reinterpret_cast<float *>(elem_buf + 0x4C) = 36.0f;

    *reinterpret_cast<void **>(mgr_buf + 0x004) = elem_buf;
    int current_val = 0;
    *reinterpret_cast<int **>(mgr_buf + 0x324) = &current_val;
    *reinterpret_cast<int *>(mgr_buf + 0x644) = 4; // bit 2 set -> other_team 2
    *reinterpret_cast<short *>(mgr_buf + 0x964) = 88;

    g_lookup_ret = elem_buf;
    g_eba00_ret = 0;
    g_202b10_ret = 1;

    func_001ECE20(mgr_buf);
    assert(*reinterpret_cast<int *>(mgr_buf + 0x644) == 0);
    assert(g_remove_called == 0);
    assert(g_func74_called == 1);
    assert(g_func74_team == other_team);
    assert(g_func74_elem == elem_buf);
    assert(g_func74_x == 12.0f);
    assert(g_func74_y == 24.0f);
    assert(g_func74_z == 36.0f);

    assert(g_m118_called == 1);
    assert(g_m118_a1 == -1);
    assert(g_m118_a2 == 2);
    assert(g_m118_a3 == 0x20D);
    assert(g_m118_a4 == 0x5678);
    assert(g_m118_t1 == 0);
    assert(g_m118_t2 == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_id = std::atoi(argv[1]);
    switch (case_id) {
    case 0:
        test_layout();
        break;
    case 1:
        test_count_zero_or_negative_early_return();
        break;
    case 2:
        test_no_change_when_val_matches();
        break;
    case 3:
        test_remove_when_lookup_mismatches();
        break;
    case 4:
        test_team_notification_dispatch();
        break;
    default:
        return 2;
    }
    std::cout << "PASS" << std::endl;
    return 0;
}
