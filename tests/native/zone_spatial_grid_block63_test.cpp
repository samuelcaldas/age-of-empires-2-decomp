#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include "zone_spatial_grid_destructor.h"

static int g_func_001F34D0_called = 0;
static void *g_func_001F34D0_arg_self = 0;

static int g_func_0021B430_called = 0;
static void *g_func_0021B430_last_arg = 0;

static int g_func_001F32F0_called = 0;
static void *g_func_001F32F0_arg_self = 0;

static int g_func_100670_called = 0;
static void *g_func_100670_last_arg = 0;

static int g_func_00116F68_called = 0;

struct StrictSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    void *field_14;
    int field_18;
    int field_1C;
    void *table_20[10];
    char buckets_48[10][256];
    int table_A48[10];
    int table_A70[10];
    int field_A98;
    int field_A9C;
    int field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    int field_AB0;
};

extern "C" {
void *D_004D9AD0[16] = { (void *)0x4D9AD0 };

void func_001F34D0(ZoneSpatialGrid *self) {
    g_func_001F34D0_called++;
    g_func_001F34D0_arg_self = self;
}

void func_00116F68(void *ptr) {
    g_func_00116F68_called++;
}

void func_0021B430(void *ptr) {
    g_func_0021B430_called++;
    g_func_0021B430_last_arg = ptr;
}

void func_001F32F0(ZoneSpatialGrid *self) {
    g_func_001F32F0_called++;
    g_func_001F32F0_arg_self = self;
}

void func_100670(void *ptr) {
    g_func_100670_called++;
    g_func_100670_last_arg = ptr;
}
}

int main() {
    // Case 1: Null self guard returns null without calling helpers
    g_func_001F34D0_called = 0;
    g_func_100670_called = 0;
    ZoneSpatialGrid *null_ret = func_001F2590(NULL, 1);
    assert(null_ret == NULL);
    assert(g_func_001F34D0_called == 0);
    assert(g_func_100670_called == 0);

    // Case 2: Populated object destruction with flag = 0 (no delete)
    StrictSpatialGrid *grid = new StrictSpatialGrid();
    memset(grid, 0xEE, sizeof(StrictSpatialGrid));
    grid->field_14 = 0; // empty linked list

    char dummy_sub[32];
    for (int i = 0; i < 10; ++i) {
        grid->table_20[i] = (i % 2 == 0) ? dummy_sub : 0;
        grid->buckets_48[i][0] = (char)0x77;
        grid->table_A48[i] = 100 + i;
        grid->table_A70[i] = 200 + i;
    }

    g_func_001F34D0_called = 0;
    g_func_0021B430_called = 0;
    g_func_001F32F0_called = 0;
    g_func_100670_called = 0;

    ZoneSpatialGrid *ret0 = func_001F2590((ZoneSpatialGrid *)grid, 0);

    assert(ret0 == (ZoneSpatialGrid *)grid);
    assert(grid->vtable_00 == (void *)D_004D9AD0);
    assert(g_func_001F34D0_called == 1);
    assert(g_func_001F34D0_arg_self == (void *)grid);
    assert(g_func_0021B430_called == 5); // 5 non-null entries
    assert(g_func_001F32F0_called == 1);
    assert(g_func_001F32F0_arg_self == (void *)grid);
    assert(g_func_100670_called == 0); // flag was 0

    for (int i = 0; i < 10; ++i) {
        assert(grid->table_20[i] == 0);
        assert(grid->buckets_48[i][0] == ((i % 2 == 0) ? 0 : 0x77));
        assert(grid->table_A48[i] == ((i % 2 == 0) ? 0 : 100 + i));
        assert(grid->table_A70[i] == ((i == 0) ? 0 : 200 + i));
    }

    // Case 3: flag = 1 invokes func_100670 (operator delete)
    g_func_100670_called = 0;
    g_func_100670_last_arg = 0;

    ZoneSpatialGrid *ret1 = func_001F2590((ZoneSpatialGrid *)grid, 1);
    assert(ret1 == (ZoneSpatialGrid *)grid);
    assert(g_func_100670_called == 1);
    assert(g_func_100670_last_arg == (void *)grid);

    delete grid;
    return 0;
}
