#ifndef TRADE_ACTION_MARKET_EVAL_PLANNER_FIXTURE_H
#define TRADE_ACTION_MARKET_EVAL_PLANNER_FIXTURE_H

#include <cassert>
#include <cstddef>
#include <cstring>
#include "../../src/trade_action_market_eval_planner.cpp"

union TargetStorage {
    long long alignment;
    unsigned char bytes[sizeof(TargetObj)];
};

extern TargetStorage target_storage[3];
extern TargetObj *primary_target;
extern TargetObj *allied_target;
extern TargetObj *candidate_target;
extern TradeAction action;
extern bool return_candidates;
extern bool route_exists;
extern int fail_before_success;
extern int search_count;
extern int dispatch_count;
extern int searched_coordinates[110];
extern int dispatch_arguments[5];
extern float dispatch_coordinate;
extern CandidateNode candidate;

/** Reset the native fixture, installing a call-recording virtual table. */
void reset_planner_fixture();

#endif
