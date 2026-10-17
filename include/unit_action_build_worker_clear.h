#ifndef UNIT_ACTION_BUILD_WORKER_CLEAR_H
#define UNIT_ACTION_BUILD_WORKER_CLEAR_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Clears and releases all active worker task slots, updates stats, and resets task lists.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_00270530(ActionRebind *self);
void func_270530(ActionRebind *self);

void func_2E04D0(void *world, int task_id);
void func_002E04D0(void *world, int task_id);
float func_2E6C60(void *world, int task_id);
void Free__8BaseListFv(void *list);
void func_0026FF60(ActionRebind *self);

extern void *D_004E3180;

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_WORKER_CLEAR_H
