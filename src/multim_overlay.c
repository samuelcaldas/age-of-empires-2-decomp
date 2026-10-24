/* Age of Empires II PS2 - MULTIMCD.BIN Overlay */
#include "common.h"
#include "multim_overlay.h"

/* External mock prototypes for external calls */
extern void *func_00100670(void *a0, void *a1, void *a2, void *a3);
extern void *func_00100850(void *a0, void *a1, void *a2, void *a3);
extern void *func_00114378(void *a0, void *a1, void *a2, void *a3);
extern void *func_00116F40(void *a0, void *a1, void *a2, void *a3);
extern void *func_00116F68(void *a0, void *a1, void *a2, void *a3);
extern void *func_00117AF8(void *a0, void *a1, void *a2, void *a3);
extern void *func_00117CAC(void *a0, void *a1, void *a2, void *a3);
extern void *func_00118DE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011A498(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011A708(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011AA78(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011ABBC(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011ACD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011AFB8(void *a0, void *a1, void *a2, void *a3);
extern void *func_0017DD90(void *a0, void *a1, void *a2, void *a3);
extern void *func_00185E20(void *a0, void *a1, void *a2, void *a3);
extern void *func_001860D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00186110(void *a0, void *a1, void *a2, void *a3);
extern void *func_001886B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AB8F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AB9D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001ABA00(void *a0, void *a1, void *a2, void *a3);
extern void *func_001ABA70(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F2900(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6EA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F8140(void *a0, void *a1, void *a2, void *a3);
extern void *func_00215910(void *a0, void *a1, void *a2, void *a3);
extern void *func_00215950(void *a0, void *a1, void *a2, void *a3);
extern void *func_002159B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00215A50(void *a0, void *a1, void *a2, void *a3);
extern void *func_00215A80(void *a0, void *a1, void *a2, void *a3);
extern void *func_002254F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002257A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00225820(void *a0, void *a1, void *a2, void *a3);
extern void *func_00225BE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002261C0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025D060(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025DAA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025DE30(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025F140(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025F2B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D98590(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D988A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D988D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D98DE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D98E20(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D991F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D99630(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D99730(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D99810(void *a0, void *a1, void *a2, void *a3);
extern void *func_01D99D30(void *a0, void *a1, void *a2, void *a3);

/* Data and Read-Only Tables (.rodata: 75,712 bytes) */
const unsigned int multim_data[MULTIM_DATA_WORD_COUNT] = {
#include "multim_data.inc"
};

/* Function 1: multim_func_01D98000 (VMA: 0x01D98000, size: 1068 bytes) */
void *multim_func_01D98000(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0, r_t1 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    (void)r_t1;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x50));
    /* unhandled: dpa.w.ph $ac0 $sp $ra */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_sp) { *(int *)((char *)r_sp + (76)) = (int)r_a0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (76)); }
    r_s2 = (long)(r_a1 | 0);
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3f00));
    r_s1 = (long)(r_a2 | 0);
    r_s0 = (long)(r_a3 | 0);
    r_v0 = (long)func_00215910((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0x4e << 16);
    r_v1 = (long)(r_v0 + (0x1f70));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_v1; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (76)); }
    r_v0 = (long)func_01D98590((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_a2 = (long)(0 + (0x190));
    r_v1 = (long)(0 + (1));
    r_a0 = (long)(0 | 0);
    if (r_v0) { *(int *)((char *)r_v0 + (2196)) = (int)r_a2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_a1 = (long)(0 | 0);
    if (r_v0) { *(int *)((char *)r_v0 + (2200)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2080)) = (int)r_v1; }
    r_v0 = (long)func_0017DD90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_at = (long)((long)r_s2 < (long)(9) ? 1 : 0);
    if (r_at != 0) { r_at = (long)((long)r_s1 < (long)(9) ? 1 : 0); goto _lbl_01D98090; }
    r_at = (long)((long)r_s1 < (long)(9) ? 1 : 0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    goto _lbl_01D98414;
    r_at = (long)((long)r_s1 < (long)(9) ? 1 : 0);
_lbl_01D98090:
    if (r_at != 0) { r_at = (long)((long)r_s0 < (long)(2) ? 1 : 0); goto _lbl_01D980A4; }
    r_at = (long)((long)r_s0 < (long)(2) ? 1 : 0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    goto _lbl_01D98414;
    r_at = (long)((long)r_s0 < (long)(2) ? 1 : 0);
_lbl_01D980A4:
    if (r_at != 0) goto _lbl_01D980B4;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    goto _lbl_01D98414;
_lbl_01D980B4:
    if (r_s0 == 0) { r_v0 = (long)(0 + (8)); goto _lbl_01D98134; }
    r_v0 = (long)(0 + (8));
    r_v0 = (long)(0 + (8));
    if (r_s2 != r_v0) goto _lbl_01D980D8;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 + (4));
    if (r_v0) { *(int *)((char *)r_v0 + (2056)) = (int)r_v1; }
    goto _lbl_01D980E4;
_lbl_01D980D8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(r_s2 + (-1));
    if (r_v0) { *(int *)((char *)r_v0 + (2056)) = (int)r_v1; }
_lbl_01D980E4:
    if (r_sp) { r_a2 = *(int *)((char *)r_sp + (76)); }
    r_v0 = (long)(0x1db << 16);
    r_v0 = (long)(r_v0 + (-0x4180));
    r_v1 = (long)((unsigned long)r_s2 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_a2) { r_a1 = *(int *)((char *)r_a2 + (2056)); }
    r_v1 = (long)((unsigned long)r_s1 << (2));
    r_a0 = (long)((unsigned long)r_a1 << (1));
    r_a0 = (long)(r_a0 + r_a1);
    r_a0 = (long)((unsigned long)r_a0 << (1));
    r_a0 = (long)(r_s1 + r_a0);
    r_a0 = (long)(r_a0 + (-1));
    if (r_a2) { *(int *)((char *)r_a2 + (2056)) = (int)r_a0; }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0)); }
    r_v1 = (long)(r_v1 + r_a0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (-4)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2060)) = (int)r_v1; }
    goto _lbl_01D981A0;
    r_v0 = (long)(0 + (8));
_lbl_01D98134:
    if (r_s2 != r_v0) goto _lbl_01D9814C;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 + (4));
    if (r_v0) { *(int *)((char *)r_v0 + (2056)) = (int)r_v1; }
    goto _lbl_01D98158;
_lbl_01D9814C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(r_s2 + (-1));
    if (r_v0) { *(int *)((char *)r_v0 + (2056)) = (int)r_v1; }
_lbl_01D98158:
    if (r_sp) { r_a2 = *(int *)((char *)r_sp + (76)); }
    r_v0 = (long)(0x1db << 16);
    r_v0 = (long)(r_v0 + (-0x40b0));
    r_v1 = (long)((unsigned long)r_s2 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_a2) { r_a1 = *(int *)((char *)r_a2 + (2056)); }
    r_v1 = (long)((unsigned long)r_s1 << (2));
    r_a0 = (long)((unsigned long)r_a1 << (1));
    r_a0 = (long)(r_a0 + r_a1);
    r_a0 = (long)((unsigned long)r_a0 << (1));
    r_a0 = (long)(r_s1 + r_a0);
    r_a0 = (long)(r_a0 + (0xff));
    if (r_a2) { *(int *)((char *)r_a2 + (2056)) = (int)r_a0; }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0)); }
    r_v1 = (long)(r_v1 + r_a0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (-4)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2060)) = (int)r_v1; }
_lbl_01D981A0:
    r_v0 = (long)(0x1db << 16);
    r_v1 = (long)(r_v0 + (-0x4088));
    r_v1 = (long)(r_v1 + r_s2);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (0)); }
    r_a3 = (long)(0 + (-1));
    if (r_v0) { *(int *)((char *)r_v0 + (2064)) = (int)r_v1; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (76)); }
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (2064)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (112)); }
    r_t0 = (long)(0 + (1));
    r_v0 = (long)func_002159B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01D981F0;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    goto _lbl_01D98414;
_lbl_01D981F0:
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    r_a0 = (long)(0 + (-1));
    r_v0 = (long)(0 + (8));
    if (r_s2 == r_v0) { if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_a0; } goto _lbl_01D9827C; }
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_a0; }
    r_v0 = (long)(0 + (4));
    if (r_s2 == r_v0) goto _lbl_01D9826C;
    r_v0 = (long)(0 + (3));
    if (r_s2 == r_v0) goto _lbl_01D9825C;
    r_v0 = (long)(0 + (2));
    if (r_s2 == r_v0) goto _lbl_01D9824C;
    r_v1 = (long)(0 + (1));
    if (r_s2 == r_v1) goto _lbl_01D9823C;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    goto _lbl_01D98290;
_lbl_01D9823C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 | (0xcb20));
    if (r_v0) { *(int *)((char *)r_v0 + (2100)) = (int)r_v1; }
    goto _lbl_01D9829C;
_lbl_01D9824C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 | (0xcb30));
    if (r_v0) { *(int *)((char *)r_v0 + (2100)) = (int)r_v1; }
    goto _lbl_01D9829C;
_lbl_01D9825C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 | (0xcb40));
    if (r_v0) { *(int *)((char *)r_v0 + (2100)) = (int)r_v1; }
    goto _lbl_01D9829C;
