#pragma exceptions off
#include "tactical_ai_func_342880.h"

extern "C" {
void func_00342880(TacticalItem_342820 *self, void *stream) {
    func_00226D90(stream, self->name, 16);
    func_00226D90(stream, &self->field_10, 4);
    func_00226D90(stream, &self->field_14, 4);
    func_00226D90(stream, &self->field_18, 4);
    func_00226D90(stream, self->field_1C, 7);
}
}
