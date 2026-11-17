#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E118(void) {
    .word 0x27bdffd0 // 0012E118:  addiu $sp, $sp, -0x30
    .word 0x0000202d // 0012E11C:  move $a0, $zero
    .word 0xffb00010 // 0012E120:  sd $s0, 0x10($sp)
    .word 0x03a0282d // 0012E124:  move $a1, $sp
    .word 0xffbf0020 // 0012E128:  sd $ra, 0x20($sp)
    .word 0x0c044250 // 0012E12C:  jal 0x110940
    .word 0x37a60004 // 0012E130:  ori $a2, $sp, 4
    .word 0x3c030050 // 0012E134:  lui $v1, 0x50
    .word 0x247097d8 // 0012E138:  addiu $s0, $v1, -0x6828
    .word 0x8e02004c // 0012E13C:  lw $v0, 0x4c($s0)
    .word 0x30420001 // 0012E140:  andi $v0, $v0, 1
    .word 0x10400007 // 0012E144:  beqz $v0, 0x12e164
    .word 0xae000004 // 0012E148:  sw $zero, 4($s0)
    .word 0x0c045bda // 0012E14C:  jal 0x116f68
    .word 0x8c6497d8 // 0012E150:  lw $a0, -0x6828($v1)
    .word 0x8e02004c // 0012E154:  lw $v0, 0x4c($s0)
    .word 0x2403fffe // 0012E158:  addiu $v1, $zero, -2
    .word 0x00431024 // 0012E15C:  and $v0, $v0, $v1
    .word 0xae02004c // 0012E160:  sw $v0, 0x4c($s0)
    .word 0xdfbf0020 // 0012E164:  ld $ra, 0x20($sp)
    .word 0xdfb00010 // 0012E168:  ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012E16C:  jr $ra
    .word 0x27bd0030 // 0012E170:  addiu $sp, $sp, 0x30
}
#else

void func_00110940(s32 a0, void* a1, void* a2);
void func_00116F68(s32 a0);

struct KtFileContext {
    s32 field_00;
    s32 field_04;
    u8 pad_08_4B[0x48 - 4];
    s32 flags_4C;
};

extern KtFileContext D_004F97D8;

void func_0012E118(void) {
    u32 buf[2];
    func_00110940(0, &buf[0], &buf[1]);
    if (D_004F97D8.flags_4C & 1) {
        D_004F97D8.field_04 = 0;
        func_00116F68(D_004F97D8.field_00);
        D_004F97D8.flags_4C &= ~1;
    }
}

#endif

}
