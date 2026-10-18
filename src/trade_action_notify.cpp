/*
 * Experimental Trade Action Notification Subsystem (NonMatching / Experimental)
 * VRAM 0x2B9770 - 0x2B9880
 */
#pragma exceptions off
#include "trade_action_notify.h"
#include "trade_action_candidates_access.h"

using namespace trade_action_candidates;

extern "C" {
void *func_00332e60(void *manager, int id);
int func_001471a0(int entity_id);
int func_00147170(int entity_id);
int func_00147190(int entity_id);
int func_0014c430(int entity_id, int code);
int func_002bb100(void *self, int item_id, int action_type);
}

namespace trade_action_candidates {

static bool check_pool_membership(void *self, int target_id) {
    if (!self) {
        return false;
    }
    int count = integer_at(self, 3188);
    int capacity = integer_at(self, 3196);
    int *pool = *reinterpret_cast<int **>(bytes(self) + 3184);
    if (!pool || count <= 0 || capacity <= 0) {
        return false;
    }
    int limit = (count < capacity) ? count : capacity;
    for (int i = 0; i < limit; ++i) {
        if (target_id == pool[i]) {
            return true;
        }
    }
    return false;
}

static bool check_item_qualifications(void *item) {
    if (!item) {
        return false;
    }
    void **vtable = *reinterpret_cast<void ***>(item);
    if (!vtable) {
        return false;
    }
    typedef int (*Predicate)(void *);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!pred) {
        return false;
    }
    int pred_id = pred(item);

    int class_id = func_001471a0(pred_id);
    if (class_id == 600 || class_id == 613 || class_id == 602 || class_id == 618 || class_id == 605) {
        return true;
    }

    if (*reinterpret_cast<float *>(bytes(item) + 64) <= 0.0f) {
        return false;
    }

    if (func_00147170(pred_id) == 710) {
        return func_00147190(pred_id) == 100;
    }

    if (func_00147170(pred_id) != 702) {
        return func_0014c430(pred_id, 705) != 1;
    }
    return false;
}

} // namespace trade_action_candidates

extern "C" {
int func_002B9770(void *self, short item_id, int action_type) {
    if (!self) {
        return 0;
    }
    return func_002B9880(self, static_cast<int>(item_id), action_type);
}

int func_002B97D0(void *self, short item_id, int action_type, float param) {
    if (!self) {
        return 0;
    }
    store_float(self, 3224, param);
    return func_002B9880(self, static_cast<int>(item_id), action_type);
}

int func_002B9830(void *self, int a1, int a2, int a3) {
    if (!self) {
        return 0;
    }
    int count = integer_at(self, 3172);
    int capacity = integer_at(self, 3180);
    int *candidate_ids = *reinterpret_cast<int **>(bytes(self) + 3168);
    int handled = 0;
    if (!candidate_ids || count <= 0 || capacity <= 0) {
        return 0;
    }
    int limit = (count < capacity) ? count : capacity;
    for (int i = 0; i < limit; ++i) {
        int item_id = candidate_ids[i];
        if (func_002B9880(self, item_id, a1) == 1) {
            handled++;
        }
    }
    return handled;
}

int func_002B9880(void *self, int item_id, int action_type) {
    if (!self) {
        return 0;
    }
    if (check_pool_membership(self, item_id)) {
        return 0;
    }

    void *mgr_root = manager_entity_root(self);
    if (!mgr_root) {
        return 0;
    }

    void *item = func_00332e60(mgr_root, item_id);
    if (!item) {
        return 0;
    }

    void **vtable = *reinterpret_cast<void ***>(item);
    if (!vtable) {
        return 0;
    }

    typedef int (*Predicate)(void *);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!pred || !pred(item)) {
        return 0;
    }

    if (!check_item_qualifications(item)) {
        return 0;
    }

    int res = func_002bb100(self, item_id, action_type);
    return res != 0 ? 1 : 0;
}
}
