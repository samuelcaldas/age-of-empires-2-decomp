#ifndef UNIT_ACTION_BUILD_STAGE_H
#define UNIT_ACTION_BUILD_STAGE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Updates stage progress for construction actions on target units.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param arg1 Target parameter forwarded to func_001DF340.
 */
void func_0026EEA0(ActionRebind *self, void *arg1);

void func_001DF340(ActionRebind *self, void *arg1);
void func_1DF340(ActionRebind *self, void *arg1);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_STAGE_H
