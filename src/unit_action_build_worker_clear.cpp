#pragma exceptions off
#include "unit_action_build_worker_clear.h"

struct TaskSlot {
    short m_task_id;
    short m_amount;
};

void func_00270530(ActionRebind *self) {
    unsigned char count = *(unsigned char*)((char*)self + 343);
    void *world = *(void**)((char*)self + 8);
    TaskSlot *slots = *(TaskSlot**)((char*)self + 336);

    for (int s0 = 0; s0 < (int)count; ++s0) {
        short tid = slots[s0].m_task_id;
        short amt = slots[s0].m_amount;

        for (short s1 = 0; s1 < amt; ++s1) {
            func_2E04D0(world, tid);
        }

        float rate = func_2E6C60(world, tid);
        typedef void (*Method7CFn)(void *w, int stat, float val, int zero);
        void *w_vt = *(void**)((char*)world + 6960);
        Method7CFn m7c = *(Method7CFn*)((char*)w_vt + 124);
        m7c(world, 80, -(rate * (float)amt), 0);
    }

    short f154 = *(short*)((char*)self + 340);
    if (f154 != -1) {
        typedef void (*Method17Fn)(void *sing, int a1, int pcount, int tid, int zero1, int zero2);
        void **vt = *(void***)&D_004E3180;
        Method17Fn m17 = (Method17Fn)vt[17];
        int pcount = *(int*)((char*)world + 2976);
        m17(&D_004E3180, 125, pcount, f154, 0, 0);
        *(short*)((char*)self + 340) = -1;
    }

    *(unsigned char*)((char*)self + 343) = 0;
    Free__8BaseListFv(*(void**)((char*)self + 332));
    *(unsigned char*)((char*)self + 344) = 0;
    *(unsigned char*)((char*)self + 345) += 1;

    func_0026FF60(self);
}
