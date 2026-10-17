#pragma exceptions off
#include "unit_action_build_795e0.h"

extern "C" {
    void func_138D10(void *action_mgr);
    void *func_366DA0(void *pool);
    void func_365740(void *task, void *self, void *target);
    void func_139430(void *action_mgr, void *task);
    float func_1DEA80(void *self);
}

#if defined(__LP64__) || defined(_LP64)
#define UNIT_ACTION_OFFSET 0x138
#else
#define UNIT_ACTION_OFFSET 0xCC
#endif

void func_002795E0(void *self, void *target) {
    void *action_mgr = *(void **)((char *)self + UNIT_ACTION_OFFSET);
    func_138D10(action_mgr);
    void *task = func_366DA0(nullptr);
    if (task == 0) return;
    func_365740(task, self, target);
    func_139430(action_mgr, task);
}

int func_00279660(void *self) {
    *(short *)((char *)self + 0x124) += 1;
    return 1;
}

int func_00279690(void *self) {
    short count = *(short *)((char *)self + 0x124);
    if (count > 0) {
        *(short *)((char *)self + 0x124) = count - 1;
    }
    return 1;
}

float func_002796C0(void *self) {
    short count = *(short *)((char *)self + 0x124);
    if (count <= 0) return 0.0f;
    return func_1DEA80(self);
}
