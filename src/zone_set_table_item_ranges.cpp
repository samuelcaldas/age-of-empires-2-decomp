#pragma exceptions off

#include "zone_set_table_item_ranges.h"

extern "C" void func_001CEA30(void *self, int index, int a2, int a3, int t0) {
    char *entry = (char *)self + (unsigned char)index * 6;
    *(short *)(entry + 0x18) = (short)a2;
    *(short *)(entry + 0x1A) = (short)a3;
    *(short *)(entry + 0x1C) = (short)t0;
}
