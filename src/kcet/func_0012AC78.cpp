#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012AC78(void) {
    .word 0x27bdffc0 // addiu $sp, $sp, -0x40
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0030 // sd $ra, 0x30($sp)
    .word 0x2450d300 // addiu $s0, $v0, -0x2d00
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x8e050040 // lw $a1, 0x40($s0)
    .word 0x04a20006 // bltzl $a1, 0x12acb4
    .word 0x26100034 // addiu $s0, $s0, 0x34
    .word 0x0c04d37a // jal 0x134de8
    .word 0x24040003 // addiu $a0, $zero, 3
    .word 0x2403ffff // addiu $v1, $zero, -1
    .word 0xae030040 // sw $v1, 0x40($s0)
    .word 0x26100034 // addiu $s0, $s0, 0x34
    .word 0x0000882d // move $s1, $zero
    .word 0x2412ffff // addiu $s2, $zero, -1
    .word 0x00000000 // nop
    .word 0x8e020000 // lw $v0, ($s0)
    .word 0x26310001 // addiu $s1, $s1, 1
    .word 0x04400003 // bltz $v0, 0x12acd8
    .word 0x0040202d // move $a0, $v0
    .word 0x0c04d130 // jal 0x1344c0
    .word 0x00000000 // nop
    .word 0xae120000 // sw $s2, ($s0)
    .word 0x2e220002 // sltiu $v0, $s1, 2
    .word 0x1440fff7 // bnez $v0, 0x12acc0
    .word 0x26100004 // addiu $s0, $s0, 4
    .word 0xdfbf0030 // ld $ra, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0040 // addiu $sp, $sp, 0x40
}
#else

struct CdvdServerData {
    u8 pad[0x34];
    s32 sem[2];
    s32 f_3c;
    s32 f_40;
};
extern CdvdServerData D_004ED300;

void func_00134DE8(s32);
void func_001344C0(s32);

void func_0012AC78(void) {
    if (D_004ED300.f_40 >= 0) {
        func_00134DE8(3);
        D_004ED300.f_40 = -1;
    }
    for (s32 i = 0; i < 2; i++) {
        s32 sem = D_004ED300.sem[i];
        if (sem >= 0) {
            func_001344C0(sem);
        }
        D_004ED300.sem[i] = -1;
    }
}

#endif

}
