#ifndef TRADE_ACTION_CANDIDATES_DUAL_H
#define TRADE_ACTION_CANDIDATES_DUAL_H

#include "trade_action_candidates_access.h"

namespace trade_action_candidates {

inline int get_secondary_item_id(void *self, int index) {
    int capacity = integer_at(self, 272);
    int access_index = (index < capacity - 1) ? index : 0;
    int *item_ids = *reinterpret_cast<int **>(bytes(self) + 260);
    return item_ids[access_index];
}

inline bool matches_target_score(void *item, int threshold, int mode) {
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

} // namespace trade_action_candidates

#endif // TRADE_ACTION_CANDIDATES_DUAL_H
