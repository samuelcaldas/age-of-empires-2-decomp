#include "zone_spatial_entity_dispatch_config_action_ac.h"

struct ConfigEntity {
    char pad[0xAC];
    void *fAC;
};

class SpatialEntity {
public:
    virtual void dummy();
    ConfigEntity *config;
};

extern "C" {
#if defined(__mips__)
asm int func_001E3660(SpatialEntity *self) {
    .word 0x27BDFFF0 /* 001E3660: addiu sp, sp, -16 */
    .word 0x7FBF0000 /* 001E3664: sq    ra, 0(sp) */
    .word 0x8C820004 /* 001E3668: lw    v0, 4(a0) */
    .word 0x8C4500AC /* 001E366C: lw    a1, 172(v0) */
    .word 0x10A00008 /* 001E3670: beqz  a1, .Lzero */
    .word 0x70001628 /* 001E3674: paddub v0, zero, zero */
    .word 0x8C990000 /* 001E3678: lw    t9, 0(a0) */
    .word 0x8F39004C /* 001E367C: lw    t9, 76(t9) */
    .word 0x0320F809 /* 001E3680: jalr  t9 */
    .word 0x00000000 /* 001E3684: nop */
    .word 0x10000002 /* 001E3688: b     .Lret */
    .word 0x24020001 /* 001E368C: li    v0, 1 */
/*.Lzero: */
    .word 0x70001628 /* 001E3690: paddub v0, zero, zero */
/*.Lret: */
    .word 0x7BBF0000 /* 001E3694: lq    ra, 0(sp) */
    .word 0x03E00008 /* 001E3698: jr    ra */
}

asm void func_001E369C() {
    .word 0x27BD0010 /* 001E369C: addiu sp, sp, 16 */
}
#else
int func_001E3660(SpatialEntity *self) {
    void **vtable = *(void ***)self;
    typedef void (*Method4CFn)(void *, void *);
    Method4CFn method4c = (Method4CFn)(vtable[19]);
    if (self->config->fAC != 0) {
        method4c(self, self->config->fAC);
        return 1;
    }
    return 0;
}
void func_001E369C() {}
#endif
}
