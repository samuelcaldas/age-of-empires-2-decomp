#include <cassert>
#include <cstring>
#include "zone_spatial_grid_find_spatial_path.h"
#include "zone_spatial_grid_smooth_path_waypoints.h"
#include "zone_spatial_grid_clear_table_b4_flags.h"
#include "zone_spatial_grid_clear_table_b8_flags.h"

int main() {
    struct TableEntry {
        char pad[0x20];
        char flag_20;
        char pad_21[3];
    } table_b4[4], table_b8[4];

    for (int i = 0; i < 4; i++) {
        table_b4[i].flag_20 = 1;
        table_b8[i].flag_20 = 1;
    }

    struct DummyGrid {
        char pad_B4[0xB4];
        TableEntry *table_B4;
        TableEntry *table_B8;
    } dummy;
    dummy.table_B4 = table_b4;
    dummy.table_B8 = table_b8;

    func_001EB220((SpatialGrid *)&dummy);
    for (int i = 0; i < 4; i++) {
        assert(table_b4[i].flag_20 == 0);
    }

    func_001EB260((SpatialGrid *)&dummy);
    for (int i = 0; i < 4; i++) {
        assert(table_b8[i].flag_20 == 0);
    }
    return 0;
}
