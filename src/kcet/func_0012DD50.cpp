/* Function: func_0012DD50 (0x0012DD50 - 0x0012DDBC)
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
asm u32 func_0012DD50(u32 a0) {
    .word 0x27bdffd0 // 0012DD50:  addiu $sp, $sp, -0x30
    .word 0x3c020049 // 0012DD54:  lui $v0, 0x49
    .word 0xffbf0020 // 0012DD58:  sd $ra, 0x20($sp)
    .word 0x24840001 // 0012DD5C:  addiu $a0, $a0, 1
    .word 0x03a0282d // 0012DD60:  move $a1, $sp
    .word 0x2449ff90 // 0012DD64:  addiu $t1, $v0, -0x70
    .word 0x69230007 // 0012DD68:  ldl $v1, 7($t1)
    .word 0x6d230000 // 0012DD6C:  ldr $v1, ($t1)
    .word 0x6927000f // 0012DD70:  ldl $a3, 0xf($t1)
    .word 0x6d270008 // 0012DD74:  ldr $a3, 8($t1)
    .word 0x69280017 // 0012DD78:  ldl $t0, 0x17($t1)
    .word 0x6d280010 // 0012DD7C:  ldr $t0, 0x10($t1)
    .word 0xb3a30007 // 0012DD80:  sdl $v1, 7($sp)
    .word 0xb7a30000 // 0012DD84:  sdr $v1, ($sp)
    .word 0xb3a7000f // 0012DD88:  sdl $a3, 0xf($sp)
    .word 0xb7a70008 // 0012DD8C:  sdr $a3, 8($sp)
    .word 0xb3a80017 // 0012DD90:  sdl $t0, 0x17($sp)
    .word 0xb7a80010 // 0012DD94:  sdr $t0, 0x10($sp)
    .word 0x6923001f // 0012DD98:  ldl $v1, 0x1f($t1)
    .word 0x6d230018 // 0012DD9C:  ldr $v1, 0x18($t1)
    .word 0xb3a3001f // 0012DDA0:  sdl $v1, 0x1f($sp)
    .word 0xb7a30018 // 0012DDA4:  sdr $v1, 0x18($sp)
    .word 0x0c04b740 // 0012DDA8:  jal 0x12dd00
    .word 0x24060004 // 0012DDAC:  addiu $a2, $zero, 4
    .word 0xdfbf0020 // 0012DDB0:  ld $ra, 0x20($sp)
    .word 0x03e00008 // 0012DDB4:  jr $ra
    .word 0x27bd0030 // 0012DDB8:  addiu $sp, $sp, 0x30
}
#else

struct KeyVal {
    u32 key;
    u32 val;
};

extern const KeyVal D_0048FF90[4];
u32 func_0012DD00(u32 key, const KeyVal* items, s32 count);

u32 func_0012DD50(u32 a0) {
    KeyVal items[4];
    for (s32 i = 0; i < 4; i++) {
        items[i] = D_0048FF90[i];
    }
    return func_0012DD00(a0 + 1, items, 4);
}

#endif

}
