#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "map_zone.h"

static int g_func_002082B0_called = 0;
static void *g_last_obj = nullptr;
static int g_last_x = -1;
static int g_last_y = -1;

extern "C" {
    float D_004E2F24 = 1.0f;
    float D_004E2A98 = 1.0f;
    int *D_50A5A0[100];
    void func_226f70(void *stream, void *src, int size) {
        (void)stream; (void)src; (void)size;
    }
    void func_002082B0(void *obj, int x, int y) {
        g_func_002082B0_called++;
        g_last_obj = obj;
        g_last_x = x;
        g_last_y = y;
    }
}

static void test_map_zone_query() {
    MapZone zone;
    memset(&zone, 0, sizeof(zone));
    ZoneWorld world;
    memset(&world, 0, sizeof(world));
    zone.m_world = &world;

    int row0[10] = {0, 0x10, 0x20, 0};
    D_50A5A0[0] = row0;

    world.m_fieldC28 = 0x10;
    world.m_fieldC24 = 0x20;

    assert(func_001378C0(&zone, 1, 0) == 15);
    assert(func_001378C0(&zone, 2, 0) == 128);
    assert(func_001378C0(&zone, 0, 0) == 0);
}

static void test_map_zone_process_tiles() {
    MapZone zone;
    memset(&zone, 0, sizeof(zone));
    ZoneWorld world;
    memset(&world, 0, sizeof(world));
    zone.m_world = &world;
    zone.m_width = 2;
    zone.m_height = 2;
    zone.m_field2C = 0x40;

    unsigned char row0[2] = {255, 0};
    unsigned char row1[2] = {1, 255};
    unsigned char *rows[2] = {row0, row1};
    zone.m_row_ptrs = rows;

    int flag_row0[2] = {0, 0};
    int flag_row1[2] = {0, 0};
    D_50A5A0[0] = flag_row0;
    D_50A5A0[1] = flag_row1;

    g_func_002082B0_called = 0;
    func_00137920(&zone);

    assert(zone.m_field1C == 2);
    assert(row0[0] == 0);
    assert(row1[1] == 0);
    assert(flag_row0[0] == 0x40);
    assert(flag_row1[1] == 0x40);
    assert(world.m_fieldBBC == 1);
    assert(g_func_002082B0_called == 2);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_map_zone_query();
        test_map_zone_process_tiles();
        return 0;
    }
    int c = atoi(argv[1]);
    if (c == 0) test_map_zone_query();
    else if (c == 1) test_map_zone_process_tiles();
    return 0;
}
