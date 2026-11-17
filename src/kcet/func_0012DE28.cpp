/* Function: func_0012DE28 (0x0012DE28 - 0x0012DEA0)
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
asm u32 func_0012DE28(u32 a0) {
    .word 0x27bdffc0 // 0012DE28:  addiu $sp, $sp, -0x40
    .word 0x3c020049 // 0012DE2C:  lui $v0, 0x49
    .word 0xffbf0030 // 0012DE30:  sd $ra, 0x30($sp)
    .word 0x03a0282d // 0012DE34:  move $a1, $sp
    .word 0x24490010 // 0012DE38:  addiu $t1, $v0, 0x10
    .word 0x69230007 // 0012DE3C:  ldl $v1, 7($t1)
    .word 0x6d230000 // 0012DE40:  ldr $v1, ($t1)
    .word 0x6927000f // 0012DE44:  ldl $a3, 0xf($t1)
    .word 0x6d270008 // 0012DE48:  ldr $a3, 8($t1)
    .word 0x69280017 // 0012DE4C:  ldl $t0, 0x17($t1)
    .word 0x6d280010 // 0012DE50:  ldr $t0, 0x10($t1)
    .word 0xb3a30007 // 0012DE54:  sdl $v1, 7($sp)
    .word 0xb7a30000 // 0012DE58:  sdr $v1, ($sp)
    .word 0xb3a7000f // 0012DE5C:  sdl $a3, 0xf($sp)
    .word 0xb7a70008 // 0012DE60:  sdr $a3, 8($sp)
    .word 0xb3a80017 // 0012DE64:  sdl $t0, 0x17($sp)
    .word 0xb7a80010 // 0012DE68:  sdr $t0, 0x10($sp)
    .word 0x6923001f // 0012DE6C:  ldl $v1, 0x1f($t1)
    .word 0x6d230018 // 0012DE70:  ldr $v1, 0x18($t1)
    .word 0x69270027 // 0012DE74:  ldl $a3, 0x27($t1)
    .word 0x6d270020 // 0012DE78:  ldr $a3, 0x20($t1)
    .word 0xb3a3001f // 0012DE7C:  sdl $v1, 0x1f($sp)
    .word 0xb7a30018 // 0012DE80:  sdr $v1, 0x18($sp)
    .word 0xb3a70027 // 0012DE84:  sdl $a3, 0x27($sp)
    .word 0xb7a70020 // 0012DE88:  sdr $a3, 0x20($sp)
    .word 0x0c04b740 // 0012DE8C:  jal 0x12dd00
    .word 0x24060005 // 0012DE90:  addiu $a2, $zero, 5
    .word 0xdfbf0030 // 0012DE94:  ld $ra, 0x30($sp)
    .word 0x03e00008 // 0012DE98:  jr $ra
    .word 0x27bd0040 // 0012DE9C:  addiu $sp, $sp, 0x40
}
#else

struct KeyVal {
    u32 key;
    u32 val;
};

extern const KeyVal D_00490010[5];
u32 func_0012DD00(u32 key, const KeyVal* items, s32 count);

u32 func_0012DE28(u32 a0) {
    KeyVal items[5];
    for (s32 i = 0; i < 5; i++) {
        items[i] = D_00490010[i];
    }
    return func_0012DD00(a0, items, 5);
}

#endif

}
