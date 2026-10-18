#include <cassert>
#include <cstring>
#include "zone_spatial_grid_query_bounds.h"
#include "zone_spatial_grid_update_bounds_margin.h"
#include "zone_spatial_grid_set_entity_flags.h"

static int g_func_123350_called = 0;
static int g_func_1EE5A0_called = 0;
static int g_func_1F2320_called = 0;
static int g_func_117CAC_called = 0;
static int g_func_1EE660_called = 0;
static int g_func_1EE780_called = 0;

extern "C" {
int func_123350(float val) {
    g_func_123350_called++;
    return (int)val;
}

int func_1EE5A0(SpatialGrid *self, int x0, int y0, int x1, int y1, void *p5, int p6, int p7) {
    g_func_1EE5A0_called++;
    return 1;
}

void *func_1F2320(void *pool) {
    g_func_1F2320_called++;
    return (void *)0xCAFE;
}

void func_117CAC(void *dst, int val, int size) {
    g_func_117CAC_called++;
    memset(dst, val, size);
}

int func_1EE660(SpatialGrid *self, int x0, int y0, int x1, int y1, int p5) {
    g_func_1EE660_called++;
    return 1;
}

int func_1EE780(SpatialGrid *self, int p1, int p2, int p3, int p4) {
    g_func_1EE780_called++;
    return 2;
}
}

struct DummyGrid45 {
    char pad_00[0x12B41C];
    char is_initialized;
    char pad_align[3];
    void *world;
    int width;
    int height;
    float f_width;
    float f_height;
    char pad_table[0x12B578 - 0x12B434];
    void *pool;
};

int main() {
    // -------------------------------------------------------------
    // Test 1: func_001EE050 - set entity flags
    // -------------------------------------------------------------
    SpatialEntity entity;
    memset(&entity, 0, sizeof(entity));

    // When sub_obj is NULL, must return safely
    entity.sub_obj = 0;
    func_001EE050(0, &entity, 0x50);

    // When sub_obj is present: (flags & 0xF) | flag
    EntitySubObject sub;
    sub.flags = 0x23; // low nibble 3, high nibble 2
    entity.sub_obj = &sub;
    func_001EE050(0, &entity, 0x80);
    assert(sub.flags == ((0x23 & 0x0F) | 0x80)); // 0x83

    // -------------------------------------------------------------
    // Test 2: func_001EDF30 - update bounds margin
    // -------------------------------------------------------------
    DummyGrid45 grid;
    memset(&grid, 0, sizeof(grid));
    grid.width = 100;
    grid.height = 100;

    struct MockEntityData {
        char pad[0x20];
        float size_x;
        float size_y;
        char pad_28[0x82 - 0x28];
        unsigned char mode;
        unsigned char field_83;
    } mock_data;
    memset(&mock_data, 0, sizeof(mock_data));
    mock_data.size_x = 2.0f;
    mock_data.size_y = 2.0f;
    mock_data.mode = 1;
    mock_data.field_83 = 1;

    struct MockEntity {
        char pad[4];
        MockEntityData *data;
        void *world;
        char pad_0C[0x18];
        short field_24;
        char pad_26[0x44 - 0x26];
        float pos_x;
        float pos_y;
        char pad_4C[4];
        void *sub_obj;
    } mock_entity;
    memset(&mock_entity, 0, sizeof(mock_entity));
    mock_entity.data = &mock_data;
    mock_entity.pos_x = 10.0f;
    mock_entity.pos_y = 10.0f;

    g_func_123350_called = 0;
    g_func_1EE660_called = 0;
    g_func_1EE780_called = 0;

    int res_upd = func_001EDF30((SpatialGrid *)&grid, (Entity *)&mock_entity);
    assert(res_upd == 1);
    assert(g_func_123350_called == 4);
    assert(g_func_1EE660_called == 1);

    // -------------------------------------------------------------
    // Test 3: func_001EDA90 - query bounds
    // -------------------------------------------------------------
    g_func_123350_called = 0;
    g_func_1EE5A0_called = 0;

    int res_qb = func_001EDA90((SpatialGrid *)&grid, (Entity *)&mock_entity);
    assert(res_qb == 1);
    assert(g_func_1EE5A0_called == 1);

    return 0;
}
