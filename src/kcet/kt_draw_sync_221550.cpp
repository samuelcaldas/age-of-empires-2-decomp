#pragma exceptions off
#include "kt_draw_sync_221550.h"

extern "C" {
void func_00104448(void);
void func_001045E8(void);
void func_00104600(void);
void func_00104890(void);
void func_00116F40(void);
void func_00116F68(void);

#ifdef __MWERKS__
asm void func_00221550(void *a0) {
    .word 0x27BDFFD0
    .word 0x7FBF0020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x3C0300CA
    .word 0x247015B0
    .word 0x3C0100CA
    .word 0x9023157C
    .word 0x00031F7C
    .word 0x00031FFE
    .word 0x10600010
    .word 0x70808E28
    .word 0x70002E28
    .word 0x70003628
    jal func_00104448
    .word 0x70003E28
    .word 0x3C020039
    .word 0x24422CB0
    .word 0x78450000
    jal func_001045E8
    .word 0x72202628
    .word 0x260500E0
    .word 0x24060006
    jal func_00104890
    .word 0x72202628
    jal func_00104600
    .word 0x72202628
    .word 0x7BBF0020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0030
}

asm void func_002215D0(void) {
    .word 0x3C0201D9
    .word 0x34438000
    .word 0x3C020179
    .word 0x244253A0
    .word 0x27BDFFF0
    .word 0x00621023
    .word 0x7FBF0000
    jal func_00116F40
    .word 0x2444FF80
    jal func_00116F68
    .word 0x70402628
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}
#else
void func_00221550(void *a0) {
    (void)a0;
}

void func_002215D0(void) {
    func_00116F40();
    func_00116F68();
}
#endif
}
