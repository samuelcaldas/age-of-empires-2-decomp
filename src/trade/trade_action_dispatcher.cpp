#pragma exceptions off
#include "trade_action_dispatcher_access.h"
#include "trade_action_dispatcher_market.h"
#include "trade_action_dispatcher_fallback.h"

using namespace trade_action_dispatcher;

extern "C" {
void *func_00332e60(void *manager, int id);
int func_002261c0();
void func_002a03c0(void *target, int id, int flag);
void func_002a03f0(void *target, int id, int flag);
void func_00297390(void *target, void *entity, int zero);
int func_001471c0(void *entity);
void func_002d1a40(void *entity);
void func_002c29e0(void *self, int target_idx);
void *func_002be490(void *self, short id);
void func_002bfe30(void *self, short id1, short id2);
void func_002b9770(void *self, short id, int val);
void func_002a0420(void *target, short id1, short id2);
int func_00123350(float val);
int func_00297b50(void *target, void *entity);
void *func_002be250(void *self, int mode, int val, int *coords);
int func_002ac300(void *target, int mode);
void func_002ac370(void *target, void *self, void *mgr, int mode, int zero);
void *func_00144d20(void *mgr, int a1, int mode, int a3, int t0, int t1, int t2, int t3, int stack0, int stack1, int stack2);
extern void *D_004E3180;
}

static void *get_manager_pointer(void *self) {
    void *manager_object = manager(self);
    void *root = pointer_at(manager_object, 0x1f348);
    return pointer_at(root, 2968);
}

#include "trade_action_dispatcher_direct.h"

static bool contains_target_id(void *self, short id, int data_offset, int count_offset, int capacity_offset) {
    char *object = bytes(self);
    int count = *reinterpret_cast<int *>(object + count_offset);
    int capacity = *reinterpret_cast<int *>(object + capacity_offset);
    int bound = count < capacity ? count : capacity;
    int *ids = *reinterpret_cast<int **>(object + data_offset);
    for (int index = 0; index < bound; ++index) {
        if (ids[index] == id) {
            return true;
        }
    }
    return false;
}

static void append_target_id(void *self, short id, int data_offset, int count_offset, int capacity_offset) {
    char *object = bytes(self);
    int count = *reinterpret_cast<int *>(object + count_offset);
    int capacity = *reinterpret_cast<int *>(object + capacity_offset);
    if (count < capacity - 1) {
        (*reinterpret_cast<int **>(object + data_offset))[count] = id;
        *reinterpret_cast<int *>(object + count_offset) = count + 1;
    }
}

static void update_target_buffers(void *self, short id) {
    if (contains_target_id(self, id, 3816, 3820, 3828)) {
        return;
    }
    append_target_id(self, id, 3816, 3820, 3828);
    if (!contains_target_id(self, id, 3800, 3804, 3812)) {
        append_target_id(self, id, 3800, 3804, 3812);
    }
}

static void dispatch_market_target(void *self, int target_id, void *target, void *item, int start_time) {
    char *self_bytes = bytes(self);
    void *manager_object = manager(self);
    void *group = manager_group(manager_object);
    if (entity_team(target) == manager_team(group)) {
        return;
    }
    void *target_data = pointer_at(target, 4);
    if (*reinterpret_cast<unsigned char *>(target_data) == 60) {
        return;
    }

    short item_number = short_at(item, 36);
    if (!can_assign_candidate(self, item_number)) {
        return;
    }
    update_target_buffers(self, item_number);
    void *item_record = func_002be490(self, item_number);
    if (integer_at(self, 3060) && item_record) {
        int record_kind = integer_at(item_record, 52);
        int record_state = integer_at(item_record, 228);
        if ((record_kind == 100 || record_kind == 102) && record_state != 2) {
            return;
        }
    }
    if (item_record && (integer_at(item_record, 52) == 101 || integer_at(item_record, 52) == 103)) {
        return;
    }
    short item_type = short_at(pointer_at(item, 4), 14);
    if (item_type == 4) {
        func_002bfe30(self, item_number, short_at(target, 36));
    }
    if (item_type == 21) {
        func_002b9770(self, item_number, 100);
        func_002a0420(bytes(manager_object) + 13860, item_number, short_at(target, 36));
    }
    int target_team = entity_team(target);
    if (target_team != 0 && !has_diplomacy_exception(self, item, item_number)) {
        apply_diplomacy_adjustment(self, manager_object);
    }
    ++*reinterpret_cast<int *>(self_bytes + 3748 + target_team * 4);
    process_trade_notifications(self, manager_object, item, entity_team(item));
    issue_route_notification(manager_object, pointer_at(group, 2968), group, item, target);

    int coords[2];
    coords[0] = func_00123350(float_at(target, 68));
    coords[1] = func_00123350(float_at(target, 72));
    int mode = func_00297b50(bytes(manager_object) + 13860, target);
    int search_mode = mode == 1 ? 102 : 100;
    int radius = *reinterpret_cast<int *>(self_bytes + 2216);
    void *candidate = func_002be250(self, search_mode, radius, coords);
    if (!candidate && mode != 1) {
        candidate = func_002be250(self, 102, radius, coords);
    }
    if (candidate && assign_preferred_candidate(self, manager_object, candidate, target, target_id)) {
        return;
    }
    candidate = create_fallback_candidate(manager_object);
    int quota_mode = update_quota_state(self, candidate, item);
    if (quota_mode < 0) {
        return;
    }
    int quota = quota_mode == 1
                    ? preferred_budget(self, manager_object, item, target, candidate)
                    : general_budget(self, manager_object, target);
    run_timed_candidate_loop(self, manager_object, item, target, start_time, quota);
}

void func_002B66B0(void *self, int arg1, int arg2, int action_id, int target_idx) {
    (void)arg2;
    if (!self) {
        return;
    }
    void *manager_pointer = get_manager_pointer(self);
    void *item = func_00332e60(manager_pointer, arg1);
    if (!is_direct_action(action_id) && !item) {
        return;
    }
    int start_time = func_002261c0();
    if (action_id != 513) {
        dispatch_entity_action(self, action_id, arg1, target_idx);
        return;
    }
    void *target = func_00332e60(manager_pointer, target_idx);
    item = func_00332e60(manager_pointer, arg1);
    if (!target || !item) {
        return;
    }
    dispatch_market_target(self, target_idx, target, item, start_time);
}
