#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

struct TargetStruct;

extern "C" {

s32 func_0012F6A8(TargetStruct *self);

#if defined(__mips__)
asm s32 func_0012F6C8(TargetStruct *self, s32 val) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x0c04bdaa // jal 0x12f6a8
    .word 0x00a0802d // move $s0, $a1
    .word 0x0050102a // slt $v0, $v0, $s0
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x38420001 // xori $v0, $v0, 1
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else
s32 func_0012F6C8(TargetStruct *self, s32 val) {
    return func_0012F6A8(self) >= val;
}
#endif

}
