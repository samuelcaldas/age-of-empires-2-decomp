#pragma exceptions off
#include "kt_gs_swap_221790.h"

extern "C" {
void func_001043B8(void);
void func_00104FA0(void);
void func_00117CAC(void);
void func_0021C4A0(void);
void func_0021C610(void);
void func_0021C810(void);
void func_0021E500(void);
void func_002204E0(void);

extern int D_004E1CA0;
extern int D_004E32E4;
extern int D_004E1CA4;

#ifdef __MWERKS__
asm void func_00221790(void) {
    .word 0x27BDFFC0
    .word 0x7FBF0030
    .word 0x7FB20020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x3C011001
    .word 0x8C22A000
    .word 0x30420100
    .word 0x1440FFFD
    .word 0x3C011001
    .word 0xAF808B60
    .word 0xAF808B64
    .word 0x3C117000
    .word 0x1000000D
    .word 0x70008628
    .word 0x00101100
    .word 0x02229021
    .word 0x24060010
    .word 0x72402628
    jal func_00117CAC
    .word 0x70002E28
    .word 0x00101300
    .word 0x02221021
    .word 0x24450020
    jal func_001043B8
    .word 0x72402628
    .word 0x26100001
    .word 0x2A020002
    .word 0x1440FFF3
    .word 0x00101100
    .word 0x8F828B60
    .word 0x3C017000
    .word 0x24060002
    .word 0x24070280
    .word 0x00021100
    .word 0x00418021
    .word 0x24080200
    .word 0x3C050008
    .word 0x72002628
    .word 0x3C090005
    .word 0x70005628
    jal func_0021E500
    .word 0x70005E28
    .word 0x2405000D
    jal func_0021C610
    .word 0x72002628
    .word 0x24050001
    jal func_0021C4A0
    .word 0x72002628
    .word 0x24070080
    .word 0x72002628
    .word 0x70002E28
    jal func_0021C810
    .word 0x70003628
    .word 0x7BBF0030
    .word 0x7BB20020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0040
}

asm void func_00221880(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    jal func_00104FA0
    .word 0x70002628
    .word 0x3C011001
    .word 0x8C22A000
    .word 0x30420100
    .word 0x1440FFFD
    .word 0x3C011001
    .word 0x3C0100C7
    jal func_002204E0
    .word 0x8C24F3D0
    .word 0x1040FFFC
    .word 0x00000000
    .word 0x3C011001
    .word 0x9026E000
    .word 0x2403FFF3
    .word 0x6405000C
    .word 0x24047FF0
    .word 0x00C31824
    .word 0x00651825
    .word 0x3C011001
    .word 0xA023E000
    .word 0x8F8586A4
    .word 0x3C011001
    .word 0x24030104
    .word 0xAC25E050
    .word 0x3C011001
    .word 0xAC24E040
    .word 0x8F8486A4
    .word 0x3C011001
    .word 0xAC24D010
    .word 0x8F8486A4
    .word 0x3C011001
    .word 0xAC24A030
    .word 0x3C011001
    .word 0xAC23A000
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}
#else
void func_00221790(void) {
    func_00117CAC();
    func_00117CAC();
    func_001043B8();
    func_001043B8();
    func_0021E500();
    func_0021C610();
    func_0021C4A0();
    func_0021C810();
}

void func_00221880(void) {
    func_00104FA0();
    func_002204E0();
}
#endif
}
