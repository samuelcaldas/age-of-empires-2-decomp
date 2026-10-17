#ifndef TRADE_ACTION_DISPATCHER_FALLBACK_H
#define TRADE_ACTION_DISPATCHER_FALLBACK_H

#include "trade_action_dispatcher_access.h"
#include "trade_action_dispatcher_market.h"

extern "C" {
int func_002b7bb0(void *self, int radius, int target, int mode);
int func_002b76b0(void *self, int radius, int target, int mode, int include);
void func_002c22e0(void *self, void *item, void *target);
void func_002bf1e0(void *self, int team, int x, int y);
void func_0029dd20(void *target_list, int zero, int x, int y, int team, int manager_team, int zero_a, int zero_b, int route_flags, int unknown);
int func_00297b50(void *target_list, void *entity);
int func_002261c0();
int func_001233e0(float value);
int func_001471a0(void *entity);
int func_00147170(void *entity);
int func_00147190(void *entity);
int func_001471c0(void *entity);
int func_001fe830(void *candidate, void *target, float scale, int *candidate_position, int *target_position, int zero_a, int unknown_a, int zero_b, int zero_c, int zero_d, int zero_e);
void func_002bb730(void *self, int candidate_id, int target_id, int team, float x, float y, int zero_a, int zero_b, int unknown, int zero_c, int limit);
}

