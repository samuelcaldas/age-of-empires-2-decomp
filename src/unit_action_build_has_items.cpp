#pragma exceptions off
#include "unit_action_build_has_items.h"

int func_002714B0(ActionRebind *self) {
    void *list1 = *(void**)((char*)self + 204);
    if (HasItems__8BaseListFv(list1) != 0) {
        return 1;
    }

    void *list2 = *(void**)((char*)self + 332);
    if (HasItems__8BaseListFv(list2) != 0) {
        return 1;
    }

    return 0;
}
