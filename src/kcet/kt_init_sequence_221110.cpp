#pragma exceptions off
#include "kt_init_sequence_221110.h"

extern "C" {
void func_00221630(void);
void func_00103358(void);
void func_00102688(void);
void func_00103060(void);
void func_00102E70(void);
int func_00223F50(void);
int func_00223F70(void);
void func_00133FB8(void);
void func_00224940(void);
void func_002201E0(void);
void func_002222D0(void);
void func_00224150(void);
void func_00117CAC(void);
void func_00387100(void);
void func_0036D4E0(void);
void func_00221CF0(void);

extern int D_004E26E0;

#ifdef __MWERKS__
asm void func_00221110(void) {
    .word 0x27BDFFB0
    .word 0x7FBF0030
    .word 0x7FB00020
    .word 0x3C0200CA
    jal func_00221630
    .word 0x245015B0
    jal func_00103358
    .word 0x70002628
    .word 0x24050001
    .word 0x24060003
    .word 0x70002628
    jal func_00102688
    .word 0x70003E28
    .word 0x3C0200CA
    .word 0x24050002
    .word 0x244415B0
    .word 0x24060280
    .word 0x24070200
    .word 0x24090032
    .word 0x70A04628
    jal func_00103060
    .word 0x70005628
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
    jal func_00223F50
    .word 0x00000000
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
    .word 0x3C0100CA
    .word 0x942615E8
    .word 0x000212C3
    .word 0x304501FF
    .word 0x3C030005
    .word 0x3463000D
    .word 0x2402FE00
    .word 0xFFA30048
    .word 0x00C21824
    .word 0x00651825
    .word 0x3C0100CA
    .word 0xA42315E8
    .word 0x3C0100CA
    .word 0x942515C0
    .word 0x306601FF
    .word 0x3C0300CA
    .word 0x246A16E0
    .word 0x3C0300CA
    .word 0x00A22824
    .word 0x00A62825
    .word 0x3C0100CA
    .word 0xA42515C0
    .word 0x3C0100CA
    .word 0x942C1710
    .word 0x246917D0
    .word 0x3C03FF80
    .word 0x34670FFF
    .word 0x640400A0
    .word 0x3C01001F
    .word 0x3428F000
    .word 0x01821824
    .word 0x00641825
    .word 0x3C0100CA
    .word 0xA4231710
    .word 0x3C0100CA
    .word 0x942C1620
    .word 0x306D01FF
    .word 0x27AB0048
    .word 0x24040280
    .word 0x01821024
    .word 0x004D1025
    .word 0x3C0100CA
    .word 0xA4221620
    .word 0xDD620000
    .word 0x3C0100CA
    .word 0x24030200
    .word 0x2405F000
    .word 0xFD420000
    .word 0xDD620000
    .word 0x640609FF
    .word 0xFD220000
    .word 0xA424158C
    .word 0x3C0100CA
    .word 0xA423158E
    .word 0x3C0100CA
    .word 0x8C2315CC
    .word 0x8F8286A0
    .word 0x00671824
    .word 0x00681825
    .word 0x3C0100CA
    .word 0xAC2315CC
    .word 0x3C0100CA
    .word 0x8C2315F4
    .word 0x00671824
    .word 0x00681825
    .word 0x3C0100CA
    .word 0xAC2315F4
    .word 0x3C0100CA
    .word 0x942315CC
    .word 0x00651824
    .word 0x00661825
    .word 0x3C0100CA
    .word 0xA42315CC
    .word 0x3C0100CA
    .word 0x942315F4
    .word 0x00651824
    .word 0x00661825
    .word 0x3C0100CA
    .word 0xA42315F4
    .word 0x3C0100CA
    .word 0x942415C8
    .word 0x3C0100CA
    .word 0x8C2315C8
    .word 0x30840FFF
    .word 0x3C0100CA
    .word 0xAC241598
    .word 0x00031A7C
    .word 0x00031D7E
    .word 0x3C0100CA
    .word 0x10400003
    .word 0xAC23159C
    jal func_00133FB8
    .word 0x72002628
    .word 0x3C0100CA
    .word 0x9024157C
    .word 0x2402FFFB
    .word 0x64030004
    .word 0x00821024
    .word 0x00431025
    .word 0x3C0100CA
    jal func_00224940
    .word 0xA022157C
    jal func_002201E0
    .word 0x00000000
    jal func_002222D0
    .word 0x00000000
    jal func_00224150
    .word 0x00000000
    .word 0x24064000
    .word 0x3C047000
    jal func_00117CAC
    .word 0x70002E28
    jal func_00387100
    .word 0x00000000
    jal func_0036D4E0
    .word 0x00000000
    jal func_00221CF0
    .word 0x00000000
    .word 0x7BBF0030
    .word 0x7BB00020
    .word 0x03E00008
    .word 0x27BD0050
}
#else
void func_00221110(void) {
    func_00221630();
    func_00103358();
    func_00102688();
    func_00103060();
    func_00102E70();
    func_00102E70();
    func_00223F50();
    func_00223F70();
    if (D_004E26E0 != 0) {
        func_00133FB8();
    }
    func_00224940();
    func_002201E0();
    func_002222D0();
    func_00224150();
    func_00117CAC();
    func_00387100();
    func_0036D4E0();
    func_00221CF0();
}
#endif
}
