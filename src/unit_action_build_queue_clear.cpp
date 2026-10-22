#pragma exceptions off
#include "unit_action_build_queue_clear.h"

struct ActionQueueLayout {
    void *vtable;
    void *m_master;
    char pad_8[0x12C - 8];
    void *m_list12C;
};

void func_00270EF0(ActionRebind *self) {
    ActionQueueLayout *act = (ActionQueueLayout*)self;
    short master_type = *(short*)((char*)act->m_master + 8);
    if (master_type == 50 || master_type == 199 || master_type == 276) {
        return;
    }

    func_1950D0(self);

    if (GetHeadItem__8BaseListFv(act->m_list12C)) {
        CallMethod13__8BaseListFv(act->m_list12C);
        Free__8BaseListFv(act->m_list12C);
        return;
    }

    func_00270530(self);
}
