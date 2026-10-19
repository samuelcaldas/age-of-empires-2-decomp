#pragma exceptions off
#include "zone_spatial_grid_update.h"

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
    int field_1C;
};

extern "C" int func_001F2900(ZoneSpatialGrid *self, void *item, int param2) {
    ListNode *node = func_001F2E00(self, item);
    if (node != 0) {
        if (self->field_04 != 0) {
            func_001F65A0(self->field_04);
        }
        self->field_0C = 0;
        self->field_08 = 0;
        func_001F2EB0(self, node->elem, param2);
        return 1;
    }
    return 0;
}
