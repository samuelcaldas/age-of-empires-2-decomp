#pragma exceptions off
#include "kt_vsync_thread.h"

extern "C" {
int func_2204D0(int sema_id);
int func_104D60(int sema_id);

void func_00220C10(void) {
    while (1) {
        func_2204D0(D_00C80490.id);
        func_104D60(D_00C80490.id);
#ifdef __MWERKS__
        asm {
            sync
            ei
        }
#endif
        u64 csr = *(volatile u64 *)0x12001000;
        D_004E3318 = (int)((csr & 0x2000) >> 13);
    }
}
}
