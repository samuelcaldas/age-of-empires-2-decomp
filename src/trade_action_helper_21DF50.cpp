#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DF50(void *obj, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    if (obj == 0) {
        return 0;
    }
    volatile void **p = (volatile void **)obj;
    p[0] = arg1;
    p[1] = arg2;
    p[2] = arg3;
    p[3] = arg4;
    p[4] = arg5;
    return obj;
}
}
