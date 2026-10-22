#ifndef UNIT_ACTION_BUILD_FLAG_2000_GET_H
#define UNIT_ACTION_BUILD_FLAG_2000_GET_H

#include "unit_action_rebind.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Tail-call query returning action flag 0x2000 status.
 *
 * @param self Pointer to the ActionRebind instance.
 * @return Flag 0x2000 evaluation result.
 */
char func_002715E0(ActionRebind *self);
char func_2715E0(ActionRebind *self);

char func_26AD20(void *action, int flag);

#ifdef __cplusplus
}
#endif

#endif // UNIT_ACTION_BUILD_FLAG_2000_GET_H
