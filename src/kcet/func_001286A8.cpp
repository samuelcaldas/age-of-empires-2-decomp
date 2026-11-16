typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_001286A8(s32 a0) {
    .word 0x27bdff90 /* addiu $sp, $sp, -0x70 */
    .word 0xffb20020 /* sd $s2, 0x20($sp) */
    .word 0xffb10010 /* sd $s1, 0x10($sp) */
    .word 0x0000902d /* move $s2, $zero */
    .word 0xffbf0060 /* sd $ra, 0x60($sp) */
    .word 0x0080882d /* move $s1, $a0 */
    .word 0xffb50050 /* sd $s5, 0x50($sp) */
    .word 0xffb40040 /* sd $s4, 0x40($sp) */
    .word 0xffb30030 /* sd $s3, 0x30($sp) */
    .word 0xffb00000 /* sd $s0, ($sp) */
    .word 0x8e30007c /* lw $s0, 0x7c($s1) */
    .word 0x8e330080 /* lw $s3, 0x80($s1) */
    .word 0x8e34006c /* lw $s4, 0x6c($s1) */
    .word 0x0c04a1a6 /* jal 0x128698 */
    .word 0x8e350070 /* lw $s5, 0x70($s1) */
    .word 0x50400032 /* beql $v0, $zero, 0x1287b0 */
    .word 0x0240102d /* move $v0, $s2 */
    .word 0x52600005 /* beql $s3, $zero, 0x128704 */
    .word 0x92220034 /* lbu $v0, 0x34($s1) */
    .word 0x52000005 /* beql $s0, $zero, 0x12870c */
    .word 0x92300034 /* lbu $s0, 0x34($s1) */
    .word 0x10000003 /* b 0x12870c */
    .word 0x00000000 /* nop */
    .word 0x02021026 /* xor $v0, $s0, $v0 */
    .word 0x0002800a /* movz $s0, $zero, $v0 */
    .word 0x1a00001d /* blez $s0, 0x128784 */
    .word 0x0200302d /* move $a2, $s0 */
    .word 0x0280202d /* move $a0, $s4 */
    .word 0x0c04a17e /* jal 0x1285f8 */
    .word 0x02a0282d /* move $a1, $s5 */
    .word 0x04400014 /* bltz $v0, 0x128774 */
    .word 0x0280202d /* move $a0, $s4 */
    .word 0x02a0282d /* move $a1, $s5 */
    .word 0x0040302d /* move $a2, $v0 */
    .word 0x0c0435fe /* jal 0x10d7f8 */
    .word 0x0260382d /* move $a3, $s3 */
    .word 0x24030001 /* addiu $v1, $zero, 1 */
    .word 0x54430003 /* bnel $v0, $v1, 0x12874c */
    .word 0x8e240084 /* lw $a0, 0x84($s1) */
    .word 0x1000000b /* b 0x128774 */
    .word 0x24120001 /* addiu $s2, $zero, 1 */
    .word 0x28820006 /* slti $v0, $a0, 6 */
    .word 0x14400004 /* bnez $v0, 0x128764 */
    .word 0x24830001 /* addiu $v1, $a0, 1 */
    .word 0x0000902d /* move $s2, $zero */
    .word 0x10000004 /* b 0x128770 */
    .word 0x0000202d /* move $a0, $zero */
    .word 0x3a620003 /* xori $v0, $s3, 3 */
    .word 0x0062200b /* movn $a0, $v1, $v0 */
    .word 0x2412ffff /* addiu $s2, $zero, -1 */
    .word 0xae240084 /* sw $a0, 0x84($s1) */
    .word 0x24020003 /* addiu $v0, $zero, 3 */
    .word 0x16620002 /* bne $s3, $v0, 0x128784 */
    .word 0x2402ffff /* addiu $v0, $zero, -1 */
    .word 0x0052900a /* movz $s2, $v0, $s2 */
    .word 0x06400005 /* bltz $s2, 0x12879c */
    .word 0x24020001 /* addiu $v0, $zero, 1 */
    .word 0x8e2200b0 /* lw $v0, 0xb0($s1) */
    .word 0x38420020 /* xori $v0, $v0, 0x20 */
    .word 0xae2200b0 /* sw $v0, 0xb0($s1) */
    .word 0x24020001 /* addiu $v0, $zero, 1 */
    .word 0x16420004 /* bne $s2, $v0, 0x1287b0 */
    .word 0x0240102d /* move $v0, $s2 */
    .word 0x0c049a30 /* jal 0x1268c0 */
    .word 0x0220202d /* move $a0, $s1 */
    .word 0x0240102d /* move $v0, $s2 */
    .word 0xdfbf0060 /* ld $ra, 0x60($sp) */
    .word 0xdfb50050 /* ld $s5, 0x50($sp) */
    .word 0xdfb40040 /* ld $s4, 0x40($sp) */
    .word 0xdfb30030 /* ld $s3, 0x30($sp) */
    .word 0xdfb20020 /* ld $s2, 0x20($sp) */
    .word 0xdfb10010 /* ld $s1, 0x10($sp) */
    .word 0xdfb00000 /* ld $s0, ($sp) */
    .word 0x03e00008 /* jr $ra */
    .word 0x27bd0070 /* addiu $sp, $sp, 0x70 */
}
#else
s32 func_001286A8(s32 a0) {
    return 0;
}
#endif

}
