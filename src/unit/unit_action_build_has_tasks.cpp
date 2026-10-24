#pragma exceptions off
#include "unit_action_build_has_tasks.h"

int func_002714B0(ActionRebind *self) {
    if (HasItems__8BaseListFv(*(void**)((char*)self + 0xCC))) {
        return 1;
    }
    if (!HasItems__8BaseListFv(*(void**)((char*)self + 0x14C))) {
        return 0;
    }
    return 1;
}
