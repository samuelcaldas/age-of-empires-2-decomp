#pragma exceptions off

typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm u32 func_0012F7A0(u32 a0, u32 a1) {
    .word 0x00041027 // nor $v0, $zero, $a0
    .word 0x00451024 // and $v0, $v0, $a1
    .word 0x03e00008 // jr $ra
    .word 0x2c420001 // sltiu $v0, $v0, 1
}
#else
u32 func_0012F7A0(u32 a0, u32 a1) {
    return ((~a0) & a1) == 0;
}
#endif

}
