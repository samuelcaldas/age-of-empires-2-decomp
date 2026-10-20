#pragma exceptions off
#include "tactical_ai_func_342ab0.h"

extern "C" {
int func_00342AB0(TacticalItem_342820 *self, int level, int force_flag) {
    if (!force_flag) {
        if (level < self->field_14) {
            if (self->field_1C[level]) {
                if (self->field_18 < level) {
                    self->field_10 = self->field_18;
                } else {
                    self->field_10 = level;
                }
                return 1;
            }
        }
        return 0;
    }
    if (level < self->field_14) {
        self->field_10 = level;
        return 1;
    }
    return 0;
}
}
