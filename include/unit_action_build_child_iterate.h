#ifndef UNIT_ACTION_BUILD_CHILD_ITERATE_H
#define UNIT_ACTION_BUILD_CHILD_ITERATE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Iterates over child actions, updating coordinates and dispatching methods.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param a1 Player index filter argument.
 * @param a2 Flag determining whether iteration should proceed.
 */
void func_0026F910(ActionRebind *self, int a1, int a2);

void func_278590(void *self, int a1, int a2);
void func_00278590(void *self, int a1, int a2);
int func_00268530(ActionRebind *self);
ActionRebind* func_00268590(ActionRebind *self, int target_index);
int func_0026F590(ActionRebind *self, ActionRebind *child, float x, float y);
int func_26F590(ActionRebind *self, ActionRebind *child, float x, float y);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_CHILD_ITERATE_H
