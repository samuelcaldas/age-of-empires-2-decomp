#ifndef UNIT_ACTION_BUILD_SAVE_H
#define UNIT_ACTION_BUILD_SAVE_H

#include "unit_action_rebind.h"

extern "C" {
    char func_26AD20(void *action, int flag);
    void func_273330(ActionRebind *self, void *stream);
    void func_00226F70(void *stream, void *buffer, int size);
    void Save__8BaseListFPv(void *item, void *stream);

    void func_0026DAC0(ActionRebind *self, void *stream);
}

#endif // UNIT_ACTION_BUILD_SAVE_H
