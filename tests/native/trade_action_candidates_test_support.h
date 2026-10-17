#ifndef TRADE_ACTION_CANDIDATES_TEST_SUPPORT_H
#define TRADE_ACTION_CANDIDATES_TEST_SUPPORT_H

#include "trade_action_candidates.h"

static_assert(sizeof(void *) == 4, "candidates fixtures require 32-bit pointers");

extern int g_1471a0_calls;
extern int g_1471a0_return_val;
extern int g_1471c0_calls;
extern int g_1471c0_return_val;
extern int g_147190_calls;
extern int g_147190_return_val;
extern int g_332e60_calls;
extern int g_2bf050_calls;
extern int g_2bf050_return_val;
extern int g_2bfcd0_calls;
extern int g_2bfcd0_return_val;

void reset_candidates_test_support();

#endif // TRADE_ACTION_CANDIDATES_TEST_SUPPORT_H
