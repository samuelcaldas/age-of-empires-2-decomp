#pragma exceptions off
#include "tactical_ai_check_340cf0.h"

extern "C" {
int func_210010(void *ptr);

int func_00340CF0(TacticalObj_340CF0 *self) {
    void *p = self->field_838;
    if (p == 0) {
        return 1;
    }
    return func_210010(p) ? 0 : 1;
}

}
