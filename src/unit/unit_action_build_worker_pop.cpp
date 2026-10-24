#pragma exceptions off
#include "unit_action_build_worker_pop.h"

struct TaskSlot {
    short m_task_id;
    short m_amount;
};

void func_00270450(ActionRebind *self) {
    unsigned char count = *(unsigned char*)((char*)self + 343);
    if (count == 0) {
        return;
    }

    TaskSlot *slots = *(TaskSlot**)((char*)self + 336);
    short tid = slots[0].m_task_id;

    void *world = *(void**)((char*)self + 8);
    float rate = func_2E6C60(world, tid);

    typedef void (*Method7CFn)(void *w, int stat, float val, int zero);
    void *w_vt = *(void**)((char*)world + 6960);
    Method7CFn m7c = *(Method7CFn*)((char*)w_vt + 124);
    m7c(world, 80, -rate, 0);

    slots = *(TaskSlot**)((char*)self + 336);
    slots[0].m_amount--;
    *(unsigned char*)((char*)self + 344) -= 1;
    *(unsigned char*)((char*)self + 345) += 1;

    if (slots[0].m_amount <= 0) {
        unsigned char c = *(unsigned char*)((char*)self + 343) - 1;
        *(unsigned char*)((char*)self + 343) = c;

        for (int i = 0; i < (int)c; ++i) {
            slots[i] = slots[i + 1];
        }

        func_0026FF60(self);
    }
}
