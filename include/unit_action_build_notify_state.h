#ifndef UNIT_ACTION_BUILD_NOTIFY_STATE_H
#define UNIT_ACTION_BUILD_NOTIFY_STATE_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Queries current active building item or primary worker task state.
 *
 * @param self Pointer to the ActionRebind instance.
 * @param out_task_id Pointer to receive the task ID.
 * @param out_flag Pointer to receive state flag.
 * @return 1 on successful retrieval, 0 if no active task exists.
 */
int func_00270900(ActionRebind *self, short *out_task_id, short *out_flag);
int func_270900(ActionRebind *self, short *out_task_id, short *out_flag);

void* GetHeadItem__8BaseListFv(void *list);
void func_347880(void *item, short *out_task_id, short *out_flag, int a3, int a4);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_NOTIFY_STATE_H
