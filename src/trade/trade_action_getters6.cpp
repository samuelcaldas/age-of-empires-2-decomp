#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_002B61F0(void *self, int index) {
    if (index >= 0) {
        if (index < 239) {
            return *(int *)((char *)self + (index * 4) + 0x858);
        }
    }
    return -1;
}
}
