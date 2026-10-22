#ifndef UNIT_ACTION_BUILD_TARGET_RECHECK_H
#define UNIT_ACTION_BUILD_TARGET_RECHECK_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Validates visibility/targeting between actor and view before forwarding to func_2646E0.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param a1 First dispatch parameter.
 * @param a2 Second dispatch parameter.
 * @param a3 Third dispatch parameter.
 * @param a4 Fourth dispatch parameter.
 */
void func_00271070(ActionRebind *self, int a1, int a2, int a3, int a4);
void func_271070(ActionRebind *self, int a1, int a2, int a3, int a4);

extern void *D_004E3180;
void* func_00186010(void *game);
void func_2646E0(ActionRebind *self, int a1, int a2, int a3, int a4);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_TARGET_RECHECK_H
