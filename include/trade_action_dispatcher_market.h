#ifndef TRADE_ACTION_DISPATCHER_MARKET_H
#define TRADE_ACTION_DISPATCHER_MARKET_H

#include "trade_action_dispatcher_access.h"

extern "C" {
int func_00332da0(void *manager);
int func_00147170(void *entity);
int func_00202b10(void *entity);
void func_002bea40(void *object, int value);
void func_0013fdf0(void *diplomacy, int team, int zero);
void func_0013fc80(void *diplomacy, int team, int zero, int amount);
void func_00140360(void *diplomacy, int team, int amount);
void func_0013fb50(void *diplomacy, int team, int mode, int value);
void *func_00332e60(void *manager, int id);
int func_00123350(float value);
int func_002ac300(void *candidate, int mode);
void func_002ac370(void *candidate, void *self, void *manager, int mode, int zero);
void *func_00144d20(void *manager, int first, int mode, int third, int fourth, int fifth, int sixth, int seventh, int eighth, int ninth, int tenth);
float func_002690d0(void *candidate, void *item);
extern float D_004E2808;
}

namespace trade_action_dispatcher {

inline bool has_id(void *self, int data_offset, int count_offset, int capacity_offset, int id) {
    char *object = bytes(self);
    int count = integer_at(self, count_offset);
    int capacity = integer_at(self, capacity_offset);
    int limit = count < capacity ? count : capacity;
    int *ids = *reinterpret_cast<int **>(object + data_offset);
    for (int index = 0; index < limit; ++index) {
        if (ids[index] == id) {
            return true;
        }
    }
    return false;
}

inline void apply_diplomacy_adjustment(void *self, void *manager_object) {
    void *group = manager_group(manager_object);
    int relation = func_00332da0(pointer_at(group, 2968));
    if (relation == 3) {
        store_integer(self, 2552, integer_at(self, 2552) - 2);
        return;
    }
    if (relation == 4) {
        store_integer(self, 2552, integer_at(self, 2552) - 1);
        return;
    }
    func_002bea40(bytes(manager_object) + 0x1e374, 3);
}

inline bool has_diplomacy_exception(void *self, void *item, int item_id) {
    bool in_first_list = has_id(self, 180, 184, 192, item_id);
    bool in_second_list = has_id(self, 196, 200, 208, item_id);
    if (in_first_list && !in_second_list) {
        return false;
    }
    void **vtable = *reinterpret_cast<void ***>(item);
    typedef void *(*Predicate)(void *);
    Predicate predicate = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!predicate(item)) {
        return true;
    }
    void *predicate_result = predicate(item);
    return func_00147170(pointer_at(predicate_result, 0)) == 705;
}

inline void issue_diplomacy_notification(void *diplomacy, int team) {
    func_0013fdf0(diplomacy, team, 1);
    func_0013fc80(diplomacy, team, 0, 100);
    func_00140360(diplomacy, team, 3);
    func_0013fdf0(diplomacy, team, 0);
}

inline void issue_fallback_notification(void *diplomacy, int team, int limit) {
    func_0013fb50(diplomacy, team, 2, limit);
    func_0013fb50(diplomacy, team, 0, limit);
}

inline int invoke_diplomacy_team_action(void *manager_object, int team) {
    void *group = manager_group(manager_object);
    void *dispatcher = pointer_at(group, 6960);
    void **vtable = *reinterpret_cast<void ***>(dispatcher);
    typedef int (*TeamAction)(void *, int);
    TeamAction team_action = reinterpret_cast<TeamAction>(*reinterpret_cast<void **>(bytes(vtable) + 36));
    return team_action(dispatcher, team);
}

inline int invoke_team_record_action(void *manager_object, int team) {
    void *group = manager_group(manager_object);
    void *manager_data = pointer_at(group, 2968);
    void *team_records = pointer_at(manager_data, 84);
    void *record = *reinterpret_cast<void **>(bytes(team_records) + team * 4);
    void **vtable = *reinterpret_cast<void ***>(record);
    typedef int (*TeamAction)(void *, int);
    TeamAction team_action = reinterpret_cast<TeamAction>(*reinterpret_cast<void **>(bytes(vtable) + 32));
    return team_action(record, team);
}

inline void process_team_action_notification(void *self, void *manager_object, int team) {
    int action = invoke_diplomacy_team_action(manager_object, team);
    if (action == 1) {
        int total = integer_at(self, 3020);
        int count = integer_at(self, 3748 + team * 4);
        if (count >= total && integer_at(self, 2996) == 1) {
            void *diplomacy = bytes(manager_object) + 13212;
            issue_diplomacy_notification(diplomacy, team);
            return;
        }
    }
    issue_fallback_notification(bytes(manager_object) + 13212, team, integer_at(self, 2848));
}

inline void process_team_record_notification(void *self, void *manager_object, int team) {
    if (invoke_diplomacy_team_action(manager_object, team) != 1) {
        return;
    }
    if (invoke_team_record_action(manager_object, team) == 1) {
        issue_diplomacy_notification(bytes(manager_object) + 13212, team);
    }
    (void)self;
}

inline void process_trade_notifications(void *self, void *manager_object, void *item, int item_team) {
    int handled = func_00202b10(pointer_at(item, 8));
    if (item_team && !handled) {
        process_team_action_notification(self, manager_object, item_team);
        return;
    }
    process_team_record_notification(self, manager_object, item_team);
}

inline bool assign_preferred_candidate(void *self, void *manager_object, void *candidate, void *target, int target_id) {
    int candidate_id = func_002ac300(candidate, 0);
    void *candidate_record = func_00332e60(pointer_at(manager_group(manager_object), 2968), candidate_id);
    if (!candidate_record) {
        return false;
    }
    int coordinates[3];
    coordinates[0] = func_00123350(float_at(target, 68));
    coordinates[1] = func_00123350(float_at(target, 72));
    coordinates[2] = func_00123350(float_at(target, 76));
    void **vtable = *reinterpret_cast<void ***>(candidate_record);
    typedef float (*CandidateScale)(void *);
    CandidateScale scale = reinterpret_cast<CandidateScale>(*reinterpret_cast<void **>(bytes(vtable) + 292));
    float scale_value = scale(candidate_record);
    vtable = *reinterpret_cast<void ***>(candidate_record);
    typedef int (*CandidateCheck)(void *, int *, short, float, int, int, int, int);
    CandidateCheck check = reinterpret_cast<CandidateCheck>(*reinterpret_cast<void **>(bytes(vtable) + 436));
    int result = check(candidate_record, coordinates, short_at(target, 36), scale_value, 0, -1, -1, 0);
    if (result != 1) {
        return false;
    }
    store_integer(candidate, 232, target_id);
    store_integer(candidate, 236, short_at(pointer_at(target, 4), 8));
    store_integer(candidate, 228, 2);
    *reinterpret_cast<float *>(bytes(candidate) + 520) = float_at(target, 68);
    *reinterpret_cast<float *>(bytes(candidate) + 524) = float_at(target, 72);
    *reinterpret_cast<float *>(bytes(candidate) + 528) = float_at(target, 76);
    func_002ac370(candidate, self, manager_object, 2, 0);
    (void)scale_value;
    return true;
}

inline void *create_fallback_candidate(void *manager_object) {
    return func_00144d20(manager_object, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
}

inline bool can_assign_candidate(void *self, short item_id) {
    return !has_id(self, 3816, 3820, 3828, item_id);
}

}

#endif
