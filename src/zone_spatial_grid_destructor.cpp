#pragma exceptions off
#include "zone_spatial_grid_destructor.h"

extern "C" void *D_004D9AD0[16];

struct ListNode {
    void *pad_00;
    void **elem;
    ListNode *next;
};

struct SpatialEntity {
    virtual ~SpatialEntity();
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
    void *table_20[10];
    char buckets_48[10][256];
    int table_A48[10];
    int table_A70[10];
    int field_A98;
    int field_A9C;
    int field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    int field_AB0;
};

extern "C" ZoneSpatialGrid *func_001F2590(ZoneSpatialGrid *self, short flag) {
    if (self != 0) {
        self->vtable_00 = D_004D9AD0;
        func_001F34D0(self);
        if (self->field_14 != 0) {
            ListNode *node = self->field_14->next;
            while (node != self->field_14) {
                node = node->next;
                delete (SpatialEntity *)node->elem[0];
                func_00116F68(node->elem);
            }
            func_00116F68(self->field_14);
            self->field_14 = 0;
        }

        for (int i = 0; i < 10; ++i) {
            if (self->table_20[i] != 0) {
                func_0021B430(self->table_20[i]);
                self->table_20[i] = 0;
                self->buckets_48[i][0] = 0;
                self->table_A48[i] = 0;
                self->table_A70[0] = 0;
            }
        }

        func_001F32F0(self);
        if (flag > 0) {
            func_100670(self);
        }
    }
    return self;
}
