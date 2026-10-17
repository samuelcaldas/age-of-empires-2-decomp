#ifndef UNIT_ACTION_BUILD_FORMATION_H
#define UNIT_ACTION_BUILD_FORMATION_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates formation item and attaches it to building action item list.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param a1 Formation slot / type identifier.
 * @param a2 Secondary formation parameter.
 * @return 1 on successful formation creation and insertion, 0 otherwise.
 */
int func_0026FC20(ActionRebind *self, int a1, int a2);

void* func_366D70(void *param);
void* func_00366D70(void *param);
void func_363410(void *item, void *self, short a1, int a2);
void func_00363410(void *item, void *self, short a1, int a2);
void Free__8BaseListFv(void *list);
void AddHead__8BaseListFPv(void *list, void *item);

extern void *D_4E35DC;

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_FORMATION_H
