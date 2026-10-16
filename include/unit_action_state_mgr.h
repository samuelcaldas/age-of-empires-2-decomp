#ifndef UNIT_ACTION_STATE_MGR_H
#define UNIT_ACTION_STATE_MGR_H

#include "unit_action_spatial_node.h"

extern "C" {
    void func_3675D0(void *arg0, int a1, int a2);
    void func_1C9E00(void *arg0, int a1, int a2, int a3 = 0, int a4 = 0, int a5 = 0);
    char func_26AD20(void *action, int flag);
    void func_26AD30(void *action, int flag);
    void func_26AD60(void *action, int flag);

    void func_0026A460(void *action, float x, float y);
    void func_0026A540(void *action, int flag);
    void func_0026A680(void *action, unsigned char frame);
}

#endif // UNIT_ACTION_STATE_MGR_H
