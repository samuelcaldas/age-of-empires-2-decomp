/* Function: func_0012D228 (0x0012D228 - 0x0012D2D8)
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
asm void *func_0012D228(u32 target) {
    .word 0x27bdff80 // 0012d228:  addiu $sp, $sp, -0x80
    .word 0xffb60060 // 0012d22c:  sd $s6, 0x60($sp)
    .word 0xffb50050 // 0012d230:  sd $s5, 0x50($sp)
    .word 0x0080b02d // 0012d234:  move $s6, $a0
    .word 0xffb40040 // 0012d238:  sd $s4, 0x40($sp)
    .word 0x0000a82d // 0012d23c:  move $s5, $zero
    .word 0xffb30030 // 0012d240:  sd $s3, 0x30($sp)
    .word 0xffbf0070 // 0012d244:  sd $ra, 0x70($sp)
    .word 0xffb20020 // 0012d248:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012d24c:  sd $s1, 0x10($sp)
    .word 0x0c04b2b8 // 0012d250:  jal 0x12cae0
    .word 0xffb00000 // 0012d254:  sd $s0, ($sp)
    .word 0x0c04b2bc // 0012d258:  jal 0x12caf0
    .word 0x0040982d // 0012d25c:  move $s3, $v0
    .word 0x12600012 // 0012d260:  beqz $s3, 0x12d2ac
    .word 0x0040a02d // 0012d264:  move $s4, $v0
    .word 0x0000902d // 0012d268:  move $s2, $zero
    .word 0x10000005 // 0012d26c:  b 0x12d284
    .word 0x0000882d // 0012d270:  move $s1, $zero
    .word 0x00000000 // 0012d274:  nop
    .word 0x0c04b308 // 0012d278:  jal 0x12cc20
    .word 0x26310001 // 0012d27c:  addiu $s1, $s1, 1
    .word 0x02429021 // 0012d280:  addu $s2, $s2, $v0
    .word 0x0234102a // 0012d284:  slt $v0, $s1, $s4
    .word 0x10400008 // 0012d288:  beqz $v0, 0x12d2ac
    .word 0x02728021 // 0012d28c:  addu $s0, $s3, $s2
    .word 0x0c04b2fe // 0012d290:  jal 0x12cbf8
    .word 0x0200202d // 0012d294:  move $a0, $s0
    .word 0x0c04b2c4 // 0012d298:  jal 0x12cb10
    .word 0x0040202d // 0012d29c:  move $a0, $v0
    .word 0x56c2fff5 // 0012d2a0:  bnel $s6, $v0, 0x12d278
    .word 0x0200202d // 0012d2a4:  move $a0, $s0
    .word 0x0200a82d // 0012d2a8:  move $s5, $s0
    .word 0x02a0102d // 0012d2ac:  move $v0, $s5
    .word 0xdfbf0070 // 0012d2b0:  ld $ra, 0x70($sp)
    .word 0xdfb60060 // 0012d2b4:  ld $s6, 0x60($sp)
    .word 0xdfb50050 // 0012d2b8:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012d2bc:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012d2c0:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012d2c4:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012d2c8:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012d2cc:  ld $s0, ($sp)
    .word 0x03e00008 // 0012d2d0:  jr $ra
    .word 0x27bd0080 // 0012d2d4:  addiu $sp, $sp, 0x80
}
#else

s32 func_0012CAE0(void);
void *func_0012CAF0(void);
s32 func_0012CC20(void *);
u32 func_0012CBF8(void *);
u32 func_0012CB10(u32);

void *func_0012D228(u32 target) {
    s32 count = func_0012CAE0();
    u8 *table = (u8 *)func_0012CAF0();
    u8 *result = 0;

    if (table != 0) {
        s32 offset = 0;
        s32 i;
        for (i = 0; i < count; i++) {
            u8 *entry = table + offset;
            if (func_0012CB10(func_0012CBF8(entry)) == target) {
                result = entry;
                break;
            }
            offset += func_0012CC20(entry);
        }
    }
    return result;
}

#endif

}