_lbl_01D9826C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 | (0xcb50));
    if (r_v0) { *(int *)((char *)r_v0 + (2100)) = (int)r_v1; }
    goto _lbl_01D9829C;
_lbl_01D9827C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 | (0xcb66));
    if (r_v0) { *(int *)((char *)r_v0 + (2100)) = (int)r_v1; }
    goto _lbl_01D9829C;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
_lbl_01D98290:
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    goto _lbl_01D98414;
_lbl_01D9829C:
    r_at = (long)((unsigned long)r_s1 < (unsigned long)(9) ? 1 : 0);
    if (r_at == 0) goto _lbl_01D98358;
    r_v1 = (long)(0x1db << 16);
    r_v1 = (long)(r_v1 + (-0x3ee0));
    r_v0 = (long)((unsigned long)r_s1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    return (void *)r_v0;
    goto _lbl_01D9836C;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    r_v0 = (long)(r_v0 + (2));
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_v0; }
    goto _lbl_01D9836C;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    r_v0 = (long)(r_v0 + (4));
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_v0; }
    goto _lbl_01D9836C;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    r_v0 = (long)(r_v0 + (6));
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_v0; }
    goto _lbl_01D9836C;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    r_v0 = (long)(r_v0 + (8));
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_v0; }
    goto _lbl_01D9836C;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    r_v0 = (long)(r_v0 + (0xa));
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_v0; }
    goto _lbl_01D9836C;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    r_v0 = (long)(r_v0 + (0xc));
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_v0; }
    goto _lbl_01D9836C;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    r_v0 = (long)(r_v0 + (0xe));
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_v0; }
    goto _lbl_01D9836C;
_lbl_01D98358:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    goto _lbl_01D98414;
_lbl_01D9836C:
    if (r_s0 != 0) goto _lbl_01D98384;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (2100)) = (int)r_v0; }
_lbl_01D98384:
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (76)); }
    r_v0 = (long)func_01D99730((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a0 = (long)(0 + (0x14)); goto _lbl_01D983AC; }
    r_a0 = (long)(0 + (0x14));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    goto _lbl_01D98414;
    r_a0 = (long)(0 + (0x14));
_lbl_01D983AC:
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01D983D0; }
    r_s0 = (long)(r_v0 | 0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_a2 = (long)(0 + (-1));
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (2060)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_0025DAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D983D0:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_a1 = (long)(0 + (0x280));
    if (r_v0) { *(int *)((char *)r_v0 + (2124)) = (int)r_s0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (76)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (268)); }
    r_a2 = (long)(0 + (0x1c0));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (2096)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2080)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2228)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (76)); }
_lbl_01D98414:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 2: multim_func_01D9842C (VMA: 0x01D9842C, size: 216 bytes) */
void *multim_func_01D9842C(void *a0, void *a1, void *a2, void *a3) {
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
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s1 = (long)(r_a0 | 0);
    if (r_s1 == 0) { r_s0 = (long)(r_a1 | 0); goto _lbl_01D984EC; }
    r_s0 = (long)(r_a1 | 0);
    r_v0 = (long)(0x4e << 16);
    r_v0 = (long)(r_v0 + (0x1f70));
    if (r_s1) { *(int *)((char *)r_s1 + (0)) = (int)r_v0; }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2124)); }
    if (r_a0 == 0) goto _lbl_01D98470;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (2124)) = (int)0; }
_lbl_01D98470:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2136)); }
    if (r_a0 == 0) { r_v1 = (long)(0 | 0); goto _lbl_01D9848C; }
    r_v1 = (long)(0 | 0);
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (2136)) = (int)0; }
    r_v1 = (long)(0 | 0);
_lbl_01D9848C:
    r_v0 = (long)((long)r_v1 < (long)(0xa) ? 1 : 0);
    goto _lbl_01D984B8;
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01D98498:
    r_v0 = (long)(r_s1 + r_v0);
    r_a0 = (long)(r_v0 + (0x85c));
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (2140)); }
    if (r_v0 == 0) { r_v1 = (long)(r_v1 + (1)); goto _lbl_01D984B4; }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)0; }
    r_v1 = (long)(r_v1 + (1));
_lbl_01D984B4:
    r_v0 = (long)((long)r_v1 < (long)(0xa) ? 1 : 0);
_lbl_01D984B8:
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_v1 << (2)); goto _lbl_01D98498; }
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01D99630((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00215950((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 <= 0) { r_v0 = (long)(r_s1 | 0); goto _lbl_01D984F0; }
    r_v0 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D984EC:
    r_v0 = (long)(r_s1 | 0);
_lbl_01D984F0:
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 3: multim_func_01D98504 (VMA: 0x01D98504, size: 164 bytes) */
void *multim_func_01D98504(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a0) { *(int *)((char *)r_a0 + (2204)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2208)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2212)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2216)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2220)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2224)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2124)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2128)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2132)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2072)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2076)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2128)) = (int)0; }
    r_v1 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (2080)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2088)) = (int)r_v1; }
    r_v1 = (long)(0 + (0x1388));
    if (r_a0) { *(int *)((char *)r_a0 + (2092)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2116)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2120)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2084)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2220)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2224)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2136)) = (int)0; }
    r_a1 = (long)(0 | 0);
    goto _lbl_01D98584;
    r_v1 = (long)((unsigned long)r_a1 << (2));
_lbl_01D98578:
    r_v1 = (long)(r_a0 + r_v1);
    r_a1 = (long)(r_a1 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (2140)) = (int)0; }
_lbl_01D98584:
    r_v1 = (long)((long)r_a1 < (long)(0xa) ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a1 << (2)); goto _lbl_01D98578; }
    r_v1 = (long)((unsigned long)r_a1 << (2));
    r_v1 = (long)(0 + (-1));
    if (r_a0) { *(int *)((char *)r_a0 + (2180)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2184)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2188)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2192)) = (int)r_v1; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 4: multim_func_01D985A8 (VMA: 0x01D985A8, size: 60 bytes) */
void *multim_func_01D985A8(void *a0, void *a1, void *a2, void *a3) {
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
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2080)); }
    if (r_v0 == 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01D985D0; }
    r_s0 = (long)(r_a0 | 0);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_001860D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D985D0:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2080)); }
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 5: multim_func_01D985E4 (VMA: 0x01D985E4, size: 120 bytes) */
void *multim_func_01D985E4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t9;
    return (void *)0x1FBD30;
    return (void *)0x1F5EB0;
    r_sp = (long)(r_sp + (-0x10));
    r_v0 = (long)(0 + (0x1b));
    if (r_a1 != r_v0) { /* unhandled: ext $ra $sp 0 1 */ goto _lbl_01D98628; }
    /* unhandled: ext $ra $sp 0 1 */
    r_v0 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (2080)) = (int)r_v0; }
_lbl_01D98628:
    r_v0 = (long)(0 + (0x20));
    if (r_a1 != r_v0) goto _lbl_01D9864C;
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a1 = (long)(0 + (1));
    r_a2 = (long)(0 | 0);
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (120)); }
    r_a3 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01D9864C:
    /* unhandled: xori.b $w0 $w0 0xbf */
    r_v0 = (long)(0 | 0);
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 6: multim_func_01D9865C (VMA: 0x01D9865C, size: 356 bytes) */
void *multim_func_01D9865C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x20));
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2096)); }
    if (r_v0 == 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01D98704; }
    r_s0 = (long)(r_a0 | 0);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (28)); }
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3eb8));
    r_a2 = (long)(0 + (6));
    r_v0 = (long)func_0011AFB8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01D986A8;
    r_a0 = (long)(r_s0 | 0);
    if (r_s0) { *(int *)((char *)r_s0 + (2096)) = (int)0; }
    r_v0 = (long)func_01D988A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (2096)) = (int)0; }
    goto _lbl_01D98704;
_lbl_01D986A8:
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (28)); }
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3eb0));
    r_a2 = (long)(0 + (0xa));
    r_v0 = (long)func_0011AFB8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a0 = (long)(r_s0 | 0); goto _lbl_01D98708; }
    r_a0 = (long)(r_s0 | 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2220)); }
    if (r_v0 != 0) goto _lbl_01D986D8;
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01D98DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D986D8:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2216)); }
    if (r_v0 == 0) { r_a0 = (long)(r_s0 | 0); goto _lbl_01D986F8; }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)(0 + (1));
    if (r_s0) { *(int *)((char *)r_s0 + (2220)) = (int)r_v0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01D987B0;
    r_a0 = (long)(r_s0 | 0);
_lbl_01D986F8:
    if (r_s0) { *(int *)((char *)r_s0 + (2096)) = (int)0; }
    r_v0 = (long)func_01D988A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (2096)) = (int)0; }
_lbl_01D98704:
    r_a0 = (long)(r_s0 | 0);
