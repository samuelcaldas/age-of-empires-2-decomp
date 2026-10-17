#pragma exceptions off
#include "sub_list.h"

extern "C" {
int strcmp(const char *s1, const char *s2);
extern char D_004E32D0;

short func_00219AC0(void *self) {
    char *s = (char *)self;
    short count = *(short *)(s + 0x120);
    if (count == 0) {
        return -1;
    }
    return *(short *)(s + 0x128);
}

int func_00219AF0(void *self, int arg1) {
    char *s = (char *)self;
    void *node = *(void **)(s + 0x11C);
    int index = 0;

    while (node != 0) {
        if (*(int *)((char *)node + 0x8) == arg1) {
            return index;
        }
        node = *(void **)((char *)node + 0x28);
        index++;
    }

    return -1;
}

int func_00219B30(void *self, const char *arg1) {
    char *s = (char *)self;
    void *node = *(void **)(s + 0x11C);
    int index = 0;

    while (node != 0) {
        char *str = *(char **)node;
        if (strcmp(str, arg1) == 0) {
            return index;
        }
        node = *(void **)((char *)node + 0x28);
        index++;
    }

    return -1;
}

void *func_00219BA0(void *self) {
    void **vtable = *(void ***)self;
    typedef void *(*VirtualMethod128)(void *, short);
    VirtualMethod128 method128 = (VirtualMethod128)*(void **)((char *)vtable + 0x128);
    short f128 = *(short *)((char *)self + 0x128);
    return method128(self, f128);
}

const char *func_00219BC0(void *self, int index) {
    char *s = (char *)self;
    void *node = *(void **)(s + 0x11C);
    int idx = 0;

    while (node != 0) {
        if (idx == index) {
            return *(const char **)node;
        }
        node = *(void **)((char *)node + 0x28);
        idx++;
    }

    D_004E32D0 = '\0';
    return &D_004E32D0;
}
}
