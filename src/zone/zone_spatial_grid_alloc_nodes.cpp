#pragma exceptions off
#include "zone_spatial_grid_alloc_nodes.h"

extern "C" {
void *func_100730(unsigned int size);
extern int D_004E3284;
}

struct NodeEntry {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
};

struct SpatialGrid {
    int m_f0;       // 0x00
    void *m_f4;     // 0x04
    int m_count1;   // 0x08 = 0x20
    void *m_fC;     // 0x0C
    int m_f10;      // 0x10
    int m_f14;      // 0x14
    int m_f18;      // 0x18
    int m_f1C;      // 0x1C
    int m_f20;      // 0x20
    int m_count2;   // 0x24 = 0xC8
    NodeEntry *m_f28;// 0x28
};

extern "C" void func_001E3FA0(SpatialGrid *self) {
    self->m_f0 = 0;
    self->m_count1 = 0x20;
    self->m_f20 = 0;
    self->m_count2 = 0xC8;

    long v1 = (long)self->m_count1;
    self->m_f4 = func_100730((int)(v1 << 3));
    long v2 = (long)self->m_count1;
    self->m_fC = func_100730((int)(v2 << 2));
    long v3 = (long)self->m_count2;
    self->m_f28 = (NodeEntry *)func_100730((int)((v3 * 5) << 2));

    self->m_f1C = 0;
    self->m_f18 = 0;
    self->m_f14 = 0;
    self->m_f10 = 0;

    D_004E3284++;
}
