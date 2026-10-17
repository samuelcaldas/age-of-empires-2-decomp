#ifndef UNIT_ACTION_BUILD_WORKER_QUERY_H
#define UNIT_ACTION_BUILD_WORKER_QUERY_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Queries the task_id of a worker assigned at given cumulative worker index.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param worker_index Cumulative worker index across active task slots.
 * @return Task ID assigned to the worker, or -1 if index is invalid or list empty.
 */
int func_002703C0(ActionRebind *self, int worker_index);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_WORKER_QUERY_H
