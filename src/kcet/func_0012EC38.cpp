#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012EC38(void *a0) {
    .word 0x27bdffd0 // 0012EC38: addiu $sp, $sp, -0x30
    .word 0xffb00000 // 0012EC3C: sd $s0, ($sp)
    .word 0xffb10010 // 0012EC40: sd $s1, 0x10($sp)
    .word 0x2490000c // 0012EC44: addiu $s0, $a0, 0xc
    .word 0xffbf0020 // 0012EC48: sd $ra, 0x20($sp)
    .word 0x0000882d // 0012EC4C: move $s1, $zero
    .word 0x0c04b85e // 0012EC50: jal 0x12e178
    .word 0x0200202d // 0012EC54: move $a0, $s0
    .word 0x10400003 // 0012EC58: beqz $v0, 0x12ec68
    .word 0x0200202d // 0012EC5C: move $a0, $s0
    .word 0x0c04b870 // 0012EC60: jal 0x12e1c0
    .word 0x2411ff82 // 0012EC64: addiu $s1, $zero, -0x7e
    .word 0x0220102d // 0012EC68: move $v0, $s1
    .word 0xdfbf0020 // 0012EC6C: ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012EC70: ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012EC74: ld $s0, ($sp)
    .word 0x03e00008 // 0012EC78: jr $ra
    .word 0x27bd0030 // 0012EC7C: addiu $sp, $sp, 0x30
}
#else

s32 func_0012E178(void *ptr);
void func_0012E1C0(void *ptr);

s32 func_0012EC38(u8 *arg0) {
    s32 res = 0;
    u8 *ptr = arg0 + 0xc;
    if (func_0012E178(ptr)) {
        func_0012E1C0(ptr);
        res = -0x7e;
    }
    return res;
}

#endif

}
