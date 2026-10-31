#pragma exceptions off

#include "zone_set_table_item_ranges.h"

struct RangeEntry {
    short min;
    short max;
    short val;
};

struct RangeTable {
    char pad[0x18];
    RangeEntry entries[1];
};

extern "C" void func_001CEA30(void *self, int index, int a2, int a3, int t0) {
    RangeTable *table = (RangeTable *)self;
    table->entries[(unsigned char)index].min = (short)a2;
    table->entries[(unsigned char)index].max = (short)a3;
    table->entries[(unsigned char)index].val = (short)t0;
}
