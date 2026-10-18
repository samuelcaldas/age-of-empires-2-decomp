#ifndef TRADE_ACTION_NOTIFY_SUPPORT_H
#define TRADE_ACTION_NOTIFY_SUPPORT_H

#include "trade_action_notify.h"

extern int g_bb100_calls;
extern int g_bb100_return_val;
extern int g_entity_lookup_calls;
extern int g_entity_lookup_id;
extern void *g_mock_entity;

void reset_notify_support();

#endif
