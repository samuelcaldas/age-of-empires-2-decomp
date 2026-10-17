#ifndef UNIT_ACTION_BUILD_DELEGATE_H
#define UNIT_ACTION_BUILD_DELEGATE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Validates player world state and delegates secondary action dispatch without reset.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param a1 First dispatch parameter.
 * @param a2 Second dispatch parameter.
 * @param a3 Third dispatch parameter.
 * @param t0 Fourth dispatch parameter.
 */
void func_00271070(ActionRebind *self, int a1, int a2, int a3, int t0);
void func_271070(ActionRebind *self, int a1, int a2, int a3, int t0);

extern void *D_004E3180;
void func_186010(void *sing);
void func_002646E0(ActionRebind *self, int a1, int a2, int a3, int t0);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_DELEGATE_H
