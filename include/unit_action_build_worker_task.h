#ifndef UNIT_ACTION_BUILD_WORKER_TASK_H
#define UNIT_ACTION_BUILD_WORKER_TASK_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Allocates or accumulates worker task assignments and manages task slot array.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param task_id Resource/task type identifier.
 * @param amount Number of worker units requested.
 * @return 1 on successful task addition/accumulation, 0 on failure or capacity limit.
 */
int func_0026FCC0(ActionRebind *self, int task_id, int amount);

int func_2E03F0(void *world, int task_id, float amount, int mode);
int func_002E03F0(void *world, int task_id, float amount, int mode);
float func_2E6C60(void *world, int task_id);
float func_002E6C60(void *world, int task_id);
void* func_1143F8(int count, int elem_size);
void* func_001143F8(int count, int elem_size);
void func_116F68(void *ptr);
void func_00116F68(void *ptr);

extern void *D_004E3180;

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_WORKER_TASK_H
