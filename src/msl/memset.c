#ifdef __MWERKS__
#pragma optimization_level 1
asm void *memset(void *dest, int c, unsigned int n) {
    sltiu      $v0, $a2, 0x8
    bnez       $v0, @byte_init
    daddu      $v1, $a0, $zero
    andi       $v0, $a0, 0xF
    bnez       $v0, @byte_init
    daddu      $a3, $a0, $zero
    andi       $t1, $a1, 0xFF
    sltiu      $t2, $a2, 0x20
    daddu      $t0, $t1, $zero
    dsll       $v1, $t0, 8
    or         $t0, $v1, $t1
    pcpyh      $v1, $t0
    bnez       $t2, @dword_check
    sltiu      $v0, $a2, 0x8
    pcpyld     $t0, $v1, $v1
@qword_loop:
    sq         $t0, 0x0($a3)
    addiu      $a2, $a2, -0x20
    addiu      $a3, $a3, 0x10
    sltiu      $v0, $a2, 0x20
    sq         $t0, 0x0($a3)
    beqz       $v0, @qword_loop
    addiu      $a3, $a3, 0x10
    b          @dword_check
    sltiu      $v0, $a2, 0x8
@dword_loop:
    addiu      $a2, $a2, -0x8
    addiu      $a3, $a3, 0x8
    sltiu      $v0, $a2, 0x8
@dword_check:
    nop
    nop
    beql       $v0, $zero, @dword_loop
    sd         $v1, 0x0($a3)
    daddu      $v1, $a3, $zero
@byte_init:
    lui        $v0, 0xFFFF
    addiu      $a2, $a2, -0x1
    ori        $v0, $v0, 0xFFFF
    beq        $a2, $v0, @done
    nop
    lui        $v0, 0xFFFF
    ori        $v0, $v0, 0xFFFF
@byte_loop:
    sb         $a1, 0x0($v1)
    addiu      $a2, $a2, -0x1
    nop
    nop
    nop
    bne        $a2, $v0, @byte_loop
    addiu      $v1, $v1, 0x1
@done:
    jr         $ra
    daddu      $v0, $a0, $zero
}
#else
#include <stddef.h>
void *memset(void *dest, int c, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)dest;
    unsigned char val = (unsigned char)c;
    while (n--) {
        *p++ = val;
    }
    return dest;
}
#endif

void *msl_memset(void *dest, int c, unsigned int n) {
    return memset(dest, c, n);
}
