#pragma exceptions off
#include "kt_vblank_handlers.h"

extern "C" {
int func_104D50(int sema_id);

int func_00220D50(void) {
    D_00CA1550[1] = D_00CA1550[1] + 1;
    func_104D50(D_00C7F430.id);
#ifdef __MWERKS__
    asm {
        sync
        ei
    }
#endif
    D_004E331C = 1;
    return 0;
}

int func_00220DA0(void) {
    func_104D50(D_00C80490.id);
#ifdef __MWERKS__
    asm {
        sync
        ei
    }
#endif
    D_004E331C = 0;
    return 0;
}
}
