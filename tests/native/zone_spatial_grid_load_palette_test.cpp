#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include "zone_spatial_grid_load_palette.h"

struct MockPalette {
    int id;
};

struct MockManagerSub {
    char pad_00[0x45];
    unsigned char mode_45;
};

struct MockManager {
    char pad_00[0x6C];
    MockManagerSub *field_6C;
};

struct MockGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    void *field_10;
    void *field_14;
    int field_18;
    int field_1C;
    MockPalette *table_20[10];
    char buckets_48[10][256];
    int table_A48[10];
    int table_A70[16];
    int field_AB0;
};

static MockManager default_mock_mgr;
GlobalManager *D_004D89C0 = reinterpret_cast<GlobalManager *>(&default_mock_mgr);

static char observed_lwr_buffer[256];
static int observed_lwr_called = 0;

extern "C" char *func_001AAA70(char *s) {
    observed_lwr_called++;
    if (s != NULL) {
        for (char *p = s; *p; ++p) {
            if (*p >= 'A' && *p <= 'Z') {
                *p = *p + ('a' - 'A');
            }
        }
        std::strncpy(observed_lwr_buffer, s, sizeof(observed_lwr_buffer) - 1);
        observed_lwr_buffer[sizeof(observed_lwr_buffer) - 1] = '\0';
    }
    return s;
}

static char observed_loader_path[256];
static int observed_loader_key = 0;
static int observed_loader_policy = 0;
static int observed_loader_called = 0;
static MockPalette *mock_loader_return = 0;

extern "C" Palette *func_001A6270(const char *path, int key, int policy) {
    observed_loader_called++;
    observed_loader_key = key;
    observed_loader_policy = policy;
    if (path != NULL) {
        std::strncpy(observed_loader_path, path, sizeof(observed_loader_path) - 1);
        observed_loader_path[sizeof(observed_loader_path) - 1] = '\0';
    } else {
        observed_loader_path[0] = '\0';
    }
    return reinterpret_cast<Palette *>(mock_loader_return);
}

static int observed_extract_called = 0;
extern "C" int func_0021BAE0(void *palette_obj, int start_idx, int count, void *dst_buf) {
    observed_extract_called++;
    return 0;
}

static int observed_set_colors_called = 0;
extern "C" int func_0021BB20(void *palette_obj, int start_idx, int count, void *src_buf) {
    observed_set_colors_called++;
    return 0;
}

static int observed_release_called = 0;
extern "C" int func_0021B430(void *palette_obj) {
    observed_release_called++;
    return 0;
}

