#ifdef __MWERKS__
asm char *strcpy(char *dest, const char *src) {
    daddu      $a3, $a0, $zero
    or         $t0, $a1, $a3
    andi       $v0, $t0, 0x7
    bnez       $v0, @byte_loop
    daddu      $v1, $a3, $zero
    andi       $v0, $t0, 0xF
    lui        $t1, 0x101
    ori        $t1, $t1, 0x101
    dsll       $t1, $t1, 16
    ori        $t1, $t1, 0x101
    dsll       $t1, $t1, 16
    ori        $t1, $t1, 0x101
    lui        $a0, 0x8080
    ori        $a0, $a0, 0x8080
    dsll       $a0, $a0, 16
    ori        $a0, $a0, 0x8080
    dsll       $a0, $a0, 16
    ori        $a0, $a0, 0x8080
    bnel       $v0, $zero, @doubleword_init
    ld         $t2, 0x0($a1)
    pcpyld     $t2, $t1, $t1
    lq         $t1, 0x0($a1)
    pcpyld     $t0, $a0, $a0
    psubb      $v0, $t1, $t2
    pnor       $v1, $zero, $t1
    pand       $v0, $v0, $v1
    pand       $v0, $v0, $t0
    pcpyud     $a0, $v0, $t1
    or         $v1, $v0, $a0
    bnez       $v1, @align_dest
    daddu      $a2, $a3, $zero
@quadword_loop:
    sq         $t1, 0x0($a2)
    addiu      $a1, $a1, 0x10
    lq         $t1, 0x0($a1)
    psubb      $v0, $t1, $t2
    pnor       $v1, $zero, $t1
    pand       $v0, $v0, $v1
    pand       $v0, $v0, $t0
    pcpyud     $a0, $v0, $t1
    or         $v1, $v0, $a0
    beqz       $v1, @quadword_loop
    addiu      $a2, $a2, 0x10
    b          @byte_loop
    daddu      $v1, $a2, $zero
@doubleword_init:
    dsubu      $v0, $t2, $t1
    nor        $v1, $zero, $t2
    and        $v0, $v0, $v1
    and        $v0, $v0, $a0
    bnez       $v0, @align_dest
    daddu      $a2, $a3, $zero
@doubleword_loop:
    sd         $t2, 0x0($a2)
    addiu      $a1, $a1, 0x8
    ld         $t2, 0x0($a1)
    nor        $v0, $zero, $t2
    dsubu      $v1, $t2, $t1
    and        $v1, $v1, $v0
    and        $v1, $v1, $a0
    beqz       $v1, @doubleword_loop
    addiu      $a2, $a2, 0x8
@align_dest:
    daddu      $v1, $a2, $zero
@byte_loop:
    lbu        $v0, 0x0($a1)
    addiu      $a1, $a1, 0x1
    sb         $v0, 0x0($v1)
    sll        $v0, $v0, 24
    nop
    bnez       $v0, @byte_loop
    addiu      $v1, $v1, 0x1
    jr         $ra
    daddu      $v0, $a3, $zero
}
#else
#include <string.h>
char *strcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++) != '\0') {
    }
    return dest;
}
#endif

char *msl_strcpy(char *dest, const char *src) {
    return strcpy(dest, src);
}
