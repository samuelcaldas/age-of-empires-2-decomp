#ifndef UNIT_ACTION_BUILD_WORK_H
#define UNIT_ACTION_BUILD_WORK_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Updates building action work state, periodic timer, and triggers completion callbacks.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_00271640(ActionRebind *self);

extern float D_004E2824;
extern char D_00D8EBC0[256];

char func_26AD20(void *action, int flag);
float func_3675D0(void *action);
void func_2717B0(void *action, void *buffer, int *out_valid, int count, int *out_count);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_WORK_H
