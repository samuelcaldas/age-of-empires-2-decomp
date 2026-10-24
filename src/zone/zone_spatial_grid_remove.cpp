#pragma exceptions off
#include "zone_spatial_grid_remove.h"

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

extern "C" int func_001F2820(ZoneSpatialGrid *self, void *elem) {
    if (elem == 0) {
        return 0;
    }
    ListNode *node = func_001F2E00(self, elem);
    if (node == 0) {
        return 0;
    }
    self->field_18--;
    node->next->prev = node->prev;
    node->prev->next = node->next;
    func_00116F68(node);
    return 1;
}
