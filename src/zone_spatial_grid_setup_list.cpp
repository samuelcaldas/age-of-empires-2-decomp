#pragma exceptions off
#include "zone_spatial_grid_setup_list.h"

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
    char pad_1C[0xAB0 - 0x1C];
    int field_AB0;
};

extern "C" int func_001F2DA0(ZoneSpatialGrid *self) {
    self->field_14 = (ListNode *)func_001143F8(1, 12);
    if (self->field_14 == 0) {
        return 0;
    }
    self->field_14->elem = 0;
    self->field_14->next = self->field_14;
    self->field_14->prev = self->field_14;
    self->field_AB0 = 1;
    return 1;
}
