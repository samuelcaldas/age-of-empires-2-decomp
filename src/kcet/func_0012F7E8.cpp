#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012F7E8(void) {
    .word 0x3c040050 // lui $a0, 0x50
    .word 0x24050600 // addiu $a1, $zero, 0x600
    .word 0x080450f0 // j 0x1143c0
    .word 0x24849840 // addiu $a0, $a0, -0x67c0
}
#else

extern u8 D_004F9840[];
void func_001143C0(void *ptr, s32 size);

void func_0012F7E8(void) {
    func_001143C0(D_004F9840, 0x600);
}

#endif

}
