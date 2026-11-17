#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

s32 func_0012F500(void *a0, s32 a1, s32 *a2);
s32 func_0012F5C8(s32 a0, s32 a1);

#if defined(__mips__)
asm s32 func_0012F610(void *a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    .word 0x27bdff90 // addiu $sp, $sp, -0x70
    .word 0xffb10020 // sd $s1, 0x20($sp)
    .word 0xffb00010 // sd $s0, 0x10($sp)
    .word 0x00c0882d // move $s1, $a2
    .word 0xffb30040 // sd $s3, 0x40($sp)
    .word 0x00a0802d // move $s0, $a1
    .word 0xffb20030 // sd $s2, 0x30($sp)
    .word 0x00e0982d // move $s3, $a3
    .word 0xffb40050 // sd $s4, 0x50($sp)
    .word 0x0100902d // move $s2, $t0
    .word 0xffbf0060 // sd $ra, 0x60($sp)
    .word 0x0c04bd40 // jal 0x12f500
    .word 0x03a0302d // move $a2, $sp
    .word 0x0040a02d // move $s4, $v0
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x1602000b // bne $s0, $v0, 0x12f67c
    .word 0x0000802d // move $s0, $zero
    .word 0x8fa40000 // lw $a0, ($sp)
    .word 0x0220282d // move $a1, $s1
    .word 0x0c04bd72 // jal 0x12f5c8
    .word 0x24840002 // addiu $a0, $a0, 2
    .word 0x0040802d // move $s0, $v0
    .word 0x0240202d // move $a0, $s2
    .word 0x0c04bd72 // jal 0x12f5c8
    .word 0x0260282d // move $a1, $s3
    .word 0x10000002 // b 0x12f680
    .word 0x0040182d // move $v1, $v0
    .word 0x0000182d // move $v1, $zero
    .word 0x02901021 // addu $v0, $s4, $s0
    .word 0xdfbf0060 // ld $ra, 0x60($sp)
    .word 0xdfb40050 // ld $s4, 0x50($sp)
    .word 0x00431021 // addu $v0, $v0, $v1
    .word 0xdfb30040 // ld $s3, 0x40($sp)
    .word 0xdfb20030 // ld $s2, 0x30($sp)
    .word 0xdfb10020 // ld $s1, 0x20($sp)
    .word 0xdfb00010 // ld $s0, 0x10($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0070 // addiu $sp, $sp, 0x70
}
#else
s32 func_0012F610(void *a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    s32 count;
    s32 total = func_0012F500(a0, a1, &count);
    s32 part1 = 0;
    s32 part2 = 0;
    if (a1 == 2) {
        part1 = func_0012F5C8(count + 2, a2);
        part2 = func_0012F5C8(t0, a3);
    }
    return total + part1 + part2;
}
#endif

}
