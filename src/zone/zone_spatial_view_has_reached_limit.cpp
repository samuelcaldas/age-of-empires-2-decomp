#pragma exceptions off
#pragma conditional_move off

#include "zone_spatial_view_has_reached_limit.h"

extern "C" {
void *func_1FCE60(void *sub);
void *func_3334A0(void *obj, int id);
extern void *D_004E3180;
}

struct SpatialViewObj {
    char pad[0xA8];
    void *sub;
};

struct Item {
    char pad0[8];
    void *field_8;
    int field_C;
    int field_10;
};

struct Target {
    char pad[0x20];
    char count;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

extern "C" int func_001D9250(SpatialViewObj *self) {
    if (self->sub) {
        Item *item = (Item *)func_1FCE60(self->sub);
        if (item) {
            if (item->field_8 == 0) {
                GlobalContext *ctx = (GlobalContext *)D_004E3180;
                Target *t = (Target *)func_3334A0(ctx->field_404, item->field_C);
                if (t) {
                    if (item->field_10 < (int)(t->count - 1)) {
                        return 0;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
