/* Function: func_0012BC40 (0x0012BC40 - 0x0012BC60)
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
asm void func_0012BC40(void) {
    .word 0x3c02004f // 0012BC40:  lui $v0, 0x4f
    .word 0x2442d300 // 0012BC44:  addiu $v0, $v0, -0x2d00
    .word 0x8c430068 // 0012BC48:  lw $v1, 0x68($v0)
    .word 0x10600002 // 0012BC4C:  beqz $v1, 0x12bc58
    .word 0x2463ffff // 0012BC50:  addiu $v1, $v1, -1
    .word 0xac430068 // 0012BC54:  sw $v1, 0x68($v0)
    .word 0x03e00008 // 0012BC58:  jr $ra
    .word 0x00000000 // 0012BC5C:  nop 
}
#else

struct CdvdServerData {
    u8 pad[0x68];
    s32 f_68;
};

extern CdvdServerData D_004ED300;

void func_0012BC40(void) {
    if (D_004ED300.f_68 != 0) {
        D_004ED300.f_68--;
    }
}

#endif

}
