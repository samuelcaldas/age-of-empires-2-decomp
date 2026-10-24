#pragma exceptions off
#include "unit_action_build_4970.h"

extern "C" {
    void func_0013AB90(void *self);
    void func_00205F70(void *self);
    void func_002643C0(void *self, int flag);
    int func_0026AD20(void *self, int flag);
    void func_00272A88(void *self, float amount);
    void func_00264290(void *self);
    void func_00150F50(void *self);
    void func_002E00D0(void *self);
}

static void update_stat_adjustments(void *self) {
    if (func_0026AD20(self, 0x100)) {
        func_00272A88(self, -1.0f);
    }
    if (func_0026AD20(self, 0x400)) {
        func_00272A88(self, -1.0f);
    }
}

int func_274970(void *self, void *target) {
    func_0013AB90(self);
    func_00205F70(self);
    func_002643C0(self, 1);

    update_stat_adjustments(self);

    func_00264290(self);
    func_00150F50(self);
    func_002E00D0(self);

    return 1;
}
