#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012CCD8(void) {
    .word 0x3c04004f // 0012CCD8:  lui $a0, 0x4f
    .word 0x24050014 // 0012CCDC:  addiu $a1, $zero, 0x14
    .word 0x080450f0 // 0012CCE0:  j 0x1143c0
    .word 0x24841508 // 0012CCE4:  addiu $a0, $a0, 0x1508
}
#else

extern s32 D_004F1508;
void func_001143C0(void *ptr, s32 size);

void func_0012CCD8(void) {
    func_001143C0(&D_004F1508, 0x14);
}

#endif

}