_lbl_01D98708:
    r_v0 = (long)func_01D99D30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01D988D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (496)); }
    if (r_v0 != 0) goto _lbl_01D98730;
    r_v0 = (long)func_001886B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D98730:
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (2080)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_a0 = (long)(r_s0 | 0); goto _lbl_01D987A8; }
    r_a0 = (long)(r_s0 | 0);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (28)); }
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3eb8));
    r_a2 = (long)(0 + (6));
    r_v0 = (long)func_0011AFB8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01D987A4;
    r_v0 = (long)(0xa8 << 16);
    r_a0 = (long)(r_v0 + (0xbb0));
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3f00));
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F2900((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2216)); }
    if (r_a0 == 0) { r_v0 = (long)(0 + (1)); goto _lbl_01D98794; }
    r_v0 = (long)(0 + (1));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (8)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (1));
_lbl_01D98794:
    if (r_s0) { *(int *)((char *)r_s0 + (2216)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2224)) = (int)r_v0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01D987B0;
_lbl_01D987A4:
    r_a0 = (long)(r_s0 | 0);
_lbl_01D987A8:
    r_v0 = (long)func_001F8140((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D987B0:
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 7: multim_func_01D987C0 (VMA: 0x01D987C0, size: 76 bytes) */
void *multim_func_01D987C0(void *a0, void *a1, void *a2, void *a3) {
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
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_s0 = *(int *)((char *)r_a0 + (56)); }
    r_v0 = (long)(0 + (2));
    if (r_s0 != r_v0) { r_s1 = (long)(r_a0 | 0); goto _lbl_01D987E8; }
    r_s1 = (long)(r_a0 | 0);
    r_v0 = (long)func_00215A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D987E8:
    r_a0 = (long)(r_s1 | 0);
    if (r_s1) { *(int *)((char *)r_s1 + (56)) = (int)r_s0; }
    r_v0 = (long)func_01D98E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (56)) = (int)0; }
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 8: multim_func_01D9880C (VMA: 0x01D9880C, size: 60 bytes) */
void *multim_func_01D9880C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    return (void *)0x215A60;
    r_sp = (long)(r_sp + (-0x20));
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (2072)) = (int)r_v0; }
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 9: multim_func_01D98848 (VMA: 0x01D98848, size: 1300 bytes) */
void *multim_func_01D98848(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x650));
    /* unhandled: ext $ra $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    r_s3 = (long)(r_a0 | 0);
    r_v1 = (long)(0x1db << 16);
    /* unhandled: addu.qb $zero $sp $s1 */
    r_a2 = (long)(r_v1 + (-0x4070));
    r_a1 = (long)(r_sp + (0x50));
    r_a0 = (long)(0 + (0xf));
    /* unhandled: ext $s0 $sp 0 1 */
_lbl_01D9887C:
    /* unhandled: andi.b $w0 $w0 0xc3 */
    r_a0 = (long)(r_a0 + (-1));
    /* unhandled: ext $v1 $a1 0 1 */
    r_a2 = (long)(r_a2 + (0x10));
    if ((long)r_a0 > 0) { r_a1 = (long)(r_a1 + (0x10)); goto _lbl_01D9887C; }
    r_a1 = (long)(r_a1 + (0x10));
    if (r_s3) { r_s2 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2 == 0) goto _lbl_01D98D40;
    goto _lbl_01D98D38;
_lbl_01D988B0:
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    if (r_a1 == 0) goto _lbl_01D98D30;
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (28)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2076)); }
    r_at = (long)((unsigned long)r_v1 < (unsigned long)r_a0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01D98A9C;
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (8)); }
    if (r_v1 != 0) { r_a3 = (long)(r_a1 + (8)); goto _lbl_01D98A9C; }
    r_a3 = (long)(r_a1 + (8));
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (4)); }
    r_v1 = (long)(0 + (2));
    if (r_a0 == r_v1) goto _lbl_01D989EC;
    r_a2 = (long)(0 + (1));
    if (r_a0 == r_a2) goto _lbl_01D98978;
    if (r_a0 == 0) goto _lbl_01D98908;
    if (r_a3) { *(int *)((char *)r_a3 + (0)) = (int)r_v1; }
    goto _lbl_01D98A9C;
_lbl_01D98908:
    if (r_a3) { *(int *)((char *)r_a3 + (0)) = (int)r_a2; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3ac0));
    if (r_v1) { *(int *)((char *)r_v1 + (52)) = (int)0; }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0)); }
    if (r_s3) { r_t0 = *(int *)((char *)r_s3 + (2076)); }
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_a3 = *(int *)((char *)r_v0 + (28)); }
    if (r_v0) { r_t1 = *(int *)((char *)r_v0 + (12)); }
    if (r_v0) { r_t2 = *(int *)((char *)r_v0 + (16)); }
    r_a0 = (long)(r_sp + (0x150));
    r_v0 = (long)func_0011A498((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x150));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2196)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_a1 = (long)(0 + (2)); goto _lbl_01D98960; }
    r_a1 = (long)(0 + (2));
    r_a1 = (long)(0 + (1));
    goto _lbl_01D98960;
    r_a1 = (long)(0 + (2));
_lbl_01D98960:
    if (r_s3) { r_t9 = *(int *)((char *)r_s3 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s3 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    goto _lbl_01D98AA0;
_lbl_01D98978:
    if (r_a1) { *(int *)((char *)r_a1 + (52)) = (int)0; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3aa0));
    if (r_v1) { *(int *)((char *)r_v1 + (8)) = (int)r_a2; }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0)); }
    if (r_s3) { r_t0 = *(int *)((char *)r_s3 + (2076)); }
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_a3 = *(int *)((char *)r_v0 + (28)); }
    if (r_v0) { r_t1 = *(int *)((char *)r_v0 + (12)); }
    if (r_v0) { r_t2 = *(int *)((char *)r_v0 + (16)); }
    if (r_v0) { r_t3 = *(int *)((char *)r_v0 + (36)); }
    r_a0 = (long)(r_sp + (0x150));
    r_v0 = (long)func_0011A498((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x150));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2196)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_a1 = (long)(0 + (2)); goto _lbl_01D989D4; }
    r_a1 = (long)(0 + (2));
    r_a1 = (long)(0 + (1));
    goto _lbl_01D989D4;
    r_a1 = (long)(0 + (2));
_lbl_01D989D4:
    if (r_s3) { r_t9 = *(int *)((char *)r_s3 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s3 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    goto _lbl_01D98A9C;
_lbl_01D989EC:
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2228)); }
    if (r_v1 != 0) goto _lbl_01D98A9C;
    r_s1 = (long)(0 + (-1));
    r_s0 = (long)(0 | 0);
    goto _lbl_01D98A3C;
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01D98A08:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_v0 = (long)(r_v0 + r_sp);
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (40)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (80)); }
    r_v0 = (long)func_0011AA78((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_v0 = (long)(r_s0 + (1)); goto _lbl_01D98A34; }
    r_v0 = (long)(r_s0 + (1));
    goto _lbl_01D98A50;
    r_v0 = (long)(r_s0 + (1));
_lbl_01D98A34:
_lbl_01D98A3C:
    r_v0 = (long)((long)r_v1 < (long)(0x3e) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_v1 << (2)); goto _lbl_01D98A08; }
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01D98A50:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_v0 = (long)(0x1db << 16);
    r_a0 = (long)(r_sp + (0x550));
    if (r_v1) { r_a2 = *(int *)((char *)r_v1 + (40)); }
    r_a1 = (long)(r_v0 + (-0x3a80));
    r_a3 = (long)(r_s0 | 0);
    r_v0 = (long)func_0011A498((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x550));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_s0 < 0) goto _lbl_01D98A9C;
    r_a0 = (long)(r_s0 + (0x3018));
    r_v0 = (long)func_0025D060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_s3) { *(int *)((char *)r_s3 + (2228)) = (int)r_v1; }
    goto _lbl_01D98A9C;
    if (r_a3) { *(int *)((char *)r_a3 + (0)) = (int)r_v1; }
_lbl_01D98A9C:
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
_lbl_01D98AA0:
    r_a0 = (long)(0 + (2));
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (4)); }
    if (r_v1 != r_a0) goto _lbl_01D98AC4;
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (8)); }
    if (r_v1 != r_a0) goto _lbl_01D98AC4;
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D98AC4:
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (0)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2076)); }
    if (r_a2) { r_a1 = *(int *)((char *)r_a2 + (28)); }
    if (r_a2) { r_a0 = *(int *)((char *)r_a2 + (32)); }
    r_s0 = (long)(r_a1 + r_a0);
    r_at = (long)((unsigned long)r_v1 < (unsigned long)r_s0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01D98C28;
    if (r_a2) { r_a0 = *(int *)((char *)r_a2 + (8)); }
    r_v1 = (long)(0 + (2));
    if (r_a0 == r_v1) { r_a1 = (long)(r_a2 + (8)); goto _lbl_01D98B00; }
    r_a1 = (long)(r_a2 + (8));
    r_v1 = (long)(0 + (1));
    if (r_a0 != r_v1) goto _lbl_01D98C28;
_lbl_01D98B00:
    if (r_a2) { r_a0 = *(int *)((char *)r_a2 + (4)); }
    r_v1 = (long)(0 + (2));
    if (r_a0 == r_v1) goto _lbl_01D98C28;
    r_v1 = (long)(0 + (1));
    if (r_a0 == r_v1) { r_v0 = (long)(0 + (3)); goto _lbl_01D98BA8; }
    if (r_a0 == 0) { r_v0 = (long)(0 + (3)); goto _lbl_01D98B30; }
    r_v1 = (long)(0 + (4));
    goto _lbl_01D98C24;
    r_v0 = (long)(0 + (3));
_lbl_01D98B30:
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v0; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(0 + (0x64));
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3a60));
    if (r_v1) { *(int *)((char *)r_v1 + (52)) = (int)r_a2; }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0)); }
    if (r_s3) { r_t0 = *(int *)((char *)r_s3 + (2076)); }
    r_a0 = (long)(r_sp + (0x150));
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_t1 = *(int *)((char *)r_v0 + (12)); }
    if (r_v0) { r_t2 = *(int *)((char *)r_v0 + (16)); }
    r_a3 = (long)(r_s0 | 0);
    r_v0 = (long)func_0011A498((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x150));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2196)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_a1 = (long)(0 + (2)); goto _lbl_01D98B8C; }
    r_a1 = (long)(0 + (2));
    r_a1 = (long)(0 + (1));
    goto _lbl_01D98B8C;
    r_a1 = (long)(0 + (2));
