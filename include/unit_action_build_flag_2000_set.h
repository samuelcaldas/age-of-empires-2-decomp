#ifndef UNIT_ACTION_BUILD_FLAG_2000_SET_H
#define UNIT_ACTION_BUILD_FLAG_2000_SET_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Sets flag 0x2000 on action, updating field C0 timestamp from game singleton if active.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param enable Flag state (1 to set, 0 to clear).
 */
void func_002715F0(ActionRebind *self, int enable);
void func_2715F0(ActionRebind *self, int enable);

extern void *D_004E3180;
void func_26AD30(void *action, int flag, int enable);
char func_26AD20(void *action, int flag);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_FLAG_2000_SET_H
