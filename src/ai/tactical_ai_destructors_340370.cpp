#pragma exceptions off
#include "tactical_ai_destructors_340370.h"

extern "C" {
void func_210490(void *ptr, int a);
void func_216020(void *ptr, int a);
void func_208E20(void *ptr, int a);
void func_100670(void *ptr);
}

extern void *__vt__004DF080;
extern void *__vt__004DF1B0;
extern void *__vt__004DF2E0;

extern "C" {

void *func_00340370(TacticalObj_340370 *self, int flags) {
    if (self) {
        self->vtable = &__vt__004DF080;
        func_210490(self, 0);
        if ((short)flags > 0) {
            func_100670(self);
        }
    }
    return self;
}

void *func_003403D0(TacticalObj_340370 *self, int flags) {
    if (self) {
        self->vtable = &__vt__004DF1B0;
        func_216020(self, 0);
        if ((short)flags > 0) {
            func_100670(self);
        }
    }
    return self;
}

void *func_00340430(TacticalObj_340370 *self, int flags) {
    if (self) {
        self->vtable = &__vt__004DF2E0;
        func_208E20(self, 0);
        if ((short)flags > 0) {
            func_100670(self);
        }
    }
    return self;
}

}
