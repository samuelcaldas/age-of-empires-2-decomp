#pragma exceptions off
#pragma conditional_move off

#include "zone_spatial_view_has_reached_limit.h"

extern "C" {
void *func_1FCE60(void *sub);
void *func_3334A0(void *obj, int id);
extern void *D_004E3180;
}

struct SpatialViewObj {
    char pad[0xA8];
    void *sub;
};

struct Item {
    char pad0[8];
    void *field_8;
    int field_C;
    int field_10;
};

struct Target {
    char pad[0x20];
    char count;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

#pragma exceptions off

#include "zone_spatial_view_has_reached_limit.h"

extern "C" {
void *func_1FCE60(void *sub);
void *func_3334A0(void *obj, int id);
extern void *D_004E3180;

#if defined(__mips__)
asm int func_001D9250(SpatialViewObj *self) {
    addiu $sp, $sp, -0x20
    sq $ra, 0x10($sp)
    sq $s0, 0x0($sp)
    lw $a0, 0xA8($a0)
    bnez $a0, lbl_1D9270
    nop
    b lbl_1D92DC
    paddub $v0, $zero, $zero
lbl_1D9270:
    jal func_1FCE60
    nop
    paddub $s0, $v0, $zero
    bnez $s0, lbl_1D928C
    nop
    b lbl_1D92DC
    paddub $v0, $zero, $zero
lbl_1D928C:
    lw $v0, 0x8($s0)
    bnez $v0, lbl_1D92B8
    nop
    .word 0x8F8289C0 /* 001D9298 lw $v0, -0x7640($gp) */
    lw $a0, 0x404($v0)
    jal func_3334A0
    lw $a1, 0xC($s0)
    bnez $v0, lbl_1D92B8
    nop
    b lbl_1D92DC
    paddub $v0, $zero, $zero
lbl_1D92B8:
    lb $v0, 0x20($v0)
    lw $v1, 0x10($s0)
    addiu $v0, $v0, -0x1
    slt $v0, $v1, $v0
    bnez $v0, lbl_1D92DC
    paddub $v0, $zero, $zero
    .word 0x10000002 /* b lbl_1D92DC */
    addiu $v0, $zero, 0x1
    paddub $v0, $zero, $zero
lbl_1D92DC:
    lq $ra, 0x10($sp)
    lq $s0, 0x0($sp)
    jr $ra
    addiu $sp, $sp, 0x20
    nop
}
#else
int func_001D9250(SpatialViewObj *self) {
    if (self->sub) {
        Item *item = (Item *)func_1FCE60(self->sub);
        if (item) {
            void *v = item->field_8;
            if (!v) {
                GlobalContext *ctx = (GlobalContext *)D_004E3180;
                v = func_3334A0(ctx->field_404, item->field_C);
            }
            if (v) {
                Target *t = (Target *)v;
                if (item->field_10 < (int)(t->count - 1)) {
                    return 0;
                }
                return 1;
            }
        }
    }
    return 0;
}
#endif
}