int main() {
    assert(offsetof(MockGrid, table_20) == 0x20);
    assert(offsetof(MockGrid, buckets_48) == 0x48);
    assert(offsetof(MockGrid, table_A48) == 0x0A48);
    assert(offsetof(MockGrid, table_A70) == 0x0A70);

    MockGrid grid;
    std::memset(&grid, 0, sizeof(grid));
    ZoneSpatialGrid *grid_ptr = reinterpret_cast<ZoneSpatialGrid *>(&grid);

    MockPalette cached_palette;
    cached_palette.id = 12345;

    // Setup cache entry at slot 3
    grid.table_20[3] = &cached_palette;
    grid.table_A70[3] = 100;
    std::strcpy(grid.buckets_48[3], "desert.pal");
    grid.table_A48[3] = 2;

    // Test Case 1: Cache Hit by key (flag1 matches table_A70[3], filename differs)
    Palette *res1 = func_001F2F80(grid_ptr, "unrelated_name.pal", 100, 0);
    assert(res1 == reinterpret_cast<Palette *>(&cached_palette));
    assert(grid.table_A48[3] == 3);

    // Test Case 2: Cache Hit by filename when flag1 == -1 (skips key check)
    observed_lwr_called = 0;
    Palette *res2 = func_001F2F80(grid_ptr, "DESERT", -1, 0);
    assert(res2 == reinterpret_cast<Palette *>(&cached_palette));
    assert(grid.table_A48[3] == 4);
    assert(observed_lwr_called >= 1);
    assert(std::strcmp(observed_lwr_buffer, "desert.pal") == 0);

    // Test Case 3: Cache Hit by filename when flag1 mismatches key (falls back to filename)
    Palette *res3 = func_001F2F80(grid_ptr, "desert.pal", 999, 0);
    assert(res3 == reinterpret_cast<Palette *>(&cached_palette));
    assert(grid.table_A48[3] == 5);

    // Test Case 4: Cache Miss on available slot 0 - loader returns NULL
    observed_loader_called = 0;
    mock_loader_return = 0;
    std::memset(observed_loader_path, 0, sizeof(observed_loader_path));

    Palette *res4 = func_001F2F80(grid_ptr, "missing_palette", -1, 0);
    assert(res4 == NULL);
    assert(observed_loader_called == 1);
    assert(std::strcmp(observed_loader_path, "missing_palette.pal") == 0);
    assert(grid.table_20[0] == NULL);
    assert(grid.table_A48[0] == 0);
    assert(grid.buckets_48[0][0] == '\0');

    // Test Case 5: Cache Miss on available slot 0 - loader succeeds
    MockPalette fresh_palette;
    fresh_palette.id = 54321;
    mock_loader_return = &fresh_palette;
    observed_loader_called = 0;
    std::memset(observed_loader_path, 0, sizeof(observed_loader_path));

    Palette *res5 = func_001F2F80(grid_ptr, "fresh", 77, 5);
    assert(res5 == reinterpret_cast<Palette *>(&fresh_palette));
    assert(observed_loader_called == 1);
    assert(std::strcmp(observed_loader_path, "fresh.pal") == 0);
    assert(observed_loader_key == 77);
    assert(observed_loader_policy == 5);
    assert(grid.table_20[0] == &fresh_palette);
    assert(grid.table_A48[0] == 1);
    assert(grid.table_A70[0] == 77);
    assert(std::strcmp(grid.buckets_48[0], "fresh.pal") == 0);

    // Test Case 6: Full cache, no hit returns NULL without calling loader
    MockPalette filler_palettes[10];
    for (int i = 0; i < 10; ++i) {
        grid.table_20[i] = &filler_palettes[i];
        grid.table_A70[i] = 1000 + i;
        std::sprintf(grid.buckets_48[i], "filler_%d.pal", i);
    }
    observed_loader_called = 0;
    Palette *res6 = func_001F2F80(grid_ptr, "unseen_palette", -1, 0);
    assert(res6 == NULL);
    assert(observed_loader_called == 0);

    // Test Case 7: NULL name normalization builds empty string
    grid.table_20[0] = NULL;
    observed_loader_called = 0;
    std::memset(observed_loader_path, 0, sizeof(observed_loader_path));
    mock_loader_return = &fresh_palette;
    Palette *res7 = func_001F2F80(grid_ptr, NULL, 55, 0);
    assert(res7 == reinterpret_cast<Palette *>(&fresh_palette));
    assert(observed_loader_called == 1);
    assert(std::strcmp(observed_loader_path, "") == 0);
    assert(grid.table_20[0] == &fresh_palette);
    assert(grid.table_A70[0] == 55);

    // Test Case 8: Mode 2 secondary palette loading and color setup
    grid.table_20[1] = NULL;
    MockManagerSub sub;
    std::memset(&sub, 0, sizeof(sub));
    sub.mode_45 = 2;
    default_mock_mgr.field_6C = &sub;

    observed_loader_called = 0;
    observed_extract_called = 0;
    observed_set_colors_called = 0;
    observed_release_called = 0;
    mock_loader_return = &fresh_palette;

    Palette *res8 = func_001F2F80(grid_ptr, "mode2_test", 66, 0);
    assert(res8 == reinterpret_cast<Palette *>(&fresh_palette));
    assert(observed_loader_called == 2);
    assert(observed_extract_called == 1);
    assert(observed_set_colors_called == 2);
    assert(observed_release_called == 1);
    assert(grid.table_20[1] == &fresh_palette);
    assert(grid.table_A70[1] == 66);
    assert(std::strcmp(grid.buckets_48[1], "mode2_test.pal") == 0);

    default_mock_mgr.field_6C = NULL;

    return 0;
}
