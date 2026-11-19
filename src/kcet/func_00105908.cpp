#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm void func_00105908(void) {
    .word 0x27bdfff0 // 00105908:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0010590C:  sd $ra, ($sp)
    .word 0x0c0412b4 // 00105910:  jal 0x104ad0
    .word 0x00000000 // 00105914:  nop 
    .word 0x0000000f // 00105918:  sync 
    .word 0xdfbf0000 // 0010591C:  ld $ra, ($sp)
    .word 0x03e00008 // 00105920:  jr $ra
    .word 0x27bd0010 // 00105924:  addiu $sp, $sp, 0x10
}
#else
void func_00104ad0(void);

void func_00105908(void) {
    func_00104ad0();
#if defined(__MWERKS__)
    asm {
        sync
    }
#endif
}
#endif

}
