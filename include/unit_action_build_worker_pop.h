#ifndef UNIT_ACTION_BUILD_WORKER_POP_H
#define UNIT_ACTION_BUILD_WORKER_POP_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Removes one worker from the primary task slot and compacts the slot array if depleted.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_00270450(ActionRebind *self);

float func_2E6C60(void *world, int task_id);
void func_0026FF60(ActionRebind *self);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_WORKER_POP_H
