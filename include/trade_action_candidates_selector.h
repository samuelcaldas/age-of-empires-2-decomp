#ifndef TRADE_ACTION_CANDIDATES_SELECTOR_H
#define TRADE_ACTION_CANDIDATES_SELECTOR_H

#include "trade_action_candidates_access.h"

extern "C" {
int func_002bf050(void *self, int item_id);
int func_002bfcd0(void *self, short sub_id);
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

} // namespace trade_action_candidates

#endif // TRADE_ACTION_CANDIDATES_SELECTOR_H
