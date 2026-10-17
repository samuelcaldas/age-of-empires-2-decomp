#ifndef TRADE_ACTION_DISPATCHER_DIRECT_H
#define TRADE_ACTION_DISPATCHER_DIRECT_H

#include "trade_action_dispatcher_access.h"

namespace trade_action_dispatcher {

inline bool is_direct_action(int action_id) {
    return action_id == 114 || action_id == 115 || action_id == 109 ||
           action_id == 110 || action_id == 108 || action_id == 136 ||
           action_id == 104;
}

inline void dispatch_action_136(void *self, int target_id) {
    void *manager_object = manager(self);
    void *group = manager_group(manager_object);
    void *entity = func_00332e60(entity_manager(manager_object), target_id);
    if (!entity || entity_team(entity) != manager_team(group)) {
        return;
    }
    void **vtable = *reinterpret_cast<void ***>(entity);
    typedef void *(*Predicate)(void *);
    Predicate predicate = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!predicate(entity)) {
        return;
    }
    void *predicate_result = predicate(entity);
    int record_id = func_001471c0(pointer_at(predicate_result, 0));
    void *record = func_00332e60(pointer_at(group, 2968), record_id);
    if (record) {
        func_002d1a40(pointer_at(group, 112));
    }
}

inline void dispatch_entity_action(void *self, int action_id, int item_id, int target_id) {
    void *manager_object = manager(self);
    void *target_list = bytes(manager_object) + 13860;
    if (action_id == 114) {
        func_002a03c0(target_list, item_id, 1);
        return;
    }
    if (action_id == 115) {
        func_002a03c0(target_list, item_id, 0);
        return;
    }
    if (action_id == 109) {
        func_002a03f0(target_list, item_id, 1);
        return;
    }
    if (action_id == 110) {
        func_002a03f0(target_list, item_id, 0);
        return;
    }
    if (action_id == 108) {
        void *entity = func_00332e60(pointer_at(D_004E3180, 1028), target_id);
        func_00297390(target_list, entity, 0);
        return;
    }
    if (action_id == 104) {
        func_002c29e0(self, target_id);
        return;
    }
    dispatch_action_136(self, target_id);
}

}

#endif
