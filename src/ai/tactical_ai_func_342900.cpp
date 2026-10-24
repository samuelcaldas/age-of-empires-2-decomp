#pragma exceptions off
#include "tactical_ai_func_342900.h"

extern "C" {
void func_00342900(TacticalItem_342820 *self, void *info) {
    self->field_24 = (int)(long)info;
    const char *str = func_00188DB0((void*)(long)self->field_24);
    func_11ABBC(self->name, str);
    self->field_14 = func_00188DC0((void*)(long)self->field_24);
    if (self->field_14 > 0) {
        self->field_10 = 0;
        self->field_18 = 0;
        self->field_1C[0] = 2;
    }
}
}
