#pragma exceptions off

#include "zone_spatial_view_obj_dtor.h"

extern "C" {
void func_1FC610(void *ptr);
void func_100670(void *ptr);
}

extern void *__vt__004D9610;

struct SpatialViewObj {
    void *vtable;
    char pad[0xA8 - 4];
    void *field_A8;
};

extern "C" void *func_001D8C30(SpatialViewObj *self, int flag) {
    if (self) {
        self->vtable = &__vt__004D9610;
        if (self->field_A8 != 0) {
            func_1FC610(self->field_A8);
        }
        self->field_A8 = 0;
        if ((short)flag > 0) func_100670(self);
    }
    return self;
}
