#ifndef UNIT_ACTION_BUILD_TASK_REMOVE_H
#define UNIT_ACTION_BUILD_TASK_REMOVE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Removes or reduces worker task assignment and shifts remaining slots.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param task_id Resource/task type identifier to remove.
 * @param amount Number of worker units to decrement.
 */
void func_0026FFB0(ActionRebind *self, int task_id, int amount);

void func_2E04D0(void *world, int task_id);
void func_002E04D0(void *world, int task_id);
float func_2E6C60(void *world, int task_id);
void Free__8BaseListFv(void *list);
void func_0026FF60(ActionRebind *self);

extern void *D_004E3180;

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_TASK_REMOVE_H
