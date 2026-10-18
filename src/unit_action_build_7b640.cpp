#pragma exceptions off
#include "unit_action_build_7b640.h"

struct EventRecord {
    short x;
    short y;
};

// True ELF entry: 0x27B620 (16 bytes)
int func_0027B620(void *self) {
    return *(int *)((char *)self + 0x5DC);
}

// True ELF entry: 0x27B630 (128 bytes)
int func_0027B630(void *self, int flag, int index, float *out_x, float *out_y) {
    int count = *(int *)((char *)self + 0x5DC);
    if (index >= count || index < 0) {
        return 0;
    }
    if ((flag & 0xFF) != 0) {
        return 1;
    }
    EventRecord *records = (EventRecord *)self;
    *out_x = (float)records[index].x;
    *out_y = (float)records[index].y;
    return 1;
}

// True ELF entry: 0x27B6B0 (80 bytes) - Allocator for free entry in 36-slot pool
void *func_0027B6B0(void *self) {
    for (int i = 0; i < 36; ++i) {
        char *entry = (char *)self + 0x1E4 + (i * 28);
        if (*(int *)(entry + 0x8) == 0) {
            return (void *)entry;
        }
    }
    return nullptr;
}

// Backward-compatible aliases
int func_0027B640(void *self) {
    return func_0027B620(self);
}

int func_0027B650(void *self, int flag, int index, float *out_x, float *out_y) {
    return func_0027B630(self, flag, index, out_x, out_y);
}

void *func_0027B6D0(void *self) {
    return func_0027B6B0(self);
}
