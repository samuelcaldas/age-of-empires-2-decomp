#pragma exceptions off

typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_00104358(u32 *p) {
    .word 0x3c021000 // 00104358:  lui $v0, 0x1000
    .word 0x0080282d // 0010435C:  move $a1, $a0
    .word 0x3442f520 // 00104360:  ori $v0, $v0, 0xf520
    .word 0x8c430000 // 00104364:  lw $v1, ($v0)
    .word 0x14600004 // 00104368:  bnez $v1, 0x10437c
    .word 0x3c021000 // 0010436C:  lui $v0, 0x1000
    .word 0x24031000 // 00104370:  addiu $v1, $zero, 0x1000
    .word 0x3442f590 // 00104374:  ori $v0, $v0, 0xf590
    .word 0xac430000 // 00104378:  sw $v1, ($v0)
    .word 0x8ca20000 // 0010437C:  lw $v0, ($a1)
    .word 0x3c03ffff // 00104380:  lui $v1, 0xffff
    .word 0x3463feff // 00104384:  ori $v1, $v1, 0xfeff
    .word 0x3c041000 // 00104388:  lui $a0, 0x1000
    .word 0x00431824 // 0010438C:  and $v1, $v0, $v1
    .word 0x3484f590 // 00104390:  ori $a0, $a0, 0xf590
    .word 0xaca30000 // 00104394:  sw $v1, ($a1)
    .word 0x03e00008 // 00104398:  jr $ra
    .word 0xac800000 // 0010439C:  sw $zero, ($a0)
}
#else
void func_00104358(u32 *p) {
    volatile u32 *d_enabler = (volatile u32 *)0x1000F520;
    volatile u32 *d_enablew = (volatile u32 *)0x1000F590;

    if (*d_enabler == 0) {
        *d_enablew = 0x1000;
    }
    *p &= ~0x101;
    *d_enablew = 0;
}
#endif

}
