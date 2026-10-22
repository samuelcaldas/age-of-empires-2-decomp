#ifndef UNIT_ACTION_BUILD_CHECK_TARGET_STATUS_H
#define UNIT_ACTION_BUILD_CHECK_TARGET_STATUS_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Validates target capability 39, attribute 1A2, flag 2000, and player targeting acceptance.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param target_player_id Target player index.
 * @return 1 if target player is valid and mutually acceptable, 0 otherwise.
 */
int func_00271500(ActionRebind *self, int target_player_id);
int func_271500(ActionRebind *self, int target_player_id);

char func_26AD20(void *action, int flag);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_CHECK_TARGET_STATUS_H
