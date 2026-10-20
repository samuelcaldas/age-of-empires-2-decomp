#pragma exceptions off
#include "tactical_ai_func_3429e0.h"

extern "C" {
void func_003429E0(TacticalItem_342820 *self, void **descriptors, int count) {
    self->field_24 = 0;
    for (int i = 0; i < count; i++) {
        void **desc = &descriptors[i];
        const char *name = func_00188DB0(*desc);
        if (func_11AA78(name, self->name) == 0) {
            self->field_24 = (int)(long)*desc;
            self->field_14 = func_00188DC0((void*)(long)self->field_24);
            if (self->field_18 >= self->field_14) {
                self->field_18 = self->field_14 - 1;
            }
            if (self->field_10 > self->field_18) {
                self->field_10 = self->field_18;
            }
        }
    }
}
}