_lbl_01D98B8C:
    if (r_s3) { r_t9 = *(int *)((char *)r_s3 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s3 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    goto _lbl_01D98C2C;
    r_v0 = (long)(0 + (3));
_lbl_01D98BA8:
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v0; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(0 + (0x64));
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3a40));
    if (r_v1) { *(int *)((char *)r_v1 + (52)) = (int)r_a2; }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0)); }
    if (r_s3) { r_t0 = *(int *)((char *)r_s3 + (2076)); }
    r_a0 = (long)(r_sp + (0x150));
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_t1 = *(int *)((char *)r_v0 + (12)); }
    if (r_v0) { r_t2 = *(int *)((char *)r_v0 + (16)); }
    if (r_v0) { r_t3 = *(int *)((char *)r_v0 + (36)); }
    r_a3 = (long)(r_s0 | 0);
    r_v0 = (long)func_0011A498((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x150));
    r_v0 = (long)func_00118DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2196)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_a1 = (long)(0 + (2)); goto _lbl_01D98C08; }
    r_a1 = (long)(0 + (2));
    r_a1 = (long)(0 + (1));
    goto _lbl_01D98C08;
    r_a1 = (long)(0 + (2));
_lbl_01D98C08:
    if (r_s3) { r_t9 = *(int *)((char *)r_s3 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s3 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    goto _lbl_01D98C28;
    r_v1 = (long)(0 + (4));
_lbl_01D98C24:
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v1; }
_lbl_01D98C28:
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
_lbl_01D98C2C:
    r_v1 = (long)(0 + (1));
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (8)); }
    if (r_a0 != r_v1) goto _lbl_01D98CA4;
    if (r_a1) { r_a2 = *(int *)((char *)r_a1 + (52)); }
    if ((long)r_a2 <= 0) { r_a3 = (long)(r_a1 + (0x34)); goto _lbl_01D98CA4; }
    r_a3 = (long)(r_a1 + (0x34));
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (28)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2196)); }
    if (r_s3) { r_a1 = *(int *)((char *)r_s3 + (2076)); }
    r_a1 = (long)(r_a1 - r_a0);
    r_a0 = (long)((unsigned long)r_a1 << (2));
    r_a0 = (long)(r_a0 + r_a1);
    r_a0 = (long)((unsigned long)r_a0 << (1));
    if (r_v1 != 0) { /* unhandled: div $zero $a0 $v1 */ goto _lbl_01D98C70; }
    /* unhandled: div $zero $a0 $v1 */
    /* unhandled: break 0 7 */
_lbl_01D98C70:
    /* unhandled: mflo $a0 */
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 + r_a0);
    r_v1 = (long)((unsigned long)r_v1 << (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_v1 == r_a2) goto _lbl_01D98CA4;
    if (r_a3) { *(int *)((char *)r_a3 + (0)) = (int)r_v1; }
    if (r_s3) { r_t9 = *(int *)((char *)r_s3 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s3 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01D98CA4:
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_v1 = (long)(0 + (3));
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (8)); }
    if (r_a0 != r_v1) goto _lbl_01D98D30;
    if (r_a1) { r_a3 = *(int *)((char *)r_a1 + (52)); }
    r_at = (long)((long)r_a3 < (long)(0x64) ? 1 : 0);
    if (r_at == 0) { r_t0 = (long)(r_a1 + (0x34)); goto _lbl_01D98D30; }
    r_t0 = (long)(r_a1 + (0x34));
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2076)); }
    if (r_s3) { r_a1 = *(int *)((char *)r_s3 + (2196)); }
    r_a0 = (long)(r_v1 - r_s0);
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 + r_a0);
    r_v1 = (long)((unsigned long)r_v1 << (1));
    if (r_a1 != 0) { /* unhandled: div $zero $v1 $a1 */ goto _lbl_01D98CEC; }
    /* unhandled: div $zero $v1 $a1 */
    /* unhandled: break 0 7 */
_lbl_01D98CEC:
    /* unhandled: mflo $a2 */
    r_v1 = (long)((long)r_a0 < (long)r_a1 ? 1 : 0);
    r_a0 = (long)(0 + (0x63));
    r_a1 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 + r_a2);
    r_a1 = (long)((unsigned long)r_a1 << (1));
    if (r_v1 != 0) { r_a0 = (long)(r_a0 - r_a1); goto _lbl_01D98D10; }
    r_a0 = (long)(r_a0 - r_a1);
    r_a0 = (long)(0 | 0);
_lbl_01D98D10:
    if (r_a0 == r_a3) goto _lbl_01D98D30;
    if (r_t0) { *(int *)((char *)r_t0 + (0)) = (int)r_a0; }
    if (r_s3) { r_t9 = *(int *)((char *)r_s3 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s3 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01D98D30:
    if (r_s2) { r_s2 = *(int *)((char *)r_s2 + (4)); }
_lbl_01D98D38:
    if (r_s2 != 0) goto _lbl_01D988B0;
_lbl_01D98D40:
    /* unhandled: xori.b $w1 $w0 0xbf */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x650));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 10: multim_func_01D98D5C (VMA: 0x01D98D5C, size: 60 bytes) */
void *multim_func_01D98D5C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (2128)); }
    if (r_a1 == 0) goto _lbl_01D98D90;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2080)); }
    if (r_v1 != 0) goto _lbl_01D98D90;
    goto _lbl_01D98D88;
_lbl_01D98D80:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (4)); }
_lbl_01D98D88:
    if (r_a1 != 0) goto _lbl_01D98D80;
_lbl_01D98D90:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 11: multim_func_01D98D98 (VMA: 0x01D98D98, size: 980 bytes) */
void *multim_func_01D98D98(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x70));
    /* unhandled: subu.qb $zero $sp $ra */
    /* unhandled: ext $s3 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s2 */
    /* unhandled: addu.qb $zero $sp $s0 */
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2128)); }
    if (r_v1 == 0) { r_s3 = (long)(r_a0 | 0); goto _lbl_01D99150; }
    r_s3 = (long)(r_a0 | 0);
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2080)); }
    if (r_v1 == 0) goto _lbl_01D98DD8;
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    goto _lbl_01D99154;
_lbl_01D98DD8:
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (552)); }
    if (r_v1 == 0) goto _lbl_01D98E4C;
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (19)); }
    if (r_v1 == 0) goto _lbl_01D98E4C;
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (32)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_001AB8F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98E4C;
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (552)); }
    r_v0 = (long)(0x8080 << 16);
    r_v0 = (long)(r_v0 | (0x8080));
    r_a2 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    r_t2 = (long)(0 | 0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (12)); }
    if (r_v1) { r_t0 = *(unsigned short *)((char *)r_v1 + (8)); }
    if (r_v1) { r_t1 = *(unsigned short *)((char *)r_v1 + (10)); }
    if (r_s3) { r_a1 = *(int *)((char *)r_s3 + (32)); }
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_0025F140((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (32)); }
    r_v0 = (long)func_001AB9D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D98E4C:
    if (r_s3) { r_s0 = *(int *)((char *)r_s3 + (2128)); }
    goto _lbl_01D98FDC;
_lbl_01D98E54:
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0)); }
    if (r_s1 == 0) goto _lbl_01D98FD4;
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (4)); }
    r_a0 = (long)(0 + (1));
    if (r_v1 != r_a0) goto _lbl_01D98FD4;
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (8)); }
    r_v1 = (long)(0 + (2));
    if (r_a1 == r_v1) goto _lbl_01D98E90;
    if (r_a1 == r_a0) { r_v1 = (long)(0 + (3)); goto _lbl_01D98E90; }
    r_v1 = (long)(0 + (3));
    if (r_a1 != r_v1) goto _lbl_01D98FD4;
_lbl_01D98E90:
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2124)); }
    if (r_v1 == 0) goto _lbl_01D98F60;
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (19)); }
    if (r_v1 == 0) goto _lbl_01D98F60;
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (32)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_001AB8F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D98F60;
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (52)); }
    r_at = (long)((long)r_v0 < (long)(0x65) ? 1 : 0);
    if (r_at != 0) goto _lbl_01D98EDC;
    r_v0 = (long)(0 + (0x64));
    goto _lbl_01D98EE8;
