#pragma exceptions off
#include "zone_spatial_grid_clear_table_b4_flags.h"

struct TableEntry {
    char pad[0x20];
    char flag_20;
    char pad_21[3];
};

struct SpatialGrid {
    char pad_B4[0xB4];
    TableEntry *table_B4;
};

extern "C" void func_001EB220(SpatialGrid *self) {
    for (int i = 0; i < 4; i++) {
        self->table_B4[i].flag_20 = 0;
    }
}
