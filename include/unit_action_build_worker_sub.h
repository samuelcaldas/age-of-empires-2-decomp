#ifndef UNIT_ACTION_BUILD_WORKER_SUB_H
#define UNIT_ACTION_BUILD_WORKER_SUB_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Decrements active worker counters and subtracts construction rate.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param target Pointer to the target unit instance.
 */
void func_0026F4E0(ActionRebind *self, void *target);

void func_278E20(void *self, void *target);
void func_00278E20(void *self, void *target);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_WORKER_SUB_H
