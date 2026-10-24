#pragma exceptions off

#include "zone_spatial_entity_dtor.h"

extern "C" {
void func_1D8480(void *self, void *arg);
void func_194E20(void *self, int flag);
void func_100670(void *ptr);
}

extern void *__vt__004D92B0;

struct SpatialEntityDestructor {
    void *vtable;
};

extern "C" void *func_001D84B0(SpatialEntityDestructor *self, int flag) {
    if (self) {
        self->vtable = &__vt__004D92B0;
        func_1D8480(self, 0);
        func_194E20(self, 0);
        if ((short)flag > 0) func_100670(self);
    }
    return self;
}
