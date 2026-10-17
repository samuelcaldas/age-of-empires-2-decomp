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

} // namespace trade_action_candidates

#endif // TRADE_ACTION_CANDIDATES_DUAL_H
