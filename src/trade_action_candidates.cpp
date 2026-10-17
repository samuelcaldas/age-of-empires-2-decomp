#pragma exceptions off
#include "trade_action_candidates_access.h"
#include "trade_action_candidates_dual.h"
#include "trade_action_candidates_selector.h"

using namespace trade_action_candidates;

extern "C" {
void *func_00332e60(void *manager, int id);
int func_001471a0(int entity_id);
int func_001471c0(int entity_id);
int func_00147190(int entity_id);
}

static int get_item_id(void *self, int index) {
    int capacity = integer_at(self, 224);
    int access_index = (index < capacity - 1) ? index : 0;
    int *item_ids = *reinterpret_cast<int **>(bytes(self) + 212);
    return item_ids[access_index];
}

static bool is_excluded(void *self, int item_id) {
    int count = integer_at(self, 3188);
    int capacity = integer_at(self, 3196);
    int *excluded_ids = *reinterpret_cast<int **>(bytes(self) + 3184);
    for (int i = 0; i < count && i < capacity; ++i) {
        if (item_id == excluded_ids[i]) {
            return true;
        }
    }
    return false;
}

static bool check_classification_predicate(void *self, void *item, int flag_t0) {
    typedef int (*Predicate)(void *);
    void **vtable = *reinterpret_cast<void ***>(item);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    int pred_id = pred(item);

    if (func_001471a0(pred_id) == -1) {
        return true;
    }
    if (flag_t0 == 0) {
        return false;
    }
    if (func_001471a0(pred_id) != 600) {
        return false;
    }

    int linked_id = func_001471c0(pred_id);
    void *linked_entity = func_00332e60(manager_group_root(self), linked_id);
    if (!linked_entity) {
        return true;
    }
    void *field4 = pointer_at(linked_entity, 4);
    return short_at(field4, 14) == 27;
}

static bool matches_target_score(void *item, int threshold, int mode) {
    typedef int (*Predicate)(void *);
    void **vtable = *reinterpret_cast<void ***>(item);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    int score = func_00147190(pred(item));

    if (mode < 0) {
        return score < threshold;
    }
    if (mode > 0) {
        return score > threshold;
    }
    return score == threshold;
}

static void append_candidate_id(void *self, int item_id) {
    int count = integer_at(self, 3172);
    int capacity = integer_at(self, 3180);
    int *candidate_ids = *reinterpret_cast<int **>(bytes(self) + 3168);
    for (int i = 0; i < count && i < capacity; ++i) {
        if (item_id == candidate_ids[i]) {
            return;
        }
    }
    if (count < capacity - 1) {
        candidate_ids[count] = item_id;
        store_integer(self, 3172, count + 1);
    }
}

static void evaluate_candidate(void *self, int index, int threshold, int mode, int flag_t0, int &matched_count) {
    int item_id = get_item_id(self, index);
    void *item = func_00332e60(manager_entity_root(self), item_id);
    if (!item) {
        return;
    }

    typedef int (*Predicate)(void *);
    void **vtable = *reinterpret_cast<void ***>(item);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!pred(item) || is_excluded(self, item_id)) {
        return;
    }

    bool special_flag = check_classification_predicate(self, item, flag_t0);
    if (!special_flag && !matches_target_score(item, threshold, mode)) {
        return;
    }

    append_candidate_id(self, item_id);
    matched_count++;
}

static void evaluate_secondary_candidate(void *self, int index, int threshold, int mode, int &matched_count) {
    int item_id = get_secondary_item_id(self, index);
    void *item = func_00332e60(manager_entity_root(self), item_id);
    if (!item) {
        return;
    }

    typedef int (*Predicate)(void *);
    void **vtable = *reinterpret_cast<void ***>(item);
    Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
    if (!pred(item) || is_excluded(self, item_id)) {
        return;
    }

    bool special_flag = check_classification_predicate(self, item, 0);
    if (!special_flag && !matches_target_score(item, threshold, mode)) {
        return;
    }

    append_candidate_id(self, item_id);
    matched_count++;
}

int func_002B76B0(void *self, int a1, int a2, int a3, int t0) {
    if (a3 == 1) {
        store_integer(self, 3172, 0);
    }

    int total_items = integer_at(self, 216);
    int matched_count = 0;
    for (int index = 0; index < total_items; ++index) {
        evaluate_candidate(self, index, a1, a2, t0, matched_count);
    }
    return matched_count;
}

int func_002B7BB0(void *self, int a1, int a2, int a3) {
    store_integer(self, 3172, 0);
    int matched_count = 0;

    if (a3 == 1) {
        int secondary_count = integer_at(self, 264);
        for (int index = 0; index < secondary_count; ++index) {
            evaluate_secondary_candidate(self, index, a1, a2, matched_count);
        }
    }

    int total_items = integer_at(self, 216);
    for (int index = 0; index < total_items; ++index) {
        evaluate_candidate(self, index, a1, a2, 0, matched_count);
    }
    return matched_count;
}

int func_002B8560(void *self, int mode) {
    int total_items = integer_at(self, 184);
    for (int index = 0; index < total_items; ++index) {
        int item_id = get_pool_item_id(self, index);
        void *item = func_00332e60(manager_entity_root(self), item_id);
        if (!item) {
            continue;
        }

        typedef int (*Predicate)(void *);
        void **vtable = *reinterpret_cast<void ***>(item);
        Predicate pred = reinterpret_cast<Predicate>(*reinterpret_cast<void **>(bytes(vtable) + 356));
        if (!pred(item)) {
            continue;
        }

        if (!check_mode_predicate(self, item_id, mode)) {
            continue;
        }

        short sub_id = short_at(item, 36);
        if ((func_002bfcd0(self, sub_id) & 0xFF) == 1) {
            return sub_id;
        }
    }
    return -1;
}
