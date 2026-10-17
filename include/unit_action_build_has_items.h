#ifndef UNIT_ACTION_BUILD_HAS_ITEMS_H
#define UNIT_ACTION_BUILD_HAS_ITEMS_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Checks if either worker or item sub-list contains active items.
 *
 * @param self Pointer to the ActionRebind instance.
 * @return 1 if either list has items, 0 otherwise.
 */
int func_002714B0(ActionRebind *self);
int func_2714B0(ActionRebind *self);

int HasItems__8BaseListFv(void *list);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_HAS_ITEMS_H
