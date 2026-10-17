#ifndef UNIT_ACTION_BUILD_PROGRESS_FRAME_H
#define UNIT_ACTION_BUILD_PROGRESS_FRAME_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculates current building construction frame index based on progress and master limits.
 *
 * @param self Pointer to the ActionRebind instance.
 * @return Frame index (zero or positive).
 */
int func_00270E70(ActionRebind *self);
int func_270E70(ActionRebind *self);

int func_123350(float val);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_PROGRESS_FRAME_H
