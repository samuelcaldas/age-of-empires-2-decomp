/* Function: func_0012DBA0 (0x0012DBA0 - 0x0012DBBC)
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
asm void func_0012DBA0(void) {
    .word 0x27bdfff0 // 0012DBA0:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012DBA4:  sd $ra, ($sp)
    .word 0x0c043ed4 // 0012DBA8:  jal 0x10fb50
    .word 0x00000000 // 0012DBAC:  nop 
    .word 0xdfbf0000 // 0012DBB0:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DBB4:  jr $ra
    .word 0x27bd0010 // 0012DBB8:  addiu $sp, $sp, 0x10
}
#else

void func_0010FB50(void);

void func_0012DBA0(void) {
    func_0010FB50();
}

#endif

}
