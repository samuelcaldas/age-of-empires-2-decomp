#pragma exceptions off
#include "unit_action_build_progress.h"

int func_0026EC90(ActionRebind *self, short *out_type, short *out_val1, short *out_val2, int flag) {
    if (self == 0 || out_type == 0 || out_val1 == 0 || out_val2 == 0) {
        return 0;
    }

    void *list = *(void**)((char*)self + 0x12C);
    void *item = GetHeadItem__8BaseListFv(list);
    if (item == 0) {
        return 0;
    }

    *out_val1 = -1;
    *out_val2 = 0;
    short item_type = *(short*)((char*)item + 4);
    *out_type = item_type;

    if (item_type == 0x67) {
        func_347880(item, out_val1, out_val2, 0, 0);
        return 1;
    }

    if (self->m_world == 0 || func_00202B10(self->m_world) == 0) {
        return 0;
    }

    if (func_270900(self, out_val1, out_val2) == 0) {
        return 0;
    }

    if (flag != 0) {
        func_2794A0(self, 0x66);
    }

    return 1;
}

int func_0026ED90(ActionRebind *self) {
    if (self == 0) {
        return 100;
    }
    if (self->m_field39 != 0) {
        return 100;
    }
    if (self->m_field4 == 0) {
        return 100;
    }

    short max_work = *(short*)((char*)self->m_field4 + 0x13E);
    if (max_work == 0) {
        return 100;
    }

    float work = *(float*)((char*)self + 0x170);
    float pct = 100.0f * (work / (float)max_work);
    return func_123350(pct);
}
