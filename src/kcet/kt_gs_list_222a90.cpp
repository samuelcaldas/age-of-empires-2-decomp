#include "kt_gs_list_222a90.h"

extern "C" {
void func_117CAC(void *dst, int val, int size);
void func_00222B40(void *ptr);
void func_00222BA0(void *ptr);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void *func_00222A90(void) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x3C0100C9
    .word 0x8C302D48
    .word 0x70001628
    .word 0x3C0100C9
    .word 0x94242D42
    .word 0x00000000
    .word 0x92030000
    .word 0x5460000A
    .word 0x2484FFFF
    .word 0x24060014
    .word 0x72002628
    jal func_117CAC
    .word 0x70002E28
    .word 0x24020001
    .word 0xA2020000
    .word 0x10000004
    .word 0x72001628
    .word 0x2484FFFF
    .word 0x1480FFF3
    .word 0x26100014
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
}

asm void func_00222B00(void *ptr) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x70808628
    .word 0x12000007
    .word 0x00000000
    .word 0x92030010
    .word 0x10600004
    .word 0x00000000
    jal func_00222B40
    .word 0x00000000
    .word 0xA2000010
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0020
}

asm void func_00222B40(void *ptr) {
    .word 0x27BDFFD0
    .word 0x7FBF0020
    .word 0x7FB10010
    .word 0x70808E28
    .word 0x1220000B
    .word 0x7FB00000
    .word 0x10000006
    .word 0x8E300028
    jal func_00222BA0
    .word 0x72002628
    .word 0xA2000000
    .word 0x8E100008
    .word 0x00000000
    .word 0x1600FFFA
    .word 0x00000000
    .word 0xAE200028
    .word 0x7BBF0020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0030
}

asm void func_00222BA0(void *ptr) {
    .word 0x10800009
    .word 0x00000000
    .word 0x10000004
    .word 0x8C830004
    .word 0xA0600000
    .word 0x8C630008
    .word 0x00000000
    .word 0x1460FFFC
    .word 0x00000000
    .word 0xAC800004
    .word 0x03E00008
    .word 0x00000000
}

asm void func_00222BD0(void *ptr) {
    .word 0x10000004
    .word 0x00000000
    .word 0xA0800000
    .word 0x8C840008
    .word 0x00000000
    .word 0x1480FFFC
    .word 0x00000000
    .word 0x03E00008
    .word 0x00000000
}

asm void func_00222C00(void *ptr, char val) {
    .word 0x03E00008
    .word 0xA085002C
}
#else
void *func_00222A90(void) {
    return (void *)0;
}

void func_00222B00(void *ptr) {
}

void func_00222B40(void *ptr) {
}

void func_00222BA0(void *ptr) {
}

void func_00222BD0(void *ptr) {
}

void func_00222C00(void *ptr, char val) {
}
#endif
}
