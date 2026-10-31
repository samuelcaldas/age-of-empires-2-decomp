#pragma exceptions off
#pragma divbyzerocheck on

#if !defined(__mips__)
#define func_1ab8f0 func_001AB8F0
#define func_25E640 func_0025E640
#define func_1ab9d0 func_001AB9D0
extern "C" void helper_2184d0_mock_break(int code);
#endif

extern "C" {
int func_001AC470(void *manager, void *x0, void *y0, int x1, int y1);
int func_1ab8f0(void *manager, int mode);
int func_25E640(void *field, void *manager, void *x, void *y, int arg4, int arg5);
int func_1ab9d0(void *manager);
int func_001AD650(void *manager, void *x0, void *y0, int x1, int y1, int flag);

struct VObj40 {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30();
    virtual void method3C(void *arg);
    virtual void v40();
    virtual void method44(void *arg);
};

inline void call_vslot3c(void *receiver, void *arg) {
#if defined(__mips__)
    ((VObj40 *)receiver)->method3C(arg);
#else
    void **vt = *(void ***)receiver;
    ((void (*)(void *, void *))vt[0x3C / 4])(receiver, arg);
#endif
}

inline void call_vslot44(void *receiver, void *arg) {
#if defined(__mips__)
    ((VObj40 *)receiver)->method44(arg);
#else
    void **vt = *(void ***)receiver;
    ((void (*)(void *, void *))vt[0x44 / 4])(receiver, arg);
#endif
}

struct RenderManager {
    char pad00[0x28];
    int saved_28;
    int saved_2C;
    int saved_30;
    int saved_34;
};

struct RenderObject {
    char pad00[0x0C];
    int x;
    int y;
    int w;
    int h;
    char pad1C[0x04];
    RenderManager *manager;
    char pad24[0x1C];
    void *obj40;
    char pad44[0x13C];
    void *field180;
    short step_x;
    short step_y;
    int state;
    unsigned char flag;
    char pad18D[0x1F];
    int field1AC;
};

static inline short grid_count(short step, int span) {
    short count;
    if (step >= span) return 1;
#if !defined(__mips__)
    if (step == 0) {
        __I_break(7);
    }
#endif
    count = span / step;
    if (count * step < span) count++;
    return count;
}

/* 0x002184D0 */
#if defined(__mips__)
asm void func_002184D0(void *self) {
    addiu      sp, sp, -0xB0
    sq         ra, 0x90(sp)
    sq         s8, 0x80(sp)
    sq         s7, 0x70(sp)
    sq         s6, 0x60(sp)
    sq         s5, 0x50(sp)
    sq         s4, 0x40(sp)
    sq         s3, 0x30(sp)
    sq         s2, 0x20(sp)
    sq         s1, 0x10(sp)
    sq         s0, 0x0(sp)
    lw         a2, 0x180(a0)
    beqz       a2, lbl_002186D4
    paddub    s6, a0, zero
    lw         a0, 0x20(s6)
    lw         a1, 0xC(s6)
    lw         a3, 0x14(s6)
    lw         a2, 0x10(s6)
    lw         v1, 0x18(s6)
    lw         v0, 0x28(a0)
    lw         s8, 0x2C(a0)
    lw         s7, 0x30(a0)
    lw         s2, 0x34(a0)
    sw         v0, 0xA0(sp)
    addu       v0, a1, a3
    addiu      a3, v0, -0x1
    addu       v0, a2, v1
    jal        func_001AC470
    addiu     t0, v0, -0x1
    lw         a0, 0x20(s6)
    jal        func_1ab8f0
    addiu     a1, zero, 0x1
    beqz       v0, lbl_002186AC
    nop
    lh         a0, 0x184(s6)
    lw         a1, 0x14(s6)
    slt        v0, a0, a1
    bnel       v0, zero, lbl_00218580
    .word 0x00A4001A
    addiu      v0, zero, 0x1
    dsll32     v1, v0, 16
    .word 0x1000000F
    dsra32    v1, v1, 16
    .word 0x00A4001A
lbl_00218580:
    bnez       a0, lbl_0021858C
    nop
    .word 0x000001cd
lbl_0021858C:
    mflo       v0
    dsll32     v1, v0, 16
    dsra32     v1, v1, 16
    mult       v0, v1, a0
    slt        at, v0, a1
    beqz       at, lbl_002185B4
    nop
    addiu      v0, v1, 0x1
    dsll32     v1, v0, 16
    dsra32     v1, v1, 16
lbl_002185B4:
    lh         a1, 0x186(s6)
    lw         a2, 0x18(s6)
    slt        v0, a1, a2
    bnel       v0, zero, lbl_002185DC
    .word 0x00C5001A
    addiu      v0, zero, 0x1
    dsll32     a0, v0, 16
    .word 0x1000000F
    dsra32    a0, a0, 16
    .word 0x00C5001A
lbl_002185DC:
    bnez       a1, lbl_002185E8
    nop
    .word 0x000001cd
lbl_002185E8:
    mflo       v0
    dsll32     a0, v0, 16
    dsra32     a0, a0, 16
    mult       v0, a0, a1
    slt        at, v0, a2
    beqz       at, lbl_00218614
    dsll32    s3, v1, 16
    addiu      v0, a0, 0x1
    dsll32     a0, v0, 16
    dsra32     a0, a0, 16
lbl_00218610:
    dsll32     s3, v1, 16
lbl_00218614:
    dsll32     s4, a0, 16
    dsra32     s3, s3, 16
    dsra32     s4, s4, 16
    b          lbl_00218690
    paddub    s1, zero, zero
lbl_00218628:
    b          lbl_00218670
    paddub    s0, zero, zero
lbl_00218630:
    lh         a3, 0x184(s6)
    lh         v1, 0x186(s6)
    lw         a2, 0xC(s6)
    lw         v0, 0x10(s6)
    lw         a0, 0x180(s6)
    lw         a1, 0x20(s6)
    mult       t1, t0, a3
    mult1      v1, s5, v1
    addu       a2, a2, t1
    addu       a3, v0, v1
    paddub     t0, zero, zero
    jal        func_25E640
    paddub    t1, zero, zero
    addiu      v0, s0, 0x1
    dsll32     s0, v0, 16
    dsra32     s0, s0, 16
lbl_00218670:
    dsll32     t0, s0, 16
    dsra32     t0, t0, 16
    slt        v0, t0, s3
    bnez       v0, lbl_00218630
    nop
    addiu      v0, s1, 0x1
    dsll32     s1, v0, 16
    dsra32     s1, s1, 16
lbl_00218690:
    dsll32     s5, s1, 16
    dsra32     s5, s5, 16
    slt        v0, s5, s4
    bnez       v0, lbl_00218628
    nop
    jal        func_1ab9d0
    lw        a0, 0x20(s6)
lbl_002186AC:
    lw         a0, 0x20(s6)
    lw         v1, 0xA0(sp)
    sw         v1, 0x28(a0)
    lw         v1, 0x20(s6)
    sw         s8, 0x2C(v1)
    lw         v1, 0x20(s6)
    sw         s7, 0x30(v1)
    lw         v1, 0x20(s6)
    b          lbl_002187E8
    sw        s2, 0x34(v1)
lbl_002186D4:
    lw         a0, 0x188(s6)
    addiu      a1, zero, 0x1
    bne        a0, a1, lbl_00218734
    addiu     v1, zero, 0x2
    jal        func_1ab8f0
    lw        a0, 0x20(s6)
    beqz       v0, lbl_002187E8
    nop
    lw         a2, 0x10(s6)
    lw         v0, 0x18(s6)
    lw         a1, 0xC(s6)
    lw         v1, 0x14(s6)
    lw         a0, 0x20(s6)
    lbu        t1, 0x18C(s6)
    addu       v0, a2, v0
    addu       v1, a1, v1
    addiu      a3, v1, -0x1
    jal        func_001AD650
    addiu     t0, v0, -0x1
    jal        func_1ab9d0
    lw        a0, 0x20(s6)
    .word 0x10000030
    lq        ra, 0x90(sp)
    addiu      v1, zero, 0x2
lbl_00218734:
    beq        a0, v1, lbl_002187E8
    nop
    addiu      v1, zero, 0x3
    bne        a0, v1, lbl_0021878C
    nop
    beqz       a2, lbl_002187E8
    nop
    jal        func_1ab8f0
    lw        a0, 0x20(s6)
    beqz       v0, lbl_002187E8
    nop
    lw         a0, 0x180(s6)
    lw         a1, 0x20(s6)
    lw         a2, 0xC(s6)
    lw         a3, 0x10(s6)
    paddub     t0, zero, zero
    jal        func_25E640
    paddub    t1, zero, zero
    jal        func_1ab9d0
    lw        a0, 0x20(s6)
    b          lbl_002187E8
    nop
lbl_0021878C:
    lw         a0, 0x40(s6)
    beqz       a0, lbl_002187E8
    nop
    lw         a1, 0x1AC(s6)
    slti       v1, a1, 0x2
    bnez       v1, lbl_002187CC
    nop
    slti       at, a1, 0x8
    beqz       at, lbl_002187CC
    nop
    lw         t9, 0x0(a0)
    lw         t9, 0x44(t9)
    jalr ra, t9
    addiu     a1, s6, 0x24
    b          lbl_002187E8
    nop
lbl_002187CC:
    lw         v1, 0x9C(a0)
    bnez       v1, lbl_002187E8
    nop
    lw         t9, 0x0(a0)
    lw         t9, 0x3C(t9)
    jalr ra, t9
    addiu     a1, s6, 0x24
lbl_002187E8:
    lq         ra, 0x90(sp)
lbl_002187EC:
    lq         s8, 0x80(sp)
    lq         s7, 0x70(sp)
    lq         s6, 0x60(sp)
    lq         s5, 0x50(sp)
    lq         s4, 0x40(sp)
    lq         s3, 0x30(sp)
    lq         s2, 0x20(sp)
    lq         s1, 0x10(sp)
    lq         s0, 0x0(sp)
    jr         ra
    addiu     sp, sp, 0xB0
}
#else
void func_002184D0(void *self) {
    void *field180 = *(void **)((char *)self + 0x180);
    char *s6 = (char *)self;

    if (field180 != 0) {
        void *mgr = *(void **)(s6 + 0x20);
        int x1 = *(int *)(s6 + 0xC);
        int w = *(int *)(s6 + 0x14);
        int y1 = *(int *)(s6 + 0x10);
        int h = *(int *)(s6 + 0x18);

        int saved_28 = *(int *)((char *)mgr + 0x28);
        int saved_2C = *(int *)((char *)mgr + 0x2C);
        int saved_30 = *(int *)((char *)mgr + 0x30);
        int saved_34 = *(int *)((char *)mgr + 0x34);

        func_001AC470(mgr, (void *)x1, (void *)y1, x1 + w - 1, y1 + h - 1);

        if (func_1ab8f0(*(void **)(s6 + 0x20), 1) != 0) {
            short step_x = *(short *)(s6 + 0x184);
            int span_x = *(int *)(s6 + 0x14);
            short cols = grid_count(step_x, span_x);

            short step_y = *(short *)(s6 + 0x186);
            int span_y = *(int *)(s6 + 0x18);
            short rows = grid_count(step_y, span_y);

            for (short s1 = 0; s1 < rows; s1++) {
                for (short s0 = 0; s0 < cols; s0++) {
                    short cur_step_x = *(short *)(s6 + 0x184);
                    short cur_step_y = *(short *)(s6 + 0x186);
                    int cur_start_x = *(int *)(s6 + 0xC);
                    int cur_start_y = *(int *)(s6 + 0x10);
                    void *cur_180 = *(void **)(s6 + 0x180);
                    void *cur_mgr = *(void **)(s6 + 0x20);
                    int x = cur_start_x + (int)s0 * cur_step_x;
                    int y = cur_start_y + (int)s1 * cur_step_y;
                    func_25E640(cur_180, cur_mgr, (void *)x, (void *)y, 0, 0);
                }
            }

            func_1ab9d0(*(void **)(s6 + 0x20));
        }

        void *cur_mgr = *(void **)(s6 + 0x20);
        *(int *)((char *)cur_mgr + 0x28) = saved_28;
        *(int *)((char *)*(void **)(s6 + 0x20) + 0x2C) = saved_2C;
        *(int *)((char *)*(void **)(s6 + 0x20) + 0x30) = saved_30;
        *(int *)((char *)*(void **)(s6 + 0x20) + 0x34) = saved_34;
        return;
    }

    int state = *(int *)(s6 + 0x188);
    if (state == 1) {
        if (func_1ab8f0(*(void **)(s6 + 0x20), 2) != 0) {
            int y1 = *(int *)(s6 + 0x10);
            int h = *(int *)(s6 + 0x18);
            int x1 = *(int *)(s6 + 0xC);
            int w = *(int *)(s6 + 0x14);
            int flag = *(unsigned char *)(s6 + 0x18C);
            func_001AD650(*(void **)(s6 + 0x20), (void *)x1, (void *)y1, x1 + w - 1, y1 + h - 1, flag);
            func_1ab9d0(*(void **)(s6 + 0x20));
        }
        return;
    }

    if (state == 2 || state == 3) {
        if (state == 3 && field180 != 0) {
            if (func_1ab8f0(*(void **)(s6 + 0x20), 2) != 0) {
                func_25E640(*(void **)(s6 + 0x180), *(void **)(s6 + 0x20), *(void **)(s6 + 0xC), *(void **)(s6 + 0x10), 0, 0);
                func_1ab9d0(*(void **)(s6 + 0x20));
            }
        }
        return;
    }

    void *obj40 = *(void **)(s6 + 0x40);
    if (obj40 != 0) {
        int a1 = *(int *)(s6 + 0x1AC);
        if (a1 >= 2 && a1 < 8) {
            call_vslot44(obj40, s6 + 0x24);
        } else if (*(int *)((char *)obj40 + 0x9C) == 0) {
            call_vslot3c(obj40, s6 + 0x24);
        }
    }
}
#endif

}
