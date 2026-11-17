/* Function: func_0012DBC0 (0x0012DBC0 - 0x0012DBD8)
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
asm void func_0012DBC0(void) {
    .word 0x27bdfff0 // 0012DBC0:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012DBC4:  sd $ra, ($sp)
    .word 0x0c043eae // 0012DBC8:  jal 0x10fab8
    .word 0x00000000 // 0012DBCC:  nop 
    .word 0xdfbf0000 // 0012DBD0:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DBD4:  jr $ra
    .word 0x27bd0010 // 0012DBD8:  addiu $sp, $sp, 0x10
}
#else

void func_0010FAB8(void);

void func_0012DBC0(void) {
    func_0010FAB8();
}

#endif

}
