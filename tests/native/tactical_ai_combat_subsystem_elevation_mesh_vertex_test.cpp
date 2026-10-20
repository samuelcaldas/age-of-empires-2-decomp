#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_elevation_mesh_vertex.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(sizeof(MeshVertex) == 8, "vertex size");
static_assert(offsetof(MeshVertex, m_id) == 0, "m_id");
static_assert(offsetof(MeshVertex, m_flags_4) == 4, "flags_4");
static_assert(offsetof(MeshVertex, m_flags_5) == 5, "flags_5");
static_assert(offsetof(MeshVertex, m_x) == 6, "m_x");
static_assert(offsetof(MeshVertex, m_y) == 7, "m_y");
static_assert(offsetof(Entity, m_x) == 0x44, "entity_x");
static_assert(offsetof(Entity, m_y) == 0x48, "entity_y");
static_assert(offsetof(ElevationMeshDescriptor, m_table_0) == 0x00, "table_0");
static_assert(offsetof(ElevationMeshDescriptor, m_table_8) == 0x08, "table_8");
static_assert(offsetof(ElevationMeshDescriptor, m_count) == 0x10, "count");

static Entity *s_entities[16];
Entity **D_004E350C = s_entities;

extern "C" int func_123350(float val) {
    return static_cast<int>(std::round(val));
}

static void test_early_exits() {
    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 0;

    MeshVertex buffer[4];
    std::memset(buffer, 0, sizeof(buffer));
    void *table0[2] = {buffer, buffer};
    int table8[2] = {0, 0};
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    Entity entity;
    std::memset(&entity, 0, sizeof(entity));
    s_entities[0] = &entity;

    func_00328230(&desc, 0, 0);
    assert(table8[0] == 0);

    desc.m_count = 1;
    s_entities[1] = 0;
    func_00328230(&desc, 1, 0);
    assert(table8[0] == 0);
}

static void test_vertex_append() {
    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_count = 1;

    MeshVertex buffer[4];
    std::memset(buffer, 0xFF, sizeof(buffer));
    void *table0[2] = {0, buffer};
    int table8[2] = {0, 0};
    desc.m_table_0 = table0;
    desc.m_table_8 = table8;

    Entity entity1;
    std::memset(&entity1, 0, sizeof(entity1));
    entity1.m_x = 10.2f;
    entity1.m_y = 20.9f;
    s_entities[2] = &entity1;

    func_00328230(&desc, 2, 1);
    assert(table8[1] == 1);
    assert(buffer[0].m_id == 2);
    assert(buffer[0].m_flags_4 == 0);
    assert(buffer[0].m_flags_5 == 0);
    assert(buffer[0].m_x == 10);
    assert(buffer[0].m_y == 21);

    Entity entity2;
    std::memset(&entity2, 0, sizeof(entity2));
    entity2.m_x = -5.4f;
    entity2.m_y = 12.1f;
    s_entities[3] = &entity2;

    func_00328230(&desc, 3, 1);
    assert(table8[1] == 2);
    assert(buffer[1].m_id == 3);
    assert(buffer[1].m_flags_4 == 0);
    assert(buffer[1].m_flags_5 == 0);
    assert(buffer[1].m_x == -5);
    assert(buffer[1].m_y == 12);
}

int main() {
    test_early_exits();
    test_vertex_append();
    return 0;
}
