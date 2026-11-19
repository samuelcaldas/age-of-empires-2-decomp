#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct sceDmaEnv {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u16 e;
    u16 f;
    u16 g;
    u16 h;
    u32 i;
    u32 j;
};

#pragma options align=packed
struct sceDmaEnvRaw {
    u8 raw[0x14];
};
#pragma options align=reset

extern "C" {

#if defined(__mips__)
asm sceDmaEnv *func_00103C10(sceDmaEnv *dst) {
    .word 0x3c030039 // 00103C10:  lui $v1, 0x39
    .word 0x24689c48 // 00103C14:  addiu $t0, $v1, -0x63b8
    .word 0x69050007 // 00103C18:  ldl $a1, 7($t0)
    .word 0x6d050000 // 00103C1C:  ldr $a1, ($t0)
    .word 0x6906000f // 00103C20:  ldl $a2, 0xf($t0)
    .word 0x6d060008 // 00103C24:  ldr $a2, 8($t0)
    .word 0x8d070010 // 00103C28:  lw $a3, 0x10($t0)
    .word 0xb0850007 // 00103C2C:  sdl $a1, 7($a0)
    .word 0xb4850000 // 00103C30:  sdr $a1, ($a0)
    .word 0xb086000f // 00103C34:  sdl $a2, 0xf($a0)
    .word 0xb4860008 // 00103C38:  sdr $a2, 8($a0)
    .word 0xac870010 // 00103C3C:  sw $a3, 0x10($a0)
    .word 0x03e00008 // 00103C40:  jr $ra
    .word 0x0080102d // 00103C44:  move $v0, $a0
}
#else
sceDmaEnv *func_00103C10(sceDmaEnv *dst) {
    *(sceDmaEnvRaw *)dst = *(const sceDmaEnvRaw *)0x389C48;
    return dst;
}
#endif

}
