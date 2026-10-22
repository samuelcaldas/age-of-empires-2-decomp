#ifndef UNIT_ACTION_BUILD_OFFSET_QUERY_H
#define UNIT_ACTION_BUILD_OFFSET_QUERY_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Queries target distance offset subtracting field 16E from waypoint/target range.
 *
 * @param self Pointer to the ActionRebind instance.
 * @return Adjusted target distance value, or 0 if target is invalid.
 */
int func_00271460(ActionRebind *self);
int func_271460(ActionRebind *self);

int func_00268500(ActionRebind *self);
int func_00268530(ActionRebind *self);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_OFFSET_QUERY_H
