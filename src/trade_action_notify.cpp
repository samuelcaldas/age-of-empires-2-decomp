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

typedef void (*NotifyOrderFn)(void *world, void *ba0, int item_id, int code, int action_type,
                              float f12, float f13, float f14, float f15,
                              int t0, int t1, int t2, int t3);

static inline void dispatch_order_notification(void *self, int item_id, int code, int action_type,
                                               float f12, float f13, float f14, float f15,
                                               int t0, int t1, int t2, int t3) {
    void *mgr = *reinterpret_cast<void **>(bytes(self) + 176);
    void *world = *reinterpret_cast<void **>(bytes(mgr) + 172);
    void *ba0 = *reinterpret_cast<void **>(bytes(world) + 2976);
    void *action_mgr = *reinterpret_cast<void **>(bytes(world) + 6960);
    NotifyOrderFn fn = *reinterpret_cast<NotifyOrderFn *>(bytes(action_mgr) + 56);
    fn(world, ba0, item_id, code, action_type, f12, f13, f14, f15, t0, t1, t2, t3);
}

} // namespace trade_action_candidates

extern "C" {
int func_002B9770(void *self, short item_id, int action_type) {
    if (!self) {
        return 0;
    }
    dispatch_order_notification(self, static_cast<int>(item_id), 706, action_type,
                                -1.0f, -1.0f, -1.0f, -1.0f,
                                -1, -1, 1, 0);
    return 1;
}

int func_002B97D0(void *self, short item_id, int action_type, float param) {
    if (!self) {
        return 0;
    }
    dispatch_order_notification(self, static_cast<int>(item_id), 710, action_type,
                                -1.0f, -1.0f, 1.0f, param,
                                -1, -1, 1, 0);
    return 1;
}

int func_002B9830(void *self, int a1, int a2, int a3) {
    if (!self) {
        return 0;
    }
    dispatch_order_notification(self, a1, 724, a3,
                                -1.0f, -1.0f, -1.0f, -1.0f,
                                a2, -1, 1, 0);
    return 1;
}

int func_002B9880(void *self, int item_id, int action_type) {
    if (!self) {
        return 0;
    }

    int found = 0;
    int count = integer_at(self, 3188);
    int capacity = integer_at(self, 3196);
    int *pool = *reinterpret_cast<int **>(bytes(self) + 3184);

    if (pool && count > 0 && capacity > 0) {
        for (int i = 0; i < count && i < capacity; ++i) {
            if (item_id == pool[i]) {
                found = 1;
                break;
            }
        }
    }
    if (found) {
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

    int *pred_ptr = get_item_pred(item);
    if (!pred_ptr) {
        return 0;
    }

    int class_id = func_001471a0(*pred_ptr);
    if (class_id == 600 || class_id == 613) {
        return 1;
    }
    if (class_id == 602 || class_id == 618) {
        return 1;
    }
    if (class_id == 605) {
        return 1;
    }

    if (*reinterpret_cast<float *>(bytes(item) + 64) > 0.0f) {
        return 0;
    }

    int type_id = func_00147170(*get_item_pred(item));
    if (type_id == 710) {
        if (func_00147190(*get_item_pred(item)) == 100) {
            return 0;
        }
    } else if (type_id == 702) {
        return 0;
    }

    if (func_0014c430(*get_item_pred(item), 705) != 1) {
        int res = func_002bb100(self, item_id, action_type);
        return res != 0 ? 1 : 0;
    }

    return 0;
}
}
