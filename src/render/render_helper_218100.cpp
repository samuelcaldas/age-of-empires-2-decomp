#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00217DD0(void *self, int arg1, int arg2, int arg3);
void func_1F6460(void);

int func_00218100(void *self, int arg1, int op, int a3, int a4, int a5) {
    char *s0 = (char *)self;
    int ptr16C = *(int *)(s0 + 0x16C);
    if (ptr16C == 0 || ptr16C != arg1) {
        return 0;
    }

    if (op == 4) {
        func_00217DD0(self, 1, a4, 0);
        return 1;
    }
    if (op == 3) {
        func_00217DD0(self, a3, 0, 1);
        return 1;
    }
    if (op == 2) {
        func_00217DD0(self, 5, 0, 1);
        return 1;
    }
    if (op == 1) {
        func_00217DD0(self, a3, a4, 0);
        return 1;
    }
    if (op == 0) {
        func_00217DD0(self, a3, a5, 0);
        return 1;
    }
    func_1F6460();
    return 0;
}
}
