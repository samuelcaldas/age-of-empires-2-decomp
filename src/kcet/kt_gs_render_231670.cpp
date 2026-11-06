#include "kt_gs_render_231670.h"

extern "C" {
void func_0021A3F0(void);
void func_002317A0(void);
}

// func_00231670 (0x231670, size 0x40)
asm int func_00231670(void* a0, void* a1, void* a2, void* a3) {
    .word 0x3c0300cd
    .word 0x2464aac0
    .word 0x10000006
    .word 0x70002e28
    .word 0x000518c0
    .word 0x00831821
    .word 0xac600004
    .word 0x24a50001
    .word 0xac600008
    .word 0x28a3000a
    .word 0x1460fffa
    .word 0x000518c0
    .word 0x2403ffff
    .word 0x3c0100cd
    .word 0x03e00008
    .word 0xac23aac0
}

// func_002316B0 (0x2316B0, size 0x60)
asm int func_002316B0(void* a0, void* a1, void* a2, void* a3) {
    .word 0x27bdfff0
    .word 0x7fbf0000
    jal func_0021A3F0
    .word 0x70a02628
    .word 0x3c0100cd
    .word 0x8c25aac0
    .word 0x3c0300cd
    .word 0x2464aac4
    .word 0x3c0300cd
    .word 0x2463aac8
    .word 0x000528c0
    .word 0x00852021
    .word 0xac820000
    .word 0x3c0100cd
    .word 0x8c24aac0
    .word 0x000420c0
    .word 0x00641821
    .word 0xac600000
    .word 0x7bbf0000
    .word 0x03e00008
    .word 0x27bd0010
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

// func_00231710 (0x231710, size 0x50)
asm int func_00231710(void* a0, void* a1, void* a2, void* a3) {
    .word 0x3c030048
    .word 0x24643840
    .word 0x10000009
    .word 0x70003e28
    .word 0x8c830004
    .word 0x54a30005
    .word 0x24e70001
    .word 0x8c830000
    .word 0x10000006
    .word 0xacc30000
    .word 0x24e70001
    .word 0x24840008
    .word 0x28e30010
    .word 0x1460fff6
    .word 0x00000000
    .word 0x03e00008
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}

// func_00231760 (0x231760, size 0x40)
asm int func_00231760(void* a0, void* a1, void* a2, void* a3) {
    .word 0x27bdffd0
    .word 0x7fbf0010
    .word 0x7fb00000
    .word 0xafa6002c
    .word 0x27a6002c
    jal func_00231710
    .word 0x70808628
    .word 0x8fa5002c
    .word 0x72002628
    jal func_002317A0
    .word 0x70003628
    .word 0x7bbf0010
    .word 0x7bb00000
    .word 0x03e00008
    .word 0x27bd0030
    .word 0x00000000
}
