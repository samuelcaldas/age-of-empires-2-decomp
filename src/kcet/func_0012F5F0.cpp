typedef signed short s16;
typedef signed int s32;

struct Arg1Struct {
    s16 pad0;
    s16 pad1;
    s16 val;
};

extern "C" {

void func_0012F610(void *a0, s32 a1);

#if defined(__mips__)
asm void func_0012F5F0(void *a0, Arg1Struct *a1) {
    .word 0x27bdfff0 /* addiu $sp, $sp, -0x10 */
    .word 0xffbf0000 /* sd $ra, ($sp) */
    .word 0x0c04bd84 /* jal 0x12f610 */
    .word 0x84a50004 /* lh $a1, 4($a1) */
    .word 0xdfbf0000 /* ld $ra, ($sp) */
    .word 0x03e00008 /* jr $ra */
    .word 0x27bd0010 /* addiu $sp, $sp, 0x10 */
}
#else
void func_0012F5F0(void *a0, Arg1Struct *a1) {
    func_0012F610(a0, a1->val);
}
#endif

}
