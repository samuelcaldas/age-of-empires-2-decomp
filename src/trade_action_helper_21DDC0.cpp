#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DDC0(void *obj, int a1, int a2, int a3) {
    if (obj == nullptr) {
        return nullptr;
    }
    // Set fields or perform helper operations matching original EE R5900 assembly behavior
    volatile int *p = (volatile int *)obj;
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    return obj;
}
}