_lbl_01D98EDC:
    if ((long)r_v0 >= 0) { r_v1 = (long)((unsigned long)r_v0 << (7)); goto _lbl_01D98EEC; }
    r_v1 = (long)((unsigned long)r_v0 << (7));
    r_v0 = (long)(0 | 0);
_lbl_01D98EE8:
    r_v1 = (long)((unsigned long)r_v0 << (7));
_lbl_01D98EEC:
    r_v0 = (long)(0 + (0x64));
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (2124)); }
    /* unhandled: div $zero $v1 $v0 */
    if (r_s1) { r_a2 = *(int *)((char *)r_s1 + (36)); }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (8)); }
    r_a1 = (long)(r_a1 + (8));
    r_v1 = (long)((unsigned long)r_a2 << (4));
    if (r_v0 != 0) { r_a1 = (long)(r_a1 + r_v1); goto _lbl_01D98F18; }
    r_a1 = (long)(r_a1 + r_v1);
    /* unhandled: break 0 7 */
_lbl_01D98F18:
    /* unhandled: mflo $v1 */
    r_v0 = (long)(0x80 << 16);
    r_v0 = (long)(r_v0 | (0x8080));
    r_v1 = (long)((unsigned long)r_v1 << (24));
    r_v0 = (long)(r_v1 + r_v0);
    if (r_a1) { r_t0 = *(unsigned short *)((char *)r_a1 + (8)); }
    if (r_a1) { r_t1 = *(unsigned short *)((char *)r_a1 + (10)); }
    if (r_s1) { r_a2 = *(int *)((char *)r_s1 + (12)); }
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (16)); }
    r_t2 = (long)(0 | 0);
    if (r_s3) { r_a1 = *(int *)((char *)r_s3 + (32)); }
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_0025F140((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (32)); }
    r_v0 = (long)func_001AB9D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D98F60:
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (8)); }
    r_a0 = (long)(0 + (1));
    if (r_a1 != r_a0) { r_v1 = (long)(0 + (3)); goto _lbl_01D98F90; }
    r_v1 = (long)(0 + (3));
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2196)); }
    r_at = (long)((long)r_v1 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_v1 = (long)(0 + (0x64)); goto _lbl_01D98F88; }
    r_v1 = (long)(0 + (0x64));
    if (r_s1) { *(int *)((char *)r_s1 + (52)) = (int)r_a0; }
    goto _lbl_01D98FD4;
_lbl_01D98F88:
    if (r_s1) { *(int *)((char *)r_s1 + (52)) = (int)r_v1; }
    goto _lbl_01D98FD4;
_lbl_01D98F90:
    if (r_a1 != r_v1) goto _lbl_01D98FD4;
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (52)); }
    r_v1 = (long)(0 + (0x64));
    if (r_a0 != r_v1) goto _lbl_01D98FC4;
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2196)); }
    r_at = (long)((long)r_v1 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_v1 = (long)(0 + (0x63)); goto _lbl_01D98FC0; }
    r_v1 = (long)(0 + (0x63));
    if (r_s1) { *(int *)((char *)r_s1 + (52)) = (int)r_v1; }
    goto _lbl_01D98FC4;
_lbl_01D98FC0:
    if (r_s1) { *(int *)((char *)r_s1 + (52)) = (int)0; }
_lbl_01D98FC4:
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (52)); }
    if ((long)r_v1 > 0) { r_v1 = (long)(0 + (4)); goto _lbl_01D98FD4; }
    r_v1 = (long)(0 + (4));
    if (r_s1) { *(int *)((char *)r_s1 + (8)) = (int)r_v1; }
_lbl_01D98FD4:
    if (r_s0) { r_s0 = *(int *)((char *)r_s0 + (4)); }
_lbl_01D98FDC:
    if (r_s0 != 0) goto _lbl_01D98E54;
    if (r_s3) { r_s1 = *(int *)((char *)r_s3 + (2128)); }
    goto _lbl_01D99148;
_lbl_01D98FEC:
    if (r_s1) { r_s2 = *(int *)((char *)r_s1 + (0)); }
    if (r_s2 == 0) goto _lbl_01D99140;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (4)); }
    if (r_v1 != 0) goto _lbl_01D99140;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (8)); }
    r_v1 = (long)(0 + (2));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (1)); goto _lbl_01D99024; }
    r_v1 = (long)(0 + (1));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (3)); goto _lbl_01D99024; }
    r_v1 = (long)(0 + (3));
    if (r_a0 != r_v1) goto _lbl_01D99140;
_lbl_01D99024:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (40)); }
    if (r_v1 == 0) goto _lbl_01D990CC;
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (32)); }
    r_v0 = (long)func_001ABA00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01D990CC;
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (32)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (56)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00225820((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(0 + (2));
    r_v0 = (long)func_00185E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (32)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (56)); }
    r_v0 = (long)func_002257A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (16)); }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (24)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (12)); }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (20)); }
    r_a0 = (long)(r_sp + (0x60));
    r_v0 = (long)(r_a2 + r_v0);
    r_v1 = (long)(r_a1 + r_v1);
    r_a3 = (long)(r_v1 + (-1));
    r_t0 = (long)(r_v0 + (-1));
    r_v0 = (long)func_002254F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (32)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (40)); }
    r_a2 = (long)(0 + (-1));
    r_a3 = (long)(r_sp + (0x60));
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (56)); }
    r_t0 = (long)(0 + (0x10));
    r_v0 = (long)func_00225BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (32)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (56)); }
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_002257A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (32)); }
    r_v0 = (long)func_001ABA70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D990CC:
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (8)); }
    r_a0 = (long)(0 + (1));
    if (r_a1 != r_a0) { r_v1 = (long)(0 + (3)); goto _lbl_01D990FC; }
    r_v1 = (long)(0 + (3));
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2196)); }
    r_at = (long)((long)r_v1 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_v1 = (long)(0 + (0x64)); goto _lbl_01D990F4; }
    r_v1 = (long)(0 + (0x64));
    if (r_s2) { *(int *)((char *)r_s2 + (52)) = (int)r_a0; }
    goto _lbl_01D99140;
_lbl_01D990F4:
    if (r_s2) { *(int *)((char *)r_s2 + (52)) = (int)r_v1; }
    goto _lbl_01D99140;
_lbl_01D990FC:
    if (r_a1 != r_v1) goto _lbl_01D99140;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (52)); }
    r_v1 = (long)(0 + (0x64));
    if (r_a0 != r_v1) goto _lbl_01D99130;
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2196)); }
    r_at = (long)((long)r_v1 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_v1 = (long)(0 + (0x63)); goto _lbl_01D9912C; }
    r_v1 = (long)(0 + (0x63));
    if (r_s2) { *(int *)((char *)r_s2 + (52)) = (int)r_v1; }
    goto _lbl_01D99130;
_lbl_01D9912C:
    if (r_s2) { *(int *)((char *)r_s2 + (52)) = (int)0; }
_lbl_01D99130:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (52)); }
    if ((long)r_v1 > 0) { r_v1 = (long)(0 + (4)); goto _lbl_01D99140; }
    r_v1 = (long)(0 + (4));
    if (r_s2) { *(int *)((char *)r_s2 + (8)) = (int)r_v1; }
_lbl_01D99140:
    if (r_s1) { r_s1 = *(int *)((char *)r_s1 + (4)); }
_lbl_01D99148:
    if (r_s1 != 0) goto _lbl_01D98FEC;
_lbl_01D99150:
    /* unhandled: aver_u.h $w1 $w0 $w31 */
