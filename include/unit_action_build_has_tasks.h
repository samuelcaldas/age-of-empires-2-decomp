#ifndef UNIT_ACTION_BUILD_HAS_TASKS_H
#define UNIT_ACTION_BUILD_HAS_TASKS_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Checks if the construction action has active tasks in list 0xCC or list 0x14C.
 *
 * @param self Pointer to the ActionRebind instance.
 * @return 1 if either list contains items, 0 otherwise.
 */
int func_002714B0(ActionRebind *self);
int func_2714B0(ActionRebind *self);

int HasItems__8BaseListFv(void *list);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_HAS_TASKS_H
