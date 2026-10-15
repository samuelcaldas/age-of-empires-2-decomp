#include <cstdio>
#include "trade_action_market_eval_planner_fixture.h"

TargetStorage target_storage[3];
TargetObj *primary_target;
TargetObj *allied_target;
TargetObj *candidate_target;
TradeAction action;
bool return_candidates;
bool route_exists;
int fail_before_success;
int search_count;
int dispatch_count;
int searched_coordinates[110];
int dispatch_arguments[5];
float dispatch_coordinate;
CandidateNode candidate;
static unsigned char world_storage[0xC68];
static unsigned char manager_storage[0x12B574];
static unsigned char definition_storage[0x20];
static void *virtual_table[111];

extern "C" {
PlannerManager *D_004E3244 = reinterpret_cast<PlannerManager *>(manager_storage);
void *func_332e60(void *, int identifier) { return identifier == -1 ? 0 : allied_target; }
int func_269FF0(void *) { return 7; }
void func_1E9130(void *) {}
int func_123350(float coordinate) { return static_cast<int>(coordinate); }
TargetObj *func_001510D0(TradeAction *, int) { return route_exists ? candidate_target : 0; }

CandidateNode *func_3283C0(void *, int x, int, int team, int,
                         int *visited, int count) {
    assert(team == 7 && search_count < 110);
    searched_coordinates[search_count++] = x;
    for (int index = 0; index < count; index++) assert(visited[index] == 1000 + index);
    candidate.m_id = 999 + search_count;
    if (!return_candidates) return 0;
    return &candidate;
}
}

static int dispatch(TargetObj *, int identifier, int second, int third,
                    int fourth, int flag, float coordinate) {
    dispatch_arguments[0] = identifier;
    dispatch_arguments[1] = second;
    dispatch_arguments[2] = third;
    dispatch_arguments[3] = fourth;
    dispatch_arguments[4] = flag;
    dispatch_coordinate = coordinate;
    dispatch_count++;
    return dispatch_count > fail_before_success;
}

static TargetObj *initialize_target(int index, float coordinate) {
    TargetObj *target = reinterpret_cast<TargetObj *>(target_storage[index].bytes);
    *reinterpret_cast<void ***>(target) = virtual_table;
    target->m_world = world_storage;
    target->m_field04 = definition_storage;
    target->m_field39 = 2;
    target->pos_x = coordinate;
    return target;
}

void reset_planner_fixture() {
    std::memset(target_storage, 0, sizeof(target_storage));
    for (int index = 0; index < 111; index++) virtual_table[index] = (void *)&dispatch;
    primary_target = initialize_target(0, 11.0f);
    allied_target = initialize_target(1, 22.0f);
    candidate_target = initialize_target(2, 33.0f);
    action.m_target = primary_target;
    candidate.m_dist = 3;
    return_candidates = route_exists = true;
}

static void target_layout_matches_original() {
    assert(offsetof(TargetObj, m_field04) == 0x04);
    assert(offsetof(TargetObj, m_world) == 0x08);
    assert(offsetof(TargetObj, m_field39) == 0x39);
    assert(offsetof(TargetObj, m_field3A) == 0x3A);
    assert(offsetof(TargetObj, pos_x) == 0x44);
    assert(offsetof(TradeAction, m_target) == 0x38);
}

static void virtual_call_preserves_arguments() {
    int distance = -1;
    assert(func_0014EE90(&action, 5, -1, -1, &distance) == 1000);
    assert(distance == 3 && dispatch_count == 1);
    assert(dispatch_arguments[0] == 1000 && dispatch_arguments[1] == 0);
    assert(dispatch_arguments[2] == -1 && dispatch_arguments[3] == -1);
    assert(dispatch_arguments[4] == 0 && dispatch_coordinate == 0.0f);
}

static void unlimited_allied_search_resets_target() {
    return_candidates = false;
    assert(func_0014EE90(&action, 5, 77, -1, 0) == -1);
    assert(search_count == 2);
    assert(searched_coordinates[0] == 22 && searched_coordinates[1] == 11);
}

static void limited_allied_search_visits_both_targets() {
    return_candidates = false;
    assert(func_0014EE90(&action, 5, 77, 2, 0) == -1);
    assert(search_count == 4);
    assert(searched_coordinates[0] == 22 && searched_coordinates[1] == 22);
    assert(searched_coordinates[2] == 11 && searched_coordinates[3] == 11);
}

static void candidate_below_limit_is_accepted() {
    primary_target->m_field3A = 99;
    candidate_target->m_field3A = 1;
    assert(func_0014EE90(&action, 5, -1, 2, 0) == 1000);
    assert(dispatch_count == 1);
}

static void candidate_at_limit_is_rejected() {
    primary_target->m_field3A = 0;
    candidate_target->m_field3A = 2;
    assert(func_0014EE90(&action, 5, -1, 2, 0) == -1);
    assert(dispatch_count == 0 && search_count == 30);
}

static void visited_history_stops_at_one_hundred() {
    route_exists = false;
    assert(func_0014EE90(&action, 5, -1, -1, 0) == -1);
    assert(search_count == 100 && dispatch_count == 0);
}

static void failed_dispatch_stops_at_thirty() {
    fail_before_success = 100;
    assert(func_0014EE90(&action, 5, -1, -1, 0) == -1);
    assert(search_count == 30 && dispatch_count == 30);
}

static void retry_flag_changes_after_failure() {
    fail_before_success = 1;
    assert(func_0014EE90(&action, 5, -1, -1, 0) == 1001);
    assert(dispatch_count == 2 && dispatch_arguments[4] == 1);
}

typedef void (*RegressionCase)();
static RegressionCase TEST_CASES[] = {
    target_layout_matches_original, virtual_call_preserves_arguments,
    unlimited_allied_search_resets_target, limited_allied_search_visits_both_targets,
    candidate_below_limit_is_accepted, candidate_at_limit_is_rejected,
    visited_history_stops_at_one_hundred, failed_dispatch_stops_at_thirty,
    retry_flag_changes_after_failure,
};

int main(int argument_count, char **arguments) {
    assert(argument_count == 2);
    unsigned int index = static_cast<unsigned char>(arguments[1][0]) - '0';
    assert(index < sizeof(TEST_CASES) / sizeof(TEST_CASES[0]));
    reset_planner_fixture();
    TEST_CASES[index]();
    std::puts("planner regression passed");
    return 0;
}
