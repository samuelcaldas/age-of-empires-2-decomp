#ifndef TRADE_ACTION_CANDIDATES_SELECTOR_H
#define TRADE_ACTION_CANDIDATES_SELECTOR_H

#include "trade_action_candidates_access.h"

extern "C" {
void *func_00332e60(void *manager, int id);
int func_002bf050(void *self, int item_id);
int func_002bfcd0(void *self, short sub_id);
float func_00269190(float x, float y, void *item);
}

namespace trade_action_candidates {

inline int get_pool_item_id(void *self, int index) {
    int capacity = integer_at(self, 192);
    int access_index = (index < capacity - 1) ? index : 0;
    int *item_ids = *reinterpret_cast<int **>(bytes(self) + 180);
    return item_ids[access_index];
}

inline bool is_pool_excluded(void *self, int item_id) {
    int count = integer_at(self, 200);
    int capacity = integer_at(self, 208);
    int *excluded_ids = *reinterpret_cast<int **>(bytes(self) + 196);
    for (int i = 0; i < count && i < capacity; ++i) {
        if (item_id == excluded_ids[i]) {
            return true;
        }
    }
    return false;
}

inline bool check_mode_predicate(void *self, int item_id, int mode) {
    if (mode == 0 || mode == 3) {
        if (func_002bf050(self, item_id) != 0) {
            return false;
        }
    }
    if (mode == 0 || mode == 1) {
        if (is_pool_excluded(self, item_id)) {
            return false;
        }
    }
    return true;
}

inline bool is_better_distance(float dist, float best_dist, int flag) {
    if (flag == 1) {
        return dist <= best_dist;
    }
    if (flag == 0) {
        return dist < best_dist;
    }
    return false;
}

inline void evaluate_distance_candidate(void *self, int item_id, void *item, int *coords, int mode, int flag,
                                       short &best_sub_id, float &best_dist) {
    if (!check_mode_predicate(self, item_id, mode)) {
        return;
    }
    if ((func_002bfcd0(self, short_at(item, 36)) & 0xFF) != 1) {
        return;
    }

    float x = static_cast<float>(coords[0]);
    float y = static_cast<float>(coords[1]);
    float dist = func_00269190(x, y, item);

    if (best_sub_id == -1) {
        best_sub_id = short_at(item, 36);
        best_dist = dist;
        return;
    }

    if (is_better_distance(dist, best_dist, flag)) {
        best_sub_id = short_at(item, 36);
        best_dist = dist;
    }
}

} // namespace trade_action_candidates

#endif // TRADE_ACTION_CANDIDATES_SELECTOR_H
