typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_00127DC8(s32 a0, s32 a1, s32 a2, s32 a3) {
    .word 0x27bdffe0 /* addiu $sp, $sp, -0x20 */
    .word 0x00c0402d /* move $t0, $a2 */
    .word 0xffbf0010 /* sd $ra, 0x10($sp) */
    .word 0x28e20080 /* slti $v0, $a3, 0x80 */
    .word 0x10400003 /* beqz $v0, 0x127de8 */
    .word 0xffb00000 /* sd $s0, ($sp) */
    .word 0x10000003 /* b 0x127df0 */
    .word 0x00e0102d /* move $v0, $a3 */
    .word 0x24020100 /* addiu $v0, $zero, 0x100 */
    .word 0x00471023 /* subu $v0, $v0, $a3 */
    .word 0x2443ffff /* addiu $v1, $v0, -1 */
    .word 0x0087802a /* slt $s0, $a0, $a3 */
    .word 0x0102102a /* slt $v0, $t0, $v0 */
    .word 0x16000003 /* bnez $s0, 0x127e0c */
    .word 0x0062400a /* movz $t0, $v1, $v0 */
    .word 0x10000003 /* b 0x127e14 */
    .word 0x00872023 /* subu $a0, $a0, $a3 */
    .word 0x24820001 /* addiu $v0, $a0, 1 */
    .word 0x00e22023 /* subu $a0, $a3, $v0 */
    .word 0x00a0302d /* move $a2, $a1 */
    .word 0x0100382d /* move $a3, $t0 */
    .word 0x0c049f62 /* jal 0x127d88 */
    .word 0x24050080 /* addiu $a1, $zero, 0x80 */
    .word 0x00021823 /* negu $v1, $v0 */
    .word 0xdfbf0010 /* ld $ra, 0x10($sp) */
    .word 0x0050180a /* movz $v1, $v0, $s0 */
    .word 0xdfb00000 /* ld $s0, ($sp) */
    .word 0x306200ff /* andi $v0, $v1, 0xff */
    .word 0x03e00008 /* jr $ra */
    .word 0x27bd0020 /* addiu $sp, $sp, 0x20 */
}
#else
s32 func_00127DC8(s32 a0, s32 a1, s32 a2, s32 a3) {
    return 0;
}
#endif

}
