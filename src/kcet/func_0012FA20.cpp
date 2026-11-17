#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012FA20(void) {
    .word 0x3c020050 // lui $v0, 0x50
    .word 0x03e00008 // jr $ra
    .word 0xac409800 // sw $zero, -0x6800($v0)
}
#else
extern u32 D_004F9800;

void func_0012FA20(void) {
    D_004F9800 = 0;
}
#endif

}
