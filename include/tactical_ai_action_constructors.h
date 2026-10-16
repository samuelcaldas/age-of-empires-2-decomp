#ifndef TACTICAL_AI_ACTION_CONSTRUCTORS_H
#define TACTICAL_AI_ACTION_CONSTRUCTORS_H

#include "tactical_ai_action_desc.h"

extern "C" {
    extern void *D_4DE760;
    int func_2cc630(void *self, ActionDesc *desc);
    void *func_315560(void *self);
    void *func_315a50(void *self);

    /**
     * Action command delegator: tests type 104 -> 1, or delegates to func_2cc630.
     * VRAM: 0x307160 - 0x3071A0 (64 bytes).
     */
    int func_00307160(void *self, ActionDesc *desc);

    /**
     * Tactical Action Primary Constructor.
     * VRAM: 0x3071A0 - 0x3071E0 (64 bytes).
     */
    void *func_003071A0(void *self);

    /**
     * Tactical Action Secondary Constructor.
     * VRAM: 0x3071E0 - 0x307220 (64 bytes).
     */
    void *func_003071E0(void *self);
}

#endif // TACTICAL_AI_ACTION_CONSTRUCTORS_H
