/* Function: func_0012DDC0 (0x0012DDC0 - 0x0012DE28)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm u32 func_0012DDC0(u32 a0) {
    .word 0x27bdffd0 // 0012DDC0:  addiu $sp, $sp, -0x30
    .word 0x3c020049 // 0012DDC4:  lui $v0, 0x49
    .word 0xffbf0020 // 0012DDC8:  sd $ra, 0x20($sp)
    .word 0x03a0282d // 0012DDCC:  move $a1, $sp
    .word 0x2449ffb0 // 0012DDD0:  addiu $t1, $v0, -0x50
    .word 0x69230007 // 0012DDD4:  ldl $v1, 7($t1)
    .word 0x6d230000 // 0012DDD8:  ldr $v1, ($t1)
    .word 0x6927000f // 0012DDDC:  ldl $a3, 0xf($t1)
    .word 0x6d270008 // 0012DDE0:  ldr $a3, 8($t1)
    .word 0x69280017 // 0012DDE4:  ldl $t0, 0x17($t1)
    .word 0x6d280010 // 0012DDE8:  ldr $t0, 0x10($t1)
    .word 0xb3a30007 // 0012DDEC:  sdl $v1, 7($sp)
    .word 0xb7a30000 // 0012DDF0:  sdr $v1, ($sp)
    .word 0xb3a7000f // 0012DDF4:  sdl $a3, 0xf($sp)
    .word 0xb7a70008 // 0012DDF8:  sdr $a3, 8($sp)
    .word 0xb3a80017 // 0012DDFC:  sdl $t0, 0x17($sp)
    .word 0xb7a80010 // 0012DE00:  sdr $t0, 0x10($sp)
    .word 0x6923001f // 0012DE04:  ldl $v1, 0x1f($t1)
    .word 0x6d230018 // 0012DE08:  ldr $v1, 0x18($t1)
    .word 0xb3a3001f // 0012DE0C:  sdl $v1, 0x1f($sp)
    .word 0xb7a30018 // 0012DE10:  sdr $v1, 0x18($sp)
    .word 0x0c04b740 // 0012DE14:  jal 0x12dd00
    .word 0x24060004 // 0012DE18:  addiu $a2, $zero, 4
    .word 0xdfbf0020 // 0012DE1C:  ld $ra, 0x20($sp)
    .word 0x03e00008 // 0012DE20:  jr $ra
    .word 0x27bd0030 // 0012DE24:  addiu $sp, $sp, 0x30
}
#else

struct KeyVal {
    u32 key;
    u32 val;
};

extern const KeyVal D_0048FFB0[4];
u32 func_0012DD00(u32 key, const KeyVal* items, s32 count);

u32 func_0012DDC0(u32 a0) {
    KeyVal items[4];
    for (s32 i = 0; i < 4; i++) {
        items[i] = D_0048FFB0[i];
    }
    return func_0012DD00(a0, items, 4);
}

#endif

}
