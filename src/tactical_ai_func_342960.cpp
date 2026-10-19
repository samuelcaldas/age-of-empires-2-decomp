#pragma exceptions off
#include "tactical_ai_func_342960.h"

extern "C" {
void func_00342960(TacticalItem_342820 *self, void *stream) {
    func_00226F70(stream, self->name, 16);
    func_00226F70(stream, &self->field_10, 4);
    func_00226F70(stream, &self->field_14, 4);
    func_00226F70(stream, &self->field_18, 4);
    func_00226F70(stream, self->field_1C, 7);
}
}
