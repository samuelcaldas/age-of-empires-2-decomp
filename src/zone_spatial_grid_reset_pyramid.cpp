#pragma exceptions off
#include "zone_spatial_grid_reset_pyramid.h"

extern "C" {
void func_1E4090(void *ptr);
void *func_117CAC(void *dst, int val, unsigned int size);
void func_1002A0(void *ptr, void *fn);
void func_100630(void *ptr);
void func_1FD400(void *p, int flag);
extern void *func_1FD480;
}

struct SpatialGrid {
    char pad_4[0x4];
    int f4;
    int f8;
    void **fC;
    char pad_8C[0x7C];
    int f8C;
    int f90;
    void *f94;
    char pad_A0[0x8];
    void *fA0;
    char pad_B4[0x10];
    void *fB4;
    void *fB8;
    char pad_CC[0x10];
    char fCC[0x100];
    char f1CC[0x400];
    char f5CC[0x400];
};

extern "C" void func_001E6550(SpatialGrid *self) {
    int count = self->f8;
    for (int i = 0; i < count; i++) {
        void *item = self->fC[i];
        if (item != 0) {
            func_1E4090(item);
            func_117CAC(item, 0, 0x2C);
            self->fC[i] = 0;
        }
    }
    self->f4 = 0;
    func_117CAC(&self->f1CC[0], 0, 0x400);
    self->f8 = 0;
    func_117CAC(&self->f5CC[0], 0, 0x400);
    self->fC = 0;
    self->fA0 = 0;
    if (self->fB4 != 0) {
        func_1002A0(self->fB4, &func_1FD480);
        self->fB4 = 0;
    }
    if (self->fB8 != 0) {
        func_1002A0(self->fB8, &func_1FD480);
        self->fB8 = 0;
    }
    if (self->f94 != 0) {
        if (self->f94 != &self->fCC[0]) {
            func_100630(self->f94);
        }
        self->f94 = 0;
    }
    self->f90 = 0;
    func_1FD400(self, -1);
    self->f8C = 0;
}
