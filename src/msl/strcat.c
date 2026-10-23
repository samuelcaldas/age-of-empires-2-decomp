#ifdef __MWERKS__
extern char *strcpy(char *dest, const char *src);

asm char *strcat(char *dest, const char *src) {
    addiu      $sp, $sp, -0x20
    sq         $s0, 0x0($sp)
    daddu      $s0, $a0, $zero
    andi       $v0, $s0, 0x7
    bnez       $v0, @byte_loop
    sq         $ra, 0x10($sp)
    andi       $v0, $s0, 0xF
    lui        $v1, 0x101
    ori        $v1, $v1, 0x101
    dsll       $v1, $v1, 16
    ori        $v1, $v1, 0x101
    dsll       $v1, $v1, 16
    ori        $v1, $v1, 0x101
    lui        $a0, 0x8080
    ori        $a0, $a0, 0x8080
    dsll       $a0, $a0, 16
    ori        $a0, $a0, 0x8080
    dsll       $a0, $a0, 16
    ori        $a0, $a0, 0x8080
    bnez       $v0, @dword_init
    ld         $a2, 0x0($s0)
    lq         $v0, 0x0($s0)
    pcpyld     $a3, $v1, $v1
    pcpyld     $t0, $a0, $a0
    psubb      $v1, $v0, $a3
    pnor       $v0, $zero, $v0
    pand       $v1, $v1, $v0
    pand       $v1, $v1, $t0
    pcpyud     $v0, $v1, $v1
    or         $v1, $v0, $v1
    bnez       $v1, @byte_loop
    daddu      $a0, $s0, $zero
    addiu      $a2, $a0, 0x10
@qword_loop:
    lq         $v0, 0x0($a2)
    pnor       $v1, $zero, $v0
    psubb      $v0, $v0, $a3
    pand       $v0, $v0, $v1
    pand       $v0, $v0, $t0
    pcpyud     $v1, $v0, $v0
    or         $v0, $v0, $v1
    beql       $v0, $zero, @qword_loop
    addiu      $a2, $a2, 0x10
    b          @byte_loop
    daddu      $a0, $a2, $zero
@dword_init:
    daddu      $a3, $v1, $zero
    daddu      $t0, $a0, $zero
    dsubu      $v1, $a2, $v1
    nor        $v0, $zero, $a2
    and        $v1, $v1, $v0
    and        $v1, $v1, $a0
    bnez       $v1, @byte_loop
    daddu      $a0, $s0, $zero
    addiu      $a2, $s0, 0x8
@dword_loop:
    ld         $v0, 0x0($a2)
    nor        $v1, $zero, $v0
    dsubu      $v0, $v0, $a3
    and        $v0, $v0, $v1
    and        $v0, $v0, $t0
    beql       $v0, $zero, @dword_loop
    addiu      $a2, $a2, 0x8
    daddu      $a0, $a2, $zero
@byte_loop:
    lb         $v0, 0x0($a0)
    nop
    nop
    nop
    nop
    bnel       $v0, $zero, @byte_loop
    addiu      $a0, $a0, 0x1
    jal        strcpy
    nop
    daddu      $v0, $s0, $zero
    lq         $ra, 0x10($sp)
    lq         $s0, 0x0($sp)
    jr         $ra
    addiu      $sp, $sp, 0x20
}
#else
#include <string.h>
char *strcat(char *dest, const char *src) {
    char *d = dest;
    while (*d != '\0') {
        d++;
    }
    while ((*d++ = *src++) != '\0') {
    }
    return dest;
}
#endif

char *msl_strcat(char *dest, const char *src) {
    return strcat(dest, src);
}
