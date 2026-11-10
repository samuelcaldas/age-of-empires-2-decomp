#pragma exceptions off

#if defined(__mips__)

extern "C" {
int func_001C1FD0(void *ctx, char *dest, int size);

asm void *func_00184C28(void *self, int p1) {
    .word 0x00000000 /* nop */
    .word 0x00000000 /* nop */
    .word 0x27BDFFF0 /* addiu      $sp, $sp, -0x10 */
    .word 0x7FBF0000 /* sq         $ra, 0x0($sp) */
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x3C020056 /* lui        $v0, 0x56 */
    .word 0x24466EC0 /* addiu      $a2, $v0, 0x6EC0 */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x24070200 /* addiu      $a3, $zero, 0x200 */
    .word 0x7BBF0000 /* lq         $ra, 0x0($sp) */
    .word 0x3C020056 /* lui        $v0, 0x56 */
    .word 0x24426EC0 /* addiu      $v0, $v0, 0x6EC0 */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0010 /* addiu      $sp, $sp, 0x10 */
}

asm char *func_00184C70(void *self, int a1, char *dest, int size) {
    .word 0x27BDFFD0 /* addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x8F848950 /* lw         $a0, -0x76B0($gp) */
    .word 0x70C08E28 /* paddub     $s1, $a2, $zero */
    jal func_001C1FD0
    .word 0x70E08628 /* paddub     $s0, $a3, $zero */
    .word 0x14400003 /* bnez       $v0, .L00184CA0 */
    .word 0x02111021 /* addu       $v0, $s0, $s1 */
    .word 0xA2200000 /* sb         $zero, 0x0($s1) */
    .word 0x02111021 /* addu       $v0, $s0, $s1 */
    .word 0xA040FFFF /* sb         $zero, -0x1($v0) */
    .word 0x72201628 /* paddub     $v0, $s1, $zero */
    .word 0x7BBF0020 /* lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0030 /* addiu      $sp, $sp, 0x30 */
}

asm void *func_00184CC0(void *self, int a1, int a2, int a3, int t0) {
    .word 0x8C990000 /* lw         $t9, 0x0($a0) */
    .word 0x71004E28 /* paddub     $t1, $t0, $zero */
    .word 0x70E04628 /* paddub     $t0, $a3, $zero */
    .word 0x70003E28 /* paddub     $a3, $zero, $zero */
    .word 0x8F390034 /* lw         $t9, 0x34($t9) */
    .word 0x03200008 /* jr         $t9 */
    .word 0x00000000 /* nop */
}
}

#else

extern "C" {
int func_1C1FD0(void *ctx, char *dest, int size);
int func_001C1FD0(void *ctx, char *dest, int size) {
    return func_1C1FD0(ctx, dest, size);
}

extern void *D_004E3110;

void *func_00184C28(void *self, int p1) {
    typedef void (*VMethod10)(void *self, int p1, void *buf, int size);
    VMethod10 fn = *(VMethod10 *)(*(char **)self + 0x28);
    fn(self, p1, (void *)0x00566EC0, 0x200);
    return (void *)0x00566EC0;
}

char *func_00184C70(void *self, int a1, char *dest, int size) {
    (void)self;
    (void)a1;
    void *ctx = D_004E3110;
    if (func_1C1FD0(ctx, dest, size) == 0) {
        dest[0] = 0;
        dest[size - 1] = 0;
    }
    return dest;
}

void *func_00184CC0(void *self, int a1, int a2, int a3, int t0) {
    typedef void *(*VMethod13)(void *self, int a1, int a2, int a3, int t0, int t1);
    VMethod13 fn = *(VMethod13 *)(*(char **)self + 0x34);
    return fn(self, a1, a2, 0, a3, t0);
}

void *func_00184c28(void *self, int p1) {
    return func_00184C28(self, p1);
}

char *func_00184c70(void *self, int a1, char *dest, int size) {
    return func_00184C70(self, a1, dest, size);
}

void *func_00184cc0(void *self, int a1, int a2, int a3, int t0) {
    return func_00184CC0(self, a1, a2, a3, t0);
}
}

#endif
