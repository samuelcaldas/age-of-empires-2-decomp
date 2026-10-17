#pragma exceptions off
#include "unit_action_build_formation.h"

int func_0026FC20(ActionRebind *self, int a1, int a2) {
    void *obj = func_366D70(&D_4E35DC);
    if (obj != 0) {
        func_363410(obj, self, (short)a1, a2);
    }
    if (obj == 0) {
        return 0;
    }
    void *list = *(void**)((char*)self + 300);
    Free__8BaseListFv(list);
    AddHead__8BaseListFPv(list, obj);
    return 1;
}
