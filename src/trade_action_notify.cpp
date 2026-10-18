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

typedef void *(*PredFn)(void *);

static inline int *get_item_pred(void *item) {
    PredFn fn = *reinterpret_cast<PredFn *>(*reinterpret_cast<char **>(item) + 356);
    return reinterpret_cast<int *>(fn(item));
}

typedef void (*NotifyOrderFn)(void *world, void *ba0, int item_id, int code,
                              int t0, int t1, int t2, int t3,
                              int action_type,
                              float f12, float f13, float f14, float f15);

} // namespace trade_action_candidates

extern "C" {
int func_002B9770(void *self, int item_id, int action_type) {
    void *mgr = *reinterpret_cast<void **>(bytes(self) + 176);
    void *world = *reinterpret_cast<void **>(bytes(mgr) + 172);
    void *ba0 = *reinterpret_cast<void **>(bytes(world) + 2976);
    void *vt = *reinterpret_cast<void **>(bytes(world) + 6960);
    NotifyOrderFn fn = *reinterpret_cast<NotifyOrderFn *>(bytes(vt) + 56);
    fn(world, ba0, item_id, 706,
       -1, -1, 1, 0,
       action_type,
       -1.0f, -1.0f, -1.0f, -1.0f);
    return 1;
}

int func_002B97D0(void *self, int item_id, int action_type, float param) {
    void *mgr = *reinterpret_cast<void **>(bytes(self) + 176);
    void *world = *reinterpret_cast<void **>(bytes(mgr) + 172);
    void *ba0 = *reinterpret_cast<void **>(bytes(world) + 2976);
    void *vt = *reinterpret_cast<void **>(bytes(world) + 6960);
    NotifyOrderFn fn = *reinterpret_cast<NotifyOrderFn *>(bytes(vt) + 56);
    fn(world, ba0, item_id, 710,
       -1, -1, 1, 0,
       action_type,
       -1.0f, -1.0f, 1.0f, param);
    return 1;
}

int func_002B9830(void *self, int a1, int a2, int a3) {
    void *mgr = *reinterpret_cast<void **>(bytes(self) + 176);
    void *world = *reinterpret_cast<void **>(bytes(mgr) + 172);
    void *ba0 = *reinterpret_cast<void **>(bytes(world) + 2976);
    void *vt = *reinterpret_cast<void **>(bytes(world) + 6960);
    NotifyOrderFn fn = *reinterpret_cast<NotifyOrderFn *>(bytes(vt) + 56);
    fn(world, ba0, a1, 724,
       a2, -1, 1, 0,
       a3,
       -1.0f, -1.0f, -1.0f, -1.0f);
    return 1;
}

int func_002B9880(void *self, int item_id, int action_type) {
    int found = 0;
    for (int i = 0; i < integer_at(self, 3188) && i < integer_at(self, 3196); i++) {
        if (item_id == (*reinterpret_cast<int **>(bytes(self) + 3184))[i]) {
            found = 1;
            break;
        }
    }
    if (found) {
        return 0;
    }

    void *mgr = *reinterpret_cast<void **>(bytes(self) + 176);
    void *group = *reinterpret_cast<void **>(bytes(mgr) + 172);
    void *root = *reinterpret_cast<void **>(bytes(group) + 2968);

    void *item = func_00332e60(root, item_id);
    if (!item) {
        return 0;
    }

    if (!get_item_pred(item)) {
        return 0;
    }

    if (func_001471a0(*get_item_pred(item)) == 600 || func_001471a0(*get_item_pred(item)) == 613) {
        return 1;
    }
    if (func_001471a0(*get_item_pred(item)) == 602 || func_001471a0(*get_item_pred(item)) == 618) {
        return 1;
    }
    if (func_001471a0(*get_item_pred(item)) == 605) {
        return 1;
    }

    if (!(*reinterpret_cast<float *>(bytes(item) + 64) <= 0.0f)) {
        return 0;
    }

    if (func_00147170(*get_item_pred(item)) == 710) {
        if (func_00147190(*get_item_pred(item)) == 100) {
            return 0;
        }
    } else if (func_00147170(*get_item_pred(item)) == 702) {
        return 0;
    }

    if (func_0014c430(*get_item_pred(item), 705) != 1) {
        int res = func_002bb100(self, item_id, action_type);
        return res != 0 ? 1 : 0;
    }

    return 0;
}
}
