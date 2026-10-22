#pragma exceptions off
#include "tactical_ai_mode_ops.h"

void func_00309310(TacticalModeManager *self, int mode) {
    self->m_field194 = mode;
}

int func_00309320(TacticalModeManager *self) {
    return self->m_field194;
}
