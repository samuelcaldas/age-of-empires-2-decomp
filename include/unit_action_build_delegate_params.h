#ifndef UNIT_ACTION_BUILD_DELEGATE_PARAMS_H
#define UNIT_ACTION_BUILD_DELEGATE_PARAMS_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Validates player world state and delegates 3-parameter action dispatch.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param a1 First dispatch parameter.
 * @param a2 Second dispatch parameter.
 * @param a3 Third dispatch parameter.
 */
void func_00271150(ActionRebind *self, int a1, int a2, int a3);
void func_271150(ActionRebind *self, int a1, int a2, int a3);

extern void *D_004E3180;
void func_186010(void *sing);
void func_002647C0(ActionRebind *self, int a1, int a2, int a3);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_DELEGATE_PARAMS_H
