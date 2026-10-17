#ifndef UNIT_ACTION_BUILD_WORKER_ADD_H
#define UNIT_ACTION_BUILD_WORKER_ADD_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Increments active worker counters and accumulates construction rate.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param target Pointer to the target unit instance.
 */
void func_0026F430(ActionRebind *self, void *target);

void func_278D50(void *self, void *target);
void func_00278D50(void *self, void *target);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_WORKER_ADD_H
