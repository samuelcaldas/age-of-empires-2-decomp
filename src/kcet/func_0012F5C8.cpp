typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012F5C8(s32 a0, s32 a1) {
    .word 0x00851023 /* subu $v0, $a0, $a1 */
    .word 0x2403ffff /* addiu $v1, $zero, -1 */
    .word 0x0062182a /* slt $v1, $v1, $v0 */
    .word 0x0003100a /* movz $v0, $zero, $v1 */
    .word 0x24420001 /* addiu $v0, $v0, 1 */
    .word 0x00021fc2 /* srl $v1, $v0, 0x1f */
    .word 0x00431021 /* addu $v0, $v0, $v1 */
    .word 0x03e00008 /* jr $ra */
    .word 0x00021043 /* sra $v0, $v0, 1 */
}
#else
s32 func_0012F5C8(s32 a, s32 b) {
    s32 diff = a - b;
    if (diff < 0) {
        diff = 0;
    }
    return (diff + 1) / 2;
}
#endif

}
