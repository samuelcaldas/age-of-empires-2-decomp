#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm int func_0012E320(void) {
    .word 0x3c030050 // 0012E320:  lui $v1, 0x50
    .word 0x0000202d // 0012E324:  move $a0, $zero
    .word 0x8c6297d8 // 0012E328:  lw $v0, -0x6828($v1)
    .word 0x10400002 // 0012E32C:  beqz $v0, 0x12e338
    .word 0x246597d8 // 0012E330:  addiu $a1, $v1, -0x6828
    .word 0x8ca40004 // 0012E334:  lw $a0, 4($a1)
    .word 0x03e00008 // 0012E338:  jr $ra
    .word 0x0080102d // 0012E33C:  move $v0, $a0
}
#else

struct TargetTable {
    void *base;
    int count;
};

extern TargetTable D_004F97D8;

int func_0012E320(void) {
    if (D_004F97D8.base == 0) {
        return 0;
    }
    return D_004F97D8.count;
}

#endif

}
