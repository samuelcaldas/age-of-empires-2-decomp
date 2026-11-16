typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_001285F8(s32 a0, s32 a1, s32 a2) {
    .word 0x27bdff90 /* addiu $sp, $sp, -0x70 */
    .word 0x2407ffff /* addiu $a3, $zero, -1 */
    .word 0xffb50050 /* sd $s5, 0x50($sp) */
    .word 0xffb20020 /* sd $s2, 0x20($sp) */
    .word 0x00c0a82d /* move $s5, $a2 */
    .word 0xffb10010 /* sd $s1, 0x10($sp) */
    .word 0x0080902d /* move $s2, $a0 */
    .word 0x00a0882d /* move $s1, $a1 */
    .word 0xffb40040 /* sd $s4, 0x40($sp) */
    .word 0xffb30030 /* sd $s3, 0x30($sp) */
    .word 0xffb00000 /* sd $s0, ($sp) */
    .word 0xffbf0060 /* sd $ra, 0x60($sp) */
    .word 0x0c0435b0 /* jal 0x10d6c0 */
    .word 0x24060004 /* addiu $a2, $zero, 4 */
    .word 0x2414ffff /* addiu $s4, $zero, -1 */
    .word 0x0000802d /* move $s0, $zero */
    .word 0x0040982d /* move $s3, $v0 */
    .word 0x00000000 /* nop */
    .word 0x0213102a /* slt $v0, $s0, $s3 */
    .word 0x1040000a /* beqz $v0, 0x128670 */
    .word 0x0240202d /* move $a0, $s2 */
    .word 0x0220282d /* move $a1, $s1 */
    .word 0x24060004 /* addiu $a2, $zero, 4 */
    .word 0x0c0435b0 /* jal 0x10d6c0 */
    .word 0x0200382d /* move $a3, $s0 */
    .word 0x58400005 /* blezl $v0, 0x128674 */
    .word 0x0280102d /* move $v0, $s4 */
    .word 0x5455fff6 /* bnel $v0, $s5, 0x128640 */
    .word 0x26100001 /* addiu $s0, $s0, 1 */
    .word 0x0200a02d /* move $s4, $s0 */
    .word 0x0280102d /* move $v0, $s4 */
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
s32 func_001285F8(s32 a0, s32 a1, s32 a2) {
    return 0;
}
#endif

}
