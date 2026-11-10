#include "zone_spatial_entity_get_velocity_vector.h"

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
asm Vector3 *func_001DFD20(Vector3 *out, const SpatialEntity *ent) {
    .word 0x8CA300BC /* 001DFD20: lw   v1, 0xBC(a1) */
    .word 0x10600008 /* 001DFD24: beqz v1, .Lzero */
    .word 0x00000000 /* 001DFD28: nop */
    .word 0xC4600000 /* 001DFD2C: lwc1 $f0, 0(v1) */
    .word 0xE4800000 /* 001DFD30: swc1 $f0, 0(a0) */
    .word 0xC4600004 /* 001DFD34: lwc1 $f0, 4(v1) */
    .word 0xE4800004 /* 001DFD38: swc1 $f0, 4(a0) */
    .word 0xC4600008 /* 001DFD3C: lwc1 $f0, 8(v1) */
    .word 0x10000005 /* 001DFD40: b    .Lret */
    .word 0xE4800008 /* 001DFD44: swc1 $f0, 8(a0) */
/*.Lzero: */
    .word 0xAC800000 /* 001DFD48: sw   $zero, 0(a0) */
    .word 0xAC800004 /* 001DFD4C: sw   $zero, 4(a0) */
    .word 0xAC800008 /* 001DFD50: sw   $zero, 8(a0) */
    .word 0x70801628 /* 001DFD54: paddub v0, a0, $zero */
/*.Lret: */
    .word 0x03E00008 /* 001DFD58: jr   $ra */
    .word 0x00000000 /* 001DFD5C: nop */
}
#else
Vector3 *func_001DFD20(Vector3 *out, const SpatialEntity *ent) {
    Vector3 *v;
    if ((v = ent->vel_vec) != 0) {
        out->x = v->x;
        out->y = v->y;
        out->z = v->z;
    } else {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
    }
    return out;
}
#endif
}
