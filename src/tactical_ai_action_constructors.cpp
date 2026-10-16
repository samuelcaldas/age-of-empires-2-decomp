#pragma exceptions off
#include "tactical_ai_action_constructors.h"

int func_00307160(void *self, ActionDesc *desc) {
    if (desc->m_type == 104) {
        return 1;
    }
    return func_2cc630(self, desc);
}

void *func_003071A0(void *self) {
    void *s0 = self;
    func_315560(s0);
    *(void **)((char *)s0 + 36) = &D_4DE760;
    return s0;
}

void *func_003071E0(void *self) {
    void *s0 = self;
    func_315a50(s0);
    *(void **)((char *)s0 + 36) = &D_4DE760;
    return s0;
}
