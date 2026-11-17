#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

void* func_00110940(void);
void func_00130440(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5);
void func_001304D0(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5);

#if defined(__mips__)
asm void func_001303A8(void* a0, void* a1, void* a2, void* a3, void* a4) {
    .word 0x27bdffa0 // addiu $sp, $sp, -0x60
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x00c0902d // move $s2, $a2
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x00a0882d // move $s1, $a1
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0x0080802d // move $s0, $a0
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x0100a02d // move $s4, $t0
    .word 0xffbf0050 // sd $ra, 0x50($sp)
    .word 0x0c044250 // jal 0x110940
    .word 0x00e0982d // move $s3, $a3
    .word 0x0040202d // move $a0, $v0
    .word 0x3c020050 // lui $v0, 0x50
    .word 0x8c4397fc // lw $v1, -0x6804($v0)
    .word 0x14600008 // bnez $v1, 0x13040c
    .word 0x0200282d // move $a1, $s0
    .word 0x0220302d // move $a2, $s1
    .word 0x0240382d // move $a3, $s2
    .word 0x0260402d // move $t0, $s3
    .word 0x0c04c110 // jal 0x130440
    .word 0x0280482d // move $t1, $s4
    .word 0x10000007 // b 0x130424
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0x0220302d // move $a2, $s1
    .word 0x0240382d // move $a3, $s2
    .word 0x0260402d // move $t0, $s3
    .word 0x0c04c134 // jal 0x1304d0
    .word 0x0280482d // move $t1, $s4
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0060 // addiu $sp, $sp, 0x60
}
#else
extern s32 D_004F97FC;

void func_001303A8(void* a0, void* a1, void* a2, void* a3, void* a4) {
    void* v0 = func_00110940();
    if (D_004F97FC != 0) {
        func_001304D0(v0, a0, a1, a2, a3, a4);
    } else {
        func_00130440(v0, a0, a1, a2, a3, a4);
    }
}
#endif

}
