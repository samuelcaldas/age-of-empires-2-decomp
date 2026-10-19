#pragma exceptions off
#include "zone_spatial_grid_lookup_node.h"

struct ListNode {
    void *elem;
    ListNode *next;
    ListNode *prev;
};

struct ZoneSpatialGrid {
    void *vtable_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    ListNode *field_14;
    int field_18;
};

extern "C" ListNode *func_001F2E00(ZoneSpatialGrid *self, void *handle) {
    if (handle == 0) {
        return 0;
    }
    ListNode *curr = self->field_14->prev;
    while (curr != self->field_14 && func_0011AA78(func_001F6CD0((SpatialItem *)curr->elem), handle) != 0) {
        curr = curr->prev;
    }
    if (curr != self->field_14 && func_0011AA78(func_001F6CD0((SpatialItem *)curr->elem), handle) == 0) {
        return curr;
    }
    return 0;
}
