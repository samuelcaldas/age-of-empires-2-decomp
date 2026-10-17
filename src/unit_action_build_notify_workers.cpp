#pragma exceptions off
#include "unit_action_build_notify_workers.h"

struct TaskSlot {
    short m_task_id;
    short m_amount;
};

void func_00270660(ActionRebind *self) {
    unsigned char count = *(unsigned char*)((char*)self + 343);
    if (count == 0) {
        return;
    }

    short a1, a2, a3;
    typedef int (*Method219Fn)(void *s, short *o1, short *o2, short *o3, int z1, int z2);
    void **vt = *(void***)self;
    Method219Fn m219 = (Method219Fn)vt[219];
    int res = m219(self, &a1, &a2, &a3, 0, 0);

    if (res != 0) {
        if (a1 == 102) {
            if (func_202B10() == 0) {
                return;
            }
        }
        if (a1 == 103) {
            return;
        }
        if ((unsigned int)(a1 - 123) < 3) {
            return;
        }
    }

    void *list = *(void**)((char*)self + 332);
    int s1 = -1;
    if (*(void**)((char*)list + 8) == 0) {
        void *world = *(void**)((char*)self + 8);
        TaskSlot *slots = *(TaskSlot**)((char*)self + 336);
        float rate = func_2E6C60(world, slots[0].m_task_id);

        void *w_node = *(void**)((char*)world + 2988);
        float f44 = *(float*)((char*)w_node + 44);
        float f324 = *(float*)((char*)w_node + 324);
        float f128 = *(float*)((char*)w_node + 128);

        if (rate + f44 + f324 <= f128) {
            s1 = 32;
        }
        if (s1 == -1) {
            float f16 = *(float*)((char*)w_node + 16);
            if (f16 - f324 - rate < 0.0f) {
                s1 = 4;
            }
        }

        if (s1 != -1) {
            if (func_202B10() != 0) {
                func_00270530(self);
                return;
            }
            short f154 = *(short*)((char*)self + 340);
            if (f154 == s1) {
                return;
            }
            if (f154 != -1) {
                typedef void (*Method17Fn)(void *sing, int msg, int pcount, int tid, int z1, int z2);
                void **s_vt = *(void***)&D_004E3180;
                Method17Fn m17 = (Method17Fn)s_vt[17];
                int pcount = *(int*)((char*)world + 2976);
                m17(&D_004E3180, 125, pcount, f154, 0, 0);
            }
            *(short*)((char*)self + 340) = (short)s1;
            typedef void (*Method17Fn)(void *sing, int msg, int pcount, int tid, int z1, int z2);
            void **s_vt = *(void***)&D_004E3180;
            Method17Fn m17 = (Method17Fn)s_vt[17];
            int pcount = *(int*)((char*)world + 2976);
            m17(&D_004E3180, 124, pcount, *(short*)((char*)self + 340), 0, 0);
            return;
        }

        short f154 = *(short*)((char*)self + 340);
        if (f154 != -1) {
            typedef void (*Method17Fn)(void *sing, int msg, int pcount, int tid, int z1, int z2);
            void **s_vt = *(void***)&D_004E3180;
            Method17Fn m17 = (Method17Fn)s_vt[17];
            int pcount = *(int*)((char*)&D_4E35DC + 2976);
            m17(&D_004E3180, 125, pcount, f154, 0, 0);
            *(short*)((char*)self + 340) = -1;
        }
        void *item = func_366D10(&D_4E35DC);
        if (item != 0) {
            TaskSlot *slots2 = *(TaskSlot**)((char*)self + 336);
            func_35D7C0(item, self, slots2[0].m_task_id, -1, 0);
            AddHead__8BaseListFPv(list, item);
        }
    }

    typedef int (*ActionMethodFn)(void *l);
    void **l_vt = *(void***)list;
    ActionMethodFn afn = (ActionMethodFn)l_vt[6];
    int act_res = afn(list);
    if ((act_res & 0xFF) == 3 || (unsigned int)((act_res & 0xFF) - 1) < 2) {
        DeleteHead__8BaseListFv(list);
        func_00270450(self);
    }
}
