#ifndef UNIT_ACTION_BUILD_RETRY_H
#define UNIT_ACTION_BUILD_RETRY_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Handles action retry transition and tile flag validation.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param status Status / action state code.
 */
void func_00270A20(ActionRebind *self, int status);
void func_270A20(ActionRebind *self, int status);

extern void *D_004E3180;
int func_123350(float val);
int func_1378c0(void *map_zone, int tile_x, int tile_y);
void func_270BA0(ActionRebind *self, int status);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_RETRY_H
