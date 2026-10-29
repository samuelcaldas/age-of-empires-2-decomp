#ifndef UNIT_ACTION_BUILD_TARGET_CHECK_H
#define UNIT_ACTION_BUILD_TARGET_CHECK_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Validates visibility/targeting between actor and view before dispatching build rebind.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param a1 First dispatch parameter.
 * @param a2 Second dispatch parameter.
 * @param a3 Third dispatch parameter.
 * @param a4 Fourth dispatch parameter.
 */
void func_00270F80(ActionRebind *self, int a1, int a2, int a3, int a4);
void func_270F80(ActionRebind *self, int a1, int a2, int a3, int a4);

extern void *D_004E3180;
void* func_00186010(void *game);
void func_270E30(ActionRebind *self);
void func_00270E30(ActionRebind *self);
void func_264450(ActionRebind *self, int a1, int a2, int a3, int a4);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_TARGET_CHECK_H
