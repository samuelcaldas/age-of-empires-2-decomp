#ifndef UNIT_ACTION_BUILD_TILE_PATH_H
#define UNIT_ACTION_BUILD_TILE_PATH_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Scans surrounding tiles for overlapping construction targets (class 80) and notifies them.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_00271220(ActionRebind *self);
void func_271220(ActionRebind *self);

int func_123350(float val);
char func_26AD20(void *unit, int flag);
void func_0026E750(void *unit);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_TILE_PATH_H
