#pragma exceptions off

#include "zone_spatial_grid_validate_cell_index.h"

extern "C" {
void func_001E46E0(void *self, void *ptr, int a2);
void func_001E4820(void *self, int a1, int a2);
}

struct SpatialStruct {
    int field_0;
    int field_4;
    char pad[0x18];
    int count;
    char pad_24[4];
    char *buffer;
};

extern "C" int func_001E4EC0(SpatialGrid *self, SpatialStruct *p1) {
    for (int i = 0; i < p1->count; i++) {
        func_001E46E0(self, p1->buffer + i * 20, 1);
    }
    func_001E4820(self, p1->field_4, p1->field_0);
    return 1;
}
