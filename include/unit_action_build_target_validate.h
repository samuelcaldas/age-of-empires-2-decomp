#ifndef UNIT_ACTION_BUILD_TARGET_VALIDATE_H
#define UNIT_ACTION_BUILD_TARGET_VALIDATE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Validates and updates build target state and worker list detachment.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_00270EF0(ActionRebind *self);
void func_270EF0(ActionRebind *self);

void func_1950d0();
void* GetHeadItem__8BaseListFv(void *list);
void CallMethod13__8BaseListFv(void *self);
void Free__8BaseListFv(void *list);
void func_00270530(ActionRebind *self);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_TARGET_VALIDATE_H
