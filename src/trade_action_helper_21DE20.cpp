#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DE20(void *obj, void *arg1, void *arg2, void *arg3) {
    if (obj == 0) {
        return 0;
    }
    volatile void **p = (volatile void **)obj;
    p[0] = arg1;
    p[1] = arg2;
    p[2] = arg3;
    return obj;
}
}
