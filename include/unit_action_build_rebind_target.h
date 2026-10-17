#ifndef UNIT_ACTION_BUILD_REBIND_TARGET_H
#define UNIT_ACTION_BUILD_REBIND_TARGET_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculates modified action efficiency rate against target unit.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param target Pointer to the target unit instance.
 * @return Modified efficiency rate.
 */
float func_002709B0(ActionRebind *self, void *target);

float func_274C90(void *self, void *target);
float func_00274C90(void *self, void *target);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_REBIND_TARGET_H
