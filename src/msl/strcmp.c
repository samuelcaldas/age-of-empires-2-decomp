#ifdef __MWERKS__
#pragma optimization_level 1
asm int strcmp(const char *s1, const char *s2) {
    or         $t0, $a0, $a1
    andi       $v0, $t0, 0x7
    bnel       $v0, $zero, @byte_check
    lb         $v0, 0x0($a0)
    andi       $t1, $t0, 0xF
    lui        $a3, 0x101
    ori        $a3, $a3, 0x101
    dsll       $a3, $a3, 16
    ori        $a3, $a3, 0x101
    dsll       $a3, $a3, 16
    ori        $a3, $a3, 0x101
    lui        $a2, 0x8080
    ori        $a2, $a2, 0x8080
    dsll       $a2, $a2, 16
    ori        $a2, $a2, 0x8080
    dsll       $a2, $a2, 16
    ori        $a2, $a2, 0x8080
    bnez       $t1, @dword_init
    ld         $v0, 0x0($a1)
    lq         $v1, 0x0($a0)
    pcpyld     $t0, $a3, $a3
    lq         $v0, 0x0($a1)
    pcpyld     $t2, $a2, $a2
    psubw      $a3, $v0, $v1
    pcpyud     $a2, $a3, $a0
    or         $v1, $a2, $a3
    bnel       $v1, $zero, @byte_check
    lb         $v0, 0x0($a0)
    lq         $v0, 0x0($a0)
    pnor       $v1, $zero, $v0
@qword_test_null:
    psubb      $v0, $v0, $t0
    pand       $v0, $v0, $v1
    pand       $v0, $v0, $t2
    pcpyud     $v1, $v0, $a0
    or         $a2, $v1, $v0
    beqz       $a2, @qword_advance
    addiu      $a0, $a0, 0x10
    jr         $ra
    daddu      $v0, $zero, $zero
@qword_advance:
    addiu      $a1, $a1, 0x10
    lq         $v0, 0x0($a0)
    lq         $v1, 0x0($a1)
    psubw      $a3, $v0, $v1
    pcpyud     $a2, $a3, $a0
    or         $t1, $a2, $a3
    beql       $t1, $zero, @qword_test_null
    pnor       $v1, $zero, $v0
    b          @byte_check
    lb         $v0, 0x0($a0)
@dword_init:
    ld         $v1, 0x0($a0)
    bnel       $v1, $v0, @byte_check
    lb         $v0, 0x0($a0)
    ld         $v0, 0x0($a0)
    nor        $t0, $zero, $v0
@dword_test_null:
    dsubu      $v0, $v0, $a3
    and        $v0, $v0, $t0
    and        $v0, $v0, $a2
    beqz       $v0, @dword_advance
    addiu      $a0, $a0, 0x8
    jr         $ra
    daddu      $v0, $zero, $zero
@dword_advance:
    addiu      $a1, $a1, 0x8
    ld         $v0, 0x0($a0)
    ld         $v1, 0x0($a1)
    beql       $v1, $v0, @dword_test_null
    nor        $t0, $zero, $v0
    b          @byte_check
    lb         $v0, 0x0($a0)
@byte_loop:
    sll        $v0, $v1, 24
    lb         $v1, 0x0($a1)
    sra        $v0, $v0, 24
    bnel       $v0, $v1, @diff
    lbu        $v1, 0x0($a0)
    addiu      $a0, $a0, 0x1
    addiu      $a1, $a1, 0x1
    lb         $v0, 0x0($a0)
@byte_check:
    bnez       $v0, @byte_loop
    lbu        $v1, 0x0($a0)
@diff:
    lbu        $v0, 0x0($a1)
    jr         $ra
    subu       $v0, $v1, $v0
}
#else
#include <string.h>
int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (int)((unsigned char)*s1 - (unsigned char)*s2);
}
#endif

int msl_strcmp(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}
