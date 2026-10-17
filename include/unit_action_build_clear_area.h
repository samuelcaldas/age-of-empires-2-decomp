#ifndef UNIT_ACTION_BUILD_CLEAR_AREA_H
#define UNIT_ACTION_BUILD_CLEAR_AREA_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Scans spatial cells surrounding building footprint and repels/removes tree obstructions.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_00271220(ActionRebind *self);
void func_271220(ActionRebind *self);

int func_123350(float val);
int func_26ad20(void *entity, int flag);
void func_26e750(void *entity);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_CLEAR_AREA_H
