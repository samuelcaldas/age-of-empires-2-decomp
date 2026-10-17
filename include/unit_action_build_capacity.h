#ifndef UNIT_ACTION_BUILD_CAPACITY_H
#define UNIT_ACTION_BUILD_CAPACITY_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculates remaining worker capacity or delta against field 366.
 *
 * @param self Pointer to the ActionRebind instance.
 * @return Remaining capacity or 0.
 */
int func_00271460(ActionRebind *self);
int func_271460(ActionRebind *self);

int func_00268500(ActionRebind *self);
int func_00268530(ActionRebind *self);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_CAPACITY_H
