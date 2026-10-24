/* Age of Empires II PS2 - DCOMP_CD.BIN Overlay */
#include "common.h"
#include "dcomp_overlay.h"

/* External overlay calls */
extern void *func_00100670(void *a0, ...);
extern void *func_00114320(void *a0, ...);
extern void *func_00118de0(void *a0, ...);

/* External overlay calls */
extern void *func_00100670(void *a0, ...);
extern void *func_00114320(void *a0, ...);
extern void *func_00117AF8(void *a0, ...);
extern void *func_00117CAC(void *a0, ...);
extern void *func_00118DE0(void *a0, ...);
extern void *func_00118de0(void *a0, ...);
extern void *func_01D98080(void *a0, ...);
extern void *func_01D980B0(void *a0, ...);
extern void *func_01D980E0(void *a0, ...);
extern void *func_01D98190(void *a0, ...);
extern void *func_01D98280(void *a0, ...);
extern void *func_01D98480(void *a0, ...);
extern void *func_01D985A0(void *a0, ...);
extern void *func_01D986B0(void *a0, ...);
extern void *func_01D98860(void *a0, ...);
extern void *func_01D98AC0(void *a0, ...);
extern void *func_01D98B00(void *a0, ...);
extern void *func_01D98B70(void *a0, ...);
extern void *func_01D98C80(void *a0, ...);
extern void *func_01D98D70(void *a0, ...);
extern void *func_01D99050(void *a0, ...);
extern void *func_01D99170(void *a0, ...);
extern void *func_01D991A0(void *a0, ...);
extern void *func_01D99240(void *a0, ...);
extern void *func_01D99310(void *a0, ...);
extern void *func_01D99680(void *a0, ...);
extern void *func_01D998C0(void *a0, ...);
extern void *func_01D99B80(void *a0, ...);
extern void *func_01D99BD0(void *a0, ...);
extern void *func_01D99E20(void *a0, ...);
extern void *func_01D9A2D0(void *a0, ...);
extern void *func_01D9A360(void *a0, ...);
extern void *func_01D9A430(void *a0, ...);
extern void *func_01D9AB60(void *a0, ...);
extern void *func_01D9B120(void *a0, ...);
extern void *func_01D9B840(void *a0, ...);
extern void *func_01D9B8A0(void *a0, ...);
extern void *func_01D9B8C0(void *a0, ...);
extern void *func_01D9B990(void *a0, ...);
extern void *func_01D9BB00(void *a0, ...);
extern void *func_01D9C010(void *a0, ...);
extern void *func_01D9C030(void *a0, ...);
extern void *func_01D9C050(void *a0, ...);
extern void *func_01D9C0B0(void *a0, ...);
extern void *func_01D9C0E0(void *a0, ...);
extern void *func_01D9C110(void *a0, ...);
extern void *func_01D9C150(void *a0, ...);
extern void *func_01D9C1A0(void *a0, ...);
extern void *func_01D9C1C0(void *a0, ...);
extern void *func_01D9C210(void *a0, ...);
extern void *func_01D9C270(void *a0, ...);
extern void *func_01D9C300(void *a0, ...);
extern void *func_01D9CCE0(void *a0, ...);
extern void *func_01D9CE10(void *a0, ...);
extern void *func_01D9CF90(void *a0, ...);
extern void *func_01D9D0D0(void *a0, ...);
extern void *func_01D9D210(void *a0, ...);
extern void *func_01D9D490(void *a0, ...);
extern void *func_01D9D610(void *a0, ...);
extern void *func_01D9D750(void *a0, ...);
extern void *func_01D9DBC0(void *a0, ...);
extern void *func_01D9DE90(void *a0, ...);
extern void *func_01D9E160(void *a0, ...);
extern void *func_01D9ED10(void *a0, ...);
extern void *func_01DA0FB0(void *a0, ...);
extern void *func_01DA1200(void *a0, ...);

/* Function 1: dcomp_func_01D98000 (VMA: 0x01D98000, size: 36 bytes) */
void *dcomp_func_01D98000(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    goto _lbl_01D98014;
_lbl_01D98008:
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_a1; }
    r_a0 = (long)(r_a0 + (4));
    r_a2 = (long)(r_a2 + (-1));
_lbl_01D98014:
    if (r_a2 != 0) goto _lbl_01D98008;
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 2: dcomp_func_01D98024 (VMA: 0x01D98024, size: 56 bytes) */
void *dcomp_func_01D98024(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    goto _lbl_01D9804C;
_lbl_01D98038:
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    r_a2 = (long)(r_a2 + (-1));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    r_a1 = (long)(r_a1 + (4));
    r_a0 = (long)(r_a0 + (4));
_lbl_01D9804C:
    if (r_a2 != 0) goto _lbl_01D98038;
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 3: dcomp_func_01D9805C (VMA: 0x01D9805C, size: 40 bytes) */
void *dcomp_func_01D9805C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    goto _lbl_01D98074;
_lbl_01D98068:
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)r_a1; }
    r_a0 = (long)(r_a0 + (1));
    r_a2 = (long)(r_a2 + (-1));
_lbl_01D98074:
    if (r_a2 != 0) goto _lbl_01D98068;
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 4: dcomp_func_01D98084 (VMA: 0x01D98084, size: 140 bytes) */
void *dcomp_func_01D98084(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (-0x7e98)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (-0x7e9c)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7e94)); }
    r_a1 = (long)(r_a1 - r_v1);
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 == 0) goto _lbl_01D980DC;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98104;
_lbl_01D980DC:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(0 | 0);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7e9c)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_v1; }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7e98)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v1; }
_lbl_01D98104:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 5: dcomp_func_01D98110 (VMA: 0x01D98110, size: 228 bytes) */
void *dcomp_func_01D98110(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    r_v1 = (long)((unsigned long)r_a3 << (2));
    r_v1 = (long)(r_a0 + r_v1);
    if (r_v1) { r_t1 = *(int *)((char *)r_v1 + (0)); }
    r_v1 = (long)((unsigned long)r_t1 << (2));
    r_t2 = (long)(r_a1 + r_v1);
    goto _lbl_01D981D4;
    r_at = (long)((long)r_t0 < (long)r_a2 ? 1 : 0);
_lbl_01D9812C:
    if (r_at == 0) { r_v1 = (long)((unsigned long)r_t0 << (2)); goto _lbl_01D9818C; }
    r_v1 = (long)((unsigned long)r_t0 << (2));
    r_v1 = (long)((unsigned long)r_t0 << (2));
    r_v1 = (long)(r_a0 + r_v1);
    if (r_v1) { r_t6 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { r_t5 = *(int *)((char *)r_v1 + (4)); }
    r_v1 = (long)((unsigned long)r_t6 << (2));
    r_v1 = (long)(r_a1 + r_v1);
    if (r_v1) { r_t4 = *(int *)((char *)r_v1 + (0)); }
    r_v1 = (long)((unsigned long)r_t5 << (2));
    r_v1 = (long)(r_a1 + r_v1);
    if (r_v1) { r_t3 = *(int *)((char *)r_v1 + (0)); }
    r_v1 = (long)((long)r_t3 < (long)r_t4 ? 1 : 0);
    if (r_v1 == 0) goto _lbl_01D98170;
    r_t0 = (long)(r_t0 + (1));
    goto _lbl_01D98188;
_lbl_01D98170:
    if (r_t4 != r_t3) goto _lbl_01D98188;
    r_at = (long)((long)r_t6 < (long)r_t5 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D98188;
    r_t0 = (long)(r_t0 + (1));
_lbl_01D98188:
    r_v1 = (long)((unsigned long)r_t0 << (2));
_lbl_01D9818C:
    r_v1 = (long)(r_a0 + r_v1);
    if (r_t2) { r_t4 = *(int *)((char *)r_t2 + (0)); }
    if (r_v1) { r_t5 = *(int *)((char *)r_v1 + (0)); }
    r_v1 = (long)((unsigned long)r_t5 << (2));
    r_v1 = (long)(r_a1 + r_v1);
    if (r_v1) { r_t3 = *(int *)((char *)r_v1 + (0)); }
    r_v1 = (long)((long)r_t4 < (long)r_t3 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (2)); goto _lbl_01D981E8; }
    r_v1 = (long)((unsigned long)r_a3 << (2));
    if (r_t4 != r_t3) { r_v1 = (long)((unsigned long)r_a3 << (2)); goto _lbl_01D981C8; }
    r_v1 = (long)((unsigned long)r_a3 << (2));
    r_at = (long)((long)r_t5 < (long)r_t1 ? 1 : 0);
    if (r_at != 0) goto _lbl_01D981E4;
    r_v1 = (long)((unsigned long)r_a3 << (2));
_lbl_01D981C8:
    r_v1 = (long)(r_a0 + r_v1);
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_t5; }
    r_a3 = (long)(r_t0 | 0);
_lbl_01D981D4:
    r_t0 = (long)((unsigned long)r_a3 << (1));
    r_at = (long)((long)r_a2 < (long)r_t0 ? 1 : 0);
    if (r_at == 0) { r_at = (long)((long)r_t0 < (long)r_a2 ? 1 : 0); goto _lbl_01D9812C; }
    r_at = (long)((long)r_t0 < (long)r_a2 ? 1 : 0);
_lbl_01D981E4:
    r_v1 = (long)((unsigned long)r_a3 << (2));
_lbl_01D981E8:
    r_v1 = (long)(r_a0 + r_v1);
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_t1; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 6: dcomp_func_01D981F4 (VMA: 0x01D981F4, size: 520 bytes) */
void *dcomp_func_01D981F4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t7 = 0, r_t8 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t7;
    (void)r_t8;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x10));
    r_t9 = (long)(r_a2 | 0);
    r_v1 = (long)(0x1da << 16);
    r_a3 = (long)(0 + (-1));
    r_a2 = (long)(r_v1 + (0x3110));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    r_t0 = (long)(0 | 0);
    goto _lbl_01D98230;
    r_v1 = (long)((unsigned long)r_t0 << (2));
_lbl_01D98224:
    r_v1 = (long)(r_a2 + r_v1);
    r_t0 = (long)(r_t0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_a3; }
_lbl_01D98230:
    r_v1 = (long)((long)r_t0 < (long)r_a0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (2)); goto _lbl_01D98224; }
    r_v1 = (long)((unsigned long)r_t0 << (2));
    r_a2 = (long)(0 | 0);
    goto _lbl_01D98254;
    r_v1 = (long)((unsigned long)r_a2 << (2));
_lbl_01D98248:
    r_v1 = (long)(r_t9 + r_v1);
    r_a2 = (long)(r_a2 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)0; }
_lbl_01D98254:
    r_v1 = (long)((long)r_a2 < (long)r_a0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a2 << (2)); goto _lbl_01D98248; }
    r_v1 = (long)((unsigned long)r_a2 << (2));
    r_v1 = (long)(0x1da << 16);
    r_a2 = (long)(0 + (1));
    r_a3 = (long)(r_v1 + (0x2c80));
    r_t0 = (long)(0 | 0);
    goto _lbl_01D9829C;
    r_v1 = (long)((unsigned long)r_t0 << (2));
_lbl_01D98278:
    r_v1 = (long)(r_a1 + r_v1);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1 == 0) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01D9829C; }
    r_t0 = (long)(r_t0 + (1));
    r_v1 = (long)((unsigned long)r_a2 << (2));
    r_v1 = (long)(r_a3 + r_v1);
    r_a2 = (long)(r_a2 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_t0; }
    r_t0 = (long)(r_t0 + (1));
_lbl_01D9829C:
    r_v1 = (long)((long)r_t0 < (long)r_a0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (2)); goto _lbl_01D98278; }
    r_v1 = (long)((unsigned long)r_t0 << (2));
    r_a2 = (long)(r_a2 + (-1));
    r_at = (long)((long)r_a2 < (long)(2) ? 1 : 0);
    if (r_at == 0) { r_t7 = (long)((long)r_a2 >> (1)); goto _lbl_01D982E0; }
    r_t7 = (long)((long)r_a2 >> (1));
    if (r_a2 == 0) goto _lbl_01D983F0;
    r_at = (long)(0x1da << 16);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x2c84)); }
    r_a0 = (long)(0 + (1));
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v1 = (long)(r_t9 + r_v1);
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_a0; }
    goto _lbl_01D983F0;
    r_t7 = (long)((long)r_a2 >> (1));
_lbl_01D982E0:
    goto _lbl_01D982FC;
    r_a3 = (long)(r_t7 | 0);
_lbl_01D982EC:
    r_v1 = (long)(0x1da << 16);
    r_t7 = (long)(r_a3 + (-1));
    r_a0 = (long)(r_v1 + (0x2c80));
    r_v0 = (long)func_01D98190((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D982FC:
    if (r_t7 != 0) { r_a3 = (long)(r_t7 | 0); goto _lbl_01D982EC; }
    r_a3 = (long)(r_t7 | 0);
_lbl_01D98304:
    r_v1 = (long)(0x1da << 16);
    r_v1 = (long)(r_v1 + (0x2c80));
    r_a0 = (long)((unsigned long)r_a2 << (2));
    r_at = (long)(0x1da << 16);
    r_v1 = (long)(r_v1 + r_a0);
    if (r_at) { r_t7 = *(int *)((char *)r_at + (0x2c84)); }
    if (r_v1) { r_a3 = *(int *)((char *)r_v1 + (0)); }
    r_a2 = (long)(r_a2 + (-1));
    r_at = (long)(0x1da << 16);
    r_v1 = (long)(0x1da << 16);
    if (r_at) { *(int *)((char *)r_at + (0x2c84)) = (int)r_a3; }
    r_a0 = (long)(r_v1 + (0x2c80));
    r_a3 = (long)(0 + (1));
    r_v0 = (long)func_01D98190((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((unsigned long)r_t7 << (2));
    r_v1 = (long)(r_a1 + r_v1);
    if (r_v1) { r_t0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(0x1da << 16);
    if (r_at) { r_t8 = *(int *)((char *)r_at + (0x2c84)); }
    r_a3 = (long)(0 + (1));
    r_v1 = (long)(0x1da << 16);
    r_a0 = (long)(r_v1 + (0x2c80));
    r_v1 = (long)((unsigned long)r_t8 << (2));
    r_t1 = (long)(r_a1 + r_v1);
    if (r_t1) { r_v1 = *(int *)((char *)r_t1 + (0)); }
    r_v1 = (long)(r_v1 + r_t0);
    if (r_t1) { *(int *)((char *)r_t1 + (0)) = (int)r_v1; }
    r_v0 = (long)func_01D98190((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0x1da << 16);
    r_a3 = (long)(r_v1 + (0x3110));
    r_v1 = (long)(0 + (-1));
    r_t2 = (long)((unsigned long)r_t8 << (2));
_lbl_01D98384:
    r_t1 = (long)(r_t9 + r_t2);
    if (r_t1) { r_t0 = *(int *)((char *)r_t1 + (0)); }
    r_a0 = (long)(r_a3 + r_t2);
    r_t0 = (long)(r_t0 + (1));
    if (r_t1) { *(int *)((char *)r_t1 + (0)) = (int)r_t0; }
    if (r_a0) { r_t8 = *(int *)((char *)r_a0 + (0)); }
    if (r_t8 != r_v1) { r_t2 = (long)((unsigned long)r_t8 << (2)); goto _lbl_01D98384; }
    r_t2 = (long)((unsigned long)r_t8 << (2));
    r_v1 = (long)(0x1da << 16);
    r_v1 = (long)(r_v1 + (0x3110));
    r_v1 = (long)(r_v1 + r_t2);
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_t7; }
    r_v1 = (long)(0x1da << 16);
    r_a3 = (long)(r_v1 + (0x3110));
    r_v1 = (long)(0 + (-1));
    r_a0 = (long)((unsigned long)r_t7 << (2));
_lbl_01D983C4:
    r_t1 = (long)(r_t9 + r_a0);
    if (r_t1) { r_t0 = *(int *)((char *)r_t1 + (0)); }
    r_a0 = (long)(r_a3 + r_a0);
    r_t0 = (long)(r_t0 + (1));
    if (r_t1) { *(int *)((char *)r_t1 + (0)) = (int)r_t0; }
    if (r_a0) { r_t7 = *(int *)((char *)r_a0 + (0)); }
    if (r_t7 != r_v1) { r_a0 = (long)((unsigned long)r_t7 << (2)); goto _lbl_01D983C4; }
    r_a0 = (long)((unsigned long)r_t7 << (2));
    r_v1 = (long)(0 + (1));
    if (r_a2 != r_v1) goto _lbl_01D98304;
_lbl_01D983F0:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 7: dcomp_func_01D983FC (VMA: 0x01D983FC, size: 292 bytes) */
void *dcomp_func_01D983FC(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_a3 = (long)(r_a0 | 0);
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)(0x1da << 16);
    r_v1 = (long)(r_a1 | 0);
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    r_a0 = (long)(r_a0 + (0x3a10));
    r_a2 = (long)(0 + (0x21));
    r_a1 = (long)(0 | 0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc8)) = (int)0; }
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0x1da << 16);
    r_a2 = (long)(r_a0 + (0x3a10));
    r_t0 = (long)(0 | 0);
    goto _lbl_01D9845C;
    r_a0 = (long)((unsigned long)r_t0 << (2));
_lbl_01D9843C:
    r_a0 = (long)(r_v1 + r_a0);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (0)); }
    r_t0 = (long)(r_t0 + (1));
    r_a0 = (long)((unsigned long)r_a0 << (2));
    r_a1 = (long)(r_a2 + r_a0);
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (0)); }
    r_a0 = (long)(r_a0 + (1));
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_a0; }
_lbl_01D9845C:
    r_a0 = (long)((long)r_t0 < (long)r_a3 ? 1 : 0);
    if (r_a0 != 0) { r_a0 = (long)((unsigned long)r_t0 << (2)); goto _lbl_01D9843C; }
    r_a0 = (long)((unsigned long)r_t0 << (2));
    r_a0 = (long)(0x1da << 16);
    r_a2 = (long)(r_a0 + (0x3aa0));
    r_a0 = (long)(0x1da << 16);
    r_t2 = (long)(0 + (1));
    r_a1 = (long)(r_a0 + (0x3a10));
    r_t0 = (long)(0 | 0);
    goto _lbl_01D984A0;
    r_t1 = (long)((unsigned long)r_t2 << (2));
_lbl_01D98488:
    r_a0 = (long)(r_a2 + r_t1);
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_t0; }
    r_a0 = (long)(r_a1 + r_t1);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (0)); }
    r_t2 = (long)(r_t2 + (1));
    r_t0 = (long)(r_t0 + r_a0);
_lbl_01D984A0:
    r_at = (long)((long)r_t2 < (long)(0x21) ? 1 : 0);
    if (r_at != 0) { r_t1 = (long)((unsigned long)r_t2 << (2)); goto _lbl_01D98488; }
    r_t1 = (long)((unsigned long)r_t2 << (2));
    r_a0 = (long)(0x1da << 16);
    r_t1 = (long)(r_a0 + (0x3aa0));
    r_a0 = (long)(0x1da << 16);
    r_a1 = (long)(r_a0 + (0x3590));
    r_t2 = (long)(0 | 0);
    goto _lbl_01D98508;
    r_a0 = (long)((unsigned long)r_t2 << (2));
_lbl_01D984C8:
    r_a0 = (long)(r_v1 + r_a0);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (0)); }
    if (r_a0 == 0) { r_t2 = (long)(r_t2 + (1)); goto _lbl_01D98508; }
    r_t2 = (long)(r_t2 + (1));
    r_a0 = (long)((unsigned long)r_a0 << (2));
    r_t0 = (long)(r_t1 + r_a0);
    if (r_t0) { r_a2 = *(int *)((char *)r_t0 + (0)); }
    r_a0 = (long)(r_a2 + (1));
    if (r_t0) { *(int *)((char *)r_t0 + (0)) = (int)r_a0; }
    r_a0 = (long)((unsigned long)r_a2 << (2));
    r_a0 = (long)(r_a1 + r_a0);
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_t2; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bc8)); }
    r_a0 = (long)(r_a0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc8)) = (int)r_a0; }
    r_t2 = (long)(r_t2 + (1));
_lbl_01D98508:
    r_a0 = (long)((long)r_t2 < (long)r_a3 ? 1 : 0);
    if (r_a0 != 0) { r_a0 = (long)((unsigned long)r_t2 << (2)); goto _lbl_01D984C8; }
    r_a0 = (long)((unsigned long)r_t2 << (2));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 8: dcomp_func_01D98520 (VMA: 0x01D98520, size: 268 bytes) */
void *dcomp_func_01D98520(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc8)); }
    r_at = (long)((long)r_v1 < (long)(2) ? 1 : 0);
    if (r_at != 0) goto _lbl_01D98624;
    r_v1 = (long)(0x1da << 16);
    r_v1 = (long)(r_v1 + (0x3a10));
    r_a1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 + r_a1);
    r_a1 = (long)(0x1da << 16);
    r_t0 = (long)(r_a0 + (1));
    r_a3 = (long)(r_a1 + (0x3a10));
    goto _lbl_01D9856C;
    r_a1 = (long)((unsigned long)r_t0 << (2));
