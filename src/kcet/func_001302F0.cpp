#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

void* func_001113B0(void*, void*, void*, void*, void*);
void func_0012FA60(void*, void*);

#if defined(__mips__)
asm void func_001302F0(void* a0, void* a1, void* a2, void* a3, void* a4) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x0c0444ec // jal 0x1113b0
    .word 0x0100802d // move $s0, $t0
    .word 0x0200282d // move $a1, $s0
    .word 0x0c04be98 // jal 0x12fa60
    .word 0x0040202d // move $a0, $v0
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else
void func_001302F0(void* a0, void* a1, void* a2, void* a3, void* a4) {
    void* v0 = func_001113B0(a0, a1, a2, a3, a4);
    func_0012FA60(v0, a4);
}
#endif

}
