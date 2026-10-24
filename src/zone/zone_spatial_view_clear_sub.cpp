#pragma exceptions off

#include "zone_spatial_view_clear_sub.h"

extern "C" {
void func_1FC610(void *ptr);
void func_1FCD90(void *ptr);
}

struct SubObj {
    char pad0[4];
    SubObj *next;
    char pad1[0x10 - 8];
    int field_10;
    char pad2[0x25 - 0x14];
    char field_25;
    char field_26;
    char field_27;
};

struct SpatialViewObj {
    char pad[0xA8];
    SubObj *sub;
};

extern "C" void func_001D9110(SpatialViewObj *self) {
    SubObj *cur = self->sub;
    if (!cur) {
        return;
    }
    if (cur->next != 0) {
        do {
            SubObj *next = cur->next;
            if (!next) {
                break;
            }
            func_1FC610(cur);
            cur->next = 0;
            cur = next;
            if (!cur) {
                break;
            }
        } while (cur->field_25 != 2);
        self->sub = cur;
    }
    cur = self->sub;
    if (!cur) {
        return;
    }
    if (cur->field_25 == 2) {
        cur->field_10 = 1;
        self->sub->field_26 = 2;
        self->sub->field_27 = 10;
        return;
    }
    func_1FCD90(cur);
}
