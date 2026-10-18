#pragma exceptions off
#include "trade_action_notify.h"

extern "C" {
int func_00332e60(void *manager, int id);
int func_001471a0(int entity_id);
int func_00147170(int entity_id);
int func_00147190(int entity_id);
int func_0014c430(int entity_id, int code);
int func_002bb100(void *self, int action_type, int item_id);
}

using namespace trade_action_candidates;

static bool check_pool_membership(void *self, int target_id) {
    int count = integer_at(self, 3188);
    int capacity = integer_at(self, 3196);
    int *pool = *reinterpret_cast<int **>(bytes(self) + 3184);
    for (int i = 0; i < count && i < capacity; ++i) {
        if (target_id == pool[i]) {
            return true;
        }
    }
    return false;
}

static bool check_item_qualifications(void *item) {
    typedef int (*Predicate)(void *);
    void **vtable = *reinterpret_cast<void ***>(item);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
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

int func_002B9880(void *self, int item_id, int action_type) {
    if (check_pool_membership(self, item_id)) {
        return 0;
    }

    void *item = func_00332e60(manager_entity_root(self), item_id);
    if (!item) {
        return 0;
    }

    typedef int (*Predicate)(void *);
    void **vtable = *reinterpret_cast<void ***>(item);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!pred(item)) {
        return 0;
    }

    if (!check_item_qualifications(item)) {
        return 0;
    }

    int res = func_002bb100(self, item_id, action_type);
    return res != 0 ? 1 : 0;
}