_lbl_01D98554:
    r_a1 = (long)(r_a3 + r_a1);
    if (r_v1) { r_a2 = *(int *)((char *)r_v1 + (0)); }
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_t0 = (long)(r_t0 + (1));
    r_a1 = (long)(r_a2 + r_a1);
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_a1; }
_lbl_01D9856C:
    r_at = (long)((long)r_t0 < (long)(0x21) ? 1 : 0);
    if (r_at != 0) { r_a1 = (long)((unsigned long)r_t0 << (2)); goto _lbl_01D98554; }
    r_a1 = (long)((unsigned long)r_t0 << (2));
    r_a1 = (long)(0x1da << 16);
    r_a3 = (long)(r_a1 + (0x3a10));
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_a0 | 0);
    goto _lbl_01D985A8;
    r_a1 = (long)((unsigned long)r_t1 << (2));
_lbl_01D98590:
    r_a1 = (long)(r_a3 + r_a1);
    if (r_a1) { r_a2 = *(int *)((char *)r_a1 + (0)); }
    r_a1 = (long)(r_a0 - r_t1);
    r_a1 = (long)((unsigned long)r_a2 << r_a1);
    r_t1 = (long)(r_t1 + (-1));
    r_t0 = (long)(r_t0 + r_a1);
_lbl_01D985A8:
    if ((long)r_t1 > 0) { r_a1 = (long)((unsigned long)r_t1 << (2)); goto _lbl_01D98590; }
    r_a1 = (long)((unsigned long)r_t1 << (2));
    r_a1 = (long)(0 + (1));
    r_a1 = (long)(0x1da << 16);
    r_a2 = (long)(r_a1 + (0x3a10));
    goto _lbl_01D98614;
_lbl_01D985C4:
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (0)); }
    r_t2 = (long)(r_a0 + (-1));
    r_a1 = (long)(r_a1 + (-1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_a1; }
    goto _lbl_01D98608;
    r_a1 = (long)((unsigned long)r_t2 << (2));
_lbl_01D985DC:
    r_t1 = (long)(r_a2 + r_a1);
    if (r_t1) { r_a1 = *(int *)((char *)r_t1 + (0)); }
    if (r_a1 == 0) { r_t2 = (long)(r_t2 + (-1)); goto _lbl_01D98608; }
    r_t2 = (long)(r_t2 + (-1));
    r_a1 = (long)(r_a1 + (-1));
    if (r_t1) { *(int *)((char *)r_t1 + (0)) = (int)r_a1; }
    if (r_t1) { r_a1 = *(int *)((char *)r_t1 + (4)); }
    r_a1 = (long)(r_a1 + (2));
    if (r_t1) { *(int *)((char *)r_t1 + (4)) = (int)r_a1; }
    goto _lbl_01D98610;
    r_t2 = (long)(r_t2 + (-1));
_lbl_01D98608:
    if ((long)r_t2 > 0) { r_a1 = (long)((unsigned long)r_t2 << (2)); goto _lbl_01D985DC; }
    r_a1 = (long)((unsigned long)r_t2 << (2));
_lbl_01D98610:
    r_t0 = (long)(r_t0 + (-1));
_lbl_01D98614:
    if (r_a1 != r_a3) goto _lbl_01D985C4;
_lbl_01D98624:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 9: dcomp_func_01D9862C (VMA: 0x01D9862C, size: 424 bytes) */
void *dcomp_func_01D9862C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    (void)r_t5;
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc8)); }
    if (r_v1 == 0) goto _lbl_01D987CC;
    r_t0 = (long)(0 | 0);
    goto _lbl_01D98654;
    r_v1 = (long)((unsigned long)r_t0 << (2));
_lbl_01D98648:
    r_v1 = (long)(r_a3 + r_v1);
    r_t0 = (long)(r_t0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)0; }
_lbl_01D98654:
    r_v1 = (long)((long)r_t0 < (long)r_a0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (2)); goto _lbl_01D98648; }
    r_v1 = (long)((unsigned long)r_t0 << (2));
    r_v1 = (long)(0x1da << 16);
    r_t1 = (long)(r_v1 + (0x3a10));
    r_v1 = (long)(0x1da << 16);
    r_t4 = (long)(0 + (1));
    r_t0 = (long)(r_v1 + (0x3b30));
    r_t3 = (long)(0 | 0);
    goto _lbl_01D986AC;
    r_v1 = (long)((unsigned long)r_t4 << (2));
_lbl_01D98680:
    r_v1 = (long)(r_t1 + r_v1);
    if (r_v1) { r_t2 = *(int *)((char *)r_v1 + (0)); }
    goto _lbl_01D986A0;
    r_v1 = (long)((unsigned long)r_t3 << (2));
_lbl_01D98690:
    r_v1 = (long)(r_t0 + r_v1);
    r_t3 = (long)(r_t3 + (1));
    r_t2 = (long)(r_t2 + (-1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_t4; }
_lbl_01D986A0:
    if ((long)r_t2 > 0) { r_v1 = (long)((unsigned long)r_t3 << (2)); goto _lbl_01D98690; }
    r_v1 = (long)((unsigned long)r_t3 << (2));
    r_t4 = (long)(r_t4 + (1));
_lbl_01D986AC:
    r_at = (long)((long)r_a2 < (long)r_t4 ? 1 : 0);
    if (r_at == 0) { r_v1 = (long)((unsigned long)r_t4 << (2)); goto _lbl_01D98680; }
    r_v1 = (long)((unsigned long)r_t4 << (2));
    r_v1 = (long)(0x1da << 16);
    r_t2 = (long)(r_v1 + (0x3a10));
    r_v1 = (long)(0x1da << 16);
    r_at = (long)(0x1da << 16);
    r_t5 = (long)(0 + (2));
    r_t0 = (long)(r_v1 + (0x3aa0));
    if (r_at) { *(int *)((char *)r_at + (0x3aa4)) = (int)0; }
    r_t3 = (long)(0 | 0);
    goto _lbl_01D986FC;
    r_t4 = (long)((unsigned long)r_t5 << (2));
_lbl_01D986E0:
    r_v1 = (long)(r_t2 + r_t4);
    if (r_v1) { r_t1 = *(int *)((char *)r_v1 + (-4)); }
    r_t5 = (long)(r_t5 + (1));
    r_t1 = (long)(r_t3 + r_t1);
    r_v1 = (long)(r_t0 + r_t4);
    r_t3 = (long)((unsigned long)r_t1 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_t3; }
_lbl_01D986FC:
    r_at = (long)((long)r_a2 < (long)r_t5 ? 1 : 0);
    if (r_at == 0) { r_t4 = (long)((unsigned long)r_t5 << (2)); goto _lbl_01D986E0; }
    r_t4 = (long)((unsigned long)r_t5 << (2));
    r_v1 = (long)(0x1da << 16);
    r_t1 = (long)(r_v1 + (0x3b30));
    r_v1 = (long)(0x1da << 16);
    r_a2 = (long)(r_v1 + (0x3590));
    r_t3 = (long)(0 | 0);
    goto _lbl_01D98744;
    r_t2 = (long)((unsigned long)r_t3 << (2));
_lbl_01D98724:
    r_v1 = (long)(r_t1 + r_t2);
    if (r_v1) { r_t0 = *(int *)((char *)r_v1 + (0)); }
    r_t3 = (long)(r_t3 + (1));
    r_v1 = (long)(r_a2 + r_t2);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v1 = (long)(r_a1 + r_v1);
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_t0; }
_lbl_01D98744:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc8)); }
    r_v1 = (long)((long)r_t3 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_t2 = (long)((unsigned long)r_t3 << (2)); goto _lbl_01D98724; }
    r_t2 = (long)((unsigned long)r_t3 << (2));
    r_v1 = (long)(0x1da << 16);
    r_t0 = (long)(r_v1 + (0x3aa0));
    r_t3 = (long)(0 | 0);
    goto _lbl_01D987C0;
    r_t2 = (long)((unsigned long)r_t3 << (2));
_lbl_01D98768:
    r_t1 = (long)(r_a1 + r_t2);
    if (r_t1) { r_v1 = *(int *)((char *)r_t1 + (0)); }
    if (r_v1 == 0) { r_t3 = (long)(r_t3 + (1)); goto _lbl_01D987C0; }
    r_t3 = (long)(r_t3 + (1));
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_a2 = (long)(r_t0 + r_v1);
    if (r_a2) { r_t5 = *(int *)((char *)r_a2 + (0)); }
    r_v1 = (long)(r_t5 + (1));
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_v1; }
    if (r_t1) { r_t1 = *(int *)((char *)r_t1 + (0)); }
    r_t4 = (long)(0 | 0);
    goto _lbl_01D987AC;
    r_v1 = (long)(r_t5 & (1));
_lbl_01D9879C:
    r_a2 = (long)((unsigned long)r_t4 << (1));
    r_t1 = (long)(r_t1 + (-1));
    r_t4 = (long)(r_a2 | r_v1);
    r_t5 = (long)((unsigned long)r_t5 >> (1));
_lbl_01D987AC:
    if ((long)r_t1 > 0) { r_v1 = (long)(r_t5 & (1)); goto _lbl_01D9879C; }
    r_v1 = (long)(r_t5 & (1));
    r_v1 = (long)(r_a3 + r_t2);
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_t4; }
    r_t3 = (long)(r_t3 + (1));
_lbl_01D987C0:
    r_v1 = (long)((long)r_t3 < (long)r_a0 ? 1 : 0);
    if (r_v1 != 0) { r_t2 = (long)((unsigned long)r_t3 << (2)); goto _lbl_01D98768; }
    r_t2 = (long)((unsigned long)r_t3 << (2));
_lbl_01D987CC:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 10: dcomp_func_01D987D4 (VMA: 0x01D987D4, size: 620 bytes) */
void *dcomp_func_01D987D4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bcc)); }
    if (r_v0 != 0) goto _lbl_01D98A10;
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bd0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd4)); }
    r_v1 = (long)((unsigned long)r_a0 << r_a2);
    r_v0 = (long)(r_v0 | r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd4)) = (int)r_v0; }
    r_v0 = (long)(r_a2 + r_a1);
    r_at = (long)((long)r_v0 < (long)(8) ? 1 : 0);
    if (r_at == 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd0)) = (int)r_v0; } goto _lbl_01D98820; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd0)) = (int)r_v0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01D98A34;
_lbl_01D98820:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd0)); }
    r_at = (long)((long)r_v0 < (long)(0x10) ? 1 : 0);
    if (r_at == 0) goto _lbl_01D988F0;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D98878; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(unsigned char *)((char *)r_gp + (-0x6bd4)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(0 | 0);
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bd0)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd4)); }
    r_a1 = (long)(r_a1 + (1));
    r_v1 = (long)(r_v1 + (-8));
    r_a0 = (long)((unsigned long)r_a0 >> (8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_a1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd4)) = (int)r_a0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd0)) = (int)r_v1; }
    goto _lbl_01D98A34;
_lbl_01D98878:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    goto _lbl_01D988A8;
_lbl_01D98888:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D988A8;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98A34;
_lbl_01D988A8:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D98888; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(unsigned char *)((char *)r_gp + (-0x6bd4)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(0 | 0);
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bd0)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd4)); }
    r_a1 = (long)(r_a1 + (1));
    r_v1 = (long)(r_v1 + (-8));
    r_a0 = (long)((unsigned long)r_a0 >> (8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_a1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd4)) = (int)r_a0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd0)) = (int)r_v1; }
    goto _lbl_01D98A34;
_lbl_01D988F0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-2));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D98948; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(unsigned char *)((char *)r_gp + (-0x6bd4)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(0 | 0);
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd4)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_a0 = (long)((unsigned long)r_a0 >> (8));
    if (r_v1) { *(char *)((char *)r_v1 + (1)) = (char)r_a0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bd0)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd4)); }
    r_a1 = (long)(r_a1 + (2));
    r_v1 = (long)(r_v1 + (-0x10));
    r_a0 = (long)((unsigned long)r_a0 >> (0x10));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_a1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd4)) = (int)r_a0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd0)) = (int)r_v1; }
    goto _lbl_01D98A34;
_lbl_01D98948:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    goto _lbl_01D98978;
_lbl_01D98958:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98978;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98A34;
_lbl_01D98978:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D98958; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(unsigned char *)((char *)r_gp + (-0x6bd4)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_v0; }
    goto _lbl_01D989C4;
_lbl_01D989A4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D989C4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98A34;
_lbl_01D989C4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D989A4; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd4)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(0 | 0);
    r_a0 = (long)((unsigned long)r_a0 >> (8));
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bdc)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bd0)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd4)); }
    r_a1 = (long)(r_a1 + (1));
    r_v1 = (long)(r_v1 + (-0x10));
    r_a0 = (long)((unsigned long)r_a0 >> (0x10));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_a1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd4)) = (int)r_a0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd0)) = (int)r_v1; }
    goto _lbl_01D98A34;
_lbl_01D98A10:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(0 | 0);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee4)); }
    r_at = (long)(4 << 16);
    r_v1 = (long)(r_v1 + r_a1);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee4)) = (int)r_v1; }
_lbl_01D98A34:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 11: dcomp_func_01D98A40 (VMA: 0x01D98A40, size: 56 bytes) */
void *dcomp_func_01D98A40(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)(0 + (7));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    r_a0 = (long)(0 | 0);
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98A64;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98A6C;
_lbl_01D98A64:
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd0)) = (int)0; }
    r_v0 = (long)(0 | 0);
_lbl_01D98A6C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 12: dcomp_func_01D98A78 (VMA: 0x01D98A78, size: 120 bytes) */
void *dcomp_func_01D98A78(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_a3 = (long)(r_a0 + (0x1000));
    r_a2 = (long)(0 | (0xffff));
    goto _lbl_01D98ADC;
_lbl_01D98A8C:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bec)); }
    r_a1 = (long)((unsigned long)r_a0 << (1));
    r_v1 = (long)(r_v1 + r_a1);
    if (r_v1) { r_a1 = *(unsigned short *)((char *)r_v1 + (0)); }
    r_v1 = (long)(r_a1 & (0x8000));
    if (r_v1 == 0) goto _lbl_01D98AC8;
    if (r_a1 == r_a2) { r_a0 = (long)(r_a0 + (1)); goto _lbl_01D98ADC; }
    r_a0 = (long)(r_a0 + (1));
    r_v1 = (long)(r_a1 & (0x7fff));
    r_a1 = (long)((unsigned long)r_v1 << (1));
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf4)); }
    r_v1 = (long)(r_v1 + r_a1);
    if (r_v1) { *(short *)((char *)r_v1 + (0)) = (short)r_a2; }
    goto _lbl_01D98AD8;
_lbl_01D98AC8:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf0)); }
    r_a1 = (long)((unsigned long)r_a1 << (1));
    r_v1 = (long)(r_v1 + r_a1);
    if (r_v1) { *(short *)((char *)r_v1 + (0)) = (short)r_a2; }
_lbl_01D98AD8:
    r_a0 = (long)(r_a0 + (1));
_lbl_01D98ADC:
    r_v1 = (long)((unsigned long)r_a0 < (unsigned long)r_a3 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01D98A8C;
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 13: dcomp_func_01D98AF0 (VMA: 0x01D98AF0, size: 268 bytes) */
void *dcomp_func_01D98AF0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_t0 = (long)(r_a1 + (-2));
    r_at = (long)((long)r_t0 < (long)0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D98B04;
    r_t0 = (long)(0 | 0);
_lbl_01D98B04:
    r_a2 = (long)(0 | (0xffff));
    goto _lbl_01D98B30;
_lbl_01D98B0C:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bec)); }
    r_a3 = (long)(r_a0 + r_t0);
    r_a3 = (long)((unsigned long)r_a3 << (1));
    r_t0 = (long)(r_t0 + (1));
    r_v1 = (long)(r_v1 + r_a3);
    if (r_v1) { *(short *)((char *)r_v1 + (0)) = (short)r_a2; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf0)); }
    r_v1 = (long)(r_v1 + r_a3);
    if (r_v1) { *(short *)((char *)r_v1 + (0)) = (short)r_a2; }
_lbl_01D98B30:
    r_v1 = (long)((unsigned long)r_t0 < (unsigned long)r_a1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01D98B0C;
    r_at = (long)((long)r_a1 < (long)(3) ? 1 : 0);
    if (r_at != 0) goto _lbl_01D98BF4;
    r_v1 = (long)(r_a0 + r_a1);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bf8)); }
    r_v1 = (long)(r_v1 + (-2));
    r_a3 = (long)(0 | (0xffff));
    r_a1 = (long)(r_a1 + r_a0);
    if (r_a1) { r_a2 = *(unsigned char *)((char *)r_a1 + (0)); }
    if (r_a1) { r_a1 = *(unsigned char *)((char *)r_a1 + (1)); }
    r_a2 = (long)((unsigned long)r_a2 << (5));
    r_t1 = (long)(r_a2 ^ r_a1);
    goto _lbl_01D98BE8;
_lbl_01D98B70:
    if (r_gp) { r_t0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    r_a1 = (long)((unsigned long)r_t1 << (5));
    r_a2 = (long)(r_a1 & (0x1fff));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bec)); }
    r_t2 = (long)((unsigned long)r_a0 << (1));
    r_t0 = (long)(r_t0 + r_a0);
    if (r_t0) { r_t0 = *(unsigned char *)((char *)r_t0 + (2)); }
    r_a1 = (long)(r_a1 + r_t2);
    r_t1 = (long)(r_a2 ^ r_t0);
    r_a2 = (long)(r_t1 | (0x8000));
    if (r_a1) { *(short *)((char *)r_a1 + (0)) = (short)r_a2; }
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bf4)); }
    r_t0 = (long)((unsigned long)r_t1 << (1));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bf0)); }
    r_a2 = (long)(r_a2 + r_t0);
    if (r_a2) { r_a2 = *(unsigned short *)((char *)r_a2 + (0)); }
    r_a1 = (long)(r_a1 + r_t2);
    if (r_a2 == r_a3) { if (r_a1) { *(short *)((char *)r_a1 + (0)) = (short)r_a2; } goto _lbl_01D98BD8; }
    if (r_a1) { *(short *)((char *)r_a1 + (0)) = (short)r_a2; }
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bf0)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bec)); }
    r_a2 = (long)(r_a2 + r_t2);
    if (r_a2) { r_a2 = *(unsigned short *)((char *)r_a2 + (0)); }
    r_a2 = (long)((unsigned long)r_a2 << (1));
    r_a1 = (long)(r_a1 + r_a2);
    if (r_a1) { *(short *)((char *)r_a1 + (0)) = (short)r_a0; }
_lbl_01D98BD8:
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bf4)); }
    r_a1 = (long)(r_a1 + r_t0);
    if (r_a1) { *(short *)((char *)r_a1 + (0)) = (short)r_a0; }
    r_a0 = (long)(r_a0 + (1));
_lbl_01D98BE8:
    r_a1 = (long)((unsigned long)r_a0 < (unsigned long)r_v1 ? 1 : 0);
    if (r_a1 != 0) goto _lbl_01D98B70;
_lbl_01D98BF4:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 14: dcomp_func_01D98BFC (VMA: 0x01D98BFC, size: 232 bytes) */
void *dcomp_func_01D98BFC(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0, r_t8 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    (void)r_t7;
    (void)r_t8;
    (void)r_t9;
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bf8)); }
    r_t5 = (long)(r_a0 & (0x7fff));
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6be4)); }
    if (r_gp) { r_t4 = *(int *)((char *)r_gp + (-0x6be8)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf0)); }
    r_a0 = (long)(r_a1 + r_a0);
    r_a2 = (long)(r_a0 + r_a2);
    if (r_a2) { r_t6 = *(unsigned char *)((char *)r_a2 + (0)); }
    if (r_a2) { r_t7 = *(unsigned char *)((char *)r_a2 + (-1)); }
    r_a3 = (long)(0 + (0x102));
    r_t2 = (long)(0 | (0xffff));
_lbl_01D98C30:
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_t3 = (long)(r_t6 & (0xff));
    r_t1 = (long)(r_a1 + r_a2);
    r_t4 = (long)(r_t4 + (-1));
_lbl_01D98C40:
    if (r_t4 == 0) goto _lbl_01D98CDC;
    r_t0 = (long)((unsigned long)r_t5 << (1));
    r_t0 = (long)(r_v1 + r_t0);
    if (r_t0) { r_t5 = *(unsigned short *)((char *)r_t0 + (0)); }
    if (r_t5 == r_t2) goto _lbl_01D98CDC;
    r_t0 = (long)(r_t1 + r_t5);
    if (r_t0) { r_t0 = *(unsigned char *)((char *)r_t0 + (0)); }
    if (r_t3 != r_t0) { r_t4 = (long)(r_t4 + (-1)); goto _lbl_01D98C40; }
    r_t4 = (long)(r_t4 + (-1));
    r_t9 = (long)(r_a1 + r_t5);
    r_t0 = (long)(r_t9 + r_a2);
    if (r_t0) { r_t0 = *(unsigned char *)((char *)r_t0 + (-1)); }
    r_t1 = (long)(r_t7 & (0xff));
    if (r_t1 != r_t0) goto _lbl_01D98C30;
    r_t8 = (long)(r_a0 | 0);
    r_t3 = (long)(0 | 0);
    goto _lbl_01D98CA8;
