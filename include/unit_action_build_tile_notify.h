#ifndef UNIT_ACTION_BUILD_TILE_NOTIFY_H
#define UNIT_ACTION_BUILD_TILE_NOTIFY_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Notifies grid/spatial system of building tile placement coordinates.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_0026F8A0(ActionRebind *self);

int func_26A700(void *action, int *out1, int *out2);
int func_0026A700(void *action, int *out1, int *out2);
void func_25F6E0(void *field38, int a1, int a2, int a3, int a4, int a5);
void func_0025F6E0(void *field38, int a1, int a2, int a3, int a4, int a5);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_TILE_NOTIFY_H
