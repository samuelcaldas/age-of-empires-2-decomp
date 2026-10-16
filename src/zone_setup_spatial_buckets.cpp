#pragma exceptions off

#include "zone_setup_spatial_buckets.h"

extern "C" {
void *func_117CAC(void *heap, int flag, int size);
void func_1D0EE0(void *self, void *bucket, int size);
void func_1D07D0(void *self, void *bucket, int flag);
void func_1D08E0(void *self, void *bucket, int size);
}

extern "C" void func_001D0430(void *self) {
    char *zm = (char *)self;
    *(int *)(zm + 0x8F04) = 2;

    int width = *(int *)(zm + 0x8);
    int height = *(int *)(zm + 0xC);

    int total_tiles = width * height;
    *(int *)(zm + 0x8F14) = total_tiles >> 3;
    *(int *)(zm + 0x8F08) = 4;
    *(int *)(zm + 0x8F18) = total_tiles >> 5;
    *(int *)(zm + 0x8F0C) = 12;
    *(int *)(zm + 0x8F1C) = 32;
    *(int *)(zm + 0x8F10) = 250;
    *(int *)(zm + 0x8F20) = 16;

    char *buf = (char *)func_117CAC((void *)0x8CEEC0, 0, 251);
    *(char **)(zm + 0x8F00) = buf;

    int a0 = 0;
    int a1 = 0;
    while (a0 < 251) {
        if (*(int *)(zm + 0x8F04 + a1 * 4) < a0) {
            a1++;
        }
        buf[a0] = (char)a1;
        a0++;
    }

    for (int i = 0; i < 4; i++) {
        char *bucket = zm + 0x8F24 + i * 68;
        *(int *)(bucket + 0x0) = 0;
        *(int *)(bucket + 0x8) = 0;
        *(int *)(bucket + 0xC) = i;
        *(int *)(bucket + 0x14) = 8;
        *(int *)(bucket + 0x10) = 0;
        *(int *)(bucket + 0x18) = 0;
        *(int *)(bucket + 0x1C) = -1;
        *(int *)(bucket + 0x20) = -1;
        *(int *)(bucket + 0x24) = 0;
        *(int *)(bucket + 0x28) = 0;

        int size = *(int *)(zm + 0x8F14 + i * 4);
        *(int *)(bucket + 0x2C) = size;
        *(int *)(bucket + 0x30) = *(int *)(zm + 0x8F04 + i * 4);

        func_1D0EE0(self, bucket + 0x2C, *(int *)(zm + 0x8F04 + i * 4));
        func_1D07D0(self, bucket + 0x2C, 8);
        func_1D08E0(self, bucket + 0x2C, size);
    }

    *(int *)(zm + 0x8EFC) = 1;
}
