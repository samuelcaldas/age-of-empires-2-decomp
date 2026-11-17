#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm u32 func_0012E928(u32 a0) {
    .word 0x27bdfff0 // 0012E928:  addiu $sp, $sp, -0x10
    .word 0x3c050049 // 0012E92C:  lui $a1, 0x49
    .word 0xffbf0000 // 0012E930:  sd $ra, ($sp)
    .word 0x24a50130 // 0012E934:  addiu $a1, $a1, 0x130
    .word 0x0c04b740 // 0012E938:  jal 0x12dd00
    .word 0x2406000b // 0012E93C:  addiu $a2, $zero, 0xb
    .word 0xdfbf0000 // 0012E940:  ld $ra, ($sp)
    .word 0x03e00008 // 0012E944:  jr $ra
    .word 0x27bd0010 // 0012E948:  addiu $sp, $sp, 0x10
}
#else

struct KeyVal {
    u32 key;
    u32 val;
};

extern const KeyVal D_00490130[];
u32 func_0012DD00(u32 a0, const KeyVal* a1, s32 a2);

u32 func_0012E928(u32 a0) {
    return func_0012DD00(a0, D_00490130, 11);
}

#endif

}
