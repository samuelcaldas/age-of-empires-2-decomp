#ifndef TRADE_ACTION_NOTIFY_SUPPORT_H
#define TRADE_ACTION_NOTIFY_SUPPORT_H

#include "trade_action_notify.h"

extern int g_bb100_calls;
extern int g_bb100_return_val;
extern int g_entity_lookup_calls;
extern int g_entity_lookup_id;
extern int g_1471a0_return_val;
extern int g_1471c0_return_val;
extern int g_147170_return_val;
extern int g_147190_return_val;
extern int g_14c430_return_val;
extern void *g_mock_entity;

extern int g_order_dispatch_calls;
extern int g_order_dispatch_last_code;
extern int g_order_dispatch_last_item;
extern int g_order_dispatch_last_action;
extern float g_order_dispatch_last_f15;

void reset_notify_support();
void mock_notify_order_fn(void *world, void *ba0, int item_id, int code,
                          int t0, int t1, int t2, int t3,
                          int action_type,
                          float f12, float f13, float f14, float f15);

#endif
