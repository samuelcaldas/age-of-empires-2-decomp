#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void *func_0012E2F0(int a0) {
    .word 0x3c060050 // 0012E2F0:  lui $a2, 0x50
    .word 0x24c397d8 // 0012E2F4:  addiu $v1, $a2, -0x6828
    .word 0x8c620004 // 0012E2F8:  lw $v0, 4($v1)
    .word 0x0082102a // 0012E2FC:  slt $v0, $a0, $v0
    .word 0x10400004 // 0012E300:  beqz $v0, 0x12e314
    .word 0x0000282d // 0012E304:  move $a1, $zero
    .word 0x8cc397d8 // 0012E308:  lw $v1, -0x6828($a2)
    .word 0x00041100 // 0012E30C:  sll $v0, $a0, 4
    .word 0x00622821 // 0012E310:  addu $a1, $v1, $v0
    .word 0x03e00008 // 0012E314:  jr $ra
    .word 0x00a0102d // 0012E318:  move $v0, $a1
}
#else

struct TargetTable {
    u8 *base;
    int count;
};

extern TargetTable D_004F97D8;

void *func_0012E2F0(int idx) {
    if (idx < D_004F97D8.count) {
        return D_004F97D8.base + (idx * 16);
    }
    return 0;
}

#endif

}
