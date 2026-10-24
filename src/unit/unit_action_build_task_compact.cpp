#pragma exceptions off
#include "unit_action_build_task_compact.h"

struct TaskSlot {
    short m_task_id;
    short m_amount;
};

void func_002701D0(ActionRebind *self, int worker_index) {
    unsigned char count = *(unsigned char*)((char*)self + 343);
    if (count == 0) {
        return;
    }

    int s0 = 0;
    int cur_idx = 0;
    int in_slot = 0;
    TaskSlot *slots = *(TaskSlot**)((char*)self + 336);

    while (cur_idx != worker_index) {
        in_slot++;
        if (in_slot < (int)slots[s0].m_amount) {
            cur_idx++;
            continue;
        }
        s0++;
        if (s0 >= (int)count) {
            break;
        }
        in_slot = 0;
        cur_idx++;
    }

    if (cur_idx == worker_index) {
        void *world = *(void**)((char*)self + 8);
        short tid = slots[s0].m_task_id;
        func_2E04D0(world, tid);

        float rate = func_2E6C60(world, tid);
        typedef void (*Method7CFn)(void *w, int stat, float val, int zero);
        void *w_vt = *(void**)((char*)world + 6960);
        Method7CFn m7c = *(Method7CFn*)((char*)w_vt + 124);
        m7c(world, 80, -rate, 0);

        slots[s0].m_amount--;
        *(unsigned char*)((char*)self + 344) -= 1;
        *(unsigned char*)((char*)self + 345) += 1;

        if (slots[s0].m_amount <= 0) {
            unsigned char c = *(unsigned char*)((char*)self + 343) - 1;
            *(unsigned char*)((char*)self + 343) = c;

            for (int i = s0; i < (int)c; ++i) {
                slots[i] = slots[i + 1];
            }

            if (worker_index == 0) {
                short f154 = *(short*)((char*)self + 340);
                if (f154 != -1) {
                    typedef void (*Method17Fn)(void *sing, int a1, int pcount, int tid, int zero1, int zero2);
                    void **vt = *(void***)&D_004E3180;
                    Method17Fn m17 = (Method17Fn)vt[17];
                    int pcount = *(int*)((char*)world + 2976);
                    m17(&D_004E3180, 125, pcount, f154, 0, 0);
                    *(short*)((char*)self + 340) = -1;
                }
                Free__8BaseListFv(*(void**)((char*)self + 332));
            }
        }
    }

    func_0026FF60(self);
}
