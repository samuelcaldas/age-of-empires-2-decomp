#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021E070(void *obj, void *arg1, void *arg2, void *arg3, void *arg4) {
    if (obj == nullptr) {
        return nullptr;
    }
    volatile void **p = (volatile void **)obj;
    p[0] = arg1;
    p[1] = arg2;
    p[2] = arg3;
    p[3] = arg4;
    return obj;
}
}
