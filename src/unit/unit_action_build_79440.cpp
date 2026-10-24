#pragma exceptions off
#include "unit_action_build_79440.h"

extern "C" {
    void func_26AD60(void *self, int flag);
    void func_13A0A0(void *self, void *target, float x, float y, float z);
    void *func_139860(void *action_mgr);
    void func_347810(void *task, short *out_flag);
    void func_347880(void *task, short *out_flag1, short *out_flag2, int p3, int p4);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_ACTION_OFFSET 0x138
#else
#define UNIT_ACTION_OFFSET 0xCC
#endif

void func_00279440(void *self, void *target, float x, float y, float z) {
    func_26AD60(self, 0x400);
    func_13A0A0(self, target, x, y, z);
}

static int process_task_query(void *active_task, short action, short *out_flag1, short *out_flag2) {
    if (action == 0x7D || action == 0x7C || action == 0x7B) {
        func_347810(active_task, out_flag2);
        return 1;
    }
    if (action == 0x67 || action == 0x66) {
        func_347880(active_task, out_flag1, out_flag2, 0, 0);
        return 1;
    }
    return 0;
}

int func_002794B0(void *self, short *out_action_id, short *out_flag1, short *out_flag2) {
    *out_flag1 = -1;
    *out_flag2 = 0;
    void *action_mgr = *(void **)((char *)self + UNIT_ACTION_OFFSET);
    void *active_task = func_139860(action_mgr);
    short action = (active_task != 0) ? *(short *)((char *)active_task + 0x4) : 0;
    *out_action_id = action;
    return process_task_query(active_task, action, out_flag1, out_flag2);
}