_lbl_01D99154:
    /* unhandled: xori.b $w1 $w0 0xb3 */
    /* unhandled: ld.b $w0 -0x4f($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w16 */
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 12: multim_func_01D9916C (VMA: 0x01D9916C, size: 1084 bytes) */
void *multim_func_01D9916C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    /* unhandled: ext $ra $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_s0 = *(int *)((char *)r_a0 + (2128)); }
    r_s2 = (long)(r_a1 | 0);
    if (r_s0 != 0) { r_s3 = (long)(r_a0 | 0); goto _lbl_01D993F4; }
    r_s3 = (long)(r_a0 | 0);
    r_a0 = (long)(0 + (0xc));
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { *(int *)((char *)r_s3 + (2128)) = (int)r_v0; }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2128)); }
    r_a0 = (long)(0 + (0x3c));
    if (r_v0) { *(int *)((char *)r_v0 + (8)) = (int)0; }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v0) { *(int *)((char *)r_v0 + (4)) = (int)0; }
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    r_a2 = (long)(0 + (0x3c));
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (0)); }
    if (r_a1 == 0) goto _lbl_01D9958C;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(0 + (-1));
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (4)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (4)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (8)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (8)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (12)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (12)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (16)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    r_a1 = (long)(r_a1 + (-0x10));
    if (r_v1) { *(int *)((char *)r_v1 + (16)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (20)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (20)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (24)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (24)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (28)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (32)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (32)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (36)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (36)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (44)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (44)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (48)) = (int)r_a0; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (52)) = (int)0; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (56)) = (int)0; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (4)); }
    if (r_a0 == 0) { r_v1 = (long)(0 + (2)); goto _lbl_01D992E0; }
    r_v1 = (long)(0 + (2));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (4)); goto _lbl_01D992E0; }
    r_v1 = (long)(0 + (4));
    if (r_a0 != r_v1) { r_v1 = (long)(0 + (3)); goto _lbl_01D993D8; }
    r_v1 = (long)(0 + (3));
_lbl_01D992E0:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (40)); }
    r_v1 = (long)(0x49 << 16);
    r_v1 = (long)(r_v1 + (-0x1eff));
    if (r_a0) { r_a1 = *(char *)((char *)r_a0 + (0)); }
    r_v1 = (long)(r_v1 + r_a1);
    if (r_v1) { r_v1 = *(char *)((char *)r_v1 + (0)); }
    r_v1 = (long)(r_v1 & (4));
    if (r_v1 == 0) goto _lbl_01D99374;
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_001F6EA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (40)); }
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if ((long)r_s0 <= 0) { r_a0 = (long)(r_s0 + (1)); goto _lbl_01D9958C; }
    r_a0 = (long)(r_s0 + (1));
    r_v0 = (long)func_00116F40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    r_a2 = (long)(r_s0 + (1));
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (40)) = (int)r_v0; }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (40)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (40)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (40)); }
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D993EC;
_lbl_01D99374:
    if (r_a0 == 0) goto _lbl_01D9958C;
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if ((long)r_s0 <= 0) { r_a0 = (long)(r_s0 + (1)); goto _lbl_01D9958C; }
    r_a0 = (long)(r_s0 + (1));
    r_v0 = (long)func_00116F40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (2128)); }
    r_a2 = (long)(r_s0 + (1));
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (40)) = (int)r_v0; }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (40)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (2128)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (40)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (40)); }
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01D993EC;
_lbl_01D993D8:
    if (r_a0 != r_v1) goto _lbl_01D9958C;
    if (r_s3) { *(int *)((char *)r_s3 + (2088)) = (int)0; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (32)); }
    if (r_s3) { *(int *)((char *)r_s3 + (2092)) = (int)r_v1; }
_lbl_01D993EC:
    /* unhandled: xori.b $w1 $w0 0xbf */
    goto _lbl_01D99590;
_lbl_01D993F4:
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01D99404;
_lbl_01D993FC:
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (4)); }
_lbl_01D99404:
    if (r_v0 != 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01D993FC; }
    r_a0 = (long)(0 + (0xc));
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { *(int *)((char *)r_v0 + (8)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (4)) = (int)0; }
    r_s1 = (long)(r_v0 | 0);
    if (r_s1 == 0) { if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)0; } goto _lbl_01D99584; }
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)0; }
    r_a0 = (long)(0 + (0x3c));
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (0)) = (int)r_v0; }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0)); }
    r_a2 = (long)(0 + (0x3c));
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0)); }
    if (r_a1 == 0) goto _lbl_01D99584;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(0 + (-1));
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (4)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (4)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (8)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (8)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (12)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (12)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (16)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    r_a1 = (long)(r_a1 + (-0x10));
    if (r_v1) { *(int *)((char *)r_v1 + (16)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (20)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (20)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (24)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (24)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (28)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (32)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (32)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (36)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (36)) = (int)r_a1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (44)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (44)) = (int)r_a1; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (48)) = (int)r_a0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (52)) = (int)0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (56)) = (int)0; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0)); }
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (4)); }
    if (r_a0 == 0) { r_v1 = (long)(0 + (2)); goto _lbl_01D99510; }
    r_v1 = (long)(0 + (2));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (4)); goto _lbl_01D99510; }
    r_v1 = (long)(0 + (4));
    if (r_a0 != r_v1) { r_v1 = (long)(0 + (3)); goto _lbl_01D99560; }
    r_v1 = (long)(0 + (3));
_lbl_01D99510:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (40)); }
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 | 0);
    if ((long)r_s3 <= 0) { r_a0 = (long)(r_s3 + (1)); goto _lbl_01D99584; }
    r_a0 = (long)(r_s3 + (1));
    r_v0 = (long)func_00116F40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    r_a2 = (long)(r_s3 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (40)) = (int)r_v0; }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (40)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (40)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (40)); }
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (8)) = (int)r_s0; }
    goto _lbl_01D99588;
_lbl_01D99560:
    if (r_a0 != r_v1) goto _lbl_01D99580;
    if (r_s3) { *(int *)((char *)r_s3 + (2088)) = (int)0; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (32)); }
    if (r_s3) { *(int *)((char *)r_s3 + (2092)) = (int)r_v1; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (40)) = (int)0; }
    goto _lbl_01D99584;
_lbl_01D99580:
    if (r_a1) { *(int *)((char *)r_a1 + (40)) = (int)0; }
_lbl_01D99584:
    if (r_s1) { *(int *)((char *)r_s1 + (8)) = (int)r_s0; }
_lbl_01D99588:
    if (r_s0) { *(int *)((char *)r_s0 + (4)) = (int)r_s1; }
_lbl_01D9958C:
    /* unhandled: xori.b $w1 $w0 0xbf */
_lbl_01D99590:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 13: multim_func_01D995A8 (VMA: 0x01D995A8, size: 252 bytes) */
void *multim_func_01D995A8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    /* unhandled: dpa.w.ph $ac0 $sp $ra */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_s2 = *(int *)((char *)r_a0 + (2128)); }
    if (r_s2 == 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01D9968C; }
    r_s0 = (long)(r_a0 | 0);
    r_v1 = (long)(r_s2 | 0);
    goto _lbl_01D995E4;
    r_s2 = (long)(r_v1 | 0);
_lbl_01D995DC:
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (4)); }
_lbl_01D995E4:
    if (r_v1 != 0) { r_s2 = (long)(r_v1 | 0); goto _lbl_01D995DC; }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (2128)); }
    goto _lbl_01D99648;
_lbl_01D995F4:
    if (r_s2 == 0) { if (r_s2) { r_s1 = *(int *)((char *)r_s2 + (8)); } goto _lbl_01D99640; }
    if (r_s2) { r_s1 = *(int *)((char *)r_s2 + (8)); }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0)); }
    if (r_v0 == 0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01D99638; }
    r_a0 = (long)(r_s2 | 0);
    r_a0 = (long)(0 + (0x2009));
    r_v0 = (long)func_0025D060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (2228)) = (int)0; }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (40)); }
    if (r_a0 == 0) goto _lbl_01D9962C;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9962C:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (0)); }
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 | 0);
_lbl_01D99638:
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D99640:
    r_s2 = (long)(r_s1 | 0);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (2128)); }
_lbl_01D99648:
    if (r_s2 != r_v1) goto _lbl_01D995F4;
    if (r_v1 == 0) goto _lbl_01D9968C;
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    if (r_v0 == 0) goto _lbl_01D99684;
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (40)); }
    if (r_a0 == 0) goto _lbl_01D99678;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D99678:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2128)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D99684:
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2128)); }
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D9968C:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 14: multim_func_01D996A4 (VMA: 0x01D996A4, size: 232 bytes) */
void *multim_func_01D996A4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    /* unhandled: subu.qb $zero $sp $ra */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2056)); }
    r_v0 = (long)((long)r_v1 < (long)(0x100) ? 1 : 0);
    if (r_v0 != 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01D996F8; }
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)(r_v1 + (-0x100));
    if (r_s0) { *(int *)((char *)r_s0 + (2056)) = (int)r_v0; }
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (0x4210));
    r_v0 = (long)(0x1da << 16);
    r_s3 = (long)(r_v0 + (0x4310));
    goto _lbl_01D99708;
_lbl_01D996F8:
    r_v0 = (long)(0x1da << 16);
    r_v1 = (long)(r_v0 + (-0x6100));
    r_v0 = (long)(0x1da << 16);
    r_s3 = (long)(r_v0 + (-0x6000));
_lbl_01D99708:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2056)); }
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(r_v1 + r_v0);
    if (r_v0) { r_s1 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_s4 = *(int *)((char *)r_v0 + (4)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00116F40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s3 + r_s4);
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01D99810((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 == 0) goto _lbl_01D99768;
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01D99768:
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_v0 = (long)(0 + (1));
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 15: multim_func_01D9978C (VMA: 0x01D9978C, size: 1304 bytes) */
void *multim_func_01D9978C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0;
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
    (void)r_s8;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x4f0));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    r_s6 = (long)(r_a0 | 0);
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s5 = (long)(r_a1 | 0);
    r_v0 = (long)(0x1db << 16);
    r_a1 = (long)(r_v0 + (-0x3f70));
    r_a0 = (long)(r_sp + (0x4b0));
    r_v1 = (long)(0 + (3));
    /* unhandled: ext $s0 $sp 0 1 */
    r_s7 = (long)(r_a2 | 0);
