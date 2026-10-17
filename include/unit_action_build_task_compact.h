#ifndef UNIT_ACTION_BUILD_TASK_COMPACT_H
#define UNIT_ACTION_BUILD_TASK_COMPACT_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Removes a single worker at given global worker index and compacts task slots.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param worker_index Index of the worker to remove across all task slots.
 */
void func_002701D0(ActionRebind *self, int worker_index);

void func_2E04D0(void *world, int task_id);
void func_002E04D0(void *world, int task_id);
float func_2E6C60(void *world, int task_id);
void Free__8BaseListFv(void *list);
void func_0026FF60(ActionRebind *self);

extern void *D_004E3180;

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_TASK_COMPACT_H
