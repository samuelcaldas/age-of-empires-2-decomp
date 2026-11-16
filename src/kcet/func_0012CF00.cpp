/* Function: func_0012CF00 (0x0012CF00 - 0x0012CF54)
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
asm void *func_0012CF00(s32 a0) {
    .word 0x27bdffe0 // 0012cf00:  addiu $sp, $sp, -0x20
    .word 0xffb00000 // 0012cf04:  sd $s0, ($sp)
    .word 0x0080802d // 0012cf08:  move $s0, $a0
    .word 0x2e020004 // 0012cf0c:  sltiu $v0, $s0, 4
    .word 0x14400007 // 0012cf10:  bnez $v0, 0x12cf30
    .word 0xffbf0010 // 0012cf14:  sd $ra, 0x10($sp)
    .word 0x3c040049 // 0012cf18:  lui $a0, 0x49
    .word 0x3c060049 // 0012cf1c:  lui $a2, 0x49
    .word 0x2484fea0 // 0012cf20:  addiu $a0, $a0, -0x160
    .word 0x24c6feb0 // 0012cf24:  addiu $a2, $a2, -0x150
    .word 0x0c0450c8 // 0012cf28:  jal 0x114320
    .word 0x2405016a // 0012cf2c:  addiu $a1, $zero, 0x16a
    .word 0x3c020039 // 0012cf30:  lui $v0, 0x39
    .word 0x00101880 // 0012cf34:  sll $v1, $s0, 2
    .word 0x2442c7f8 // 0012cf38:  addiu $v0, $v0, -0x3808
    .word 0xdfbf0010 // 0012cf3c:  ld $ra, 0x10($sp)
    .word 0x00621821 // 0012cf40:  addu $v1, $v1, $v0
    .word 0xdfb00000 // 0012cf44:  ld $s0, ($sp)
    .word 0x8c620000 // 0012cf48:  lw $v0, ($v1)
    .word 0x03e00008 // 0012cf4c:  jr $ra
    .word 0x27bd0020 // 0012cf50:  addiu $sp, $sp, 0x20
}
#else

extern const char D_48FEA0[];
extern const char D_48FEB0[];
extern void *D_38C7F8[];
void func_114320(const char *, int, const char *);

void *func_0012CF00(s32 kind) {
    if ((u32)kind >= 4) {
        func_114320(D_48FEA0, 0x16a, D_48FEB0);
    }
    return D_38C7F8[kind];
}

#endif

}