_lbl_01D98C90:
    if (r_t8) { r_t1 = *(unsigned char *)((char *)r_t8 + (0)); }
    if (r_t9) { r_t0 = *(unsigned char *)((char *)r_t9 + (0)); }
    r_t8 = (long)(r_t8 + (1));
    if (r_t1 != r_t0) { r_t9 = (long)(r_t9 + (1)); goto _lbl_01D98CB4; }
    r_t9 = (long)(r_t9 + (1));
    r_t3 = (long)(r_t3 + (1));
_lbl_01D98CA8:
    r_t0 = (long)((long)r_t3 < (long)(0x102) ? 1 : 0);
    if (r_t0 != 0) goto _lbl_01D98C90;
_lbl_01D98CB4:
    r_at = (long)((long)r_a2 < (long)r_t3 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D98C30;
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be0)) = (int)r_t5; }
    if (r_t3 == r_a3) { if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_t3; } goto _lbl_01D98CDC; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_t3; }
    r_a2 = (long)(r_a0 + r_t3);
    if (r_a2) { r_t7 = *(unsigned char *)((char *)r_a2 + (-1)); }
    if (r_a2) { r_t6 = *(unsigned char *)((char *)r_a2 + (0)); }
    goto _lbl_01D98C30;
_lbl_01D98CDC:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 15: dcomp_func_01D98CE4 (VMA: 0x01D98CE4, size: 744 bytes) */
void *dcomp_func_01D98CE4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x80));
    if (r_sp) { *(long *)((char *)r_sp + (112)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (96)) = (long)r_s6; }
    if (r_sp) { *(long *)((char *)r_sp + (80)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (64)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (48)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (32)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(2 << 16);
    r_at = (long)(r_at | (0xd102));
    r_s1 = (long)(r_v0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x610c));
    r_s4 = (long)(r_v0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_s0 = *(int *)((char *)r_at + (0x6108)); }
    r_s2 = (long)(0 | 0);
    goto _lbl_01D98F70;
_lbl_01D98D44:
    if (r_s2 != 0) { r_v0 = (long)(0x8000 << 16); goto _lbl_01D98D5C; }
    r_v0 = (long)(0x8000 << 16);
    if (r_s4) { r_s3 = *(int *)((char *)r_s4 + (0)); }
    r_s2 = (long)(0 + (0x20));
    r_s4 = (long)(r_s4 + (4));
    r_v0 = (long)(0x8000 << 16);
_lbl_01D98D5C:
    r_v0 = (long)(r_s3 & r_v0);
    if (r_v0 == 0) goto _lbl_01D98F24;
    if (r_s1) { r_s5 = *(unsigned char *)((char *)r_s1 + (0)); }
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x1d20));
    if (r_s1) { r_a1 = *(unsigned char *)((char *)r_s1 + (2)); }
    if (r_s1) { r_a2 = *(unsigned char *)((char *)r_s1 + (1)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_a0 = (long)((unsigned long)r_s5 << (1));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_v1) { r_v1 = *(unsigned short *)((char *)r_v1 + (0)); }
    r_a0 = (long)((unsigned long)r_a1 << (8));
    r_a0 = (long)(r_a2 + r_a0);
    r_at = (long)(3 << 16);
    r_s6 = (long)(r_a0 + (-1));
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x71b8)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x6c6c)); }
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98DCC;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98FA4;
_lbl_01D98DCC:
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2020));
    r_v0 = (long)(r_v0 + r_s5);
    if (r_v0) { r_v1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x1f20));
    r_v0 = (long)(r_v0 + r_s5);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s5 & r_v1);
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_at = (long)((unsigned long)r_s6 < (unsigned long)(0x200) ? 1 : 0); goto _lbl_01D98E08; }
    r_at = (long)((unsigned long)r_s6 < (unsigned long)(0x200) ? 1 : 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98FA4;
    r_at = (long)((unsigned long)r_s6 < (unsigned long)(0x200) ? 1 : 0);
_lbl_01D98E08:
    if (r_at == 0) goto _lbl_01D98E90;
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x2120));
    r_v1 = (long)(r_v1 + r_s6);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x7638)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x70ec)); }
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98E58;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98FA4;
_lbl_01D98E58:
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2520));
    r_v0 = (long)(r_v0 + r_s6);
    if (r_v0) { r_v1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2320));
    r_v0 = (long)(r_v0 + r_s6);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s6 & r_v1);
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s1 = (long)(r_s1 + (3)); goto _lbl_01D98F1C; }
    r_s1 = (long)(r_s1 + (3));
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98FA4;
_lbl_01D98E90:
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x2720));
    r_s5 = (long)((unsigned long)r_s6 >> (8));
    r_v1 = (long)(r_v1 + r_s5);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x7638)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x70ec)); }
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98EDC;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98FA4;
_lbl_01D98EDC:
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2820));
    r_v1 = (long)((unsigned long)r_s5 << (1));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v1 = *(unsigned short *)((char *)r_v0 + (0)); }
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x27a0));
    r_v0 = (long)(r_v0 + r_s5);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s6 & r_v1);
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98F18;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98FA4;
_lbl_01D98F18:
    r_s1 = (long)(r_s1 + (3));
_lbl_01D98F1C:
    r_s2 = (long)(r_s2 + (-1));
    goto _lbl_01D98F68;
_lbl_01D98F24:
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x71b8)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x6c6c)); }
    r_s1 = (long)(r_s1 + (1));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98F64;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D98FA4;
_lbl_01D98F64:
    r_s2 = (long)(r_s2 + (-1));
_lbl_01D98F68:
    r_s0 = (long)(r_s0 + (-1));
    r_s3 = (long)((unsigned long)r_s3 << (1));
_lbl_01D98F70:
    if ((long)r_s0 > 0) goto _lbl_01D98D44;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x75b8)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x706c)); }
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 == 0) r_v1 = 0;
    r_v0 = (long)(r_v1 | 0);
_lbl_01D98FA4:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (112)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (96)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (80)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (64)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (48)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (32)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 16: dcomp_func_01D98FCC (VMA: 0x01D98FCC, size: 292 bytes) */
void *dcomp_func_01D98FCC(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c6c));
    r_a1 = (long)(0 + (8));
    r_a2 = (long)(0 + (0x90));
    r_a0 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6eac));
    r_a1 = (long)(0 + (9));
    r_a2 = (long)(0 + (0x70));
    r_a0 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x706c));
    r_a1 = (long)(0 + (7));
    r_a2 = (long)(0 + (0x18));
    r_a0 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_a1 = (long)(0 + (8));
    r_at = (long)(r_at | (0x70cc));
    r_a2 = (long)(r_a1 | 0);
    r_a0 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c6c));
    r_a0 = (long)(0 + (0x120));
    r_a1 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98480((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c6c));
    r_a0 = (long)(0 + (0x120));
    r_a2 = (long)(0 + (0xf));
    r_a1 = (long)(r_v1 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x71b8));
    r_a3 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D986B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x70ec));
    r_a1 = (long)(0 + (5));
    r_a2 = (long)(0 + (0x20));
    r_a0 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x70ec));
    r_a0 = (long)(0 + (0x20));
    r_a1 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98480((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x70ec));
    r_a0 = (long)(0 + (0x20));
    r_a2 = (long)(0 + (0xf));
    r_a1 = (long)(r_v1 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x7638));
    r_a3 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D986B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 17: dcomp_func_01D990F0 (VMA: 0x01D990F0, size: 44 bytes) */
void *dcomp_func_01D990F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)(0 + (1));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    r_a1 = (long)(0 + (2));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_v1 = (long)(0 + (1));
    if (r_v0 == 0) r_v1 = 0;
    r_v0 = (long)(r_v1 | 0);
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 18: dcomp_func_01D9911C (VMA: 0x01D9911C, size: 152 bytes) */
void *dcomp_func_01D9911C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    r_at = (long)((long)r_a2 < (long)(3) ? 1 : 0);
    if (r_at == 0) { r_v0 = (long)(r_a2 + (-3)); goto _lbl_01D99178; }
    r_v0 = (long)(r_a2 + (-3));
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_v0 = (long)((unsigned long)r_a1 << (2));
    r_at = (long)(3 << 16);
    r_v1 = (long)(r_v0 + r_v1);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6c20)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_a2);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6c20)) = (int)r_v0; }
    goto _lbl_01D99160;
_lbl_01D99158:
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_a1; }
    r_a0 = (long)(r_a0 + (4));
_lbl_01D99160:
    r_v0 = (long)(r_a2 | 0);
    if (r_v0 != 0) { r_a2 = (long)(r_v0 + (-1)); goto _lbl_01D99158; }
    r_a2 = (long)(r_v0 + (-1));
    r_v0 = (long)(r_a0 | 0);
    goto _lbl_01D991AC;
    r_v0 = (long)(r_a2 + (-3));
_lbl_01D99178:
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v1 = (long)(0 + (0x10));
    r_at = (long)(r_a2 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x6c60)); }
    r_at = (long)(3 << 16);
    r_a1 = (long)(r_a1 + (1));
    r_at = (long)(r_a2 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6c60)) = (int)r_a1; }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    r_a0 = (long)(r_a0 + (8));
    r_v0 = (long)(r_a0 | 0);
_lbl_01D991AC:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 19: dcomp_func_01D991B4 (VMA: 0x01D991B4, size: 220 bytes) */
void *dcomp_func_01D991B4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    r_at = (long)((long)r_a1 < (long)(3) ? 1 : 0);
    if (r_at == 0) { r_at = (long)((long)r_a1 < (long)(0xb) ? 1 : 0); goto _lbl_01D99210; }
    r_at = (long)((long)r_a1 < (long)(0xb) ? 1 : 0);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6c20)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_a1);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6c20)) = (int)r_v0; }
    goto _lbl_01D991F8;
_lbl_01D991F0:
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)0; }
    r_a0 = (long)(r_a0 + (4));
_lbl_01D991F8:
    r_v0 = (long)(r_a1 | 0);
    if (r_v0 != 0) { r_a1 = (long)(r_v0 + (-1)); goto _lbl_01D991F0; }
    r_a1 = (long)(r_v0 + (-1));
    r_v0 = (long)(r_a0 | 0);
    goto _lbl_01D99288;
    r_at = (long)((long)r_a1 < (long)(0xb) ? 1 : 0);
_lbl_01D99210:
    if (r_at == 0) goto _lbl_01D99250;
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a1 + (-3));
    r_v1 = (long)(0 + (0x11));
    r_at = (long)(r_a2 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x6c64)); }
    r_at = (long)(3 << 16);
    r_a1 = (long)(r_a1 + (1));
    r_at = (long)(r_a2 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6c64)) = (int)r_a1; }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    r_a0 = (long)(r_a0 + (8));
    goto _lbl_01D99284;
_lbl_01D99250:
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a1 + (-0xb));
    r_v1 = (long)(0 + (0x12));
    r_at = (long)(r_a2 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x6c68)); }
    r_at = (long)(3 << 16);
    r_a1 = (long)(r_a1 + (1));
    r_at = (long)(r_a2 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6c68)) = (int)r_a1; }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    r_a0 = (long)(r_a0 + (8));
_lbl_01D99284:
    r_v0 = (long)(r_a0 | 0);
_lbl_01D99288:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 20: dcomp_func_01D99290 (VMA: 0x01D99290, size: 872 bytes) */
void *dcomp_func_01D99290(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c20));
    r_a2 = (long)(0 + (0x13));
    r_a3 = (long)(0 + (0xff));
    r_a0 = (long)(r_v1 + r_at);
    r_a1 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(0 | 0);
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_a0 = (long)(0 + (0x11d));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ef8)) = (int)r_a0; }
    goto _lbl_01D99300;
    r_v1 = (long)((unsigned long)r_a1 << (2));
_lbl_01D992DC:
    r_v1 = (long)(r_a0 + r_v1);
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6c6c)); }
    if (r_v1 != 0) { r_v1 = (long)(r_a1 + (1)); goto _lbl_01D99320; }
    r_v1 = (long)(r_a1 + (1));
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    r_v1 = (long)(r_v1 + (-1));
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_v1; }
_lbl_01D99300:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x8108));
    r_a2 = (long)(r_a0 + r_at);
    if (r_a2) { r_a1 = *(int *)((char *)r_a2 + (0)); }
    if ((long)r_a1 >= 0) { r_v1 = (long)((unsigned long)r_a1 << (2)); goto _lbl_01D992DC; }
    r_v1 = (long)((unsigned long)r_a1 << (2));
    r_v1 = (long)(r_a1 + (1));
_lbl_01D99320:
    r_at = (long)((long)r_v1 < (long)(0x101) ? 1 : 0);
    if (r_at == 0) goto _lbl_01D99330;
    r_v1 = (long)(0 + (0x101));
_lbl_01D99330:
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_a0 = (long)(0 + (0x1d));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ef4)) = (int)r_a0; }
    goto _lbl_01D99374;
    r_v1 = (long)((unsigned long)r_a1 << (2));
_lbl_01D99350:
    r_v1 = (long)(r_a0 + r_v1);
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x70ec)); }
    if (r_v1 != 0) goto _lbl_01D99390;
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    r_v1 = (long)(r_v1 + (-1));
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_v1; }
_lbl_01D99374:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x810c));
    r_a2 = (long)(r_a0 + r_at);
    if (r_a2) { r_a1 = *(int *)((char *)r_a2 + (0)); }
    if ((long)r_a1 >= 0) { r_v1 = (long)((unsigned long)r_a1 << (2)); goto _lbl_01D99350; }
    r_v1 = (long)((unsigned long)r_a1 << (2));
_lbl_01D99390:
    if ((long)r_a1 >= 0) { r_v1 = (long)(r_a1 + (1)); goto _lbl_01D993A4; }
    r_v1 = (long)(r_a1 + (1));
    r_v1 = (long)(0 + (1));
    goto _lbl_01D993A4;
    r_v1 = (long)(r_a1 + (1));
_lbl_01D993A4:
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x7704));
    r_a0 = (long)(r_v1 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c6c));
    r_a1 = (long)(r_v1 + r_at);
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_a2 = *(int *)((char *)r_at + (-0x7ef8)); }
    r_v0 = (long)func_01D980B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ef8)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x70ec));
    r_a1 = (long)(r_a0 + r_at);
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_a2 = *(int *)((char *)r_at + (-0x7ef4)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v1 = (long)(r_a0 + r_v1);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x7704));
    r_a0 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D980B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x7704));
    r_t2 = (long)(r_v1 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x7c04));
    r_a0 = (long)(r_v1 + r_at);
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (-0x7ef8)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ef4)); }
    r_t3 = (long)(r_a1 + r_v1);
    goto _lbl_01D99538;
_lbl_01D99450:
    if (r_t2) { r_t4 = *(int *)((char *)r_t2 + (0)); }
    if (r_t4 != 0) { r_t2 = (long)(r_t2 + (4)); goto _lbl_01D9949C; }
    r_t2 = (long)(r_t2 + (4));
    if (r_t1 == 0) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01D9947C; }
    r_t0 = (long)(r_t0 + (1));
    r_a1 = (long)(r_a3 | 0);
    r_a2 = (long)(r_t1 | 0);
    r_v0 = (long)func_01D991A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    r_t1 = (long)(0 | 0);
    r_t0 = (long)(r_t0 + (1));
_lbl_01D9947C:
    r_v1 = (long)(0 + (0x8a));
    if (r_t0 != r_v1) { r_t3 = (long)(r_t3 + (-1)); goto _lbl_01D99534; }
    r_t3 = (long)(r_t3 + (-1));
    r_a1 = (long)(r_t0 | 0);
    r_v0 = (long)func_01D99240((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    r_t0 = (long)(0 | 0);
    goto _lbl_01D99530;
_lbl_01D9949C:
    if (r_t0 == 0) goto _lbl_01D994B4;
    r_a1 = (long)(r_t0 | 0);
    r_v0 = (long)func_01D99240((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    r_t0 = (long)(0 | 0);
_lbl_01D994B4:
    if (r_t4 == r_a3) { r_t1 = (long)(r_t1 + (1)); goto _lbl_01D99510; }
    r_t1 = (long)(r_t1 + (1));
    if (r_t1 == 0) goto _lbl_01D994D8;
    r_a1 = (long)(r_a3 | 0);
    r_a2 = (long)(r_t1 | 0);
    r_v0 = (long)func_01D991A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    r_t1 = (long)(0 | 0);
_lbl_01D994D8:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_a1 = (long)((unsigned long)r_t4 << (2));
    r_at = (long)(3 << 16);
    r_a1 = (long)(r_v1 + r_a1);
    r_at = (long)(r_a1 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6c20)); }
    r_at = (long)(3 << 16);
    r_v1 = (long)(r_v1 + (1));
    r_at = (long)(r_a1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6c20)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_t4; }
    r_a0 = (long)(r_a0 + (4));
    goto _lbl_01D99530;
    r_t1 = (long)(r_t1 + (1));
_lbl_01D99510:
    r_v1 = (long)(0 + (6));
    if (r_t1 != r_v1) goto _lbl_01D99530;
    r_a1 = (long)(r_a3 | 0);
    r_a2 = (long)(r_t1 | 0);
    r_v0 = (long)func_01D991A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    r_t1 = (long)(0 | 0);
_lbl_01D99530:
    r_t3 = (long)(r_t3 + (-1));
_lbl_01D99534:
    r_a3 = (long)(r_t4 | 0);
_lbl_01D99538:
    if ((long)r_t3 > 0) goto _lbl_01D99450;
    if (r_t1 == 0) goto _lbl_01D9955C;
    r_a1 = (long)(r_a3 | 0);
    r_a2 = (long)(r_t1 | 0);
    r_v0 = (long)func_01D991A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    goto _lbl_01D99570;
_lbl_01D9955C:
    if (r_t0 == 0) goto _lbl_01D99570;
    r_a1 = (long)(r_t0 | 0);
    r_v0 = (long)func_01D99240((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
_lbl_01D99570:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7efc)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c20));
    r_a0 = (long)(0 + (0x13));
    r_a1 = (long)(r_v1 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x716c));
    r_a2 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98280((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x716c));
    r_a0 = (long)(0 + (0x13));
    r_a1 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D98480((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (7));
    r_v0 = (long)func_01D985A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x716c));
    r_a0 = (long)(0 + (0x13));
    r_a2 = (long)(0 + (7));
    r_a1 = (long)(r_v1 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x76b8));
    r_a3 = (long)(r_v1 + r_at);
    r_v0 = (long)func_01D986B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 21: dcomp_func_01D995F8 (VMA: 0x01D995F8, size: 584 bytes) */
void *dcomp_func_01D995F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (32)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_a1 = (long)(0 + (5));
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ef8)); }
    r_a0 = (long)(r_v0 + (-0x101));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9963C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9982C;
_lbl_01D9963C:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_a1 = (long)(0 + (5));
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ef4)); }
    r_a0 = (long)(r_v0 + (-1));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99668;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9982C;
_lbl_01D99668:
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_v0 = (long)(0x1da << 16);
    r_a0 = (long)(0 + (0x12));
    r_v1 = (long)(r_v0 + (0x1d00));
    goto _lbl_01D996A4;
    r_v0 = (long)(r_v1 + r_a0);
_lbl_01D99680:
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_a1 + r_v0);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x716c)); }
    if (r_v0 != 0) { r_s1 = (long)(r_a0 + (1)); goto _lbl_01D996B0; }
    r_s1 = (long)(r_a0 + (1));
    r_a0 = (long)(r_a0 + (-1));
_lbl_01D996A4:
    if ((long)r_a0 >= 0) { r_v0 = (long)(r_v1 + r_a0); goto _lbl_01D99680; }
    r_v0 = (long)(r_v1 + r_a0);
    r_s1 = (long)(r_a0 + (1));
_lbl_01D996B0:
    r_at = (long)((long)r_s1 < (long)(4) ? 1 : 0);
    if (r_at == 0) goto _lbl_01D996C0;
    r_s1 = (long)(0 + (4));
_lbl_01D996C0:
    r_a0 = (long)(r_s1 + (-4));
    r_a1 = (long)(0 + (4));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(0 | 0); goto _lbl_01D996E0; }
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9982C;
    r_s0 = (long)(0 | 0);
_lbl_01D996E0:
    r_v0 = (long)((long)r_s0 < (long)r_s1 ? 1 : 0);
    goto _lbl_01D99730;
_lbl_01D996E8:
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x1d00));
    r_v1 = (long)(r_v1 + r_s0);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x716c)); }
    r_a1 = (long)(0 + (3));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01D9972C; }
    r_s0 = (long)(r_s0 + (1));
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9982C;
    r_s0 = (long)(r_s0 + (1));
_lbl_01D9972C:
    r_v0 = (long)((long)r_s0 < (long)r_s1 ? 1 : 0);
_lbl_01D99730:
    if (r_v0 != 0) goto _lbl_01D996E8;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x7c04));
    r_s0 = (long)(r_v0 + r_at);
    goto _lbl_01D9980C;
_lbl_01D9974C:
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_s1 << (2));
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x76b8)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x716c)); }
    r_s0 = (long)(r_s0 + (4));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)(0 + (0x10)); goto _lbl_01D9978C; }
    r_v0 = (long)(0 + (0x10));
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9982C;
    r_v0 = (long)(0 + (0x10));
