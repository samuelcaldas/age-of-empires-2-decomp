#ifndef UNIT_ACTION_BUILD_NOTIFY_WORKERS_H
#define UNIT_ACTION_BUILD_NOTIFY_WORKERS_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Updates worker notifications, resource costs, task items, and subaction execution.
 *
 * @param self Pointer to the ActionRebind instance.
 */
void func_00270660(ActionRebind *self);
void func_270660(ActionRebind *self);

int func_202B10();
int func_00202B10();
float func_2E6C60(void *world, int task_id);
void func_00270530(ActionRebind *self);
void func_00270450(ActionRebind *self);
void* func_366D10(void *param);
void func_35D7C0(void *item, void *self, short task_id, int mode, int opt);
void AddHead__8BaseListFPv(void *list, void *item);
void DeleteHead__8BaseListFv(void *list);

extern void *D_004E3180;
extern void *D_4E35DC;

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_NOTIFY_WORKERS_H
