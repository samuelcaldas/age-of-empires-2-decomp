#ifndef TRADE_ACTION_CANDIDATES_ACCESS_H
#define TRADE_ACTION_CANDIDATES_ACCESS_H

#include "trade_action_candidates.h"

namespace trade_action_candidates {

inline char *bytes(void *pointer) {
    return static_cast<char *>(pointer);
}

inline void *pointer_at(void *object, int offset) {
    return *reinterpret_cast<void **>(bytes(object) + offset);
}

inline int integer_at(void *object, int offset) {
    return *reinterpret_cast<int *>(bytes(object) + offset);
}

inline short short_at(void *object, int offset) {
    return *reinterpret_cast<short *>(bytes(object) + offset);
}

inline void store_integer(void *object, int offset, int value) {
    *reinterpret_cast<int *>(bytes(object) + offset) = value;
}

inline void *manager_entity_root(void *self) {
    void *mgr = pointer_at(self, 176);
    void *root = pointer_at(mgr, 0x1f348);
    return pointer_at(root, 2968);
}

inline void *manager_group_root(void *self) {
    void *mgr = pointer_at(self, 176);
    void *group = pointer_at(mgr, 172);
    return pointer_at(group, 2968);
}

} // namespace trade_action_candidates

#endif // TRADE_ACTION_CANDIDATES_ACCESS_H
