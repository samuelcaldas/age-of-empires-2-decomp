#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00218100(void *self, int arg1) {
    char *s0 = (char *)self;
    void *ptr16C = *(void **)(s0 + 0x16C);
    if (ptr16C == 0) {
        return;
    }
    int val16C = *(int *)ptr16C;
    if (val16C != arg1) {
        return;
    }
}
}
