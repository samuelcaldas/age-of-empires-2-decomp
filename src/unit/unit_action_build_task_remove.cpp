#pragma exceptions off
#include "unit_action_build_task_remove.h"

struct TaskSlot {
    short m_task_id;
    short m_amount;
};

void func_0026FFB0(ActionRebind *self, int task_id, int amount) {
    unsigned char count = *(unsigned char*)((char*)self + 343);
    if (count == 0) {
        return;
    }

    short tid = (short)task_id;
    int s0 = (int)count - 1;
    while (s0 >= 0) {
        TaskSlot *slots = *(TaskSlot**)((char*)self + 336);
        if (slots[s0].m_task_id == tid) {
            short dec = (short)amount;
            if (slots[s0].m_amount < dec) {
                dec = slots[s0].m_amount;
            }

            void *world = *(void**)((char*)self + 8);
            for (short i = 0; i < dec; ++i) {
                func_2E04D0(world, task_id);
            }

            float rate = func_2E6C60(world, tid);
            typedef void (*Method7CFn)(void *w, int stat, float val, int zero);
            void *w_vt = *(void**)((char*)world + 6960);
            Method7CFn m7c = *(Method7CFn*)((char*)w_vt + 124);
            m7c(world, 80, -(float)dec * rate, 0);

            slots = *(TaskSlot**)((char*)self + 336);
            slots[s0].m_amount -= dec;
            *(unsigned char*)((char*)self + 344) -= (unsigned char)dec;
            *(unsigned char*)((char*)self + 345) += 1;

            if (slots[s0].m_amount <= 0) {
                unsigned char c = *(unsigned char*)((char*)self + 343) - 1;
                *(unsigned char*)((char*)self + 343) = c;

                for (int i = s0; i < (int)c; ++i) {
                    slots[i] = slots[i + 1];
                }

                if (s0 == 0) {
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
            break;
        }
        s0--;
    }

    func_0026FF60(self);
}
