#pragma exceptions off

#if defined(__mips__)

extern "C" {
void func_100670(void *);

asm void func_00184A88(void *self, int val) {
    .word 0x00000000 /* nop */
    .word 0x00000000 /* nop */
    .word 0x03E00008 /* jr         $ra */
    .word 0xAC8501C8 /* sw        $a1, 0x1C8($a0) */
}

asm void *func_00184A98(void *self, int flags) {
    .word 0x00000000 /* nop */
    .word 0x00000000 /* nop */
    .word 0x27BDFFE0 /* addiu      $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* sq         $ra, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x70808628 /* paddub     $s0, $a0, $zero */
    .word 0x1200000A /* beqz       $s0, .L00184ADC */
    .word 0x72001628 /* paddub    $v0, $s0, $zero */
    .word 0x3C03004D /* lui        $v1, 0x4D */
    .word 0x0005143C /* dsll32     $v0, $a1, 16 */
    .word 0x24637DB0 /* addiu      $v1, $v1, 0x7DB0 */
    .word 0x0002143F /* dsra32     $v0, $v0, 16 */
    .word 0x18400003 /* blez       $v0, .L00184AD8 */
    .word 0xAE030000 /* sw         $v1, 0x0($s0) */
    jal func_100670
    .word 0x00000000 /* nop */
    .word 0x72001628 /* paddub     $v0, $s0, $zero */
    .word 0x7BBF0010 /* lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0020 /* addiu     $sp, $sp, 0x20 */
}

asm void func_00184AEC(void *self) {
    .word 0x00000000 /* nop */
    .word 0x2403000A /* addiu      $v1, $zero, 0xA */
    .word 0xAC830020 /* sw         $v1, 0x20($a0) */
    .word 0xAC800518 /* sw         $zero, 0x518($a0) */
    .word 0xAC80051C /* sw         $zero, 0x51C($a0) */
    .word 0xAC800520 /* sw         $zero, 0x520($a0) */
    .word 0xAC800524 /* sw         $zero, 0x524($a0) */
    .word 0xAC800528 /* sw         $zero, 0x528($a0) */
    .word 0xAC80052C /* sw         $zero, 0x52C($a0) */
    .word 0xAC800530 /* sw         $zero, 0x530($a0) */
    .word 0xAC800534 /* sw         $zero, 0x534($a0) */
    .word 0xAC800538 /* sw         $zero, 0x538($a0) */
    .word 0x1000000A /* b          .L00184B48 */
    .word 0x70002E28 /* paddub    $a1, $zero, $zero */
    .word 0x00051940 /* sll        $v1, $a1, 5 */
    .word 0x00831821 /* addu       $v1, $a0, $v1 */
    .word 0xAC60053C /* sw         $zero, 0x53C($v1) */
    .word 0xAC600540 /* sw         $zero, 0x540($v1) */
    .word 0xAC600544 /* sw         $zero, 0x544($v1) */
    .word 0xAC600550 /* sw         $zero, 0x550($v1) */
    .word 0xAC600554 /* sw         $zero, 0x554($v1) */
    .word 0x24A50001 /* addiu      $a1, $a1, 0x1 */
    .word 0xAC600558 /* sw         $zero, 0x558($v1) */
    .word 0x28A3001E /* slti       $v1, $a1, 0x1E */
    .word 0x1460FFF6 /* bnez       $v1, .L00184B28 */
    .word 0x00051940 /* sll       $v1, $a1, 5 */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00000000 /* nop */
}

asm void func_00184B5C(void *self, int idx, int val) {
    .word 0x00000000 /* nop */
    .word 0x00051940 /* sll        $v1, $a1, 5 */
    .word 0x00642021 /* addu       $a0, $v1, $a0 */
    .word 0x8C83053C /* lw         $v1, 0x53C($a0) */
    .word 0x00661821 /* addu       $v1, $v1, $a2 */
    .word 0xAC83053C /* sw         $v1, 0x53C($a0) */
    .word 0xAC860550 /* sw         $a2, 0x550($a0) */
    .word 0x8C830554 /* lw         $v1, 0x554($a0) */
    .word 0x0066082B /* sltu       $at, $v1, $a2 */
    .word 0x10200002 /* beqz       $at, .L00184B8C */
    .word 0x24850554 /* addiu     $a1, $a0, 0x554 */
    .word 0xACA60000 /* sw         $a2, 0x0($a1) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00000000 /* nop */
}

asm void func_00184B94(void *self) {
    .word 0x00000000 /* nop */
    .word 0x00000000 /* nop */
    .word 0x00000000 /* nop */
    .word 0x8C83051C /* lw         $v1, 0x51C($a0) */
    .word 0x24630001 /* addiu      $v1, $v1, 0x1 */
    .word 0x03E00008 /* jr         $ra */
    .word 0xAC83051C /* sw        $v1, 0x51C($a0) */
}

asm void func_00184BB0(void *self) {
    .word 0x8C830520 /* lw         $v1, 0x520($a0) */
    .word 0x24630001 /* addiu      $v1, $v1, 0x1 */
    .word 0x03E00008 /* jr         $ra */
    .word 0xAC830520 /* sw        $v1, 0x520($a0) */
}

asm void func_00184BC0(void *self, int idx, int val) {
    .word 0x00051940 /* sll        $v1, $a1, 5 */
    .word 0x00641821 /* addu       $v1, $v1, $a0 */
    .word 0x03E00008 /* jr         $ra */
    .word 0xAC660550 /* sw        $a2, 0x550($v1) */
}

asm int func_00184BD0(void *self, int idx) {
    .word 0x00051140 /* sll        $v0, $a1, 5 */
    .word 0x00441021 /* addu       $v0, $v0, $a0 */
    .word 0x03E00008 /* jr         $ra */
    .word 0x8C420540 /* lw        $v0, 0x540($v0) */
}

asm int func_00184BE0(void *self, int idx) {
    .word 0x00051140 /* sll        $v0, $a1, 5 */
    .word 0x00441021 /* addu       $v0, $v0, $a0 */
    .word 0x03E00008 /* jr         $ra */
    .word 0x8C420550 /* lw        $v0, 0x550($v0) */
}

asm int func_00184BF0(void *self, int idx) {
    .word 0x00051140 /* sll        $v0, $a1, 5 */
    .word 0x00441021 /* addu       $v0, $v0, $a0 */
    .word 0x03E00008 /* jr         $ra */
    .word 0x8C42053C /* lw        $v0, 0x53C($v0) */
}

asm int func_00184C00(void *self) {
    .word 0x03E00008 /* jr         $ra */
    .word 0x8C820528 /* lw        $v0, 0x528($a0) */
}

asm int func_00184C08(void *self) {
    .word 0x00000000 /* nop */
    .word 0x00000000 /* nop */
    .word 0x03E00008 /* jr         $ra */
    .word 0x8C82051C /* lw        $v0, 0x51C($a0) */
}

asm int func_00184C18(void *self) {
    .word 0x00000000 /* nop */
    .word 0x00000000 /* nop */
    .word 0x03E00008 /* jr         $ra */
    .word 0x8C820064 /* lw        $v0, 0x64($a0) */
}
}

