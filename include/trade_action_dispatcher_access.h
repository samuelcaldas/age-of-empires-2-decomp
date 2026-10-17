#ifndef TRADE_ACTION_DISPATCHER_ACCESS_H
#define TRADE_ACTION_DISPATCHER_ACCESS_H

#include "trade_action_dispatcher.h"

namespace trade_action_dispatcher {

struct Entity {
    char padding[36];
    short id;
};

struct ActionData {
    char padding[14];
    short type;
};

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

inline float float_at(void *object, int offset) {
    return *reinterpret_cast<float *>(bytes(object) + offset);
}

inline void store_integer(void *object, int offset, int value) {
    *reinterpret_cast<int *>(bytes(object) + offset) = value;
}

inline void *manager(void *self) {
    return pointer_at(self, 176);
}

inline void *manager_group(void *manager_object) {
    return pointer_at(manager_object, 172);
}

inline void *entity_manager(void *manager_object) {
    return pointer_at(manager_group(manager_object), 2968);
}

inline int entity_team(void *entity) {
    return integer_at(pointer_at(entity, 8), 2976);
}

inline int manager_team(void *group) {
    return integer_at(group, 2976);
}

}

#endif
