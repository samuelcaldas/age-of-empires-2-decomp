/* Function: func_0012CDE0 (0x0012CDE0 - 0x0012CE9C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
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
asm s32 func_0012CDE0(void *a0) {
    .word 0x27bdff80 // 0012cde0:  addiu $sp, $sp, -0x80
    .word 0xffb60060 // 0012cde4:  sd $s6, 0x60($sp)
    .word 0xffb30030 // 0012cde8:  sd $s3, 0x30($sp)
    .word 0x3c16004f // 0012cdec:  lui $s6, 0x4f
    .word 0xffb20020 // 0012cdf0:  sd $s2, 0x20($sp)
    .word 0x26c21508 // 0012cdf4:  addiu $v0, $s6, 0x1508
    .word 0xffb10010 // 0012cdf8:  sd $s1, 0x10($sp)
    .word 0x0080902d // 0012cdfc:  move $s2, $a0
    .word 0xffbf0070 // 0012ce00:  sd $ra, 0x70($sp)
    .word 0x0000982d // 0012ce04:  move $s3, $zero
    .word 0xffb40040 // 0012ce08:  sd $s4, 0x40($sp)
    .word 0x0000882d // 0012ce0c:  move $s1, $zero
    .word 0xffb00000 // 0012ce10:  sd $s0, ($sp)
    .word 0xffb50050 // 0012ce14:  sd $s5, 0x50($sp)
    .word 0x1240000d // 0012ce18:  beqz $s2, 0x12ce50
    .word 0x8c55000c // 0012ce1c:  lw $s5, 0xc($v0)
    .word 0x10000004 // 0012ce20:  b 0x12ce34
    .word 0x3c140049 // 0012ce24:  lui $s4, 0x49
    .word 0x0c04b308 // 0012ce28:  jal 0x12cc20
    .word 0x26730001 // 0012ce2c:  addiu $s3, $s3, 1
    .word 0x02228821 // 0012ce30:  addu $s1, $s1, $v0
    .word 0x02518021 // 0012ce34:  addu $s0, $s2, $s1
    .word 0x0c04b2fe // 0012ce38:  jal 0x12cbf8
    .word 0x0200202d // 0012ce3c:  move $a0, $s0
    .word 0x1440fff9 // 0012ce40:  bnez $v0, 0x12ce28
    .word 0x0200202d // 0012ce44:  move $a0, $s0
    .word 0x10000003 // 0012ce48:  b 0x12ce58
    .word 0x26c21508 // 0012ce4c:  addiu $v0, $s6, 0x1508
    .word 0x3c140049 // 0012ce50:  lui $s4, 0x49
    .word 0x26c21508 // 0012ce54:  addiu $v0, $s6, 0x1508
    .word 0x2684fe70 // 0012ce58:  addiu $a0, $s4, -0x190
    .word 0xac530010 // 0012ce5c:  sw $s3, 0x10($v0)
    .word 0x0240282d // 0012ce60:  move $a1, $s2
    .word 0x0260302d // 0012ce64:  move $a2, $s3
    .word 0x0c046378 // 0012ce68:  jal 0x118de0
    .word 0xac52000c // 0012ce6c:  sw $s2, 0xc($v0)
    .word 0x02a0102d // 0012ce70:  move $v0, $s5
    .word 0xdfbf0070 // 0012ce74:  ld $ra, 0x70($sp)
    .word 0xdfb60060 // 0012ce78:  ld $s6, 0x60($sp)
    .word 0xdfb50050 // 0012ce7c:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012ce80:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012ce84:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012ce88:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012ce8c:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012ce90:  ld $s0, ($sp)
    .word 0x03e00008 // 0012ce94:  jr $ra
    .word 0x27bd0080 // 0012ce98:  addiu $sp, $sp, 0x80
}
#else

s32 func_0012CBF8(void *p);
s32 func_0012CC20(void *p);
void func_118de0(const char *fmt, void *arg1, s32 arg2);

struct UnknownGlobal {
    void *ptr;
    s32 count;
    s32 min_val;
    void *name_table;
    s32 name_count;
};

extern UnknownGlobal D_004F1508;
extern const char D_0048FE70[];

s32 func_0012CDE0(void *arg0) {
    s32 count = 0;
    s32 offset = 0;
    void *old_name_table = D_004F1508.name_table;

    if (arg0 != 0) {
        while (func_0012CBF8((u8 *)arg0 + offset) != 0) {
            count++;
            offset += func_0012CC20((u8 *)arg0 + offset);
        }
    }

    D_004F1508.name_count = count;
    func_118de0(D_0048FE70, arg0, count);
    D_004F1508.name_table = arg0;

    return (s32)old_name_table;
}

#endif

}
