#pragma exceptions off
#include "unit_action_build_notify_state.h"

int func_00270900(ActionRebind *self, short *out_task_id, short *out_flag) {
    *out_task_id = -1;
    *out_flag = 0;

    void *list = *(void**)((char*)self + 332);
    void *item = GetHeadItem__8BaseListFv(list);
    if (item != 0) {
        if (*(short*)((char*)item + 4) == 102) {
            func_347880(item, out_task_id, out_flag, 0, 0);
            return 1;
        }
    }

    unsigned char count = *(unsigned char*)((char*)self + 343);
    if ((int)count > 0) {
        void *slots = *(void**)((char*)self + 336);
        *out_task_id = *(short*)slots;
        *out_flag = 0;
        return 1;
    }

    return 0;
}