_lbl_01D9978C:
    if (r_s1 != r_v0) { r_v0 = (long)(0 + (0x11)); goto _lbl_01D997B8; }
    r_v0 = (long)(0 + (0x11));
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0)); }
    r_a1 = (long)(0 + (2));
    r_s0 = (long)(r_s0 + (4));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9980C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9982C;
    r_v0 = (long)(0 + (0x11));
_lbl_01D997B8:
    if (r_s1 != r_v0) { r_v0 = (long)(0 + (0x12)); goto _lbl_01D997E4; }
    r_v0 = (long)(0 + (0x12));
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0)); }
    r_a1 = (long)(0 + (3));
    r_s0 = (long)(r_s0 + (4));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9980C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9982C;
    r_v0 = (long)(0 + (0x12));
_lbl_01D997E4:
    if (r_s1 != r_v0) goto _lbl_01D9980C;
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0)); }
    r_a1 = (long)(0 + (7));
    r_s0 = (long)(r_s0 + (4));
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9980C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9982C;
_lbl_01D9980C:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7efc)); }
    r_v0 = (long)((unsigned long)r_s0 < (unsigned long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01D9974C;
    r_v0 = (long)(0 | 0);
_lbl_01D9982C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (32)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 22: dcomp_func_01D99840 (VMA: 0x01D99840, size: 704 bytes) */
void *dcomp_func_01D99840(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(2 << 16);
    r_at = (long)(r_at | (0xd102));
    r_a2 = (long)(0 + (0x120));
    r_a1 = (long)(0 | 0);
    r_a3 = (long)(r_v0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x610c));
    r_t2 = (long)(r_v0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6720));
    r_a0 = (long)(r_v0 + r_at);
    r_t0 = (long)(0 | 0);
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6ba0));
    r_a2 = (long)(0 + (0x20));
    r_a0 = (long)(r_v0 + r_at);
    r_v0 = (long)func_01D98080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x1d20));
    r_v0 = (long)(0x1da << 16);
    r_at = (long)(r_a1 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (0x6108)); }
    r_a2 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2120));
    r_t4 = (long)(r_a2 + (0x2720));
    r_a0 = (long)(0x8000 << 16);
    goto _lbl_01D999EC;
_lbl_01D998C8:
    if (r_t0 != 0) { r_a2 = (long)(r_t1 & r_a0); goto _lbl_01D998E0; }
    r_a2 = (long)(r_t1 & r_a0);
    if (r_t2) { r_t1 = *(int *)((char *)r_t2 + (0)); }
    r_t0 = (long)(0 + (0x20));
    r_t2 = (long)(r_t2 + (4));
    r_a2 = (long)(r_t1 & r_a0);
_lbl_01D998E0:
    if (r_a2 == 0) goto _lbl_01D999B0;
    if (r_a3) { r_t3 = *(unsigned char *)((char *)r_a3 + (0)); }
    if (r_a3) { r_t5 = *(unsigned char *)((char *)r_a3 + (2)); }
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    if (r_a3) { r_t6 = *(unsigned char *)((char *)r_a3 + (1)); }
    r_t3 = (long)((unsigned long)r_t3 << (1));
    r_t3 = (long)(r_v1 + r_t3);
    if (r_t3) { r_t3 = *(unsigned short *)((char *)r_t3 + (0)); }
    r_t5 = (long)((unsigned long)r_t5 << (8));
    r_t5 = (long)(r_t6 + r_t5);
    r_t5 = (long)(r_t5 + (-1));
    r_t3 = (long)((unsigned long)r_t3 << (2));
    r_t3 = (long)(r_a2 + r_t3);
    r_at = (long)(r_t3 + r_at);
    if (r_at) { r_a2 = *(int *)((char *)r_at + (0x6720)); }
    r_at = (long)(3 << 16);
    r_a2 = (long)(r_a2 + (1));
    r_at = (long)(r_t3 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6720)) = (int)r_a2; }
    r_at = (long)((unsigned long)r_t5 < (unsigned long)(0x200) ? 1 : 0);
    if (r_at == 0) { r_a2 = (long)((unsigned long)r_t5 >> (8)); goto _lbl_01D99978; }
    r_a2 = (long)((unsigned long)r_t5 >> (8));
    r_t3 = (long)(r_v0 + r_t5);
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_t3) { r_t3 = *(unsigned char *)((char *)r_t3 + (0)); }
    r_at = (long)(3 << 16);
    r_t3 = (long)((unsigned long)r_t3 << (2));
    r_t3 = (long)(r_a2 + r_t3);
    r_at = (long)(r_t3 + r_at);
    if (r_at) { r_a2 = *(int *)((char *)r_at + (0x6ba0)); }
    r_at = (long)(3 << 16);
    r_a2 = (long)(r_a2 + (1));
    r_at = (long)(r_t3 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6ba0)) = (int)r_a2; }
    goto _lbl_01D999A8;
    r_a2 = (long)((unsigned long)r_t5 >> (8));
_lbl_01D99978:
    r_t3 = (long)(r_t4 + r_a2);
    if (r_t3) { r_t3 = *(unsigned char *)((char *)r_t3 + (0)); }
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_t3 = (long)((unsigned long)r_t3 << (2));
    r_t3 = (long)(r_a2 + r_t3);
    r_at = (long)(r_t3 + r_at);
    if (r_at) { r_a2 = *(int *)((char *)r_at + (0x6ba0)); }
    r_at = (long)(3 << 16);
    r_a2 = (long)(r_a2 + (1));
    r_at = (long)(r_t3 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6ba0)) = (int)r_a2; }
_lbl_01D999A8:
    r_a3 = (long)(r_a3 + (3));
    goto _lbl_01D999E0;
_lbl_01D999B0:
    if (r_a3) { r_t3 = *(unsigned char *)((char *)r_a3 + (0)); }
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_t3 = (long)((unsigned long)r_t3 << (2));
    r_t3 = (long)(r_a2 + r_t3);
    r_at = (long)(r_t3 + r_at);
    if (r_at) { r_a2 = *(int *)((char *)r_at + (0x6720)); }
    r_a3 = (long)(r_a3 + (1));
    r_at = (long)(3 << 16);
    r_a2 = (long)(r_a2 + (1));
    r_at = (long)(r_t3 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6720)) = (int)r_a2; }
_lbl_01D999E0:
    r_t0 = (long)(r_t0 + (-1));
    r_a1 = (long)(r_a1 + (-1));
    r_t1 = (long)((unsigned long)r_t1 << (1));
_lbl_01D999EC:
    if ((long)r_a1 > 0) goto _lbl_01D998C8;
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_a0 = (long)(0 + (0x120));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6b20)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6b20)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6720));
    r_a1 = (long)(r_v0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c6c));
    r_a2 = (long)(r_v0 + r_at);
    r_v0 = (long)func_01D98280((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c6c));
    r_a0 = (long)(0 + (0x120));
    r_a1 = (long)(r_v0 + r_at);
    r_v0 = (long)func_01D98480((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xf));
    r_v0 = (long)func_01D985A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6c6c));
    r_a0 = (long)(0 + (0x120));
    r_a2 = (long)(0 + (0xf));
    r_a1 = (long)(r_v0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x71b8));
    r_a3 = (long)(r_v0 + r_at);
    r_v0 = (long)func_01D986B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x6ba0));
    r_a0 = (long)(0 + (0x20));
    r_a1 = (long)(r_v0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x70ec));
    r_a2 = (long)(r_v0 + r_at);
    r_v0 = (long)func_01D98280((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x70ec));
    r_a0 = (long)(0 + (0x20));
    r_a1 = (long)(r_v0 + r_at);
    r_v0 = (long)func_01D98480((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xf));
    r_v0 = (long)func_01D985A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x70ec));
    r_a0 = (long)(0 + (0x20));
    r_a2 = (long)(0 + (0xf));
    r_a1 = (long)(r_v0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x7638));
    r_a3 = (long)(r_v0 + r_at);
    r_v0 = (long)func_01D986B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99310((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 23: dcomp_func_01D99B00 (VMA: 0x01D99B00, size: 68 bytes) */
void *dcomp_func_01D99B00(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)(0 + (2));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    r_a1 = (long)(r_a0 | 0);
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99B24;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D99B38;
_lbl_01D99B24:
    r_v0 = (long)func_01D99680((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 == 0) r_v1 = 0;
    r_v0 = (long)(r_v1 | 0);
_lbl_01D99B38:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 24: dcomp_func_01D99B44 (VMA: 0x01D99B44, size: 600 bytes) */
void *dcomp_func_01D99B44(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (32)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_s1; }
    r_a1 = (long)(0 + (2));
    r_a0 = (long)(0 | 0);
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99B7C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D99D88;
_lbl_01D99B7C:
    r_v0 = (long)func_01D98AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99BB4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D99D88;
_lbl_01D99B94:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99BB4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D99D88;
_lbl_01D99BB4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D99B94; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v1 = *(unsigned char *)((char *)r_at + (0x671c)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_v0; }
    goto _lbl_01D99C0C;
_lbl_01D99BEC:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99C0C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D99D88;
_lbl_01D99C0C:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D99BEC; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x671c)); }
    r_v1 = (long)((long)r_v1 >> (8));
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_v0; }
    goto _lbl_01D99C68;
_lbl_01D99C48:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99C68;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D99D88;
_lbl_01D99C68:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D99C48; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v1 = *(unsigned char *)((char *)r_at + (0x671c)); }
    /* unhandled: not $v1 $v1 */
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_v0; }
    goto _lbl_01D99CC4;
_lbl_01D99CA4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99CC4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D99D88;
_lbl_01D99CC4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D99CA4; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x671c)); }
    /* unhandled: not $v1 $v1 */
    r_v1 = (long)((long)r_v1 >> (8));
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_v0; }
    if (r_at) { r_s1 = *(int *)((char *)r_at + (0x6714)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_s0 = *(int *)((char *)r_at + (0x671c)); }
    goto _lbl_01D99D7C;
_lbl_01D99D20:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99D40;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D99D88;
_lbl_01D99D40:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_v0 = (long)(r_v0 + (-1));
    if ((long)r_v0 < 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; } goto _lbl_01D99D20; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_s0 = (long)(r_s0 + (-1));
    r_v1 = (long)(r_v1 + r_s1);
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (0)); }
    r_s1 = (long)(r_s1 + (1));
    r_s1 = (long)(r_s1 & (0x7fff));
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_v0; }
_lbl_01D99D7C:
    if ((long)r_s0 > 0) goto _lbl_01D99D40;
    r_v0 = (long)(0 | 0);
_lbl_01D99D88:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (32)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 25: dcomp_func_01D99D9C (VMA: 0x01D99D9C, size: 1196 bytes) */
void *dcomp_func_01D99D9C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (32)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6718)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6108)); }
    if (r_v0 == 0) { r_s1 = (long)(r_a0 | 0); goto _lbl_01D9A150; }
    r_s1 = (long)(r_a0 | 0);
    r_a1 = (long)(0 + (1));
    r_a0 = (long)(0 | 0);
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99E00;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99E00:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ec8)); }
    if (r_v0 != 0) { r_v1 = (long)(0 + (1)); goto _lbl_01D99E54; }
    r_v1 = (long)(0 + (1));
    r_v0 = (long)func_01D99050((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99170((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99E38;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99E38:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A150;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
    r_v1 = (long)(0 + (1));
_lbl_01D99E54:
    if (r_v0 != r_v1) { r_at = (long)(3 << 16); goto _lbl_01D99E98; }
    r_at = (long)(3 << 16);
    r_v0 = (long)func_01D998C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99B80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99E7C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99E7C:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A150;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
    r_at = (long)(3 << 16);
_lbl_01D99E98:
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6108)); }
    r_at = (long)((long)r_v0 < (long)(0x80) ? 1 : 0);
    if (r_at == 0) { r_at = (long)(3 << 16); goto _lbl_01D9A028; }
    r_at = (long)(3 << 16);
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bcc)) = (int)r_v1; }
    if (r_at) { *(int *)((char *)r_at + (-0x7ee4)) = (int)0; }
    r_v0 = (long)func_01D99050((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99170((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99ED8;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99ED8:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99EF0;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99EF0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x811c));
    r_v0 = (long)(r_v0 + r_at);
    if (r_v0) { r_s0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)0; }
    r_v0 = (long)func_01D998C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99B80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99F24;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99F24:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99F3C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99F3C:
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd0)); }
    r_at = (long)(r_a1 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (-0x7ee4)); }
    r_v0 = (long)(r_v0 + (2));
    r_v1 = (long)(r_v0 & (7));
    r_at = (long)(3 << 16);
    r_at = (long)(r_a1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bcc)) = (int)0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_v0 = (long)((unsigned long)r_v0 << (3));
    if (r_v1 == 0) { r_a1 = (long)(r_v0 + (0x22)); goto _lbl_01D99F80; }
    r_a1 = (long)(r_v0 + (0x22));
    r_v0 = (long)(0 + (8));
    r_v0 = (long)(r_v0 - r_v1);
    r_a1 = (long)(r_a1 + r_v0);
_lbl_01D99F80:
    r_at = (long)((unsigned long)r_a1 < (unsigned long)r_s0 ? 1 : 0);
    if (r_at == 0) { r_at = (long)((unsigned long)r_s0 < (unsigned long)r_a0 ? 1 : 0); goto _lbl_01D99FB4; }
    r_at = (long)((unsigned long)r_s0 < (unsigned long)r_a0 ? 1 : 0);
    r_at = (long)((unsigned long)r_a1 < (unsigned long)r_a0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D99FB0;
    r_v0 = (long)func_01D99BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A150;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99FB0:
    r_at = (long)((unsigned long)r_s0 < (unsigned long)r_a0 ? 1 : 0);
_lbl_01D99FB4:
    if (r_at == 0) goto _lbl_01D99FF4;
    r_v0 = (long)func_01D99050((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99170((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D99FDC;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99FDC:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A150;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D99FF4:
    r_v0 = (long)func_01D99B80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A00C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A00C:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A150;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
    r_at = (long)(3 << 16);
_lbl_01D9A028:
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_v0 = (long)((long)r_v0 < (long)(0x3999) ? 1 : 0);
    if (r_v0 != 0) { r_at = (long)(4 << 16); goto _lbl_01D9A078; }
    r_at = (long)(4 << 16);
    r_v0 = (long)func_01D998C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99B80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A05C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A05C:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A150;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
    r_at = (long)(4 << 16);
_lbl_01D9A078:
    r_at = (long)(r_a0 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bcc)) = (int)r_v1; }
    if (r_at) { *(int *)((char *)r_at + (-0x7ee4)) = (int)0; }
    r_v0 = (long)func_01D998C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99B80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A0A0;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A0A0:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A0B8;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A0B8:
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bd0)); }
    r_at = (long)(r_a1 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (-0x7ee4)); }
    r_v0 = (long)(r_v0 + (2));
    r_v1 = (long)(r_v0 & (7));
    r_at = (long)(3 << 16);
    r_at = (long)(r_a1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bcc)) = (int)0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_v0 = (long)((unsigned long)r_v0 << (3));
    if (r_v1 == 0) { r_a1 = (long)(r_v0 + (0x22)); goto _lbl_01D9A0FC; }
    r_a1 = (long)(r_v0 + (0x22));
    r_v0 = (long)(0 + (8));
    r_v0 = (long)(r_v0 - r_v1);
    r_a1 = (long)(r_a1 + r_v0);
_lbl_01D9A0FC:
    r_at = (long)((unsigned long)r_a1 < (unsigned long)r_a0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D9A120;
    r_v0 = (long)func_01D99BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A150;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A120:
    r_v0 = (long)func_01D99B80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A138;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A138:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A150;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A150:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x610c));
    r_v1 = (long)(0 + (0x20));
    r_v0 = (long)(r_a0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x670c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(2 << 16);
    r_at = (long)(r_at | (0xd102));
    r_v0 = (long)(r_v1 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6108)) = (int)0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6718)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_s1 == 0) { if (r_at) { *(int *)((char *)r_at + (0x6714)) = (int)r_v0; } goto _lbl_01D9A230; }
    if (r_at) { *(int *)((char *)r_at + (0x6714)) = (int)r_v0; }
    r_a0 = (long)(0 + (1));
    r_a1 = (long)(r_a0 | 0);
    r_v0 = (long)func_01D98860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A1F8;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A1F8:
    r_v0 = (long)func_01D99050((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D99170((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9A218;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A218:
    r_v0 = (long)func_01D98D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)(0 | 0); goto _lbl_01D9A234; }
    r_v0 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9A234;
_lbl_01D9A230:
    r_v0 = (long)(0 | 0);
_lbl_01D9A234:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (32)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 26: dcomp_func_01D9A248 (VMA: 0x01D9A248, size: 140 bytes) */
void *dcomp_func_01D9A248(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_a0 = (long)(0 + (0x20));
    r_v0 = (long)(0 + (0x3000));
    r_at = (long)(r_a1 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    r_at = (long)(3 << 16);
    r_v1 = (long)(r_v1 + (4));
    r_at = (long)(r_a1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x670c)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_a0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6108)); }
    r_at = (long)(3 << 16);
    r_v1 = (long)(r_v1 + (0x20));
    r_at = (long)(r_a0 + r_at);
    if (r_v1 != r_v0) { if (r_at) { *(int *)((char *)r_at + (0x6108)) = (int)r_v1; } goto _lbl_01D9A2C4; }
    if (r_at) { *(int *)((char *)r_at + (0x6108)) = (int)r_v1; }
    r_a0 = (long)(0 | 0);
    r_v0 = (long)func_01D99E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    goto _lbl_01D9A2CC;
_lbl_01D9A2C4:
    r_v0 = (long)(0 | 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
_lbl_01D9A2CC:
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 27: dcomp_func_01D9A2D4 (VMA: 0x01D9A2D4, size: 2052 bytes) */
void *dcomp_func_01D9A2D4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(0 + (0x20));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6710)); }
    if (r_v1 == r_v0) { r_a0 = (long)(0 + (1)); goto _lbl_01D9A3A4; }
    r_a0 = (long)(0 + (1));
    r_at = (long)(3 << 16);
    r_at = (long)(r_a0 + r_at);
    r_v1 = (long)(r_v0 - r_v1);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6108)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6108)) = (int)r_v0; }
    goto _lbl_01D9A358;
    r_at = (long)(3 << 16);
_lbl_01D9A324:
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
_lbl_01D9A358:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    if (r_v0 != 0) { r_at = (long)(3 << 16); goto _lbl_01D9A324; }
    r_at = (long)(3 << 16);
    r_at = (long)(3 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x670c)); }
    r_v1 = (long)(0 + (0x20));
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (4));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x670c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v1; }
    r_a0 = (long)(0 + (1));
_lbl_01D9A3A4:
    return (void *)0x1D99E20;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (32)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    goto _lbl_01D9AA64;
    r_v0 = (long)(r_v1 & (0x7fff));
_lbl_01D9A3C8:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf0)); }
    r_a0 = (long)((unsigned long)r_v0 << (1));
    r_v0 = (long)(0 | (0xffff));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_v1) { r_v1 = *(unsigned short *)((char *)r_v1 + (0)); }
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (2)); goto _lbl_01D9A4BC; }
    r_v0 = (long)(0 + (2));
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9AA64; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9AA64;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9AAC4;
    r_v0 = (long)(0 + (2));
_lbl_01D9A4BC:
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v0; }
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (0)); }
    r_v0 = (long)func_01D98C80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_s1 = *(int *)((char *)r_gp + (-0x6be4)); }
    if (r_s1 != r_v0) goto _lbl_01D9A5BC;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9AA64; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9AA64;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9AAC4;
_lbl_01D9A5BC:
    if (r_gp) { r_s0 = *(int *)((char *)r_gp + (-0x6be0)); }
    goto _lbl_01D9A724;
_lbl_01D9A5C4:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf0)); }
    r_v0 = (long)(0 | (0xffff));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_a0 = (long)(r_a0 + (1));
    r_a1 = (long)(r_a0 & (0x7fff));
    r_a1 = (long)((unsigned long)r_a1 << (1));
    r_v1 = (long)(r_v1 + r_a1);
    if (r_v1) { r_v1 = *(unsigned short *)((char *)r_v1 + (0)); }
    if (r_v1 == r_v0) goto _lbl_01D9A730;
    r_v0 = (long)func_01D98C80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D9A628;
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v0; }
_lbl_01D9A628:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D9A730;
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_gp) { r_s0 = *(int *)((char *)r_gp + (-0x6be0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_s1 = (long)(r_v0 | 0);
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9A724; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)((long)r_s1 < (long)(0x80) ? 1 : 0); goto _lbl_01D9A728; }
    r_v0 = (long)((long)r_s1 < (long)(0x80) ? 1 : 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9AAC4;
_lbl_01D9A724:
    r_v0 = (long)((long)r_s1 < (long)(0x80) ? 1 : 0);
_lbl_01D9A728:
    if (r_v0 != 0) goto _lbl_01D9A5C4;
_lbl_01D9A730:
    if (r_gp) { r_a3 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a3 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)((long)r_v0 < (long)r_s1 ? 1 : 0);
    if (r_at == 0) { r_at = (long)(3 << 16); goto _lbl_01D9A840; }
    r_at = (long)(3 << 16);
    r_at = (long)((long)r_v0 < (long)(3) ? 1 : 0);
    if (r_at == 0) { r_s1 = (long)(r_v0 | 0); goto _lbl_01D9A83C; }
    r_s1 = (long)(r_v0 | 0);
    r_at = (long)(4 << 16);
    r_at = (long)(r_a3 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a3 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9AA64; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9AA64;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9AAC4;
_lbl_01D9A83C:
    r_at = (long)(3 << 16);
_lbl_01D9A840:
    r_at = (long)(r_at | (0x8120));
    r_a0 = (long)(r_a3 + r_at);
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0)); }
    r_v0 = (long)(0 + (3));
    r_v1 = (long)(r_a1 - r_s0);
    if (r_s1 != r_v0) { r_a2 = (long)(r_v1 & (0x7fff)); goto _lbl_01D9A938; }
    r_a2 = (long)(r_v1 & (0x7fff));
    r_v0 = (long)((long)r_a2 < (long)(0x4000) ? 1 : 0);
    if (r_v0 != 0) { r_at = (long)(3 << 16); goto _lbl_01D9A93C; }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a1 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_a0 + r_at);
    r_v0 = (long)(r_v0 + r_a1);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9AA64; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9AA64;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9AAC4;
