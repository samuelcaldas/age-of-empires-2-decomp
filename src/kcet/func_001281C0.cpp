typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_001281C0(s32 a0) {
    .word 0x27bdff40 /* addiu $sp, $sp, -0xc0 */
    .word 0xffbe00a0 /* sd $fp, 0xa0($sp) */
    .word 0xffb10030 /* sd $s1, 0x30($sp) */
    .word 0x0000f02d /* move $fp, $zero */
    .word 0xffbf00b0 /* sd $ra, 0xb0($sp) */
    .word 0x0080882d /* move $s1, $a0 */
    .word 0xffb70090 /* sd $s7, 0x90($sp) */
    .word 0xffb60080 /* sd , 0x80($sp) */
    .word 0xffb50070 /* sd $s5, 0x70($sp) */
    .word 0xffb40060 /* sd $s4, 0x60($sp) */
    .word 0xffb30050 /* sd $s3, 0x50($sp) */
    .word 0xffb20040 /* sd $s2, 0x40($sp) */
    .word 0xffb00020 /* sd $s0, 0x20($sp) */
    .word 0x8e22006c /* lw $v0, 0x6c($s1) */
    .word 0xafa20010 /* sw $v0, 0x10($sp) */
    .word 0x8e220070 /* lw $v0, 0x70($s1) */
    .word 0x0c04a06c /* jal 0x1281b0 */
    .word 0xafa20014 /* sw $v0, 0x14($sp) */
    .word 0x10400053 /* beqz $v0, 0x128358 */
    .word 0x240300ff /* addiu $v1, $zero, 0xff */
    .word 0x24120005 /* addiu $s2, $zero, 5 */
    .word 0x27a20005 /* addiu $v0, $sp, 5 */
    .word 0xa0430000 /* sb $v1, ($v0) */
    .word 0x2652ffff /* addiu $s2, $s2, -1 */
    .word 0x2442ffff /* addiu $v0, $v0, -1 */
    .word 0x00000000 /* nop */
    .word 0x00000000 /* nop */
    .word 0x0641fffa /* bgez $s2, 0x128218 */
    .word 0x00000000 /* nop */
    .word 0x0000982d /* move $s3, $zero */
    .word 0x0000902d /* move $s2, $zero */
    .word 0x24160001 /* addiu $s6, $zero, 1 */
    .word 0x26370055 /* addiu $s7, $s1, 0x55 */
    .word 0x2635001c /* addiu $s5, $s1, 0x1c */
    .word 0x26340054 /* addiu $s4, $s1, 0x54 */
    .word 0x00128040 /* sll $s0, $s2, 1 */
    .word 0x02a0202d /* move $a0, $s5 */
    .word 0x02121021 /* addu $v0, $s0, $s2 */
    .word 0x02e21821 /* addu $v1, $s7, $v0 */
    .word 0xa0600000 /* sb $zero, ($v1) */
    .word 0x02821021 /* addu $v0, $s4, $v0 */
    .word 0x0c04a04c /* jal 0x128130 */
    .word 0x90450000 /* lbu $a1, ($v0) */
    .word 0x0040282d /* move $a1, $v0 */
    .word 0x240200ff /* addiu $v0, $zero, 0xff */
    .word 0x10a20010 /* beq $a1, $v0, 0x1282b8 */
    .word 0x00051880 /* sll $v1, $a1, 2 */
    .word 0x24040001 /* addiu $a0, $zero, 1 */
    .word 0x02231821 /* addu $v1, $s1, $v1 */
    .word 0x9062001e /* lbu $v0, 0x1e($v1) */
    .word 0x0082100a /* movz $v0, $a0, $v0 */
    .word 0x02623021 /* addu $a2, $s3, $v0 */
    .word 0x28c30007 /* slti $v1, $a2, 7 */
    .word 0x1060000e /* beqz $v1, 0x1282d0 */
    .word 0x02301021 /* addu $v0, $s1, $s0 */
    .word 0x03b31821 /* addu $v1, $sp, $s3 */
    .word 0xa04500a4 /* sb $a1, 0xa4($v0) */
    .word 0x0040202d /* move $a0, $v0 */
    .word 0xa09300a5 /* sb $s3, 0xa5($a0) */
    .word 0xa0650000 /* sb $a1, ($v1) */
    .word 0x10000003 /* b 0x1282c0 */
    .word 0x00c0982d /* move $s3, $a2 */
    .word 0x02301021 /* addu $v0, $s1, $s0 */
    .word 0xa04500a4 /* sb $a1, 0xa4($v0) */
    .word 0x26520001 /* addiu $s2, $s2, 1 */
    .word 0x2a560006 /* slti $s6, $s2, 6 */
    .word 0x16c0ffe1 /* bnez $s6, 0x128250 */
    .word 0x00128040 /* sll $s0, $s2, 1 */
    .word 0x52c0000c /* beql $s6, $zero, 0x128304 */
    .word 0x8e2200b0 /* lw $v0, 0xb0($s1) */
    .word 0x262500a4 /* addiu $a1, $s1, 0xa4 */
    .word 0x00000000 /* nop */
    .word 0x00121040 /* sll $v0, $s2, 1 */
    .word 0x240400ff /* addiu $a0, $zero, 0xff */
    .word 0x00a21021 /* addu $v0, $a1, $v0 */
    .word 0x26520001 /* addiu $s2, $s2, 1 */
    .word 0xa0440000 /* sb $a0, ($v0) */
    .word 0x2a430006 /* slti $v1, $s2, 6 */
    .word 0x1460fff9 /* bnez $v1, 0x1282e0 */
    .word 0x00000000 /* nop */
    .word 0x8e2200b0 /* lw $v0, 0xb0($s1) */
    .word 0x3c030002 /* lui $v1, 2 */
    .word 0x00431024 /* and $v0, $v0, $v1 */
    .word 0x1040000c /* beqz $v0, 0x128340 */
    .word 0x8fa40010 /* lw $a0, 0x10($sp) */
    .word 0x03a0302d /* move $a2, $sp */
    .word 0x0c04365a /* jal 0x10d968 */
    .word 0x8fa50014 /* lw $a1, 0x14($sp) */
    .word 0x0040f02d /* move $fp, $v0 */
    .word 0x24020001 /* addiu $v0, $zero, 1 */
    .word 0x13c20003 /* beq $fp, $v0, 0x128338 */
    .word 0x8fa40010 /* lw $a0, 0x10($sp) */
    .word 0x10000003 /* b 0x128340 */
    .word 0x241effff /* addiu $fp, $zero, -1 */
    .word 0x0c0496ba /* jal 0x125ae8 */
    .word 0x8fa50014 /* lw $a1, 0x14($sp) */
    .word 0x2402ffff /* addiu $v0, $zero, -1 */
    .word 0x13c20005 /* beq $fp, $v0, 0x12835c */
    .word 0x03c0102d /* move $v0, $fp */
    .word 0x8e2200b0 /* lw $v0, 0xb0($s1) */
    .word 0x38420010 /* xori $v0, $v0, 0x10 */
    .word 0xae2200b0 /* sw $v0, 0xb0($s1) */
    .word 0x03c0102d /* move $v0, $fp */
    .word 0xdfbf00b0 /* ld $ra, 0xb0($sp) */
    .word 0xdfbe00a0 /* ld $fp, 0xa0($sp) */
    .word 0xdfb70090 /* ld $s7, 0x90($sp) */
    .word 0xdfb60080 /* ld $s6, 0x80($sp) */
    .word 0xdfb50070 /* ld $s5, 0x70($sp) */
    .word 0xdfb40060 /* ld $s4, 0x60($sp) */
    .word 0xdfb30050 /* ld $s3, 0x50($sp) */
    .word 0xdfb20040 /* ld $s2, 0x40($sp) */
    .word 0xdfb10030 /* ld $s1, 0x30($sp) */
    .word 0xdfb00020 /* ld $s0, 0x20($sp) */
    .word 0x03e00008 /* jr $ra */
    .word 0x27bd00c0 /* addiu $sp, $sp, 0xc0 */
}
#else
s32 func_001281C0(s32 a0) {
    return 0;
}
#endif

}
