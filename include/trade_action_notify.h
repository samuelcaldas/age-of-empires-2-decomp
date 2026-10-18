#ifndef TRADE_ACTION_NOTIFY_H
#define TRADE_ACTION_NOTIFY_H

#include "trade_action_candidates_access.h"

extern "C" {
int func_002b9770(void *self, int action_type, short item_id);
int func_002b97d0(void *self, int action_type, short item_id, float param);
int func_002b9830(void *self, int a1, int a2, int a3);
int func_002b9880(void *self, int item_id, int action_type);
}

#endif // TRADE_ACTION_NOTIFY_H
