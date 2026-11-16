#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012BD40(void *arg0) {
    .word 0x27bdffc0 // 0012BD40:  addiu $sp, $sp, -0x40
    .word 0xffb00010 // 0012BD44:  sd $s0, 0x10($sp)
    .word 0x0080802d // 0012BD48:  move $s0, $a0
    .word 0xffb10020 // 0012BD4C:  sd $s1, 0x20($sp)
    .word 0xffbf0030 // 0012BD50:  sd $ra, 0x30($sp)
    .word 0x0c04af62 // 0012BD54:  jal 0x12bd88
    .word 0x03a0202d // 0012BD58:  move $a0, $sp
    .word 0x0040882d // 0012BD5C:  move $s1, $v0
    .word 0x0200202d // 0012BD60:  move $a0, $s0
    .word 0x0c04af2a // 0012BD64:  jal 0x12bca8
    .word 0x03a0282d // 0012BD68:  move $a1, $sp
    .word 0x0220102d // 0012BD6C:  move $v0, $s1
    .word 0xdfbf0030 // 0012BD70:  ld $ra, 0x30($sp)
    .word 0xdfb10020 // 0012BD74:  ld $s1, 0x20($sp)
    .word 0xdfb00010 // 0012BD78:  ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012BD7C:  jr $ra
    .word 0x27bd0040 // 0012BD80:  addiu $sp, $sp, 0x40
}
#else

s32 func_0012BD88(void *);
void func_0012BCA8(void *, void *);

s32 func_0012BD40(void *arg0) {
    u8 temp[16];
    s32 res = func_0012BD88(temp);
    func_0012BCA8(arg0, temp);
    return res;
}

#endif

}
