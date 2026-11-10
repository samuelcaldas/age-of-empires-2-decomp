#include "zone_spatial_entity_get_angular_velocity.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0xBC];
    Vector3 *vel_vec;
};

extern "C" {
#if defined(__mips__)
asm Vector3 *func_001DFE00(Vector3 *out, const SpatialEntity *ent) {
    .word 0x8CA300BC /* 001DFE00: lw   v1, 0xBC(a1) */
    .word 0x10600008 /* 001DFE04: beqz v1, .Lzero */
    .word 0x00000000 /* 001DFE08: nop */
    .word 0xC460000C /* 001DFE0C: lwc1 $f0, 0xC(v1) */
    .word 0xE4800000 /* 001DFE10: swc1 $f0, 0(a0) */
    .word 0xC4600010 /* 001DFE14: lwc1 $f0, 0x10(v1) */
    .word 0xE4800004 /* 001DFE18: swc1 $f0, 4(a0) */
    .word 0xC4600014 /* 001DFE1C: lwc1 $f0, 0x14(v1) */
    .word 0x10000005 /* 001DFE20: b    .Lret */
    .word 0xE4800008 /* 001DFE24: swc1 $f0, 8(a0) */
/*.Lzero: */
    .word 0xAC800000 /* 001DFE28: sw   $zero, 0(a0) */
    .word 0xAC800004 /* 001DFE2C: sw   $zero, 4(a0) */
    .word 0xAC800008 /* 001DFE30: sw   $zero, 8(a0) */
    .word 0x70801628 /* 001DFE34: paddub v0, a0, $zero */
/*.Lret: */
    .word 0x03E00008 /* 001DFE38: jr   $ra */
    .word 0x00000000 /* 001DFE3C: nop */
}
#else
Vector3 *func_001DFE00(Vector3 *out, const SpatialEntity *ent) {
    Vector3 *v;
    if ((v = ent->vel_vec) != 0) {
        out->x = v[1].x;
        out->y = v[1].y;
        out->z = v[1].z;
    } else {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
    }
    return out;
}
#endif
}
