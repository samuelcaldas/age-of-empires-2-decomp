#include "kt_gs_step_222180.h"

extern "C" {
void func_002240B0(void);
void func_002249C0(void);
void func_00224B30(void);
void func_0025D060(void);
void func_01DE9900(void);
void func_01DE9B00(void);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void func_00222180(void) {
    .word 0xA7848B4A
    .word 0x03E00008
    .word 0xA7808B4C
}

asm void func_00222190(void) {
    .word 0xA7808B48
    .word 0xA7808B4A
    .word 0x03E00008
    .word 0xA7808B4C
}

asm void func_002221A0(void) {
    .word 0x27BDFFE0
    .word 0x7FBF0010
    .word 0x7FB00000
    .word 0x87848B4A
    .word 0x24060011
    .word 0x1086003C
    .word 0x00000000
    .word 0x24020010
    .word 0x10820034
    .word 0x00000000
    .word 0x2403000C
    .word 0x10830027
    .word 0x3C0201D9
    .word 0x2402000B
    .word 0x10820021
    .word 0x00000000
    .word 0x24020009
    .word 0x10820017
    .word 0x00000000
    .word 0x24020008
    .word 0x1082000D
    .word 0x00000000
    .word 0x10800004
    .word 0x24042009
    .word 0x1000002C
    .word 0x7BBF0010
    .word 0x24042009
    jal func_0025D060
    .word 0x00000000
    jal func_0025D060
    .word 0x24042008
    .word 0x24020008
    .word 0x10000023
    .word 0xA7828B4A
    .word 0x3C020039
    .word 0x24452E40
    jal func_002249C0
    .word 0x70002628
    .word 0x24020009
    .word 0x1000001C
    .word 0xA7828B4A
    jal func_00224B30
    .word 0x00000000
    .word 0x10400018
    .word 0x00000000
    .word 0x2402000B
    .word 0x10000015
    .word 0xA7828B4A
    .word 0x10000013
    .word 0xA7838B4A
    .word 0x3C0201D9
    .word 0x34508000
    .word 0x3C020049
    .word 0x24442F18
    jal func_002240B0
    .word 0x72002E28
    .word 0x1040FFFB
    .word 0x00000000
    .word 0x24020010
    .word 0x10000008
    .word 0xA7828B4A
    jal func_01DE9900
    .word 0x00000000
    .word 0x24020011
    .word 0x10000003
    .word 0xA7828B4A
    jal func_01DE9B00
    .word 0x00000000
    .word 0x7BBF0010
    .word 0x7BB00000
    .word 0x70001628
    .word 0x03E00008
    .word 0x27BD0020
}
#else
void func_00222180(void) {
}

void func_00222190(void) {
}

void func_002221A0(void) {
}
#endif
}
