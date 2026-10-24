#pragma exceptions off
#include "unit_action_state_mgr.h"

void func_0026A460(void *action, float x, float y) {
    if (action == 0) {
        return;
    }
    int ix = func_123350(x);
    int iy = func_123350(y);
    func_3675D0(action, ix, iy);
    func_1C9E00(action, ix, iy);
}

void func_0026A540(void *action, int flag) {
    if (action == 0) {
        return;
    }
    func_26AD30(action, flag);
    if (func_26AD20(action, 1) != 0) {
        func_26AD60(action, flag);
    }
}

void func_0026A680(void *action, unsigned char frame) {
    if (action == 0) {
        return;
    }
    unsigned char cur = *(unsigned char*)((char*)action + 0x35);
    if (cur == frame) {
        return;
    }
    *(unsigned char*)((char*)action + 0x35) = frame;
}
