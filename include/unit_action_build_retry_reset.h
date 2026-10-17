#ifndef UNIT_ACTION_BUILD_RETRY_RESET_H
#define UNIT_ACTION_BUILD_RETRY_RESET_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Consumes and applies pending retry status to tiles, then resets field 15A.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_00270E30(ActionRebind *self);
void func_270E30(ActionRebind *self);

void func_270BA0(ActionRebind *self, int status);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_RETRY_RESET_H