_lbl_01D9A938:
    r_at = (long)(3 << 16);
_lbl_01D9A93C:
    r_at = (long)(r_a3 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x6104)); }
    r_a1 = (long)(r_s1 + (-3));
    r_v1 = (long)((long)r_a2 >> (8));
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a0 + (1));
    r_at = (long)(r_a3 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)r_a1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_a2; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    if (r_v0) { *(char *)((char *)r_v0 + (1)) = (char)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (2));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + r_s1);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    r_v0 = (long)(r_v0 - r_s1);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_s1);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    r_v0 = (long)(r_v0 | (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9AA64; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9AA64;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9AAC4;
_lbl_01D9AA64:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    if (r_v0 == 0) { r_at = (long)(4 << 16); goto _lbl_01D9AAA8; }
    r_at = (long)(4 << 16);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x8120));
    r_a1 = (long)(r_a0 + r_at);
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ed8)); }
    r_v0 = (long)((unsigned long)r_v1 < (unsigned long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(r_v1 & (0x7fff)); goto _lbl_01D9A3C8; }
    r_v0 = (long)(r_v1 & (0x7fff));
    r_at = (long)(4 << 16);
_lbl_01D9AAA8:
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_v0 = (long)(0 | 0);
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    r_v1 = (long)(r_v1 & (0x7fff));
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v1; }
_lbl_01D9AAC4:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (32)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 28: dcomp_func_01D9AAD8 (VMA: 0x01D9AAD8, size: 1476 bytes) */
void *dcomp_func_01D9AAD8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    goto _lbl_01D9B030;
    r_v0 = (long)(r_v1 & (0x7fff));
_lbl_01D9AAF0:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf0)); }
    r_a0 = (long)((unsigned long)r_v0 << (1));
    r_v0 = (long)(0 | (0xffff));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_v1) { r_v1 = *(unsigned short *)((char *)r_v1 + (0)); }
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (2)); goto _lbl_01D9ABE4; }
    r_v0 = (long)(0 + (2));
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B030; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B030;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B090;
    r_v0 = (long)(0 + (2));
_lbl_01D9ABE4:
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v0; }
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (0)); }
    r_v0 = (long)func_01D98C80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6be4)); }
    if (r_v1 != r_v0) goto _lbl_01D9ACE4;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B030; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B030;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B090;
_lbl_01D9ACE4:
    if (r_gp) { r_a3 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a3 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) { r_at = (long)(3 << 16); goto _lbl_01D9ADF4; }
    r_at = (long)(3 << 16);
    r_at = (long)((long)r_v0 < (long)(3) ? 1 : 0);
    if (r_at == 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v0; } goto _lbl_01D9ADF0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v0; }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a3 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a3 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B030; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B030;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B090;
_lbl_01D9ADF0:
    r_at = (long)(3 << 16);
_lbl_01D9ADF4:
    r_at = (long)(r_at | (0x8120));
    r_t0 = (long)(r_a3 + r_at);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6be0)); }
    if (r_t0) { r_a1 = *(int *)((char *)r_t0 + (0)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_v0 = (long)(0 + (3));
    r_a0 = (long)(r_a1 - r_a0);
    if (r_v1 != r_v0) { r_a2 = (long)(r_a0 & (0x7fff)); goto _lbl_01D9AEF4; }
    r_a2 = (long)(r_a0 & (0x7fff));
    r_v0 = (long)((long)r_a2 < (long)(0x4000) ? 1 : 0);
    if (r_v0 != 0) { r_at = (long)(3 << 16); goto _lbl_01D9AEF8; }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a1 + (1));
    if (r_t0) { *(int *)((char *)r_t0 + (0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_a0 + r_at);
    r_v0 = (long)(r_v0 + r_a1);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B030; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B030;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B090;
_lbl_01D9AEF4:
    r_at = (long)(3 << 16);
_lbl_01D9AEF8:
    r_at = (long)(r_a3 + r_at);
    if (r_gp) { r_v0 = *(unsigned char *)((char *)r_gp + (-0x6be4)); }
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x6104)); }
    r_v1 = (long)((long)r_a2 >> (8));
    r_a1 = (long)(r_v0 + (-3));
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a0 + (1));
    r_at = (long)(r_a3 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)r_a1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_a2; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    if (r_v0) { *(char *)((char *)r_v0 + (1)) = (char)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (2));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    r_v0 = (long)(r_v1 - r_v0);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    r_v0 = (long)(r_v0 | (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B030; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B030;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B090;
_lbl_01D9B030:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    if (r_v0 == 0) { r_at = (long)(4 << 16); goto _lbl_01D9B074; }
    r_at = (long)(4 << 16);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x8120));
    r_a1 = (long)(r_a0 + r_at);
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ed8)); }
    r_v0 = (long)((unsigned long)r_v1 < (unsigned long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(r_v1 & (0x7fff)); goto _lbl_01D9AAF0; }
    r_v0 = (long)(r_v1 & (0x7fff));
    r_at = (long)(4 << 16);
_lbl_01D9B074:
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_v0 = (long)(0 | 0);
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    r_v1 = (long)(r_v1 & (0x7fff));
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v1; }
_lbl_01D9B090:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 29: dcomp_func_01D9B09C (VMA: 0x01D9B09C, size: 1704 bytes) */
void *dcomp_func_01D9B09C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    goto _lbl_01D9B6D4;
    r_v0 = (long)(r_v1 & (0x7fff));
_lbl_01D9B0B0:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf0)); }
    r_a1 = (long)((unsigned long)r_v0 << (1));
    r_v0 = (long)(0 | (0xffff));
    r_v1 = (long)(r_v1 + r_a1);
    if (r_v1) { r_v1 = *(unsigned short *)((char *)r_v1 + (0)); }
    if (r_v1 != r_v0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6be0)) = (int)r_v1; } goto _lbl_01D9B1A0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be0)) = (int)r_v1; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B6D4; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B6D4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B738;
_lbl_01D9B1A0:
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6be0)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0)); }
    r_a2 = (long)(r_a1 + r_v1);
    r_v1 = (long)(r_a1 + r_v0);
    if (r_a2) { r_t2 = *(unsigned char *)((char *)r_a2 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) { r_v0 = (long)(r_a2 | 0); goto _lbl_01D9B1D4; }
    r_v0 = (long)(r_a2 | 0);
    if (r_a2) { r_t2 = *(unsigned char *)((char *)r_a2 + (1)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (1)); }
    if (r_t2 == r_t1) { r_t1 = (long)(0 + (0x20)); goto _lbl_01D9B2A8; }
    r_t1 = (long)(0 + (0x20));
_lbl_01D9B1D4:
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a1 + r_v1);
    r_v1 = (long)(r_v1 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B6D4; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B6D4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B738;
    r_t1 = (long)(0 + (0x20));
_lbl_01D9B2A8:
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_t1; }
_lbl_01D9B2AC:
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { r_t2 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) goto _lbl_01D9B37C;
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { r_t2 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) goto _lbl_01D9B37C;
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { r_t2 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) goto _lbl_01D9B37C;
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { r_t2 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) goto _lbl_01D9B37C;
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { r_t2 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) goto _lbl_01D9B37C;
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { r_t2 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) goto _lbl_01D9B37C;
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { r_t2 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) goto _lbl_01D9B37C;
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { r_t2 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_t2 != r_t1) goto _lbl_01D9B37C;
    if (r_gp) { r_t1 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_t1 = (long)(r_t1 + (-1));
    if ((long)r_t1 > 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_t1; } goto _lbl_01D9B2AC; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_t1; }
_lbl_01D9B37C:
    if (r_gp) { r_t1 = *(int *)((char *)r_gp + (-0x6be4)); }
    if (r_t1 != 0) goto _lbl_01D9B394;
    r_v0 = (long)(0 + (0x102));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v0; }
    goto _lbl_01D9B3B4;
_lbl_01D9B394:
    if (r_v1) { r_t1 = *(unsigned char *)((char *)r_v1 + (0)); }
    r_v1 = (long)(r_v0 - r_a2);
    if (r_v0) { r_a2 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_v0 = (long)((unsigned long)r_v1 << (1));
    r_v1 = (long)(r_a2 ^ r_t1);
    r_v1 = (long)((unsigned long)r_v1 < (unsigned long)(1) ? 1 : 0);
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v0; }
_lbl_01D9B3B4:
    if (r_a3) { r_v1 = *(int *)((char *)r_a3 + (0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D9B4A4;
    r_at = (long)((long)r_v1 < (long)(3) ? 1 : 0);
    if (r_at == 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v1; } goto _lbl_01D9B4A4; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v1; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a1 + r_v1);
    r_v1 = (long)(r_v1 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B6D4; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B6D4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B738;
_lbl_01D9B4A4:
    if (r_a0) { r_a3 = *(int *)((char *)r_a0 + (0)); }
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x6be0)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_v0 = (long)(0 + (3));
    r_a2 = (long)(r_a3 - r_a2);
    if (r_v1 != r_v0) { r_a2 = (long)(r_a2 & (0x7fff)); goto _lbl_01D9B598; }
    r_a2 = (long)(r_a2 & (0x7fff));
    r_v0 = (long)((long)r_a2 < (long)(0x4000) ? 1 : 0);
    if (r_v0 != 0) { r_at = (long)(3 << 16); goto _lbl_01D9B59C; }
    r_at = (long)(3 << 16);
    r_v1 = (long)(r_a3 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a1 + r_a3);
    if (r_v0) { r_a1 = *(unsigned char *)((char *)r_v0 + (0)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + (1));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B6D4; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B6D4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B738;
_lbl_01D9B598:
    r_at = (long)(3 << 16);
_lbl_01D9B59C:
    r_at = (long)(r_t0 + r_at);
    if (r_gp) { r_v0 = *(unsigned char *)((char *)r_gp + (-0x6be4)); }
    if (r_at) { r_a0 = *(int *)((char *)r_at + (0x6104)); }
    r_v1 = (long)((long)r_a2 >> (8));
    r_a1 = (long)(r_v0 + (-3));
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_a0 + (1));
    r_at = (long)(r_t0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)r_a1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_a2; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    if (r_v0) { *(char *)((char *)r_v0 + (1)) = (char)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6104)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (2));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    r_v0 = (long)(r_v1 - r_v0);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x671c)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x671c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (0x670c)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)((unsigned long)r_v0 << (1));
    r_v0 = (long)(r_v0 | (1));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (0x6710)); }
    r_at = (long)(3 << 16);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(r_v1 + r_at);
    if (r_v0 != 0) { if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; } goto _lbl_01D9B6D4; }
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_v0; }
    r_v0 = (long)func_01D9A2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9B6D4;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9B738;
_lbl_01D9B6D4:
    if (r_gp) { r_t0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x8124));
    r_a3 = (long)(r_t0 + r_at);
    if (r_a3) { r_v0 = *(int *)((char *)r_a3 + (0)); }
    if (r_v0 == 0) { r_at = (long)(4 << 16); goto _lbl_01D9B71C; }
    r_at = (long)(4 << 16);
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x8120));
    r_a0 = (long)(r_t0 + r_at);
    r_at = (long)(4 << 16);
    r_at = (long)(r_t0 + r_at);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0)); }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ed8)); }
    r_v0 = (long)((unsigned long)r_v1 < (unsigned long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(r_v1 & (0x7fff)); goto _lbl_01D9B0B0; }
    r_v0 = (long)(r_v1 & (0x7fff));
    r_at = (long)(4 << 16);
_lbl_01D9B71C:
    r_at = (long)(r_t0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_v0 = (long)(0 | 0);
    r_at = (long)(4 << 16);
    r_at = (long)(r_t0 + r_at);
    r_v1 = (long)(r_v1 & (0x7fff));
    if (r_at) { *(int *)((char *)r_at + (-0x7ee0)) = (int)r_v1; }
_lbl_01D9B738:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 30: dcomp_func_01D9B744 (VMA: 0x01D9B744, size: 112 bytes) */
void *dcomp_func_01D9B744(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ec4)); }
    if (r_v0 == 0) goto _lbl_01D9B7A0;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6be8)); }
    r_at = (long)((long)r_v0 < (long)(4) ? 1 : 0);
    if (r_at == 0) goto _lbl_01D9B790;
    r_v0 = (long)func_01D9B120((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9B798;
_lbl_01D9B790:
    r_v0 = (long)func_01D9AB60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9B798:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    goto _lbl_01D9B7AC;
_lbl_01D9B7A0:
    r_v0 = (long)func_01D9A430((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
_lbl_01D9B7AC:
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 31: dcomp_func_01D9B7B4 (VMA: 0x01D9B7B4, size: 348 bytes) */
void *dcomp_func_01D9B7B4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a1 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7ee0)); }
_lbl_01D9B7D0:
    r_at = (long)(4 << 16);
    r_at = (long)(r_a1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_v1 = (long)(r_a0 - r_v1);
    r_v1 = (long)(r_v1 & (0x7fff));
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(r_a1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ee0)); }
    r_v0 = (long)(r_v0 + r_v1);
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + (0xefd));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ed8)) = (int)r_v0; }
    goto _lbl_01D9B7D0;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_v1 = (long)(0 | (0xffff));
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ed8)) = (int)r_v1; }
    goto _lbl_01D9B7D0;
    r_a2 = (long)(0 | 0);
    r_a1 = (long)(0 | (0xffff));
    r_a0 = (long)(0 | (0x8000));
    goto _lbl_01D9B880;
_lbl_01D9B850:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_a3 = (long)((unsigned long)r_a2 << (1));
    r_at = (long)(2 << 16);
    r_a2 = (long)(r_a2 + (1));
    r_v1 = (long)(r_v1 + r_a3);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(short *)((char *)r_at + (-0x2efe)) = (short)r_a1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(1 << 16);
    r_v1 = (long)(r_v1 + r_a3);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(short *)((char *)r_at + (-0x2efe)) = (short)r_a1; }
_lbl_01D9B880:
    r_v1 = (long)((long)r_a2 < (long)r_a0 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01D9B850;
    r_a2 = (long)(0 | 0);
    r_a1 = (long)(0 | (0xffff));
    goto _lbl_01D9B8B4;
_lbl_01D9B898:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_a0 = (long)((unsigned long)r_a2 << (1));
    r_at = (long)(1 << 16);
    r_a2 = (long)(r_a2 + (1));
    r_v1 = (long)(r_v1 + r_a0);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(short *)((char *)r_at + (-0x6efe)) = (short)r_a1; }
_lbl_01D9B8B4:
    r_v1 = (long)((long)r_a2 < (long)(0x2000) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01D9B898;
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x610c));
    r_a0 = (long)(0 + (0x20));
    r_v1 = (long)(r_a1 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_a1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x670c)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6710)) = (int)r_a0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(2 << 16);
    r_at = (long)(r_at | (0xd102));
    r_v1 = (long)(r_a0 + r_at);
    r_at = (long)(3 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (0x6104)) = (int)r_v1; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 32: dcomp_func_01D9B910 (VMA: 0x01D9B910, size: 360 bytes) */
void *dcomp_func_01D9B910(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_s0 = *(int *)((char *)r_at + (-0x7ea8)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7eb0)); }
    r_v0 = (long)((long)r_s0 < (long)r_v1 ? 1 : 0);
    if (r_v0 == 0) r_s0 = r_v1;
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf8)); }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7eb4)); }
    r_a2 = (long)(r_s0 | 0);
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (-0x7eac)); }
    r_a0 = (long)(r_v1 + r_v0);
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7eac)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + r_s0);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7eac)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ea8)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    r_v0 = (long)(r_v0 - r_s0);
    if (r_at) { *(int *)((char *)r_at + (-0x7ea8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(3 << 16);
    r_at = (long)(r_at | (0x814c));
    r_v1 = (long)(r_v0 + r_at);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + r_s0);
    r_v0 = (long)(r_v0 & (0x7fff));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7eb0)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    r_v0 = (long)(r_v0 - r_s0);
    if (r_at) { *(int *)((char *)r_at + (-0x7eb0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7edc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(r_v0 + r_s0);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)r_v0; }
    r_at = (long)(3 << 16);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(r_at | (0x8150));
    r_a0 = (long)(r_v1 + r_at);
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (0)); }
    if (r_a2 == 0) { r_v0 = (long)(0 + (0x1000)); goto _lbl_01D9BA60; }
    r_v0 = (long)(0 + (0x1000));
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ec0)); }
    if (r_v0 == 0) { r_v0 = (long)(0 + (1)); goto _lbl_01D9BA58; }
    r_v0 = (long)(0 + (1));
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7eb4)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bf8)); }
    r_a1 = (long)(0 | 0);
    r_a0 = (long)(r_v1 + r_v0);
    r_v0 = (long)func_01D980E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01D9BA58:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    goto _lbl_01D9BA6C;
_lbl_01D9BA60:
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
    r_v0 = (long)(0 | 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
_lbl_01D9BA6C:
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 33: dcomp_func_01D9BA78 (VMA: 0x01D9BA78, size: 484 bytes) */
void *dcomp_func_01D9BA78(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
_lbl_01D9BA88:
    r_v0 = (long)func_01D9B990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9BAB8;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ec0)); }
    if (r_v0 != 0) goto _lbl_01D9BAB8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01D9BC50;
_lbl_01D9BAB8:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ebc)); }
    if (r_v0 == 0) goto _lbl_01D9BAE0;
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (-0x7eb8)); }
    r_v0 = (long)func_01D98B00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9BAE0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (-0x7eb8)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a1 = *(int *)((char *)r_at + (-0x7edc)); }
    r_v0 = (long)func_01D98B70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7eb8)); }
    if (r_v0 != 0) goto _lbl_01D9BB28;
    r_a0 = (long)(r_a1 + (8));
    r_a0 = (long)(r_a0 + (0x7ff8));
    r_a2 = (long)(0 + (0x1102));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9BB28:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_a0 = *(int *)((char *)r_at + (-0x7eb8)); }
    r_v0 = (long)func_01D9B840((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9BB4C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9BC50;
_lbl_01D9BB4C:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(0 | (0x8000));
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7eb8)); }
    r_at = (long)(4 << 16);
    r_v1 = (long)(r_v1 + (0x1000));
    r_at = (long)(r_a0 + r_at);
    if (r_v1 != r_v0) { if (r_at) { *(int *)((char *)r_at + (-0x7eb8)) = (int)r_v1; } goto _lbl_01D9BB98; }
    if (r_at) { *(int *)((char *)r_at + (-0x7eb8)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_v1 = (long)(0 + (1));
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7eb8)) = (int)0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ebc)) = (int)r_v1; }
_lbl_01D9BB98:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ec0)); }
    if (r_v0 == 0) { r_at = (long)(4 << 16); goto _lbl_01D9BBC8; }
    r_at = (long)(4 << 16);
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ea8)); }
    if (r_v0 == 0) goto _lbl_01D9BBD4;
    r_at = (long)(4 << 16);
_lbl_01D9BBC8:
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7edc)) = (int)0; }
    goto _lbl_01D9BA88;
_lbl_01D9BBD4:
    r_v0 = (long)func_01D9B8A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9BBEC;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9BC50;
_lbl_01D9BBEC:
    r_v0 = (long)func_01D9A360((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9BC04;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9BC50;
_lbl_01D9BC04:
    r_v0 = (long)func_01D98AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9BC1C;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9BC50;
_lbl_01D9BC1C:
    r_v0 = (long)dcomp_func_01D98110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D9BC34;
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9BC50;
_lbl_01D9BC34:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_v0 = (long)(0xabcd << 16);
    r_at = (long)(4 << 16);
    r_a0 = (long)(r_v0 | (0x1234));
    r_v0 = (long)(0 + (1));
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e88)) = (int)r_a0; }
_lbl_01D9BC50:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 34: dcomp_func_01D9BC5C (VMA: 0x01D9BC5C, size: 500 bytes) */
void *dcomp_func_01D9BC5C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bfc)) = (int)r_a0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    if (r_a0 == 0) { r_v0 = (long)(0 + (2)); goto _lbl_01D9BC98; }
    r_v0 = (long)(0 + (2));
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v1 = *(int *)((char *)r_at + (-0x7e88)); }
    r_v0 = (long)(0x1234 << 16);
    r_v0 = (long)(r_v0 | (0x5678));
    if (r_v1 == r_v0) { r_at = (long)(4 << 16); goto _lbl_01D9BCA4; }
    r_at = (long)(4 << 16);
    r_v0 = (long)(0 + (2));
