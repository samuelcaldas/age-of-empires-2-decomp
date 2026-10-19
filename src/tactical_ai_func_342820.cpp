#pragma exceptions off
#include "tactical_ai_func_342820.h"

extern "C" {
const char D_004D5668[] = "";

void func_00342820(TacticalItem_342820 *self) {
    func_11ABBC(self, D_004D5668);
    self->field_10 = 0;
    self->field_14 = 0;
    for (int i = 0; i < 7; i++) {
        self->field_1C[i] = 0;
    }
    self->field_18 = 0;
    self->field_24 = 0;
}
}
