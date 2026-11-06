#include "kt_gs_render_229af0.h"

extern "C" {
int func_00100850(int);
int func_00236F50(void*, void*, void*);
int func_0022C1F0(void*, void*, void*);
int func_0022CF90(void*, void*, void*, int);
int func_0022B2B0(void*, void*, void*);
void func_00227480(void);
void func_002276D0(void*);
void func_00227830(void*);
void func_00227900(void*, void*);
}

// func_00229AF0 (0x229AF0, size 0x0D0)
asm void func_00229AF0(void* a0) {
    .word 0x27bdffe0
    .word 0x7fbf0010
    .word 0x7fb00000
    .word 0x70808628
    jal func_00100850
    .word 0x24041778
    .word 0x10400007
    .word 0x24041470
    .word 0x8e050008
    .word 0x2607147c
    .word 0x70402628
    jal func_00236F50
    .word 0x72003628
    .word 0x24041470
    jal func_00100850
    .word 0x00000000
    .word 0x10400007
    .word 0x24041c4c
    .word 0x8e050008
    .word 0x26070044
    .word 0x70402628
    jal func_0022C1F0
    .word 0x72003628
    .word 0x24041c4c
    jal func_00100850
    .word 0x00000000
    .word 0x10400009
    .word 0x24040fb8
    .word 0x8e050008
    .word 0x8e070038
    .word 0x26082bb8
    .word 0x24090001
    .word 0x70402628
    jal func_0022CF90
    .word 0x72003628
    .word 0x24040fb8
    jal func_00100850
    .word 0x00000000
    .word 0x10400007
    .word 0x72002628
    .word 0x8e050008
    .word 0x26074798
    .word 0x70402628
    jal func_0022B2B0
    .word 0x72003628
    .word 0x72002628
    jal func_00227480
    .word 0x00000000
    .word 0x7bbf0010
    .word 0x7bb00000
    .word 0x03e00008
    .word 0x27bd0020
}

// func_00229BC0 (0x229BC0, size 0x090)
asm int func_00229BC0(void* a0, void* a1, int a2, int a3, void* t0, void* t1) {
    .word 0x27bdffd0
    .word 0x7fbf0020
    .word 0x7fb10010
    .word 0x7fb00000
    .word 0xac860038
    .word 0x30e200ff
    .word 0xac82003c
    .word 0x71208628
    .word 0xac880040
    jal func_00227900
    .word 0x70808e28
    jal func_002276D0
    .word 0x72202628
    .word 0x8e390034
    .word 0x72002e28
    .word 0x8f390010
    .word 0x0320f809
    .word 0x72202628
    .word 0x8e390034
    .word 0x8f390014
    .word 0x0320f809
    .word 0x72202628
    .word 0x8e390034
    .word 0x8f390018
    .word 0x0320f809
    .word 0x72202628
    .word 0x8e390034
    .word 0x8f39001c
    .word 0x0320f809
    .word 0x72202628
    .word 0x7bbf0020
    .word 0x7bb10010
    .word 0x7bb00000
    .word 0x24020001
    .word 0x03e00008
    .word 0x27bd0030
}

// func_00229C50 (0x229C50, size 0x080)
asm void func_00229C50(void* a0) {
    .word 0x27bdffe0
    .word 0x7fbf0010
    .word 0x7fb00000
    .word 0x2402ffff
    .word 0xac800038
    .word 0xac82003c
    .word 0x70808628
    .word 0x10000008
    .word 0xac800040
    .word 0x8c440000
    .word 0x10800005
    .word 0x00000000
    .word 0x8c990034
    .word 0x8f390008
    .word 0x0320f809
    .word 0x24050001
    .word 0x8e020004
    .word 0x1440fff7
    .word 0x00000000
    jal func_00227830
    .word 0x72002628
    .word 0x72002628
    jal func_00227900
    .word 0x70002e28
    .word 0x7bbf0010
    .word 0x7bb00000
    .word 0x70001628
    .word 0x03e00008
    .word 0x27bd0020
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}
