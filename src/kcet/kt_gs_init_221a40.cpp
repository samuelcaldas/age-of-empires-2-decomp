#include "kt_gs_init_221a40.h"

extern "C" {
void func_00103920(int);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void func_00221A40(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    jal func_00103920
    .word 0x24040002
    jal func_00103920
    .word 0x24040008
    .word 0x3C011001
    .word 0x9024E000
    .word 0x24030003
    .word 0x0004273C
    .word 0x000427BE
    .word 0x14830011
    .word 0x00000000
    .word 0x3C011001
    .word 0x8C23D000
    .word 0x30630100
    .word 0x1460FFFD
    .word 0x3C011001
    .word 0x3C011001
    .word 0x8C24D010
    .word 0x3C011001
    .word 0x8C25A030
    .word 0x3C011001
    .word 0x8C23A000
    .word 0x30630100
    .word 0x10600003
    .word 0x00000000
    .word 0x1485FFF7
    .word 0x3C011001
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}

asm void func_00221AC0(void) {
    .word 0x27BDFFF0
    .word 0x7FBF0000
    .word 0x3C011001
    .word 0x9025E000
    .word 0x24030003
    .word 0x0005273C
    .word 0x000427BE
    .word 0x1483001A
    .word 0x00000000
    .word 0x3C011001
    .word 0x9024A001
    .word 0x24030001
    .word 0x30840001
    .word 0x10830009
    .word 0x00000000
    .word 0x30030003
    .word 0x00032080
    .word 0x2403FFF3
    .word 0x00A31824
    .word 0x00641825
    .word 0x3C011001
    .word 0x1000000C
    .word 0xA023E000
    jal func_00221A40
    .word 0xAF838B64
    .word 0x3C011001
    .word 0x9025E000
    .word 0x30030003
    .word 0x00032080
    .word 0x2403FFF3
    .word 0x00A31824
    .word 0x00641825
    .word 0x3C011001
    .word 0xA023E000
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
}
#else
void func_00221A40(void) {
    func_00103920(2);
    func_00103920(8);
}

void func_00221AC0(void) {
}
#endif
}
