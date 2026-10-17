#pragma exceptions off
#include "tactical_ai_dispatch_3409c0.h"

extern "C" {
int func_340C30(void *self);
int func_1F8140(void *self);

int func_003409C0(TacticalObj_3409C0 *self) {
    if (self->field_858) {
        func_340C30(self);
        return 0;
    }
    return func_1F8140(self);
}

}
