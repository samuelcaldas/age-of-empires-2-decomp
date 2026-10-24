#pragma exceptions off

#include "zone_spatial_pyramid_init.h"

extern "C" {
void *func_100730(int size);
void func_117AF8(void *dst, const void *src, int size);
void func_1D2140(void *self);
void func_1D2320(void *self, int x0, int y0, int x1, int y1);
}

extern "C" void *func_001D1D70(void *self, void *zone, const void *values, int count) {
    char *zm = (char *)self;
    *(void **)(zm + 0x94) = zone;

    char *v0 = *(char **)((char *)zone + 0x3C);
    *(void **)(zm + 0x98) = *(void **)(v0 + 0x8E8C);

    *(int *)(zm + 0x28) = 0;
    *(int *)(zm + 0x54) = 0;
    *(int *)(zm + 0x80) = 0;
    *(int *)(zm + 0xA0) = count;

    if (count > 0) {
        void *arr = func_100730(count * 4);
        *(void **)(zm + 0x9C) = arr;
        func_117AF8(arr, values, count * 4);
    } else {
        *(void **)(zm + 0x9C) = 0;
    }

    *(int *)(zm + 4) = 8;
    int e4 = *(int *)(v0 + 8);
    *(int *)(zm + 0xE4) = e4;
    int e8 = *(int *)(v0 + 0xC);
    *(int *)(zm + 0xE8) = e8;
    *(int *)(zm + 0xEC) = e4 - 1;
    *(int *)(zm + 0xF0) = e8 - 1;

    int stride = *(int *)(zm + 4);
    int s0 = (e4 + stride - 1) / stride;
    s0 = stride * s0;
    int s1 = (e8 + stride - 1) / stride;
    s1 = stride * s1;

    if (s0 > 0 && s1 > 0) {
        void ***root = (void ***)func_100730(0x10);
        *(void ****)(zm + 0) = root;

        for (int i = 0; i < 4; i++) {
            *(int *)(zm + 0xA4 + i * 4) = s0;
            *(int *)(zm + 0xB4 + i * 4) = s1;
            *(int *)(zm + 0xC4 + i * 4) = s0 - 1;
            *(int *)(zm + 0xD4 + i * 4) = s1 - 1;

            void **level_array = (void **)func_100730(s0 * 4);
            root[i] = level_array;

            int s4 = s1 * 2;
            for (int j = 0; j < s0; j++) {
                void *sub_buf = func_100730(s4);
                level_array[j] = sub_buf;
            }
            s0 >>= 1;
            s1 >>= 1;
        }
    } else {
        *(void **)(zm + 0) = 0;
    }

    func_1D2140(self);
    func_1D2320(self, 0, 0, *(int *)(zm + 0xE4), *(int *)(zm + 0xE8));

    return self;
}
