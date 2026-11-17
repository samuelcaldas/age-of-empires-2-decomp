#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

struct TargetStruct {
    u32 pad[3];
    u32 field_c;
};

extern "C" {

#if defined(__mips__)
asm void func_0012EFB0(TargetStruct *s, s32 val) {
    .word 0x18a00003 // blez $a1, 0x12efc0
    .word 0x8c86000c // lw $a2, 0xc($a0)
    .word 0x10000005 // b 0x12efd0
    .word 0x34c60002 // ori $a2, $a2, 2
    .word 0x2402ffff // addiu $v0, $zero, -1
    .word 0x34c30001 // ori $v1, $a2, 1
    .word 0x0045102a // slt $v0, $v0, $a1
    .word 0x0062300a // movz $a2, $v1, $v0
    .word 0x03e00008 // jr $ra
    .word 0xac86000c // sw $a2, 0xc($a0)
}
#else
void func_0012EFB0(TargetStruct *s, s32 val) {
    if (val > 0) {
        s->field_c |= 2;
    } else if (val < 0) {
        s->field_c |= 1;
    }
}
#endif

}
