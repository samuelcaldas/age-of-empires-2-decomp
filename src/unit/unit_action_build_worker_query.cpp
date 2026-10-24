#pragma exceptions off
#include "unit_action_build_worker_query.h"

struct TaskSlot {
    short m_task_id;
    short m_amount;
};

int func_002703C0(ActionRebind *self, int worker_index) {
    unsigned char count = *(unsigned char*)((char*)self + 343);
    if (count == 0) {
        return -1;
    }

    TaskSlot *slots = *(TaskSlot**)((char*)self + 336);
    int slot_idx = 0;
    int cur_worker = 0;
    int in_slot = 0;

    while (worker_index != cur_worker) {
        in_slot++;
        if (in_slot < (int)slots[slot_idx].m_amount) {
            cur_worker++;
            continue;
        }
        slot_idx++;
        if (slot_idx >= (int)count) {
            return -1;
        }
        in_slot = 0;
        cur_worker++;
    }

    return (int)slots[slot_idx].m_task_id;
}
