#ifndef UNIT_ACTION_BUILD_CHILD_UPDATE_H
#define UNIT_ACTION_BUILD_CHILD_UPDATE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Updates child unit position, navigation targets, and formation state.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param child Pointer to the child action instance.
 * @param x Target coordinate X (or -1.0f sentinel).
 * @param y Target coordinate Y (or -1.0f sentinel).
 * @return 1 on success, 0 on failure or early exit.
 */
int func_0026F590(ActionRebind *self, ActionRebind *child, float x, float y);
int func_26F590(ActionRebind *self, ActionRebind *child, float x, float y);

int func_271B40(void *self, void *child_field4, float *out_x, float *out_y);
int func_00271B40(void *self, void *child_field4, float *out_x, float *out_y);
void func_0026F8A0(ActionRebind *self);
void func_2697B0(void *child, float x, float y, float z);
void func_002697B0(void *child, float x, float y, float z);
void* func_332E60(void *fieldB98);
void* func_00332E60(void *fieldB98);
void func_14BCE0(void *obj);
void func_0014BCE0(void *obj);
void func_14C7F0(void *obj, unsigned char param);
void func_0014C7F0(void *obj, unsigned char param);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_CHILD_UPDATE_H
