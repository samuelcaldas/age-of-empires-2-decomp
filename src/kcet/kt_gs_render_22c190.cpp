#include "kt_gs_render_22c190.h"

extern "C" {
void func_002273A0(void);
void func_00100670(void);
void func_002272A0(void);
void func_00227C20(void);
void func_00117CAC(void);
void func_001CF9B0(void);
void func_0022C6C0(void);
void func_001CC6E0(void);
}

// func_0022C190 (0x22C190, size 0x60)
asm void func_0022C190(void* a0) {
    .word 0x27bdffd0
    .word 0x7fbf0020
    .word 0x7fb10010
    .word 0x7fb00000
    .word 0x70808e28
    .word 0x1220000c
    .word 0x70a08628
    .word 0x3c02004e
    .word 0x2442aec0
    .word 0xae220034
    jal func_002273A0
    .word 0x70002e28
    .word 0x0010143c
    .word 0x0002143f
    .word 0x18400004
    .word 0x72201628
    jal func_00100670
    .word 0x72202628
    .word 0x72201628
    .word 0x7bbf0020
    .word 0x7bb10010
    .word 0x7bb00000
    .word 0x03e00008
    .word 0x27bd0030
}

// func_0022C1F0 (0x22C1F0, size 0x90)
asm void func_0022C1F0(void* a0, void* a1, void* a2) {
    .word 0x27bdffd0
    .word 0x7fbf0020
    .word 0x7fb10010
    .word 0x7fb00000
    .word 0x70e08628
    .word 0x24070001
    jal func_002272A0
    .word 0x70808e28
    .word 0x3c02004e
    .word 0x2442aed0
    .word 0xae220034
    .word 0x3c023f80
    .word 0x1200000d
    .word 0xae220020
    .word 0x26250038
    .word 0x24040287
    .word 0x8e030000
    .word 0x8e020004
    .word 0x2484ffff
    .word 0xaca30000
    .word 0xaca20004
    .word 0x26100008
    .word 0x1c80fff9
    .word 0x24a50008
    .word 0x10000004
    .word 0x72201628
    .word 0xae201454
    .word 0xa2201458
    .word 0x72201628
    .word 0x7bbf0020
    .word 0x7bb10010
    .word 0x7bb00000
    .word 0x03e00008
    .word 0x27bd0030
    .word 0x00000000
    .word 0x00000000
}

// func_0022C280 (0x22C280, size 0xB0)
asm int func_0022C280(void* a0) {
    .word 0x27bdffd0
    .word 0x7fbf0020
    .word 0x7fb00010
    jal func_00227C20
    .word 0x70808628
    .word 0x8e030010
    .word 0x8e020014
    .word 0x8e040024
    .word 0x240500fe
    jal func_00117CAC
    .word 0x00623018
    .word 0x24020001
    .word 0xffa20000
    .word 0xffa00008
    .word 0x8e030010
    .word 0x8e020014
    .word 0x8e040008
    .word 0x920b1458
    .word 0x70002e28
    .word 0x70003628
    .word 0x2463ffff
    .word 0x2442ffff
    .word 0x00034c3c
    .word 0x0002543c
    .word 0x70003e28
    .word 0x00094c3f
    .word 0x000a543f
    jal func_001CF9B0
    .word 0x70004628
    jal func_0022C6C0
    .word 0x72002628
    .word 0x8e040008
    .word 0x8e070010
    .word 0x8e080014
    .word 0x92091458
    .word 0x70002e28
    jal func_001CC6E0
    .word 0x70003628
    .word 0x7bbf0020
    .word 0x7bb00010
    .word 0x24020001
    .word 0x03e00008
    .word 0x27bd0030
    .word 0x00000000
}
