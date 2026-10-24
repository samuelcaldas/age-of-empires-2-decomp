#pragma exceptions off
#include "unit_action_build_8d0.h"

typedef void (*VtableMethod)(void *, ActionRebind *, void *,
                              int, float, float, float);

void *func_002718D0(ActionRebind *self, void *other,
                    float x, float y, float z) {
    if (func_001EBA00((char *)other + 116) != 0) {
        return 0;
    }
    void *obj = func_00367230(70);
    if (obj == 0) {
        return 0;
    }
    VtableMethod *vtbl = *(VtableMethod **)obj;
    vtbl[3](obj, self, other, 1, x, y, z);
    return obj;
}
