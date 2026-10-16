#pragma exceptions off

#include "zone_init_bucket_arrays.h"

extern "C" {
void func_1D07D0(void *self, void *bucket, int capacity);
void *func_100730(int bytes);
}

extern "C" void func_001D08E0(void *self, void *bucket, int size) {
    char *b = (char *)bucket;
    int count = *(int *)(b + 0x10);
    int capacity = *(int *)(b + 0x14);

    if (count == capacity) {
        func_1D07D0(self, bucket, count + 4);
    }

    int idx = *(int *)(b + 0x10);
    *(int *)(b + 0x10) = idx + 1;

    *(int *)(*(char **)(b + 0x8) + idx * 4) = size;

    int factor = *(int *)(b + 0x30);
    int total_words = size * factor;
    void *buf = func_100730(total_words * 4);

    *(void **)(*(char **)(b + 0x0) + idx * 4) = buf;

    *(int *)(b + 0x3C) += 1;
    *(int *)(b + 0x24) += size;
    *(int *)(b + 0x28) += size;

    if (*(int *)(b + 0x1C) == -1) {
        *(int *)(b + 0x1C) = idx;
        *(int *)(b + 0x20) = 0;
    }
}
