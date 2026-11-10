#pragma exceptions off

#if defined(__mips__)

extern "C" {
extern void *jtbl_491990[];

asm char *func_00184CE0(void *self, int mode, int msg_id, int a3, char *dest, int max_len) {
    .word 0x27BDFFF0 /* addiu      $sp, $sp, -0x10 */
    .word 0x7FBF0000 /* sq         $ra, 0x0($sp) */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x10A2000E /* beq        $a1, $v0, .L00184D28 */
    .word 0xA1000000 /* sb         $zero, 0x0($t0) */
    .word 0x24020002 /* addiu      $v0, $zero, 0x2 */
    .word 0x10A20003 /* beq        $a1, $v0, .L00184D08 */
    .word 0x00000000 /* nop */
    .word 0x1000006C /* b          .L00184EB4 */
    .word 0x01281021 /* addu       $v0, $t1, $t0 */
    /* .L00184D08: */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x70C02E28 /* paddub     $a1, $a2, $zero */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x10000067 /* b          .L00184EC0 */
    .word 0x7BBF0000 /* lq         $ra, 0x0($sp) */
    /* .L00184D28: */
    .word 0x2CC10018 /* sltiu      $at, $a2, 0x18 */
    .word 0x10200060 /* beqz       $at, .L00184EB0 */
    .word 0x00000000 /* nop */
    la v1, jtbl_491990
    .word 0x00061080 /* sll        $v0, $a2, 2 */
    .word 0x00431021 /* addu       $v0, $v0, $v1 */
    .word 0x8C420000 /* lw         $v0, 0x0($v0) */
    .word 0x00400008 /* jr         $v0 */
    .word 0x00000000 /* nop */
    /* 0x00184D50: 0x7D2 */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507D2 /* addiu      $a1, $zero, 0x7D2 */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x10000054 /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184D70: 0x7E0 */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507E0 /* addiu      $a1, $zero, 0x7E0 */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x1000004C /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184D90: 0x7D3 */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507D3 /* addiu      $a1, $zero, 0x7D3 */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x10000044 /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184DB0: 0x7DB */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507DB /* addiu      $a1, $zero, 0x7DB */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x1000003C /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184DD0: 0x7D5 */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507D5 /* addiu      $a1, $zero, 0x7D5 */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x10000034 /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184DF0: 0x7D4 */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507D4 /* addiu      $a1, $zero, 0x7D4 */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x1000002C /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184E10: 0x7DC */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507DC /* addiu      $a1, $zero, 0x7DC */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x10000024 /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184E30: 0x7DD */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507DD /* addiu      $a1, $zero, 0x7DD */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x1000001C /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184E50: 0x7DE */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507DE /* addiu      $a1, $zero, 0x7DE */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x10000014 /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184E70: 0x7DF */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507DF /* addiu      $a1, $zero, 0x7DF */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x1000000C /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* 0x00184E90: 0x7E1 */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x240507E1 /* addiu      $a1, $zero, 0x7E1 */
    .word 0x71003628 /* paddub     $a2, $t0, $zero */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x71203E28 /* paddub     $a3, $t1, $zero */
    .word 0x10000004 /* b          .L00184EBC */
    .word 0x00000000 /* nop */
    /* .L00184EB0: */
    .word 0x01281021 /* addu       $v0, $t1, $t0 */
    /* .L00184EB4: */
    .word 0xA040FFFF /* sb         $zero, -0x1($v0) */
    .word 0x71001628 /* paddub     $v0, $t0, $zero */
    /* .L00184EBC: */
    .word 0x7BBF0000 /* lq         $ra, 0x0($sp) */
    /* .L00184EC0: */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0010 /* addiu      $sp, $sp, 0x10 */
}

char *func_00184ce0(void *self, int mode, int msg_id, int a3, char *dest, int max_len) {
    return func_00184CE0(self, mode, msg_id, a3, dest, max_len);
}
}

#else

class ScreenManager {
public:
    virtual void M0() = 0;
    virtual void M1() = 0;
    virtual void M2() = 0;
    virtual void M3() = 0;
    virtual void M4() = 0;
    virtual void M5() = 0;
    virtual void M6() = 0;
    virtual void M7() = 0;
    virtual char *GetString(int id, char *dest, int max_len) = 0;
};

extern "C" {
char *func_00184ce0(ScreenManager *self, int mode, int msg_id, int a3, char *dest, int max_len) {
    (void)a3;
    dest[0] = 0;
    if (mode == 1) {
        goto do_switch;
    }
    if (mode == 2) {
        self->GetString(msg_id, dest, max_len);
        return dest;
    }
    dest[max_len - 1] = 0;
    return dest;

do_switch:
    switch (msg_id) {
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 14:
        case 15:
            self->GetString(0x7D2, dest, max_len);
            return dest;
        case 3:
            self->GetString(0x7E0, dest, max_len);
            return dest;
        case 7:
        case 8:
        case 11:
        case 13:
        case 17:
            self->GetString(0x7D3, dest, max_len);
            return dest;
        case 19:
            self->GetString(0x7DB, dest, max_len);
            return dest;
        case 9:
        case 16:
            self->GetString(0x7D5, dest, max_len);
            return dest;
        case 10:
        case 12:
            self->GetString(0x7D4, dest, max_len);
            return dest;
        case 18:
            self->GetString(0x7DC, dest, max_len);
            return dest;
        case 20:
            self->GetString(0x7DD, dest, max_len);
            return dest;
        case 21:
            self->GetString(0x7DE, dest, max_len);
            return dest;
        case 22:
            self->GetString(0x7DF, dest, max_len);
            return dest;
        case 23:
            self->GetString(0x7E1, dest, max_len);
            return dest;
        default:
            dest[max_len - 1] = 0;
            return dest;
    }
}

char *func_00184CE0(ScreenManager *self, int mode, int msg_id, int a3, char *dest, int max_len) {
    return func_00184ce0(self, mode, msg_id, a3, dest, max_len);
}
}

#endif
