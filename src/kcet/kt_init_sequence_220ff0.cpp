#pragma exceptions off
#include "kt_init_sequence_220ff0.h"

extern "C" {
void func_003887F0(int, int);
void func_00337D40(void);
void func_0025D430(int);
int func_0021BDD0(void);
void func_0025D060(int);
void func_00220F70(void);

extern int D_004E33E0;
extern int D_004E33E4;
extern int D_004E33E8;

#ifdef __MWERKS__
asm void func_00220FF0(void) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x24040003
    .word 0x240501EC
    jal func_003887F0
    .word 0x7FB00000
    jal func_00337D40
    .word 0x00000000
    .word 0x24040019
    .word 0x27838C20
    .word 0x10000005
    .word 0x70002E28
    .word 0x00051080
    .word 0x00621021
    .word 0x24A50001
    .word 0xAC440000
    .word 0x18A0FFFC
    .word 0x00051080
    jal func_0025D430
    .word 0x24041003
    .word 0x24040018
    .word 0x27838C24
    .word 0x10000005
    .word 0x70002E28
    .word 0x00051080
    .word 0x00621021
    .word 0x24A50001
    .word 0xAC440000
    .word 0x18A0FFFC
    .word 0x00051080
    jal func_0025D430
    .word 0x24041004
    .word 0x10000008
    .word 0x70008628
    jal func_0021BDD0
    .word 0x00000000
    .word 0x27838C28
    .word 0x00102080
    .word 0x00641821
    .word 0x26100001
    .word 0xAC620000
    .word 0x1A00FFF8
    .word 0x00000000
    jal func_0025D430
    .word 0x24041005
    jal func_0025D060
    .word 0x24041010
    jal func_00220F70
    .word 0x00000000
    jal func_0025D060
    .word 0x24041011
    jal func_00220F70
    .word 0x00000000
    jal func_0025D060
    .word 0x24041012
    jal func_00220F70
    .word 0x00000000
    jal func_0025D060
    .word 0x24041013
    jal func_00220F70
    .word 0x00000000
    jal func_0025D060
    .word 0x2404101F
    jal func_00220F70
    .word 0x00000000
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
}
#else
void func_00220FF0(void) {
    func_003887F0(3, 0x1EC);
    func_00337D40();

    D_004E33E0 = 0x19;
    func_0025D430(0x1003);

    D_004E33E4 = 0x18;
    func_0025D430(0x1004);

    D_004E33E8 = func_0021BDD0();
    func_0025D430(0x1005);

    func_0025D060(0x1010);
    func_00220F70();

    func_0025D060(0x1011);
    func_00220F70();

    func_0025D060(0x1012);
    func_00220F70();

    func_0025D060(0x1013);
    func_00220F70();

    func_0025D060(0x101F);
    func_00220F70();
}
#endif
}
