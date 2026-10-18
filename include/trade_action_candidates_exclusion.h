#ifndef TRADE_ACTION_CANDIDATES_EXCLUSION_H
#define TRADE_ACTION_CANDIDATES_EXCLUSION_H

#include "trade_action_candidates_access.h"

namespace trade_action_candidates {

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

}

#endif