_lbl_01D997D8:
    /* unhandled: andi.b $w0 $w0 0xa2 */
    r_v1 = (long)(r_v1 + (-1));
    /* unhandled: ext $v0 $a0 0 1 */
    r_a1 = (long)(r_a1 + (0x10));
    if ((long)r_v1 > 0) { r_a0 = (long)(r_a0 + (0x10)); goto _lbl_01D997D8; }
    r_a0 = (long)(r_a0 + (0x10));
    /* unhandled: lwc1 $f2 8($a1) */
    r_s1 = (long)(0 + (1));
    r_a2 = (long)(0 + (0x100));
    if (r_sp) { *(char *)((char *)r_sp + (160)) = (char)0; }
    /* unhandled: swc1 $f2 8($a0) */
    r_a0 = (long)(r_sp + (0xb0));
    r_a1 = (long)(0 | 0);
    r_s8 = (long)(0 | 0);
    r_s4 = (long)(0 | 0);
    r_s2 = (long)(0 | 0);
    r_s3 = (long)(r_s1 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(0 | 0);
    goto _lbl_01D99C64;
    r_v0 = (long)(r_s5 + r_s0);
_lbl_01D99834:
    if (r_v0) { r_v1 = *(char *)((char *)r_v0 + (0)); }
    r_v0 = (long)(0 + (0x20));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (0xa)); goto _lbl_01D99858; }
    r_v0 = (long)(0 + (0xa));
    r_v0 = (long)(r_v1 + (-9));
    r_at = (long)((unsigned long)r_v0 < (unsigned long)(2) ? 1 : 0);
    if (r_at == 0) { r_a2 = (long)(0 + (0x22)); goto _lbl_01D99B70; }
    r_a2 = (long)(0 + (0x22));
    r_v0 = (long)(0 + (0xa));
_lbl_01D99858:
    if (r_v1 != r_v0) { r_s1 = (long)(0 | 0); goto _lbl_01D99898; }
    if (r_v1 != r_v0) { r_s1 = (long)(0 + (1)); goto _lbl_01D99880; }
    if (r_s1 == 0) goto _lbl_01D9987C;
    r_s1 = (long)(0 + (1));
    r_s4 = (long)(0 | 0);
    goto _lbl_01D99884;
_lbl_01D9987C:
    r_s1 = (long)(0 + (1));
_lbl_01D99880:
    r_s4 = (long)(r_s1 | 0);
_lbl_01D99884:
    if (r_v1 != 0) { r_v0 = (long)(r_s2 + r_sp); goto _lbl_01D9989C; }
    r_v0 = (long)(r_s2 + r_sp);
    r_s0 = (long)(r_s7 | 0);
    goto _lbl_01D99898;
    r_s1 = (long)(0 | 0);
_lbl_01D99898:
    r_v0 = (long)(r_s2 + r_sp);
_lbl_01D9989C:
    if (r_s4 == 0) { if (r_v0) { *(char *)((char *)r_v0 + (176)) = (char)0; } goto _lbl_01D99C60; }
    if (r_v0) { *(char *)((char *)r_v0 + (176)) = (char)0; }
    r_at = (long)((unsigned long)r_s3 < (unsigned long)(0xf) ? 1 : 0);
    if (r_at == 0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01D99B60; }
    r_v0 = (long)(0x1db << 16);
    r_v1 = (long)(r_v0 + (-0x39b0));
    r_v0 = (long)((unsigned long)r_s3 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    return (void *)r_v0;
    if (r_s1 == 0) goto _lbl_01D99B5C;
    r_s3 = (long)(0 | 0);
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (1200)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    r_v0 = (long)(0x1db << 16);
    r_a0 = (long)(r_sp + (0xb0));
    r_a1 = (long)(r_v0 + (-0x3a20));
    r_v0 = (long)func_0011A708((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01D9990C;
    if (r_sp) { *(int *)((char *)r_sp + (1204)) = (int)0; }
    goto _lbl_01D99B5C;
_lbl_01D9990C:
    r_v0 = (long)(0x1db << 16);
    r_a0 = (long)(r_sp + (0xb0));
    r_a1 = (long)(r_v0 + (-0x3a18));
    r_v0 = (long)func_0011A708((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01D99930;
    r_v0 = (long)(0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (1204)) = (int)r_v0; }
    goto _lbl_01D99B5C;
_lbl_01D99930:
    r_v0 = (long)(0x1db << 16);
    r_a0 = (long)(r_sp + (0xb0));
    r_a1 = (long)(r_v0 + (-0x3a10));
    r_v0 = (long)func_0011A708((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01D99954;
    r_v0 = (long)(0 + (2));
    if (r_sp) { *(int *)((char *)r_sp + (1204)) = (int)r_v0; }
    goto _lbl_01D99B5C;
_lbl_01D99954:
    r_v0 = (long)(0x1db << 16);
    r_a0 = (long)(r_sp + (0xb0));
    r_a1 = (long)(r_v0 + (-0x3a08));
    r_v0 = (long)func_0011A708((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01D99978;
    r_v0 = (long)(0 + (3));
    if (r_sp) { *(int *)((char *)r_sp + (1204)) = (int)r_v0; }
    goto _lbl_01D99B5C;
_lbl_01D99978:
    r_v0 = (long)(0x1db << 16);
    r_a0 = (long)(r_sp + (0xb0));
    r_a1 = (long)(r_v0 + (-0x3a00));
    r_v0 = (long)func_0011A708((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01D99B5C;
    r_v0 = (long)(0 + (4));
    if (r_sp) { *(int *)((char *)r_sp + (1204)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (1212)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (1216)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (1220)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (1224)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (1228)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (1232)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (1236)) = (int)r_v0; }
    goto _lbl_01D99B5C;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (1204)); }
    if (r_v1 == 0) { r_v0 = (long)(r_sp + (0x2b0)); goto _lbl_01D99A34; }
    r_v0 = (long)(r_sp + (0x2b0));
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01D99A30;
    r_v0 = (long)(0 + (4));
    if (r_v1 != r_v0) goto _lbl_01D99A3C;
_lbl_01D99A30:
    r_v0 = (long)(r_sp + (0x2b0));
_lbl_01D99A34:
    if (r_sp) { *(int *)((char *)r_sp + (1240)) = (int)r_v0; }
    goto _lbl_01D99B5C;
_lbl_01D99A3C:
    if (r_sp) { *(int *)((char *)r_sp + (1240)) = (int)0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(char *)((char *)r_sp + (160)) = (char)r_v0; }
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s8 = (long)(r_v0 & (0xff));
    goto _lbl_01D99B5C;
    r_a0 = (long)(r_sp + (0xb0));
    r_v0 = (long)func_00114378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_v0 & (0xff));
    r_v1 = (long)((unsigned long)r_v0 << (16));
    r_v0 = (long)(r_s8 & (0xff));
    r_a0 = (long)((unsigned long)r_v0 << (8));
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (160)); }
    r_v0 = (long)(r_v0 | 0);
    r_v0 = (long)(r_v0 | r_a0);
    r_v0 = (long)(r_v1 | r_v0);
    if (r_s1 == 0) { if (r_sp) { *(int *)((char *)r_sp + (1244)) = (int)r_v0; } goto _lbl_01D99B5C; }
    if (r_sp) { *(int *)((char *)r_sp + (1244)) = (int)r_v0; }
    r_a0 = (long)(r_sp + (0x4c4));
    if (r_sp) { *(int *)((char *)r_sp + (1208)) = (int)0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (1212)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0)); }
    r_v0 = (long)(r_v1 + r_v0);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)((long)r_v0 < (long)(0x281) ? 1 : 0);
    if (r_at != 0) { r_a0 = (long)(r_sp + (0x4c8)); goto _lbl_01D99AC8; }
    r_v0 = (long)(0 + (0x280));
    r_v0 = (long)(r_v0 - r_v1);
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
    r_a0 = (long)(r_sp + (0x4c8));
_lbl_01D99AC8:
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (1216)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0)); }
    r_v0 = (long)(r_v1 + r_v0);
    r_v0 = (long)(r_v0 + (-1));
    r_at = (long)((long)r_v0 < (long)(0x1c1) ? 1 : 0);
    if (r_at != 0) goto _lbl_01D99AF0;
    r_v0 = (long)(0 + (0x1c0));
    r_v0 = (long)(r_v0 - r_v1);
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
_lbl_01D99AF0:
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (2196)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) { r_v1 = (long)(r_sp + (0x4dc)); goto _lbl_01D99B30; }
    r_v1 = (long)(r_sp + (0x4dc));
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (1204)); }
    if (r_v1 == 0) goto _lbl_01D99B18;
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01D99B2C;
_lbl_01D99B18:
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2196)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (1232)); }
    r_v1 = (long)(r_v1 + (0x64));
    r_v0 = (long)(r_v0 - r_v1);
    if (r_sp) { *(int *)((char *)r_sp + (1232)) = (int)r_v0; }
_lbl_01D99B2C:
    r_v1 = (long)(r_sp + (0x4dc));
_lbl_01D99B30:
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0)); }
    if (r_v0 != 0) { r_a1 = (long)(r_sp + (0x4b0)); goto _lbl_01D99B48; }
    r_a1 = (long)(r_sp + (0x4b0));
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (844)); }
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_v0; }
    r_a1 = (long)(r_sp + (0x4b0));
_lbl_01D99B48:
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01D991F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1 == 0) goto _lbl_01D99B5C;
    r_s3 = (long)(0 | 0);
_lbl_01D99B5C:
    r_s3 = (long)(r_s3 + (1));
_lbl_01D99B60:
    r_s4 = (long)(0 | 0);
    r_s2 = (long)(0 | 0);
    goto _lbl_01D99C60;
    r_a2 = (long)(0 + (0x22));
