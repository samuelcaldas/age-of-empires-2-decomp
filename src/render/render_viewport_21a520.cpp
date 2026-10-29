#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_0021A550(void *self);

void *func_0021A520(void *self) {
    func_0021A550(self);
    return self;
}

void func_0021A550(void *self) {
    char *s = (char *)self;
    *(int *)(s + 0x0) = 0;
    *(int *)(s + 0x10) = 0;
    *(int *)(s + 0x8) = 0;
    *(int *)(s + 0xC) = 0;
    *(int *)(s + 0x4) = 0;
}

int func_0021A570(void *self) {
    *(int *)self = 0;
    return 0;
}

int func_0021A580(void *self, int arg1) {
    char *s = (char *)self;
    *(int *)(s + 0x14) = arg1;
    return arg1 == 0;
}
}
