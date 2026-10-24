#pragma exceptions off
#include "zone_spatial_grid_insert.h"

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

extern "C" int func_001F2730(ZoneSpatialGrid *self, void *elem, int update_spatial, int param3) {
    void *item = func_001F6CD0(elem);
    ListNode *node = func_001F2E00(self, item);
    if (node == 0) {
        node = (ListNode *)func_001143F8(1, sizeof(ListNode));
        if (node == 0) {
            return 0;
        }
        node->elem = elem;
        func_001F6CA0(elem, 0);
        node->next = self->field_14->next;
        node->prev = self->field_14;
        self->field_14->next = node;
        node->next->prev = node;
        self->field_18++;
    }
    if (update_spatial != 0) {
        func_001F2EB0(self, elem, param3);
    }
    return 1;
}
