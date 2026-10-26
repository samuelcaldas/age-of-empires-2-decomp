#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00219430(void *self, short arg1);

int func_002194D0(void *self, int arg1) {
    char *s = (char *)self;
    void *node = *(void **)(s + 0x11C);
    int index = 0;

    while (node != 0) {
        if (*(int *)((char *)node + 0x8) == arg1) {
            func_00219430(self, (short)index);
            return index;
        }
        node = *(void **)((char *)node + 0x28);
        index++;
    }

    return -1;
}
}
