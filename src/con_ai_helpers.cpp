#include "sub_list.h"

struct SubListConItem;

extern "C" {
SubListConItem *func_0013F4B0(void *self, float x, float y);
void func_0013E1B0(SubListConItem *item);
void func_0013E1C0(SubListConItem *item);

void func_0013F3F0(void *self, float x, float y, int count);
void func_0013F450(void *self, float x, float y, int count);
}

void func_0013F3F0(void *self, float x, float y, int count) {
    SubListConItem *item = func_0013F4B0(self, x, y);
    if (!item) {
        return;
    }

    for (int i = 0; i < count; i++) {
        func_0013E1C0(item);
    }
}

void func_0013F450(void *self, float x, float y, int count) {
    SubListConItem *item = func_0013F4B0(self, x, y);
    if (!item) {
        return;
    }

    for (int i = 0; i < count; i++) {
        func_0013E1B0(item);
    }
}