_lbl_01D9BC98:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    goto _lbl_01D9BE48;
    r_at = (long)(4 << 16);
_lbl_01D9BCA4:
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ea4)) = (int)r_a1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ea0)) = (int)r_a2; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ea4)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7eac)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ea0)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ea8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ec0)) = (int)r_a3; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_at | (0xd102));
    r_v0 = (long)(r_v1 + (0x110a));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bf4)) = (int)r_v0; }
    r_v0 = (long)(r_v1 + (0x510a));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bf0)) = (int)r_v0; }
    r_v0 = (long)(r_v1 + r_at);
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bf8)) = (int)r_v1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bec)) = (int)r_v0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ecc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be8)) = (int)r_v0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ed4)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be4)) = (int)r_v0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ed0)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6be0)) = (int)r_v0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ef0)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd4)) = (int)r_v0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7eec)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd0)) = (int)r_v0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ee8)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bcc)) = (int)r_v0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7e90)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bdc)) = (int)r_v0; }
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7e8c)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bd8)) = (int)r_v0; }
    r_v0 = (long)func_01D9BB00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6be4)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ed4)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6be0)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ed0)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd4)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ef0)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd0)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7eec)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bcc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ee8)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bdc)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e90)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bd8)); }
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e8c)) = (int)r_a0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
_lbl_01D9BE48:
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 35: dcomp_func_01D9BE50 (VMA: 0x01D9BE50, size: 32 bytes) */
void *dcomp_func_01D9BE50(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bfc)) = (int)r_a0; }
    r_v1 = (long)(0xabcd << 16);
    r_a0 = (long)(r_v1 | (0x1234));
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e88)) = (int)r_a0; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 36: dcomp_func_01D9BE70 (VMA: 0x01D9BE70, size: 280 bytes) */
void *dcomp_func_01D9BE70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if ((long)r_a1 > 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x6bfc)) = (int)r_a0; } goto _lbl_01D9BE88; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bfc)) = (int)r_a0; }
    r_v0 = (long)(0 + (1));
    goto _lbl_01D9BE8C;
_lbl_01D9BE88:
    r_v0 = (long)(r_a1 | 0);
_lbl_01D9BE8C:
    r_at = (long)((long)r_v0 < (long)(0x5dd) ? 1 : 0);
    if (r_at != 0) goto _lbl_01D9BEA0;
    r_a1 = (long)(0 + (0x5dc));
    goto _lbl_01D9BEB0;
_lbl_01D9BEA0:
    if ((long)r_a1 > 0) goto _lbl_01D9BEB0;
    r_a1 = (long)(0 + (1));
    goto _lbl_01D9BEB0;
_lbl_01D9BEB0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_v1 = (long)(0 + (0x1000));
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ecc)) = (int)r_a1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ec8)) = (int)r_a2; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ec4)) = (int)r_a3; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e9c)) = (int)r_t0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e98)) = (int)r_t1; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7e9c)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e90)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7e98)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e8c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e94)) = (int)r_t2; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7eb0)) = (int)r_v1; }
    r_v0 = (long)func_01D9B8C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bfc)); }
    r_at = (long)(4 << 16);
    r_v0 = (long)(0x1234 << 16);
    r_a0 = (long)(r_v0 | (0x5678));
    r_v0 = (long)(0 | 0);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7e88)) = (int)r_a0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 37: dcomp_func_01D9BF88 (VMA: 0x01D9BF88, size: 32 bytes) */
void *dcomp_func_01D9BF88(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (0)); }
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_a2; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 38: dcomp_func_01D9BFA8 (VMA: 0x01D9BFA8, size: 32 bytes) */
void *dcomp_func_01D9BFA8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_a2 = *(unsigned char *)((char *)r_a0 + (0)); }
    if (r_a1) { r_v1 = *(signed char *)((char *)r_a1 + (0)); }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)r_v1; }
    if (r_a1) { *(char *)((char *)r_a1 + (0)) = (char)r_a2; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 39: dcomp_func_01D9BFC8 (VMA: 0x01D9BFC8, size: 100 bytes) */
void *dcomp_func_01D9BFC8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 == 0) r_v0 = 0;
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_v0; }
    goto _lbl_01D9C010;
_lbl_01D9BFE8:
    r_v0 = (long)(0x8000 << 16);
    r_v0 = (long)(r_a0 & r_v0);
    r_a3 = (long)(0 + (1));
    if (r_v0 == 0) r_a3 = 0;
    r_v1 = (long)((unsigned long)r_a0 << (1));
    r_v0 = (long)(0 + (-2));
    r_v1 = (long)(r_v1 & r_v0);
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (0)); }
    r_a0 = (long)(r_v1 | r_v0);
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_a3; }
_lbl_01D9C010:
    r_v0 = (long)(r_a1 | 0);
    r_a1 = (long)(r_v0 + (-1));
    if (r_v0 != 0) goto _lbl_01D9BFE8;
    r_v0 = (long)(r_a0 | 0);
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 40: dcomp_func_01D9C02C (VMA: 0x01D9C02C, size: 44 bytes) */
void *dcomp_func_01D9C02C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (0)); }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (1)); }
    if (r_a0) { *(char *)((char *)r_a0 + (1)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (2)); }
    if (r_a0) { *(char *)((char *)r_a0 + (2)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (3)); }
    if (r_a0) { *(char *)((char *)r_a0 + (3)) = (char)r_v1; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 41: dcomp_func_01D9C058 (VMA: 0x01D9C058, size: 48 bytes) */
void *dcomp_func_01D9C058(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (0)); }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (1)); }
    if (r_a0) { *(char *)((char *)r_a0 + (1)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (2)); }
    if (r_a0) { *(char *)((char *)r_a0 + (2)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (3)); }
    if (r_a0) { *(char *)((char *)r_a0 + (3)) = (char)r_v1; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 42: dcomp_func_01D9C088 (VMA: 0x01D9C088, size: 64 bytes) */
void *dcomp_func_01D9C088(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(int *)((char *)r_sp + (0xc)) = (int)r_a1; }
    r_a1 = (long)(r_sp + (0xc));
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (0)); }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (1)); }
    if (r_a0) { *(char *)((char *)r_a0 + (1)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (2)); }
    if (r_a0) { *(char *)((char *)r_a0 + (2)) = (char)r_v1; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (3)); }
    if (r_a0) { *(char *)((char *)r_a0 + (3)) = (char)r_v1; }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 43: dcomp_func_01D9C0C8 (VMA: 0x01D9C0C8, size: 84 bytes) */
void *dcomp_func_01D9C0C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x3fb0));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bb8)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bb8)); }
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 + (0x1000));
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bb8)); }
    r_v1 = (long)(r_v1 + (0x1000));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bb4)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bb4)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bb0)) = (int)r_v1; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 44: dcomp_func_01D9C11C (VMA: 0x01D9C11C, size: 28 bytes) */
void *dcomp_func_01D9C11C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bb8)); }
    if (r_v1 == 0) goto _lbl_01D9C130;
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bb8)) = (int)0; }
_lbl_01D9C130:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 45: dcomp_func_01D9C138 (VMA: 0x01D9C138, size: 88 bytes) */
void *dcomp_func_01D9C138(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bb0)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bb8)); }
    r_at = (long)((unsigned long)r_v1 < (unsigned long)r_a1 ? 1 : 0);
    if (r_at != 0) goto _lbl_01D9C174;
    r_v0 = (long)(0x1da << 16);
    r_a0 = (long)(r_v0 + (0x2c00));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9C180;
_lbl_01D9C174:
    r_v1 = (long)(r_a1 + (-4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bb0)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (-4)) = (int)r_a0; }
_lbl_01D9C180:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 46: dcomp_func_01D9C190 (VMA: 0x01D9C190, size: 88 bytes) */
void *dcomp_func_01D9C190(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x6bb0)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bb4)); }
    r_v1 = (long)((unsigned long)r_a1 < (unsigned long)r_v1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01D9C1C4;
    r_v0 = (long)(0x1da << 16);
    r_a0 = (long)(r_v0 + (0x2c20));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9C1D8;
_lbl_01D9C1C4:
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bb0)); }
    r_v1 = (long)(r_v1 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bb0)) = (int)r_v1; }
_lbl_01D9C1D8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 47: dcomp_func_01D9C1E8 (VMA: 0x01D9C1E8, size: 84 bytes) */
void *dcomp_func_01D9C1E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x6bb0)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bb4)); }
    r_v1 = (long)((unsigned long)r_a0 < (unsigned long)r_v1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01D9C224;
    r_v0 = (long)(0x1da << 16);
    r_a0 = (long)(r_v0 + (0x2c40));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9C22C;
_lbl_01D9C224:
    r_v1 = (long)(r_a0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bb0)) = (int)r_v1; }
_lbl_01D9C22C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 48: dcomp_func_01D9C23C (VMA: 0x01D9C23C, size: 64 bytes) */
void *dcomp_func_01D9C23C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    r_v0 = (long)(0x1da << 16);
    r_a0 = (long)(r_v0 + (0x2c60));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 49: dcomp_func_01D9C27C (VMA: 0x01D9C27C, size: 2520 bytes) */
void *dcomp_func_01D9C27C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x27c));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x11));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
    goto _lbl_01D9C314;
_lbl_01D9C2F8:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9C314:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9C2F8;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x27c));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (8));
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
_lbl_01D9C37C:
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + r_v1);
    r_a0 = (long)(r_sp + (0x1c));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x1c)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (0x1c)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_v0 + r_v1);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x1c)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9C37C;
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v1 + (0x23c));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(r_v1 + (0x27c));
    r_v0 = (long)(r_v0 + (0x7ff8));
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(0 + (0xf));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
_lbl_01D9C46C:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    r_v0 = (long)(r_a0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9C46C;
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (-0x8000));
    r_v0 = (long)(r_v0 + (-0x8000));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9C594;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x27c));
    r_v0 = (long)(r_v0 + (0x7ff8));
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x10));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
_lbl_01D9C528:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77fc)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    r_v0 = (long)(r_a0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9C528;
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 <= 0) goto _lbl_01D9C594;
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    goto _lbl_01D9C9F0;
_lbl_01D9C594:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x23c));
    r_v0 = (long)(r_v0 + (0x7ff8));
    r_v0 = (long)(r_v0 + (-4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (4));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (8));
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9C5F8:
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9C670;
    r_v1 = (long)((unsigned long)r_v1 << (2));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_sp + (0x20));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x20)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (0x20)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x20)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9C670:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9C5F8;
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (0xc));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x100));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
    goto _lbl_01D9C708;
_lbl_01D9C6EC:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9C708:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9C6EC;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (0x10));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)((unsigned long)r_v0 << (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    goto _lbl_01D9C774;
_lbl_01D9C758:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9C774:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9C758;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (8));
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
_lbl_01D9C7C0:
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9C9C4;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (8));
    r_a0 = (long)(r_sp + (0x24));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x24)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (-4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (4));
    r_a0 = (long)(r_sp + (0x28));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x28)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_a0 = (long)(r_gp + (-0x77fc));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
_lbl_01D9C898:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)(r_v1 & (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)((unsigned long)r_v1 >> (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_a1 = (long)(0 + (1));
    r_a2 = (long)(r_gp + (-0x6bc0));
    r_v0 = (long)func_01D9C050((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9C898;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 > 0) goto _lbl_01D9CA40;
    r_v0 = (long)(0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 << r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x100));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (0xc));
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9C95C:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_v1 + r_v0);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9C95C;
_lbl_01D9C9A0:
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9C9C4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9C7C0;
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)0; }
_lbl_01D9C9F0:
    r_a0 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77fc));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9CC44;
_lbl_01D9CA40:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(unsigned char *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (0xc));
    r_a0 = (long)(r_sp + (0x2c));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x2c)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_a0 = (long)(r_gp + (-0x77fc));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9CC18;
_lbl_01D9CAAC:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + (0x10));
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-9));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9CB70;
_lbl_01D9CAE4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    /* unhandled: not $v0 $v0 */
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7807)); }
    r_v0 = (long)(r_v1 & (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)((long)r_v1 >> (1));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7807)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bbc)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a1 = (long)(r_v0 + r_v1);
    r_a0 = (long)(r_gp + (-0x77fc));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v0 == 0) goto _lbl_01D9CB64;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9CAE4;
_lbl_01D9CB64:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9CBD0;
_lbl_01D9CB70:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    /* unhandled: not $v0 $v0 */
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7807)); }
    r_v0 = (long)(r_v1 & (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)((long)r_v1 >> (1));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7807)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bbc)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_v0 + r_v1);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9C9A0;
_lbl_01D9CBD0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_v0 + r_v1);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f0)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    r_v0 = (long)(r_v0 + (-2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9CAE4;
    goto _lbl_01D9CB70;
_lbl_01D9CC18:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f0)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    r_v0 = (long)(r_v0 + (-2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    goto _lbl_01D9CAAC;
_lbl_01D9CC44:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 50: dcomp_func_01D9CC54 (VMA: 0x01D9CC54, size: 316 bytes) */
void *dcomp_func_01D9CC54(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d90));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6ba4)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x234));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x22c));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_sp + (0x18));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x18)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6b98)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x220));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x218));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_sp + (0x1c));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x1c)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 51: dcomp_func_01D9CD90 (VMA: 0x01D9CD90, size: 372 bytes) */
void *dcomp_func_01D9CD90(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2d6c));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2d70));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2d74));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2d78));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2d7c));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2d80));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d94));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bb0)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)((unsigned long)r_v0 >> (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2d68));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x2964));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9CE88:
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)(r_v1 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v1 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v1 != 0) goto _lbl_01D9CE88;
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)(r_v1 + (-4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v1 + (0x2d64));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 52: dcomp_func_01D9CF04 (VMA: 0x01D9CF04, size: 324 bytes) */
void *dcomp_func_01D9CF04(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x5274)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bb0)) = (int)r_v0; }
    r_a1 = (long)(r_v1 + (0x2d64));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d68));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9CF58:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + (-4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9CF58;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d6c));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d70));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d74));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d78));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77fc));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d7c));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d80));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 53: dcomp_func_01D9D048 (VMA: 0x01D9D048, size: 316 bytes) */
void *dcomp_func_01D9D048(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
_lbl_01D9D058:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    if (r_a0 == 0) goto _lbl_01D9D174;
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)(r_a1 & (3));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v1 == 0) goto _lbl_01D9D0B8;
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_a1) { *(char *)((char *)r_a1 + (0)) = (char)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)(r_v1 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v1 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v1; }
    goto _lbl_01D9D058;
_lbl_01D9D0B8:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)((unsigned long)r_v0 >> (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    goto _lbl_01D9D100;
_lbl_01D9D0D8:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C0B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9D100:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9D0D8;
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v1 = (long)(r_v1 & (3));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v1; }
    goto _lbl_01D9D160;
_lbl_01D9D138:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_v1) { r_a0 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_v1) { *(char *)((char *)r_v1 + (0)) = (char)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v1 = (long)(r_v1 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v1; }
_lbl_01D9D160:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v1 = (long)(r_a0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v1; }
    if (r_a0 != 0) goto _lbl_01D9D138;
_lbl_01D9D174:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 54: dcomp_func_01D9D184 (VMA: 0x01D9D184, size: 232 bytes) */
void *dcomp_func_01D9D184(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ddc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9D1CC;
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (2));
    goto _lbl_01D9D25C;
_lbl_01D9D1CC:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x228));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_v1) { r_v0 = *(signed char *)((char *)r_v1 + (0)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x77fb)) = (char)r_v0; }
    r_v0 = (long)(r_v1 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x228));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7ddc)); }
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ddc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
_lbl_01D9D25C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 55: dcomp_func_01D9D26C (VMA: 0x01D9D26C, size: 180 bytes) */
void *dcomp_func_01D9D26C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_a0 == 0) goto _lbl_01D9D304;
    r_v1 = (long)(0 + (-1));
    if (r_a0 == r_v1) goto _lbl_01D9D2A0;
    goto _lbl_01D9D294;
_lbl_01D9D294:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9D310;
_lbl_01D9D2A0:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x5280)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9D2D8;
    if (r_gp) { *(char *)((char *)r_gp + (-0x77fb)) = (char)r_v1; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9D310;
_lbl_01D9D2D8:
    r_v0 = (long)(0 + (1));
    r_at = (long)(1 << 16);
    r_at = (long)(r_a0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x56a8)) = (int)r_v0; }
    r_v0 = (long)func_01D9CCE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9CE10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-4));
    goto _lbl_01D9D310;
_lbl_01D9D304:
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01D9D310:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 56: dcomp_func_01D9D320 (VMA: 0x01D9D320, size: 236 bytes) */
void *dcomp_func_01D9D320(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v1 = (long)(0 + (1));
    if (r_a0 == r_v1) goto _lbl_01D9D3EC;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9D358;
    goto _lbl_01D9D34C;
_lbl_01D9D34C:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9D3F8;
_lbl_01D9D358:
    r_a0 = (long)(r_v1 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9CF90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9D3A8;
_lbl_01D9D37C:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9D3A8:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9D3E0;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9D3E0;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9D3E0;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9D3EC;
    goto _lbl_01D9D37C;
_lbl_01D9D3E0:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9D3F8;
_lbl_01D9D3EC:
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01D9D3F8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 57: dcomp_func_01D9D40C (VMA: 0x01D9D40C, size: 380 bytes) */
void *dcomp_func_01D9D40C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_a1 = (long)(0 + (2));
    if (r_a0 == r_a1) goto _lbl_01D9D528;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9D448;
    goto _lbl_01D9D43C;
_lbl_01D9D43C:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9D574;
_lbl_01D9D448:
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 > 0) goto _lbl_01D9D554;
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_a0 = (long)(r_a1 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9D4E4;
_lbl_01D9D4B8:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9D4E4:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9D51C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9D51C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9D51C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9D528;
    goto _lbl_01D9D4B8;
_lbl_01D9D51C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9D574;
_lbl_01D9D528:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7800)); }
    /* unhandled: negu $v0 $v0 */
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v0 + (8));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
_lbl_01D9D554:
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
_lbl_01D9D574:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 58: dcomp_func_01D9D588 (VMA: 0x01D9D588, size: 316 bytes) */
void *dcomp_func_01D9D588(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_a1 = (long)(0 + (3));
    if (r_a0 == r_a1) goto _lbl_01D9D678;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9D5C8;
    goto _lbl_01D9D5BC;
_lbl_01D9D5BC:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9D6B0;
_lbl_01D9D5C8:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_a0 = (long)(r_a1 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9D634;
_lbl_01D9D608:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9D634:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9D66C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9D66C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9D66C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9D678;
    goto _lbl_01D9D608;
_lbl_01D9D66C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9D6B0;
_lbl_01D9D678:
    r_v0 = (long)(0 + (8));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
_lbl_01D9D6B0:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 59: dcomp_func_01D9D6C4 (VMA: 0x01D9D6C4, size: 1144 bytes) */
void *dcomp_func_01D9D6C4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)(0 + (6));
    if (r_a0 == r_v0) goto _lbl_01D9DAE0;
    r_v0 = (long)(0 + (5));
    if (r_a0 == r_v0) goto _lbl_01D9D974;
    r_a2 = (long)(0 + (4));
    if (r_a0 == r_a2) goto _lbl_01D9D848;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9D720;
    goto _lbl_01D9D714;
_lbl_01D9D714:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9DB28;
_lbl_01D9D720:
    if (r_gp) { r_a1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    r_v1 = (long)(r_a1 + (-8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 > 0) goto _lbl_01D9D89C;
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)((unsigned long)r_v0 << r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)(r_v0 & r_a0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v0 - r_a1);
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 > 0) goto _lbl_01D9D874;
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)((unsigned long)r_a0 >> r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_a0 = (long)(r_a2 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9D804;
_lbl_01D9D7D8:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9D804:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9D83C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9D83C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9D83C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9D848;
    goto _lbl_01D9D7D8;
_lbl_01D9D83C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9DB28;
_lbl_01D9D848:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7800)); }
    /* unhandled: negu $v0 $v0 */
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v0 + (8));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
_lbl_01D9D874:
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9DB28;
_lbl_01D9D89C:
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7808)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7807)) = (char)r_v0; }
    r_a0 = (long)(r_gp + (-0x7800));
    r_a1 = (long)(r_gp + (-0x77ff));
    r_v0 = (long)func_01D9C030((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_a0 = (long)(0 + (5));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9D930;
_lbl_01D9D904:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9D930:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9D968;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9D968;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9D968;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9D974;
    goto _lbl_01D9D904;
_lbl_01D9D968:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9DB28;
_lbl_01D9D974:
    r_v0 = (long)(0 + (8));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_a0 = *(signed char *)((char *)r_gp + (-0x7807)); }
    r_v0 = (long)(r_v0 - r_a0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_a0; }
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7807)) = (char)r_v0; }
    if (r_gp) { r_a0 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7807)); }
    r_v0 = (long)((unsigned long)r_v0 << r_a0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7807)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7807)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7807)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7807)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)(r_v1 & r_v0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7807)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v0 - r_a0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 <= 0) goto _lbl_01D9DA28;
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9DB28;
_lbl_01D9DA28:
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_a0 = (long)(0 + (6));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9DA9C;
_lbl_01D9DA70:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9DA9C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9DAD4;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9DAD4;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9DAD4;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9DAE0;
    goto _lbl_01D9DA70;
