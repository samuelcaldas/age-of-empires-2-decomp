#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_elevation_mesh_filter.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(sizeof(CellCoord) == 8, "coord size");
static_assert(sizeof(ZoneCell) == 28, "cell size");
static_assert(offsetof(ZoneCell, m_entity_count) == 0x0D, "entity_count");
static_assert(offsetof(ZoneCell, m_entities) == 0x14, "entities");
static_assert(offsetof(MapZone, m_cell_rows) == 0x8E8C, "cell_rows");
static_assert(offsetof(GameMgr, m_map_zone) == 0x3C, "map_zone");
static_assert(offsetof(CombatWorld, m_game_mgr) == 0xB98, "game_mgr");
static_assert(offsetof(ElevationMeshDescriptor, m_world) == 0x0C, "world");
static_assert(offsetof(ElevationMeshDescriptor, m_count) == 0x10, "count");
static_assert(offsetof(EntityDesc, m_active) == 0x03, "active");
static_assert(offsetof(EntityDesc, m_tag) == 0x91, "tag");
static_assert(offsetof(Entity, m_desc) == 0x04, "desc");
static_assert(offsetof(Entity, m_id) == 0x24, "id");

struct MockCall {
    void *self;
    short id;
    unsigned char tag;
};

static MockCall s_calls[16];
static int s_call_count = 0;
static CellCoord *s_mock_coords = 0;
static int s_mock_coord_count = 0;

extern "C" {
    void func_208480(void *, CellCoord **coords, int *count) {
        *coords = s_mock_coords;
        *count = s_mock_coord_count;
    }

    void func_328230(ElevationMeshDescriptor *self, short id, unsigned char tag) {
        assert(s_call_count < 16);
        s_calls[s_call_count].self = self;
        s_calls[s_call_count].id = id;
        s_calls[s_call_count].tag = tag;
        s_call_count++;
    }
}

static void test_early_exits() {
    EntityDesc desc_active;
    std::memset(&desc_active, 0, sizeof(desc_active));
    desc_active.m_active = 1;
    desc_active.m_tag = 10;

    Entity entity;
    std::memset(&entity, 0, sizeof(entity));
    entity.m_desc = &desc_active;
    entity.m_id = 99;

    Entity *entities[1] = {&entity};
    ZoneCell cell0;
    std::memset(&cell0, 0, sizeof(cell0));
    cell0.m_entity_count = 1;
    cell0.m_entities = entities;

    ZoneCell row0[1] = {cell0};
    ZoneCell *rows[1] = {row0};

    MapZone zone;
    std::memset(&zone, 0, sizeof(zone));
    zone.m_cell_rows = rows;

    GameMgr game_mgr;
    std::memset(&game_mgr, 0, sizeof(game_mgr));
    game_mgr.m_map_zone = &zone;

    CombatWorld world;
    std::memset(&world, 0, sizeof(world));
    world.m_game_mgr = &game_mgr;

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_world = &world;
    desc.m_count = 5;

    CellCoord query_coords[1] = {{0, 0}};
    s_mock_coords = query_coords;

    s_mock_coord_count = 0;
    s_call_count = 0;
    func_00328100(&desc, 0);
    TEST_ASSERT(s_call_count == 0, "early exit zero coord count failed");

    s_mock_coord_count = -1;
    s_call_count = 0;
    func_00328100(&desc, 0);
    TEST_ASSERT(s_call_count == 0, "early exit negative coord count failed");

    s_mock_coord_count = 1;
    desc.m_count = 0;
    s_call_count = 0;
    func_00328100(&desc, 0);
    TEST_ASSERT(s_call_count == 0, "early exit zero mesh count failed");
}

