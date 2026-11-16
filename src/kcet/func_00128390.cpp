typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_00128390(s32 a0, s32 a1) {
    .word 0x27bdff40 /* addiu $sp, $sp, -0xc0 */
    .word 0xffb30050 /* sd $s3, 0x50($sp) */
    .word 0xffbf00b0 /* sd $ra, 0xb0($sp) */
    .word 0x0080982d /* move $s3, $a0 */
    .word 0xffbe00a0 /* sd $fp, 0xa0($sp) */
    .word 0xffb70090 /* sd $s7, 0x90($sp) */
    .word 0xffb60080 /* sd $s6, 0x80($sp) */
    .word 0xffb50070 /* sd $s5, 0x70($sp) */
    .word 0xffb40060 /* sd $s4, 0x60($sp) */
    .word 0xffb20040 /* sd $s2, 0x40($sp) */
    .word 0xffb10030 /* sd $s1, 0x30($sp) */
    .word 0xffb00020 /* sd $s0, 0x20($sp) */
    .word 0xafa00018 /* sw $zero, 0x18($sp) */
    .word 0x8e62006c /* lw $v0, 0x6c($s3) */
    .word 0xafa20010 /* sw $v0, 0x10($sp) */
    .word 0x8e640070 /* lw $a0, 0x70($s3) */
    .word 0x10a00005 /* beqz $a1, 0x1283e8 */
    .word 0xafa40014 /* sw $a0, 0x14($sp) */
    .word 0x8e6200b0 /* lw $v0, 0xb0($s3) */
    .word 0x30420008 /* andi $v0, $v0, 8 */
    .word 0x0002102b /* sltu $v0, $zero, $v0 */
    .word 0xafa20018 /* sw $v0, 0x18($sp) */
    .word 0x0000382d /* move $a3, $zero */
    .word 0x03a0182d /* move $v1, $sp */
    .word 0xac600000 /* sw $zero, ($v1) */
    .word 0x24e70001 /* addiu $a3, $a3, 1 */
    .word 0x24630004 /* addiu $v1, $v1, 4 */
    .word 0x2ce20002 /* sltiu $v0, $a3, 2 */
    .word 0x00000000 /* nop */
    .word 0x1440fffa /* bnez $v0, 0x1283f0 */
    .word 0x00000000 /* nop */
    .word 0x0000382d /* move $a3, $zero */
    .word 0x266200a4 /* addiu $v0, $s3, 0xa4 */
    .word 0xafa2001c /* sw $v0, 0x1c($sp) */
    .word 0x267e00a5 /* addiu $fp, $s3, 0xa5 */
    .word 0x26760055 /* addiu $s6, $s3, 0x55 */
    .word 0x26770056 /* addiu $s7, $s3, 0x56 */
    .word 0x8fa4001c /* lw $a0, 0x1c($sp) */
    .word 0x00073040 /* sll $a2, $a3, 1 */
    .word 0x00c71821 /* addu $v1, $a2, $a3 */
    .word 0x240500ff /* addiu $a1, $zero, 0xff */
    .word 0x00861021 /* addu $v0, $a0, $a2 */
    .word 0x02e32021 /* addu $a0, $s7, $v1 */
    .word 0x90480000 /* lbu $t0, ($v0) */
    .word 0x03c61021 /* addu $v0, $fp, $a2 */
    .word 0x02c31821 /* addu $v1, $s6, $v1 */
    .word 0x90550000 /* lbu $s5, ($v0) */
    .word 0x90630000 /* lbu $v1, ($v1) */
    .word 0x11050032 /* beq $t0, $a1, 0x12851c */
    .word 0x90910000 /* lbu $s1, ($a0) */
    .word 0x8fa20018 /* lw $v0, 0x18($sp) */
    .word 0x0002180a /* movz $v1, $zero, $v0 */
    .word 0x50600002 /* beql $v1, $zero, 0x12846c */
    .word 0x0000882d /* move $s1, $zero */
    .word 0x2463ffff /* addiu $v1, $v1, -1 */
    .word 0x00081080 /* sll $v0, $t0, 2 */
    .word 0x02621021 /* addu $v0, $s3, $v0 */
    .word 0x9050001e /* lbu $s0, 0x1e($v0) */
    .word 0x16000004 /* bnez $s0, 0x12848c */
    .word 0x24020001 /* addiu $v0, $zero, 1 */
    .word 0x0000202d /* move $a0, $zero */
    .word 0x10000008 /* b 0x1284a8 */
    .word 0x0051880b /* movn $s1, $v0, $s1 */
    .word 0x12020005 /* beq $s0, $v0, 0x1284a4 */
    .word 0x6604ffff /* daddiu $a0, $s0, -1 */
    .word 0x000410fc /* dsll32 $v0, $a0, 3 */
    .word 0x0002103f /* dsra32 $v0, $v0, 0 */
    .word 0x10000002 /* b 0x1284a8 */
    .word 0x00518814 /* dsllv $s1, $s1, $v0 */
    .word 0x0000202d /* move $a0, $zero */
    .word 0x00c71021 /* addu $v0, $a2, $a3 */
    .word 0x0080802d /* move $s0, $a0 */
    .word 0x02c21021 /* addu $v0, $s6, $v0 */
    .word 0x06000019 /* bltz $s0, 0x12851c */
    .word 0xa0430000 /* sb $v1, ($v0) */
    .word 0x24f20001 /* addiu $s2, $a3, 1 */
    .word 0x02a0a02d /* move $s4, $s5 */
    .word 0x00000000 /* nop */
    .word 0x0290102d /* daddu $v0, $s4, $s0 */
    .word 0x28420006 /* slti $v0, $v0, 6 */
    .word 0x14400006 /* bnez $v0, 0x1284ec */
    .word 0x3c040049 /* lui $a0, 0x49 */
    .word 0x3c060049 /* lui $a2, 0x49 */
    .word 0x2484f1f0 /* addiu $a0, $a0, -0xe10 */
    .word 0x24c6f430 /* addiu $a2, $a2, -0xbd0 */
    .word 0x0c0450c8 /* jal 0x114320 */
    .word 0x240509d9 /* addiu $a1, $zero, 0x9d9 */
    .word 0x0010103c /* dsll32 $v0, $s0, 0 */
    .word 0x0002103f /* dsra32 $v0, $v0, 0 */
    .word 0x322300ff /* andi $v1, $s1, 0xff */
    .word 0x02a21021 /* addu $v0, $s5, $v0 */
    .word 0x306300ff /* andi $v1, $v1, 0xff */
    .word 0x03a22021 /* addu $a0, $sp, $v0 */
    .word 0x00118a3a /* dsrl $s1, $s1, 8 */
    .word 0x6610ffff /* daddiu $s0, $s0, -1 */
    .word 0x0601ffee /* bgez $s0, 0x1284c8 */
    .word 0xa0830000 /* sb $v1, ($a0) */
    .word 0x10000003 /* b 0x128524 */
    .word 0x0240382d /* move $a3, $s2 */
    .word 0x24f20001 /* addiu $s2, $a3, 1 */
    .word 0x0240382d /* move $a3, $s2 */
    .word 0x28e20006 /* slti $v0, $a3, 6 */
    .word 0x1440ffbf /* bnez $v0, 0x128428 */
    .word 0x8fa4001c /* lw $a0, 0x1c($sp) */
    .word 0x8fa30000 /* lw $v1, ($sp) */
    .word 0x0000302d /* move $a2, $zero */
    .word 0x8e6200b4 /* lw $v0, 0xb4($s3) */
    .word 0x1462000b /* bne $v1, $v0, 0x12856c */
    .word 0x0000382d /* move $a3, $zero */
    .word 0x24e70001 /* addiu $a3, $a3, 1 */
    .word 0x2ce20002 /* sltiu $v0, $a3, 2 */
    .word 0x10400008 /* beqz $v0, 0x128570 */
    .word 0x00071880 /* sll $v1, $a3, 2 */
    .word 0x03a31021 /* addu $v0, $sp, $v1 */
    .word 0x02632821 /* addu $a1, $s3, $v1 */
    .word 0x8c440000 /* lw $a0, ($v0) */
    .word 0x8ca300b4 /* lw $v1, 0xb4($a1) */
    .word 0x5083fff8 /* beql $a0, $v1, 0x128548 */
    .word 0x24e70001 /* addiu $a3, $a3, 1 */
    .word 0x24060001 /* addiu $a2, $zero, 1 */
    .word 0x10c00015 /* beqz $a2, 0x1285c8 */
    .word 0x3c030002 /* lui $v1, 2 */
    .word 0x8e6200b0 /* lw $v0, 0xb0($s3) */
    .word 0x00431024 /* and $v0, $v0, $v1 */
    .word 0x10400012 /* beqz $v0, 0x1285cc */
    .word 0xdfbf00b0 /* ld $ra, 0xb0($sp) */
    .word 0x8fa40010 /* lw $a0, 0x10($sp) */
    .word 0x03a0302d /* move $a2, $sp */
    .word 0x0c04362c /* jal 0x10d8b0 */
    .word 0x8fa50014 /* lw $a1, 0x14($sp) */
    .word 0x266400b4 /* addiu $a0, $s3, 0xb4 */
    .word 0x0000382d /* move $a3, $zero */
    .word 0x03a0302d /* move $a2, $sp */
    .word 0x00000000 /* nop */
    .word 0x8cc30000 /* lw $v1, ($a2) */
    .word 0x24e70001 /* addiu $a3, $a3, 1 */
    .word 0x24c60004 /* addiu $a2, $a2, 4 */
    .word 0x2ce20002 /* sltiu $v0, $a3, 2 */
    .word 0xac830000 /* sw $v1, ($a0) */
    .word 0x24840004 /* addiu $a0, $a0, 4 */
    .word 0x1440fff9 /* bnez $v0, 0x1285a8 */
    .word 0x00000000 /* nop */
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
s32 func_00128390(s32 a0, s32 a1) {
    return 0;
}
#endif

}
