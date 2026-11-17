#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E1C0(void* ptr) {
    .word 0x27bdffd0 // 0012E1C0:  addiu $sp, $sp, -0x30
    .word 0xffb00000 // 0012E1C4:  sd $s0, ($sp)
    .word 0xffbf0020 // 0012E1C8:  sd $ra, 0x20($sp)
    .word 0x0080802d // 0012E1CC:  move $s0, $a0
    .word 0xffb10010 // 0012E1D0:  sd $s1, 0x10($sp)
    .word 0x8e11000c // 0012E1D4:  lw $s1, 0xc($s0)
    .word 0x32220001 // 0012E1D8:  andi $v0, $s1, 1
    .word 0x10400006 // 0012E1DC:  beqz $v0, 0x12e1f8
    .word 0xdfbf0020 // 0012E1E0:  ld $ra, 0x20($sp)
    .word 0x0c045bda // 0012E1E4:  jal 0x116f68
    .word 0x8e040008 // 0012E1E8:  lw $a0, 8($s0)
    .word 0x3a220001 // 0012E1EC:  xori $v0, $s1, 1
    .word 0xae02000c // 0012E1F0:  sw $v0, 0xc($s0)
    .word 0xdfbf0020 // 0012E1F4:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012E1F8:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012E1FC:  ld $s0, ($sp)
    .word 0x03e00008 // 0012E200:  jr $ra
    .word 0x27bd0030 // 0012E204:  addiu $sp, $sp, 0x30
}
#else

void func_00116F68(void* ptr);

struct TargetStruct {
    u32 unk0;
    u32 unk4;
    void* ptr8;
    u32 flagsC;
};

void func_0012E1C0(TargetStruct* s) {
    if (s->flagsC & 1) {
        func_00116F68(s->ptr8);
        s->flagsC ^= 1;
    }
}

#endif

}
