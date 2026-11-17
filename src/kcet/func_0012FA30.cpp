#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct TargetStruct {
    char pad[0x20];
    void *field_20;
};

extern "C" {

void func_0012F108(TargetStruct *a0, void *a1);

#if defined(__mips__)
asm void *func_0012FA30(void *a0, TargetStruct *a1, void *a2, void *a3) {
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0x00e0102d // move $v0, $a3
    .word 0x10800005 // beqz $a0, 0x12fa50
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0xaca40020 // sw $a0, 0x20($a1)
    .word 0x00a0202d // move $a0, $a1
    .word 0x0c04bc42 // jal 0x12f108
    .word 0x00c0282d // move $a1, $a2
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
}
#else
void *func_0012FA30(void *a0, TargetStruct *a1, void *a2, void *a3) {
    if (a0 != 0) {
        a1->field_20 = a0;
        func_0012F108(a1, a2);
    }
    return a3;
}
#endif

}
