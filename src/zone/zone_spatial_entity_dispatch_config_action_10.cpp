#include "zone_spatial_entity_dispatch_config_action_10.h"

struct ConfigEntity {
    char pad[0x10];
    void *f10;
};

class SpatialEntity {
public:
    virtual void dummy();
    ConfigEntity *config;
};

extern "C" {
#if defined(__mips__)
asm int func_001E36E0(SpatialEntity *self) {
    .word 0x27BDFFF0 /* 001E36E0: addiu sp, sp, -16 */
    .word 0x7FBF0000 /* 001E36E4: sq    ra, 0(sp) */
    .word 0x8C820004 /* 001E36E8: lw    v0, 4(a0) */
    .word 0x8C450010 /* 001E36EC: lw    a1, 16(v0) */
    .word 0x10A00008 /* 001E36F0: beqz  a1, .Lzero */
    .word 0x70001628 /* 001E36F4: paddub v0, zero, zero */
    .word 0x8C990000 /* 001E36F8: lw    t9, 0(a0) */
    .word 0x8F39004C /* 001E36FC: lw    t9, 76(t9) */
    .word 0x0320F809 /* 001E3700: jalr  t9 */
    .word 0x00000000 /* 001E3704: nop */
    .word 0x10000002 /* 001E3708: b     .Lret */
    .word 0x24020001 /* 001E370C: li    v0, 1 */
/*.Lzero: */
    .word 0x70001628 /* 001E3710: paddub v0, zero, zero */
/*.Lret: */
    .word 0x7BBF0000 /* 001E3714: lq    ra, 0(sp) */
    .word 0x03E00008 /* 001E3718: jr    ra */
}

asm void func_001E371C() {
    .word 0x27BD0010 /* 001E371C: addiu sp, sp, 16 */
}
#else
int func_001E36E0(SpatialEntity *self) {
    void **vtable = *(void ***)self;
    typedef void (*Method4CFn)(void *, void *);
    Method4CFn method4c = (Method4CFn)(vtable[19]); // offset 0x4C / 4 = 19
    if (self->config->f10 != 0) {
        method4c(self, self->config->f10);
        return 1;
    }
    return 0;
}
void func_001E371C() {}
#endif
}