static void test_grid_entity_filtering() {
    EntityDesc desc_active_1;
    std::memset(&desc_active_1, 0, sizeof(desc_active_1));
    desc_active_1.m_active = 1;
    desc_active_1.m_tag = 42;

    EntityDesc desc_active_2;
    std::memset(&desc_active_2, 0, sizeof(desc_active_2));
    desc_active_2.m_active = 1;
    desc_active_2.m_tag = 77;

    EntityDesc desc_inactive;
    std::memset(&desc_inactive, 0, sizeof(desc_inactive));
    desc_inactive.m_active = 0;
    desc_inactive.m_tag = 99;

    Entity entity_1;
    std::memset(&entity_1, 0, sizeof(entity_1));
    entity_1.m_desc = &desc_active_1;
    entity_1.m_id = 101;

    Entity entity_2;
    std::memset(&entity_2, 0, sizeof(entity_2));
    entity_2.m_desc = &desc_inactive;
    entity_2.m_id = 102;

    Entity entity_3;
    std::memset(&entity_3, 0, sizeof(entity_3));
    entity_3.m_desc = &desc_active_2;
    entity_3.m_id = 202;

    Entity *entities_cell0[3] = {&entity_1, 0, &entity_2};
    Entity *entities_cell1[1] = {&entity_3};

    ZoneCell cell0;
    std::memset(&cell0, 0, sizeof(cell0));
    cell0.m_entity_count = 3;
    cell0.m_entities = entities_cell0;

    ZoneCell cell1;
    std::memset(&cell1, 0, sizeof(cell1));
    cell1.m_entity_count = 1;
    cell1.m_entities = entities_cell1;

    ZoneCell row0[2] = {cell0, cell1};
    ZoneCell *rows[1] = {row0};

    MapZone zone;
    std::memset(&zone, 0, sizeof(zone));
    zone.m_cell_rows = rows;

    GameMgr game_mgr;
    std::memset(&game_mgr, 0, sizeof(game_mgr));
    game_mgr.m_map_zone = &zone;

    CombatWorld world;
    std::memset(&world, 0, sizeof(world));
    world.m_game_mgr = &game_mgr;

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_world = &world;
    desc.m_count = 1;

    CellCoord query_coords[2] = {{0, 0}, {1, 0}};
    s_mock_coords = query_coords;
    s_mock_coord_count = 2;
    s_call_count = 0;

    func_00328100(&desc, 0);

    TEST_ASSERT(s_call_count == 2, "grid entity filtering call count contract violated");
    TEST_ASSERT(s_calls[0].self == &desc, "grid entity filtering self pointer mismatch");
    TEST_ASSERT(s_calls[0].id == 101, "grid entity filtering entity id mismatch");
    TEST_ASSERT(s_calls[0].tag == 42, "grid entity filtering tag mismatch");

    TEST_ASSERT(s_calls[1].self == &desc, "grid entity filtering self pointer mismatch");
    TEST_ASSERT(s_calls[1].id == 202, "grid entity filtering entity id mismatch");
    TEST_ASSERT(s_calls[1].tag == 77, "grid entity filtering tag mismatch");
}

static void test_inactive_entity_rejection() {
    EntityDesc desc_inactive;
    std::memset(&desc_inactive, 0, sizeof(desc_inactive));
    desc_inactive.m_active = 0; // inactive entity must be rejected
    desc_inactive.m_tag = 99;

    EntityDesc desc_active;
    std::memset(&desc_active, 0, sizeof(desc_active));
    desc_active.m_active = 1; // active entity must be accepted
    desc_active.m_tag = 42;

    Entity entity_inactive;
    std::memset(&entity_inactive, 0, sizeof(entity_inactive));
    entity_inactive.m_desc = &desc_inactive;
    entity_inactive.m_id = 105;

    Entity entity_active;
    std::memset(&entity_active, 0, sizeof(entity_active));
    entity_active.m_desc = &desc_active;
    entity_active.m_id = 106;

    Entity *entities_cell0[2] = {&entity_inactive, &entity_active};

    ZoneCell cell0;
    std::memset(&cell0, 0, sizeof(cell0));
    cell0.m_entity_count = 2;
    cell0.m_entities = entities_cell0;

    ZoneCell row0[1] = {cell0};
    ZoneCell *rows[1] = {row0};

    MapZone zone;
    std::memset(&zone, 0, sizeof(zone));
    zone.m_cell_rows = rows;

    GameMgr game_mgr;
    std::memset(&game_mgr, 0, sizeof(game_mgr));
    game_mgr.m_map_zone = &zone;

    CombatWorld world;
    std::memset(&world, 0, sizeof(world));
    world.m_game_mgr = &game_mgr;

    ElevationMeshDescriptor desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_world = &world;
    desc.m_count = 1;

    CellCoord query_coords[1] = {{0, 0}};
    s_mock_coords = query_coords;
    s_mock_coord_count = 1;
    s_call_count = 0;

    func_00328100(&desc, 0);
    // Exactly 1 call (for the active entity), proving inactive entity was rejected and active was accepted
    TEST_ASSERT(s_call_count == 1, "inactive entity rejection contract failed (inactive entity was not filtered out)");
    TEST_ASSERT(s_calls[0].id == 106, "inactive entity rejection active id mismatch");
    TEST_ASSERT(s_calls[0].tag == 42, "inactive entity rejection active tag mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "early_exits") == 0) { test_early_exits(); return 0; }
        if (std::strcmp(argv[1], "grid_filtering") == 0) { test_grid_entity_filtering(); return 0; }
        if (std::strcmp(argv[1], "inactive_rejection") == 0) { test_inactive_entity_rejection(); return 0; }
    }
    test_early_exits();
    test_grid_entity_filtering();
    test_inactive_entity_rejection();
    return 0;
}
