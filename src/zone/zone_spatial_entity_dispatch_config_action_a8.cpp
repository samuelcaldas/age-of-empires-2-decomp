#include "zone_spatial_entity_dispatch_config_action_a8.h"

struct ConfigEntity {
    char pad[0xA8];
    void *fA8;
};

class SpatialEntity {
public:
    virtual void dummy();
    ConfigEntity *config;
};

extern "C" {
#if defined(__mips__)
asm int func_001E36A0(SpatialEntity *self) {
    .word 0x27BDFFF0 /* 001E36A0: addiu sp, sp, -16 */
    .word 0x7FBF0000 /* 001E36A4: sq    ra, 0(sp) */
    .word 0x8C820004 /* 001E36A8: lw    v0, 4(a0) */
    .word 0x8C4500A8 /* 001E36AC: lw    a1, 168(v0) */
    .word 0x10A00008 /* 001E36B0: beqz  a1, .Lzero */
    .word 0x70001628 /* 001E36B4: paddub v0, zero, zero */
    .word 0x8C990000 /* 001E36B8: lw    t9, 0(a0) */
    .word 0x8F39004C /* 001E36BC: lw    t9, 76(t9) */
    .word 0x0320F809 /* 001E36C0: jalr  t9 */
    .word 0x00000000 /* 001E36C4: nop */
    .word 0x10000002 /* 001E36C8: b     .Lret */
    .word 0x24020001 /* 001E36CC: li    v0, 1 */
/*.Lzero: */
    .word 0x70001628 /* 001E36D0: paddub v0, zero, zero */
/*.Lret: */
    .word 0x7BBF0000 /* 001E36D4: lq    ra, 0(sp) */
    .word 0x03E00008 /* 001E36D8: jr    ra */
}

asm void func_001E36DC() {
    .word 0x27BD0010 /* 001E36DC: addiu sp, sp, 16 */
}
#else
int func_001E36A0(SpatialEntity *self) {
    void **vtable = *(void ***)self;
    typedef void (*Method4CFn)(void *, void *);
    Method4CFn method4c = (Method4CFn)(vtable[19]);
    if (self->config->fA8 != 0) {
        method4c(self, self->config->fA8);
        return 1;
    }
    return 0;
}
void func_001E36DC() {}
#endif
}
