#ifndef UNIT_ACTION_BUILD_RATE_H
#define UNIT_ACTION_BUILD_RATE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Updates construction rates and player statistics across subaction slots.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param a1 Unused / pass-through parameter.
 * @param a2 Unused / pass-through parameter.
 * @param player_ptr Pointer to the player object.
 * @param t0 Unused parameter.
 * @param has_subactions Flag indicating subaction presence.
 */
void func_0026EF50(ActionRebind *self, int a1, int a2, void *player_ptr, int t0, int has_subactions);

void func_195F40(void *action, void *player);
void func_00195F40(void *action, void *player);
void func_27B700(void *action, int type, float val, float fzero, int zero);
void func_0027B700(void *action, int type, float val, float fzero, int zero);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_RATE_H
