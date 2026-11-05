#include "kt_gs_render_225600.h"

extern "C" {
void func_00116F68(void);
void func_00116F40(void);
int func_0011ACD0(void *);
void func_0011B170(void *, void *, int);

#if defined(__MWERKS__) && defined(__MIPS__)
// func_00225600: 0x00225600 - 0x00225620 (0x020 bytes)
asm int func_00225600(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    jal func_00116F68
    .word 0x00000000
    .word 0x7BBF0000
    .word 0x70001628
    .word 0x03E00008
    .word 0x27BD0010
}

// func_00225620: 0x00225620 - 0x00225650 (0x030 bytes)
asm void func_00225620(void *p0, void *p1) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x7FB00000
    jal func_00116F68
    .word 0x70A08628
    jal func_00116F40
    .word 0x72002628
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
    .word 0x00000000
}

// func_00225650: 0x00225650 - 0x00225660 (0x010 bytes)
asm int func_00225650(void) {
    .word 0x03E00008
    .word 0x24020001
    .word 0x00000000
    .word 0x00000000
}

// func_00225660: 0x00225660 - 0x00225750 (0x0F0 bytes)
asm int func_00225660(void *p0, int p1, void *p2, int p3) {
    .word 0x27BDFFB0
    .word 0x7FBF0040
    .word 0x7FB30030
    .word 0x7FB20020
    .word 0x7FB10010
    .word 0x70C09628
    .word 0x3C020048
    .word 0x7FB00000
    .word 0x24061418
    .word 0x2443BF80
    .word 0x70E08E28
    .word 0x70008628
    .word 0x10000012
    .word 0x70002628
    .word 0x00861021
    .word 0x00023843
    .word 0x00071040
    .word 0x00621021
    .word 0x94420000
    .word 0x0045082B
    .word 0x10200003
    .word 0x00A2082B
    .word 0x24E40001
    .word 0x00A2082B
    .word 0x10200002
    .word 0x00000000
    .word 0x24E6FFFF
    .word 0x14450004
    .word 0x00C4082A
    .word 0x10000004
    .word 0x24100001
    .word 0x00C4082A
    .word 0x1020FFEE
    .word 0x00861021
    .word 0x1200000F
    .word 0x00000000
    .word 0x3C020048
    .word 0x2442E7C0
    .word 0x00071880
    .word 0x00439821
    jal func_0011ACD0
    .word 0x8E640000
    .word 0x8E650000
    .word 0x70408628
    .word 0x72402628
    jal func_0011B170
    .word 0x72203628
    .word 0x02321021
    .word 0x10000002
    .word 0xA040FFFF
    .word 0xA2400000
    .word 0x72001628
    .word 0x7BBF0040
    .word 0x7BB30030
    .word 0x7BB20020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0050
    .word 0x00000000
}

// func_00225750: 0x00225750 - 0x00225760 (0x010 bytes)
asm void func_00225750(void) {
    .word 0x03E00008
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

// func_00225760: 0x00225760 - 0x002257A0 (0x040 bytes)
asm int func_00225760(int p0) {
    .word 0x24020020
    .word 0x10820008
    .word 0x24020001
    .word 0x2C820009
    .word 0x14400008
    .word 0x70001628
    .word 0x2C81000E
    .word 0x10200004
    .word 0x00000000
    .word 0x24020001
    .word 0x10000002
    .word 0x00000000
    .word 0x70001628
    .word 0x03E00008
    .word 0x00000000
    .word 0x00000000
}

// func_002257A0: 0x002257A0 - 0x002257C0 (0x020 bytes)
asm int func_002257A0(void *p0, int p1) {
    .word 0x10800003
    .word 0x70001628
    .word 0x8C82009C
    .word 0xAC85009C
    .word 0x03E00008
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

// func_002257C0: 0x002257C0 - 0x00225820 (0x060 bytes)
asm int func_002257C0(int p0, int p1) {
    .word 0x04810002
    .word 0x00000000
    .word 0x70002628
    .word 0x04A10003
    .word 0x28810275
    .word 0x70002E28
    .word 0x28810275
    .word 0x14200003
    .word 0x28A101B0
    .word 0x24040274
    .word 0x28A101B0
    .word 0x14200002
    .word 0x00000000
    .word 0x240501AF
    .word 0x3C0100C6
    .word 0xAC24E840
    .word 0x3C0100C6
    .word 0x24020001
    .word 0x03E00008
    .word 0xAC25E844
    j func_002257C0
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

#else
int func_00225600(void) { return 0; }
void func_00225620(void *p0, void *p1) {}
int func_00225650(void) { return 0; }
int func_00225660(void *p0, int p1, void *p2, int p3) { return 0; }
void func_00225750(void) {}
int func_00225760(int p0) { return 0; }
int func_002257A0(void *p0, int p1) { return 0; }
int func_002257C0(int p0, int p1) { return 0; }
#endif
}
