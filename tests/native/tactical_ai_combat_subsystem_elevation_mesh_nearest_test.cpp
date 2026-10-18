#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_elevation_mesh_nearest.h"

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

extern "C" int func_123350(float val) {
    return static_cast<int>(std::round(val));
}

static void test_early_exits() {
    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));

    MeshVertex dummy[2];
    std::memset(dummy, 0, sizeof(dummy));
    void *table0[4] = {dummy, dummy, dummy, dummy};
    int table8[4] = {1, 1, 1, 1};

    desc.m_table_0 = table0;
    desc.m_table_8 = table8;
    desc.m_count = 0;

    assert(func_003283C0(&desc, 0, 0, 0, -1, 0, 0) == 0);
    assert(func_003283C0(&desc, 0, 0, 0, 0, 0, 0) == 0);

    desc.m_count = 2;
    assert(func_003283C0(&desc, 0, 0, 0, 2, 0, 0) == 0);

    table8[0] = 0;
    assert(func_003283C0(&desc, 0, 0, 0, 0, 0, 0) == 0);
}

static void test_nearest_search() {
    MeshVertex buffer[3];
    std::memset(buffer, 0, sizeof(buffer));

    buffer[0].m_id = 1;
    buffer[0].m_x = 10;
    buffer[0].m_y = 10;

    buffer[1].m_id = 2;
    buffer[1].m_x = 12;
    buffer[1].m_y = 11;

    buffer[2].m_id = 3;
    buffer[2].m_x = 20;
    buffer[2].m_y = 20;

    void *table0[1] = {buffer};
    int table8[1] = {3};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    MeshVertex *res = func_003283C0(&desc, 11, 10, 0, 0, 0, 0);
    assert(res == &buffer[0]);
    assert(buffer[0].m_flags_4 == 2);

    int exclude_list[1] = {1};
    res = func_003283C0(&desc, 11, 10, 0, 0, exclude_list, 1);
    assert(res == &buffer[1]);
    assert(buffer[1].m_flags_4 == 2);
}

static void test_clamp_distance() {
    MeshVertex buffer[1];
    std::memset(buffer, 0, sizeof(buffer));
    buffer[0].m_id = 10;
    buffer[0].m_x = 0;
    buffer[0].m_y = 0;

    void *table0[1] = {buffer};
    int table8[1] = {1};

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    MeshVertex *res = func_003283C0(&desc, 200, 200, 0, 0, 0, 0);
    assert(res == &buffer[0]);
    assert(static_cast<unsigned char>(buffer[0].m_flags_4) == 255);
}

int main() {
    test_early_exits();
    test_nearest_search();
    test_clamp_distance();
    return 0;
}
