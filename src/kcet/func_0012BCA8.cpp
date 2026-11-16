#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012BCA8(u8 *dst, const u8 *src) {
    .word 0x27bdffd0 // 0012BCA8:  addiu $sp, $sp, -0x30
    .word 0xffb10010 // 0012BCAC:  sd $s1, 0x10($sp)
    .word 0xffb00000 // 0012BCB0:  sd $s0, ($sp)
    .word 0x0080882d // 0012BCB4:  move $s1, $a0
    .word 0xffbf0020 // 0012BCB8:  sd $ra, 0x20($sp)
    .word 0x00a0802d // 0012BCBC:  move $s0, $a1
    .word 0x24050002 // 0012BCC0:  addiu $a1, $zero, 2
    .word 0x92020000 // 0012BCC4:  lbu $v0, ($s0)
    .word 0xa2220000 // 0012BCC8:  sb $v0, ($s1)
    .word 0x0c04af1c // 0012BCCC:  jal 0x12bc70
    .word 0x92040001 // 0012BCD0:  lbu $a0, 1($s0)
    .word 0xa2220001 // 0012BCD4:  sb $v0, 1($s1)
    .word 0x24050002 // 0012BCD8:  addiu $a1, $zero, 2
    .word 0x0c04af1c // 0012BCDC:  jal 0x12bc70
    .word 0x92040002 // 0012BCE0:  lbu $a0, 2($s0)
    .word 0xa2220002 // 0012BCE4:  sb $v0, 2($s1)
    .word 0x24050002 // 0012BCE8:  addiu $a1, $zero, 2
    .word 0x0c04af1c // 0012BCEC:  jal 0x12bc70
    .word 0x92040003 // 0012BCF0:  lbu $a0, 3($s0)
    .word 0xa2220003 // 0012BCF4:  sb $v0, 3($s1)
    .word 0x24050002 // 0012BCF8:  addiu $a1, $zero, 2
    .word 0x0c04af1c // 0012BCFC:  jal 0x12bc70
    .word 0x92040005 // 0012BD00:  lbu $a0, 5($s0)
    .word 0xa2220005 // 0012BD04:  sb $v0, 5($s1)
    .word 0x24050002 // 0012BD08:  addiu $a1, $zero, 2
    .word 0x0c04af1c // 0012BD0C:  jal 0x12bc70
    .word 0x92040006 // 0012BD10:  lbu $a0, 6($s0)
    .word 0xa2220006 // 0012BD14:  sb $v0, 6($s1)
    .word 0x24050002 // 0012BD18:  addiu $a1, $zero, 2
    .word 0x0c04af1c // 0012BD1C:  jal 0x12bc70
    .word 0x92040007 // 0012BD20:  lbu $a0, 7($s0)
    .word 0xa2220007 // 0012BD24:  sb $v0, 7($s1)
    .word 0xdfbf0020 // 0012BD28:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012BD2C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012BD30:  ld $s0, ($sp)
    .word 0x03e00008 // 0012BD34:  jr $ra
    .word 0x27bd0030 // 0012BD38:  addiu $sp, $sp, 0x30
}
#else
s32 func_0012BC70(s32 val, s32 count);

void func_0012BCA8(u8 *dst, const u8 *src) {
    dst[0] = src[0];
    dst[1] = (u8)func_0012BC70(src[1], 2);
    dst[2] = (u8)func_0012BC70(src[2], 2);
    dst[3] = (u8)func_0012BC70(src[3], 2);
    dst[5] = (u8)func_0012BC70(src[5], 2);
    dst[6] = (u8)func_0012BC70(src[6], 2);
    dst[7] = (u8)func_0012BC70(src[7], 2);
}
#endif

}