_lbl_01D9DAD4:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9DB28;
_lbl_01D9DAE0:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7800)); }
    /* unhandled: negu $v0 $v0 */
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7800)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)((unsigned long)r_v0 >> r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v0 + (8));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
_lbl_01D9DB28:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 60: dcomp_func_01D9DB3C (VMA: 0x01D9DB3C, size: 716 bytes) */
void *dcomp_func_01D9DB3C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)(0 + (8));
    if (r_a0 == r_v0) goto _lbl_01D9DDE4;
    r_a1 = (long)(0 + (7));
    if (r_a0 == r_a1) goto _lbl_01D9DC98;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9DB84;
    goto _lbl_01D9DB78;
_lbl_01D9DB78:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9DDF4;
_lbl_01D9DB84:
    if (r_gp) { r_v0 = *(unsigned char *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_a3 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_a3 + r_v0);
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7440)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_a2; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc0)); }
    r_v0 = (long)(0x8000 << 16);
    r_v0 = (long)(r_v1 & r_v0);
    if (r_v0 != 0) goto _lbl_01D9DC04;
    r_v0 = (long)((unsigned long)r_a0 >> (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)(r_a3 + (0x748));
    r_v0 = (long)(r_v0 + (0x7ff8));
    r_v0 = (long)(r_v0 + r_a2);
    if (r_v0) { r_v0 = *(signed char *)((char *)r_v0 + (0)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (4));
    goto _lbl_01D9DDF4;
_lbl_01D9DC04:
    r_a0 = (long)(r_a1 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D610((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9DC54;
_lbl_01D9DC28:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9DC54:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9DC8C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9DC8C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9DC8C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9DC98;
    goto _lbl_01D9DC28;
_lbl_01D9DC8C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9DDF4;
_lbl_01D9DC98:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    /* unhandled: not $v0 $v0 */
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 < 0) goto _lbl_01D9DD50;
_lbl_01D9DCC8:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)(r_v1 & (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)((unsigned long)r_v1 >> (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x6bbc)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7804)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7040)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc0)); }
    r_v0 = (long)(0x8000 << 16);
    r_v0 = (long)(r_v1 & r_v0);
    if (r_v0 != 0) goto _lbl_01D9DC98;
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_a0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)((unsigned long)r_v0 >> (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9DDF4;
_lbl_01D9DD50:
    r_a0 = (long)(0 + (8));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9DDA0;
_lbl_01D9DD74:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9DDA0:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9DDD8;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9DDD8;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9DDD8;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9DDE4;
    goto _lbl_01D9DD74;
_lbl_01D9DDD8:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9DDF4;
_lbl_01D9DDE4:
    r_v0 = (long)(0 + (7));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    goto _lbl_01D9DCC8;
_lbl_01D9DDF4:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 61: dcomp_func_01D9DE08 (VMA: 0x01D9DE08, size: 720 bytes) */
void *dcomp_func_01D9DE08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)(0 + (0xa));
    if (r_a0 == r_v0) goto _lbl_01D9E0B4;
    r_a1 = (long)(0 + (9));
    if (r_a0 == r_a1) goto _lbl_01D9DF68;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9DE54;
    goto _lbl_01D9DE48;
_lbl_01D9DE48:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9E0C4;
_lbl_01D9DE54:
    if (r_gp) { r_v0 = *(unsigned char *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_a3 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_a3 + r_v0);
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x6640)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_a2; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc0)); }
    r_v0 = (long)(0x8000 << 16);
    r_v0 = (long)(r_v1 & r_v0);
    if (r_v0 != 0) goto _lbl_01D9DED4;
    r_v0 = (long)((unsigned long)r_a0 >> (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)(r_a3 + (0x1948));
    r_v0 = (long)(r_v0 + (0x7ff8));
    r_v0 = (long)(r_v0 + r_a2);
    if (r_v0) { r_v0 = *(signed char *)((char *)r_v0 + (0)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (4));
    goto _lbl_01D9E0C4;
_lbl_01D9DED4:
    r_a0 = (long)(r_a1 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D610((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9DF24;
_lbl_01D9DEF8:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9DF24:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9DF5C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9DF5C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9DF5C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9DF68;
    goto _lbl_01D9DEF8;
_lbl_01D9DF5C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9E0C4;
_lbl_01D9DF68:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    /* unhandled: not $v0 $v0 */
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 < 0) goto _lbl_01D9E020;
_lbl_01D9DF98:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)(r_v1 & (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)((unsigned long)r_v1 >> (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x6bbc)); }
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_gp) { *(char *)((char *)r_gp + (-0x7804)) = (char)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x6240)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bc0)); }
    r_v0 = (long)(0x8000 << 16);
    r_v0 = (long)(r_v1 & r_v0);
    if (r_v0 != 0) goto _lbl_01D9DF68;
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_a0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)((unsigned long)r_v0 >> (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9E0C4;
_lbl_01D9E020:
    r_a0 = (long)(0 + (0xa));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E070;
_lbl_01D9E044:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E070:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E0A8;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E0A8;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E0A8;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9E0B4;
    goto _lbl_01D9E044;
_lbl_01D9E0A8:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9E0C4;
_lbl_01D9E0B4:
    r_v0 = (long)(0 + (7));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    goto _lbl_01D9DF98;
_lbl_01D9E0C4:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 62: dcomp_func_01D9E0D8 (VMA: 0x01D9E0D8, size: 576 bytes) */
void *dcomp_func_01D9E0D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    r_v0 = (long)(0 + (0xb));
    if (r_a0 == r_v0) goto _lbl_01D9E278;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9E114;
    goto _lbl_01D9E108;
_lbl_01D9E108:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9E308;
_lbl_01D9E114:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x208));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x20c));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 - r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v1; }
_lbl_01D9E18C:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x218));
    r_a1 = (long)(r_a1 + (0x7ff8));
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 - r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 <= 0) goto _lbl_01D9E1C8;
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9E1C8:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 - r_a0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7df0)); }
    r_v0 = (long)(r_v0 - r_a0);
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7df0)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x214));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_a1 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9D0D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_a1 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x214));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7df0)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9E2E4;
_lbl_01D9E278:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9E18C;
    r_a0 = (long)(r_gp + (-0x77fc));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_a1 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9E308;
_lbl_01D9E2E4:
    r_v0 = (long)(0 + (2));
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x56a8)) = (int)r_v0; }
    r_v0 = (long)func_01D9CCE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9CE10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-4));
_lbl_01D9E308:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 63: dcomp_func_01D9E318 (VMA: 0x01D9E318, size: 2412 bytes) */
void *dcomp_func_01D9E318(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    goto _lbl_01D9EBB8;
_lbl_01D9E334:
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x218));
    r_a1 = (long)(r_a1 + (0x7ff8));
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 - r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 <= 0) goto _lbl_01D9E36C;
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9E36C:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 - r_a0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7df0)); }
    r_v0 = (long)(r_v0 - r_a0);
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7df0)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x214));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_a1 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9D0D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_a1 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x214));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7df0)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9EB8C;
_lbl_01D9E41C:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9E334;
    r_a0 = (long)(r_gp + (-0x77fc));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_a1 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x2c));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x2c)); }
    r_v0 = (long)(0 + (0x28));
    if (r_v1 == r_v0) goto _lbl_01D9EAEC;
    r_v0 = (long)(0 + (0x27));
    if (r_v1 == r_v0) goto _lbl_01D9EA58;
    r_v0 = (long)(0 + (0x26));
    if (r_v1 == r_v0) goto _lbl_01D9E9C4;
    r_v0 = (long)(0 + (0x25));
    if (r_v1 == r_v0) goto _lbl_01D9E930;
    r_v0 = (long)(0 + (0x24));
    if (r_v1 == r_v0) goto _lbl_01D9E89C;
    r_v0 = (long)(0 + (0x12));
    if (r_v1 == r_v0) goto _lbl_01D9E808;
    r_v0 = (long)(0 + (0x11));
    if (r_v1 == r_v0) goto _lbl_01D9E774;
    r_v0 = (long)(0 + (0x10));
    if (r_v1 == r_v0) goto _lbl_01D9E6E0;
    r_v0 = (long)(0 + (0xf));
    if (r_v1 == r_v0) goto _lbl_01D9E64C;
    r_v0 = (long)(0 + (0xe));
    if (r_v1 == r_v0) goto _lbl_01D9E5B8;
    r_v0 = (long)(0 + (0xd));
    if (r_v1 == r_v0) goto _lbl_01D9E524;
    r_v0 = (long)(0 + (-1));
    if (r_v1 == r_v0) goto _lbl_01D9EB80;
    goto _lbl_01D9EB80;
_lbl_01D9E524:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xd));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E574;
_lbl_01D9E548:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E574:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E5AC;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E5AC;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E5AC;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E548;
_lbl_01D9E5AC:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9E5B8:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xe));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E608;
_lbl_01D9E5DC:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E608:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E640;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E640;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E640;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E5DC;
_lbl_01D9E640:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9E64C:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xf));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E69C;
_lbl_01D9E670:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E69C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E6D4;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E6D4;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E6D4;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E670;
_lbl_01D9E6D4:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9E6E0:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x10));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E730;
_lbl_01D9E704:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E730:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E768;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E768;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E768;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E704;
_lbl_01D9E768:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9E774:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x11));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E7C4;
_lbl_01D9E798:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E7C4:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E7FC;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E7FC;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E7FC;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E798;
_lbl_01D9E7FC:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9E808:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x12));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E858;
_lbl_01D9E82C:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E858:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E890;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E890;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E890;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E82C;
_lbl_01D9E890:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9E89C:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x24));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E8EC;
_lbl_01D9E8C0:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E8EC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E924;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E924;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E924;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E8C0;
_lbl_01D9E924:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9E930:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x25));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9E980;
_lbl_01D9E954:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9E980:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9E9B8;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9E9B8;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9E9B8;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E954;
_lbl_01D9E9B8:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9E9C4:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x26));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9EA14;
_lbl_01D9E9E8:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9EA14:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9EA4C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9EA4C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9EA4C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9E9E8;
_lbl_01D9EA4C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9EA58:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x27));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9EAA8;
_lbl_01D9EA7C:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9EAA8:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9EAE0;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9EAE0;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9EAE0;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9EA7C;
_lbl_01D9EAE0:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9EAEC:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x28));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9EB3C;
_lbl_01D9EB10:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9EB3C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9EB74;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9EB74;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9EB74;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9EB80;
    goto _lbl_01D9EB10;
_lbl_01D9EB74:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9EC70;
_lbl_01D9EB80:
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9EC70;
_lbl_01D9EB8C:
    r_v0 = (long)(0 + (2));
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x56a8)) = (int)r_v0; }
    r_v0 = (long)func_01D9CCE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9CE10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-4));
    goto _lbl_01D9EC70;
_lbl_01D9EBB8:
    r_v1 = (long)(0 + (0xc));
    if (r_a0 == r_v1) goto _lbl_01D9E41C;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9EBE4;
    goto _lbl_01D9EBD8;
_lbl_01D9EBD8:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9EC70;
_lbl_01D9EBE4:
    r_a0 = (long)(r_v1 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9CF90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9EC34;
_lbl_01D9EC08:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9EC34:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9EC6C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9EC6C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9EC6C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9E41C;
    goto _lbl_01D9EC08;
_lbl_01D9EC6C:
    r_v0 = (long)(r_s0 | 0);
_lbl_01D9EC70:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 64: dcomp_func_01D9EC84 (VMA: 0x01D9EC84, size: 3912 bytes) */
void *dcomp_func_01D9EC84(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)(0 + (0x12));
    if (r_a0 == r_v0) goto _lbl_01D9FAC0;
    r_v0 = (long)(0 + (0x11));
    if (r_a0 == r_v0) goto _lbl_01D9F910;
    r_v0 = (long)(0 + (0x10));
    if (r_a0 == r_v0) goto _lbl_01D9F864;
    r_v0 = (long)(0 + (0xf));
    if (r_a0 == r_v0) goto _lbl_01D9F794;
    r_v0 = (long)(0 + (0xe));
    if (r_a0 == r_v0) goto _lbl_01D9F6B4;
    r_v0 = (long)(0 + (0xd));
    if (r_a0 == r_v0) goto _lbl_01D9F5B8;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9ED04;
    goto _lbl_01D9ECF8;
_lbl_01D9ECF8:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01D9FBB8;
_lbl_01D9ED04:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x28e8));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    r_v0 = (long)func_01D9C300((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bbc)); }
    if (r_v0 == 0) goto _lbl_01D9ED3C;
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9FBB8;
_lbl_01D9ED3C:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x2910));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    r_v0 = (long)func_01D9C300((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bbc)); }
    if (r_v0 == 0) goto _lbl_01D9ED74;
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9FBB8;
_lbl_01D9ED74:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x208));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9F524;
_lbl_01D9ED94:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc4)); }
    if (r_v0 == 0) goto _lbl_01D9F4DC;
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x2c));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x2c)); }
    r_v0 = (long)(0 + (0x28));
    if (r_v1 == r_v0) goto _lbl_01D9F43C;
    r_v0 = (long)(0 + (0x27));
    if (r_v1 == r_v0) goto _lbl_01D9F3A8;
    r_v0 = (long)(0 + (0x26));
    if (r_v1 == r_v0) goto _lbl_01D9F314;
    r_v0 = (long)(0 + (0x25));
    if (r_v1 == r_v0) goto _lbl_01D9F280;
    r_v0 = (long)(0 + (0x24));
    if (r_v1 == r_v0) goto _lbl_01D9F1EC;
    r_v0 = (long)(0 + (0x12));
    if (r_v1 == r_v0) goto _lbl_01D9F158;
    r_v0 = (long)(0 + (0x11));
    if (r_v1 == r_v0) goto _lbl_01D9F0C4;
    r_v0 = (long)(0 + (0x10));
    if (r_v1 == r_v0) goto _lbl_01D9F030;
    r_v0 = (long)(0 + (0xf));
    if (r_v1 == r_v0) goto _lbl_01D9EF9C;
    r_v0 = (long)(0 + (0xe));
    if (r_v1 == r_v0) goto _lbl_01D9EF08;
    r_v0 = (long)(0 + (0xd));
    if (r_v1 == r_v0) goto _lbl_01D9EE74;
    r_v0 = (long)(0 + (-1));
    if (r_v1 == r_v0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F4D0;
_lbl_01D9EE74:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xd));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9EEC4;
_lbl_01D9EE98:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9EEC4:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9EEFC;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9EEFC;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9EEFC;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9EE98;
_lbl_01D9EEFC:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9EF08:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xe));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9EF58;
_lbl_01D9EF2C:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9EF58:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9EF90;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9EF90;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9EF90;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9EF2C;
_lbl_01D9EF90:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9EF9C:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xf));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9EFEC;
_lbl_01D9EFC0:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9EFEC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F024;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F024;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F024;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9EFC0;
_lbl_01D9F024:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F030:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x10));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F080;
_lbl_01D9F054:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F080:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F0B8;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F0B8;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F0B8;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F054;
_lbl_01D9F0B8:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F0C4:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x11));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F114;
_lbl_01D9F0E8:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F114:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F14C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F14C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F14C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F0E8;
_lbl_01D9F14C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F158:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x12));
    r_v0 = (long)func_01D9ED10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F1A8;
_lbl_01D9F17C:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F1A8:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F1E0;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F1E0;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F1E0;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F17C;
_lbl_01D9F1E0:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F1EC:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x24));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F23C;
_lbl_01D9F210:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F23C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F274;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F274;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F274;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F210;
_lbl_01D9F274:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F280:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x25));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F2D0;
_lbl_01D9F2A4:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F2D0:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F308;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F308;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F308;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F2A4;
_lbl_01D9F308:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F314:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x26));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F364;
_lbl_01D9F338:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F364:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F39C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F39C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F39C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F338;
_lbl_01D9F39C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F3A8:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x27));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F3F8;
_lbl_01D9F3CC:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F3F8:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F430;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F430;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F430;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F3CC;
_lbl_01D9F430:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F43C:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x28));
    r_v0 = (long)func_01DA1200((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F48C;
_lbl_01D9F460:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F48C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F4C4;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F4C4;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F4C4;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F4D0;
    goto _lbl_01D9F460;
_lbl_01D9F4C4:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F4D0:
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9FBB8;
_lbl_01D9F4DC:
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9FBB8;
_lbl_01D9F4F0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01D9FBB8;
_lbl_01D9F524:
    r_a0 = (long)(0 + (0xd));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9DBC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F574;
_lbl_01D9F548:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F574:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F5AC;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F5AC;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F5AC;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F5B8;
    goto _lbl_01D9F548;
_lbl_01D9F5AC:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F5B8:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7807)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01D9F6D4;
    if (r_gp) { r_v1 = *(unsigned char *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7df8)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_a1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 < 0) goto _lbl_01D9F524;
    r_a0 = (long)(r_v1 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0xe));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9E160((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F670;
_lbl_01D9F644:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F670:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F6A8;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F6A8;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F6A8;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F6B4;
    goto _lbl_01D9F644;
_lbl_01D9F6A8:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F6B4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x208));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9F524;
_lbl_01D9F6D4:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01D9ED94;
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x29c0));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(signed char *)((char *)r_v0 + (-0x404)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0xf));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F750;
_lbl_01D9F724:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F750:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F788;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F788;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F788;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F794;
    goto _lbl_01D9F724;
_lbl_01D9F788:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F794:
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x2a40));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (-0x404)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v1 + (-0x102));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 > 0) goto _lbl_01D9F4F0;
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v1; }
    r_a0 = (long)(0 + (0x10));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9DE90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F820;
_lbl_01D9F7F4:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F820:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F858;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F858;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F858;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F864;
    goto _lbl_01D9F7F4;
_lbl_01D9F858:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F864:
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x2ac0));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(signed char *)((char *)r_v0 + (0)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x11));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9F8CC;
_lbl_01D9F8A0:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9F8CC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9F904;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9F904;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9F904;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9F910;
    goto _lbl_01D9F8A0;
_lbl_01D9F904:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9F910:
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x2b40));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7800));
    r_a1 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 < 0) goto _lbl_01D9FAE0;
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 < 0) goto _lbl_01D9FAE0;
_lbl_01D9F994:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    goto _lbl_01D9F9CC;
_lbl_01D9F9A4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_v0) { r_v1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9F9CC:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9F9A4;
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f0)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7df8)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_a1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 < 0) goto _lbl_01D9F524;
    r_a0 = (long)(r_v1 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x12));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9E160((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9FA7C;
_lbl_01D9FA50:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9FA7C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9FAB4;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9FAB4;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9FAB4;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9FAC0;
    goto _lbl_01D9FA50;
_lbl_01D9FAB4:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D9FBB8;
_lbl_01D9FAC0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x208));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9F524;
_lbl_01D9FAE0:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_a0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_a1 = (long)(r_a0 + (0x20c));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 - r_a0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_a0 - r_v1);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 >= 0) goto _lbl_01D9F994;
    r_v0 = (long)(r_v1 - r_a0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    r_a0 = (long)(r_gp + (-0x7800));
    r_a1 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_a1 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D9FB94;
_lbl_01D9FB6C:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_v0) { r_v1 = *(unsigned char *)((char *)r_v0 + (0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9FB94:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9FB6C;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    goto _lbl_01D9F994;
_lbl_01D9FBB8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 65: dcomp_func_01D9FBCC (VMA: 0x01D9FBCC, size: 2940 bytes) */
void *dcomp_func_01D9FBCC(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)(0 + (0x1a));
    if (r_a0 == r_v0) goto _lbl_01DA053C;
    r_v0 = (long)(0 + (0x19));
    if (r_a0 == r_v0) goto _lbl_01DA0488;
    r_v0 = (long)(0 + (0x18));
    if (r_a0 == r_v0) goto _lbl_01DA03AC;
    r_v0 = (long)(0 + (0x17));
    if (r_a0 == r_v0) goto _lbl_01DA0290;
    r_v0 = (long)(0 + (0x16));
    if (r_a0 == r_v0) goto _lbl_01DA00C8;
    r_v0 = (long)(0 + (0x15));
    if (r_a0 == r_v0) goto _lbl_01D9FFF8;
    r_v0 = (long)(0 + (0x14));
    if (r_a0 == r_v0) goto _lbl_01D9FF00;
    r_v0 = (long)(0 + (0x13));
    if (r_a0 == r_v0) goto _lbl_01D9FE08;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01D9FC5C;
    goto _lbl_01D9FC50;
_lbl_01D9FC50:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01DA0734;
_lbl_01D9FC5C:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x748));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x120));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    goto _lbl_01D9FCAC;
_lbl_01D9FC90:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9FCAC:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9FC90;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x1948));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x20));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    goto _lbl_01D9FCFC;
_lbl_01D9FCE0:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9FCFC:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9FCE0;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x1f14));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x13));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    goto _lbl_01D9FD4C;
_lbl_01D9FD30:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01D9FD4C:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01D9FD30;
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (5));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x13));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9FDC4;
_lbl_01D9FD98:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9FDC4:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9FDFC;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9FDFC;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9FDFC;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9FE08;
    goto _lbl_01D9FD98;
