#ifndef TRADE_ACTION_DISPATCHER_TEST_SUPPORT_H
#define TRADE_ACTION_DISPATCHER_TEST_SUPPORT_H

#include "trade_action_dispatcher.h"

static_assert(sizeof(void *) == 4, "dispatcher fixtures require 32-bit pointers");

extern int g_2261c0_calls;
extern int g_2a03c0_calls;
extern int g_2a03c0_last_flag;
extern int g_2a03f0_calls;
extern int g_2a03f0_last_flag;
extern int g_297390_calls;
extern int g_2c29e0_calls;
extern int g_2c29e0_last_target_idx;
extern int g_1471c0_calls;
extern int g_2d1a40_calls;
extern int g_2be490_calls;
extern int g_2bfe30_calls;
extern int g_2b9770_calls;
extern int g_2a0420_calls;
extern int g_2b9770_last_id;
extern int g_2b9770_last_value;
extern int g_2bfe30_last_id1;
extern int g_2bfe30_last_id2;
extern int g_2a0420_last_id1;
extern int g_2a0420_last_id2;
extern int g_144d20_calls;
extern int g_2ac300_calls;
extern int g_2ac370_calls;
extern int g_2be250_calls;
extern int g_2be250_last_mode;
extern void *g_mock_zero_id_entity;

extern "C" {
extern void *D_004E3180;
}
extern void *g_mock_last_lookup_entity;
extern int g_mock_last_lookup_id;
extern void *g_mock_entity;
extern void *g_mock_target_ent;
extern void *g_mock_found_ent;
extern int g_mock_mode_flag;

void reset_dispatcher_test_support();

#endif // TRADE_ACTION_DISPATCHER_TEST_SUPPORT_H
