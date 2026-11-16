/* Function: func_0012BFF0 (0x0012BFF0 - 0x0012C05C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
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
asm void func_0012BFF0(void *arg0, s32 arg1, s32 arg2) {
    .word 0x27bdffd0 // 0012BFF0:  addiu $sp, $sp, -0x30
    .word 0xffb10010 // 0012BFF4:  sd $s1, 0x10($sp)
    .word 0xffb00000 // 0012BFF8:  sd $s0, ($sp)
    .word 0x00c0882d // 0012BFFC:  move $s1, $a2
    .word 0x0080802d // 0012C000:  move $s0, $a0
    .word 0xffbf0020 // 0012C004:  sd $ra, 0x20($sp)
    .word 0xae110028 // 0012C008:  sw $s1, 0x28($s0)
    .word 0x0c04a552 // 0012C00C:  jal 0x129548
    .word 0xae050000 // 0012C010:  sw $a1, ($s0)
    .word 0x0c04af04 // 0012C014:  jal 0x12bc10
    .word 0xae02002c // 0012C018:  sw $v0, 0x2c($s0)
    .word 0x0c04d110 // 0012C01C:  jal 0x134440
    .word 0x0040202d // 0012C020:  move $a0, $v0
    .word 0x12200009 // 0012C024:  beqz $s1, 0x12c04c
    .word 0xdfbf0020 // 0012C028:  ld $ra, 0x20($sp)
    .word 0x0c04af08 // 0012C02C:  jal 0x12bc20
    .word 0x00000000 // 0012C030:  nop 
    .word 0xdfbf0020 // 0012C034:  ld $ra, 0x20($sp)
    .word 0x0040202d // 0012C038:  move $a0, $v0
    .word 0xdfb10010 // 0012C03C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C040:  ld $s0, ($sp)
    .word 0x0804d140 // 0012C044:  j 0x134500
    .word 0x27bd0030 // 0012C048:  addiu $sp, $sp, 0x30
    .word 0xdfb10010 // 0012C04C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C050:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C054:  jr $ra
    .word 0x27bd0030 // 0012C058:  addiu $sp, $sp, 0x30
}
#else

int func_00129548(void);
int func_0012BC10(void);
int func_0012BC20(void);
void func_00134440(int);
void func_00134500(int);

struct CdvdContext {
    s32 field_00;
    u8 pad_04[0x24];
    s32 field_28;
    s32 field_2c;
};

void func_0012BFF0(CdvdContext *ctx, s32 arg1, s32 arg2) {
    ctx->field_28 = arg2;
    ctx->field_00 = arg1;
    ctx->field_2c = func_00129548();
    func_00134440(func_0012BC10());
    if (arg2 != 0) {
        func_00134500(func_0012BC20());
    }
}

#endif

}
