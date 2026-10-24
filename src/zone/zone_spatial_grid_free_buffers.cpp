#pragma exceptions off
#include "zone_spatial_grid_free_buffers.h"

extern "C" {
void func_1E6540(void *self);
void func_1E6400(void *self, int flag);
void func_100630(void *ptr);
}

struct SpatialGrid {
    char pad_64[0x64];
    void *buf_64;
    char pad_70[0x8];
    void *buf_70;
    char pad_7C[0x8];
    void *buf_7C;
};

extern "C" void func_001E6390(SpatialGrid *self) {
    func_1E6540(self);
    func_1E6400(self, 0);
    if (self->buf_64 != 0) {
        func_100630(self->buf_64);
        self->buf_64 = 0;
    }
    if (self->buf_70 != 0) {
        func_100630(self->buf_70);
        self->buf_70 = 0;
    }
    if (self->buf_7C != 0) {
        func_100630(self->buf_7C);
        self->buf_7C = 0;
    }
}
