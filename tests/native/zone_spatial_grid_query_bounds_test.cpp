#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_query_bounds.h"

struct EntityData {
    char pad_00[0x20];
    float size_x;
    float size_y;
    char pad_28[0x82 - 0x28];
    unsigned char mode;
    unsigned char field_83;
};

struct SubObject {
    int type;
    unsigned char mode;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    void *entity;
    int field_C;
    int cell_idx;
    int list_idx;
    short field_18;
    char pad_1A[2];
    unsigned char indices[4];
    float min_x;
    float min_y;
    float max_x;
    float max_y;
    float pad_box[4];
};

struct Entity {
    char pad_00[4];
    EntityData *data;
    void *world;
    char pad_0C[0x18];
    short field_24;
    char pad_26[0x44 - 0x26];
    float pos_x;
    float pos_y;
    char pad_4C[4];
    SubObject *sub_obj;
};

struct PyramidCell {
    SubObject **items;
    int count;
    int capacity;
};

struct PyramidLevel {
    int id;
    int shift;
    int dim;
    int offset;
    void *nodes;
};

struct SpatialGrid {
    char pad_00[0x27420];
    char buffer_27420[0x3FFC];
    char pad_after[0x12B41C - 0x27420 - 0x3FFC];
    char is_initialized;
    char pad_align[3];
    void *world;
    int width;
    int height;
    float f_width;
    float f_height;
    void *table1;
    void *table2;
    int level_count;
    PyramidCell *cells;
    int total_nodes;
    int level_lut[0x20];
    PyramidLevel levels[8];
    char pad_12B570[8];
    void *pool;
};

static int s_func_1EE5A0_called = 0;
static int s_func_1F2320_called = 0;
static SubObject s_mock_sub;

extern "C" {
int func_123350(float val) {
    return (int)val;
}

int func_1EE5A0(SpatialGrid *self, int x0, int y0, int x1, int y1, void *p5, int p6, int p7) {
    (void)self; (void)x0; (void)y0; (void)x1; (void)y1; (void)p5; (void)p6; (void)p7;
    s_func_1EE5A0_called++;
    return 1;
}

void *func_1F2320(void *pool) {
    (void)pool;
    s_func_1F2320_called++;
    std::memset(&s_mock_sub, 0, sizeof(s_mock_sub));
    return &s_mock_sub;
}

void func_117CAC(void *dst, int val, int size) {
    std::memset(dst, val, size);
}
}

int main() {
    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid) + 0x100000);
    std::memset(grid, 0, sizeof(SpatialGrid) + 0x100000);

    PyramidCell cells[16];
    std::memset(cells, 0, sizeof(cells));
    grid->cells = cells;

    // Initialize level LUT and level 0
    for (int i = 0; i < 0x20; i++) {
        grid->level_lut[i] = 0;
    }
    grid->levels[0].id = 0;
    grid->levels[0].shift = 2;
    grid->levels[0].dim = 4;
    grid->levels[0].offset = 0;

    EntityData edata;
    std::memset(&edata, 0, sizeof(edata));
    edata.size_x = 2.0f;
    edata.size_y = 2.0f;
    edata.field_83 = 1;

    Entity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.data = &edata;
    ent.pos_x = 10.0f;
    ent.pos_y = 10.0f;
    ent.field_24 = 123;

    // Test 1: mode == 0 -> should return 0
    edata.mode = 0;
    int r0 = func_001EDA90(grid, &ent);
    assert(r0 == 0);

    // Test 2: mode == 1 -> returns 1 after func_1EE5A0
    edata.mode = 1;
    int r1 = func_001EDA90(grid, &ent);
    assert(r1 == 1);
    assert(s_func_1EE5A0_called == 1);
    assert(ent.sub_obj == NULL);

    // Test 3: mode == 2 -> allocates sub_obj from pool and adds to pyramid cell
    edata.mode = 2;
    int r2 = func_001EDA90(grid, &ent);
    assert(r2 == 1);
    assert(ent.sub_obj == &s_mock_sub);
    assert(s_mock_sub.entity == &ent);
    assert(s_mock_sub.mode == 2);
    assert(s_mock_sub.type == 2);
    assert(s_mock_sub.min_x == 10.0f);
    assert(s_mock_sub.max_x == 2.0f);

    std::free(grid);
    return 0;
}
