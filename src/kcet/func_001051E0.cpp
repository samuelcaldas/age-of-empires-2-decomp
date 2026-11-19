#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm u64 func_001051E0(void) {
    .word 0x27bdffe0 // 001051E0:  addiu $sp, $sp, -0x20
    .word 0xffbf0010 // 001051E4:  sd $ra, 0x10($sp)
    .word 0x03a0202d // 001051E8:  move $a0, $sp
    .word 0xafa00000 // 001051EC:  sw $zero, ($sp)
    .word 0x0c041424 // 001051F0:  jal 0x105090
    .word 0x37a50008 // 001051F4:  ori $a1, $sp, 8
    .word 0x3c021000 // 001051F8:  lui $v0, 0x1000
    .word 0x24030004 // 001051FC:  addiu $v1, $zero, 4
    .word 0x3442f000 // 00105200:  ori $v0, $v0, 0xf000
    .word 0xac430000 // 00105204:  sw $v1, ($v0)
    .word 0x3c021001 // 00105208:  lui $v0, 0x1001
    .word 0x8c42f000 // 0010520C:  lw $v0, -0x1000($v0)
    .word 0x30420004 // 00105210:  andi $v0, $v0, 4
    .word 0x14400004 // 00105214:  bnez $v0, 0x105228
    .word 0x24020004 // 00105218:  addiu $v0, $zero, 4
    .word 0x8fa20000 // 0010521C:  lw $v0, ($sp)
    .word 0x1040fff9 // 00105220:  beqz $v0, 0x105208
    .word 0x24020004 // 00105224:  addiu $v0, $zero, 4
    .word 0xdfbf0010 // 00105228:  ld $ra, 0x10($sp)
    .word 0x3c011001 // 0010522C:  lui $at, 0x1001
    .word 0xac22f000 // 00105230:  sw $v0, -0x1000($at)
    .word 0xdfa20008 // 00105234:  ld $v0, 8($sp)
    .word 0x03e00008 // 00105238:  jr $ra
    .word 0x27bd0020 // 0010523C:  addiu $sp, $sp, 0x20
}
#else
void func_00105090(u32 *a, u64 *b);

u64 func_001051E0(void) {
    u32 flag = 0;
    u64 csr;
    func_00105090(&flag, &csr);
    *(volatile u32 *)0x1000f000 = 4;
    while (!(*(volatile u32 *)0x1000f000 & 4)) {
        if (flag != 0) break;
    }
    *(volatile u32 *)0x1000f000 = 4;
    return csr;
}
#endif

}