_lbl_01D9FDFC:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0734;
_lbl_01D9FE08:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (0x101));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2c0));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (-0x11e));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 <= 0) goto _lbl_01D9FE64;
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01DA0734;
_lbl_01D9FE64:
    r_v0 = (long)(0 + (5));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x14));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9FEBC;
_lbl_01D9FE90:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9FEBC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9FEF4;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9FEF4;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9FEF4;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9FF00;
    goto _lbl_01D9FE90;
_lbl_01D9FEF4:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0734;
_lbl_01D9FF00:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2c4));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (-0x1e));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 <= 0) goto _lbl_01D9FF5C;
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01DA0734;
_lbl_01D9FF5C:
    r_v0 = (long)(0 + (4));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x15));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01D9FFB4;
_lbl_01D9FF88:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01D9FFB4:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01D9FFEC;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01D9FFEC;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01D9FFEC;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01D9FFF8;
    goto _lbl_01D9FF88;
_lbl_01D9FFEC:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0734;
_lbl_01D9FFF8:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2970));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x1f14));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA002C:
    r_v0 = (long)(0 + (3));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x16));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0084;
_lbl_01DA0058:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0084:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA00BC;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA00BC;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA00BC;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA00C8;
    goto _lbl_01DA0058;
_lbl_01DA00BC:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0734;
_lbl_01DA00C8:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_a0 = (long)(r_v1 + r_v0);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA002C;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x2938));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    r_v0 = (long)func_01D9C300((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bbc)); }
    if (r_v0 == 0) goto _lbl_01DA0168;
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01DA0734;
_lbl_01DA0168:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2c4));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2c0));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_sp + (0x2c));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f0)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x2c)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x23f8));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA01BC:
    if (r_gp) { r_v0 = *(unsigned char *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x60a8)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    r_v1 = (long)(r_v1 + (0x1f14));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_v0) { r_v0 = *(signed char *)((char *)r_v0 + (0)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x17));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D490((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA024C;
_lbl_01DA0220:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA024C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0284;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0284;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0284;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0290;
    goto _lbl_01DA0220;
_lbl_01DA0284:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0734;
_lbl_01DA0290:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)((unsigned long)r_v0 >> (2));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v1 + (-0xf));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 > 0) goto _lbl_01DA02FC;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA01BC;
    goto _lbl_01DA05D0;
_lbl_01DA02FC:
    r_v0 = (long)(r_v1 + (-0x10));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA03D8;
    r_v0 = (long)(0 + (2));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x18));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0368;
_lbl_01DA033C:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0368:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA03A0;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA03A0;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA03A0;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA03AC;
    goto _lbl_01DA033C;
_lbl_01DA03A0:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0734;
_lbl_01DA03AC:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (3));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_a1 = (long)(r_v0 + (-4));
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01DA0554;
_lbl_01DA03D8:
    r_v0 = (long)(r_v1 + (-0x11));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA04A0;
    r_v0 = (long)(0 + (3));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x19));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0444;
_lbl_01DA0418:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0444:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA047C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA047C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA047C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0488;
    goto _lbl_01DA0418;
_lbl_01DA047C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0734;
_lbl_01DA0488:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (3));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    goto _lbl_01DA054C;
_lbl_01DA04A0:
    r_v0 = (long)(0 + (7));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x1a));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA04F8;
_lbl_01DA04CC:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA04F8:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0530;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0530;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0530;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA053C;
    goto _lbl_01DA04CC;
_lbl_01DA0530:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0734;
_lbl_01DA053C:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)(r_v0 + (0xb));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
_lbl_01DA054C:
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
_lbl_01DA0554:
    r_a0 = (long)(r_gp + (-0x7808));
    r_a1 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 < 0) goto _lbl_01DA0720;
_lbl_01DA0584:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA0584;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f0)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA01BC;
_lbl_01DA05D0:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2c0));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v1 + (0x748));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(r_v1 + (0x23f8));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    goto _lbl_01DA064C;
_lbl_01DA0624:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C0B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA064C:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01DA0624;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2c4));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x1948));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    goto _lbl_01DA06E0;
_lbl_01DA06B8:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C0B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA06E0:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01DA06B8;
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0xb));
    goto _lbl_01DA0734;
_lbl_01DA0720:
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
_lbl_01DA0734:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 66: dcomp_func_01DA0748 (VMA: 0x01DA0748, size: 456 bytes) */
void *dcomp_func_01DA0748(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_ra; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x748));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x90));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    r_v0 = (long)(0 + (8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    goto _lbl_01DA07A8;
_lbl_01DA078C:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA07A8:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01DA078C;
    r_v0 = (long)(0 + (0x70));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    r_v0 = (long)(0 + (9));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    goto _lbl_01DA07F0;
_lbl_01DA07D4:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA07F0:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01DA07D4;
    r_v0 = (long)(0 + (0x18));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    r_v0 = (long)(0 + (7));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    goto _lbl_01DA0838;
_lbl_01DA081C:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA0838:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01DA081C;
    r_v0 = (long)(0 + (8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    goto _lbl_01DA087C;
_lbl_01DA0860:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA087C:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01DA0860;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x1948));
    r_v0 = (long)(r_v0 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x20));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    r_v0 = (long)(0 + (5));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    goto _lbl_01DA08D4;
_lbl_01DA08B8:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
_lbl_01DA08D4:
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_v1 != 0) goto _lbl_01DA08B8;
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0xb));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 67: dcomp_func_01DA0910 (VMA: 0x01DA0910, size: 1556 bytes) */
void *dcomp_func_01DA0910(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)(0 + (0x21));
    if (r_a0 == r_v0) goto _lbl_01DA0EF0;
    r_v0 = (long)(0 + (0x20));
    if (r_a0 == r_v0) goto _lbl_01DA0E10;
    r_v0 = (long)(0 + (0x1f));
    if (r_a0 == r_v0) goto _lbl_01DA0D74;
    r_v0 = (long)(0 + (0x1e));
    if (r_a0 == r_v0) goto _lbl_01DA0C60;
    r_v0 = (long)(0 + (0x1d));
    if (r_a0 == r_v0) goto _lbl_01DA0B78;
    r_v0 = (long)(0 + (0x1c));
    if (r_a0 == r_v0) goto _lbl_01DA0ADC;
    r_a1 = (long)(0 + (0x1b));
    if (r_a0 == r_a1) goto _lbl_01DA0A40;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01DA0990;
    goto _lbl_01DA0984;
_lbl_01DA0984:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01DA0F10;
_lbl_01DA0990:
    if (r_gp) { r_v1 = *(signed char *)((char *)r_gp + (-0x77ff)); }
    r_v0 = (long)(r_v1 + (-8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 == 0) goto _lbl_01DA0A40;
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v1; }
    r_a0 = (long)(r_a1 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D490((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA09FC;
_lbl_01DA09D0:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA09FC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0A34;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0A34;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0A34;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0A40;
    goto _lbl_01DA09D0;
_lbl_01DA0A34:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0F10;
_lbl_01DA0A40:
    if (r_gp) { r_v0 = *(unsigned char *)((char *)r_gp + (-0x77fc)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    r_a0 = (long)(0 + (0x1c));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0A98;
_lbl_01DA0A6C:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0A98:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0AD0;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0AD0;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0AD0;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0ADC;
    goto _lbl_01DA0A6C;
_lbl_01DA0AD0:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0F10;
_lbl_01DA0ADC:
    if (r_gp) { r_v0 = *(unsigned char *)((char *)r_gp + (-0x77fb)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    r_a0 = (long)(0 + (0x1d));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0B34;
_lbl_01DA0B08:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0B34:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0B6C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0B6C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0B6C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0B78;
    goto _lbl_01DA0B08;
_lbl_01DA0B6C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0F10;
_lbl_01DA0B78:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77fb)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x7807)) = (char)r_v0; }
    if (r_gp) { r_v0 = *(unsigned short *)((char *)r_gp + (-0x7808)); }
    /* unhandled: not $v0 $v0 */
    if (r_gp) { *(short *)((char *)r_gp + (-0x7808)) = (short)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA0E30;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x208));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    if (r_v0 == 0) goto _lbl_01DA0CC0;
_lbl_01DA0BCC:
    r_a0 = (long)(0 + (0x1e));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0C1C;
_lbl_01DA0BF0:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0C1C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0C54;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0C54;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0C54;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0C60;
    goto _lbl_01DA0BF0;
_lbl_01DA0C54:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0F10;
_lbl_01DA0C60:
    if (r_gp) { r_v1 = *(unsigned char *)((char *)r_gp + (-0x77fb)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_v0) { *(char *)((char *)r_v0 + (0)) = (char)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7df8)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)(r_a1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if ((long)r_v0 >= 0) goto _lbl_01DA0E4C;
_lbl_01DA0CA4:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7800)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA0BCC;
_lbl_01DA0CC0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
    r_a0 = (long)(0 + (0x1f));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0D30;
_lbl_01DA0D04:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0D30:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0D68;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0D68;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0D68;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0D74;
    goto _lbl_01DA0D04;
_lbl_01DA0D68:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0F10;
_lbl_01DA0D74:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77fb)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x77fc)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x20));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0DCC;
_lbl_01DA0DA0:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0DCC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0E04;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0E04;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0E04;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0E10;
    goto _lbl_01DA0DA0;
_lbl_01DA0E04:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0F10;
_lbl_01DA0E10:
    r_v0 = (long)(0 + (8));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01DA0F10;
_lbl_01DA0E30:
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bbc)) = (int)r_v0; }
    r_v0 = (long)func_01D9C270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01DA0F10;
_lbl_01DA0E4C:
    r_a0 = (long)(r_v1 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x21));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9E160((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0EAC;
_lbl_01DA0E80:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0EAC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA0EE4;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA0EE4;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA0EE4;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA0EF0;
    goto _lbl_01DA0E80;
_lbl_01DA0EE4:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA0F10;
_lbl_01DA0EF0:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x208));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01DA0CA4;
_lbl_01DA0F10:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 68: dcomp_func_01DA0F24 (VMA: 0x01DA0F24, size: 600 bytes) */
void *dcomp_func_01DA0F24(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)(0 + (0x23));
    if (r_a0 == r_v0) goto _lbl_01DA10C4;
    r_v1 = (long)(0 + (0x22));
    if (r_a0 == r_v1) goto _lbl_01DA1010;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01DA0F74;
    goto _lbl_01DA0F68;
_lbl_01DA0F68:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01DA1168;
_lbl_01DA0F74:
    r_v0 = (long)(0 + (1));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(r_v1 | 0);
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA0FCC;
_lbl_01DA0FA0:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA0FCC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA1004;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA1004;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA1004;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA1010;
    goto _lbl_01DA0FA0;
_lbl_01DA1004:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA1168;
_lbl_01DA1010:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x2d8c));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (2));
    if (r_gp) { *(char *)((char *)r_gp + (-0x7800)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x23));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA1080;
_lbl_01DA1054:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA1080:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA10B8;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA10B8;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA10B8;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA10C4;
    goto _lbl_01DA1054;
_lbl_01DA10B8:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA1168;
_lbl_01DA10C4:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2bd0));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA112C;
_lbl_01DA1100:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA112C:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA1164;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA1164;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA1164;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA1164;
    goto _lbl_01DA1100;
_lbl_01DA1164:
    r_v0 = (long)(r_s0 | 0);
_lbl_01DA1168:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 69: dcomp_func_01DA117C (VMA: 0x01DA117C, size: 1628 bytes) */
void *dcomp_func_01DA117C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_v0 = (long)(0 + (0x28));
    if (r_a0 == r_v0) goto _lbl_01DA16D4;
    r_v0 = (long)(0 + (0x27));
    if (r_a0 == r_v0) goto _lbl_01DA162C;
    r_v0 = (long)(0 + (0x26));
    if (r_a0 == r_v0) goto _lbl_01DA1568;
    r_v0 = (long)(0 + (0x25));
    if (r_a0 == r_v0) goto _lbl_01DA14CC;
    r_v0 = (long)(0 + (0x24));
    if (r_a0 == r_v0) goto _lbl_01DA1430;
    r_v0 = (long)(0 + (-1));
    if (r_a0 == r_v0) goto _lbl_01DA11E8;
    goto _lbl_01DA11DC;
_lbl_01DA11DC:
    r_v0 = (long)(0 + (-2));
    goto _lbl_01DA17C4;
_lbl_01DA11E8:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x28e8));
    r_v0 = (long)(r_v0 + (0x7ff8));
    r_v1 = (long)(0 + (0x120));
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x2c8));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (4)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x748));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (8)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0xbc8));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0xc)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0xfc8));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0x10)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x2910));
    r_v0 = (long)(r_v0 + (0x7ff8));
    r_v1 = (long)(0 + (0x20));
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x18c8));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (4)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x1948));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (8)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x19c8));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0xc)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x1dc8));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0x10)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v0 + (0x2938));
    r_v0 = (long)(r_v0 + (0x7ff8));
    r_v1 = (long)(0 + (0x13));
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x1ec8));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (4)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x1f14));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (8)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x1f60));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0xc)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v1 = (long)(r_v1 + (0x2360));
    r_v1 = (long)(r_v1 + (0x7ff8));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0x10)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)(r_v1 + (0x7fff));
    r_v0 = (long)(r_v0 + (1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    r_a0 = (long)(r_v1 + (0x20c));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_v0 + (0x210));
    r_a0 = (long)(r_a0 + (0x7ff8));
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a0 = (long)(r_a1 + (0x208));
    r_a0 = (long)(r_a0 + (0x7ff8));
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { *(int *)((char *)r_gp + (-0x77fc)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
    r_a0 = (long)(0 + (0x24));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA13EC;
_lbl_01DA13C0:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA13EC:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA1424;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA1424;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA1424;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA1430;
    goto _lbl_01DA13C0;
_lbl_01DA1424:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA17C4;
_lbl_01DA1430:
    if (r_gp) { r_v0 = *(signed char *)((char *)r_gp + (-0x77fb)); }
    if (r_gp) { *(char *)((char *)r_gp + (-0x77fc)) = (char)r_v0; }
    r_a0 = (long)(0 + (0x25));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9D210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA1488;
_lbl_01DA145C:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA1488:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA14C0;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA14C0;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA14C0;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA14CC;
    goto _lbl_01DA145C;
_lbl_01DA14C0:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA17C4;
_lbl_01DA14CC:
    r_v0 = (long)(0 + (8));
    if (r_gp) { *(char *)((char *)r_gp + (-0x77ff)) = (char)r_v0; }
_lbl_01DA14D4:
    r_a0 = (long)(0 + (0x26));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01DA0FB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA1524;
_lbl_01DA14F8:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA1524:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA155C;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA155C;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA155C;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA1568;
    goto _lbl_01DA14F8;
_lbl_01DA155C:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA17C4;
_lbl_01DA1568:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bbc)); }
    if (r_v0 != 0) goto _lbl_01DA1640;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x527c)); }
    r_v0 = (long)(r_v0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bc0)); }
    if (r_v0 != 0) goto _lbl_01DA14D4;
    r_a0 = (long)(0 + (0x27));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9E160((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA15E8;
_lbl_01DA15BC:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA15E8:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA1620;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA1620;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA1620;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA162C;
    goto _lbl_01DA15BC;
_lbl_01DA1620:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA17C4;
_lbl_01DA162C:
    r_v0 = (long)func_01D9CCE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-3));
    goto _lbl_01DA17C4;
_lbl_01DA1640:
    r_a0 = (long)(0 + (0x28));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9E160((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA1690;
_lbl_01DA1664:
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA1690:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA16C8;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA16C8;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA16C8;
    r_a0 = (long)(0 + (-1));
    if (r_s0 == r_a0) goto _lbl_01DA16D4;
    goto _lbl_01DA1664;
_lbl_01DA16C8:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01DA17C4;
_lbl_01DA16D4:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x2d90));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6ba4)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x234));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6b98)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f4)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x220));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_a1 = (long)(r_v0 + (0x218));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_sp + (0x2c));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x2c)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_v0 = (long)func_01D9C110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (-2));
_lbl_01DA17C4:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 70: dcomp_func_01DA17D8 (VMA: 0x01DA17D8, size: 1088 bytes) */
void *dcomp_func_01DA17D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_s7;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0xa0));
    if (r_sp) { *(long *)((char *)r_sp + (128)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (112)) = (long)r_s7; }
    if (r_sp) { *(long *)((char *)r_sp + (96)) = (long)r_s6; }
    if (r_sp) { *(long *)((char *)r_sp + (80)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (64)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (48)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (32)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (16)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0)) = (long)r_s0; }
    r_s5 = (long)(r_a0 | 0);
    r_s4 = (long)(r_a1 | 0);
    r_s3 = (long)(r_a2 | 0);
    r_s2 = (long)(r_a3 | 0);
    r_s1 = (long)(r_t0 | 0);
    r_s0 = (long)(r_t1 | 0);
    r_s6 = (long)(r_t2 | 0);
    r_s7 = (long)(r_t3 | 0);
    r_v0 = (long)func_01D9C150((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bac)) = (int)r_s5; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6ba8)) = (int)r_s4; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6ba4)) = (int)r_s3; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6ba0)) = (int)r_s2; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6b9c)) = (int)r_s1; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6b98)) = (int)r_s0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6b94)) = (int)r_s6; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6b90)) = (int)r_s7; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f0)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bb0)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f0)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7800)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77fc)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x77f4)); }
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6b94)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x77f8)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x5278)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x6bb0)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x5274)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6bac)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7dd8)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6ba8)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7dd0)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6ba4)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7dd4)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7dd8)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    r_a1 = (long)(r_v1 + (0x238));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_sp + (0x98));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x98)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7de0)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7dd4)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7ddc)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6ba0)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7dec)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6b9c)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7de4)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6b98)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_a1 = *(int *)((char *)r_gp + (-0x7808)); }
    r_a0 = (long)(r_gp + (-0x7808));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7de8)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7dec)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    r_a1 = (long)(r_v1 + (0x224));
    r_a1 = (long)(r_a1 + (0x7ff8));
    r_a0 = (long)(r_sp + (0x9c));
    r_v0 = (long)func_01D9C0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x9c)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7df4)) = (int)r_v1; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x7de8)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v1 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x7df0)) = (int)r_v0; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x6b90)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-0x7808)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { *(int *)((char *)r_at + (-0x5280)) = (int)r_v1; }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x77f8)); }
    r_at = (long)(1 << 16);
    r_at = (long)(r_v0 + r_at);
    if (r_at) { r_v0 = *(int *)((char *)r_at + (-0x56a8)); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7804)) = (int)r_v0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v1 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    if (r_a0 != 0) r_v1 = r_v0;
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc4)) = (int)r_v1; }
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7804)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2bb8));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01DA1B30;
_lbl_01DA1B00:
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)func_01D9C1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (-1));
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(0x1da << 16);
    r_v0 = (long)(r_v0 + (0x2920));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_v0 | 0);
_lbl_01DA1B30:
    r_v0 = (long)(0 + (-2));
    if (r_s0 == r_v0) goto _lbl_01DA1BDC;
    r_v0 = (long)(0 + (-3));
    if (r_s0 == r_v0) goto _lbl_01DA1BCC;
    r_v0 = (long)(0 + (-4));
    if (r_s0 == r_v0) goto _lbl_01DA1B68;
    goto _lbl_01DA1B5C;
_lbl_01DA1B5C:
    r_v0 = (long)(0 + (-1));
    if (r_s0 != r_v0) goto _lbl_01DA1B00;
_lbl_01DA1B68:
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x6bc0)) = (int)0; }
_lbl_01DA1B70:
    r_a0 = (long)(r_gp + (-0x77f4));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77f8));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77fc));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7800));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x7804));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_gp + (-0x77f0));
    r_v0 = (long)func_01D9C210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_01D9C1A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7808)); }
    goto _lbl_01DA1BE8;
_lbl_01DA1BCC:
    r_v0 = (long)(0 + (-1));
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    goto _lbl_01DA1B70;
_lbl_01DA1BDC:
    if (r_gp) { *(int *)((char *)r_gp + (-0x7808)) = (int)r_v0; }
    goto _lbl_01DA1B70;
_lbl_01DA1BE8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (128)); }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (112)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (96)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (80)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (64)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (48)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (32)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (16)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0)); }
    r_sp = (long)(r_sp + (0xa0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 71: dcomp_func_01DA1C18 (VMA: 0x01DA1C18, size: 168 bytes) */
void *dcomp_func_01DA1C18(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    /* unhandled: tgeiu $s0 0x708 */
    /* unhandled: tltiu $zero 0x50a */
    /* unhandled: syscall 0x8340c */
    /* unhandled: syscall 0x43004 */
    return (void *)r_v0;
}

/* DCOMP_CD.BIN .rodata section: RMS Data and Tables (3,904 bytes) */
const unsigned int dcomp_data[DCOMP_DATA_WORD_COUNT] = {
#include "dcomp_data.inc"
};
