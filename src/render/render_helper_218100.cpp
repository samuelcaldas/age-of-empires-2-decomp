#pragma exceptions off
#include "sub_list.h"

extern "C" {

void func_00217DD0(void *self, int arg1, int arg2, int arg3);
int func_1F6460(void *self, void *arg1, int op, short arg3, int arg4);

/* 0x00218100 */
int func_00218100(void *self, void *arg1, int op, short arg3, int arg4) {
    char *s0 = (char *)self;
    void *v0 = *(void **)(s0 + 0x16C);
    if (v0 != 0 && arg1 == v0) {
        switch (op) {
        case 0:
            func_00217DD0(self, 3, 0, 1);
            return 1;
        case 1:
            func_00217DD0(self, 2, 0, 1);
            return 1;
        case 2:
            func_00217DD0(self, 5, 0, 1);
            return 1;
        case 3:
            func_00217DD0(self, 4, 0, 1);
            return 1;
        case 4:
            func_00217DD0(self, 1, arg3, 0);
            return 1;
        }
    }
    return func_1F6460(self, arg1, op, arg3, arg4);
}

}
