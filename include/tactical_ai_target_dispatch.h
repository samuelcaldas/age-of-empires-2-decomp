#ifndef TACTICAL_AI_TARGET_DISPATCH_H
#define TACTICAL_AI_TARGET_DISPATCH_H

#include "tactical_ai_target_scan.h"

extern "C" {
    extern void *D_004E3180;

    void *func_186010(void *global);
    void func_1a4960(void *self, int arg1, int arg2, int mark, int action_code, TargetEntity *ent);

    /**
     * Tactical target action dispatcher.
     * VRAM: 0x3088A0 - 0x308A70 (464 bytes slice, 456 bytes code).
     */
    void func_003088A0(TargetScanManager *self, int arg1, int arg2, int arg3, int arg4, TargetEntity *ent);
}

#endif // TACTICAL_AI_TARGET_DISPATCH_H
