/* Function: func_0012DD00 (0x0012DD00 - 0x0012DD50)
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
asm u32 func_0012DD00(u32 key, void* list, s32 count) {
    .word 0x3c02004e // 0012DD00: lui $v0, 0x4e
    .word 0x0000382d // 0012DD04: move $a3, $zero
    .word 0x18c0000f // 0012DD08: blez $a2, 0x12dd48
    .word 0x24482cb8 // 0012DD0C: addiu $t0, $v0, 0x2cb8
    .word 0x8ca20000 // 0012DD10: lw $v0, ($a1)
    .word 0x14440004 // 0012DD14: bne $v0, $a0, 0x12dd28
    .word 0x24e70001 // 0012DD18: addiu $a3, $a3, 1
    .word 0x1000000a // 0012DD1C: b 0x12dd48
    .word 0x8ca80004 // 0012DD20: lw $t0, 4($a1)
    .word 0x00000000 // 0012DD24: nop 
    .word 0x00e6102a // 0012DD28: slt $v0, $a3, $a2
    .word 0x10400006 // 0012DD2C: beqz $v0, 0x12dd48
    .word 0x000710c0 // 0012DD30: sll $v0, $a3, 3
    .word 0x00451021 // 0012DD34: addu $v0, $v0, $a1
    .word 0x8c430000 // 0012DD38: lw $v1, ($v0)
    .word 0x1464fffa // 0012DD3C: bne $v1, $a0, 0x12dd28
    .word 0x24e70001 // 0012DD40: addiu $a3, $a3, 1
    .word 0x8c480004 // 0012DD44: lw $t0, 4($v0)
    .word 0x03e00008 // 0012DD48: jr $ra
    .word 0x0100102d // 0012DD4C: move $v0, $t0
}
#else

struct KeyVal {
    u32 key;
    u32 val;
};

extern u32 D_004E2CB8;

u32 func_0012DD00(u32 key, const KeyVal* items, s32 count) {
    if (count <= 0) {
        return (u32)&D_004E2CB8;
    }
    for (s32 i = 0; i < count; i++) {
        if (items[i].key == key) {
            return items[i].val;
        }
    }
    return (u32)&D_004E2CB8;
}

#endif

}
