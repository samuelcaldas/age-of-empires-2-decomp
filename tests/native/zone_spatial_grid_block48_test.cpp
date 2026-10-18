#include <cassert>
#include <cstring>
#include "zone_spatial_grid_clear_entity_markers.h"
#include "zone_spatial_grid_remove_node.h"
#include "zone_spatial_grid_set_obstacle_array.h"
#include "zone_spatial_grid_set_query_params.h"
#include "zone_spatial_grid_set_collision_margin.h"

static int g_func_1EE780_called = 0;
static int g_func_1F24A0_called = 0;

extern "C" {
void func_1EE780(SpatialGrid *self, void *node) {
    g_func_1EE780_called++;
}

void func_1F24A0(void *node) {
    g_func_1F24A0_called++;
}
}

struct MockMarker {
    char pad_00[0xC];
    MockMarker *next;
};

struct Entity {
    char pad_00[0x54];
    MockMarker *marker_list;
};

int main() {
    // -------------------------------------------------------------
    // Test 1: func_001EE730 - clear entity markers
    // -------------------------------------------------------------
    MockMarker marker2;
    marker2.next = 0;
    MockMarker marker1;
    marker1.next = &marker2;

    Entity entity;
    entity.marker_list = &marker1;

    g_func_1EE780_called = 0;
    int res = func_001EE730(0, &entity);
    assert(res == 1);
    assert(g_func_1EE780_called == 2);
    assert(entity.marker_list == 0);

    // -------------------------------------------------------------
    // Test 2: func_001EE860 - set obstacle array
    // -------------------------------------------------------------
    struct DummyGrid48 {
        char pad_00[0x12B584];
        char flag_88;
        char pad_8C[3];
        int count_8C;
        int *array_94;
        int field_12B590;
        int field_12B594;
        int field_12B598;
        char pad_12B59C[2];
        unsigned char has_margin;
        char pad_align;
        float margin;
    } grid;
    memset(&grid, 0, sizeof(grid));

    int dummy_array[4] = { 1, 2, 3, 4 };
    func_001EE860((SpatialGrid *)&grid, 1, (int)(long)dummy_array, 4);
    assert(grid.flag_88 == 1);
    assert(grid.count_8C == 4);
    assert(grid.array_94 == dummy_array);

    // When flag == 0 or count <= 0: zeroes out
    func_001EE860((SpatialGrid *)&grid, 0, (int)(long)dummy_array, 4);
    assert(grid.flag_88 == 0);
    assert(grid.count_8C == 0);
    assert(grid.array_94 == 0);

    // -------------------------------------------------------------
    // Test 3: func_001EE8D0 - set query params
    // -------------------------------------------------------------
    func_001EE8D0((SpatialGrid *)&grid, 10, 20, 30);
    assert(grid.field_12B590 == 10);
    assert(grid.field_12B594 == 20);
    assert(grid.field_12B598 == 30);

    // -------------------------------------------------------------
    // Test 4: func_001EE900 - set collision margin
    // -------------------------------------------------------------
    func_001EE900((SpatialGrid *)&grid, 1, 2.5f);
    assert(grid.has_margin == 1);
    assert(grid.margin == 2.5f);

    return 0;
}
