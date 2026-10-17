#pragma exceptions off
#include "unit_action_build_worker_task.h"

struct TaskSlot {
    short m_task_id;
    short m_amount;
};

int func_0026FCC0(ActionRebind *self, int task_id, int amount) {
    unsigned char total = *(unsigned char*)((char*)self + 344);
    if (total >= 15) {
        typedef void (*Method17Fn)(void *sing, int a1, int pcount, int tid, int zero1, int zero2);
        void **vt = *(void***)&D_004E3180;
        Method17Fn m17 = (Method17Fn)vt[17];
        void *world = *(void**)((char*)self + 8);
        int pcount = *(int*)((char*)world + 2976);
        m17(&D_004E3180, 132, pcount, (short)task_id, 0, 0);
        return 0;
    }

    short req = (short)amount;
    if ((int)total + (int)req >= 16) {
        req = (short)(15 - (int)total);
    }

    void *world = *(void**)((char*)self + 8);
    int res = func_2E03F0(world, task_id, (float)req, 1);
    if (res == 0) {
        short s = req - 1;
        while (s >= 1) {
            req = s;
            res = func_2E03F0(world, task_id, (float)req, 1);
            if (res != 0) {
                break;
            }
            s--;
        }
        if (res == 0) {
            return 0;
        }
    }

    float rate = func_2E6C60(world, (short)task_id);
    typedef void (*Method7CFn)(void *sing, int stat, float val, int zero);
    void *w_vt = *(void**)((char*)world + 6960);
    Method7CFn m7c = *(Method7CFn*)((char*)w_vt + 124);
    m7c(world, 80, (float)req * rate, 0);

    unsigned char count = *(unsigned char*)((char*)self + 343);
    if (count > 0) {
        TaskSlot *slots = *(TaskSlot**)((char*)self + 336);
        if (slots[count - 1].m_task_id == (short)task_id) {
            slots[count - 1].m_amount += req;
            *(unsigned char*)((char*)self + 344) += (unsigned char)req;
            *(unsigned char*)((char*)self + 345) += 1;
            return 1;
        }
    }

    unsigned char cap = *(unsigned char*)((char*)self + 342);
    if (count == cap) {
        TaskSlot *new_slots = (TaskSlot*)func_1143F8(cap + 15, 4);
        if (new_slots == 0) {
            return 0;
        }
        TaskSlot *old_slots = *(TaskSlot**)((char*)self + 336);
        if (old_slots != 0) {
            for (int i = 0; i < (int)cap; ++i) {
                new_slots[i] = old_slots[i];
            }
            func_116F68(old_slots);
        }
        *(TaskSlot**)((char*)self + 336) = new_slots;
        *(unsigned char*)((char*)self + 342) += 15;
    }

    TaskSlot *slots = *(TaskSlot**)((char*)self + 336);
    slots[count].m_task_id = (short)task_id;
    slots[count].m_amount = req;
    *(unsigned char*)((char*)self + 344) += (unsigned char)req;
    *(unsigned char*)((char*)self + 343) += 1;
    *(unsigned char*)((char*)self + 345) += 1;
    return 1;
}
