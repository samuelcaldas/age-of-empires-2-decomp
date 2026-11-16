typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_00127D88(s32 a0, s32 a1, s32 a2, s32 a3) {
    .word 0x00861823 /* subu $v1, $a0, $a2 */
    .word 0x04610003 /* bgez $v1, 0x127d9c */
    .word 0x00651818 /* mult $ac3, $v1, $a1 */
    .word 0x10000009 /* b 0x127dbc */
    .word 0x0000182d /* move $v1, $zero */
    .word 0x00e61023 /* subu $v0, $a3, $a2 */
    .word 0x50400001 /* beql $v0, $zero, 0x127da8 */
    .word 0x000001cd /* break 0, 7 */
    .word 0x24a4ffff /* addiu $a0, $a1, -1 */
    .word 0x0062001a /* div $zero, $v1, $v0 */
    .word 0x00001812 /* mflo $v1 */
    .word 0x0065102a /* slt $v0, $v1, $a1 */
    .word 0x0082180a /* movz $v1, $a0, $v0 */
    .word 0x03e00008 /* jr $ra */
    .word 0x0060102d /* move $v0, $v1 */
}
#else
s32 func_00127D88(s32 val, s32 scale, s32 min_val, s32 max_val) {
    s32 diff = val - min_val;
    if (diff < 0) {
        return 0;
    }
    s32 range = max_val - min_val;
    s32 res = (diff * scale) / range;
    if (res >= scale) {
        res = scale - 1;
    }
    return res;
}
#endif

}
