#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DE30(void *obj, void *arg1, void *arg2) {
    if (obj == nullptr) {
        return nullptr;
    }
    volatile void **p = (volatile void **)obj;
    p[0] = arg1;
    p[1] = arg2;
    return obj;
}
}
