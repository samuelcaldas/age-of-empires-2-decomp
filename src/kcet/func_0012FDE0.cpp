#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

void* func_00110410(void*, void*);
void func_0012FA60(void*, void*);

#if defined(__mips__)
asm void func_0012FDE0(void* a0, void* a1) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x0c044104 // jal 0x110410
    .word 0x00a0802d // move $s0, $a1
    .word 0x0200282d // move $a1, $s0
    .word 0x0c04be98 // jal 0x12fa60
    .word 0x0040202d // move $a0, $v0
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else
void func_0012FDE0(void* a0, void* a1) {
    void* v0 = func_00110410(a0, a1);
    func_0012FA60(v0, a1);
}
#endif

}