_lbl_01D99B70:
    if (r_v1 != r_a2) { r_v0 = (long)(r_s5 + r_s0); goto _lbl_01D99BF4; }
    r_v0 = (long)(r_s5 + r_s0);
    r_v1 = (long)(0 + (0xa));
    r_s2 = (long)(0 | 0);
    goto _lbl_01D99BBC;
    r_s0 = (long)(r_s0 + (1));
_lbl_01D99B88:
    r_a1 = (long)(r_s5 + r_s0);
    if (r_a1) { r_a0 = *(char *)((char *)r_a1 + (0)); }
    r_v0 = (long)(r_s2 + r_sp);
    if (r_v0) { *(char *)((char *)r_v0 + (688)) = (char)r_a0; }
    if (r_a1) { r_v0 = *(char *)((char *)r_a1 + (0)); }
    if (r_v0 == r_v1) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01D99BAC; }
    r_s2 = (long)(r_s2 + (1));
    if (r_v0 != r_a2) { r_v0 = (long)((long)r_s0 < (long)r_s7 ? 1 : 0); goto _lbl_01D99BC0; }
    r_v0 = (long)((long)r_s0 < (long)r_s7 ? 1 : 0);
_lbl_01D99BAC:
    r_s2 = (long)(r_s2 + (-1));
    r_v0 = (long)(r_s2 + r_sp);
    if (r_v0) { *(char *)((char *)r_v0 + (688)) = (char)0; }
    goto _lbl_01D99BC8;
_lbl_01D99BBC:
    r_v0 = (long)((long)r_s0 < (long)r_s7 ? 1 : 0);
_lbl_01D99BC0:
    if (r_v0 != 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01D99B88; }
_lbl_01D99BC8:
    r_v0 = (long)(r_s5 + r_s0);
    if (r_v0) { r_v1 = *(char *)((char *)r_v0 + (0)); }
    r_v0 = (long)(0 + (0x22));
    if (r_v1 != r_v0) goto _lbl_01D99BF0;
    r_v0 = (long)(0 + (0xa));
    if (r_s3 != r_v0) goto _lbl_01D99BF0;
    r_s4 = (long)(0 + (1));
    goto _lbl_01D99C60;
_lbl_01D99BF0:
    r_v0 = (long)(r_s5 + r_s0);
_lbl_01D99BF4:
    if (r_v0) { r_a1 = *(char *)((char *)r_v0 + (0)); }
    r_v0 = (long)(0x49 << 16);
    r_v0 = (long)(r_v0 + (-0x1f00));
    r_v0 = (long)(r_v0 + r_a1);
    if (r_v0) { r_a0 = *(char *)((char *)r_v0 + (1)); }
    r_v0 = (long)(r_a0 & (7));
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01D99C64; }
    r_at = (long)((unsigned long)r_s3 < (unsigned long)(0xe) ? 1 : 0);
    if (r_at == 0) goto _lbl_01D99C60;
    r_v0 = (long)(0x1db << 16);
    r_v1 = (long)(r_v0 + (-0x39f0));
    r_v0 = (long)((unsigned long)r_s3 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    return (void *)r_v0;
    r_v0 = (long)(r_a0 & (3));
    if (r_v0 == 0) { r_v0 = (long)(r_s2 + r_sp); goto _lbl_01D99C54; }
    r_v0 = (long)(r_s2 + r_sp);
    r_s3 = (long)(0 | 0);
    goto _lbl_01D99C60;
    r_v0 = (long)(r_s2 + r_sp);
_lbl_01D99C54:
    r_s4 = (long)(0 + (1));
    r_s2 = (long)(r_s2 + (1));
    if (r_v0) { *(char *)((char *)r_v0 + (176)) = (char)r_a1; }
_lbl_01D99C60:
    r_s0 = (long)(r_s0 + (1));
_lbl_01D99C64:
    r_at = (long)((long)r_s7 < (long)r_s0 ? 1 : 0);
    if (r_at == 0) { r_v0 = (long)(r_s5 + r_s0); goto _lbl_01D99834; }
    r_v0 = (long)(r_s5 + r_s0);
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_v0 = (long)(0 | 0);
    r_sp = (long)(r_sp + (0x4f0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 16: multim_func_01D99CA4 (VMA: 0x01D99CA4, size: 152 bytes) */
void *multim_func_01D99CA4(void *a0, void *a1, void *a2, void *a3) {
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
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2084)); }
    if (r_v0 == 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01D99CE0; }
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (2076)); }
    r_v1 = (long)(r_v0 - r_v1);
    if (r_s0) { *(int *)((char *)r_s0 + (2072)) = (int)r_v1; }
    goto _lbl_01D99CF4;
_lbl_01D99CE0:
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (2072)); }
    r_v1 = (long)(r_v0 - r_v1);
    if (r_s0) { *(int *)((char *)r_s0 + (2076)) = (int)r_v1; }
_lbl_01D99CF4:
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (2088)); }
    r_a1 = (long)(0 + (1));
    if (r_v1 == r_a1) goto _lbl_01D99D2C;
    if (r_v1 == 0) goto _lbl_01D99D14;
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    goto _lbl_01D99D30;
_lbl_01D99D14:
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2076)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (2092)); }
    r_at = (long)((unsigned long)r_v1 < (unsigned long)r_a0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D99D2C;
    if (r_s0) { *(int *)((char *)r_s0 + (2080)) = (int)r_a1; }
_lbl_01D99D2C:
    /* unhandled: aver_u.h $w0 $w0 $w31 */
_lbl_01D99D30:
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 17: multim_func_01D99D3C (VMA: 0x01D99D3C, size: 240 bytes) */
void *multim_func_01D99D3C(void *a0, void *a1, void *a2, void *a3) {
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
    r_v0 = (long)(0 + (2));
    r_v1 = (long)(r_a1 & (0xff));
    if (r_v1 != r_v0) { /* unhandled: ext $ra $sp 0 1 */ goto _lbl_01D99D60; }
    /* unhandled: ext $ra $sp 0 1 */
    r_v0 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (2080)) = (int)r_v0; }
    goto _lbl_01D99E20;
_lbl_01D99D60:
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_v0 = (long)(0 | 0); goto _lbl_01D99E20; }
    r_v0 = (long)(0 | 0);
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (2128)); }
    r_a2 = (long)(0 | 0);
    goto _lbl_01D99DE4;
_lbl_01D99D78:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (0)); }
    if (r_v0 == 0) goto _lbl_01D99DDC;
    if (r_v0) { r_a3 = *(int *)((char *)r_v0 + (28)); }
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (32)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (4)); }
    if (r_v0 != 0) { r_v1 = (long)(r_a3 + r_v1); goto _lbl_01D99DDC; }
    r_v1 = (long)(r_a3 + r_v1);
    if (r_a0) { r_t0 = *(int *)((char *)r_a0 + (2076)); }
    r_at = (long)((unsigned long)r_t0 < (unsigned long)r_a3 ? 1 : 0);
    if (r_at != 0) goto _lbl_01D99DDC;
    r_v0 = (long)((unsigned long)r_v1 < (unsigned long)r_t0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01D99DDC;
    r_v0 = (long)(r_a3 + (0x3e8));
    r_at = (long)((unsigned long)r_t0 < (unsigned long)r_v0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01D99DDC;
    if (r_a2 == 0) { r_a2 = (long)(r_v1 | 0); goto _lbl_01D99DDC; }
    r_at = (long)((unsigned long)r_v1 < (unsigned long)r_a2 ? 1 : 0);
    if (r_at == 0) goto _lbl_01D99DDC;
    r_a2 = (long)(r_v1 | 0);
_lbl_01D99DDC:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (4)); }
_lbl_01D99DE4:
    if (r_a1 != 0) goto _lbl_01D99D78;
    if (r_a2 == 0) { r_v0 = (long)(0 + (1)); goto _lbl_01D99E14; }
    r_v0 = (long)(0 + (1));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2076)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2072)); }
    r_v1 = (long)(r_a2 - r_v1);
    r_v0 = (long)(r_v0 - r_v1);
    if (r_a0) { *(int *)((char *)r_a0 + (2072)) = (int)r_v0; }
    r_a0 = (long)(0 + (0x2009));
    r_v0 = (long)func_0025D060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01D99E14:
    /* unhandled: xori.b $w0 $w0 0xbf */
    goto _lbl_01D99E24;
    r_v0 = (long)(0 | 0);
_lbl_01D99E20:
    /* unhandled: xori.b $w0 $w0 0xbf */
_lbl_01D99E24:
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 18: multim_func_01D99E2C (VMA: 0x01D99E2C, size: 76 bytes) */
void *multim_func_01D99E2C(void *a0, void *a1, void *a2, void *a3) {
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
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)func_00215A80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (144)); }
    if (r_v0 == 0) goto _lbl_01D99E60;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_00186110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    goto _lbl_01D99E6C;
_lbl_01D99E60:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_001860D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: aver_u.h $w0 $w0 $w31 */
_lbl_01D99E6C:
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 19: multim_func_01D99E78 (VMA: 0x01D99E78, size: 72 bytes) */
void *multim_func_01D99E78(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    /* unhandled: tge $zero $zero 0x12 */
    /* unhandled: teq $zero $zero 0x57 */
    return (void *)r_v0;
}

