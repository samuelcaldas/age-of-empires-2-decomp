#include "kt_gs_render_2240b0.h"

extern "C" {
void *func_0011ABBC(void *, void *);
void *func_0011A7BC(void *, void *);
int func_0012C1D0(void *, void *, void *);
void func_00100270(void *, void *);
void func_117CAC(void *, int, int);

#if defined(__MWERKS__) && defined(__MIPS__)
asm int func_002240B0(void *p0, void *p1) {
    .word 0x27BDFF60
    .word 0x7FBF0030
    .word 0x7FB20020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x24020030
    .word 0xA3A20040
    .word 0xA3A00041
    .word 0xA3A00042
    .word 0x70A08E28
    .word 0x3C020049
    .word 0x27B00044
    .word 0x70809628
    .word 0x24452F28
    .word 0x72002628
    jal func_0011ABBC
    .word 0xA3A00043
    .word 0x72002628
    jal func_0011A7BC
    .word 0x72402E28
    .word 0x27A40040
    .word 0x27A60080
    jal func_0012C1D0
    .word 0x72202E28
    .word 0x1040FFFC
    .word 0x27A40040
    .word 0x8FA30080
    .word 0x24020001
    .word 0x1462FFF7
    .word 0x00000000
    .word 0x8FA40090
    jal func_00100270
    .word 0x72202E28
    .word 0x7BBF0030
    .word 0x7BB20020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x24020001
    .word 0x03E00008
    .word 0x27BD00A0
}

asm void func_00224150(void) {
    .word 0x3C0200CA
    .word 0x244417E0
    .word 0x24060010
    j func_117CAC
    .word 0x70002E28
}

asm void func_00224170(void) {
    .word 0x27BDFFF0
    .word 0x3C0200CA
    .word 0x244417E0
    .word 0x24060010
    .word 0x7FBF0000
    jal func_117CAC
    .word 0x70002E28
    .word 0x3C0100CA
    .word 0x802717EC
    .word 0x2405FFFE
    .word 0x64060001
    .word 0x2403FFEF
    .word 0x00E52824
    .word 0x00A62825
    .word 0x3C0100CA
    .word 0xA02517EC
    .word 0x3C0100CA
    .word 0x802517EC
    .word 0x64040010
    .word 0x00A31824
    .word 0x00641825
    .word 0x3C0100CA
    .word 0xA02317EC
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}

asm int func_002241E0(void) {
    .word 0x3C0100CA
    .word 0x802217EC
    .word 0x000217FC
    .word 0x03E00008
    .word 0x000217FF
}

asm void func_00224200(int p0) {
    .word 0x3C0100CA
    .word 0x802717EC
    .word 0x30830001
    .word 0x00031E3C
    .word 0x00031E3F
    .word 0x2405FFFB
    .word 0x30630001
    .word 0x00033080
    .word 0x00E52824
    .word 0x00A62825
    .word 0x3C0100CA
    .word 0xA02517EC
    .word 0x3C0100CA
    .word 0x802517EC
    .word 0x2403FFEF
    .word 0x64040010
    .word 0x00A31824
    .word 0x00641825
    .word 0x3C0100CA
    .word 0x03E00008
    .word 0xA02317EC
}

asm void func_00224260(void) {
    .word 0x3C0100CA
    .word 0x802517EC
    .word 0x2403FFEF
    .word 0x64040010
    .word 0x00A31824
    .word 0x00641825
    .word 0x3C0100CA
    .word 0x03E00008
    .word 0xA02317EC
}

asm void func_00224290(int p0) {
    .word 0x30830001
    .word 0x3C0100CA
    .word 0x00031E3C
    .word 0x802517EC
    .word 0x00031E3F
    .word 0x30630001
    .word 0x000320C0
    .word 0x2403FFF7
    .word 0x00A31824
    .word 0x00641825
    .word 0x3C0100CA
    .word 0x03E00008
    .word 0xA02317EC
}

asm void func_002242D0(void) {
    .word 0x3C0100CA
    .word 0x802517EC
    .word 0x2403FFDF
    .word 0x64040020
    .word 0x00A31824
    .word 0x00641825
    .word 0x3C0100CA
    .word 0x03E00008
    .word 0xA02317EC
}

asm void func_00224300(int p0) {
    .word 0x3C0100CA
    .word 0x03E00008
    .word 0xAC2417E0
}
#else
int func_002240B0(void *p0, void *p1) {
    return 0;
}

void func_00224150(void) {
}

void func_00224170(void) {
}

int func_002241E0(void) {
    return 0;
}

void func_00224200(int p0) {
}

void func_00224260(void) {
}

void func_00224290(int p0) {
}

void func_002242D0(void) {
}

void func_00224300(int p0) {
}
#endif
}
