#pragma exceptions off
#include "kt_dma_flip_221410.h"

extern "C" {
void func_00104FA0(void);
void func_00133E10(void);
void func_00133F38(void);
void func_00133FB8(void);
void func_00223F50(void);
void func_00223F70(void);

extern int D_004E26E0;

#ifdef __MWERKS__
asm void func_00221410(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    jal func_00133E10
    .word 0x00000000
    .word 0x24030083
    .word 0x3C011000
    .word 0xAC230010
    .word 0x3C011000
    .word 0xAC200000
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}

asm void func_00221440(void) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x3C0200CA
    .word 0x245015B0
    .word 0x3C0100CA
    .word 0x8C221578
    .word 0x0002102B
    .word 0x38420001
    .word 0x304200FF
    .word 0x3C0100CA
    jal func_00223F50
    .word 0xAC221578
    .word 0x000212C3
    .word 0x304301FF
    .word 0x3C0100CA
    .word 0x94221700
    .word 0x2404FE00
    .word 0x00441024
    .word 0x00431025
    .word 0x3C0100CA
    .word 0xA4221700
    .word 0x304301FF
    .word 0x3C0100CA
    .word 0x94221610
    .word 0x00441024
    .word 0x00431025
    .word 0x3C0100CA
    jal func_00223F70
    .word 0xA4221610
    .word 0x000212C3
    .word 0x304301FF
    .word 0x3C0100CA
    .word 0x942215E8
    .word 0x2405FE00
    .word 0x70002628
    .word 0x00451024
    .word 0x00431025
    .word 0x3C0100CA
    .word 0xA42215E8
    .word 0x304301FF
    .word 0x3C0100CA
    .word 0x942215C0
    .word 0x00451024
    .word 0x00431025
    .word 0x3C0100CA
    jal func_00104FA0
    .word 0xA42215C0
    .word 0x8F8286A0
    .word 0x10400009
    .word 0x72002628
    jal func_00133FB8
    .word 0x72002628
    .word 0x24050001
    jal func_00133F38
    .word 0x72002628
    .word 0x10000005
    .word 0x7BBF0010
    .word 0x72002628
    jal func_00133F38
    .word 0x70002E28
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
}
#else
void func_00221410(void) {
    func_00133E10();
}

void func_00221440(void) {
    func_00223F50();
    func_00223F70();
    func_00104FA0();
    if (D_004E26E0 != 0) {
        func_00133FB8();
    }
    func_00133F38();
    func_00133F38();
}
#endif
}
