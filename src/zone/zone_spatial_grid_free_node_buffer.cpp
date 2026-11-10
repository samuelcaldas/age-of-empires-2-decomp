#pragma exceptions off
#include "zone_spatial_grid_free_node_buffer.h"

extern "C" {
void func_100630(void *ptr);
extern int D_004E3284;
extern void *D_004E3288;
extern int D_004E328C;
}

struct SpatialGrid {
    int m_f0;       // 0x00
    void *m_f4;     // 0x04
    int m_count1;   // 0x08
    void *m_fC;     // 0x0C
    int m_f10;      // 0x10
    int m_f14;      // 0x14
    int m_f18;      // 0x18
    int m_f1C;      // 0x1C
    int m_f20;      // 0x20
    int m_count2;   // 0x24
    void *m_f28;    // 0x28
};

extern "C" void func_001E40A0(SpatialGrid *self) {
    int freed_any = 0;
    if (self->m_f28 != 0) {
        func_100630(self->m_f28);
        freed_any++;
    }
    if (self->m_f4 != 0) {
        func_100630(self->m_f4);
        freed_any++;
    }
    if (self->m_fC != 0) {
        func_100630(self->m_fC);
        freed_any++;
    }

    if (freed_any != 0) {
        D_004E3284--;
    }

    if (D_004E3284 == 0) {
        if (D_004E3288 != 0) {
            func_100630(D_004E3288);
            D_004E3288 = 0;
        }
        D_004E328C = 0;
    }
}
