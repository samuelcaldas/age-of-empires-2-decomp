#ifndef UNIT_ACTION_BUILD_DISPATCH_H
#define UNIT_ACTION_BUILD_DISPATCH_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Validates player world state, invokes retry reset, and delegates action dispatch.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param a1 First dispatch parameter.
 * @param a2 Second dispatch parameter.
 * @param a3 Third dispatch parameter.
 * @param t0 Fourth dispatch parameter.
 */
void func_00270F80(ActionRebind *self, int a1, int a2, int a3, int t0);
void func_270F80(ActionRebind *self, int a1, int a2, int a3, int t0);

extern void *D_004E3180;
void func_186010(void *sing);
void func_00270E30(ActionRebind *self);
void func_00264450(ActionRebind *self, int a1, int a2, int a3, int t0);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_DISPATCH_H
