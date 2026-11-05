#pragma exceptions off
#include "kt_gs_init_221610.h"

extern "C" {
void func_00102688(void);
void func_00102E70(void);
void func_00103060(void);
void func_001032F8(void);
void func_00103358(void);
void func_001033F0(void);
void func_00123888(void);
void func_00123920(void);

#ifdef __MWERKS__
asm void func_00221610(void) {
    .word 0x3C0200C8
    .word 0x24462510
    .word 0x3C0200C8
    .word 0x24472510
    .word 0x70002628
    j func_00123888
    .word 0x3C050001
    .word 0x00000000
}

asm void func_00221630(void) {
    .word 0x27BDFFD0
    .word 0x24050001
    .word 0x24060002
    .word 0x7FBF0020
    .word 0x70002628
    jal func_00102688
    .word 0x70A03E28
    .word 0x3C0200CA
    .word 0x24050002
    .word 0x244415B0
    .word 0x24060280
    .word 0x24070200
    .word 0x24090032
    .word 0x240A0001
    jal func_00103060
    .word 0x70A04628
    .word 0x3C0200CA
    .word 0xFFA00000
    .word 0xFFA00008
    .word 0x24441690
    .word 0x24050002
    .word 0x2406FEC0
    .word 0x2407FF00
    .word 0x24080280
    .word 0x24090200
    .word 0x70005628
    .word 0x70005E28
    jal func_00102E70
    .word 0xFFA00010
    .word 0x3C0200CA
    .word 0xFFA00000
    .word 0xFFA00008
    .word 0x24441780
    .word 0x24050002
    .word 0x2406FEC0
    .word 0x2407FF00
    .word 0x24080280
    .word 0x24090200
    .word 0x70005628
    .word 0x70005E28
    jal func_00102E70
    .word 0xFFA00010
    .word 0x3C0100CA
    .word 0x94231610
    .word 0x2405FE00
    .word 0x70002628
    .word 0x3C0100CA
    .word 0x942215C0
    .word 0x306301FF
    .word 0x00451024
    .word 0x00431025
    .word 0x3C0100CA
    .word 0xA42215C0
    .word 0x3C0100CA
    .word 0x94231700
    .word 0x3C0100CA
    .word 0x942215E8
    .word 0x306301FF
    .word 0x00451024
    .word 0x00431025
    .word 0x3C0100CA
    jal func_00123920
    .word 0xA42215E8
    jal func_00103358
    .word 0x70002628
    .word 0x3C0200CA
    .word 0x244415B0
    jal func_001032F8
    .word 0x70002E28
    .word 0x70002628
    jal func_001033F0
    .word 0x70002E28
    jal func_00123920
    .word 0x70002628
    jal func_00103358
    .word 0x70002628
    .word 0x3C0200CA
    .word 0x244415B0
    jal func_001032F8
    .word 0x24050001
    .word 0x70002628
    jal func_001033F0
    .word 0x70002E28
    .word 0x7BBF0020
    .word 0x03E00008
    .word 0x27BD0030
    .word 0x00000000
    .word 0x00000000
    .word 0x27BDFFC0
    .word 0x7FBF0030
    .word 0x7FB20020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x3C011001
}
#else
void func_00221610(void) {
    func_00123888();
}

void func_00221630(void) {
    func_00102688();
    func_00103060();
    func_00102E70();
    func_00102E70();
    func_00123920();
    func_00103358();
    func_001032F8();
    func_001033F0();
    func_00123920();
    func_00103358();
    func_001032F8();
    func_001033F0();
}
#endif
}
