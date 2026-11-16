/* Function: func_0012D5F0 (0x0012D5F0 - 0x0012D648)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012D5F0(void *a0, void *a1) {
    .word 0x27bdffd0 // 0012D5F0:  addiu $sp, $sp, -0x30
    .word 0x24020001 // 0012D5F4:  addiu $v0, $zero, 1
    .word 0xffb10010 // 0012D5F8:  sd $s1, 0x10($sp)
    .word 0xffb00000 // 0012D5FC:  sd $s0, ($sp)
    .word 0x00a0882d // 0012D600:  move $s1, $a1
    .word 0x838384e8 // 0012D604:  lb $v1, -0x7b18($gp)
    .word 0x0080802d // 0012D608:  move $s0, $a0
    .word 0xffbf0020 // 0012D60C:  sd $ra, 0x20($sp)
    .word 0x14600007 // 0012D610:  bnez $v1, 0x12d630
    .word 0xaf828840 // 0012D614:  sw $v0, -0x77c0($gp)
    .word 0x0c043b28 // 0012D618:  jal 0x10eca0
    .word 0x0200202d // 0012D61C:  move $a0, $s0
    .word 0x1040fffd // 0012D620:  beqz $v0, 0x12d618
    .word 0x00000000 // 0012D624:  nop 
    .word 0x0c043c5e // 0012D628:  jal 0x10f178
    .word 0x0220202d // 0012D62C:  move $a0, $s1
    .word 0x8f828840 // 0012D630:  lw $v0, -0x77c0($gp)
    .word 0xdfbf0020 // 0012D634:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012D638:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012D63C:  ld $s0, ($sp)
    .word 0x03e00008 // 0012D640:  jr $ra
    .word 0x27bd0030 // 0012D644:  addiu $sp, $sp, 0x30
}
#else

extern s8 D_004E2CA8;
extern s32 D_004E3000;

s32 func_0043B280(void *);
void func_0043C5E0(void *);

s32 func_0012D5F0(void *a0, void *a1) {
    D_004E3000 = 1;
    if (D_004E2CA8 == 0) {
        while (func_0043B280(a0) == 0) {
        }
        func_0043C5E0(a1);
    }
    return D_004E3000;
}

#endif

}
