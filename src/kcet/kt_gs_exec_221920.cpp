#pragma exceptions off
#include "kt_gs_exec_221920.h"

extern "C" {
void func_001043C8(void);
void func_00104430(void);
void func_00104D40(void);

extern int D_004E1CA0;
extern int D_004E1CA8;
extern int D_004E1CAC;

#ifdef __MWERKS__
asm void func_00221920(void) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x8F828B60
    .word 0x3C017000
    .word 0x00021900
    .word 0x00610821
    .word 0x8C220004
    .word 0x3C017000
    .word 0x00612021
    jal func_00104430
    .word 0x30503FF0
    .word 0x3C011001
    .word 0x8C23D000
    .word 0x30630100
    .word 0x1460FFFD
    .word 0x3C011001
    .word 0x3C011001
    .word 0xAC30D080
    .word 0x3C011001
    .word 0xAC22D020
    .word 0x00021100
    .word 0x3C011001
    .word 0x8C23A030
    .word 0xAF838B68
    .word 0x3C011001
    .word 0x8C23D010
    .word 0xAF838B6C
    .word 0x3C011001
    .word 0x8C23A000
    .word 0x30630100
    .word 0x1060000F
    .word 0x3C011001
    .word 0x8F838B68
    .word 0x8F848B6C
    .word 0x54640004
    .word 0x24637FFF
    .word 0x10000005
    .word 0x34038000
    .word 0x24637FFF
    .word 0x24630001
    .word 0x00641823
    .word 0x30637FF0
    .word 0x0043082B
    .word 0x1020FFE9
    .word 0xAF838B70
    .word 0x3C011001
    .word 0x9024D001
    .word 0x2402FFFE
    .word 0x64030001
    .word 0x00821024
    .word 0x00431025
    .word 0x3C011001
    .word 0xA022D001
    .word 0x8F828B60
    .word 0x3C0100C7
    .word 0x8C24F3D0
    .word 0x0002102B
    .word 0x38420001
    .word 0x304200FF
    jal func_00104D40
    .word 0xAF828B60
    .word 0x8F828B60
    .word 0x3C017000
    .word 0x00021100
    jal func_001043C8
    .word 0x00412021
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
}
#else
void func_00221920(void) {
    func_00104430();
    func_00104D40();
    func_001043C8();
}
#endif
}
