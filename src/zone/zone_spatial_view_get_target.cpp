#pragma exceptions off

#include "zone_spatial_view_get_target.h"

extern "C" {
void *func_1FCE60(void *sub);
void *func_3334A0(void *obj, int id);
extern void *D_004E3180;
}

struct Item {
    char pad0[8];
    void *field_8;
    int field_C;
};

struct SpatialViewObj {
    char pad[0xA8];
    void *sub;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

extern "C" void *func_001D91D0(SpatialViewObj *self) {
    if (!self->sub) {
        return 0;
    }
    Item *item = (Item *)func_1FCE60(self->sub);
    if (!item) {
        return 0;
    }
    if (item->field_8 != 0) {
        return item->field_8;
    }
    if (item->field_C != -1) {
        GlobalContext *ctx = (GlobalContext *)D_004E3180;
        return func_3334A0(ctx->field_404, item->field_C);
    }
    return 0;
}
