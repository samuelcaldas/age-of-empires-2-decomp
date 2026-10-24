#pragma exceptions off
#include "zone_spatial_grid_init_pyramid.h"

extern "C" {
void func_1E70F0(void *self, int val);
void *func_100730(unsigned int size);
void func_1004E0(void *dst, void *f1, void *f2, int size, int count);
void *func_117CAC(void *dst, int val, unsigned int size);
extern void *func_1E6530;
extern void *func_1FD480;
}

struct SpatialGrid {
    char pad_4[0x4];
    int f4;
    int f8;
    int fC;
    char pad_1C[0xC];
    int f1C;
    int f20;
    int f24;
    char pad_44[0x1C];
    int f44;
    int f48;
    int f4C;
    char pad_88[0x38];
    char f88;
    char pad_89[0x3];
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
    int fA0;
    int fA4;
    int fA8;
    int fAC;
    int fB0;
    void *fB4;
    void *fB8;
    float fBC;
    float fC0;
    float fC4;
    float fC8;
    char fCC[0x100];
    char f1CC[0x400];
    char f5CC[0x400];
};

extern "C" void func_001E6410(SpatialGrid *self, int alloc_buffers) {
    self->f4 = 0;
    self->f8 = 0;
    self->fC = 0;
    self->f98 = 0;
    self->f9C = 0;
    self->fA0 = 0;
    self->f88 = 0;
    self->f8C = 0;
    self->f90 = 0;
    self->f94 = 0;
    self->fA4 = -1;
    self->fA8 = -1;
    self->fAC = -1;
    self->fB0 = -1;
    self->fBC = 0.0f;
    self->fC0 = 0.0f;
    self->fC4 = 0.0f;
    self->fC8 = 0.0f;
    self->f1C = 0;
    self->f24 = 0;
    self->f20 = 0;
    self->f44 = 0;
    self->f4C = 0;
    self->f48 = 0;
    func_1E70F0(self, 0x40);
    if (alloc_buffers != 0) {
        void *b1 = func_100730(0xA0);
        func_1004E0(b1, &func_1E6530, &func_1FD480, 0x24, 4);
        void *b2 = func_100730(0xA0);
        self->fB4 = b1;
        func_1004E0(b2, &func_1E6530, &func_1FD480, 0x24, 4);
        self->fB8 = b2;
    }
    func_117CAC(&self->fCC[0], 0, 0x100);
    func_117CAC(&self->f1CC[0], 0, 0x400);
    func_117CAC(&self->f5CC[0], 0, 0x400);
}
