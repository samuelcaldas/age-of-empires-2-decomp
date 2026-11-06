#include "kt_gs_render_231d60.h"

extern "C" {
char* strcpy(char*, const char*);
int func_00231920(void* a0, void* a1, void* a2, void* a3);
int func_002323A0(void* a0, void* a1, void* a2, void* a3);
}

// func_00231D60 (0x231D60, size 0xD0)
asm int func_00231D60(void* a0, void* a1, void* a2, void* a3) {
    .word 0x27bdff60
    .word 0x7fbf0020
    .word 0x7fb10010
    .word 0x7fb00000
    .word 0x70808e28
    .word 0x70a08628
    .word 0x3c020048
    .word 0x24453a10
    .word 0x27a60030
    .word 0x24040003
    .word 0x78a30000
    .word 0x78a20010
    .word 0x2484ffff
    .word 0x7cc30000
    .word 0x7cc20010
    .word 0x24a50020
    .word 0x1c80fff9
    .word 0x24c60020
    .word 0xc4a20000
    .word 0x72202628
    .word 0x27a50030
    jal func_00231920
    .word 0xe4c20000
    .word 0x14400004
    .word 0x27a50030
    .word 0x10000012
    .word 0x70001628
    .word 0x27a50030
    jal func_002323A0
    .word 0x72202628
    .word 0x1040000a
    .word 0x27a50030
    .word 0x90430064
    .word 0x14600006
    .word 0x00000000
    .word 0x3c010003
    .word 0x02210821
    .word 0xac228854
    .word 0x10000005
    .word 0x70001628
    .word 0x27a50030
    jal strcpy
    .word 0x72002628
    .word 0x24020001
    .word 0x7bbf0020
    .word 0x7bb10010
    .word 0x7bb00000
    .word 0x03e00008
    .word 0x27bd00a0
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
}