namespace trade_action_dispatcher {

inline bool is_quota_exempt_type(void *item) {
    short type = short_at(pointer_at(item, 4), 14);
    return type == 27 || type == 39 || type == 3;
}

inline int preferred_budget(void *self, void *manager_object, void *item, void *target, void *candidate) {
    int budget = func_002b7bb0(self, 100, -1, 1);
    budget += func_002b76b0(self, 100, -1, 0, 1);
    func_002c22e0(self, item, target);
    void *coordinate_source = candidate ? candidate : item;
    int x = func_00123350(float_at(coordinate_source, 68));
    int y = func_00123350(float_at(coordinate_source, 72));
    func_002bf1e0(self, entity_team(target), x, y);
    (void)manager_object;
    return budget;
}

inline int general_budget(void *self, void *manager_object, void *target) {
    void *target_list = bytes(manager_object) + 13860;
    int mode = func_00297b50(target_list, target);
    int radius = integer_at(self, 2216);
    int budget = func_002b7bb0(self, radius, -1, 1);
    if (mode == 1) {
        return budget;
    }
    budget += func_002b76b0(self, radius, -1, 0, 1);
    return budget * integer_at(self, 2212) / 100;
}

inline int update_quota_state(void *self, void *candidate, void *item) {
    bool was_over_quota = integer_at(self, 3832) != 0;
    float score = D_004E2808;
    if (candidate) {
        score = func_002690d0(candidate, item);
    }
    bool over_quota = score < static_cast<float>(integer_at(self, 2432) + 4);
    store_integer(self, 3832, over_quota ? 1 : 0);
    if (was_over_quota && !over_quota) {
        return -1;
    }
    if (over_quota || is_quota_exempt_type(item)) {
        return 1;
    }
    return 0;
}

inline bool candidate_is_current(void *self, void *manager_object, void *candidate, void *target, void *item) {
    void **candidate_vtable = *reinterpret_cast<void ***>(candidate);
    typedef void *(*CurrentTarget)(void *);
    CurrentTarget current_target = reinterpret_cast<CurrentTarget>(*reinterpret_cast<void **>(bytes(candidate_vtable) + 356));
    if (!current_target(candidate)) {
        return false;
    }
    void *current = current_target(candidate);
    void **current_vtable = *reinterpret_cast<void ***>(current);
    typedef int (*TargetFilter)(void *, void *);
    TargetFilter filter = reinterpret_cast<TargetFilter>(*reinterpret_cast<void **>(bytes(current_vtable) + 12));
    if (!filter(current, target)) {
        return false;
    }
    void *identifier_source = current_target(candidate);
    int entity_id = func_001471c0(pointer_at(identifier_source, 0));
    void *record = func_00332e60(pointer_at(manager_group(manager_object), 2968), entity_id);
    void *classification_source = current_target(candidate);
    int classification = func_001471a0(pointer_at(classification_source, 0));
    if (classification == 600 && record && short_at(pointer_at(record, 4), 14) != 27) {
        void *classification_value = current_target(candidate);
        if (func_00147190(pointer_at(classification_value, 0)) >= 100) {
            return false;
        }
    }
    void *route_source = current_target(candidate);
    int route_id = func_00147170(pointer_at(route_source, 0));
    if (route_id != -1) {
        void *route_value = current_target(candidate);
        if (func_00147170(pointer_at(route_value, 0)) != 700) {
            return false;
        }
        void *route_limit = current_target(candidate);
        if (func_00147190(pointer_at(route_limit, 0)) >= 100) {
            return false;
        }
    }
    float score = func_002690d0(item, candidate);
    int score_value = func_00123350(score);
    if (integer_at(self, 2216) < score_value && !integer_at(self, 3832)) {
        return false;
    }
    if (short_at(pointer_at(candidate, 4), 14) == 18) {
        if (!current_target(candidate)) {
            return false;
        }
        current = current_target(candidate);
        current_vtable = *reinterpret_cast<void ***>(current);
        typedef int (*ObjectFilter)(void *, short, int);
        ObjectFilter object_filter = reinterpret_cast<ObjectFilter>(*reinterpret_cast<void **>(bytes(current_vtable) + 340));
        if (!object_filter(current, short_at(target, 36), 0)) {
            return false;
        }
    }
    return true;
}

inline void issue_route_notification(void *manager_object, void *manager_data, void *group, void *item, void *target) {
    int target_team = entity_team(target);
    if (!target_team) {
        return;
    }
    int x = func_001233e0(float_at(item, 68));
    int y = func_001233e0(float_at(item, 72));
    func_0029dd20(bytes(manager_object) + 13860, 0, x, y, target_team,
                  *reinterpret_cast<unsigned char *>(bytes(group) + 2976), 0, 0,
                  integer_at(manager_data, 24), -1);
}

inline bool timed_out(int start_time, void *manager_object) {
    void *manager_root = pointer_at(manager_object, 0x1f348);
    void *manager_pointer = pointer_at(manager_root, 2968);
    float limit = 80.0f * float_at(manager_pointer, 44);
    int allowed_duration = func_001233e0(limit);
    return func_002261c0() - start_time > allowed_duration;
}

inline bool process_candidate(void *self, void *manager_object, void *item, void *target, void *candidate) {
    if (!candidate_is_current(self, manager_object, candidate, target, item)) {
        return false;
    }
    void **vtable = *reinterpret_cast<void ***>(candidate);
    typedef void (*Position)(void *, void *);
    Position position = reinterpret_cast<Position>(*reinterpret_cast<void **>(bytes(vtable) + 544));
    int candidate_position[4];
    int target_position[4];
    position(candidate_position, candidate);
    vtable = *reinterpret_cast<void ***>(target);
    position = reinterpret_cast<Position>(*reinterpret_cast<void **>(bytes(vtable) + 544));
    position(target_position, target);
    vtable = *reinterpret_cast<void ***>(candidate);
    typedef float (*CandidateScale)(void *);
    CandidateScale scale = reinterpret_cast<CandidateScale>(*reinterpret_cast<void **>(bytes(vtable) + 292));
    if (!func_001fe830(candidate, target, scale(candidate), candidate_position, target_position,
                       0, -1, 0, 0, 0, 0)) {
        return false;
    }
    func_002bb730(self, short_at(candidate, 36), short_at(target, 36), entity_team(target),
                  float_at(target, 68), float_at(target, 72), 0, 0, -1, 0, 100);
    (void)manager_object;
    return true;
}

inline void run_timed_candidate_loop(void *self, void *manager_object, void *item, void *target,
                                     int start_time, int quota) {
    int iteration_count = integer_at(self, 3172);
    int *candidate_ids = *reinterpret_cast<int **>(bytes(self) + 3168);
    int list_length = integer_at(self, 3180);
    int successes = 0;
    for (int index = 0; index < iteration_count && successes < quota; ++index) {
        if (index >= 2 && timed_out(start_time, manager_object)) {
            return;
        }
        int lookup_index = index < list_length - 1 ? index : 0;
        void *candidate = func_00332e60(pointer_at(manager_group(manager_object), 2968), candidate_ids[lookup_index]);
        if (candidate && process_candidate(self, manager_object, item, target, candidate)) {
            ++successes;
        }
    }
}

}

#endif