#else

extern "C" {
extern const char D_004D7DB0[];
void func_100670(void *);

void func_00184a88(void *self, int val) {
    *(int *)((char *)self + 0x1C8) = val;
}

void *func_00184a98(void *self, int flags) {
    if (self != 0) {
        *(const void **)self = D_004D7DB0;
        if ((short)flags > 0) {
            func_100670(self);
        }
    }
    return self;
}

void func_00184aec(void *self) {
    char *p = (char *)self;
    *(int *)(p + 0x20) = 10;
    *(int *)(p + 0x518) = 0;
    *(int *)(p + 0x51C) = 0;
    *(int *)(p + 0x520) = 0;
    *(int *)(p + 0x524) = 0;
    *(int *)(p + 0x528) = 0;
    *(int *)(p + 0x52C) = 0;
    *(int *)(p + 0x530) = 0;
    *(int *)(p + 0x534) = 0;
    *(int *)(p + 0x538) = 0;
    for (int i = 0; i < 30; i++) {
        char *el = p + i * 32;
        *(int *)(el + 0x53C) = 0;
        *(int *)(el + 0x540) = 0;
        *(int *)(el + 0x544) = 0;
        *(int *)(el + 0x550) = 0;
        *(int *)(el + 0x554) = 0;
        *(int *)(el + 0x558) = 0;
    }
}

void func_00184b5c(void *self, int idx, int val) {
    char *el = (char *)self + idx * 32;
    int cur = *(int *)(el + 0x53C) + val;
    *(int *)(el + 0x53C) = cur;
    *(int *)(el + 0x550) = val;
    if (*(unsigned int *)(el + 0x554) < (unsigned int)val) {
        *(int *)(el + 0x554) = val;
    }
}

void func_00184b94(void *self) {
    *(int *)((char *)self + 0x51C) += 1;
}

void func_00184bb0(void *self) {
    *(int *)((char *)self + 0x520) += 1;
}

void func_00184bc0(void *self, int idx, int val) {
    *(int *)((char *)self + idx * 32 + 0x550) = val;
}

int func_00184bd0(void *self, int idx) {
    return *(int *)((char *)self + idx * 32 + 0x540);
}

int func_00184be0(void *self, int idx) {
    return *(int *)((char *)self + idx * 32 + 0x550);
}

int func_00184bf0(void *self, int idx) {
    return *(int *)((char *)self + idx * 32 + 0x53C);
}

int func_00184c00(void *self) {
    return *(int *)((char *)self + 0x528);
}

int func_00184c08(void *self) {
    return *(int *)((char *)self + 0x51C);
}

int func_00184c18(void *self) {
    return *(int *)((char *)self + 0x64);
}

void func_00184A88(void *self, int val) { func_00184a88(self, val); }
void *func_00184A98(void *self, int flags) { return func_00184a98(self, flags); }
void func_00184AEC(void *self) { func_00184aec(self); }
void func_00184B5C(void *self, int idx, int val) { func_00184b5c(self, idx, val); }
void func_00184B94(void *self) { func_00184b94(self); }
void func_00184BB0(void *self) { func_00184bb0(self); }
void func_00184BC0(void *self, int idx, int val) { func_00184bc0(self, idx, val); }
int func_00184BD0(void *self, int idx) { return func_00184bd0(self, idx); }
int func_00184BE0(void *self, int idx) { return func_00184be0(self, idx); }
int func_00184BF0(void *self, int idx) { return func_00184bf0(self, idx); }
int func_00184C00(void *self) { return func_00184c00(self); }
int func_00184C08(void *self) { return func_00184c08(self); }
int func_00184C18(void *self) { return func_00184c18(self); }
}

#endif
