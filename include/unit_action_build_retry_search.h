#ifndef UNIT_ACTION_BUILD_RETRY_SEARCH_H
#define UNIT_ACTION_BUILD_RETRY_SEARCH_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Searches and updates tile grid status across unit bounding footprint.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param status Action retry status to apply to tiles.
 */
void func_00270BA0(ActionRebind *self, int status);
void func_270BA0(ActionRebind *self, int status);

int func_123350(float val);
void func_314DC0(int *min_x, int *min_y, int *max_x, int *max_y,
                 int min_b_x, int min_b_y, int max_b_x, int max_b_y);
void func_1CF9B0(void *zone, void *a1, void *a2, short min_x, short min_y,
                 short max_x, short max_y, int status, long long sp0, long long sp8);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_RETRY_SEARCH_H
