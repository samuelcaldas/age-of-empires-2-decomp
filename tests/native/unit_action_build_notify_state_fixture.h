#ifndef UNIT_ACTION_BUILD_NOTIFY_STATE_FIXTURE_H
#define UNIT_ACTION_BUILD_NOTIFY_STATE_FIXTURE_H

#include "unit_action_build_notify_state.h"

struct DummyNotifyItem {
    char pad_00[4];
    short m_type;
};

struct DummyNotifyAction {
    char pad_00[332];
    void *m_list;
    void *m_slots;
    char pad_154[3];
    unsigned char m_count;
};

#endif // UNIT_ACTION_BUILD_NOTIFY_STATE_FIXTURE_H
