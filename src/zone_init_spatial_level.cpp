#pragma exceptions off

#include "zone_init_spatial_level.h"

extern "C" {
void *func_100730(int size);
void func_100630(void *ptr);
void *func_117CAC(void *buf, int flag, int size);
}

extern "C" void func_001D07D0(void *self, void *bucket, int new_capacity) {
    char *b = (char *)bucket;
    int cur_cap = *(int *)(b + 0x14);
    if (new_capacity < cur_cap) {
        return;
    }

    int bytes = new_capacity * 4;
    void *new_buf0 = func_100730(bytes);
    func_117CAC(new_buf0, 0, bytes);

    void *new_buf1 = func_100730(bytes);
    func_117CAC(new_buf1, 0, bytes);

    void **old_buf0 = *(void ***)(b + 0x0);
    if (old_buf0 != 0) {
        int old_count = *(int *)(b + 0x10);
        void **old_buf1 = *(void ***)(b + 0x8);

        for (int i = 0; i < old_count; i++) {
            ((void **)new_buf0)[i] = old_buf0[i];
            ((void **)new_buf1)[i] = old_buf1[i];
        }

        func_100630(old_buf0);
        func_100630(old_buf1);
    }

    *(void **)(b + 0x0) = new_buf0;
    *(void **)(b + 0x8) = new_buf1;
    *(int *)(b + 0x14) = new_capacity;
}
