#ifndef UNIT_ACTION_BUILD_STEP_H
#define UNIT_ACTION_BUILD_STEP_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculates current building animation frame step index clamped to limits.
 *
 * @param self Pointer to the ActionRebind instance.
 * @return 0-based animation step index.
 */
int func_00270E70(ActionRebind *self);
int func_270E70(ActionRebind *self);

int func_123350(float val);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_STEP_H
