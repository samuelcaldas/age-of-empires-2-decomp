#ifndef UNIT_ACTION_BUILD_HAS_ITEMS_FIXTURE_H
#define UNIT_ACTION_BUILD_HAS_ITEMS_FIXTURE_H

#include <cstddef>
#include "unit_action_build_has_items.h"

struct DummyHasItemsAction {
    void *vtable;
    char pad_04[200];
    void *m_list1;
    char pad_CC[124];
    void *m_list2;
};

static int g_hasitems_list1_ret = 0;
static int g_hasitems_list2_ret = 0;
static int g_hasitems_calls = 0;

extern "C" {
    int HasItems__8BaseListFv(void *list) {
        g_hasitems_calls++;
        if (list == (void*)0x1111) return g_hasitems_list1_ret;
        if (list == (void*)0x2222) return g_hasitems_list2_ret;
        return 0;
    }
}

#endif // UNIT_ACTION_BUILD_HAS_ITEMS_FIXTURE_H
