#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_elevation_mesh_remove.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(sizeof(MeshVertex) == 8, "vertex size");
static_assert(offsetof(MeshVertex, m_id) == 0, "m_id");
static_assert(offsetof(MeshVertex, m_flags_4) == 4, "flags_4");
static_assert(offsetof(MeshVertex, m_flags_5) == 5, "flags_5");
static_assert(offsetof(MeshVertex, m_x) == 6, "m_x");
static_assert(offsetof(MeshVertex, m_y) == 7, "m_y");
static_assert(offsetof(ElevationMeshDescriptor, m_table_0) == 0x00, "table_0");
static_assert(offsetof(ElevationMeshDescriptor, m_table_8) == 0x08, "table_8");
static_assert(offsetof(ElevationMeshDescriptor, m_count) == 0x10, "count");

static void test_early_exits() {
    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 0;

    int res = func_00328300(&desc, 10, 0);
    assert(res == -1);

    desc.m_count = 1;
    int table8[2] = {0, 0};
    desc.m_table_8 = table8;
    res = func_00328300(&desc, 10, 0);
    assert(res == 0);
}

static void test_not_found() {
    MeshVertex buffer[2];
    std::memset(buffer, 0, sizeof(buffer));
    buffer[0].m_id = 100;
    void *table0[1] = {buffer};
    int table8[1] = {1};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    int res = func_00328300(&desc, 999, 0);
    assert(res == -1);
    assert(table8[0] == 1);
}

static void test_remove_single() {
    MeshVertex buffer[1];
    std::memset(buffer, 0, sizeof(buffer));
    buffer[0].m_id = 55;
    void *table0[1] = {buffer};
    int table8[1] = {1};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    int res = func_00328300(&desc, 55, 0);
    assert(res == 0);
    assert(table8[0] == 0);
}

static void test_remove_swap_last() {
    MeshVertex buffer[3];
    std::memset(buffer, 0, sizeof(buffer));
    buffer[0].m_id = 10;
    buffer[1].m_id = 20;
    buffer[1].m_x = 5;
    buffer[2].m_id = 30;
    buffer[2].m_x = 9;

    void *table0[1] = {buffer};
    int table8[1] = {3};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    int res = func_00328300(&desc, 20, 0);
    assert(res == 1);
    assert(table8[0] == 2);
    assert(buffer[1].m_id == 30);
    assert(buffer[1].m_x == 9);

    res = func_00328300(&desc, 30, 0);
    assert(res == 1);
    assert(table8[0] == 1);
    assert(buffer[0].m_id == 10);
}

int main() {
    test_early_exits();
    test_not_found();
    test_remove_single();
    test_remove_swap_last();
    return 0;
}
