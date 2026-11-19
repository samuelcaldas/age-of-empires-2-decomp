#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct sceDmaChan {
    volatile u32 chcr;
    volatile u32 p0[3];
    volatile u32 madr;
    volatile u32 p1[3];
    volatile u32 qwc;
    volatile u32 p2[3];
    volatile u32 tadr;
};

extern "C" {

void func_118de0(const char *fmt, ...);

#if defined(__mips__)
asm s32 func_001041C0(sceDmaChan *chan, s32 mode, s32 timeout) {
    .word 0x27bdffc0 // addiu $sp, $sp, -0x40
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0080882d // move $s1, $a0
    .word 0xffbf0030 // sd $ra, 0x30($sp)
    .word 0x00c0802d // move $s0, $a2
    .word 0x14a20005 // bne $a1, $v0, 0x1041f4
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x8e220000 // lw $v0, ($s1)
    .word 0x00021202 // srl $v0, $v0, 8
    .word 0x1000001f // b 0x10426c
    .word 0x30420001 // andi $v0, $v0, 1
    .word 0x8e220000 // lw $v0, ($s1)
    .word 0x3c030100 // lui $v1, 0x100
    .word 0x30420100 // andi $v0, $v0, 0x100
    .word 0x10400019 // beqz $v0, 0x104268
    .word 0x0070800a // movz $s0, $v1, $s0
    .word 0x3c120049 // lui $s2, 0x49
    .word 0x2610ffff // addiu $s0, $s0, -1
    .word 0x06010011 // bgez $s0, 0x104258
    .word 0x00000000 // nop
    .word 0x0c046378 // jal 0x118de0
    .word 0x2644d5e0 // addiu $a0, $s2, -0x2a20
    .word 0x8e240000 // lw $a0, ($s1)
    .word 0x00041202 // srl $v0, $a0, 8
    .word 0x30420001 // andi $v0, $v0, 1
    .word 0x1040000a // beqz $v0, 0x104258
    .word 0x00000000 // nop
    .word 0x2405feff // addiu $a1, $zero, -0x101
    .word 0x00851824 // and $v1, $a0, $a1
    .word 0x0000102d // move $v0, $zero
    .word 0x0060202d // move $a0, $v1
    .word 0x00000000 // nop
    .word 0x00000000 // nop
    .word 0x1440fffa // bnez $v0, 0x104238
    .word 0x00000000 // nop
    .word 0xae230000 // sw $v1, ($s1)
    .word 0x8e220000 // lw $v0, ($s1)
    .word 0x30420100 // andi $v0, $v0, 0x100
    .word 0x1440ffeb // bnez $v0, 0x104210
    .word 0x2610ffff // addiu $s0, $s0, -1
    .word 0x0000102d // move $v0, $zero
    .word 0xdfbf0030 // ld $ra, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0040 // addiu $sp, $sp, 0x40
}
#else
s32 func_001041C0(sceDmaChan *chan, s32 mode, s32 timeout) {
    if (mode == 1) {
        return (chan->chcr >> 8) & 1;
    }
    if (chan->chcr & 0x100) {
        if (!timeout) {
            timeout = 0x1000000;
        }
        for (timeout--; timeout >= 0; timeout--) {
            if (!(chan->chcr & 0x100)) {
                return 0;
            }
        }
        func_118de0((const char *)0x48D5E0);
        if ((chan->chcr >> 8) & 1) {
            chan->chcr &= ~0x101;
        }
    }
    return 0;
}
#endif

}
