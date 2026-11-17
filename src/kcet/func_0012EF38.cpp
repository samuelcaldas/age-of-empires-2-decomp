#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void *func_0012EF38(void *a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2) {
    .word 0x27bdffe0 // 0012EF38:  addiu $sp, $sp, -0x20
    .word 0x0080102d // 0012EF3C:  move $v0, $a0
    .word 0xffbf0010 // 0012EF40:  sd $ra, 0x10($sp)
    .word 0x244400b4 // 0012EF44:  addiu $a0, $v0, 0xb4
    .word 0xafa70000 // 0012EF48:  sw $a3, ($sp)
    .word 0xac450000 // 0012EF4C:  sw $a1, ($v0)
    .word 0xac4600b0 // 0012EF50:  sw $a2, 0xb0($v0)
    .word 0x24050020 // 0012EF54:  addiu $a1, $zero, 0x20
    .word 0xac400004 // 0012EF58:  sw $zero, 4($v0)
    .word 0xac400008 // 0012EF5C:  sw $zero, 8($v0)
    .word 0x8ba30003 // 0012EF60:  lwl $v1, 3($sp)
    .word 0x9ba30000 // 0012EF64:  lwr $v1, ($sp)
    .word 0xa843000f // 0012EF68:  swl $v1, 0xf($v0)
    .word 0xb843000c // 0012EF6C:  swr $v1, 0xc($v0)
    .word 0xac480010 // 0012EF70:  sw $t0, 0x10($v0)
    .word 0xac490034 // 0012EF74:  sw $t1, 0x34($v0)
    .word 0xac4a00a8 // 0012EF78:  sw $t2, 0xa8($v0)
    .word 0xac400014 // 0012EF7C:  sw $zero, 0x14($v0)
    .word 0xac400018 // 0012EF80:  sw $zero, 0x18($v0)
    .word 0xac40001c // 0012EF84:  sw $zero, 0x1c($v0)
    .word 0xac400020 // 0012EF88:  sw $zero, 0x20($v0)
    .word 0xac400024 // 0012EF8C:  sw $zero, 0x24($v0)
    .word 0xac400028 // 0012EF90:  sw $zero, 0x28($v0)
    .word 0xac400030 // 0012EF94:  sw $zero, 0x30($v0)
    .word 0x0c0450f0 // 0012EF98:  jal 0x1143c0
    .word 0xac4000ac // 0012EF9C:  sw $zero, 0xac($v0)
    .word 0xdfbf0010 // 0012EFA0:  ld $ra, 0x10($sp)
    .word 0x03e00008 // 0012EFA4:  jr $ra
    .word 0x27bd0020 // 0012EFA8:  addiu $sp, $sp, 0x20
}
#else

void func_001143C0(void *ptr, s32 size);

struct Struct0012EF38 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u32 pad_2c;
    u32 field_30;
    u32 field_34;
    u8 pad_38[0x70];
    u32 field_a8;
    u32 field_ac;
    u32 field_b0;
    u8 field_b4[0x20];
};

Struct0012EF38 *func_0012EF38(Struct0012EF38 *s, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2) {
    s->field_0 = a1;
    s->field_b0 = a2;
    s->field_4 = 0;
    s->field_8 = 0;
    s->field_c = a3;
    s->field_10 = t0;
    s->field_34 = t1;
    s->field_a8 = t2;
    s->field_14 = 0;
    s->field_18 = 0;
    s->field_1c = 0;
    s->field_20 = 0;
    s->field_24 = 0;
    s->field_28 = 0;
    s->field_30 = 0;
    func_001143C0(s->field_b4, 0x20);
    s->field_ac = 0;
    return s;
}

#endif

}
