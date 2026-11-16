/* Function: func_0012BB20 (0x0012BB20 - 0x0012BB4C)
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
asm void func_0012BB20(void) {
    .word 0x27bdfff0 // 0012BB20:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012BB24:  sd $ra, ($sp)
    .word 0x0c04ae68 // 0012BB28:  jal 0x12b9a0
    .word 0x00000000 // 0012BB2C:  nop 
    .word 0x0c04ab1e // 0012BB30:  jal 0x12ac78
    .word 0x00000000 // 0012BB34:  nop 
    .word 0x0c04ab56 // 0012BB38:  jal 0x12ad58
    .word 0x00000000 // 0012BB3C:  nop 
    .word 0xdfbf0000 // 0012BB40:  ld $ra, ($sp)
    .word 0x0804ab98 // 0012BB44:  j 0x12ae60
    .word 0x27bd0010 // 0012BB48:  addiu $sp, $sp, 0x10
}
#else

void func_0012B9A0(void);
void func_0012AC78(void);
void func_0012AD58(void);
void func_0012AE60(void);

void func_0012BB20(void) {
    func_0012B9A0();
    func_0012AC78();
    func_0012AD58();
    func_0012AE60();
}

#endif

}
