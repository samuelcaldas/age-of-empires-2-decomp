#include <cassert>
#include <cstring>
#include "zone_path_eval.h"

extern "C" {
void *D_004E3180 = 0;
int func_123350(float val) {
    return static_cast<int>(val);
}
int func_1378c0(void *map_zone, int x, int y) {
    (void)map_zone; (void)x; (void)y;
    return 0;
}
float func_3675D0(void *unit) {
    (void)unit;
    return 1.0f;
}
}

int main() {
    // Setup mock building master
    BuildingMaster bld;
    std::memset(&bld, 0, sizeof(bld));
    bld.m_type_id = 0;
    bld.m_radius_x = 1.0f;
    bld.m_radius_y = 1.0f;
    bld.m_alt_radius_x = 1.0f;
    bld.m_alt_radius_y = 1.0f;
    bld.m_required_zone = -1;
    bld.m_field48 = -1;
    bld.m_field4A = -1;

    // Setup mock map structure
    // world + 0xB98 -> map
    // map + 0x68 -> slope_table (slope_table[0] -> slope_limits)
    // map + 0x3C -> s0 (s0 + 0x8: map_w, s0 + 0xC: map_h)
    char world_buf[0xC00];
    std::memset(world_buf, 0, sizeof(world_buf));

    char map_buf[0x100];
    std::memset(map_buf, 0, sizeof(map_buf));

    float slope_limits[256];
    for (int i = 0; i < 256; ++i) slope_limits[i] = 1.0f;
    float *slope_table[1] = { slope_limits };

    int s0_buf[0x2500];
    std::memset(s0_buf, 0, sizeof(s0_buf));
    s0_buf[2] = 100; // map_w at offset 0x8
    s0_buf[3] = 100; // map_h at offset 0xC

    *reinterpret_cast<void **>(world_buf + 0xB98) = map_buf;
    *reinterpret_cast<void **>(map_buf + 0x68) = slope_table;
    *reinterpret_cast<void **>(map_buf + 0x3C) = s0_buf;

    // Behavioral test 1: negative x coordinate out of bounds must return 7
    int res_neg_x = func_001C7850(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5.0f, 10.0f);
    assert(res_neg_x == 7);

    // Behavioral test 2: coordinate exceeding map dimensions must return 7
    int res_oob_x = func_001C7850(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 150.0f, 10.0f);
    assert(res_oob_x == 7);

    // Behavioral test 3: negative y coordinate out of bounds must return 7
    int res_neg_y = func_001C7850(&bld, world_buf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10.0f, -5.0f);
    assert(res_neg_y == 7);

    return 0;
}
