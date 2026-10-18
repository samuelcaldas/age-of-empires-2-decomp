#ifndef TRADE_ACTION_CANDIDATES_DISTANCE_H
#define TRADE_ACTION_CANDIDATES_DISTANCE_H

#include "trade_action_candidates_selector.h"

namespace trade_action_candidates {

inline int scan_distance_candidates(void *self, int *coords, int mode, int flag) {
    short best_sub_id = -1;
    float best_dist = 0.0f;
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

        evaluate_distance_candidate(self, item_id, item, coords, mode, flag, best_sub_id, best_dist);
    }
    return best_sub_id;
}

} // namespace trade_action_candidates

#endif // TRADE_ACTION_CANDIDATES_DISTANCE_H
