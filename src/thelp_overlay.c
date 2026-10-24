/* Age of Empires II PS2 - THELP_CD.BIN Overlay */
#include "common.h"
#include "thelp_overlay.h"

/* External mock prototypes for external calls */
extern void *func_00100670(void *a0, void *a1, void *a2, void *a3);
extern void *func_00100850(void *a0, void *a1, void *a2, void *a3);
extern void *func_00114308(void *a0, void *a1, void *a2, void *a3);
extern void *func_001143F8(void *a0, void *a1, void *a2, void *a3);
extern void *func_00116F68(void *a0, void *a1, void *a2, void *a3);
extern void *func_00117AF8(void *a0, void *a1, void *a2, void *a3);
extern void *func_00117CAC(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011A498(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011A8E8(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011AA78(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011ABBC(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011ACD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011AE08(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011B170(void *a0, void *a1, void *a2, void *a3);
extern void *func_0011B330(void *a0, void *a1, void *a2, void *a3);
extern void *func_00123350(void *a0, void *a1, void *a2, void *a3);
extern void *func_0017DCA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00185D40(void *a0, void *a1, void *a2, void *a3);
extern void *func_00185E20(void *a0, void *a1, void *a2, void *a3);
extern void *func_00185F00(void *a0, void *a1, void *a2, void *a3);
extern void *func_001861C0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001880D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001880E0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001886B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AB8F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AB9D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001ABA00(void *a0, void *a1, void *a2, void *a3);
extern void *func_001ABA70(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AC320(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AC470(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AC650(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AD650(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AE110(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AE120(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AECD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001AED20(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F26D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F2900(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F2CB0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F45E0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F55C0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F5AD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6460(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6750(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6850(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6CD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6DB0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6DC0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6DD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6DE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6DF0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6E00(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6E50(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F6EA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F7B90(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F8140(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F8190(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F86F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F8E60(void *a0, void *a1, void *a2, void *a3);
extern void *func_001F8E70(void *a0, void *a1, void *a2, void *a3);
extern void *func_001FA670(void *a0, void *a1, void *a2, void *a3);
extern void *func_001FBA10(void *a0, void *a1, void *a2, void *a3);
extern void *func_001FBF30(void *a0, void *a1, void *a2, void *a3);
extern void *func_00204920(void *a0, void *a1, void *a2, void *a3);
extern void *func_0020BAF0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0020BB50(void *a0, void *a1, void *a2, void *a3);
extern void *func_0020BE60(void *a0, void *a1, void *a2, void *a3);
extern void *func_0020DA60(void *a0, void *a1, void *a2, void *a3);
extern void *func_0020DA80(void *a0, void *a1, void *a2, void *a3);
extern void *func_0020DB70(void *a0, void *a1, void *a2, void *a3);
extern void *func_0020DC00(void *a0, void *a1, void *a2, void *a3);
extern void *func_0020DDC0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002134F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00215910(void *a0, void *a1, void *a2, void *a3);
extern void *func_00215950(void *a0, void *a1, void *a2, void *a3);
extern void *func_00215EE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00216240(void *a0, void *a1, void *a2, void *a3);
extern void *func_00217840(void *a0, void *a1, void *a2, void *a3);
extern void *func_00217880(void *a0, void *a1, void *a2, void *a3);
extern void *func_002178A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002178E0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002181F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002193D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00219F00(void *a0, void *a1, void *a2, void *a3);
extern void *func_0021FEC0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0021FED0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002254F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00225520(void *a0, void *a1, void *a2, void *a3);
extern void *func_00225560(void *a0, void *a1, void *a2, void *a3);
extern void *func_002257A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002257C0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00225820(void *a0, void *a1, void *a2, void *a3);
extern void *func_00225BE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002261C0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00226B40(void *a0, void *a1, void *a2, void *a3);
extern void *func_00226BF0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00226D90(void *a0, void *a1, void *a2, void *a3);
extern void *func_00252CA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00252CE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_00252CF0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025D060(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025D6D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025DE30(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025E640(void *a0, void *a1, void *a2, void *a3);
extern void *func_0025F2B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002D2AA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002D2D90(void *a0, void *a1, void *a2, void *a3);
extern void *func_002D2EB0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002D2F00(void *a0, void *a1, void *a2, void *a3);
extern void *func_002D2FF0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002D3000(void *a0, void *a1, void *a2, void *a3);
extern void *func_002D33E0(void *a0, void *a1, void *a2, void *a3);
extern void *func_002FEDD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0032F1F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0036C2D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0036C320(void *a0, void *a1, void *a2, void *a3);
extern void *func_0036C3A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_0036DDF0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F694A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F69C20(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F69FB0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F69FC0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6A270(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6A3A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6A4F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6B250(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6CB30(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6E210(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6E3A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6E5C0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6EAE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F250(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F2E0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F380(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F390(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F3F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F450(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F5B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F770(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F8C0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6F9B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FAA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FAE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FBD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FCF0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FD40(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FD90(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FDE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FE30(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F6FEA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F704A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F70AC0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F70D50(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F71A60(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F71AC0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F71C40(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F724A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F72BD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F72E90(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F73000(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F734C0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F73780(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F73AB0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F73C90(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F743E0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F745B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F746F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F74A10(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F74C80(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F74CC0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F74CF0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F75210(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F75230(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F75300(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F75420(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F757B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F75840(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F758A0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F758F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F75930(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F759E0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F75A40(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F75F60(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F761D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F76BE0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F76D80(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F771D0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F77270(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F776B0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F77800(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F77910(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F779F0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F77BA0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F77C00(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F77D80(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F77E80(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78030(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78090(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78210(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78370(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78410(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78430(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78520(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78680(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78780(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78BD0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78C20(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78C70(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78CC0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78D10(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78D70(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78E30(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78E50(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78E70(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78ED0(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78F00(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F78F30(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F79140(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F79330(void *a0, void *a1, void *a2, void *a3);
extern void *func_01F794C0(void *a0, void *a1, void *a2, void *a3);

/* Data and Read-Only Tables (.rodata: 320 bytes) */
const unsigned int thelp_data[THELP_DATA_WORD_COUNT] = {
#include "thelp_data.inc"
};

/* Function 1: thelp_func_01F68000 (VMA: 0x01F68000, size: 4300 bytes) */
void *thelp_func_01F68000(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x240));
    /* unhandled: ext $ra $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s4 */
    /* unhandled: subu.qb $zero $sp $s2 */
    /* unhandled: ext $s1 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s0 */
    if (r_sp) { *(int *)((char *)r_sp + (156)) = (int)r_a0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_s4 = (long)(r_a1 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6b00));
    r_s3 = (long)(r_a2 | 0);
    r_s2 = (long)(r_a3 | 0);
    r_v0 = (long)func_00215910((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(0x4e << 16);
    r_a2 = (long)(r_v0 + (0x23e0));
    r_v0 = (long)(0 + (-1));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_a2; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0xbf80 << 16);
    r_v1 = (long)(0 + (5));
    if (r_a0) { *(int *)((char *)r_a0 + (2072)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2076)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2080)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2084)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2092)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2096)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2100)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2104)) = (int)r_v0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2108)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2112)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2116)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2120)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2124)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (2128)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3532)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3536)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3540)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3544)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3548)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3552)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3556)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3560)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3564)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3568)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3572)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3576)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3580)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3584)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3588)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3592)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3596)) = (int)r_a1; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3600)) = (int)r_a1; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3604)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3608)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3612)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3616)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3620)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3624)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3628)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3632)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3636)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3640)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3644)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3648)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3652)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3656)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3660)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3664)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3668)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3672)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3676)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3684)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3692)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3696)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3724)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3728)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3732)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (3736)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { *(int *)((char *)r_a0 + (5788)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5792)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5796)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5800)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5804)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5808)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5812)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5816)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5820)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5824)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5828)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5832)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5836)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5840)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5844)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5848)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5876)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5884)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5888)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a0 = (long)(r_v0 + (0x16fc));
    r_v0 = (long)func_00225560((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a0 = (long)(r_s4 | 0);
    if (r_v0) { *(int *)((char *)r_v0 + (2088)) = (int)r_s4; }
    r_v0 = (long)func_001F6DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_t1 = (long)(r_v0 + (-0x6ae0));
    r_t3 = (long)(0 + (1));
    r_a2 = (long)(r_s4 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s0 | 0);
    r_t2 = (long)(0 | (0xc3aa));
    r_v0 = (long)func_01F69FB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F68338;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68338:
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)func_01F757B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3 == 0) goto _lbl_01F68350;
    if (r_s3) { r_s2 = *(unsigned char *)((char *)r_s3 + (3161)); }
_lbl_01F68350:
    if ((long)r_s2 < 0) { r_a0 = (long)(0 | 0); goto _lbl_01F683B8; }
    r_a0 = (long)(0 | 0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2104)) = (int)r_s2; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F758A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F75930((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2092)) = (int)r_v0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (2092)); }
    if (r_a0 != 0) { r_a1 = (long)(0 + (5)); goto _lbl_01F683A4; }
    r_a1 = (long)(0 + (5));
    r_v0 = (long)(0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (244)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
    r_a1 = (long)(0 + (5));
_lbl_01F683A4:
    r_a2 = (long)(0 + (3));
    r_v0 = (long)func_01F77800((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2096)) = (int)0; }
    r_a0 = (long)(0 | 0);
_lbl_01F683B8:
    r_v0 = (long)((long)r_a0 < (long)(0x32) ? 1 : 0);
    goto _lbl_01F683D8;
_lbl_01F683C0:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_a0 = (long)(r_a0 + (1));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { *(int *)((char *)r_v0 + (2132)) = (int)0; }
    r_v0 = (long)((long)r_a0 < (long)(0x32) ? 1 : 0);
_lbl_01F683D8:
    if (r_v0 != 0) goto _lbl_01F683C0;
    r_a0 = (long)(0 | 0);
    goto _lbl_01F683FC;
_lbl_01F683E8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_a0 = (long)(r_a0 + (1));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { *(int *)((char *)r_v0 + (2332)) = (int)0; }
_lbl_01F683FC:
    r_v0 = (long)((long)r_a0 < (long)(0x96) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F683E8;
    r_a0 = (long)(0 | 0);
    goto _lbl_01F68424;
_lbl_01F68410:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_a0 = (long)(r_a0 + (1));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { *(int *)((char *)r_v0 + (2932)) = (int)0; }
_lbl_01F68424:
    r_v0 = (long)((long)r_a0 < (long)(0x96) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F68410;
    r_a0 = (long)(0 | 0);
    goto _lbl_01F6844C;
_lbl_01F68438:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_a0 = (long)(r_a0 + (1));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { *(int *)((char *)r_v0 + (3700)) = (int)0; }
_lbl_01F6844C:
    r_v0 = (long)((long)r_a0 < (long)(6) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F68438;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a0 = (long)(0 | 0);
    if (r_v0) { *(char *)((char *)r_v0 + (3740)) = (char)0; }
    goto _lbl_01F6847C;
_lbl_01F68468:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_a0 = (long)(r_a0 + (1));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { *(int *)((char *)r_v0 + (5852)) = (int)0; }
_lbl_01F6847C:
    r_v0 = (long)((long)r_a0 < (long)(3) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F68468;
    r_a0 = (long)(0 | 0);
    goto _lbl_01F684A4;
_lbl_01F68490:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_a0 = (long)(r_a0 + (1));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { *(int *)((char *)r_v0 + (5864)) = (int)0; }
_lbl_01F684A4:
    r_v0 = (long)((long)r_a0 < (long)(2) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F68490;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (0x23));
    r_a0 = (long)(0 + (0x84));
    r_v1 = (long)(0 + (0xf4));
    if (r_v0) { *(int *)((char *)r_v0 + (5892)) = (int)r_a1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_t3 = (long)(0 + (0x35));
    r_t2 = (long)(0 + (0x86));
    r_t1 = (long)(0 + (0x14));
    if (r_v0) { *(int *)((char *)r_v0 + (5896)) = (int)r_a0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_t0 = (long)(0 + (0x15));
    r_a3 = (long)(0 + (0xf7));
    r_a2 = (long)(0 + (0x26));
    if (r_v0) { *(int *)((char *)r_v0 + (5904)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (0x75));
    r_a0 = (long)(0 + (0x66));
    r_v1 = (long)(0 + (0xa));
    if (r_v0) { *(int *)((char *)r_v0 + (5900)) = (int)r_t3; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_s3 = (long)(0 | 0);
    if (r_v0) { *(int *)((char *)r_v0 + (5908)) = (int)r_t2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5912)) = (int)r_t1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5916)) = (int)r_t0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5920)) = (int)r_a3; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5924)) = (int)r_a2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5928)) = (int)r_a1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5932)) = (int)r_a0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5936)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5940)) = (int)r_t2; }
    goto _lbl_01F68618;
_lbl_01F68550:
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(0 + (5));
    r_t0 = (long)(0 + (2));
    r_s2 = (long)((unsigned long)r_s3 << (2));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_v0 = (long)(r_a0 + r_s2);
    r_a2 = (long)(r_v0 + (0x16dc));
    r_t2 = (long)(0 + (0xa0));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (296)); }
    r_t3 = (long)(0 + (0x10));
    r_a3 = (long)(0 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_t1 = (long)(r_t0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 != 0) goto _lbl_01F685B4;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F685B4:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5852)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F6850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5852)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_002178A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5852)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_002178E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5852)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s3 = (long)(r_s3 + (1));
_lbl_01F68618:
    r_v0 = (long)((long)r_s3 < (long)(3) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F68550;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5852)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (260)); }
    r_a1 = (long)(0 + (0x4e99));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5856)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (260)); }
    r_a1 = (long)(0 + (0x4e9a));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5860)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (260)); }
    r_a1 = (long)(0 + (0x4e98));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s3 = (long)(0 | 0);
    goto _lbl_01F6873C;
_lbl_01F68674:
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(0 + (5));
    r_s2 = (long)((unsigned long)r_s3 << (2));
    r_t2 = (long)(0 + (0xa0));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_v0 = (long)(r_a0 + r_s2);
    r_a2 = (long)(r_v0 + (0x16e8));
    r_t3 = (long)(0 + (0x10));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (296)); }
    r_a3 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_t1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 != 0) goto _lbl_01F686D8;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F686D8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5864)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F6850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5864)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_002178E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5864)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_002178A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5864)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6873C:
    r_v0 = (long)((long)r_s3 < (long)(2) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F68674;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (0x4e9c));
    r_a2 = (long)(0 | 0);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5864)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (272)); }
    r_a3 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (0x4ea0));
    r_a2 = (long)(0 | 0);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5868)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (272)); }
    r_a3 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (0x22c));
    r_v0 = (long)(0x1f8 << 16);
    r_v1 = (long)(0 + (-1));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a3 = (long)(r_v0 + (-0x6ad0));
    r_a2 = (long)(r_a0 + (0x16f8));
    r_t1 = (long)(0 + (2));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (344)); }
    r_t2 = (long)(0 + (0x35));
    r_t3 = (long)(0 + (0x34));
    r_a1 = (long)(r_a0 | 0);
    r_t0 = (long)(0 | (0xc4a6));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 != 0) goto _lbl_01F687E8;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F687E8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (1));
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5880)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F6850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a0 = (long)(0 + (0x14));
    if (r_v0) { *(int *)((char *)r_v0 + (5944)) = (int)0; }
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68828; }
    r_s2 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6ad0));
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(0 | (0xc4a6));
    r_v0 = (long)func_0025D6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68828:
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(0 + (0x1a));
    r_v1 = (long)(0 + (-1));
    if (r_a0) { *(int *)((char *)r_a0 + (5944)) = (int)r_s2; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_a3 = (long)(r_v0 + (-0x6ac0));
    r_t1 = (long)(0 + (0x1f0));
    r_t2 = (long)(0 + (0x10));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a2 = (long)(r_a0 + (0x16f0));
    r_t3 = (long)(0 + (0x76));
    r_t0 = (long)(0 | (0xdbb3));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (344)); }
    r_a1 = (long)(r_a0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 != 0) goto _lbl_01F68890;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68890:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (1));
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5872)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F6850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_s2 = (long)(0 + (0x3a));
    r_v0 = (long)func_001880E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F688BC;
    r_s2 = (long)(r_s2 + (0x2c));
_lbl_01F688BC:
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_t0 = (long)(0 + (0x16));
    r_a3 = (long)(0 + (0xcc));
    r_v0 = (long)(0 + (2));
    r_a2 = (long)(r_a0 + (0x16d8));
    r_t2 = (long)(0 + (0x12));
    r_t1 = (long)(r_s2 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_t3 = (long)(r_a3 | 0);
    r_v0 = (long)func_001FA670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F68908;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68908:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5848)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5848)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0020DA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_s2 = (long)(0 + (0x128));
    r_v0 = (long)func_001880E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F68948;
    r_s2 = (long)(r_s2 + (0x16));
_lbl_01F68948:
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (0x16));
    r_v0 = (long)(0 + (2));
    r_a3 = (long)(0 + (0xfa2));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a2 = (long)(r_a0 + (0x16c4));
    r_t2 = (long)(0 + (0x12));
    r_t3 = (long)(0 + (0x62));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (276)); }
    r_t1 = (long)(r_s2 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_t0 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 != 0) { r_s2 = (long)(0 + (1)); goto _lbl_01F689AC; }
    r_s2 = (long)(0 + (1));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
    r_s2 = (long)(0 + (1));
_lbl_01F689AC:
    r_v0 = (long)((long)r_s2 < (long)(0xe) ? 1 : 0);
    goto _lbl_01F68A18;
_lbl_01F689B4:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_sp) { *(char *)((char *)r_sp + (160)) = (char)0; }
    if (r_sp) { *(char *)((char *)r_sp + (288)) = (char)0; }
    if (r_sp) { *(char *)((char *)r_sp + (416)) = (char)0; }
    r_a1 = (long)(0 + (0x69));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_t0 = (long)(r_sp + (0xa0));
    r_t1 = (long)(0 + (0x80));
    r_a2 = (long)(r_s2 | 0);
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (52)); }
    r_a3 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0x1f8 << 16);
    r_a0 = (long)(r_sp + (0x1a0));
    r_a1 = (long)(r_v0 + (-0x6ab0));
    r_a2 = (long)(r_sp + (0xa0));
    r_a3 = (long)(r_sp + (0x120));
    r_v0 = (long)func_0011A498((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(r_sp + (0x1a0));
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5848)); }
    r_a2 = (long)(r_s2 | 0);
    r_v0 = (long)func_0020DC00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s2 + (1));
    r_v0 = (long)((long)r_s2 < (long)(0xe) ? 1 : 0);
_lbl_01F68A18:
    if (r_v0 != 0) goto _lbl_01F689B4;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5848)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_0020DA80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x82c));
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68A4C; }
    r_s2 = (long)(r_v0 | 0);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (156)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F75230((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68A4C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5844)) = (int)r_s2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5844)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (1));
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5844)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F6850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)(0 + (0xa));
    r_t1 = (long)(0 + (0x1f4));
    r_t2 = (long)(0 + (0x32));
    r_a2 = (long)(r_a0 + (0x16d0));
    r_t3 = (long)(0 + (2));
    r_a3 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_v0 = (long)func_01F743E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5840)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (1));
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5840)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F6850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3636)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (5968)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5840)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (5960)); }
    r_v0 = (long)func_01F75210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (5828)); }
    r_v0 = (long)func_001F6750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (5828)); }
    if (r_v0 == 0) { r_v1 = (long)(0 | 0); goto _lbl_01F68B2C; }
    r_v1 = (long)(0 | 0);
    r_v1 = (long)(r_v1 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (544)) = (int)r_v0; }
_lbl_01F68B2C:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (5848)); }
    if (r_a1 == 0) goto _lbl_01F68B48;
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_sp);
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (544)) = (int)r_a1; }
_lbl_01F68B48:
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a1 = (long)(r_sp + (0x220));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (224)); }
    r_a3 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    if (r_v0 == 0) goto _lbl_01F68B8C;
    /* unhandled: lwc1 $f0 0xc6c($v0) */
    /* unhandled: swc1 $f0 0xe0c($v1) */
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (2100)); }
    /* unhandled: lwc1 $f0 0xc70($v0) */
    /* unhandled: swc1 $f0 0xe10($v1) */
_lbl_01F68B8C:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_v0) { r_s2 = *(int *)((char *)r_v0 + (5224)); }
    if (r_s2 != 0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01F68D04; }
    r_a0 = (long)(r_s2 | 0);
    r_a0 = (long)(0 + (0x14));
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68BC0; }
    r_s2 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6aa8));
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(0 | (0xc629));
    r_v0 = (long)func_0025D6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68BC0:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5796)) = (int)r_s2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5796)); }
    if (r_a0 == 0) { r_a0 = (long)(0 + (0x14)); goto _lbl_01F68C14; }
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (19)); }
    if (r_v0 != 0) goto _lbl_01F68C10;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (5796)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68C10:
    r_a0 = (long)(0 + (0x14));
_lbl_01F68C14:
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68C38; }
    r_s2 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a98));
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(0 | (0xc62a));
    r_v0 = (long)func_0025D6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68C38:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5800)) = (int)r_s2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5800)); }
    if (r_a0 == 0) { r_a0 = (long)(0 + (0x14)); goto _lbl_01F68C8C; }
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (19)); }
    if (r_v0 != 0) goto _lbl_01F68C88;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (5800)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68C88:
    r_a0 = (long)(0 + (0x14));
_lbl_01F68C8C:
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68CB0; }
    r_s2 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a88));
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(0 | (0xc612));
    r_v0 = (long)func_0025D6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68CB0:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5804)) = (int)r_s2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5804)); }
    if (r_a0 == 0) { r_a0 = (long)(0 + (0x14)); goto _lbl_01F68DA0; }
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (19)); }
    if (r_v0 != 0) goto _lbl_01F68D9C;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (5804)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
    r_a0 = (long)(r_s2 | 0);
_lbl_01F68D04:
    r_v0 = (long)func_00252CE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { *(int *)((char *)r_v1 + (5796)) = (int)r_v0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (5796)); }
    if (r_v0 != 0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01F68D38; }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)(0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (244)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
    r_a0 = (long)(r_s2 | 0);
_lbl_01F68D38:
    r_v0 = (long)func_00252CF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { *(int *)((char *)r_v1 + (5800)) = (int)r_v0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (5800)); }
    if (r_v0 != 0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01F68D6C; }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)(0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (244)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
    r_a0 = (long)(r_s2 | 0);
_lbl_01F68D6C:
    r_v0 = (long)func_00252CA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { *(int *)((char *)r_v1 + (5804)) = (int)r_v0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (5804)); }
    if (r_v0 != 0) goto _lbl_01F68D9C;
    r_v0 = (long)(0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (244)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68D9C:
    r_a0 = (long)(0 + (0x14));
_lbl_01F68DA0:
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68DC4; }
    r_s2 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a78));
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(0 | (0xc4a3));
    r_v0 = (long)func_0025D6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68DC4:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5808)) = (int)r_s2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5808)); }
    if (r_a0 == 0) { r_a0 = (long)(0 + (0x14)); goto _lbl_01F68E04; }
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (19)); }
    if (r_v0 != 0) goto _lbl_01F68E00;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5808)) = (int)0; }
_lbl_01F68E00:
    r_a0 = (long)(0 + (0x14));
_lbl_01F68E04:
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68E28; }
    r_s2 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a68));
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(0 | (0xc4a5));
    r_v0 = (long)func_0025D6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68E28:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5812)) = (int)r_s2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5812)); }
    if (r_a0 == 0) { r_a0 = (long)(0 + (0x14)); goto _lbl_01F68E7C; }
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (19)); }
    if (r_v0 != 0) goto _lbl_01F68E78;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (5812)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68E78:
    r_a0 = (long)(0 + (0x14));
_lbl_01F68E7C:
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68EA0; }
    r_s2 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a58));
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(0 | (0xdac7));
    r_v0 = (long)func_0025D6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68EA0:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5816)) = (int)r_s2; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5816)); }
    if (r_a0 == 0) { r_a0 = (long)(0 + (0x14)); goto _lbl_01F68EF4; }
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (19)); }
    if (r_v0 != 0) goto _lbl_01F68EF0;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (5816)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68EF0:
    r_a0 = (long)(0 + (0x14));
_lbl_01F68EF4:
    r_v0 = (long)func_0025F2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_v0 | 0); goto _lbl_01F68F18; }
    r_s2 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a48));
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(0 | (0xdacc));
    r_v0 = (long)func_0025D6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F68F18:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (5820)) = (int)r_s2; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (5820)); }
    if (r_a0 == 0) { r_v0 = (long)(0 + (0x96)); goto _lbl_01F68F6C; }
    r_v0 = (long)(0 + (0x96));
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (19)); }
    if (r_v0 != 0) goto _lbl_01F68F68;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (5820)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F68F68:
    r_v0 = (long)(0 + (0x96));
_lbl_01F68F6C:
    if (r_v1) { *(int *)((char *)r_v1 + (3676)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (0x2e2));
    r_t1 = (long)(0 + (0x24));
    r_a2 = (long)(0 + (0x1f));
    if (r_v0) { *(int *)((char *)r_v0 + (3680)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 + (0x4a));
    r_a0 = (long)(0 + (0x13));
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (3684)) = (int)r_a2; }
    if (r_sp) { r_a2 = *(int *)((char *)r_sp + (156)); }
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (3684)); }
    r_v0 = (long)(r_v0 + (0xa4));
    if (r_a2) { *(int *)((char *)r_a2 + (3728)) = (int)r_v0; }
    if (r_sp) { r_a2 = *(int *)((char *)r_sp + (156)); }
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (3684)); }
    if (r_a2) { *(int *)((char *)r_a2 + (3732)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3644)) = (int)r_a1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3648)) = (int)r_a1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3652)) = (int)r_a1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3656)) = (int)r_a1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3660)) = (int)r_t1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3664)) = (int)r_t1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3668)) = (int)r_a0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3672)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5840)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (5804)); }
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (5796)); }
    if (r_v0) { r_a3 = *(int *)((char *)r_v0 + (5800)); }
    if (r_v0) { r_t0 = *(int *)((char *)r_v0 + (5808)); }
    r_t2 = (long)(r_t1 | 0);
    r_v0 = (long)func_01F74C80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3532)) = (int)r_s1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3536)) = (int)r_s0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (12)); }
    if (r_v1) { *(int *)((char *)r_v1 + (3540)) = (int)r_v0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (16)); }
    if (r_v1) { *(int *)((char *)r_v1 + (3544)) = (int)r_v0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_v0 = (long)func_01F69FC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    if (r_v0 != 0) { if (r_v1) { *(int *)((char *)r_v1 + (3736)) = (int)r_v0; } goto _lbl_01F69064; }
    if (r_v1) { *(int *)((char *)r_v1 + (3736)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (244)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    goto _lbl_01F690AC;
_lbl_01F69064:
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (156)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_01F73C90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (156)); }
    r_a0 = (long)(0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (3632)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(int *)((char *)r_v0 + (3556)) = (int)0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    if (r_v0) { *(char *)((char *)r_v0 + (124)) = (char)r_a0; }
    r_v0 = (long)func_0021FEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
    r_a0 = (long)(r_v0 + (0x173c));
    r_v0 = (long)func_00225560((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (156)); }
_lbl_01F690AC:
    /* unhandled: xori.b $w2 $w0 0xbf */
    /* unhandled: ld.b $w1 -0x4d($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w18 */
    /* unhandled: xori.b $w1 $w0 0xb1 */
    r_sp = (long)(r_sp + (0x240));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 2: thelp_func_01F690CC (VMA: 0x01F690CC, size: 840 bytes) */
void *thelp_func_01F690CC(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x40));
    /* unhandled: dpa.w.ph $ac0 $sp $ra */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s1 = (long)(r_a0 | 0);
    if (r_s1 == 0) { r_s0 = (long)(r_a1 | 0); goto _lbl_01F693F8; }
    r_s0 = (long)(r_a1 | 0);
    r_v0 = (long)(0x4e << 16);
    r_v0 = (long)(r_v0 + (0x23e0));
    if (r_s1) { *(int *)((char *)r_s1 + (0)) = (int)r_v0; }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2100)); }
    if (r_a0 == 0) goto _lbl_01F69140;
    /* unhandled: lwc1 $f12 0xe0c($s1) */
    /* unhandled: mtc1 $zero $f0 */
    /* unhandled: c.olt.s $f12 $f0 */
    /* unhandled: bc1t 0x1f69140 */
    /* unhandled: lwc1 $f13 0xe10($s1) */
    /* unhandled: c.olt.s $f13 $f0 */
    /* unhandled: bc1t 0x1f69140 */
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00204920((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F69140:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2076)); }
    if (r_a0 == 0) goto _lbl_01F69158;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (2076)) = (int)0; }
_lbl_01F69158:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2084)); }
    if (r_a0 == 0) goto _lbl_01F69170;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (2084)) = (int)0; }
_lbl_01F69170:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    if (r_a0 == 0) goto _lbl_01F69188;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_01F75F60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (2092)) = (int)0; }
_lbl_01F69188:
    if (r_s1) { r_s2 = *(int *)((char *)r_s1 + (2108)); }
    goto _lbl_01F6919C;
    r_a0 = (long)(r_s2 | 0);
_lbl_01F69194:
    if (r_s2) { r_s2 = *(int *)((char *)r_s2 + (92)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6919C:
    if (r_s2 != 0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01F69194; }
    r_a0 = (long)(r_s2 | 0);
    if (r_s1) { *(int *)((char *)r_s1 + (2108)) = (int)0; }
    if (r_s1) { r_s2 = *(int *)((char *)r_s1 + (2116)); }
    goto _lbl_01F691BC;
    r_a0 = (long)(r_s2 | 0);
_lbl_01F691B4:
    if (r_s2) { r_s2 = *(int *)((char *)r_s2 + (1332)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F691BC:
    if (r_s2 != 0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01F691B4; }
    r_a0 = (long)(r_s2 | 0);
    if (r_s1) { *(int *)((char *)r_s1 + (2116)) = (int)0; }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5808)); }
    if (r_a0 == 0) goto _lbl_01F691E0;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5808)) = (int)0; }
_lbl_01F691E0:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5812)); }
    if (r_a0 == 0) goto _lbl_01F691F8;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5812)) = (int)0; }
_lbl_01F691F8:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5816)); }
    if (r_a0 == 0) goto _lbl_01F69210;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5816)) = (int)0; }
_lbl_01F69210:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5820)); }
    if (r_a0 == 0) goto _lbl_01F69228;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5820)) = (int)0; }
_lbl_01F69228:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5824)); }
    if (r_a0 == 0) goto _lbl_01F69240;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5824)) = (int)0; }
_lbl_01F69240:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5944)); }
    if (r_a0 == 0) goto _lbl_01F69258;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5944)) = (int)0; }
_lbl_01F69258:
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (5224)); }
    if (r_v0 != 0) { r_a1 = (long)(r_s1 + (0x16c4)); goto _lbl_01F692B4; }
    r_a1 = (long)(r_s1 + (0x16c4));
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5796)); }
    if (r_a0 == 0) goto _lbl_01F69280;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5796)) = (int)0; }
_lbl_01F69280:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5800)); }
    if (r_a0 == 0) goto _lbl_01F69298;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5800)) = (int)0; }
_lbl_01F69298:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5804)); }
    if (r_a0 == 0) goto _lbl_01F692B0;
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_0025DE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5804)) = (int)0; }
_lbl_01F692B0:
    r_a1 = (long)(r_s1 + (0x16c4));
_lbl_01F692B4:
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s1 + (0x16c8));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s1 + (0x16cc));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s1 + (0x16d8));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5840)); }
    if (r_a0 == 0) { r_a1 = (long)(r_s1 + (0x16d0)); goto _lbl_01F69300; }
    r_a1 = (long)(r_s1 + (0x16d0));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a1 = (long)(r_s1 + (0x16d0));
_lbl_01F69300:
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (5844)); }
    if (r_a0 == 0) { r_a1 = (long)(r_s1 + (0x16d4)); goto _lbl_01F69328; }
    r_a1 = (long)(r_s1 + (0x16d4));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a1 = (long)(r_s1 + (0x16d4));
_lbl_01F69328:
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s1 + (0x16f4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s1 + (0x16f0));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s1 + (0x16f8));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(0 | 0);
    goto _lbl_01F69374;
    r_v0 = (long)((unsigned long)r_s2 << (2));
_lbl_01F69360:
    r_v0 = (long)(r_s1 + r_v0);
    r_a1 = (long)(r_v0 + (0x16dc));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s2 + (1));
_lbl_01F69374:
    r_v0 = (long)((long)r_s2 < (long)(3) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (2)); goto _lbl_01F69360; }
    r_v0 = (long)((unsigned long)r_s2 << (2));
    r_s2 = (long)(0 | 0);
    goto _lbl_01F693A0;
    r_v0 = (long)((unsigned long)r_s2 << (2));
_lbl_01F6938C:
    r_v0 = (long)(r_s1 + r_v0);
    r_a1 = (long)(r_v0 + (0x16e8));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s2 + (1));
_lbl_01F693A0:
    r_v0 = (long)((long)r_s2 < (long)(2) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (2)); goto _lbl_01F6938C; }
    r_v0 = (long)((unsigned long)r_s2 << (2));
    r_a0 = (long)(r_s1 | 0);
    if (r_s1) { *(int *)((char *)r_s1 + (2088)) = (int)0; }
    r_v0 = (long)func_01F758F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F75840((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 | 0);
    r_v0 = (long)func_0021FEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_001861C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00215950((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 <= 0) { r_v0 = (long)(r_s1 | 0); goto _lbl_01F693FC; }
    r_v0 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F693F8:
    r_v0 = (long)(r_s1 | 0);
_lbl_01F693FC:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 3: thelp_func_01F69414 (VMA: 0x01F69414, size: 104 bytes) */
void *thelp_func_01F69414(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (5888)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (5884)); }
    r_v0 = (long)func_002257C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2088)); }
    r_v0 = (long)func_001F6CD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)(0xa8 << 16);
    r_a0 = (long)(r_v0 + (0xbb0));
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F2900((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0xa8 << 16);
    r_a0 = (long)(r_v0 + (0xbb0));
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6b00));
    r_v0 = (long)func_001F2CB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 4: thelp_func_01F6947C (VMA: 0x01F6947C, size: 772 bytes) */
void *thelp_func_01F6947C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t9 = 0;
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
    (void)r_t0;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x70));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s3 = (long)(r_a1 | 0);
    r_s4 = (long)(r_a0 | 0);
    r_s2 = (long)(r_a2 | 0);
    r_s1 = (long)(r_a3 | 0);
    if (r_s3 != 0) { r_s0 = (long)(r_t0 | 0); goto _lbl_01F694C8; }
    r_s0 = (long)(r_t0 | 0);
    r_v0 = (long)func_001F6460((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: ld.b $w1 -0x41($zero) */
    goto _lbl_01F69760;
_lbl_01F694C8:
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_001F6CD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6957C;
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_001F6CD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a30));
    r_v0 = (long)func_0011AA78((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F6957C;
    r_v0 = (long)(0xa8 << 16);
    r_a0 = (long)(r_v0 + (0xbb0));
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6b00));
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F2900((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0xa8 << 16);
    r_a0 = (long)(r_v0 + (0xbb0));
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a30));
    r_v0 = (long)func_001F2CB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 != 0) goto _lbl_01F6953C;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_00185D40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F69574;
_lbl_01F6953C:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_001880D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6956C;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2848)); }
    if (r_v0 != 0) goto _lbl_01F6956C;
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_00185F00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6956C:
    if (r_s4) { *(int *)((char *)r_s4 + (3560)) = (int)0; }
    r_v0 = (long)(0 + (1));
_lbl_01F69574:
    goto _lbl_01F6975C;
_lbl_01F6957C:
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (5840)); }
    if (r_s3 != r_v0) goto _lbl_01F695DC;
    if (r_s2 != 0) goto _lbl_01F695DC;
    if (r_s4) { *(int *)((char *)r_s4 + (3636)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3640)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3604)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3612)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3624)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3628)) = (int)0; }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5840)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s4) { *(int *)((char *)r_s4 + (3556)) = (int)0; }
    if (r_s4) { r_t9 = *(int *)((char *)r_s4 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s4 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (1));
    goto _lbl_01F6975C;
_lbl_01F695DC:
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (5844)); }
    if (r_s3 != r_v0) goto _lbl_01F69628;
    if (r_s2 != 0) goto _lbl_01F69628;
    if (r_s4) { *(int *)((char *)r_s4 + (3612)) = (int)0; }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5844)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s4) { *(int *)((char *)r_s4 + (3556)) = (int)0; }
    if (r_s4) { r_t9 = *(int *)((char *)r_s4 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s4 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (1));
    goto _lbl_01F6975C;
_lbl_01F69628:
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (5828)); }
    if (r_s3 != r_v0) { r_v0 = (long)(0 + (2)); goto _lbl_01F69688; }
    r_v0 = (long)(0 + (2));
    r_v0 = (long)(0 + (1));
    if (r_s2 != r_v0) goto _lbl_01F69684;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_001880D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) { r_a0 = (long)(r_s4 | 0); goto _lbl_01F69674; }
    r_a0 = (long)(r_s4 | 0);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2848)); }
    if (r_v0 != 0) goto _lbl_01F69670;
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_00185F00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F69670:
    r_a0 = (long)(r_s4 | 0);
_lbl_01F69674:
    r_v0 = (long)func_01F694A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F6975C;
_lbl_01F69684:
    r_v0 = (long)(0 + (2));
_lbl_01F69688:
    if (r_s2 != r_v0) { r_a0 = (long)(r_s4 | 0); goto _lbl_01F69748; }
    r_a0 = (long)(r_s4 | 0);
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5848)); }
    if (r_s3 != r_a0) goto _lbl_01F69744;
    r_v0 = (long)func_0020DDC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (2104)); }
    if (r_v0 == r_s5) goto _lbl_01F69744;
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (2092)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_01F75F60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s4 | 0);
    if (r_s4) { *(int *)((char *)r_s4 + (2092)) = (int)0; }
    r_v0 = (long)func_01F758F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F758A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F75930((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { *(int *)((char *)r_s4 + (2096)) = (int)r_v0; }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (2096)); }
    if (r_v0 == 0) { r_a0 = (long)(r_s4 | 0); goto _lbl_01F69738; }
    r_a0 = (long)(r_s4 | 0);
    if (r_s4) { *(int *)((char *)r_s4 + (2104)) = (int)r_s5; }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (2096)); }
    r_a1 = (long)(0 + (5));
    if (r_s4) { *(int *)((char *)r_s4 + (2092)) = (int)r_v0; }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (2092)); }
    r_a2 = (long)(0 + (3));
    r_v0 = (long)func_01F77800((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { *(int *)((char *)r_s4 + (2096)) = (int)0; }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (5968)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5840)); }
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (5960)); }
    r_v0 = (long)func_01F75210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F69FC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { *(int *)((char *)r_s4 + (3736)) = (int)r_v0; }
    goto _lbl_01F69744;
    r_a0 = (long)(r_s4 | 0);
_lbl_01F69738:
    r_v0 = (long)func_01F69FC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { *(int *)((char *)r_s4 + (3736)) = (int)r_v0; }
_lbl_01F69744:
    r_a0 = (long)(r_s4 | 0);
_lbl_01F69748:
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6460((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6975C:
    /* unhandled: ld.b $w1 -0x41($zero) */
_lbl_01F69760:
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 5: thelp_func_01F69780 (VMA: 0x01F69780, size: 244 bytes) */
void *thelp_func_01F69780(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x40));
    /* unhandled: dpa.w.ph $ac0 $sp $ra */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_v0 = (long)(0 + (4));
    r_v1 = (long)(r_a1 & (0xff));
    r_s0 = (long)(r_a0 | 0);
    r_s2 = (long)(r_a2 | 0);
    if (r_v1 == r_v0) { r_s1 = (long)(r_a3 | 0); goto _lbl_01F697B8; }
    r_s1 = (long)(r_a3 | 0);
    r_v0 = (long)(0 + (2));
    if (r_v1 != r_v0) { r_a0 = (long)(r_s0 | 0); goto _lbl_01F69850; }
    r_a0 = (long)(r_s0 | 0);
_lbl_01F697B8:
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (3612)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) goto _lbl_01F6984C;
    r_a0 = (long)(r_s0 | 0);
    r_a1 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F73780((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (1));
    if (r_v0 != r_a1) goto _lbl_01F6982C;
    if (r_s0) { *(int *)((char *)r_s0 + (3612)) = (int)r_a1; }
    if (r_s0) { *(int *)((char *)r_s0 + (3636)) = (int)r_a1; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (3604)); }
    if (r_s0) { *(int *)((char *)r_s0 + (3640)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (3620)) = (int)0; }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (5840)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s0) { *(int *)((char *)r_s0 + (3556)) = (int)0; }
    if (r_s0) { r_t9 = *(int *)((char *)r_s0 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (1));
    goto _lbl_01F6985C;
_lbl_01F6982C:
    if (r_s0) { *(int *)((char *)r_s0 + (3612)) = (int)r_a1; }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (5844)); }
    r_a1 = (long)(r_s0 + (0xe9c));
    r_a2 = (long)(r_s2 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F75420((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F6985C;
_lbl_01F6984C:
    r_a0 = (long)(r_s0 | 0);
_lbl_01F69850:
    r_a2 = (long)(r_s2 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F8190((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6985C:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 6: thelp_func_01F69874 (VMA: 0x01F69874, size: 196 bytes) */
void *thelp_func_01F69874(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x60));
    /* unhandled: subu.qb $zero $sp $ra */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { *(int *)((char *)r_a0 + (3620)) = (int)0; }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3636)); }
    r_s1 = (long)(r_a3 | 0);
    r_s0 = (long)(r_t0 | 0);
    r_s4 = (long)(r_a0 | 0);
    r_s3 = (long)(r_a1 | 0);
    if (r_v0 == 0) { r_s2 = (long)(r_a2 | 0); goto _lbl_01F69900; }
    r_s2 = (long)(r_a2 | 0);
    r_v0 = (long)func_01F734C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3604)); }
    if (r_v0 == r_v1) { r_a0 = (long)(r_s4 | 0); goto _lbl_01F69904; }
    r_a0 = (long)(r_s4 | 0);
    if (r_s4) { *(int *)((char *)r_s4 + (3636)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3640)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3604)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3620)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3624)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3628)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3556)) = (int)0; }
    if (r_s4) { r_t9 = *(int *)((char *)r_s4 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s4 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F69900:
    r_a0 = (long)(r_s4 | 0);
_lbl_01F69904:
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001FBF30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 7: thelp_func_01F69938 (VMA: 0x01F69938, size: 232 bytes) */
void *thelp_func_01F69938(void *a0, void *a1, void *a2, void *a3) {
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
    r_sp = (long)(r_sp + (-0x130));
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_v0 = (long)(0 + (0x1b));
    r_s0 = (long)(r_a1 | 0);
    if (r_s0 != r_v0) { r_s1 = (long)(r_a0 | 0); goto _lbl_01F699A4; }
    r_s1 = (long)(r_a0 | 0);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_001880D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) { r_a0 = (long)(0 + (0x4015)); goto _lbl_01F69994; }
    r_a0 = (long)(0 + (0x4015));
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2848)); }
    if (r_v0 != 0) goto _lbl_01F69990;
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_00185F00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F69990:
    r_a0 = (long)(0 + (0x4015));
_lbl_01F69994:
    r_v0 = (long)func_0025D060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F694A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F699A4:
    r_a0 = (long)(r_sp + (0x30));
    r_v0 = (long)func_0036DDF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (202)); }
    if (r_v0 != 0) goto _lbl_01F69A08;
    r_v0 = (long)(0 + (0x25));
    if (r_s0 == r_v0) goto _lbl_01F699D0;
    r_v0 = (long)(0 + (0x27));
    if (r_s0 != r_v0) goto _lbl_01F69A08;
_lbl_01F699D0:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (60)); }
    if (r_s1) { r_s0 = *(int *)((char *)r_s1 + (5828)); }
    if (r_v0 != r_s0) goto _lbl_01F699E8;
    if (r_s1) { r_s0 = *(int *)((char *)r_s1 + (5848)); }
_lbl_01F699E8:
    r_a0 = (long)(0 + (0x40ff));
    r_v0 = (long)func_0025D060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F86F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F69A08:
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_v0 = (long)(0 | 0);
    r_sp = (long)(r_sp + (0x130));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 8: thelp_func_01F69A20 (VMA: 0x01F69A20, size: 380 bytes) */
void *thelp_func_01F69A20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x50));
    /* unhandled: dpa.w.ph $ac0 $sp $ra */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s2 = (long)(r_a0 | 0);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (496)); }
    if (r_v0 != 0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01F69A54; }
    r_v0 = (long)func_001886B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 | 0);
_lbl_01F69A54:
    r_v0 = (long)func_01F73000((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F69C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x48));
    r_v0 = (long)func_00225560((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v1 = *(int *)((char *)r_gp + (-30272)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (72)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (3620)); }
    if (r_sp) { r_s1 = *(int *)((char *)r_sp + (76)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (40)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (136)); }
    if (r_a0 != 0) { r_s0 = (long)(r_v0 - r_v1); goto _lbl_01F69AF0; }
    r_s0 = (long)(r_v0 - r_v1);
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (3624)); }
    if (r_v0 != r_s0) goto _lbl_01F69AE4;
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (3628)); }
    if (r_v0 != r_s1) goto _lbl_01F69AE4;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3612)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01F69B5C; }
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(r_s0 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F734C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F69B58;
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { *(int *)((char *)r_s2 + (3616)) = (int)r_v0; }
    r_v0 = (long)(0 + (1));
    if (r_s2) { *(int *)((char *)r_s2 + (3620)) = (int)r_v0; }
    goto _lbl_01F69B58;
_lbl_01F69AE4:
    if (r_s2) { *(int *)((char *)r_s2 + (3624)) = (int)r_s0; }
    if (r_s2) { *(int *)((char *)r_s2 + (3628)) = (int)r_s1; }
    goto _lbl_01F69B58;
_lbl_01F69AF0:
    r_v0 = (long)(0 + (1));
    if (r_a0 != r_v0) goto _lbl_01F69B58;
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3616)); }
    r_v0 = (long)(r_v0 - r_v1);
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x1f4) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F69B58;
    r_v0 = (long)(0 + (1));
    if (r_s2) { *(int *)((char *)r_s2 + (3636)) = (int)r_v0; }
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(r_s0 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F734C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { *(int *)((char *)r_s2 + (3640)) = (int)r_v0; }
    if (r_s2) { *(int *)((char *)r_s2 + (3620)) = (int)0; }
    if (r_s2) { *(int *)((char *)r_s2 + (3624)) = (int)r_s0; }
    if (r_s2) { *(int *)((char *)r_s2 + (3628)) = (int)r_s1; }
    if (r_s2) { *(int *)((char *)r_s2 + (3556)) = (int)0; }
    if (r_s2) { r_t9 = *(int *)((char *)r_s2 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s2 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F69B58:
    r_a0 = (long)(r_s2 | 0);
_lbl_01F69B5C:
    r_v0 = (long)func_001F8140((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2088)); }
    if (r_a0 == 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01F69B80; }
    r_s0 = (long)(r_v0 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (84)); }
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F69B80:
    r_v0 = (long)(r_s0 | 0);
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 9: thelp_func_01F69B9C (VMA: 0x01F69B9C, size: 904 bytes) */
void *thelp_func_01F69B9C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t9 = 0;
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
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x170));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (144)); }
    if (r_v0 == 0) { r_s5 = (long)(r_a0 | 0); goto _lbl_01F69C08; }
    r_s5 = (long)(r_a0 | 0);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (60)); }
    if (r_a0 == 0) goto _lbl_01F69C14;
    r_v0 = (long)func_001F6CD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F69C14;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (60)); }
    r_v0 = (long)func_001F6CD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a30));
    r_v0 = (long)func_0011AA78((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F69C14;
_lbl_01F69C08:
    if (r_s5) { *(int *)((char *)r_s5 + (3564)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F69F00;
_lbl_01F69C14:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (5848)); }
    r_v0 = (long)(0 + (2));
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (300)); }
    if (r_v1 != r_v0) goto _lbl_01F69C34;
    if (r_s5) { *(int *)((char *)r_s5 + (3564)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F69F00;
_lbl_01F69C34:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5840)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (132)); }
    if (r_v0 != 0) goto _lbl_01F69C54;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5844)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (132)); }
    if (r_v0 == 0) { r_a0 = (long)(r_sp + (0x70)); goto _lbl_01F69C64; }
    r_a0 = (long)(r_sp + (0x70));
_lbl_01F69C54:
    if (r_s5) { *(int *)((char *)r_s5 + (3564)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F69F00;
    r_a0 = (long)(r_sp + (0x70));
_lbl_01F69C64:
    r_v0 = (long)func_0036DDF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (266)); }
    r_s0 = (long)(0 | 0);
    r_s1 = (long)(0 | 0);
    if (r_v0 != 0) { r_s2 = (long)(0 | 0); goto _lbl_01F69C8C; }
    r_s2 = (long)(0 | 0);
    if (r_s5) { *(int *)((char *)r_s5 + (3564)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F69F00;
_lbl_01F69C8C:
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (149)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) goto _lbl_01F69CAC;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F69CC8;
_lbl_01F69CAC:
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (151)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) goto _lbl_01F69CC8;
    r_v0 = (long)(0 + (1));
_lbl_01F69CC8:
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (150)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) goto _lbl_01F69CE8;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F69D04;
_lbl_01F69CE8:
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (152)); }
    r_at = (long)((long)r_v0 < (long)(2) ? 1 : 0);
    if (r_at != 0) goto _lbl_01F69D04;
    r_v0 = (long)(0 + (1));
_lbl_01F69D04:
    if (r_s1 != 0) goto _lbl_01F69D14;
    if (r_s2 == 0) goto _lbl_01F69E64;
_lbl_01F69D14:
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3568)); }
    if (r_s5) { r_s4 = *(int *)((char *)r_s5 + (3564)); }
    if (r_s4 == 0) { r_a2 = (long)(r_s3 - r_v0); goto _lbl_01F69D3C; }
    r_a2 = (long)(r_s3 - r_v0);
    r_v0 = (long)((unsigned long)r_a2 < (unsigned long)(0x1b) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F69E64;
_lbl_01F69D3C:
    if ((long)r_a2 < 0) { r_v1 = (long)((unsigned long)r_a2 >> (1)); goto _lbl_01F69D54; }
    r_v1 = (long)((unsigned long)r_a2 >> (1));
    /* unhandled: mtc1 $a2 $f0 */
    /* unhandled: cvt.s.w $f1 $f0 */
    goto _lbl_01F69D6C;
    r_v1 = (long)((unsigned long)r_a2 >> (1));
_lbl_01F69D54:
    r_v0 = (long)(r_a2 & (1));
    r_v1 = (long)(r_v1 | r_v0);
    /* unhandled: mtc1 $v1 $f0 */
    /* unhandled: cvt.s.w $f1 $f0 */
    /* unhandled: add.s $f1 $f1 $f1 */
_lbl_01F69D6C:
    r_v0 = (long)(0x41d8 << 16);
    /* unhandled: mtc1 $v0 $f0 */
    /* unhandled: div.s $f1 $f1 $f0 */
    r_v0 = (long)(0x4200 << 16);
    /* unhandled: mtc1 $v0 $f0 */
    /* unhandled: mul.s $f12 $f0 $f1 */
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    r_at = (long)((long)r_s0 < (long)(0x81) ? 1 : 0);
    if (r_at != 0) goto _lbl_01F69DA0;
    r_s0 = (long)(0 + (0x80));
_lbl_01F69DA0:
    if (r_s4 != 0) goto _lbl_01F69DB4;
    r_v0 = (long)(0 + (1));
    if (r_s5) { *(int *)((char *)r_s5 + (3564)) = (int)r_v0; }
_lbl_01F69DB4:
    if (r_s5) { *(int *)((char *)r_s5 + (3584)) = (int)0; }
    r_v0 = (long)(0 + (-1));
    if (r_v1 != r_v0) { if (r_s5) { *(int *)((char *)r_s5 + (3580)) = (int)0; } goto _lbl_01F69DE4; }
    if (r_s5) { *(int *)((char *)r_s5 + (3580)) = (int)0; }
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F6FCF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { *(int *)((char *)r_s5 + (3584)) = (int)r_v0; }
    r_v0 = (long)(0 + (1));
    if (r_s5) { *(int *)((char *)r_s5 + (3588)) = (int)r_v0; }
    goto _lbl_01F69E08;
_lbl_01F69DE4:
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F69E0C;
    /* unhandled: negu $a1 $s0 */
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F6FCF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { *(int *)((char *)r_s5 + (3584)) = (int)r_v0; }
    r_v0 = (long)(0 + (2));
    if (r_s5) { *(int *)((char *)r_s5 + (3588)) = (int)r_v0; }
_lbl_01F69E08:
_lbl_01F69E0C:
    r_v0 = (long)(0 + (-1));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F69E3C; }
    r_v0 = (long)(0 + (1));
    r_a1 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F6FD40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { *(int *)((char *)r_s5 + (3580)) = (int)r_v0; }
    r_v0 = (long)(0 + (3));
    if (r_s5) { *(int *)((char *)r_s5 + (3592)) = (int)r_v0; }
    goto _lbl_01F69E5C;
    r_v0 = (long)(0 + (1));
_lbl_01F69E3C:
    if (r_v1 != r_v0) { r_s0 = (long)(0 + (1)); goto _lbl_01F69E60; }
    /* unhandled: negu $a1 $s0 */
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F6FD40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { *(int *)((char *)r_s5 + (3580)) = (int)r_v0; }
    r_v0 = (long)(0 + (4));
    if (r_s5) { *(int *)((char *)r_s5 + (3592)) = (int)r_v0; }
_lbl_01F69E5C:
    r_s0 = (long)(0 + (1));
_lbl_01F69E60:
    if (r_s5) { *(int *)((char *)r_s5 + (3568)) = (int)r_s3; }
_lbl_01F69E64:
    if (r_s1 != 0) goto _lbl_01F69E78;
    if (r_s2 != 0) goto _lbl_01F69E78;
    if (r_s5) { *(int *)((char *)r_s5 + (3564)) = (int)0; }
_lbl_01F69E78:
    if (r_s0 == 0) { r_v0 = (long)(r_s0 | 0); goto _lbl_01F69F00; }
    r_v0 = (long)(r_s0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3580)); }
    if ((long)r_v0 > 0) goto _lbl_01F69E98;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3584)); }
    if ((long)r_v0 <= 0) goto _lbl_01F69EFC;
_lbl_01F69E98:
    if (r_s5) { *(int *)((char *)r_s5 + (3620)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (3604)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (3636)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (3640)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (3624)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (3628)) = (int)0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3612)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F69EE0;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5840)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s5) { *(int *)((char *)r_s5 + (3556)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (3612)) = (int)0; }
    goto _lbl_01F69EE4;
_lbl_01F69EE0:
    if (r_s5) { *(int *)((char *)r_s5 + (3556)) = (int)r_v0; }
_lbl_01F69EE4:
    if (r_s5) { *(int *)((char *)r_s5 + (3608)) = (int)0; }
    if (r_s5) { r_t9 = *(int *)((char *)r_s5 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s5 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F69EFC:
    r_v0 = (long)(r_s0 | 0);
_lbl_01F69F00:
    /* unhandled: ld.b $w1 -0x41($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x170));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 10: thelp_func_01F69F24 (VMA: 0x01F69F24, size: 712 bytes) */
void *thelp_func_01F69F24(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t9;
    r_a2 = (long)(r_t1 | 0);
    r_a3 = (long)(r_t2 | 0);
    r_t0 = (long)(r_t3 | 0);
    return (void *)0x215A00;
    r_sp = (long)(r_sp + (-0x20));
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2092)); }
    if (r_v0 != 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01F69F60; }
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6A1DC;
_lbl_01F69F60:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2104)); }
    if ((long)r_v0 >= 0) goto _lbl_01F69F74;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6A1DC;
_lbl_01F69F74:
    r_v0 = (long)func_01F6A3A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2104)); }
    r_at = (long)((unsigned long)r_v0 < (unsigned long)(0xe) ? 1 : 0);
    if (r_at == 0) { r_a1 = (long)(0 + (0x4eb6)); goto _lbl_01F6A14C; }
    r_a1 = (long)(0 + (0x4eb6));
    r_v1 = (long)(0x1f8 << 16);
    r_v1 = (long)(r_v1 + (-0x6a10));
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    return (void *)r_v0;
    r_a1 = (long)(0 + (0x4eb6));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4eb6));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4ebc));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4ebc));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4ebb));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4ebb));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4eb8));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4eb8));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4eba));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4eba));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4ebd));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4ebd));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4ebe));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4ebe));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4eb9));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4eb9));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4ebf));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4ebf));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4ec1));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4ec1));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4ec2));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4ec2));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4ec0));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4ec0));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4eb7));
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4eb7));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
    goto _lbl_01F6A164;
    r_a1 = (long)(0 + (0x4eb6));
_lbl_01F6A14C:
    r_a2 = (long)(r_s0 + (0xe9c));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x4eb6));
    if (r_s0) { *(int *)((char *)r_s0 + (3688)) = (int)r_v0; }
_lbl_01F6A164:
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (2104)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (5848)); }
    r_v0 = (long)func_0020DB70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a2 = *(int *)((char *)r_s0 + (2100)); }
    if (r_a2 == 0) { r_v0 = (long)(0 + (-1)); goto _lbl_01F6A1A4; }
    r_v0 = (long)(0 + (-1));
    if (r_a2) { r_v1 = *(unsigned char *)((char *)r_a2 + (3161)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2104)); }
    if (r_v1 != r_v0) goto _lbl_01F6A1A0;
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (2988)); }
    /* unhandled: lwc1 $f12 0x18($v0) */
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (5788)) = (int)r_v0; }
    goto _lbl_01F6A1A8;
_lbl_01F6A1A0:
    r_v0 = (long)(0 + (-1));
_lbl_01F6A1A4:
    if (r_s0) { *(int *)((char *)r_s0 + (5788)) = (int)r_v0; }
_lbl_01F6A1A8:
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F6A270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F6A1C0;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6A1DC;
_lbl_01F6A1C0:
    if (r_s0) { *(int *)((char *)r_s0 + (3556)) = (int)0; }
    if (r_s0) { r_t9 = *(int *)((char *)r_s0 + (0)); }
    r_a1 = (long)(0 + (2));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (1));
_lbl_01F6A1DC:
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 11: thelp_func_01F6A1EC (VMA: 0x01F6A1EC, size: 300 bytes) */
void *thelp_func_01F6A1EC(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2092)); }
    if (r_v0 != 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01F6A214; }
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6A304;
_lbl_01F6A214:
    r_v0 = (long)func_01F6A4F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 > 0) { r_a0 = (long)(r_s0 | 0); goto _lbl_01F6A230; }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6A304;
    r_a0 = (long)(r_s0 | 0);
_lbl_01F6A230:
    r_v0 = (long)func_01F6B250((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 > 0) { r_a0 = (long)(r_s0 | 0); goto _lbl_01F6A24C; }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6A304;
    r_a0 = (long)(r_s0 | 0);
_lbl_01F6A24C:
    r_v0 = (long)func_01F6CB30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a0 = (long)(r_s0 | 0); goto _lbl_01F6A268; }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6A304;
    r_a0 = (long)(r_s0 | 0);
_lbl_01F6A268:
    r_v0 = (long)func_01F6E210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F6E3A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F6E5C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (3680)); }
    r_a0 = (long)(r_s0 | 0);
    if (r_s0) { *(int *)((char *)r_s0 + (3552)) = (int)r_v0; }
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (3648)); }
    if (r_s0) { r_a2 = *(int *)((char *)r_s0 + (2072)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (3724)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (3728)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (3732)); }
    r_a3 = (long)(r_a3 + (0x1a));
    r_a2 = (long)(r_a2 + (0x1a));
    r_a1 = (long)(r_a1 + r_a2);
    r_v1 = (long)(r_v1 + r_a1);
    r_v0 = (long)(r_v0 + r_v1);
    if (r_s0) { *(int *)((char *)r_s0 + (3548)) = (int)r_v0; }
    r_v0 = (long)func_01F6EAE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (2108)); }
    goto _lbl_01F6A2D4;
    r_a0 = (long)(r_s1 | 0);
_lbl_01F6A2CC:
    if (r_s1) { r_s1 = *(int *)((char *)r_s1 + (92)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A2D4:
    if (r_s1 != 0) { r_a0 = (long)(r_s1 | 0); goto _lbl_01F6A2CC; }
    r_a0 = (long)(r_s1 | 0);
    if (r_s0) { *(int *)((char *)r_s0 + (2108)) = (int)0; }
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (2116)); }
    goto _lbl_01F6A2F4;
    r_a0 = (long)(r_s1 | 0);
_lbl_01F6A2EC:
    if (r_s1) { r_s1 = *(int *)((char *)r_s1 + (1332)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A2F4:
    if (r_s1 != 0) { r_a0 = (long)(r_s1 | 0); goto _lbl_01F6A2EC; }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(0 + (1));
    if (r_s0) { *(int *)((char *)r_s0 + (2116)) = (int)0; }
_lbl_01F6A304:
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 12: thelp_func_01F6A318 (VMA: 0x01F6A318, size: 340 bytes) */
void *thelp_func_01F6A318(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a0 | 0);
    r_v1 = (long)(0 | 0);
    goto _lbl_01F6A34C;
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01F6A340:
    r_v0 = (long)(r_s0 + r_v0);
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (2132)) = (int)0; }
_lbl_01F6A34C:
    r_v0 = (long)((long)r_v1 < (long)(0x32) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_v1 << (2)); goto _lbl_01F6A340; }
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v1 = (long)(0 | 0);
    goto _lbl_01F6A370;
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01F6A364:
    r_v0 = (long)(r_s0 + r_v0);
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (2332)) = (int)0; }
_lbl_01F6A370:
    r_v0 = (long)((long)r_v1 < (long)(0x96) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_v1 << (2)); goto _lbl_01F6A364; }
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v1 = (long)(0 | 0);
    goto _lbl_01F6A394;
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01F6A388:
    r_v0 = (long)(r_s0 + r_v0);
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (2932)) = (int)0; }
_lbl_01F6A394:
    r_v0 = (long)((long)r_v1 < (long)(0x96) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_v1 << (2)); goto _lbl_01F6A388; }
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v1 = (long)(0 | 0);
    goto _lbl_01F6A3B8;
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01F6A3AC:
    r_v0 = (long)(r_s0 + r_v0);
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (3700)) = (int)0; }
_lbl_01F6A3B8:
    r_v0 = (long)((long)r_v1 < (long)(6) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_v1 << (2)); goto _lbl_01F6A3AC; }
    r_v0 = (long)((unsigned long)r_v1 << (2));
    if (r_s0) { *(int *)((char *)r_s0 + (3548)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (3552)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2124)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2128)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (3584)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (3580)) = (int)0; }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2076)); }
    if (r_a0 == 0) goto _lbl_01F6A3F4;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (2076)) = (int)0; }
_lbl_01F6A3F4:
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2084)); }
    if (r_a0 == 0) goto _lbl_01F6A40C;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (2084)) = (int)0; }
_lbl_01F6A40C:
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (2108)); }
    goto _lbl_01F6A420;
    r_a0 = (long)(r_s1 | 0);
_lbl_01F6A418:
    if (r_s1) { r_s1 = *(int *)((char *)r_s1 + (92)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A420:
    if (r_s1 != 0) { r_a0 = (long)(r_s1 | 0); goto _lbl_01F6A418; }
    r_a0 = (long)(r_s1 | 0);
    if (r_s0) { *(int *)((char *)r_s0 + (2108)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2112)) = (int)0; }
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (2116)); }
    goto _lbl_01F6A444;
    r_a0 = (long)(r_s1 | 0);
_lbl_01F6A43C:
    if (r_s1) { r_s1 = *(int *)((char *)r_s1 + (1332)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A444:
    if (r_s1 != 0) { r_a0 = (long)(r_s1 | 0); goto _lbl_01F6A43C; }
    r_a0 = (long)(r_s1 | 0);
    if (r_s0) { *(int *)((char *)r_s0 + (2116)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2120)) = (int)0; }
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_v0 = (long)(0 + (1));
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 13: thelp_func_01F6A46C (VMA: 0x01F6A46C, size: 3416 bytes) */
void *thelp_func_01F6A46C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0;
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
    r_sp = (long)(r_sp + (-0x60));
    /* unhandled: ext $ra $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_sp) { *(int *)((char *)r_sp + (92)) = (int)0; }
    r_s1 = (long)(r_a0 | 0);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (2092)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if (r_s0 != 0) { r_a0 = (long)(r_s1 | 0); goto _lbl_01F6A4B4; }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F6B1A8;
    r_a0 = (long)(r_s1 | 0);
_lbl_01F6A4B4:
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F6F250((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x6d));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 != 0) goto _lbl_01F6A4DC;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F6B1A8;
_lbl_01F6A4DC:
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_t1 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_a3 = (long)(0 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x6d));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x26d));
    r_s0 = (long)(0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A590;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A590;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x26d));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A590:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x31));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A604;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A604;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x31));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A604:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x67));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A678;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A678;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x67));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A678:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0xd1));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A6EC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A6EC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0xd1));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A6EC:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x248));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A760;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A760;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x248));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A760:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x232));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A7D4;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A7D4;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x232));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A7D4:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x54));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A848;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A848;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x54));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A848:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x44));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A8BC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A8BC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x44));
    r_a2 = (long)(0 + (2));
    r_s3 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A8BC:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x32));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A92C;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A92C;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s3 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x32));
    r_a2 = (long)(0 + (2));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A92C:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x57));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6A9A0;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6A9A0;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_a3 = (long)(0 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x57));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6A9A0:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0xc));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AA14;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AA14;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0xc));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AA14:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x65));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AA88;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AA88;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x65));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AA88:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x114));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AAFC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AAFC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x114));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AAFC:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x2d));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AB70;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AB70;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x2d));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AB70:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0xc7));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6ABE4;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6ABE4;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0xc7));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6ABE4:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x256));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AC60;
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AC60;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x256));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AC60:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x4f));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6ACDC;
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6ACDC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x4f));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6ACDC:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0xea));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AD58;
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AD58;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0xea));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AD58:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0xeb));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6ADD4;
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6ADD4;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0xeb));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6ADD4:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0xec));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AE58;
    r_v0 = (long)(0 + (2));
    if (r_s2) { *(char *)((char *)r_s2 + (124)) = (char)r_v0; }
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AE58;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0xec));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AE58:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x48));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AED4;
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AED4;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x48));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AED4:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x1e7));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AF50;
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AF50;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x1e7));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AF50:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x75));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6AFCC;
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6AFCC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0xec));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6AFCC:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x9b));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6B048;
    r_v0 = (long)(0 + (6));
    if (r_s2) { *(int *)((char *)r_s2 + (12)) = (int)r_v0; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6B048;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x9b));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B048:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x68));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6B0BC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6B0BC;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x68));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B0BC:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x52));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6B130;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6B130;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x52));
    r_a2 = (long)(0 + (2));
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B130:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(0 + (0x46));
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 == 0) goto _lbl_01F6B1A0;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6B1A0;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (0)); }
    r_a2 = (long)(r_sp + (0x5c));
    r_a3 = (long)(r_s0 | 0);
    r_t1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6F450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x46));
    r_a2 = (long)(0 + (2));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B1A0:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (92)); }
_lbl_01F6B1A8:
    /* unhandled: xori.b $w1 $w0 0xbf */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 14: thelp_func_01F6B1C4 (VMA: 0x01F6B1C4, size: 6372 bytes) */
void *thelp_func_01F6B1C4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x150));
    /* unhandled: mulsa.w.ph $ac0 $sp $ra */
    /* unhandled: ext $s6 $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s5 */
    /* unhandled: subu.qb $zero $sp $s3 */
    /* unhandled: ext $s2 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s1 */
    if (r_a0) { r_s0 = *(int *)((char *)r_a0 + (2108)); }
    r_s2 = (long)(r_a0 | 0);
    if (r_sp) { *(int *)((char *)r_sp + (256)) = (int)0; }
    goto _lbl_01F6B254;
_lbl_01F6B20C:
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (4)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (256)); }
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(r_v0 | 0);
    r_a3 = (long)(r_s0 | 0);
    r_t0 = (long)(0 | 0);
    r_v0 = (long)func_01F6F770((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_v0 | 0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (256)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (2120)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (256)) = (int)r_v0; }
    r_v0 = (long)func_01F6F3F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_s0 = *(int *)((char *)r_s0 + (92)); }
_lbl_01F6B254:
    if (r_s0 != 0) goto _lbl_01F6B20C;
    r_a0 = (long)(r_s2 + (0xb74));
    r_a2 = (long)(0 + (0x258));
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 + (0x91c));
    r_a2 = (long)(0 + (0x258));
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_s4 = *(int *)((char *)r_s2 + (2116)); }
    r_s1 = (long)(r_s4 | 0);
    r_s3 = (long)(r_s4 | 0);
    goto _lbl_01F6C698;
_lbl_01F6B28C:
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (12)); }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (12)); }
    if (r_v0 != r_a1) goto _lbl_01F6B2A4;
    r_s3 = (long)(r_s4 | 0);
    goto _lbl_01F6C690;
_lbl_01F6B2A4:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if (r_s0 == 0) goto _lbl_01F6C690;
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    r_v0 = (long)(0 + (0xd1));
    if (r_v1 == r_v0) goto _lbl_01F6C680;
    r_v0 = (long)(0 + (0x54));
    if (r_v1 == r_v0) goto _lbl_01F6C074;
    r_v0 = (long)(0 + (0x248));
    if (r_v1 == r_v0) goto _lbl_01F6BF48;
    r_v0 = (long)(0 + (0x31));
    if (r_v1 == r_v0) goto _lbl_01F6BD88;
    r_v0 = (long)(0 + (0x68));
    if (r_v1 == r_v0) goto _lbl_01F6B8F0;
    r_v0 = (long)(0 + (0x2d));
    if (r_v1 == r_v0) goto _lbl_01F6B4D8;
    r_v0 = (long)(0 + (0x65));
    if (r_v1 == r_v0) goto _lbl_01F6B318;
    goto _lbl_01F6C680;
_lbl_01F6B318:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x149));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B3A8;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B3A8:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s1) { r_s5 = *(int *)((char *)r_s1 + (1332)); }
    r_a1 = (long)(0 + (0x26));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s5 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B43C;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s5 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B43C:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s5) { r_s6 = *(int *)((char *)r_s5 + (1332)); }
    r_a1 = (long)(0 + (0x1c0));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C680;
    r_a3 = (long)(0 + (-1));
    r_t1 = (long)(r_s6 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6C680;
_lbl_01F6B4D8:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0xd));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B568;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B568:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x11));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B5F8;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B5F8:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x211));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B688;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B688:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s1) { r_s6 = *(int *)((char *)r_s1 + (1332)); }
    r_a1 = (long)(0 + (0x221));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B71C;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B71C:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x20f));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B7AC;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B7AC:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s6) { r_s6 = *(int *)((char *)r_s6 + (1332)); }
    r_a1 = (long)(0 + (0x21b));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B840;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B840:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2104)); }
    r_v0 = (long)(0 + (0xb));
    if (r_v1 != r_v0) goto _lbl_01F6C680;
    if (r_v1 != r_v0) { if (r_s6) { r_s6 = *(int *)((char *)r_s6 + (1332)); } goto _lbl_01F6C680; }
    if (r_s6) { r_s6 = *(int *)((char *)r_s6 + (1332)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0xfa));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C680;
    r_a3 = (long)(0 + (-1));
    r_t1 = (long)(r_s6 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6C680;
_lbl_01F6B8F0:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x13c));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6B980;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6B980:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0xe6));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BA10;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BA10:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s1) { r_s6 = *(int *)((char *)r_s1 + (1332)); }
    r_a1 = (long)(0 + (0xfc));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BAA4;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BAA4:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0xe9));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BB34;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BB34:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s6) { r_s6 = *(int *)((char *)r_s6 + (1332)); }
    r_a1 = (long)(0 + (0xe7));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BBC8;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BBC8:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x2d));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BC58;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BC58:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s6) { r_s6 = *(int *)((char *)r_s6 + (1332)); }
    r_a1 = (long)(0 + (0x13f));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BCEC;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BCEC:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s6) { r_s6 = *(int *)((char *)r_s6 + (1332)); }
    r_a1 = (long)(0 + (0x7d));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C680;
    r_a3 = (long)(0 + (-1));
    r_t1 = (long)(r_s6 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6C680;
_lbl_01F6BD88:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x118));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BE18;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BE18:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s1) { r_s6 = *(int *)((char *)r_s1 + (1332)); }
    r_a1 = (long)(0 + (0x23));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BEAC;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BEAC:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s6) { r_s6 = *(int *)((char *)r_s6 + (1332)); }
    r_a1 = (long)(0 + (0x117));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C680;
    r_a3 = (long)(0 + (-1));
    r_t1 = (long)(r_s6 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6C680;
_lbl_01F6BF48:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x116));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6BFD8;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6BFD8:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s1) { r_s6 = *(int *)((char *)r_s1 + (1332)); }
    r_a1 = (long)(0 + (0x37));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C680;
    r_a3 = (long)(0 + (-1));
    r_t1 = (long)(r_s6 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6C680;
_lbl_01F6C074:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0x13));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C104;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6C104:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(0 + (0xf));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s6 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C194;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6C194:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s1) { r_s6 = *(int *)((char *)r_s1 + (1332)); }
    r_a1 = (long)(0 + (0x17));
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C228;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6C228:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s6) { r_s6 = *(int *)((char *)r_s6 + (1332)); }
    r_a1 = (long)(0 + (0x80));
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_s5 = (long)(r_v0 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s6 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C680;
    r_a3 = (long)(0 + (-1));
    r_t1 = (long)(r_s6 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6C680;
_lbl_01F6C2C4:
    r_s7 = (long)(0 | 0);
    goto _lbl_01F6C65C;
_lbl_01F6C2CC:
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (4)); }
    r_v1 = (long)((unsigned long)r_s7 << (3));
    r_v1 = (long)(r_v1 + r_s7);
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_s5 = (long)(r_v0 + r_v1);
    if (r_s5 == 0) { r_s7 = (long)(r_s7 + (1)); goto _lbl_01F6C65C; }
    if (r_sp) { *(int *)((char *)r_sp + (272)) = (int)0; }
    goto _lbl_01F6C4B8;
_lbl_01F6C2F0:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (272)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_s8 = *(int *)((char *)r_v0 + (0)); }
    r_a1 = (long)(r_s8 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if (r_s6 == 0) goto _lbl_01F6C4AC;
    r_a2 = (long)(0 + (1));
    r_a1 = (long)(r_s8 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6F8C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 == r_v1) goto _lbl_01F6C4AC;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s5) { r_s8 = *(int *)((char *)r_s5 + (0)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s8 != r_v0) goto _lbl_01F6C4AC;
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0)); }
    r_v0 = (long)(0 + (0x52));
    if (r_a0 != r_v0) { r_v0 = (long)(0 + (0x2d)); goto _lbl_01F6C384; }
    r_v0 = (long)(0 + (0x2d));
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (8)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F6C380;
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (0)); }
    r_v0 = (long)(0 + (0x14b));
    if (r_v1 != r_v0) goto _lbl_01F6C4AC;
_lbl_01F6C380:
    r_v0 = (long)(0 + (0x2d));
_lbl_01F6C384:
    if (r_a0 != r_v0) goto _lbl_01F6C3B8;
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (0)); }
    r_v0 = (long)(0 + (0xfa));
    if (r_v1 == r_v0) goto _lbl_01F6C3A8;
    r_v0 = (long)(0 + (0x215));
    if (r_v1 != r_v0) goto _lbl_01F6C3B8;
_lbl_01F6C3A8:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2104)); }
    r_v0 = (long)(0 + (0xb));
    if (r_v1 != r_v0) goto _lbl_01F6C4AC;
_lbl_01F6C3B8:
    if (r_sp) { *(int *)((char *)r_sp + (288)) = (int)0; }
    r_s8 = (long)(0 | 0);
    goto _lbl_01F6C428;
    r_v0 = (long)((unsigned long)r_s8 << (2));
_lbl_01F6C3C8:
    r_a0 = (long)(r_s6 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (76)); }
    r_v0 = (long)(0 + (2));
    if (r_v1 != r_v0) { r_s8 = (long)(r_s8 + (1)); goto _lbl_01F6C428; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6C424;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    /* unhandled: dpau.h.qbl $ac0 $sp $v0 */
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v1 != r_v0) goto _lbl_01F6C424;
    r_v0 = (long)(0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (288)) = (int)r_v0; }
    goto _lbl_01F6C438;
_lbl_01F6C424:
    r_s8 = (long)(r_s8 + (1));
_lbl_01F6C428:
    if (r_s6) { r_v0 = *(unsigned char *)((char *)r_s6 + (32)); }
    r_v0 = (long)((long)r_s8 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s8 << (2)); goto _lbl_01F6C3C8; }
    r_v0 = (long)((unsigned long)r_s8 << (2));
_lbl_01F6C438:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (288)); }
    r_v1 = (long)(0 + (1));
    if (r_v0 == r_v1) goto _lbl_01F6C4AC;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C4AC;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6C4AC:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (272)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (272)) = (int)r_v0; }
_lbl_01F6C4B8:
    if (r_s0) { r_v1 = *(unsigned char *)((char *)r_s0 + (24)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (272)); }
    r_v0 = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6C2F0;
    if (r_sp) { *(int *)((char *)r_sp + (304)) = (int)0; }
    goto _lbl_01F6C644;
_lbl_01F6C4D4:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (304)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (36)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_s8 = *(int *)((char *)r_v0 + (0)); }
    r_a1 = (long)(r_s8 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if (r_s6 == 0) goto _lbl_01F6C638;
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(r_s8 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_01F6F8C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 == r_v1) goto _lbl_01F6C638;
    r_v0 = (long)(r_s8 + (-0x66));
    r_at = (long)((unsigned long)r_v0 < (unsigned long)(3) ? 1 : 0);
    if (r_at != 0) goto _lbl_01F6C638;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s5) { r_s8 = *(int *)((char *)r_s5 + (0)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s8 != r_v0) goto _lbl_01F6C638;
    if (r_sp) { *(int *)((char *)r_sp + (320)) = (int)0; }
    r_s8 = (long)(0 | 0);
    goto _lbl_01F6C5B4;
    r_v0 = (long)((unsigned long)r_s8 << (2));
_lbl_01F6C554:
    r_a0 = (long)(r_s6 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) { r_s8 = (long)(r_s8 + (1)); goto _lbl_01F6C5B4; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6C5B0;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: ld.b $w3 -0x5d($zero) */
    if (r_v1 != r_v0) goto _lbl_01F6C5B0;
    r_v0 = (long)(0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (320)) = (int)r_v0; }
    goto _lbl_01F6C5C4;
_lbl_01F6C5B0:
    r_s8 = (long)(r_s8 + (1));
_lbl_01F6C5B4:
    if (r_s6) { r_v0 = *(unsigned char *)((char *)r_s6 + (40)); }
    r_v0 = (long)((long)r_s8 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s8 << (2)); goto _lbl_01F6C554; }
    r_v0 = (long)((unsigned long)r_s8 << (2));
_lbl_01F6C5C4:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (320)); }
    r_v1 = (long)(0 + (1));
    if (r_v0 == r_v1) goto _lbl_01F6C638;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s0 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C638;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6C638:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (304)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (304)) = (int)r_v0; }
_lbl_01F6C644:
    if (r_s0) { r_v1 = *(unsigned char *)((char *)r_s0 + (32)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (304)); }
    r_v0 = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6C4D4;
    r_s7 = (long)(r_s7 + (1));
_lbl_01F6C65C:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2092)); }
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (0)); }
    r_v0 = (long)((long)r_s7 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6C2CC;
    if (r_s1 == r_s3) { r_s1 = (long)(r_s4 | 0); goto _lbl_01F6C68C; }
    if (r_s1) { r_s1 = *(int *)((char *)r_s1 + (1332)); }
_lbl_01F6C680:
    if (r_s1 != 0) goto _lbl_01F6C2C4;
    r_s1 = (long)(r_s4 | 0);
_lbl_01F6C68C:
    r_s3 = (long)(r_s4 | 0);
_lbl_01F6C690:
    if (r_s4) { r_s4 = *(int *)((char *)r_s4 + (1332)); }
_lbl_01F6C698:
    if (r_s4 != 0) goto _lbl_01F6B28C;
    goto _lbl_01F6C9D4;
_lbl_01F6C6A8:
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (12)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    r_s0 = (long)(0 | 0);
    goto _lbl_01F6C9B8;
_lbl_01F6C6C0:
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (4)); }
    r_v1 = (long)((unsigned long)r_s0 << (3));
    r_v1 = (long)(r_v1 + r_s0);
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_s4 = (long)(r_v0 + r_v1);
    if (r_s4 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F6C9B8; }
    r_s7 = (long)(0 | 0);
    goto _lbl_01F6C830;
_lbl_01F6C6E4:
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (28)); }
    r_v1 = (long)((unsigned long)r_s7 << (2));
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_s3 = *(int *)((char *)r_v0 + (0)); }
    r_a1 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    if (r_s5 == 0) { r_s7 = (long)(r_s7 + (1)); goto _lbl_01F6C830; }
    r_a2 = (long)(0 + (1));
    r_a1 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6F8C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 == r_v1) goto _lbl_01F6C82C;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s4) { r_s3 = *(int *)((char *)r_s4 + (0)); }
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3 != r_v0) goto _lbl_01F6C82C;
    r_s8 = (long)(0 | 0);
    r_s3 = (long)(0 | 0);
    goto _lbl_01F6C7AC;
    r_v0 = (long)((unsigned long)r_s3 << (2));
_lbl_01F6C750:
    r_a0 = (long)(r_s5 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (76)); }
    r_v0 = (long)(0 + (2));
    if (r_v1 != r_v0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F6C7AC; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6C7A8;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: aver_u.h $w3 $w0 $w3 */
    if (r_v1 != r_v0) goto _lbl_01F6C7A8;
    r_s8 = (long)(0 + (1));
    goto _lbl_01F6C7BC;
_lbl_01F6C7A8:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6C7AC:
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (32)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (2)); goto _lbl_01F6C750; }
    r_v0 = (long)((unsigned long)r_s3 << (2));
_lbl_01F6C7BC:
    r_v0 = (long)(0 + (1));
    if (r_s8 == r_v0) goto _lbl_01F6C82C;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s6 | 0);
    r_t3 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C82C;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(0 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6C82C:
    r_s7 = (long)(r_s7 + (1));
_lbl_01F6C830:
    if (r_s6) { r_v0 = *(unsigned char *)((char *)r_s6 + (24)); }
    r_v0 = (long)((long)r_s7 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6C6E4;
    r_s7 = (long)(0 | 0);
    goto _lbl_01F6C9A4;
_lbl_01F6C848:
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (36)); }
    r_v1 = (long)((unsigned long)r_s7 << (2));
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_s3 = *(int *)((char *)r_v0 + (0)); }
    r_a1 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    if (r_s5 == 0) { r_s7 = (long)(r_s7 + (1)); goto _lbl_01F6C9A4; }
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_01F6F8C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 == r_v1) goto _lbl_01F6C9A0;
    r_v0 = (long)(r_s3 + (-0x66));
    r_at = (long)((unsigned long)r_v0 < (unsigned long)(3) ? 1 : 0);
    if (r_at != 0) goto _lbl_01F6C9A0;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    if (r_s4) { r_s3 = *(int *)((char *)r_s4 + (0)); }
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3 != r_v0) goto _lbl_01F6C9A0;
    r_s8 = (long)(0 | 0);
    r_s3 = (long)(0 | 0);
    goto _lbl_01F6C920;
    r_v0 = (long)((unsigned long)r_s3 << (2));
_lbl_01F6C8C4:
    r_a0 = (long)(r_s5 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F6C920; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6C91C;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    /* unhandled: ext $v0 $sp 3 1 */
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: xori.b $w3 $w0 0xa3 */
    if (r_v1 != r_v0) goto _lbl_01F6C91C;
    r_s8 = (long)(0 + (1));
    goto _lbl_01F6C930;
_lbl_01F6C91C:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6C920:
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (40)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (2)); goto _lbl_01F6C8C4; }
    r_v0 = (long)((unsigned long)r_s3 << (2));
_lbl_01F6C930:
    r_v0 = (long)(0 + (1));
    if (r_s8 == r_v0) goto _lbl_01F6C9A0;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(r_s6 | 0);
    r_t3 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6C9A0;
    r_a3 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_t2 = (long)(0 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6C9A0:
    r_s7 = (long)(r_s7 + (1));
_lbl_01F6C9A4:
    if (r_s6) { r_v0 = *(unsigned char *)((char *)r_s6 + (32)); }
    r_v0 = (long)((long)r_s7 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6C848;
    r_s0 = (long)(r_s0 + (1));
_lbl_01F6C9B8:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2092)); }
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (0)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6C6C0;
    if (r_s1) { r_s1 = *(int *)((char *)r_s1 + (1332)); }
_lbl_01F6C9D4:
    if (r_s1 != 0) goto _lbl_01F6C6A8;
    if (r_s2) { r_t0 = *(int *)((char *)r_s2 + (2116)); }
    r_v1 = (long)(0 + (1));
    goto _lbl_01F6CA6C;
    r_t1 = (long)(0 | 0);
_lbl_01F6C9EC:
    r_a2 = (long)(0 | 0);
    goto _lbl_01F6CA58;
    r_v0 = (long)((unsigned long)r_a2 << (2));
_lbl_01F6C9F8:
    r_v0 = (long)(r_v0 + r_a2);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_a1 = (long)(r_t0 + r_v0);
    r_a3 = (long)(0 | 0);
    goto _lbl_01F6CA40;
    r_v0 = (long)((unsigned long)r_a3 << (2));
_lbl_01F6CA10:
    r_a0 = (long)(r_a1 + r_v0);
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (24)); }
    if ((long)r_v0 < 0) { r_a3 = (long)(r_a3 + (1)); goto _lbl_01F6CA40; }
    if (r_a0) { *(int *)((char *)r_a0 + (1024)) = (int)r_v1; }
    if (r_t0) { r_v0 = *(int *)((char *)r_t0 + (12)); }
    r_t1 = (long)(r_v1 | 0);
    if (r_a0) { *(int *)((char *)r_a0 + (1124)) = (int)r_v0; }
    if (r_t0) { r_v0 = *(int *)((char *)r_t0 + (16)); }
    if (r_a0) { *(int *)((char *)r_a0 + (1224)) = (int)r_v0; }
    goto _lbl_01F6CA4C;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F6CA40:
    r_v0 = (long)((long)r_a3 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a3 << (2)); goto _lbl_01F6CA10; }
    r_v0 = (long)((unsigned long)r_a3 << (2));
_lbl_01F6CA4C:
    if (r_t1 == r_v1) goto _lbl_01F6CA64;
    r_a2 = (long)(r_a2 + (1));
_lbl_01F6CA58:
    r_v0 = (long)((long)r_a2 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a2 << (2)); goto _lbl_01F6C9F8; }
    r_v0 = (long)((unsigned long)r_a2 << (2));
_lbl_01F6CA64:
    if (r_t0) { r_t0 = *(int *)((char *)r_t0 + (1332)); }
_lbl_01F6CA6C:
    if (r_t0 != 0) { r_t1 = (long)(0 | 0); goto _lbl_01F6C9EC; }
    r_t1 = (long)(0 | 0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (256)); }
    /* unhandled: ld.b $w2 -0x42($zero) */
    /* unhandled: aver_u.h $w2 $w0 $w23 */
    /* unhandled: xori.b $w2 $w0 0xb6 */
    /* unhandled: ld.b $w1 -0x4c($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w19 */
    /* unhandled: xori.b $w1 $w0 0xb2 */
    /* unhandled: ld.b $w0 -0x50($zero) */
    r_sp = (long)(r_sp + (0x150));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 15: thelp_func_01F6CAA8 (VMA: 0x01F6CAA8, size: 5860 bytes) */
void *thelp_func_01F6CAA8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t9 = 0;
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
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x380));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (2108)); }
    r_s5 = (long)(r_a0 | 0);
    if (r_v0 != 0) { if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)0; } goto _lbl_01F6CAF4; }
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6E15C;
_lbl_01F6CAF4:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2116)); }
    if (r_v0 != 0) goto _lbl_01F6CB08;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6E15C;
_lbl_01F6CB08:
    if (r_s5) { *(int *)((char *)r_s5 + (2072)) = (int)0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2108)); }
    goto _lbl_01F6CB28;
_lbl_01F6CB14:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2072)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_s5) { *(int *)((char *)r_s5 + (2072)) = (int)r_v0; }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (92)); }
_lbl_01F6CB28:
    if (r_v1 != 0) goto _lbl_01F6CB14;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2072)); }
    if ((long)r_a0 > 0) { r_a1 = (long)(0 + (0x2e8)); goto _lbl_01F6CB48; }
    r_a1 = (long)(0 + (0x2e8));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6E15C;
    r_a1 = (long)(0 + (0x2e8));
_lbl_01F6CB48:
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { *(int *)((char *)r_s5 + (2076)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    if (r_v0 != 0) goto _lbl_01F6CB68;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6E15C;
_lbl_01F6CB68:
    if (r_s5) { r_s0 = *(int *)((char *)r_s5 + (2108)); }
    r_s1 = (long)(0 | 0);
    goto _lbl_01F6D198;
_lbl_01F6CB74:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2072)); }
    r_at = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6D1A0;
    r_v0 = (long)((unsigned long)r_s1 << (5));
    r_v1 = (long)(r_v0 - r_s1);
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 - r_v1);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_s2 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(0 | 0);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (0)) = (int)r_s1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (4)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (4)) = (int)r_a0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (8)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (8)) = (int)r_a0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (16)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (12)) = (int)r_a0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (32)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (676)) = (int)r_a0; }
    goto _lbl_01F6CC0C;
_lbl_01F6CBEC:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_a1 = (long)((unsigned long)r_v0 << (2));
    r_a0 = (long)(r_s0 + r_a1);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (36)); }
    r_v0 = (long)(r_v0 + (1));
    r_v1 = (long)(r_s2 + r_v1);
    r_v1 = (long)(r_v1 + r_a1);
    if (r_v1) { *(int *)((char *)r_v1 + (680)) = (int)r_a0; }
_lbl_01F6CC0C:
    r_v1 = (long)((long)r_v0 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6CBEC;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(0 + (-1));
    r_a0 = (long)(0 + (1));
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (700)) = (int)0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (20)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (672)) = (int)r_a1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (68)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (740)) = (int)r_a1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (728)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (736)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (732)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (16)) = (int)r_s1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_a1 = (long)(r_v1 + r_s2);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (176)); }
    if (r_a1) { *(int *)((char *)r_a1 + (20)) = (int)r_v1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (4)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (24)) = (int)r_a1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (16)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (516)) = (int)r_a1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (8)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (520)) = (int)r_a1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (28)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (528)) = (int)r_a1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (20)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (532)) = (int)r_a1; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (536)) = (int)r_a0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(char *)((char *)r_v1 + (540)) = (char)0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (56)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (604)) = (int)r_a0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (64)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (616)) = (int)r_a0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (608)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (60)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (612)) = (int)r_a0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (620)) = (int)0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (624)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (628)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (632)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (636)) = (int)0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (660)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (656)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (664)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (668)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (640)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (640)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (648)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (652)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (32)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(char *)((char *)r_v0 + (36)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(char *)((char *)r_v0 + (156)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(char *)((char *)r_v0 + (276)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(char *)((char *)r_v0 + (396)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (4)); }
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (24)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(int *)((char *)r_v0 + (524)) = (int)r_v1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (24)); }
    if ((long)r_a0 < 0) { r_v1 = (long)(0 | 0); goto _lbl_01F6D154; }
    r_v1 = (long)(0 | 0);
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (5968)); }
    if (r_a1) { r_v1 = *(short *)((char *)r_a1 + (20)); }
    r_at = (long)((long)r_a0 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6D150;
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (24)); }
    r_a0 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v1 == 0) goto _lbl_01F6D150;
    if (r_v1) { r_a2 = *(short *)((char *)r_v1 + (68)); }
    if (r_v1) { r_a1 = *(short *)((char *)r_v1 + (368)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (28)); }
    r_v1 = (long)(0 + (0x9b));
    if (r_a0 != r_v1) { r_a1 = (long)(r_a2 + r_a1); goto _lbl_01F6CED8; }
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)(0 + (0x2e));
    if (r_v0) { *(int *)((char *)r_v0 + (32)) = (int)r_v1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2100)); }
    if (r_a0 == 0) goto _lbl_01F6D00C;
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (3161)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2104)); }
    if (r_v1 != r_v0) goto _lbl_01F6D00C;
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (6964)); }
    r_a1 = (long)(0 + (0xc2));
    r_v0 = (long)func_002D33E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F6D00C;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(0 + (5));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(int *)((char *)r_v0 + (524)) = (int)r_v1; }
    goto _lbl_01F6D00C;
_lbl_01F6CED8:
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (4)); }
    r_v1 = (long)(0 + (0xea));
    if (r_a0 != r_v1) { r_v1 = (long)(0 + (0xeb)); goto _lbl_01F6CF44; }
    r_v1 = (long)(0 + (0xeb));
    r_v1 = (long)(0 + (0x4c));
    if (r_v0) { *(int *)((char *)r_v0 + (32)) = (int)r_v1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2100)); }
    if (r_a0 == 0) goto _lbl_01F6D00C;
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (3161)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2104)); }
    if (r_v1 != r_v0) goto _lbl_01F6D00C;
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (6964)); }
    r_a1 = (long)(0 + (0x8c));
    r_v0 = (long)func_002D33E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F6D00C;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(0 + (5));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(int *)((char *)r_v0 + (524)) = (int)r_v1; }
    goto _lbl_01F6D00C;
    r_v1 = (long)(0 + (0xeb));
_lbl_01F6CF44:
    if (r_a0 != r_v1) { r_v1 = (long)(0 + (0xec)); goto _lbl_01F6CFA8; }
    r_v1 = (long)(0 + (0xec));
    r_v1 = (long)(0 + (0x10));
    if (r_v0) { *(int *)((char *)r_v0 + (32)) = (int)r_v1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2100)); }
    if (r_a0 == 0) goto _lbl_01F6D00C;
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (3161)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2104)); }
    if (r_v1 != r_v0) goto _lbl_01F6D00C;
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (6964)); }
    r_a1 = (long)(0 + (0x3f));
    r_v0 = (long)func_002D33E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F6D00C;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(0 + (5));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(int *)((char *)r_v0 + (524)) = (int)r_v1; }
    goto _lbl_01F6D00C;
    r_v1 = (long)(0 + (0xec));
_lbl_01F6CFA8:
    if (r_a0 != r_v1) goto _lbl_01F6D008;
    r_v1 = (long)(0 + (0x2a));
    if (r_v0) { *(int *)((char *)r_v0 + (32)) = (int)r_v1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2100)); }
    if (r_a0 == 0) goto _lbl_01F6D00C;
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (3161)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2104)); }
    if (r_v1 != r_v0) goto _lbl_01F6D00C;
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (6964)); }
    r_a1 = (long)(0 + (0x40));
    r_v0 = (long)func_002D33E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F6D00C;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(0 + (5));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { *(int *)((char *)r_v0 + (524)) = (int)r_v1; }
    goto _lbl_01F6D00C;
_lbl_01F6D008:
    if (r_v0) { *(int *)((char *)r_v0 + (32)) = (int)r_a1; }
_lbl_01F6D00C:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5968)); }
    r_a0 = (long)(r_v1 + r_s2);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (24)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = *(short *)((char *)r_v0 + (4)); }
    if (r_a0) { *(int *)((char *)r_a0 + (640)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5968)); }
    r_a0 = (long)(r_v1 + r_s2);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (24)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = *(short *)((char *)r_v0 + (6)); }
    if (r_a0) { *(int *)((char *)r_a0 + (644)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5968)); }
    r_a0 = (long)(r_v1 + r_s2);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (24)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (132)); }
    if (r_a0) { *(int *)((char *)r_a0 + (648)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5968)); }
    r_a0 = (long)(r_v1 + r_s2);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (24)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (136)); }
    if (r_a0) { *(int *)((char *)r_a0 + (652)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (640)); }
    if ((long)r_a1 <= 0) goto _lbl_01F6D0D8;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a2 = (long)(r_v0 + (0x24));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a3 = (long)(0 + (0x78));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F6D0D8:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(char *)((char *)r_v1 + (36)); }
    if (r_v0 != 0) goto _lbl_01F6D0FC;
    r_v0 = (long)(0x1f8 << 16);
    r_a0 = (long)(r_v1 + (0x24));
    r_a1 = (long)(r_v0 + (-0x69d8));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6D0FC:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (640)); }
    if ((long)r_v1 <= 0) goto _lbl_01F6D12C;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(r_v1 + (0x2328));
    r_a2 = (long)(r_v0 + (0x9c));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a3 = (long)(0 + (0x78));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F6D12C:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(char *)((char *)r_v1 + (156)); }
    if (r_v0 != 0) goto _lbl_01F6D150;
    r_v0 = (long)(0x1f8 << 16);
    r_a0 = (long)(r_v1 + (0x9c));
    r_a1 = (long)(r_v0 + (-0x69d8));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6D150:
    r_v1 = (long)(0 | 0);
_lbl_01F6D154:
    r_v0 = (long)((long)r_v1 < (long)(5) ? 1 : 0);
    goto _lbl_01F6D17C;
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01F6D160:
    r_v0 = (long)(r_s0 + r_v0);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (72)); }
    if (r_v0 == 0) goto _lbl_01F6D184;
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (8)) = (int)r_s1; }
    r_v0 = (long)((long)r_v1 < (long)(5) ? 1 : 0);
_lbl_01F6D17C:
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_v1 << (2)); goto _lbl_01F6D160; }
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01F6D184:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
    if (r_s0) { r_s0 = *(int *)((char *)r_s0 + (92)); }
    r_s1 = (long)(r_s1 + (1));
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)r_v0; }
_lbl_01F6D198:
    if (r_s0 != 0) goto _lbl_01F6CB74;
_lbl_01F6D1A0:
    if (r_s5) { *(int *)((char *)r_s5 + (2080)) = (int)0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2116)); }
    goto _lbl_01F6D1C0;
_lbl_01F6D1AC:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2080)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_s5) { *(int *)((char *)r_s5 + (2080)) = (int)r_v0; }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (1332)); }
_lbl_01F6D1C0:
    if (r_v1 != 0) goto _lbl_01F6D1AC;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2080)); }
    if ((long)r_a0 > 0) { r_a1 = (long)(0 + (0x405c)); goto _lbl_01F6D1E0; }
    r_a1 = (long)(0 + (0x405c));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6E15C;
    r_a1 = (long)(0 + (0x405c));
_lbl_01F6D1E0:
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { *(int *)((char *)r_s5 + (2084)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_v0 != 0) goto _lbl_01F6D200;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6E15C;
_lbl_01F6D200:
    if (r_s5) { r_s4 = *(int *)((char *)r_s5 + (2116)); }
    if (r_sp) { *(int *)((char *)r_sp + (160)) = (int)0; }
    goto _lbl_01F6DB70;
_lbl_01F6D20C:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2080)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (160)); }
    r_at = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) { r_s4 = (long)(0 | 0); goto _lbl_01F6DB7C; }
    r_v1 = (long)(0 + (0x405c));
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_s8 = (long)(0 | 0);
    r_v1 = (long)(0 + (-1));
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (8)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (4)) = (int)r_a0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (8)) = (int)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (12)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (12)) = (int)r_a0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (16)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (16)) = (int)r_a0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (20)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (20)) = (int)r_a0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (1324)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (16436)) = (int)r_a0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (16464)) = (int)r_v1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (16468)) = (int)r_v1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (16472)) = (int)r_v1; }
    goto _lbl_01F6DB54;
    r_v0 = (long)((unsigned long)r_s8 << (2));
_lbl_01F6D2C4:
    r_v0 = (long)(r_v0 + r_s8);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_s4 + r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (240)) = (int)r_v0; }
    r_v0 = (long)(0 + (0xcd0));
    r_s7 = (long)(0 | 0);
    r_s0 = (long)(r_s1 + r_s6);
    goto _lbl_01F6DB44;
    r_v0 = (long)(0 + (-1));
_lbl_01F6D2EC:
    if (r_sp) { *(int *)((char *)r_sp + (192)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (192)); }
    r_v1 = (long)((unsigned long)r_s7 << (2));
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (240)); }
    r_s2 = (long)(r_v0 + r_v1);
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (224)); }
    r_v0 = (long)(r_s2 + (0xe0));
    if (r_sp) { *(int *)((char *)r_sp + (256)) = (int)r_v0; }
    r_v0 = (long)(0 + (4));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (3)); goto _lbl_01F6D350; }
    r_v0 = (long)(0 + (3));
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (24)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)((unsigned long)r_s7 << (2)); goto _lbl_01F6D388; }
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (128)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    if (r_sp) { *(int *)((char *)r_sp + (192)) = (int)r_v1; }
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    goto _lbl_01F6D384;
    r_v0 = (long)(0 + (3));
_lbl_01F6D350:
    if (r_v1 != r_v0) goto _lbl_01F6D384;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (24)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F6D384;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (120)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    if (r_sp) { *(int *)((char *)r_sp + (192)) = (int)r_v1; }
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
_lbl_01F6D384:
    r_v0 = (long)((unsigned long)r_s7 << (2));
_lbl_01F6D388:
    r_v0 = (long)(r_v0 + r_s7);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(r_v0 + r_s7);
    r_s3 = (long)((unsigned long)r_v0 << (4));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (160)); }
    r_v1 = (long)(r_s0 + r_v1);
    r_v1 = (long)(r_v1 + r_s3);
    r_a0 = (long)(r_s2 + (0x7c));
    if (r_v1) { *(int *)((char *)r_v1 + (36)) = (int)r_v0; }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(0 + (5));
    r_a1 = (long)(r_s0 + r_a1);
    r_a2 = (long)(r_a1 + r_s3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (176)); }
    if (r_a2) { *(int *)((char *)r_a2 + (40)) = (int)r_a1; }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (24)); }
    r_a1 = (long)(r_s0 + r_a1);
    r_a1 = (long)(r_a1 + r_s3);
    if (r_a1) { *(int *)((char *)r_a1 + (44)) = (int)r_a2; }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2084)); }
    r_a1 = (long)(r_s0 + r_a1);
    r_a2 = (long)(r_a1 + r_s3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (192)); }
    if (r_a2) { *(int *)((char *)r_a2 + (536)) = (int)r_a1; }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2084)); }
    r_a1 = (long)(r_s0 + r_a1);
    r_a2 = (long)(r_a1 + r_s3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (208)); }
    if (r_a2) { *(int *)((char *)r_a2 + (540)) = (int)r_a1; }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (124)); }
    r_a1 = (long)(r_s0 + r_a1);
    r_a1 = (long)(r_a1 + r_s3);
    if (r_a1) { *(int *)((char *)r_a1 + (544)) = (int)r_a2; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (24)); }
    if (r_a1 != r_v0) { r_v1 = (long)(r_s2 + (0x18)); goto _lbl_01F6D494; }
    r_v1 = (long)(r_s2 + (0x18));
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (2104)); }
    r_a1 = (long)(0 + (4));
    if (r_a2 != r_a1) goto _lbl_01F6D494;
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2100)); }
    if (r_a1 == 0) goto _lbl_01F6D484;
    if (r_a1) { r_a1 = *(unsigned char *)((char *)r_a1 + (3161)); }
    if (r_a1 != r_a2) goto _lbl_01F6D470;
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (0)); }
    if (r_a0 == r_v0) goto _lbl_01F6D494;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(0 + (2));
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(int *)((char *)r_v0 + (544)) = (int)r_a0; }
    goto _lbl_01F6D494;
_lbl_01F6D470:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (544)) = (int)r_v0; }
    goto _lbl_01F6D494;
_lbl_01F6D484:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (544)) = (int)r_v0; }
_lbl_01F6D494:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_a0 == 0) goto _lbl_01F6D4F0;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (256)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)(0 + (4));
    if (r_a1 != r_v0) goto _lbl_01F6D4F0;
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    r_v0 = (long)(0 + (0x198));
    if (r_v1 != r_v0) goto _lbl_01F6D4F0;
    r_v0 = (long)func_002FEDD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 & (0xff));
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F6D4F0;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(0 + (3));
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(int *)((char *)r_v0 + (544)) = (int)r_v1; }
_lbl_01F6D4F0:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (256)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a1 = (long)(0 + (2));
    r_v1 = (long)(0 + (3));
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (552)) = (int)r_a2; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (524)); }
    r_v0 = (long)(0 + (-1));
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (548)) = (int)r_a2; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (556)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (424)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (652)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (824)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (632)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (924)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (628)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (724)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (636)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (624)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (624)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (656)) = (int)0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (1024)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (640)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (1124)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (644)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (1224)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (648)) = (int)r_a1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (680)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (676)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (684)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (688)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (660)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (660)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (668)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (672)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s3);
    if (r_a0) { *(int *)((char *)r_a0 + (52)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(char *)((char *)r_v0 + (56)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(char *)((char *)r_v0 + (176)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(char *)((char *)r_v0 + (296)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(char *)((char *)r_v0 + (416)) = (char)0; }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s1 + r_a1);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (12)); }
    r_v0 = (long)(r_s0 + r_a1);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(int *)((char *)r_v0 + (48)) = (int)r_a0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_a0 = (long)(r_v0 + r_s3);
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (552)); }
    if (r_a1 != r_v1) { r_v0 = (long)(0 + (4)); goto _lbl_01F6D8C8; }
    r_v0 = (long)(0 + (4));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (44)); }
    if ((long)r_v1 < 0) goto _lbl_01F6DB34;
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (5968)); }
    if (r_a1) { r_v0 = *(short *)((char *)r_a1 + (20)); }
    r_at = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6DB34;
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (24)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0 == 0) goto _lbl_01F6DB34;
    if (r_v0) { r_v0 = *(short *)((char *)r_v0 + (68)); }
    if (r_a0) { *(int *)((char *)r_a0 + (52)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5968)); }
    r_v1 = (long)(r_s0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    r_a0 = (long)(r_v1 + r_s3);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (44)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = *(short *)((char *)r_v0 + (4)); }
    if (r_a0) { *(int *)((char *)r_a0 + (660)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5968)); }
    r_v1 = (long)(r_s0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    r_a0 = (long)(r_v1 + r_s3);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (44)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = *(short *)((char *)r_v0 + (6)); }
    if (r_a0) { *(int *)((char *)r_a0 + (664)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5968)); }
    r_v1 = (long)(r_s0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    r_a0 = (long)(r_v1 + r_s3);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (44)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (132)); }
    if (r_a0) { *(int *)((char *)r_a0 + (668)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5968)); }
    r_v1 = (long)(r_s0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    r_a0 = (long)(r_v1 + r_s3);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (44)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (136)); }
    if (r_a0) { *(int *)((char *)r_a0 + (672)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v1);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (660)); }
    if ((long)r_a1 <= 0) goto _lbl_01F6D814;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)(r_v1 + r_s1);
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a2 = (long)(r_v0 + (0x38));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a3 = (long)(0 + (0x78));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F6D814:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v1);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(char *)((char *)r_v0 + (56)); }
    if (r_v0 != 0) goto _lbl_01F6D848;
    r_v0 = (long)(r_v1 + r_s1);
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)(r_v0 + r_s3);
    r_a0 = (long)(r_v0 + (0x38));
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x69d8));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6D848:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v1);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (660)); }
    if ((long)r_v0 <= 0) goto _lbl_01F6D888;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(r_v0 + (0x2328));
    r_v0 = (long)(r_v1 + r_s1);
    r_v0 = (long)(r_v0 + r_s6);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_v0 = (long)(r_v0 + r_s3);
    r_a2 = (long)(r_v0 + (0xb0));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a3 = (long)(0 + (0x78));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F6D888:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v1);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(char *)((char *)r_v0 + (176)); }
    if (r_v0 != 0) goto _lbl_01F6DB34;
    r_v0 = (long)(r_v1 + r_s1);
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)(r_v0 + r_s3);
    r_a0 = (long)(r_v0 + (0xb0));
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x69d8));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
    goto _lbl_01F6DB38;
    r_v0 = (long)(0 + (4));
_lbl_01F6D8C8:
    if (r_a1 != r_v0) goto _lbl_01F6DB34;
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (5960)); }
    if (r_sp) { *(char *)((char *)r_sp + (384)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (44)); }
    if ((long)r_v1 < 0) goto _lbl_01F6DB34;
    if (r_s2) { r_v0 = *(short *)((char *)r_s2 + (27392)); }
    r_at = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6DB34;
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_002D3000((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(int *)((char *)r_v0 + (660)) = (int)r_v1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a1 = *(short *)((char *)r_v0 + (44)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_002D3000((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { *(int *)((char *)r_v0 + (664)) = (int)r_v1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a1 = *(short *)((char *)r_v0 + (44)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_002D2EB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(r_s0 + r_v1);
    r_v1 = (long)(r_v1 + r_s3);
    if (r_v1) { *(int *)((char *)r_v1 + (668)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a1 = *(short *)((char *)r_v0 + (44)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_002D2F00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(r_s0 + r_v1);
    r_v1 = (long)(r_v1 + r_s3);
    if (r_v1) { *(int *)((char *)r_v1 + (672)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v1 = (long)(r_v0 + r_s3);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (44)); }
    r_v0 = (long)((unsigned long)r_v0 << (6));
    r_v0 = (long)(r_s2 + r_v0);
    if (r_v0) { r_v0 = *(short *)((char *)r_v0 + (38)); }
    if (r_v1) { *(int *)((char *)r_v1 + (52)) = (int)r_v0; }
    if (r_sp) { *(char *)((char *)r_sp + (384)) = (char)0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (660)); }
    if ((long)r_a1 <= 0) { if (r_sp) { *(int *)((char *)r_sp + (236)) = (int)0; } goto _lbl_01F6D9FC; }
    if (r_sp) { *(int *)((char *)r_sp + (236)) = (int)0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a2 = (long)(r_sp + (0x180));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a3 = (long)(0 + (0x200));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F6D9FC:
    if (r_sp) { r_v0 = *(char *)((char *)r_sp + (384)); }
    if (r_v0 != 0) goto _lbl_01F6DA24;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a1 = *(short *)((char *)r_v0 + (44)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_002D2FF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (236)) = (int)r_v0; }
_lbl_01F6DA24:
    if (r_sp) { r_v0 = *(char *)((char *)r_sp + (384)); }
    if (r_v0 == 0) goto _lbl_01F6DA54;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_a1 = (long)(r_sp + (0x180));
    r_v0 = (long)(r_v0 + r_s1);
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)(r_v0 + r_s3);
    r_a0 = (long)(r_v0 + (0x38));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(char *)((char *)r_sp + (384)) = (char)0; }
    goto _lbl_01F6DA80;
_lbl_01F6DA54:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (236)); }
    if (r_v0 == 0) goto _lbl_01F6DA7C;
    r_a1 = (long)(r_v0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_v0 + r_s1);
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)(r_v0 + r_s3);
    r_a0 = (long)(r_v0 + (0x38));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6DA7C:
    if (r_sp) { *(char *)((char *)r_sp + (384)) = (char)0; }
_lbl_01F6DA80:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (660)); }
    if ((long)r_v0 <= 0) { if (r_sp) { *(int *)((char *)r_sp + (284)) = (int)0; } goto _lbl_01F6DAB4; }
    if (r_sp) { *(int *)((char *)r_sp + (284)) = (int)0; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(r_v0 + (0x2710));
    r_a2 = (long)(r_sp + (0x180));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a3 = (long)(0 + (0x200));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F6DAB4:
    if (r_sp) { r_v0 = *(char *)((char *)r_sp + (384)); }
    if (r_v0 != 0) goto _lbl_01F6DADC;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a1 = *(short *)((char *)r_v0 + (44)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_002D2FF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (284)) = (int)r_v0; }
_lbl_01F6DADC:
    if (r_sp) { r_v0 = *(char *)((char *)r_sp + (384)); }
    if (r_v0 == 0) goto _lbl_01F6DB0C;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_a1 = (long)(r_sp + (0x180));
    r_v0 = (long)(r_v0 + r_s1);
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)(r_v0 + r_s3);
    r_a0 = (long)(r_v0 + (0xb0));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6DB34;
_lbl_01F6DB0C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (284)); }
    if (r_v0 == 0) goto _lbl_01F6DB34;
    r_a1 = (long)(r_v0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_v0 + r_s1);
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)(r_v0 + r_s3);
    r_a0 = (long)(r_v0 + (0xb0));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6DB34:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
_lbl_01F6DB38:
    r_s7 = (long)(r_s7 + (1));
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)r_v0; }
_lbl_01F6DB44:
    r_v0 = (long)((long)r_s7 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(0 + (-1)); goto _lbl_01F6D2EC; }
    r_v0 = (long)(0 + (-1));
    r_s8 = (long)(r_s8 + (1));
_lbl_01F6DB54:
    r_v0 = (long)((long)r_s8 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s8 << (2)); goto _lbl_01F6D2C4; }
    r_v0 = (long)((unsigned long)r_s8 << (2));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (160)); }
    if (r_s4) { r_s4 = *(int *)((char *)r_s4 + (1332)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (160)) = (int)r_v0; }
_lbl_01F6DB70:
    if (r_s4 != 0) goto _lbl_01F6D20C;
    r_s4 = (long)(0 | 0);
_lbl_01F6DB7C:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2080)); }
    goto _lbl_01F6DFB8;
    r_v0 = (long)(0 + (0x405c));
_lbl_01F6DB88:
    r_s7 = (long)(0 | 0);
    goto _lbl_01F6DFA4;
    r_v0 = (long)(0 + (0xcd0));
_lbl_01F6DB98:
    /* unhandled: mult $ac2 $s7 $v0 */
    r_s2 = (long)(0 | 0);
    r_s0 = (long)(r_s8 + r_v0);
    goto _lbl_01F6DF94;
_lbl_01F6DBA8:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)((unsigned long)r_s2 << (2));
    r_v0 = (long)(r_v0 + r_s2);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(r_v0 + r_s2);
    r_v1 = (long)(r_s0 + r_v1);
    r_s1 = (long)((unsigned long)r_v0 << (4));
    r_v0 = (long)(r_v1 + r_s1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (44)); }
    if ((long)r_a1 < 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F6DF94; }
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (552)); }
    r_v0 = (long)(0 + (4));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (3)); goto _lbl_01F6DD78; }
    r_v0 = (long)(0 + (3));
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_sp + (0x120));
    r_a2 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F79140((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6DF90;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_sp) { r_v1 = *(unsigned char *)((char *)r_sp + (288)); }
    r_s6 = (long)(r_s0 + r_s1);
    r_s3 = (long)(0 | 0);
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(char *)((char *)r_v0 + (560)) = (char)r_v1; }
    goto _lbl_01F6DD5C;
    r_s1 = (long)((unsigned long)r_s3 << (2));
_lbl_01F6DC2C:
    r_v1 = (long)(r_s1 + r_sp);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_v1 + (0x120));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (4)); }
    r_a2 = (long)(0 + (3));
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (564)) = (int)r_v1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (604)) = (int)0; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (44)); }
    if (r_v1 == r_a2) { r_a1 = (long)(r_a0 + (4)); goto _lbl_01F6DCF0; }
    r_a1 = (long)(r_a0 + (4));
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F6DCBC;
    r_a2 = (long)(0 + (1));
    if (r_v1 == r_a2) goto _lbl_01F6DC88;
    r_a1 = (long)(0 + (-1));
    goto _lbl_01F6DD2C;
_lbl_01F6DC88:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(0 + (1));
    r_a0 = (long)(r_s6 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)r_v1; }
    goto _lbl_01F6DD58;
_lbl_01F6DCBC:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(0 + (3));
    r_a0 = (long)(r_s6 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)r_v1; }
    goto _lbl_01F6DD58;
_lbl_01F6DCF0:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(0 + (4));
    r_a0 = (long)(r_s6 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)r_v1; }
    goto _lbl_01F6DD58;
    r_a1 = (long)(0 + (-1));
_lbl_01F6DD2C:
    r_a0 = (long)(r_s5 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(r_s6 + r_v1);
    r_v1 = (long)(r_v1 + r_s1);
    if (r_v1) { *(int *)((char *)r_v1 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)0; }
_lbl_01F6DD58:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6DD5C:
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (288)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_s1 = (long)((unsigned long)r_s3 << (2)); goto _lbl_01F6DC2C; }
    r_s1 = (long)((unsigned long)r_s3 << (2));
    goto _lbl_01F6DF90;
    r_v0 = (long)(0 + (3));
_lbl_01F6DD78:
    if (r_v1 != r_v0) goto _lbl_01F6DF90;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_s3 = (long)(r_v0 | 0);
    r_a1 = (long)(r_sp + (0x120));
    r_a2 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78F30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6DF14;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_sp) { r_v1 = *(unsigned char *)((char *)r_sp + (288)); }
    r_s6 = (long)(r_s0 + r_s1);
    r_s3 = (long)(0 | 0);
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(char *)((char *)r_v0 + (560)) = (char)r_v1; }
    goto _lbl_01F6DEFC;
    r_s1 = (long)((unsigned long)r_s3 << (2));
_lbl_01F6DDCC:
    r_v1 = (long)(r_s1 + r_sp);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_v1 + (0x120));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (4)); }
    r_a2 = (long)(0 + (3));
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (564)) = (int)r_v1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (604)) = (int)0; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (44)); }
    if (r_v1 == r_a2) { r_a1 = (long)(r_a0 + (4)); goto _lbl_01F6DE90; }
    r_a1 = (long)(r_a0 + (4));
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F6DE5C;
    r_a2 = (long)(0 + (1));
    if (r_v1 == r_a2) goto _lbl_01F6DE28;
    r_a1 = (long)(0 + (-1));
    goto _lbl_01F6DECC;
_lbl_01F6DE28:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(0 + (1));
    r_a0 = (long)(r_s6 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)r_v1; }
    goto _lbl_01F6DEF8;
_lbl_01F6DE5C:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(0 + (3));
    r_a0 = (long)(r_s6 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)r_v1; }
    goto _lbl_01F6DEF8;
_lbl_01F6DE90:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(0 + (4));
    r_a0 = (long)(r_s6 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)r_v1; }
    goto _lbl_01F6DEF8;
    r_a1 = (long)(0 + (-1));
_lbl_01F6DECC:
    r_a0 = (long)(r_s5 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(r_s6 + r_v1);
    r_v1 = (long)(r_v1 + r_s1);
    if (r_v1) { *(int *)((char *)r_v1 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s6 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)0; }
_lbl_01F6DEF8:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6DEFC:
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (288)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_s1 = (long)((unsigned long)r_s3 << (2)); goto _lbl_01F6DDCC; }
    r_s1 = (long)((unsigned long)r_s3 << (2));
    goto _lbl_01F6DF90;
_lbl_01F6DF14:
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    r_v0 = (long)(0 + (0x218));
    if (r_v1 == r_v0) goto _lbl_01F6DF3C;
    r_v0 = (long)(0 + (0x210));
    if (r_v1 == r_v0) goto _lbl_01F6DF3C;
    r_v0 = (long)(0 + (0x214));
    if (r_v1 != r_v0) goto _lbl_01F6DF90;
_lbl_01F6DF3C:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_a1 = (long)(0 + (0x15));
    r_a2 = (long)(0 + (3));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (564)) = (int)r_a1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)r_a2; }
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2084)); }
    r_v1 = (long)(0 + (1));
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (604)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(char *)((char *)r_v0 + (560)) = (char)r_v1; }
_lbl_01F6DF90:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F6DF94:
    r_v0 = (long)((long)r_s2 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6DBA8;
    r_s7 = (long)(r_s7 + (1));
_lbl_01F6DFA4:
    r_v0 = (long)((long)r_s7 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(0 + (0xcd0)); goto _lbl_01F6DB98; }
    r_v0 = (long)(0 + (0xcd0));
    r_s4 = (long)(r_s4 + (1));
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2080)); }
_lbl_01F6DFB8:
    r_v0 = (long)((long)r_s4 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(0 + (0x405c)); goto _lbl_01F6DB88; }
    r_v0 = (long)(0 + (0x405c));
    r_s3 = (long)(0 | 0);
    goto _lbl_01F6E148;
    r_v0 = (long)((unsigned long)r_s3 << (5));
_lbl_01F6DFD0:
    r_v1 = (long)(r_v0 - r_s3);
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 - r_v1);
    r_s0 = (long)((unsigned long)r_v0 << (3));
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_v0 + r_s0);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (24)); }
    if ((long)r_a1 < 0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F6E148; }
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (532)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F6E144;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_sp + (0x120));
    r_a2 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F79330((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6E144;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    if (r_sp) { r_v1 = *(unsigned char *)((char *)r_sp + (288)); }
    r_s2 = (long)(0 | 0);
    r_v0 = (long)(r_v0 + r_s0);
    if (r_v0) { *(char *)((char *)r_v0 + (540)) = (char)r_v1; }
    goto _lbl_01F6E134;
    r_s1 = (long)((unsigned long)r_s2 << (2));
_lbl_01F6E044:
    r_v1 = (long)(r_s1 + r_sp);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_a0 = (long)(r_v1 + (0x120));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (4)); }
    r_a2 = (long)(0 + (3));
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (544)) = (int)r_v1; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (584)) = (int)0; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (44)); }
    if (r_v1 == r_a2) { r_a1 = (long)(r_a0 + (4)); goto _lbl_01F6E0C8; }
    r_a1 = (long)(r_a0 + (4));
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F6E094;
    r_a1 = (long)(0 + (-1));
    goto _lbl_01F6E104;
_lbl_01F6E094:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(0 + (3));
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (584)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (564)) = (int)r_v1; }
    goto _lbl_01F6E130;
_lbl_01F6E0C8:
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(0 + (4));
    r_a0 = (long)(r_s0 + r_a0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_a0) { *(int *)((char *)r_a0 + (584)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (564)) = (int)r_v1; }
    goto _lbl_01F6E130;
    r_a1 = (long)(0 + (-1));
_lbl_01F6E104:
    r_a0 = (long)(r_s5 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(r_s0 + r_v1);
    r_v1 = (long)(r_v1 + r_s1);
    if (r_v1) { *(int *)((char *)r_v1 + (584)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)(r_v0 + r_s1);
    if (r_v0) { *(int *)((char *)r_v0 + (564)) = (int)0; }
_lbl_01F6E130:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F6E134:
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (288)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_s1 = (long)((unsigned long)r_s2 << (2)); goto _lbl_01F6E044; }
    r_s1 = (long)((unsigned long)r_s2 << (2));
_lbl_01F6E144:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6E148:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2072)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (5)); goto _lbl_01F6DFD0; }
    r_v0 = (long)((unsigned long)r_s3 << (5));
    r_v0 = (long)(0 + (1));
_lbl_01F6E15C:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x380));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 16: thelp_func_01F6E18C (VMA: 0x01F6E18C, size: 396 bytes) */
void *thelp_func_01F6E18C(void *a0, void *a1, void *a2, void *a3) {
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
    r_t0 = (long)(0 + (0x405c));
    r_a3 = (long)(0 + (0xcd0));
    r_a1 = (long)(0 + (1));
    r_t1 = (long)(0 | 0);
    goto _lbl_01F6E238;
_lbl_01F6E1A8:
    r_t4 = (long)(0 + (1));
    r_t2 = (long)(0 | 0);
    goto _lbl_01F6E214;
_lbl_01F6E1B8:
    r_t3 = (long)(0 | 0);
    goto _lbl_01F6E204;
_lbl_01F6E1C0:
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (2084)); }
    r_v1 = (long)((unsigned long)r_t3 << (2));
    r_v1 = (long)(r_v1 + r_t3);
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(r_v1 + r_t3);
    r_a2 = (long)(r_a2 + r_t6);
    r_a2 = (long)(r_a2 + r_t5);
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_a2 = (long)(r_a2 + r_v1);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (624)); }
    if (r_v1 != 0) { r_t3 = (long)(r_t3 + (1)); goto _lbl_01F6E204; }
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (44)); }
    if ((long)r_v1 < 0) goto _lbl_01F6E200;
    r_t4 = (long)(0 | 0);
_lbl_01F6E200:
    r_t3 = (long)(r_t3 + (1));
_lbl_01F6E204:
    r_v1 = (long)((long)r_t3 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6E1C0;
    r_t2 = (long)(r_t2 + (1));
_lbl_01F6E214:
    r_v1 = (long)((long)r_t2 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6E1B8;
    if (r_t4 != r_a1) { r_t1 = (long)(r_t1 + (1)); goto _lbl_01F6E238; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2084)); }
    r_v1 = (long)(r_v1 + r_t6);
    if (r_v1) { *(int *)((char *)r_v1 + (24)) = (int)r_a1; }
    r_t1 = (long)(r_t1 + (1));
_lbl_01F6E238:
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2080)); }
    r_v1 = (long)((long)r_t1 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6E1A8;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2076)); }
    r_t3 = (long)(0 + (1));
    r_t1 = (long)(0 + (0x405c));
    r_a1 = (long)(0 | 0);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (4)); }
    r_a2 = (long)(0 | 0);
    r_t2 = (long)(r_t3 | 0);
    goto _lbl_01F6E300;
    r_a3 = (long)((unsigned long)r_a2 << (5));
_lbl_01F6E26C:
    r_t0 = (long)(r_a3 - r_a2);
    r_a3 = (long)((unsigned long)r_t0 << (2));
    r_a3 = (long)(r_a3 - r_t0);
    r_t0 = (long)((unsigned long)r_a3 << (3));
    if (r_a0) { r_a3 = *(int *)((char *)r_a0 + (2076)); }
    r_a3 = (long)(r_a3 + r_t0);
    if (r_a3) { r_a3 = *(int *)((char *)r_a3 + (4)); }
    if (r_v1 == r_a3) goto _lbl_01F6E2E0;
    if (r_t3 != 0) { r_a3 = (long)((unsigned long)r_a1 << (5)); goto _lbl_01F6E2B4; }
    r_t3 = (long)(0 + (1));
    r_v1 = (long)(r_a3 | 0);
    r_a1 = (long)(r_a2 | 0);
    goto _lbl_01F6E2E0;
_lbl_01F6E2A8:
    if (r_a3) { *(int *)((char *)r_a3 + (700)) = (int)r_t2; }
    r_a1 = (long)(r_a2 | 0);
    r_a3 = (long)((unsigned long)r_a1 << (5));
_lbl_01F6E2B4:
    r_t0 = (long)(r_a3 - r_a1);
    r_a3 = (long)((unsigned long)r_t0 << (2));
    r_a3 = (long)(r_a3 - r_t0);
    r_t0 = (long)((unsigned long)r_a3 << (3));
    if (r_a0) { r_a3 = *(int *)((char *)r_a0 + (2076)); }
    r_a3 = (long)(r_a3 + r_t0);
    if (r_a3) { r_t0 = *(int *)((char *)r_a3 + (4)); }
    if (r_v1 == r_t0) goto _lbl_01F6E2A8;
    r_t3 = (long)(0 + (1));
    r_v1 = (long)(r_t0 | 0);
_lbl_01F6E2E0:
    if (r_a0) { r_a3 = *(int *)((char *)r_a0 + (2084)); }
    r_a3 = (long)(r_a3 + r_t0);
    if (r_a3) { r_a3 = *(int *)((char *)r_a3 + (24)); }
    if (r_a3 != 0) { r_a2 = (long)(r_a2 + (1)); goto _lbl_01F6E300; }
    r_t3 = (long)(0 | 0);
    r_a2 = (long)(r_a2 + (1));
_lbl_01F6E300:
    if (r_a0) { r_a3 = *(int *)((char *)r_a0 + (2072)); }
    r_a3 = (long)((long)r_a2 < (long)r_a3 ? 1 : 0);
    if (r_a3 != 0) { r_a3 = (long)((unsigned long)r_a2 << (5)); goto _lbl_01F6E26C; }
    r_a3 = (long)((unsigned long)r_a2 << (5));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 17: thelp_func_01F6E318 (VMA: 0x01F6E318, size: 544 bytes) */
void *thelp_func_01F6E318(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0;
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
    r_sp = (long)(r_sp + (-0xa0));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s7 = (long)(r_a0 | 0);
    r_s0 = (long)(0 | 0);
    goto _lbl_01F6E3E8;
    r_v1 = (long)((unsigned long)r_s0 << (5));
_lbl_01F6E35C:
    r_a0 = (long)(r_v1 - r_s0);
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 - r_a0);
    if (r_s7) { r_a0 = *(int *)((char *)r_s7 + (2076)); }
    r_s1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(0 + (1));
    r_a1 = (long)(r_a0 + r_s1);
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (532)); }
    if (r_a0 != r_v1) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F6E3E8; }
    r_a0 = (long)(r_a1 + (0x9c));
    r_a1 = (long)(0 + (0xa));
    r_v0 = (long)func_0011A8E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s2 != 0) goto _lbl_01F6E3B8;
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (2076)); }
    r_v0 = (long)(r_v0 + r_s1);
    r_a0 = (long)(r_v0 + (0x114));
    r_a1 = (long)(r_v0 + (0x9c));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6E3E4;
_lbl_01F6E3B8:
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (2076)); }
    r_v0 = (long)(r_v0 + r_s1);
    r_a1 = (long)(r_v0 + (0x9c));
    r_a0 = (long)(r_v0 + (0x114));
    r_a2 = (long)(r_s2 - r_a1);
    r_v0 = (long)func_0011AE08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (2076)); }
    r_a1 = (long)(r_s2 + (1));
    r_v0 = (long)(r_v0 + r_s1);
    r_a0 = (long)(r_v0 + (0x18c));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6E3E4:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F6E3E8:
    if (r_s7) { r_v1 = *(int *)((char *)r_s7 + (2072)); }
    r_v1 = (long)((long)r_s0 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_s0 << (5)); goto _lbl_01F6E35C; }
    r_v1 = (long)((unsigned long)r_s0 << (5));
    r_s5 = (long)(0 | 0);
    goto _lbl_01F6E4F8;
    r_v1 = (long)(0 + (0x405c));
_lbl_01F6E404:
    r_s0 = (long)(0 | 0);
    goto _lbl_01F6E4E8;
    r_v1 = (long)(0 + (0xcd0));
_lbl_01F6E414:
    r_s1 = (long)(0 | 0);
    r_s8 = (long)(r_s2 + r_s3);
    goto _lbl_01F6E4D8;
    r_v1 = (long)((unsigned long)r_s1 << (2));
_lbl_01F6E428:
    r_v1 = (long)(r_v1 + r_s1);
    if (r_s7) { r_a0 = *(int *)((char *)r_s7 + (2084)); }
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(r_v1 + r_s1);
    r_s4 = (long)((unsigned long)r_v1 << (4));
    r_v1 = (long)(r_s8 + r_a0);
    r_v1 = (long)(r_v1 + r_s4);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (552)); }
    if (r_v1 == 0) { r_s1 = (long)(r_s1 + (1)); goto _lbl_01F6E4D8; }
    r_v0 = (long)(r_a0 + r_s2);
    r_v0 = (long)(r_v0 + r_s3);
    r_v0 = (long)(r_v0 + r_s4);
    r_a0 = (long)(r_v0 + (0xb0));
    r_a1 = (long)(0 + (0xa));
    r_v0 = (long)func_0011A8E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if (r_s6 != 0) goto _lbl_01F6E498;
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (2084)); }
    r_v0 = (long)(r_v0 + r_s2);
    r_v0 = (long)(r_v0 + r_s3);
    r_v0 = (long)(r_v0 + r_s4);
    r_a0 = (long)(r_v0 + (0x128));
    r_a1 = (long)(r_v0 + (0xb0));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F6E4D4;
_lbl_01F6E498:
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (2084)); }
    r_v0 = (long)(r_v0 + r_s2);
    r_v0 = (long)(r_v0 + r_s3);
    r_v0 = (long)(r_v0 + r_s4);
    r_a1 = (long)(r_v0 + (0xb0));
    r_a0 = (long)(r_v0 + (0x128));
    r_a2 = (long)(r_s6 - r_a1);
    r_v0 = (long)func_0011AE08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (2084)); }
    r_a1 = (long)(r_s6 + (1));
    r_v0 = (long)(r_v0 + r_s2);
    r_v0 = (long)(r_v0 + r_s3);
    r_v0 = (long)(r_v0 + r_s4);
    r_a0 = (long)(r_v0 + (0x1a0));
    r_v0 = (long)func_0011ABBC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F6E4D4:
    r_s1 = (long)(r_s1 + (1));
_lbl_01F6E4D8:
    r_v1 = (long)((long)r_s1 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_s1 << (2)); goto _lbl_01F6E428; }
    r_v1 = (long)((unsigned long)r_s1 << (2));
    r_s0 = (long)(r_s0 + (1));
_lbl_01F6E4E8:
    r_v1 = (long)((long)r_s0 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)(0 + (0xcd0)); goto _lbl_01F6E414; }
    r_v1 = (long)(0 + (0xcd0));
    r_s5 = (long)(r_s5 + (1));
_lbl_01F6E4F8:
    if (r_s7) { r_v1 = *(int *)((char *)r_s7 + (2080)); }
    r_v1 = (long)((long)r_s5 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)(0 + (0x405c)); goto _lbl_01F6E404; }
    r_v1 = (long)(0 + (0x405c));
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0xa0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 18: thelp_func_01F6E538 (VMA: 0x01F6E538, size: 1312 bytes) */
void *thelp_func_01F6E538(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    (void)r_t7;
    r_sp = (long)(r_sp + (-0xb0));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s6 = (long)(r_a0 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_v0 = (long)func_01F6FAE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_a1 = *(int *)((char *)r_s6 + (2076)); }
    r_a0 = (long)(0 + (0xa));
    r_v1 = (long)(0 | 0);
    if (r_a1) { r_t0 = *(int *)((char *)r_a1 + (4)); }
    if (r_s6) { *(int *)((char *)r_s6 + (3724)) = (int)r_a0; }
    goto _lbl_01F6E5F8;
_lbl_01F6E58C:
    r_a1 = (long)(r_a0 - r_v1);
    r_a0 = (long)((unsigned long)r_a1 << (2));
    r_a0 = (long)(r_a0 - r_a1);
    r_t1 = (long)((unsigned long)r_a0 << (3));
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2076)); }
    r_a0 = (long)(r_a0 + r_t1);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (4)); }
    if (r_t0 == r_a0) goto _lbl_01F6E5CC;
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (3724)); }
    r_a0 = (long)(r_a0 + (0xa));
    if (r_s6) { *(int *)((char *)r_s6 + (3724)) = (int)r_a0; }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2076)); }
    r_a0 = (long)(r_a0 + r_t1);
    if (r_a0) { r_t0 = *(int *)((char *)r_a0 + (4)); }
_lbl_01F6E5CC:
    if (r_s6) { r_a3 = *(int *)((char *)r_s6 + (3648)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2076)); }
    if (r_s6) { r_a2 = *(int *)((char *)r_s6 + (3724)); }
    if (r_s6) { r_a1 = *(int *)((char *)r_s6 + (3728)); }
    r_a3 = (long)(r_a3 + (0x1a));
    r_a0 = (long)(r_a0 + r_t1);
    r_a2 = (long)(r_a2 + r_a3);
    r_a1 = (long)(r_a1 + r_a2);
    r_v1 = (long)(r_v1 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (656)) = (int)r_a1; }
_lbl_01F6E5F8:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2072)); }
    r_a0 = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
    if (r_a0 != 0) { r_a0 = (long)((unsigned long)r_v1 << (5)); goto _lbl_01F6E58C; }
    r_a0 = (long)((unsigned long)r_v1 << (5));
    if (r_s6) { r_a1 = *(int *)((char *)r_s6 + (2084)); }
    r_a0 = (long)(0 + (0xa));
    r_v1 = (long)(0 + (0x405c));
    r_t2 = (long)(0 + (0xcd0));
    if (r_a1) { r_a2 = *(int *)((char *)r_a1 + (12)); }
    r_a3 = (long)(0 | 0);
    if (r_s6) { *(int *)((char *)r_s6 + (3724)) = (int)r_a0; }
    goto _lbl_01F6E6F0;
_lbl_01F6E628:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2084)); }
    r_a0 = (long)(r_a0 + r_a1);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (12)); }
    if (r_a2 == r_a0) goto _lbl_01F6E65C;
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (3724)); }
    r_a0 = (long)(r_a0 + (0xa));
    if (r_s6) { *(int *)((char *)r_s6 + (3724)) = (int)r_a0; }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2084)); }
    r_a0 = (long)(r_a0 + r_a1);
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (12)); }
_lbl_01F6E65C:
    if (r_s6) { r_t5 = *(int *)((char *)r_s6 + (2084)); }
    if (r_s6) { r_t1 = *(int *)((char *)r_s6 + (3648)); }
    if (r_s6) { r_t4 = *(int *)((char *)r_s6 + (3728)); }
    if (r_s6) { r_t3 = *(int *)((char *)r_s6 + (3656)); }
    if (r_s6) { r_t0 = *(int *)((char *)r_s6 + (3724)); }
    r_a0 = (long)(0 | 0);
    r_t7 = (long)(r_t5 + r_a1);
    if (r_t7) { r_t5 = *(int *)((char *)r_t7 + (4)); }
    r_t6 = (long)(r_t1 + (0x1a));
    if (r_t7) { r_t1 = *(int *)((char *)r_t7 + (8)); }
    r_t4 = (long)(r_t4 + r_t5);
    r_t4 = (long)(r_t4 + r_t1);
    r_t4 = (long)(r_t4 + r_t0);
    goto _lbl_01F6E6E0;
_lbl_01F6E69C:
    r_t3 = (long)(0 | 0);
    r_t5 = (long)(r_a1 + r_t0);
    goto _lbl_01F6E6D0;
_lbl_01F6E6A8:
    if (r_s6) { r_t1 = *(int *)((char *)r_s6 + (2084)); }
    r_t0 = (long)((unsigned long)r_t3 << (2));
    r_t0 = (long)(r_t0 + r_t3);
    r_t0 = (long)((unsigned long)r_t0 << (3));
    r_t0 = (long)(r_t0 + r_t3);
    r_t1 = (long)(r_t5 + r_t1);
    r_t0 = (long)((unsigned long)r_t0 << (4));
    r_t0 = (long)(r_t1 + r_t0);
    r_t3 = (long)(r_t3 + (1));
    if (r_t0) { *(int *)((char *)r_t0 + (676)) = (int)r_t4; }
_lbl_01F6E6D0:
    r_t0 = (long)((long)r_t3 < (long)(5) ? 1 : 0);
    if (r_t0 != 0) goto _lbl_01F6E6A8;
    r_a0 = (long)(r_a0 + (1));
_lbl_01F6E6E0:
    r_t0 = (long)((long)r_a0 < (long)(5) ? 1 : 0);
    if (r_t0 != 0) goto _lbl_01F6E69C;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F6E6F0:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2080)); }
    r_a0 = (long)((long)r_a3 < (long)r_a0 ? 1 : 0);
    if (r_a0 != 0) { r_s2 = (long)(0 | 0); goto _lbl_01F6E628; }
    r_s2 = (long)(0 | 0);
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2072)); }
    goto _lbl_01F6E7D0;
_lbl_01F6E708:
    r_a0 = (long)(r_v1 - r_s2);
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 - r_a0);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2076)); }
    r_s1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(0 + (1));
    r_a1 = (long)(r_a0 + r_s1);
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (672)); }
    if (r_a0 != r_v1) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F6E7CC; }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (8)); }
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if ((long)r_s0 >= 0) goto _lbl_01F6E760;
    /* unhandled: mtc1 $zero $f12 */
    r_v0 = (long)((unsigned long)r_s0 << (2));
    goto _lbl_01F6E798;
_lbl_01F6E760:
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2076)); }
    r_v0 = (long)(0x4110 << 16);
    /* unhandled: mtc1 $v0 $f12 */
    r_v0 = (long)(r_v1 + r_s1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (516)); }
    r_s3 = (long)(r_v0 + (-1));
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (3644)); }
    r_v0 = (long)(r_v1 + r_v0);
    /* unhandled: mult $ac2 $v0 $s3 */
    /* unhandled: mtc1 $v0 $f0 */
    /* unhandled: cvt.s.w $f12 $f0 */
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F6E798:
    r_v0 = (long)(r_s6 + r_v0);
    /* unhandled: lwc1 $f0 0xe74($v0) */
    r_v0 = (long)(0x4040 << 16);
    /* unhandled: mtc1 $v0 $f1 */
    /* unhandled: cvt.s.w $f0 $f0 */
    /* unhandled: add.s $f12 $f12 $f1 */
    /* unhandled: add.s $f12 $f12 $f0 */
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2076)); }
    r_v1 = (long)(r_v1 + r_s1);
    if (r_v1) { *(int *)((char *)r_v1 + (660)) = (int)r_v0; }
    r_s2 = (long)(r_s2 + (1));
_lbl_01F6E7CC:
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2072)); }
_lbl_01F6E7D0:
    r_v1 = (long)((long)r_s2 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_s2 << (5)); goto _lbl_01F6E708; }
    r_v1 = (long)((unsigned long)r_s2 << (5));
    r_s3 = (long)(0 | 0);
    goto _lbl_01F6E970;
_lbl_01F6E7E4:
    r_s4 = (long)(0 | 0);
    goto _lbl_01F6E960;
_lbl_01F6E7F0:
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (2084)); }
    r_v0 = (long)(r_s1 + r_v0);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (16)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != r_s4) { r_s8 = (long)(0 | 0); goto _lbl_01F6E840; }
    r_s8 = (long)(0 | 0);
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2084)); }
    r_v0 = (long)(0x4110 << 16);
    /* unhandled: mtc1 $v0 $f12 */
    r_v0 = (long)(r_s1 + r_v1);
    r_s0 = (long)(r_v0 + (0x14));
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (3644)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    r_a0 = (long)(r_a0 + r_v0);
_lbl_01F6E840:
    r_v1 = (long)(0 + (0xcd0));
    /* unhandled: mult $ac3 $s4 $v1 */
    r_s5 = (long)(0 | 0);
    r_s0 = (long)(r_s1 + r_v1);
    goto _lbl_01F6E950;
_lbl_01F6E854:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2084)); }
    r_v1 = (long)((unsigned long)r_s5 << (2));
    r_v1 = (long)(r_v1 + r_s5);
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(r_v1 + r_s5);
    r_s2 = (long)((unsigned long)r_v1 << (4));
    r_a0 = (long)(r_s0 + r_a0);
    r_a1 = (long)(r_a0 + r_s2);
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (552)); }
    r_v1 = (long)(0 + (4));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (3)); goto _lbl_01F6E894; }
    r_v1 = (long)(0 + (3));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (5)); goto _lbl_01F6E894; }
    r_v1 = (long)(0 + (5));
    if (r_a0 != r_v1) { r_s5 = (long)(r_s5 + (1)); goto _lbl_01F6E950; }
_lbl_01F6E894:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (540)); }
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if ((long)r_s7 >= 0) goto _lbl_01F6E8C4;
    /* unhandled: mtc1 $zero $f12 */
    r_v0 = (long)((unsigned long)r_s7 << (2));
    goto _lbl_01F6E918;
_lbl_01F6E8C4:
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2084)); }
    r_v0 = (long)(0x4110 << 16);
    /* unhandled: mtc1 $v0 $f12 */
    r_v0 = (long)(r_s0 + r_v1);
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (536)); }
    r_v0 = (long)(r_v0 + (-1));
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (3652)); }
    /* unhandled: mtc1 $fp $f0 */
    /* unhandled: cvt.s.w $f0 $f0 */
    r_v1 = (long)(r_v1 + r_v0);
    /* unhandled: ld.b $w2 -0x5e($zero) */
    /* unhandled: mult $ac2 $v0 $v1 */
    /* unhandled: mtc1 $v0 $f1 */
    /* unhandled: cvt.s.w $f1 $f1 */
    /* unhandled: add.s $f12 $f0 $f1 */
    r_v0 = (long)((unsigned long)r_s7 << (2));
_lbl_01F6E918:
    r_v0 = (long)(r_s6 + r_v0);
    /* unhandled: lwc1 $f0 0xe74($v0) */
    r_v0 = (long)(0x4040 << 16);
    /* unhandled: mtc1 $v0 $f1 */
    /* unhandled: cvt.s.w $f0 $f0 */
    /* unhandled: add.s $f12 $f12 $f1 */
    /* unhandled: add.s $f12 $f12 $f0 */
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2084)); }
    r_v1 = (long)(r_s0 + r_v1);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (680)) = (int)r_v0; }
    r_s5 = (long)(r_s5 + (1));
_lbl_01F6E950:
    r_v1 = (long)((long)r_s5 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6E854;
    r_s4 = (long)(r_s4 + (1));
_lbl_01F6E960:
    r_v1 = (long)((long)r_s4 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6E7F0;
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6E970:
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2080)); }
    r_v1 = (long)((long)r_s3 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)(0 + (0x405c)); goto _lbl_01F6E7E4; }
    r_v1 = (long)(0 + (0x405c));
    r_t0 = (long)(0 + (0x405c));
    r_a3 = (long)(0 + (0xcd0));
    r_a0 = (long)(0 + (1));
    r_t4 = (long)(0 | 0);
    goto _lbl_01F6EA18;
_lbl_01F6E994:
    r_t1 = (long)(0 | 0);
    r_t5 = (long)(0 | 0);
    goto _lbl_01F6EA08;
_lbl_01F6E9A0:
    r_t6 = (long)(0 | 0);
    goto _lbl_01F6E9F0;
_lbl_01F6E9A8:
    if (r_s6) { r_a1 = *(int *)((char *)r_s6 + (2084)); }
    r_v1 = (long)((unsigned long)r_t6 << (2));
    r_v1 = (long)(r_v1 + r_t6);
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(r_v1 + r_t6);
    r_a2 = (long)(r_a1 + r_t3);
    r_a1 = (long)(r_a2 + r_t2);
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_v1 = (long)(r_a1 + r_v1);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (552)); }
    if (r_v1 == 0) { r_t6 = (long)(r_t6 + (1)); goto _lbl_01F6E9F0; }
    if (r_a2) { *(int *)((char *)r_a2 + (28)) = (int)r_t5; }
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2084)); }
    r_t1 = (long)(0 + (1));
    r_v1 = (long)(r_t3 + r_v1);
    if (r_v1) { *(int *)((char *)r_v1 + (32)) = (int)r_t6; }
    goto _lbl_01F6E9FC;
_lbl_01F6E9F0:
    r_v1 = (long)((long)r_t6 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6E9A8;
_lbl_01F6E9FC:
    if (r_t1 == r_a0) { r_t4 = (long)(r_t4 + (1)); goto _lbl_01F6EA18; }
    r_t5 = (long)(r_t5 + (1));
_lbl_01F6EA08:
    r_v1 = (long)((long)r_t5 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6E9A0;
    r_t4 = (long)(r_t4 + (1));
_lbl_01F6EA18:
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (2080)); }
    r_v1 = (long)((long)r_t4 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6E994;
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0xb0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 19: thelp_func_01F6EA58 (VMA: 0x01F6EA58, size: 1900 bytes) */
void *thelp_func_01F6EA58(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0, r_t8 = 0, r_t9 = 0;
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
    r_sp = (long)(r_sp + (-0x70));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_s0 = *(int *)((char *)r_a0 + (3644)); }
    if (r_a0) { r_s1 = *(int *)((char *)r_a0 + (3652)); }
    r_s4 = (long)(0 + (1));
    r_s2 = (long)(r_a0 | 0);
    r_s3 = (long)(0 | 0);
    goto _lbl_01F6EB18;
    r_v1 = (long)((unsigned long)r_s3 << (5));
_lbl_01F6EA9C:
    r_a0 = (long)(r_v1 - r_s3);
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 - r_a0);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2076)); }
    r_s5 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(0 + (1));
    r_a1 = (long)(r_a0 + r_s5);
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (672)); }
    if (r_a0 != r_v1) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F6EB18; }
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (24)); }
    if ((long)r_a1 < 0) goto _lbl_01F6EB14;
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 >= 0) { r_v1 = (long)(r_v0 & (1)); goto _lbl_01F6EAEC; }
    r_v1 = (long)(r_v0 & (1));
    if (r_v1 == 0) goto _lbl_01F6EAEC;
    r_v1 = (long)(r_v1 + (-2));
_lbl_01F6EAEC:
    if (r_v1 != 0) goto _lbl_01F6EB14;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2076)); }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3648)); }
    r_a1 = (long)(r_a0 + r_s5);
    r_a0 = (long)(r_v1 + (0x1a));
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (656)); }
    r_a0 = (long)((long)r_a0 >> (1));
    r_v1 = (long)(r_a0 + r_v1);
    if (r_a1) { *(int *)((char *)r_a1 + (656)) = (int)r_v1; }
_lbl_01F6EB14:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6EB18:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2072)); }
    r_v1 = (long)((long)r_s3 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_s3 << (5)); goto _lbl_01F6EA9C; }
    r_v1 = (long)((unsigned long)r_s3 << (5));
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2076)); }
    r_a1 = (long)(0 + (0x405c));
    if (r_v1) { r_a2 = *(int *)((char *)r_v1 + (740)); }
    r_t0 = (long)(0 | 0);
    goto _lbl_01F6EB84;
    r_v1 = (long)((unsigned long)r_t0 << (5));
_lbl_01F6EB40:
    r_a0 = (long)(r_v1 - r_t0);
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 - r_a0);
    r_a0 = (long)((unsigned long)r_v1 << (3));
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2076)); }
    r_a0 = (long)(r_v1 + r_a0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (740)); }
    if (r_a2 == r_v1) goto _lbl_01F6EB6C;
    r_s4 = (long)(r_s4 + (1));
    r_a2 = (long)(r_v1 | 0);
_lbl_01F6EB6C:
    if (r_a0) { *(int *)((char *)r_a0 + (728)) = (int)r_s4; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2084)); }
    r_t0 = (long)(r_t0 + (1));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_v1) { *(int *)((char *)r_v1 + (16464)) = (int)r_s4; }
_lbl_01F6EB84:
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2072)); }
    r_v1 = (long)((long)r_t0 < (long)r_a3 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (5)); goto _lbl_01F6EB40; }
    r_v1 = (long)((unsigned long)r_t0 << (5));
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (2076)); }
    r_t0 = (long)(0 + (-1));
    r_a0 = (long)(0 + (1));
    r_t1 = (long)(r_t0 | 0);
    if (r_a2) { r_s3 = *(int *)((char *)r_a2 + (4)); }
    r_t2 = (long)(0 | 0);
    goto _lbl_01F6EBEC;
    r_v1 = (long)((unsigned long)r_t2 << (5));
_lbl_01F6EBB4:
    r_a1 = (long)(r_v1 - r_t2);
    r_v1 = (long)((unsigned long)r_a1 << (2));
    r_v1 = (long)(r_v1 - r_a1);
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_a1 = (long)(r_a2 + r_v1);
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (4)); }
    if (r_s3 != r_v1) { r_a0 = (long)(0 + (0x405c)); goto _lbl_01F6EBFC; }
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (672)); }
    if (r_v1 != r_a0) { r_t2 = (long)(r_t2 + (1)); goto _lbl_01F6EBEC; }
    if (r_a1) { r_t0 = *(int *)((char *)r_a1 + (660)); }
    r_t1 = (long)(r_t0 + r_s0);
    r_t2 = (long)(r_t2 + (1));
_lbl_01F6EBEC:
    r_v1 = (long)((long)r_t2 < (long)r_a3 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t2 << (5)); goto _lbl_01F6EBB4; }
    r_v1 = (long)((unsigned long)r_t2 << (5));
    r_a0 = (long)(0 + (0x405c));
_lbl_01F6EBFC:
    r_v1 = (long)(0 + (0xcd0));
    r_a2 = (long)(0 + (1));
    r_a1 = (long)(0 + (6));
    r_s4 = (long)(0 | 0);
    goto _lbl_01F6EDAC;
_lbl_01F6EC10:
    if (r_s2) { r_t3 = *(int *)((char *)r_s2 + (2076)); }
    r_a3 = (long)((unsigned long)r_s4 << (5));
    r_t4 = (long)(r_a3 - r_s4);
    r_a3 = (long)((unsigned long)r_t4 << (2));
    r_a3 = (long)(r_a3 - r_t4);
    r_t7 = (long)((unsigned long)r_a3 << (3));
    r_t5 = (long)(r_t3 + r_t7);
    if (r_t5) { r_a3 = *(int *)((char *)r_t5 + (4)); }
    if (r_s3 == r_a3) goto _lbl_01F6ECA8;
    r_t1 = (long)(0 + (-1));
    r_t0 = (long)(r_t1 | 0);
    r_s3 = (long)(r_s4 | 0);
    goto _lbl_01F6EC88;
    r_t4 = (long)((unsigned long)r_s3 << (5));
_lbl_01F6EC4C:
    r_t6 = (long)(r_t4 - r_s3);
    r_t4 = (long)((unsigned long)r_t6 << (2));
    r_t4 = (long)(r_t4 - r_t6);
    r_t4 = (long)((unsigned long)r_t4 << (3));
    r_t6 = (long)(r_t3 + r_t4);
    if (r_t6) { r_t4 = *(int *)((char *)r_t6 + (4)); }
    if (r_a3 != r_t4) goto _lbl_01F6EC94;
    if (r_t6) { r_t4 = *(int *)((char *)r_t6 + (672)); }
    if (r_t4 != r_a2) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F6EC88; }
    if (r_t6) { r_t0 = *(int *)((char *)r_t6 + (660)); }
    r_t1 = (long)(r_t0 + r_s0);
    goto _lbl_01F6EC94;
    r_s3 = (long)(r_s3 + (1));
_lbl_01F6EC88:
    r_t4 = (long)((long)r_s3 < (long)r_t2 ? 1 : 0);
    if (r_t4 != 0) { r_t4 = (long)((unsigned long)r_s3 << (5)); goto _lbl_01F6EC4C; }
    r_t4 = (long)((unsigned long)r_s3 << (5));
_lbl_01F6EC94:
    if ((long)r_t0 >= 0) goto _lbl_01F6ECA4;
    r_t0 = (long)(0 + (-1));
    r_t1 = (long)(r_t0 | 0);
_lbl_01F6ECA4:
    r_s3 = (long)(r_a3 | 0);
_lbl_01F6ECA8:
    if (r_t5) { r_t6 = *(int *)((char *)r_t5 + (672)); }
    if (r_t6 != r_a2) goto _lbl_01F6ECD0;
    if (r_t5) { r_a3 = *(int *)((char *)r_t5 + (528)); }
    if (r_a3 != r_a1) goto _lbl_01F6ECCC;
    if (r_t5) { r_a3 = *(int *)((char *)r_t5 + (660)); }
    r_t2 = (long)(r_s0 + r_a3);
    goto _lbl_01F6ED44;
_lbl_01F6ECCC:
_lbl_01F6ECD0:
    r_t2 = (long)(0 + (-1));
    r_s5 = (long)(0 | 0);
    goto _lbl_01F6ED38;
_lbl_01F6ECE0:
    r_a3 = (long)(0 | 0);
    goto _lbl_01F6ED28;
_lbl_01F6ECE8:
    if (r_s2) { r_t9 = *(int *)((char *)r_s2 + (2084)); }
    r_t8 = (long)((unsigned long)r_a3 << (2));
    r_t8 = (long)(r_t8 + r_a3);
    r_t8 = (long)((unsigned long)r_t8 << (3));
    r_t8 = (long)(r_t8 + r_a3);
    r_t9 = (long)(r_t9 + r_t4);
    r_t9 = (long)(r_t9 + r_t3);
    r_t8 = (long)((unsigned long)r_t8 << (4));
    r_t8 = (long)(r_t9 + r_t8);
    if (r_t8) { r_t8 = *(int *)((char *)r_t8 + (680)); }
    r_t8 = (long)(r_s1 + r_t8);
    r_at = (long)((long)r_t2 < (long)r_t8 ? 1 : 0);
    if (r_at == 0) { r_a3 = (long)(r_a3 + (1)); goto _lbl_01F6ED28; }
    r_t2 = (long)(r_t8 | 0);
    r_a3 = (long)(r_a3 + (1));
_lbl_01F6ED28:
    r_t8 = (long)((long)r_a3 < (long)(5) ? 1 : 0);
    if (r_t8 != 0) goto _lbl_01F6ECE8;
    r_s5 = (long)(r_s5 + (1));
_lbl_01F6ED38:
    r_a3 = (long)((long)r_s5 < (long)(5) ? 1 : 0);
    if (r_a3 != 0) goto _lbl_01F6ECE0;
_lbl_01F6ED44:
    if (r_t6 != r_a2) goto _lbl_01F6ED7C;
    if (r_t5) { *(int *)((char *)r_t5 + (732)) = (int)r_t0; }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2076)); }
    r_a3 = (long)(r_a3 + r_t7);
    if (r_a3) { *(int *)((char *)r_a3 + (736)) = (int)r_t2; }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2084)); }
    r_a3 = (long)(r_a3 + r_t3);
    if (r_a3) { *(int *)((char *)r_a3 + (16472)) = (int)r_t0; }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2084)); }
    r_a3 = (long)(r_a3 + r_t3);
    if (r_a3) { *(int *)((char *)r_a3 + (16468)) = (int)r_t2; }
    goto _lbl_01F6EDA8;
_lbl_01F6ED7C:
    if (r_t5) { *(int *)((char *)r_t5 + (732)) = (int)r_t1; }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2076)); }
    r_a3 = (long)(r_a3 + r_t7);
    if (r_a3) { *(int *)((char *)r_a3 + (736)) = (int)r_t2; }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2084)); }
    r_a3 = (long)(r_a3 + r_t3);
    if (r_a3) { *(int *)((char *)r_a3 + (16472)) = (int)r_t1; }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2084)); }
    r_a3 = (long)(r_a3 + r_t3);
    if (r_a3) { *(int *)((char *)r_a3 + (16468)) = (int)r_t2; }
_lbl_01F6EDA8:
    r_s4 = (long)(r_s4 + (1));
_lbl_01F6EDAC:
    if (r_s2) { r_t2 = *(int *)((char *)r_s2 + (2072)); }
    r_a3 = (long)((long)r_s4 < (long)r_t2 ? 1 : 0);
    if (r_a3 != 0) goto _lbl_01F6EC10;
    r_a0 = (long)(0 + (-1));
    r_a3 = (long)(0 + (0x256));
    r_a2 = (long)(0 + (0xec));
    r_v1 = (long)(r_a0 | 0);
    r_t1 = (long)(0 | 0);
    goto _lbl_01F6EE20;
    r_a1 = (long)((unsigned long)r_t1 << (5));
_lbl_01F6EDD8:
    r_t0 = (long)(r_a1 - r_t1);
    r_a1 = (long)((unsigned long)r_t0 << (2));
    r_a1 = (long)(r_a1 - r_t0);
    r_t0 = (long)((unsigned long)r_a1 << (3));
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (2076)); }
    r_a1 = (long)(r_a1 + r_t0);
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (28)); }
    if (r_a1 != r_a3) goto _lbl_01F6EE00;
    r_a0 = (long)(r_t1 | 0);
_lbl_01F6EE00:
    if (r_a1 != r_a2) goto _lbl_01F6EE0C;
    r_v1 = (long)(r_t1 | 0);
_lbl_01F6EE0C:
    if ((long)r_a0 < 0) { r_t1 = (long)(r_t1 + (1)); goto _lbl_01F6EE20; }
    if ((long)r_v1 >= 0) goto _lbl_01F6EE2C;
    r_t1 = (long)(r_t1 + (1));
_lbl_01F6EE20:
    r_a1 = (long)((long)r_t1 < (long)r_t2 ? 1 : 0);
    if (r_a1 != 0) { r_a1 = (long)((unsigned long)r_t1 << (5)); goto _lbl_01F6EDD8; }
    r_a1 = (long)((unsigned long)r_t1 << (5));
_lbl_01F6EE2C:
    if ((long)r_a0 < 0) goto _lbl_01F6EFAC;
    if ((long)r_v1 < 0) goto _lbl_01F6EFAC;
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2076)); }
    r_a1 = (long)((unsigned long)r_v1 << (5));
    r_a2 = (long)(r_a1 - r_v1);
    r_a1 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 - r_a2);
    r_a1 = (long)((unsigned long)r_a1 << (3));
    r_t0 = (long)(r_a3 + (0x290));
    r_a1 = (long)(r_t0 + r_a1);
    if (r_a1) { r_a3 = *(int *)((char *)r_a1 + (0)); }
    r_a1 = (long)((unsigned long)r_a0 << (5));
    r_a2 = (long)(r_a1 - r_a0);
    r_a1 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 - r_a2);
    r_a1 = (long)((unsigned long)r_a1 << (3));
    r_a1 = (long)(r_t0 + r_a1);
    if (r_a1) { r_t0 = *(int *)((char *)r_a1 + (0)); }
    r_a1 = (long)(r_a3 - r_t0);
    if ((long)r_a1 <= 0) goto _lbl_01F6EFAC;
    r_at = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
    goto _lbl_01F6EEB8;
    r_a2 = (long)((unsigned long)r_a0 << (5));
_lbl_01F6EE94:
    r_a3 = (long)(r_a2 - r_a0);
    r_a2 = (long)((unsigned long)r_a3 << (2));
    r_a2 = (long)(r_a2 - r_a3);
    r_a3 = (long)((unsigned long)r_a2 << (3));
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (2076)); }
    r_a0 = (long)(r_a0 + (1));
    r_a2 = (long)(r_a2 + r_a3);
    if (r_a2) { *(int *)((char *)r_a2 + (656)) = (int)r_t0; }
    r_at = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
_lbl_01F6EEB8:
    if (r_at == 0) { r_a2 = (long)((unsigned long)r_a0 << (5)); goto _lbl_01F6EE94; }
    r_a2 = (long)((unsigned long)r_a0 << (5));
    r_a3 = (long)(r_v1 + (1));
    r_a0 = (long)(0 + (0x405c));
    r_v1 = (long)(0 + (0xcd0));
    r_t5 = (long)(0 + (4));
    r_t4 = (long)(0 + (3));
    r_t3 = (long)(0 + (5));
    goto _lbl_01F6EF8C;
_lbl_01F6EEDC:
    if (r_s2) { r_t1 = *(int *)((char *)r_s2 + (2076)); }
    r_a2 = (long)((unsigned long)r_a3 << (5));
    r_t0 = (long)(r_a2 - r_a3);
    r_a2 = (long)((unsigned long)r_t0 << (2));
    r_a2 = (long)(r_a2 - r_t0);
    r_t2 = (long)((unsigned long)r_a2 << (3));
    r_t2 = (long)(r_t1 + r_t2);
    if (r_t2) { r_t1 = *(int *)((char *)r_t2 + (656)); }
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_t1 - r_a1);
    if (r_t2) { *(int *)((char *)r_t2 + (656)) = (int)r_t1; }
    goto _lbl_01F6EF7C;
_lbl_01F6EF14:
    r_t1 = (long)(0 | 0);
    r_t7 = (long)(r_a2 + r_t2);
    goto _lbl_01F6EF6C;
_lbl_01F6EF20:
    if (r_s2) { r_t6 = *(int *)((char *)r_s2 + (2084)); }
    r_t2 = (long)((unsigned long)r_t1 << (2));
    r_t2 = (long)(r_t2 + r_t1);
    r_t2 = (long)((unsigned long)r_t2 << (3));
    r_t2 = (long)(r_t2 + r_t1);
    r_t6 = (long)(r_t7 + r_t6);
    r_t2 = (long)((unsigned long)r_t2 << (4));
    r_t6 = (long)(r_t6 + r_t2);
    if (r_t6) { r_t2 = *(int *)((char *)r_t6 + (552)); }
    if (r_t2 == r_t5) goto _lbl_01F6EF5C;
    if (r_t2 == r_t4) goto _lbl_01F6EF5C;
    if (r_t2 != r_t3) { r_t1 = (long)(r_t1 + (1)); goto _lbl_01F6EF6C; }
_lbl_01F6EF5C:
    if (r_t6) { r_t2 = *(int *)((char *)r_t6 + (676)); }
    r_t2 = (long)(r_t2 - r_a1);
    if (r_t6) { *(int *)((char *)r_t6 + (676)) = (int)r_t2; }
    r_t1 = (long)(r_t1 + (1));
_lbl_01F6EF6C:
    r_t2 = (long)((long)r_t1 < (long)(5) ? 1 : 0);
    if (r_t2 != 0) goto _lbl_01F6EF20;
    r_t0 = (long)(r_t0 + (1));
_lbl_01F6EF7C:
    r_t1 = (long)((long)r_t0 < (long)(5) ? 1 : 0);
    if (r_t1 != 0) goto _lbl_01F6EF14;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F6EF8C:
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (2072)); }
    r_a2 = (long)((long)r_a3 < (long)r_a2 ? 1 : 0);
    if (r_a2 != 0) goto _lbl_01F6EEDC;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3548)); }
    r_v1 = (long)(r_v1 - r_a1);
    r_v1 = (long)(r_v1 + (0xa));
    if (r_s2) { *(int *)((char *)r_s2 + (3548)) = (int)r_v1; }
_lbl_01F6EFAC:
    if (r_s2) { r_t1 = *(int *)((char *)r_s2 + (2072)); }
    r_a0 = (long)(0 + (-1));
    r_a3 = (long)(0 + (0x48));
    r_a2 = (long)(0 + (0x9b));
    r_v1 = (long)(r_a0 | 0);
    r_t2 = (long)(0 | 0);
    goto _lbl_01F6F014;
    r_a1 = (long)((unsigned long)r_t2 << (5));
_lbl_01F6EFCC:
    r_t0 = (long)(r_a1 - r_t2);
    r_a1 = (long)((unsigned long)r_t0 << (2));
    r_a1 = (long)(r_a1 - r_t0);
    r_t0 = (long)((unsigned long)r_a1 << (3));
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (2076)); }
    r_a1 = (long)(r_a1 + r_t0);
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (28)); }
    if (r_a1 != r_a3) goto _lbl_01F6EFF4;
    r_a0 = (long)(r_t2 | 0);
_lbl_01F6EFF4:
    if (r_a1 != r_a2) goto _lbl_01F6F000;
    r_v1 = (long)(r_t2 | 0);
_lbl_01F6F000:
    if ((long)r_a0 < 0) { r_t2 = (long)(r_t2 + (1)); goto _lbl_01F6F014; }
    if ((long)r_v1 >= 0) goto _lbl_01F6F020;
    r_t2 = (long)(r_t2 + (1));
_lbl_01F6F014:
    r_a1 = (long)((long)r_t2 < (long)r_t1 ? 1 : 0);
    if (r_a1 != 0) { r_a1 = (long)((unsigned long)r_t2 << (5)); goto _lbl_01F6EFCC; }
    r_a1 = (long)((unsigned long)r_t2 << (5));
_lbl_01F6F020:
    if ((long)r_a0 < 0) goto _lbl_01F6F1A0;
    if ((long)r_v1 < 0) goto _lbl_01F6F1A0;
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2076)); }
    r_a1 = (long)((unsigned long)r_v1 << (5));
    r_a2 = (long)(r_a1 - r_v1);
    r_a1 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 - r_a2);
    r_a1 = (long)((unsigned long)r_a1 << (3));
    r_t0 = (long)(r_a3 + (0x290));
    r_a1 = (long)(r_t0 + r_a1);
    if (r_a1) { r_a3 = *(int *)((char *)r_a1 + (0)); }
    r_a1 = (long)((unsigned long)r_a0 << (5));
    r_a2 = (long)(r_a1 - r_a0);
    r_a1 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 - r_a2);
    r_a1 = (long)((unsigned long)r_a1 << (3));
    r_a1 = (long)(r_t0 + r_a1);
    if (r_a1) { r_t0 = *(int *)((char *)r_a1 + (0)); }
    r_t1 = (long)(r_a3 - r_t0);
    if ((long)r_t1 <= 0) goto _lbl_01F6F1A0;
    r_at = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
    goto _lbl_01F6F0AC;
    r_a1 = (long)((unsigned long)r_a0 << (5));
_lbl_01F6F088:
    r_a2 = (long)(r_a1 - r_a0);
    r_a1 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 - r_a2);
    r_a2 = (long)((unsigned long)r_a1 << (3));
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (2076)); }
    r_a0 = (long)(r_a0 + (1));
    r_a1 = (long)(r_a1 + r_a2);
    if (r_a1) { *(int *)((char *)r_a1 + (656)) = (int)r_t0; }
    r_at = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
_lbl_01F6F0AC:
    if (r_at == 0) { r_a1 = (long)((unsigned long)r_a0 << (5)); goto _lbl_01F6F088; }
    r_a1 = (long)((unsigned long)r_a0 << (5));
    r_a2 = (long)(r_v1 + (1));
    r_a0 = (long)(0 + (0x405c));
    r_v1 = (long)(0 + (0xcd0));
    r_t5 = (long)(0 + (4));
    r_t4 = (long)(0 + (3));
    r_t3 = (long)(0 + (5));
    goto _lbl_01F6F180;
_lbl_01F6F0D0:
    if (r_s2) { r_t0 = *(int *)((char *)r_s2 + (2076)); }
    r_a1 = (long)((unsigned long)r_a2 << (5));
    r_a3 = (long)(r_a1 - r_a2);
    r_a1 = (long)((unsigned long)r_a3 << (2));
    r_a1 = (long)(r_a1 - r_a3);
    r_t2 = (long)((unsigned long)r_a1 << (3));
    r_t2 = (long)(r_t0 + r_t2);
    if (r_t2) { r_t0 = *(int *)((char *)r_t2 + (656)); }
    r_a3 = (long)(0 | 0);
    r_t0 = (long)(r_t0 - r_t1);
    if (r_t2) { *(int *)((char *)r_t2 + (656)) = (int)r_t0; }
    goto _lbl_01F6F170;
_lbl_01F6F108:
    r_t0 = (long)(0 | 0);
    r_t7 = (long)(r_a1 + r_t2);
    goto _lbl_01F6F160;
_lbl_01F6F114:
    if (r_s2) { r_t6 = *(int *)((char *)r_s2 + (2084)); }
    r_t2 = (long)((unsigned long)r_t0 << (2));
    r_t2 = (long)(r_t2 + r_t0);
    r_t2 = (long)((unsigned long)r_t2 << (3));
    r_t2 = (long)(r_t2 + r_t0);
    r_t6 = (long)(r_t7 + r_t6);
    r_t2 = (long)((unsigned long)r_t2 << (4));
    r_t6 = (long)(r_t6 + r_t2);
    if (r_t6) { r_t2 = *(int *)((char *)r_t6 + (552)); }
    if (r_t2 == r_t5) goto _lbl_01F6F150;
    if (r_t2 == r_t4) goto _lbl_01F6F150;
    if (r_t2 != r_t3) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F6F160; }
_lbl_01F6F150:
    if (r_t6) { r_t2 = *(int *)((char *)r_t6 + (676)); }
    r_t2 = (long)(r_t2 - r_t1);
    if (r_t6) { *(int *)((char *)r_t6 + (676)) = (int)r_t2; }
    r_t0 = (long)(r_t0 + (1));
_lbl_01F6F160:
    r_t2 = (long)((long)r_t0 < (long)(5) ? 1 : 0);
    if (r_t2 != 0) goto _lbl_01F6F114;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F6F170:
    r_t0 = (long)((long)r_a3 < (long)(5) ? 1 : 0);
    if (r_t0 != 0) goto _lbl_01F6F108;
    r_a2 = (long)(r_a2 + (1));
_lbl_01F6F180:
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (2072)); }
    r_a1 = (long)((long)r_a2 < (long)r_a1 ? 1 : 0);
    if (r_a1 != 0) goto _lbl_01F6F0D0;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3548)); }
    r_v1 = (long)(r_v1 - r_t1);
    r_v1 = (long)(r_v1 + (0xa));
    if (r_s2) { *(int *)((char *)r_s2 + (3548)) = (int)r_v1; }
_lbl_01F6F1A0:
    /* unhandled: ld.b $w1 -0x41($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 20: thelp_func_01F6F1C4 (VMA: 0x01F6F1C4, size: 148 bytes) */
void *thelp_func_01F6F1C4(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a1 | 0);
    r_s1 = (long)(r_a0 | 0);
    if (r_s0 != 0) { r_s3 = (long)(0 | 0); goto _lbl_01F6F200; }
    r_s3 = (long)(0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6F23C;
_lbl_01F6F200:
    r_s2 = (long)(0 | 0);
    goto _lbl_01F6F228;
_lbl_01F6F208:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (16)); }
    r_v1 = (long)((unsigned long)r_s2 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + r_v0);
    r_s2 = (long)(r_s2 + (1));
_lbl_01F6F228:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (12)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6F208;
    r_v0 = (long)(r_s3 | 0);
_lbl_01F6F23C:
    /* unhandled: xori.b $w1 $w0 0xbf */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 21: thelp_func_01F6F258 (VMA: 0x01F6F258, size: 160 bytes) */
void *thelp_func_01F6F258(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a1 | 0);
    r_s1 = (long)(r_a0 | 0);
    r_v0 = (long)func_01F6F380((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_s0 | 0);
    r_s0 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F6F29C;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6F2E4;
_lbl_01F6F29C:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78370((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0 != 0) { /* unhandled: div $zero $v0 $s0 */ goto _lbl_01F6F2B4; }
    /* unhandled: div $zero $v0 $s0 */
    /* unhandled: break 0 7 */
_lbl_01F6F2B4:
    /* unhandled: mflo $v1 */
    if (r_s0 != 0) { /* unhandled: div $zero $v0 $s0 */ goto _lbl_01F6F2C4; }
    /* unhandled: div $zero $v0 $s0 */
    /* unhandled: break 0 7 */
_lbl_01F6F2C4:
    /* unhandled: mfhi $v0 */
    if ((long)r_v0 <= 0) goto _lbl_01F6F2D4;
    r_v1 = (long)(r_v1 + (1));
_lbl_01F6F2D4:
    if ((long)r_v1 > 0) { r_v0 = (long)(r_v1 | 0); goto _lbl_01F6F2E4; }
    r_v0 = (long)(r_v1 | 0);
    r_v1 = (long)(0 + (1));
    r_v0 = (long)(r_v1 | 0);
_lbl_01F6F2E4:
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 22: thelp_func_01F6F2F8 (VMA: 0x01F6F2F8, size: 16 bytes) */
void *thelp_func_01F6F2F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_v0 = (long)(0 + (1));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 23: thelp_func_01F6F308 (VMA: 0x01F6F308, size: 96 bytes) */
void *thelp_func_01F6F308(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a2 == 0) goto _lbl_01F6F360;
    if (r_a1 != 0) goto _lbl_01F6F344;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2108)); }
    if (r_v1 != 0) goto _lbl_01F6F338;
    if (r_a0) { *(int *)((char *)r_a0 + (2108)) = (int)r_a2; }
    if (r_a0) { *(int *)((char *)r_a0 + (2112)) = (int)r_a2; }
    goto _lbl_01F6F360;
_lbl_01F6F338:
    if (r_a2) { *(int *)((char *)r_a2 + (92)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2108)) = (int)r_a2; }
    goto _lbl_01F6F360;
_lbl_01F6F344:
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (92)); }
    if (r_a2) { *(int *)((char *)r_a2 + (92)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (92)) = (int)r_a2; }
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (92)); }
    if (r_v1 != 0) goto _lbl_01F6F360;
    if (r_a0) { *(int *)((char *)r_a0 + (2112)) = (int)r_a2; }
_lbl_01F6F360:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 24: thelp_func_01F6F368 (VMA: 0x01F6F368, size: 96 bytes) */
void *thelp_func_01F6F368(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a2 == 0) goto _lbl_01F6F3C0;
    if (r_a1 != 0) goto _lbl_01F6F3A4;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2116)); }
    if (r_v1 != 0) goto _lbl_01F6F398;
    if (r_a0) { *(int *)((char *)r_a0 + (2116)) = (int)r_a2; }
    if (r_a0) { *(int *)((char *)r_a0 + (2120)) = (int)r_a2; }
    goto _lbl_01F6F3C0;
_lbl_01F6F398:
    if (r_a2) { *(int *)((char *)r_a2 + (1332)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2116)) = (int)r_a2; }
    goto _lbl_01F6F3C0;
_lbl_01F6F3A4:
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (1332)); }
    if (r_a2) { *(int *)((char *)r_a2 + (1332)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (1332)) = (int)r_a2; }
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (1332)); }
    if (r_v1 != 0) goto _lbl_01F6F3C0;
    if (r_a0) { *(int *)((char *)r_a0 + (2120)) = (int)r_a2; }
_lbl_01F6F3C0:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 25: thelp_func_01F6F3C8 (VMA: 0x01F6F3C8, size: 356 bytes) */
void *thelp_func_01F6F3C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0;
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
    (void)r_t1;
    r_sp = (long)(r_sp + (-0xb0));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s3 = (long)(r_t0 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_s7 = (long)(r_a1 | 0);
    r_s5 = (long)(r_a2 | 0);
    r_s4 = (long)(r_a3 | 0);
    r_s8 = (long)(r_t1 | 0);
    r_s6 = (long)(r_a0 | 0);
    if (r_s3 != 0) { r_s2 = (long)(0 | 0); goto _lbl_01F6F424; }
    r_s2 = (long)(0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F6F4FC;
_lbl_01F6F424:
    if (r_s3) { r_a1 = *(int *)((char *)r_s3 + (0)); }
    r_v0 = (long)func_01F6F2E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (172)) = (int)r_v0; }
    r_v1 = (long)((long)r_v0 >> (1));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (172)); }
    r_s1 = (long)(r_v0 - r_v1);
    if ((long)r_s1 > 0) { r_s0 = (long)(0 | 0); goto _lbl_01F6F44C; }
    r_s0 = (long)(0 | 0);
    r_s1 = (long)(0 + (1));
    r_s0 = (long)(0 | 0);
_lbl_01F6F44C:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (172)); }
    goto _lbl_01F6F4EC;
    r_v0 = (long)(r_s0 + (1));
_lbl_01F6F458:
    if (r_v0 != r_s1) goto _lbl_01F6F4A4;
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (0)); }
    r_t0 = (long)(0 + (1));
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_a3 = (long)(r_s3 | 0);
    r_t1 = (long)(r_s8 | 0);
    r_v0 = (long)func_01F6F5B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (0)); }
    r_a1 = (long)(r_s4 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_v0 = (long)(r_v0 + (1));
    if (r_s5) { *(int *)((char *)r_s5 + (0)) = (int)r_v0; }
    r_v0 = (long)func_01F6F390((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s4 = (long)(r_s2 | 0);
    goto _lbl_01F6F4E4;
_lbl_01F6F4A4:
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (0)); }
    r_t0 = (long)(0 + (2));
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_a3 = (long)(r_s3 | 0);
    r_t1 = (long)(r_s8 | 0);
    r_v0 = (long)func_01F6F5B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (0)); }
    r_a1 = (long)(r_s4 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_v0 = (long)(r_v0 + (1));
    if (r_s5) { *(int *)((char *)r_s5 + (0)) = (int)r_v0; }
    r_v0 = (long)func_01F6F390((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s4 = (long)(r_s2 | 0);
_lbl_01F6F4E4:
    r_s0 = (long)(r_s0 + (1));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (172)); }
_lbl_01F6F4EC:
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(r_s0 + (1)); goto _lbl_01F6F458; }
    r_v0 = (long)(r_s0 + (1));
    r_v0 = (long)(r_s2 | 0);
_lbl_01F6F4FC:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0xb0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 26: thelp_func_01F6F52C (VMA: 0x01F6F52C, size: 440 bytes) */
void *thelp_func_01F6F52C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    /* unhandled: subu.qb $zero $sp $ra */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s4 = (long)(r_a0 | 0);
    r_s3 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_a0 = (long)(0 + (1));
    r_a1 = (long)(0 + (0x60));
    r_s0 = (long)(r_a2 | 0);
    r_s2 = (long)(r_a3 | 0);
    r_s1 = (long)(r_t0 | 0);
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_s0; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    r_s0 = (long)(r_v0 | 0);
    if (r_v0) { *(int *)((char *)r_v0 + (4)) = (int)r_v1; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (8)); }
    if (r_v0) { *(int *)((char *)r_v0 + (24)) = (int)r_v1; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (12)); }
    if (r_v0) { *(int *)((char *)r_v0 + (28)) = (int)r_v1; }
    if (r_s2) { r_v0 = *(unsigned char *)((char *)r_s2 + (16)); }
    if ((long)r_v0 > 0) { r_v0 = (long)(0 + (1)); goto _lbl_01F6F5A4; }
    r_v0 = (long)(0 + (1));
    if (r_s0) { *(int *)((char *)r_s0 + (32)) = (int)0; }
    goto _lbl_01F6F5A8;
    r_v0 = (long)(0 + (1));
_lbl_01F6F5A4:
    if (r_s0) { *(int *)((char *)r_s0 + (32)) = (int)r_v0; }
_lbl_01F6F5A8:
    r_v1 = (long)(0 + (-1));
    r_a0 = (long)(0 | 0);
    goto _lbl_01F6F5C4;
    r_v0 = (long)((unsigned long)r_a0 << (2));
_lbl_01F6F5B8:
    r_v0 = (long)(r_s0 + r_v0);
    r_a0 = (long)(r_a0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (36)) = (int)r_v1; }
_lbl_01F6F5C4:
    r_v0 = (long)((long)r_a0 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F6F5B8; }
    r_v0 = (long)((unsigned long)r_a0 << (2));
    r_a1 = (long)(0 | 0);
    goto _lbl_01F6F5F4;
_lbl_01F6F5D8:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (20)); }
    r_a0 = (long)((unsigned long)r_a1 << (2));
    r_v0 = (long)(r_s0 + r_a0);
    r_a1 = (long)(r_a1 + (1));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (0)); }
    if (r_v0) { *(int *)((char *)r_v0 + (36)) = (int)r_v1; }
_lbl_01F6F5F4:
    r_at = (long)((long)r_a1 < (long)(5) ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6F610;
    if (r_s2) { r_v0 = *(unsigned char *)((char *)r_s2 + (16)); }
    r_v0 = (long)((long)r_a1 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F6F5D8;
_lbl_01F6F610:
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78E70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) { r_v0 = (long)(0 + (-1)); goto _lbl_01F6F668; }
    r_v1 = (long)(0 + (1));
    if (r_s0) { *(int *)((char *)r_s0 + (56)) = (int)r_v1; }
    if (r_s0) { *(int *)((char *)r_s0 + (64)) = (int)r_v0; }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)(0 + (-1)); goto _lbl_01F6F65C; }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (60)) = (int)r_v0; }
    goto _lbl_01F6F674;
    r_v0 = (long)(0 + (-1));
_lbl_01F6F65C:
    if (r_s0) { *(int *)((char *)r_s0 + (60)) = (int)r_v0; }
    goto _lbl_01F6F674;
    r_v0 = (long)(0 + (-1));
_lbl_01F6F668:
    if (r_s0) { *(int *)((char *)r_s0 + (56)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (64)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (60)) = (int)r_v0; }
_lbl_01F6F674:
    if (r_s0) { *(int *)((char *)r_s0 + (12)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (68)) = (int)r_s3; }
    if (r_s2) { r_v0 = *(unsigned char *)((char *)r_s2 + (124)); }
    if (r_s0) { *(int *)((char *)r_s0 + (16)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (20)) = (int)r_s1; }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (2092)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (8)) = (int)r_v0; }
    r_v1 = (long)(0 | 0);
    goto _lbl_01F6F6B0;
    r_v0 = (long)((unsigned long)r_v1 << (2));
_lbl_01F6F6A4:
    r_v0 = (long)(r_s0 + r_v0);
    r_v1 = (long)(r_v1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (72)) = (int)0; }
_lbl_01F6F6B0:
    r_v0 = (long)((long)r_v1 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_v1 << (2)); goto _lbl_01F6F6A4; }
    r_v0 = (long)((unsigned long)r_v1 << (2));
    if (r_s0) { *(int *)((char *)r_s0 + (92)) = (int)0; }
    r_v0 = (long)(r_s0 | 0);
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 27: thelp_func_01F6F6E4 (VMA: 0x01F6F6E4, size: 336 bytes) */
void *thelp_func_01F6F6E4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    /* unhandled: subu.qb $zero $sp $ra */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s2 = (long)(r_a0 | 0);
    r_s0 = (long)(r_a1 | 0);
    r_a0 = (long)(0 + (1));
    r_a1 = (long)(0 + (0x538));
    r_s4 = (long)(r_a2 | 0);
    r_s1 = (long)(r_a3 | 0);
    r_s3 = (long)(r_t0 | 0);
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_s0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    r_s0 = (long)(r_v0 | 0);
    if (r_v0) { *(int *)((char *)r_v0 + (4)) = (int)r_v1; }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (0)); }
    if (r_v0) { *(int *)((char *)r_v0 + (12)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (1324)) = (int)r_s3; }
    if (r_v0) { *(int *)((char *)r_v0 + (1328)) = (int)r_s1; }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2092)); }
    r_a1 = (long)(r_s4 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (16)) = (int)r_v0; }
    if (r_s4) { r_v1 = *(unsigned char *)((char *)r_s4 + (124)); }
    r_v0 = (long)(0 + (-1));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(r_s1 | 0);
    r_a2 = (long)(r_s0 | 0);
    if (r_s0) { *(int *)((char *)r_s0 + (20)) = (int)r_v1; }
    if (r_s0) { *(int *)((char *)r_s0 + (8)) = (int)r_v0; }
    r_v0 = (long)func_01F6FAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    r_a0 = (long)(0 + (1));
    r_v1 = (long)(0 + (-1));
    r_a1 = (long)(0 | 0);
    r_v0 = (long)(r_v0 + (1));
    if (r_s1) { *(int *)((char *)r_s1 + (12)) = (int)r_v0; }
    goto _lbl_01F6F800;
    r_v0 = (long)((unsigned long)r_a1 << (2));
_lbl_01F6F79C:
    r_v0 = (long)(r_v0 + r_a1);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_a3 = (long)(r_s0 + r_v0);
    r_a2 = (long)(0 | 0);
    goto _lbl_01F6F7F0;
    r_v0 = (long)((unsigned long)r_a2 << (2));
_lbl_01F6F7B4:
    r_v0 = (long)(r_a3 + r_v0);
    if (r_v0) { *(int *)((char *)r_v0 + (124)) = (int)r_a0; }
    if (r_v0) { *(int *)((char *)r_v0 + (224)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (324)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (424)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (24)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (524)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (624)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (724)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (824)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (924)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (1024)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (1124)) = (int)r_v1; }
    r_a2 = (long)(r_a2 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (1224)) = (int)r_v1; }
_lbl_01F6F7F0:
    r_v0 = (long)((long)r_a2 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a2 << (2)); goto _lbl_01F6F7B4; }
    r_v0 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 + (1));
_lbl_01F6F800:
    r_v0 = (long)((long)r_a1 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a1 << (2)); goto _lbl_01F6F79C; }
    r_v0 = (long)((unsigned long)r_a1 << (2));
    if (r_s0) { *(int *)((char *)r_s0 + (1332)) = (int)0; }
    r_v0 = (long)(r_s0 | 0);
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 28: thelp_func_01F6F834 (VMA: 0x01F6F834, size: 240 bytes) */
void *thelp_func_01F6F834(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_v1 = (long)(0 + (2));
    if (r_a2 == r_v1) { r_v0 = (long)(0 | 0); goto _lbl_01F6F8E8; }
    r_v0 = (long)(0 | 0);
    r_v1 = (long)(0 + (1));
    if (r_a2 == r_v1) { r_a2 = (long)(0 | 0); goto _lbl_01F6F8AC; }
    if (r_a2 == 0) { r_a2 = (long)(0 | 0); goto _lbl_01F6F86C; }
    r_a2 = (long)(0 | 0);
    goto _lbl_01F6F91C;
    r_a2 = (long)(0 | 0);
_lbl_01F6F86C:
    r_v1 = (long)((long)r_a2 < (long)(0x96) ? 1 : 0);
    goto _lbl_01F6F898;
    r_v1 = (long)((unsigned long)r_a2 << (2));
_lbl_01F6F878:
    r_v1 = (long)(r_a0 + r_v1);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (2932)); }
    if (r_v1 != r_a1) { r_a2 = (long)(r_a2 + (1)); goto _lbl_01F6F894; }
    r_v0 = (long)(0 + (1));
    goto _lbl_01F6F91C;
    r_a2 = (long)(r_a2 + (1));
_lbl_01F6F894:
    r_v1 = (long)((long)r_a2 < (long)(0x96) ? 1 : 0);
_lbl_01F6F898:
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a2 << (2)); goto _lbl_01F6F878; }
    r_v1 = (long)((unsigned long)r_a2 << (2));
    goto _lbl_01F6F91C;
    r_a2 = (long)(0 | 0);
_lbl_01F6F8AC:
    r_v1 = (long)((long)r_a2 < (long)(0x96) ? 1 : 0);
    goto _lbl_01F6F8D8;
    r_v1 = (long)((unsigned long)r_a2 << (2));
_lbl_01F6F8B8:
    r_v1 = (long)(r_a0 + r_v1);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (2332)); }
    if (r_v1 != r_a1) { r_a2 = (long)(r_a2 + (1)); goto _lbl_01F6F8D4; }
    r_v0 = (long)(0 + (1));
    goto _lbl_01F6F91C;
    r_a2 = (long)(r_a2 + (1));
_lbl_01F6F8D4:
    r_v1 = (long)((long)r_a2 < (long)(0x96) ? 1 : 0);
_lbl_01F6F8D8:
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a2 << (2)); goto _lbl_01F6F8B8; }
    r_v1 = (long)((unsigned long)r_a2 << (2));
    goto _lbl_01F6F91C;
_lbl_01F6F8E8:
    r_a2 = (long)(0 | 0);
    goto _lbl_01F6F910;
    r_v1 = (long)((unsigned long)r_a2 << (2));
_lbl_01F6F8F4:
    r_v1 = (long)(r_a0 + r_v1);
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (2132)); }
    if (r_v1 != r_a1) { r_a2 = (long)(r_a2 + (1)); goto _lbl_01F6F910; }
    r_v0 = (long)(0 + (1));
    goto _lbl_01F6F91C;
    r_a2 = (long)(r_a2 + (1));
_lbl_01F6F910:
    r_v1 = (long)((long)r_a2 < (long)(0x32) ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a2 << (2)); goto _lbl_01F6F8F4; }
    r_v1 = (long)((unsigned long)r_a2 << (2));
_lbl_01F6F91C:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 29: thelp_func_01F6F924 (VMA: 0x01F6F924, size: 244 bytes) */
void *thelp_func_01F6F924(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    r_v1 = (long)(0 + (2));
    if (r_a2 == r_v1) { r_a3 = (long)(0 | 0); goto _lbl_01F6F9DC; }
    r_a3 = (long)(0 | 0);
    r_v1 = (long)(0 + (1));
    if (r_a2 == r_v1) { r_a3 = (long)(0 | 0); goto _lbl_01F6F99C; }
    r_a3 = (long)(0 | 0);
    if (r_a2 == 0) { r_a3 = (long)(0 | 0); goto _lbl_01F6F95C; }
    r_a3 = (long)(0 | 0);
    goto _lbl_01F6FA10;
    r_a3 = (long)(0 | 0);
_lbl_01F6F95C:
    r_v1 = (long)((long)r_a3 < (long)(0x96) ? 1 : 0);
    goto _lbl_01F6F988;
    r_v1 = (long)((unsigned long)r_a3 << (2));
_lbl_01F6F968:
    r_a2 = (long)(r_a0 + r_v1);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (2932)); }
    /* unhandled: bgtzl $v1 0x1f6f984 */
    r_a3 = (long)(r_a3 + (1));
    if (r_a2) { *(int *)((char *)r_a2 + (2932)) = (int)r_a1; }
    goto _lbl_01F6FA10;
    r_a3 = (long)(r_a3 + (1));
    r_v1 = (long)((long)r_a3 < (long)(0x96) ? 1 : 0);
_lbl_01F6F988:
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (2)); goto _lbl_01F6F968; }
    r_v1 = (long)((unsigned long)r_a3 << (2));
    goto _lbl_01F6FA10;
    r_a3 = (long)(0 | 0);
_lbl_01F6F99C:
    r_v1 = (long)((long)r_a3 < (long)(0x96) ? 1 : 0);
    goto _lbl_01F6F9C8;
    r_v1 = (long)((unsigned long)r_a3 << (2));
_lbl_01F6F9A8:
    r_a2 = (long)(r_a0 + r_v1);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (2332)); }
    /* unhandled: bgtzl $v1 0x1f6f9c4 */
    r_a3 = (long)(r_a3 + (1));
    if (r_a2) { *(int *)((char *)r_a2 + (2332)) = (int)r_a1; }
    goto _lbl_01F6FA10;
    r_a3 = (long)(r_a3 + (1));
    r_v1 = (long)((long)r_a3 < (long)(0x96) ? 1 : 0);
_lbl_01F6F9C8:
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (2)); goto _lbl_01F6F9A8; }
    r_v1 = (long)((unsigned long)r_a3 << (2));
    goto _lbl_01F6FA10;
    r_a3 = (long)(0 | 0);
_lbl_01F6F9DC:
    r_v1 = (long)((long)r_a3 < (long)(0x32) ? 1 : 0);
    goto _lbl_01F6FA08;
    r_v1 = (long)((unsigned long)r_a3 << (2));
_lbl_01F6F9E8:
    r_a2 = (long)(r_a0 + r_v1);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (2132)); }
    /* unhandled: bgtzl $v1 0x1f6fa04 */
    r_a3 = (long)(r_a3 + (1));
    if (r_a2) { *(int *)((char *)r_a2 + (2132)) = (int)r_a1; }
    goto _lbl_01F6FA10;
    r_a3 = (long)(r_a3 + (1));
    r_v1 = (long)((long)r_a3 < (long)(0x32) ? 1 : 0);
_lbl_01F6FA08:
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (2)); goto _lbl_01F6F9E8; }
    r_v1 = (long)((unsigned long)r_a3 << (2));
_lbl_01F6FA10:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 30: thelp_func_01F6FA18 (VMA: 0x01F6FA18, size: 60 bytes) */
void *thelp_func_01F6FA18(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1 == 0) goto _lbl_01F6FA4C;
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (12)); }
    if ((long)r_a0 < 0) { r_v1 = (long)((long)r_a0 < (long)(5) ? 1 : 0); goto _lbl_01F6FA4C; }
    r_v1 = (long)((long)r_a0 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F6FA44; }
    r_v1 = (long)((unsigned long)r_a0 << (2));
    goto _lbl_01F6FA4C;
_lbl_01F6FA44:
    r_v1 = (long)(r_v1 + r_a1);
    if (r_v1) { *(int *)((char *)r_v1 + (72)) = (int)r_a2; }
_lbl_01F6FA4C:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 31: thelp_func_01F6FA54 (VMA: 0x01F6FA54, size: 244 bytes) */
void *thelp_func_01F6FA54(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0;
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
    r_sp = (long)(r_sp + (-0x70));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s3 = (long)(0 + (0x26));
    /* unhandled: ext $s0 $sp 0 1 */
    r_s5 = (long)(r_a0 | 0);
    if (r_a0) { *(int *)((char *)r_a0 + (3700)) = (int)r_s3; }
    r_s1 = (long)(0 | 0);
    goto _lbl_01F6FB10;
_lbl_01F6FA94:
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (4)); }
    r_s3 = (long)(r_s3 + (3));
    r_s4 = (long)(0 | 0);
    r_s2 = (long)(0 | 0);
    r_a0 = (long)((unsigned long)r_s1 << (3));
    r_a0 = (long)(r_a0 + r_s1);
    r_a0 = (long)((unsigned long)r_a0 << (4));
    r_s0 = (long)(r_v1 + r_a0);
    goto _lbl_01F6FAEC;
    r_v1 = (long)(0 + (0x405c));
_lbl_01F6FABC:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    /* unhandled: mult $ac3 $s2 $v1 */
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s0 | 0);
    r_a2 = (long)(r_v0 + r_v1);
    r_v0 = (long)func_01F6FBD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 & (0xffff));
    r_at = (long)((long)r_s4 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F6FAEC; }
    r_s4 = (long)(r_v1 | 0);
    r_s2 = (long)(r_s2 + (1));
_lbl_01F6FAEC:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2080)); }
    r_v1 = (long)((long)r_s2 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)(0 + (0x405c)); goto _lbl_01F6FABC; }
    r_v1 = (long)(0 + (0x405c));
    r_v1 = (long)((unsigned long)r_s1 << (2));
    r_s3 = (long)(r_s3 + r_s4);
    r_v1 = (long)(r_s5 + r_v1);
    r_s1 = (long)(r_s1 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (3704)) = (int)r_s3; }
_lbl_01F6FB10:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (0)); }
    r_v1 = (long)((long)r_s1 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6FA94;
    /* unhandled: ld.b $w1 -0x41($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 32: thelp_func_01F6FB48 (VMA: 0x01F6FB48, size: 296 bytes) */
void *thelp_func_01F6FB48(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x60));
    /* unhandled: subu.qb $zero $sp $ra */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (16)); }
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (0)); }
    r_s4 = (long)(r_a0 | 0);
    r_s3 = (long)(r_a1 | 0);
    r_s2 = (long)(r_a2 | 0);
    r_s0 = (long)(0 | 0);
    if (r_v1 != r_v0) { r_s1 = (long)(0 | 0); goto _lbl_01F6FBAC; }
    r_s1 = (long)(0 | 0);
    r_v0 = (long)(0x4110 << 16);
    /* unhandled: mtc1 $v0 $f12 */
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (3644)); }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (20)); }
    r_v0 = (long)(r_a0 + r_v0);
_lbl_01F6FBAC:
    r_a1 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 >= 0) { r_v1 = (long)(0 + (0xcd0)); goto _lbl_01F6FBCC; }
    r_v1 = (long)(0 + (0xcd0));
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01F6FC50;
    r_v1 = (long)(0 + (0xcd0));
_lbl_01F6FBCC:
    /* unhandled: mult $ac2 $v0 $v1 */
    r_a3 = (long)(0 + (4));
    r_a2 = (long)(0 + (3));
    r_t1 = (long)(r_s2 + r_v0);
    r_v1 = (long)(0 + (5));
    r_t0 = (long)(0 | 0);
    goto _lbl_01F6FC24;
    r_v0 = (long)((unsigned long)r_t0 << (2));
_lbl_01F6FBEC:
    r_v0 = (long)(r_v0 + r_t0);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(r_v0 + r_t0);
    r_v0 = (long)((unsigned long)r_v0 << (4));
    r_v0 = (long)(r_t1 + r_v0);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (552)); }
    if (r_v0 == r_a3) { r_s1 = (long)(r_s1 + (1)); goto _lbl_01F6FC20; }
    if (r_v0 == r_a2) goto _lbl_01F6FC1C;
    if (r_v0 != r_v1) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F6FC24; }
_lbl_01F6FC1C:
    r_s1 = (long)(r_s1 + (1));
_lbl_01F6FC20:
    r_t0 = (long)(r_t0 + (1));
_lbl_01F6FC24:
    r_v0 = (long)((long)r_t0 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_t0 << (2)); goto _lbl_01F6FBEC; }
    r_v0 = (long)((unsigned long)r_t0 << (2));
    r_v0 = (long)(0x4110 << 16);
    /* unhandled: mtc1 $v0 $f12 */
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3652)); }
    r_v0 = (long)(r_v1 + r_v0);
    /* unhandled: mult $ac2 $s1 $v0 */
    r_v0 = (long)(r_s0 + r_v0);
_lbl_01F6FC50:
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 33: thelp_func_01F6FC70 (VMA: 0x01F6FC70, size: 228 bytes) */
void *thelp_func_01F6FC70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (3692)); }
    r_v0 = (long)(r_a2 + r_a1);
    if (r_a0) { *(int *)((char *)r_a0 + (3692)) = (int)r_v0; }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3692)); }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (3548)); }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (3532)); }
    /* unhandled: negu $v0 $v0 */
    r_v1 = (long)(r_a1 - r_v1);
    r_at = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6FCA4;
    /* unhandled: negu $v0 $v1 */
    if (r_a0) { *(int *)((char *)r_a0 + (3692)) = (int)r_v0; }
_lbl_01F6FCA4:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3692)); }
    if ((long)r_v0 <= 0) goto _lbl_01F6FCB4;
    if (r_a0) { *(int *)((char *)r_a0 + (3692)) = (int)0; }
_lbl_01F6FCB4:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3692)); }
    r_a0 = (long)(r_a2 - r_v0);
    return (void *)0x114308;
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (3696)); }
    r_v0 = (long)(r_a2 + r_a1);
    if (r_a0) { *(int *)((char *)r_a0 + (3696)) = (int)r_v0; }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3696)); }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (3552)); }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (3536)); }
    /* unhandled: negu $v0 $v0 */
    r_v1 = (long)(r_a1 - r_v1);
    r_at = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6FCF4;
    /* unhandled: negu $v0 $v1 */
    if (r_a0) { *(int *)((char *)r_a0 + (3696)) = (int)r_v0; }
_lbl_01F6FCF4:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3696)); }
    if ((long)r_v0 <= 0) goto _lbl_01F6FD04;
    if (r_a0) { *(int *)((char *)r_a0 + (3696)) = (int)0; }
_lbl_01F6FD04:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3696)); }
    r_a0 = (long)(r_a2 - r_v0);
    return (void *)0x114308;
    if (r_a0) { *(int *)((char *)r_a0 + (3692)) = (int)r_a1; }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3692)); }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (3548)); }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (3532)); }
    /* unhandled: negu $v0 $v0 */
    r_v1 = (long)(r_a1 - r_v1);
    r_at = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6FD3C;
    /* unhandled: negu $v0 $v1 */
    if (r_a0) { *(int *)((char *)r_a0 + (3692)) = (int)r_v0; }
_lbl_01F6FD3C:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3692)); }
    if ((long)r_v0 <= 0) goto _lbl_01F6FD4C;
    if (r_a0) { *(int *)((char *)r_a0 + (3692)) = (int)0; }
_lbl_01F6FD4C:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3692)); }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 34: thelp_func_01F6FD54 (VMA: 0x01F6FD54, size: 80 bytes) */
void *thelp_func_01F6FD54(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a0) { *(int *)((char *)r_a0 + (3696)) = (int)r_a1; }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3696)); }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (3552)); }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (3536)); }
    /* unhandled: negu $v0 $v0 */
    r_v1 = (long)(r_a1 - r_v1);
    r_at = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F6FD8C;
    /* unhandled: negu $v0 $v1 */
    if (r_a0) { *(int *)((char *)r_a0 + (3696)) = (int)r_v0; }
_lbl_01F6FD8C:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3696)); }
    if ((long)r_v0 <= 0) goto _lbl_01F6FD9C;
    if (r_a0) { *(int *)((char *)r_a0 + (3696)) = (int)0; }
_lbl_01F6FD9C:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (3696)); }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 35: thelp_func_01F6FDA4 (VMA: 0x01F6FDA4, size: 124 bytes) */
void *thelp_func_01F6FDA4(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_a1 != 0) { r_v0 = (long)(0 + (-1)); goto _lbl_01F6FDC0; }
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F6FE18;
_lbl_01F6FDC0:
    r_t1 = (long)(0 | 0);
    goto _lbl_01F6FDFC;
_lbl_01F6FDC8:
    if (r_a0) { r_t0 = *(int *)((char *)r_a0 + (2092)); }
    r_v1 = (long)((unsigned long)r_t1 << (3));
    r_a2 = (long)(r_v1 + r_t1);
    r_a3 = (long)((unsigned long)r_a2 << (4));
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_t0) { r_a2 = *(int *)((char *)r_t0 + (4)); }
    r_a2 = (long)(r_a2 + r_a3);
    if (r_a2) { r_a2 = *(int *)((char *)r_a2 + (0)); }
    if (r_a2 != r_v1) { r_t1 = (long)(r_t1 + (1)); goto _lbl_01F6FDFC; }
    r_v0 = (long)(r_t1 | 0);
    goto _lbl_01F6FE08;
    r_t1 = (long)(r_t1 + (1));
_lbl_01F6FDFC:
    r_v1 = (long)((long)r_t1 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6FDC8;
_lbl_01F6FE08:
    r_v1 = (long)((long)r_v0 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F6FE18;
    r_v0 = (long)(0 + (-1));
_lbl_01F6FE18:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 36: thelp_func_01F6FE20 (VMA: 0x01F6FE20, size: 1536 bytes) */
void *thelp_func_01F6FE20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x140));
    /* unhandled: mulsa.w.ph $ac0 $sp $ra */
    /* unhandled: ext $s6 $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s5 */
    /* unhandled: subu.qb $zero $sp $s3 */
    /* unhandled: ext $s2 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s1 */
    if (r_sp) { r_s7 = *(int *)((char *)r_sp + (328)); }
    if (r_sp) { r_s1 = *(int *)((char *)r_sp + (336)); }
    r_s3 = (long)(r_t1 | 0);
    if (r_sp) { *(int *)((char *)r_sp + (316)) = (int)r_a1; }
    if (r_sp) { *(int *)((char *)r_sp + (312)) = (int)r_a2; }
    if (r_sp) { *(int *)((char *)r_sp + (308)) = (int)r_a3; }
    r_s4 = (long)(r_t0 | 0);
    r_s8 = (long)(r_t2 | 0);
    r_s2 = (long)(r_t3 | 0);
    r_s5 = (long)(r_a0 | 0);
    if (r_s3 != 0) { r_s0 = (long)(0 | 0); goto _lbl_01F6FE84; }
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F703F0;
_lbl_01F6FE84:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (320)); }
    if (r_v0 != 0) goto _lbl_01F6FE98;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F703F0;
_lbl_01F6FE98:
    if (r_s7 != 0) goto _lbl_01F6FEA8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F703F0;
_lbl_01F6FEA8:
    if (r_s1 != 0) goto _lbl_01F6FEB8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F703F0;
_lbl_01F6FEB8:
    if ((long)r_s4 < 0) { r_v0 = (long)(0 | 0); goto _lbl_01F6FED0; }
    r_v0 = (long)(0 | 0);
    r_v0 = (long)((long)r_s4 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_a1 = (long)(r_s7 | 0); goto _lbl_01F6FEDC; }
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)(0 | 0);
_lbl_01F6FED0:
    goto _lbl_01F703F4;
    r_a1 = (long)(r_s7 | 0);
_lbl_01F6FEDC:
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if ((long)r_s6 >= 0) goto _lbl_01F6FEF8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F703F0;
_lbl_01F6FEF8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (320)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (12)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v1 == r_v0) goto _lbl_01F6FF14;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F703F0;
_lbl_01F6FF14:
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F6F8C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F6FF38;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F703F0;
_lbl_01F6FF38:
    if (r_s2 == 0) { r_v0 = (long)((unsigned long)r_s6 << (2)); goto _lbl_01F70074; }
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v0 = (long)(r_v0 + r_s6);
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_a2 + r_s2);
    r_a1 = (long)((unsigned long)r_s4 << (2));
    r_v0 = (long)(r_a1 + r_v0);
    r_a0 = (long)(r_v0 + (0x18));
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    if ((long)r_v0 > 0) goto _lbl_01F70168;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (1324)); }
    if (r_v1 != 0) { r_v0 = (long)(0 + (3)); goto _lbl_01F6FF84; }
    r_v0 = (long)(0 + (3));
    r_v0 = (long)(0 + (3));
    if (r_s2) { *(int *)((char *)r_s2 + (1324)) = (int)r_v0; }
    goto _lbl_01F6FF94;
    r_v0 = (long)(0 + (3));
_lbl_01F6FF84:
    if (r_v1 == r_v0) goto _lbl_01F6FF94;
    r_v0 = (long)(0 + (5));
    if (r_s2) { *(int *)((char *)r_s2 + (1324)) = (int)r_v0; }
_lbl_01F6FF94:
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    r_v0 = (long)(r_a2 + r_s2);
    r_a1 = (long)(r_a1 + r_v0);
    r_v0 = (long)(r_a1 + (0x20c));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v1; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (8)); }
    if (r_sp) { *(int *)((char *)r_sp + (240)) = (int)r_v0; }
    r_v0 = (long)(0 + (3));
    r_a2 = (long)(0 + (1));
    if (r_a1) { *(int *)((char *)r_a1 + (124)) = (int)r_v1; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    if (r_a1) { *(int *)((char *)r_a1 + (524)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (224)) = (int)r_v0; }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (20)); }
    if (r_a1) { *(int *)((char *)r_a1 + (424)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (308)); }
    if (r_a1) { *(int *)((char *)r_a1 + (624)) = (int)r_a2; }
    if (r_a1) { *(int *)((char *)r_a1 + (724)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (316)); }
    if (r_a1) { *(int *)((char *)r_a1 + (824)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (312)); }
    if (r_a1) { *(int *)((char *)r_a1 + (924)) = (int)r_v0; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    r_v0 = (long)(0 + (0x53));
    if (r_v1 != r_v0) { r_s0 = (long)(0 + (1)); goto _lbl_01F70014; }
    r_s0 = (long)(0 + (1));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (240)); }
    r_v1 = (long)(0 + (2));
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_v1; }
_lbl_01F70014:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (316)); }
    r_v1 = (long)(0 + (6));
    r_a0 = (long)(r_v0 + (1));
    goto _lbl_01F7005C;
    r_v0 = (long)((unsigned long)r_a0 << (2));
_lbl_01F70028:
    r_v0 = (long)(r_v0 + r_a0);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_a2 = (long)(r_s2 + r_v0);
    r_a1 = (long)(0 | 0);
    goto _lbl_01F7004C;
    r_v0 = (long)((unsigned long)r_a1 << (2));
_lbl_01F70040:
    r_v0 = (long)(r_a2 + r_v0);
    r_a1 = (long)(r_a1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (224)) = (int)r_v1; }
_lbl_01F7004C:
    r_v0 = (long)((long)r_a1 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a1 << (2)); goto _lbl_01F70040; }
    r_v0 = (long)((unsigned long)r_a1 << (2));
    r_a0 = (long)(r_a0 + (1));
_lbl_01F7005C:
    r_v0 = (long)((long)r_a0 < (long)r_s6 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F70028; }
    r_v0 = (long)((unsigned long)r_a0 << (2));
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (24)); }
    goto _lbl_01F7016C;
    r_v0 = (long)((unsigned long)r_s6 << (2));
_lbl_01F70074:
    r_v0 = (long)(r_v0 + r_s6);
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_a1 = (long)((unsigned long)r_s4 << (2));
    r_v1 = (long)(r_a2 + r_a1);
    r_s2 = (long)(r_s3 | 0);
    goto _lbl_01F70160;
    r_a0 = (long)(r_v1 + r_s2);
_lbl_01F70090:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (24)); }
    if ((long)r_v0 > 0) goto _lbl_01F70150;
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (224)); }
    if (r_v0 != 0) goto _lbl_01F70150;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (1324)); }
    if (r_v1 != 0) { r_v0 = (long)(0 + (3)); goto _lbl_01F700C4; }
    r_v0 = (long)(0 + (3));
    r_v0 = (long)(0 + (3));
    if (r_s2) { *(int *)((char *)r_s2 + (1324)) = (int)r_v0; }
    goto _lbl_01F700D4;
    r_v0 = (long)(0 + (3));
_lbl_01F700C4:
    if (r_v1 == r_v0) goto _lbl_01F700D4;
    r_v0 = (long)(0 + (5));
    if (r_s2) { *(int *)((char *)r_s2 + (1324)) = (int)r_v0; }
_lbl_01F700D4:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0)); }
    r_v0 = (long)(r_a2 + r_s2);
    r_a3 = (long)(r_a1 + r_v0);
    r_v0 = (long)(r_a3 + (0x20c));
    if (r_a3) { *(int *)((char *)r_a3 + (24)) = (int)r_a0; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (8)); }
    if (r_sp) { *(int *)((char *)r_sp + (256)) = (int)r_v0; }
    r_v1 = (long)(0 + (3));
    r_v0 = (long)(0 + (-1));
    if (r_a3) { *(int *)((char *)r_a3 + (124)) = (int)r_a1; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (12)); }
    r_a2 = (long)(0 + (1));
    if (r_a3) { *(int *)((char *)r_a3 + (524)) = (int)r_a1; }
    if (r_a3) { *(int *)((char *)r_a3 + (224)) = (int)r_v1; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (20)); }
    if (r_a3) { *(int *)((char *)r_a3 + (424)) = (int)r_v1; }
    if (r_a3) { *(int *)((char *)r_a3 + (624)) = (int)0; }
    if (r_a3) { *(int *)((char *)r_a3 + (724)) = (int)r_v0; }
    if (r_a3) { *(int *)((char *)r_a3 + (824)) = (int)r_v0; }
    if (r_a3) { *(int *)((char *)r_a3 + (924)) = (int)r_v0; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0)); }
    r_v0 = (long)(0 + (0x53));
    if (r_v1 != r_v0) { r_s0 = (long)(0 + (1)); goto _lbl_01F70168; }
    r_s0 = (long)(0 + (1));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (256)); }
    r_v1 = (long)(0 + (2));
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_v1; }
    goto _lbl_01F70168;
_lbl_01F70150:
    if (r_s2 == r_s8) goto _lbl_01F70168;
    if (r_s2) { r_s2 = *(int *)((char *)r_s2 + (1332)); }
_lbl_01F70160:
    if (r_s2 != 0) { r_a0 = (long)(r_v1 + r_s2); goto _lbl_01F70090; }
    r_a0 = (long)(r_v1 + r_s2);
_lbl_01F70168:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (24)); }
_lbl_01F7016C:
    if ((long)r_v0 > 0) goto _lbl_01F7017C;
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01F703F0;
_lbl_01F7017C:
    if (r_s2 != 0) { r_v0 = (long)((unsigned long)r_s6 << (2)); goto _lbl_01F70190; }
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01F703F0;
    r_v0 = (long)((unsigned long)r_s6 << (2));
_lbl_01F70190:
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v1 = (long)(r_s2 + r_v0);
    r_v0 = (long)((unsigned long)r_s4 << (2));
    r_v0 = (long)(r_v1 + r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)0; }
    if (r_sp) { *(int *)((char *)r_sp + (288)) = (int)0; }
    if (r_sp) { *(int *)((char *)r_sp + (224)) = (int)r_v0; }
    goto _lbl_01F703D8;
_lbl_01F701B4:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (288)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (28)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if (r_s6 == 0) goto _lbl_01F703CC;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F703CC;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (0)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (320)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F703CC;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (208)); }
    if (r_v0 != 0) goto _lbl_01F702F8;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (224)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (624)) = (int)r_v1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_v1 = *(int *)((char *)r_s7 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F70288;
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (320)); }
    r_t0 = (long)(r_s4 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(r_s4 | 0);
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0)); }
    r_t1 = (long)(r_s3 | 0);
    r_t2 = (long)(r_s8 | 0);
    r_t3 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01F702EC;
_lbl_01F70288:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (204)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (204)); }
    if (r_v0 == 0) { r_v0 = (long)(0 + (1)); goto _lbl_01F702F0; }
    r_v0 = (long)(0 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (320)); }
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s3 | 0);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (204)); }
    r_t2 = (long)(r_s8 | 0);
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0)); }
    r_t3 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
_lbl_01F702EC:
    r_v0 = (long)(0 + (1));
_lbl_01F702F0:
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    goto _lbl_01F703CC;
_lbl_01F702F8:
    if (r_s3 == r_s8) goto _lbl_01F703CC;
    if (r_s8 == 0) goto _lbl_01F703CC;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_v1 = *(int *)((char *)r_s7 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F70368;
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (320)); }
    r_t0 = (long)(r_s4 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(r_s4 | 0);
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0)); }
    if (r_s3) { r_t1 = *(int *)((char *)r_s3 + (1332)); }
    r_t2 = (long)(r_s8 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01F703CC;
_lbl_01F70368:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (284)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (284)); }
    if (r_v0 == 0) goto _lbl_01F703CC;
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (320)); }
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t2 = (long)(r_s8 | 0);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (284)); }
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0)); }
    if (r_s3) { r_t1 = *(int *)((char *)r_s3 + (1332)); }
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F6FEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
_lbl_01F703CC:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (288)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (288)) = (int)r_v0; }
_lbl_01F703D8:
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (24)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (288)); }
    r_v0 = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F701B4;
    r_v0 = (long)(r_s0 | 0);
_lbl_01F703F0:
_lbl_01F703F4:
    /* unhandled: ld.b $w2 -0x42($zero) */
    /* unhandled: aver_u.h $w2 $w0 $w23 */
    /* unhandled: xori.b $w2 $w0 0xb6 */
    /* unhandled: ld.b $w1 -0x4c($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w19 */
    /* unhandled: xori.b $w1 $w0 0xb2 */
    /* unhandled: ld.b $w0 -0x50($zero) */
    r_sp = (long)(r_sp + (0x140));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 37: thelp_func_01F70420 (VMA: 0x01F70420, size: 1564 bytes) */
void *thelp_func_01F70420(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x130));
    /* unhandled: mulsa.w.ph $ac0 $sp $ra */
    /* unhandled: ext $s6 $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s5 */
    /* unhandled: subu.qb $zero $sp $s3 */
    /* unhandled: ext $s2 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s1 */
    if (r_sp) { r_s7 = *(int *)((char *)r_sp + (312)); }
    if (r_sp) { r_s1 = *(int *)((char *)r_sp + (320)); }
    r_s3 = (long)(r_t1 | 0);
    if (r_sp) { *(int *)((char *)r_sp + (300)) = (int)r_a1; }
    if (r_sp) { *(int *)((char *)r_sp + (296)) = (int)r_a2; }
    if (r_sp) { *(int *)((char *)r_sp + (292)) = (int)r_a3; }
    r_s4 = (long)(r_t0 | 0);
    r_s8 = (long)(r_t2 | 0);
    r_s2 = (long)(r_t3 | 0);
    r_s5 = (long)(r_a0 | 0);
    if (r_s3 != 0) { r_s0 = (long)(0 | 0); goto _lbl_01F70484; }
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70A0C;
_lbl_01F70484:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (304)); }
    if (r_v0 != 0) goto _lbl_01F70498;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70A0C;
_lbl_01F70498:
    if (r_s7 != 0) goto _lbl_01F704A8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70A0C;
_lbl_01F704A8:
    if (r_s1 != 0) goto _lbl_01F704B8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70A0C;
_lbl_01F704B8:
    if ((long)r_s4 < 0) { r_v0 = (long)(0 | 0); goto _lbl_01F704D0; }
    r_v0 = (long)(0 | 0);
    r_v0 = (long)((long)r_s4 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_a1 = (long)(r_s7 | 0); goto _lbl_01F704DC; }
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)(0 | 0);
_lbl_01F704D0:
    goto _lbl_01F70A10;
    r_a1 = (long)(r_s7 | 0);
_lbl_01F704DC:
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if ((long)r_s6 >= 0) goto _lbl_01F704F8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70A0C;
_lbl_01F704F8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (304)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (12)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v1 == r_v0) goto _lbl_01F70514;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70A0C;
_lbl_01F70514:
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_01F6F8C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) goto _lbl_01F70538;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70A0C;
_lbl_01F70538:
    if (r_s2 == 0) { r_v0 = (long)((unsigned long)r_s6 << (2)); goto _lbl_01F70658; }
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v0 = (long)(r_v0 + r_s6);
    r_a0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_a0 + r_s2);
    r_a1 = (long)((unsigned long)r_s4 << (2));
    r_v0 = (long)(r_a1 + r_v0);
    r_a2 = (long)(r_v0 + (0x18));
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (24)); }
    if ((long)r_v0 > 0) goto _lbl_01F70728;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (1324)); }
    if (r_v1 != 0) { r_v0 = (long)(0 + (4)); goto _lbl_01F70584; }
    r_v0 = (long)(0 + (4));
    r_v0 = (long)(0 + (4));
    if (r_s2) { *(int *)((char *)r_s2 + (1324)) = (int)r_v0; }
    goto _lbl_01F70594;
    r_v0 = (long)(0 + (4));
_lbl_01F70584:
    if (r_v1 == r_v0) { r_v0 = (long)(r_a0 + r_s2); goto _lbl_01F70598; }
    r_v0 = (long)(r_a0 + r_s2);
    r_v0 = (long)(0 + (5));
    if (r_s2) { *(int *)((char *)r_s2 + (1324)) = (int)r_v0; }
_lbl_01F70594:
    r_v0 = (long)(r_a0 + r_s2);
_lbl_01F70598:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0)); }
    r_t0 = (long)(r_a1 + r_v0);
    r_a1 = (long)(0 + (4));
    r_v1 = (long)(0 + (-1));
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_a0; }
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (4)); }
    r_v0 = (long)(0 + (1));
    r_a0 = (long)(r_s5 | 0);
    if (r_t0) { *(int *)((char *)r_t0 + (124)) = (int)r_a3; }
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (8)); }
    if (r_t0) { *(int *)((char *)r_t0 + (524)) = (int)r_a3; }
    if (r_t0) { *(int *)((char *)r_t0 + (224)) = (int)r_a1; }
    if (r_t0) { *(int *)((char *)r_t0 + (424)) = (int)r_v1; }
    if (r_t0) { *(int *)((char *)r_t0 + (624)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (292)); }
    if (r_t0) { *(int *)((char *)r_t0 + (724)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (300)); }
    if (r_t0) { *(int *)((char *)r_t0 + (824)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (296)); }
    if (r_t0) { *(int *)((char *)r_t0 + (924)) = (int)r_v0; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (300)); }
    r_s0 = (long)(0 + (1));
    r_v1 = (long)(0 + (6));
    r_a0 = (long)(r_v0 + (1));
    goto _lbl_01F70640;
    r_v0 = (long)((unsigned long)r_a0 << (2));
_lbl_01F7060C:
    r_v0 = (long)(r_v0 + r_a0);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_a2 = (long)(r_s2 + r_v0);
    r_a1 = (long)(0 | 0);
    goto _lbl_01F70630;
    r_v0 = (long)((unsigned long)r_a1 << (2));
_lbl_01F70624:
    r_v0 = (long)(r_a2 + r_v0);
    r_a1 = (long)(r_a1 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (224)) = (int)r_v1; }
_lbl_01F70630:
    r_v0 = (long)((long)r_a1 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a1 << (2)); goto _lbl_01F70624; }
    r_v0 = (long)((unsigned long)r_a1 << (2));
    r_a0 = (long)(r_a0 + (1));
_lbl_01F70640:
    r_v0 = (long)((long)r_a0 < (long)r_s6 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F7060C; }
    r_v0 = (long)((unsigned long)r_a0 << (2));
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (32)); }
    goto _lbl_01F7072C;
    r_v0 = (long)((unsigned long)r_s6 << (2));
_lbl_01F70658:
    r_v0 = (long)(r_v0 + r_s6);
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_a1 = (long)((unsigned long)r_s4 << (2));
    r_v1 = (long)(r_a2 + r_a1);
    r_s2 = (long)(r_s3 | 0);
    goto _lbl_01F70720;
    r_a0 = (long)(r_v1 + r_s2);
_lbl_01F70674:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (24)); }
    if ((long)r_v0 > 0) goto _lbl_01F70710;
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (224)); }
    if (r_v0 != 0) goto _lbl_01F70710;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (1324)); }
    if (r_v1 != 0) { r_v0 = (long)(0 + (4)); goto _lbl_01F706A8; }
    r_v0 = (long)(0 + (4));
    r_v0 = (long)(0 + (4));
    if (r_s2) { *(int *)((char *)r_s2 + (1324)) = (int)r_v0; }
    goto _lbl_01F706B8;
    r_v0 = (long)(0 + (4));
_lbl_01F706A8:
    if (r_v1 == r_v0) goto _lbl_01F706B8;
    r_v0 = (long)(0 + (5));
    if (r_s2) { *(int *)((char *)r_s2 + (1324)) = (int)r_v0; }
_lbl_01F706B8:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0)); }
    r_v0 = (long)(r_a2 + r_s2);
    r_a3 = (long)(r_a1 + r_v0);
    r_v1 = (long)(0 + (4));
    if (r_a3) { *(int *)((char *)r_a3 + (24)) = (int)r_a0; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (4)); }
    r_v0 = (long)(0 + (-1));
    r_a0 = (long)(r_s5 | 0);
    if (r_a3) { *(int *)((char *)r_a3 + (124)) = (int)r_a1; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (8)); }
    if (r_a3) { *(int *)((char *)r_a3 + (524)) = (int)r_a1; }
    if (r_a3) { *(int *)((char *)r_a3 + (224)) = (int)r_v1; }
    if (r_a3) { *(int *)((char *)r_a3 + (424)) = (int)r_v0; }
    if (r_a3) { *(int *)((char *)r_a3 + (624)) = (int)0; }
    if (r_a3) { *(int *)((char *)r_a3 + (724)) = (int)r_v0; }
    if (r_a3) { *(int *)((char *)r_a3 + (824)) = (int)r_v0; }
    if (r_a3) { *(int *)((char *)r_a3 + (924)) = (int)r_v0; }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0)); }
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_01F6F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(0 + (1));
    goto _lbl_01F70728;
_lbl_01F70710:
    if (r_s2 == r_s8) goto _lbl_01F70728;
    if (r_s2) { r_s2 = *(int *)((char *)r_s2 + (1332)); }
_lbl_01F70720:
    if (r_s2 != 0) { r_a0 = (long)(r_v1 + r_s2); goto _lbl_01F70674; }
    r_a0 = (long)(r_v1 + r_s2);
_lbl_01F70728:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (32)); }
_lbl_01F7072C:
    if ((long)r_v0 > 0) goto _lbl_01F7073C;
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01F70A0C;
_lbl_01F7073C:
    if (r_s2 != 0) { r_v0 = (long)((unsigned long)r_s6 << (2)); goto _lbl_01F70750; }
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01F70A0C;
    r_v0 = (long)((unsigned long)r_s6 << (2));
_lbl_01F70750:
    r_v0 = (long)(r_v0 + r_s6);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v1 = (long)(r_s2 + r_v0);
    r_v0 = (long)((unsigned long)r_s4 << (2));
    r_v0 = (long)(r_v1 + r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (224)) = (int)0; }
    if (r_sp) { *(int *)((char *)r_sp + (272)) = (int)0; }
    if (r_sp) { *(int *)((char *)r_sp + (240)) = (int)r_v0; }
    goto _lbl_01F709F4;
_lbl_01F70774:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (272)); }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (36)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_sp) { *(int *)((char *)r_sp + (192)) = (int)r_v0; }
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (192)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if (r_s6 == 0) goto _lbl_01F709E8;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F709E8;
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0)); }
    r_v1 = (long)(0 + (0x68));
    if (r_a0 == r_v1) goto _lbl_01F707E4;
    r_v1 = (long)(r_a0 + (-0x65));
    r_at = (long)((unsigned long)r_v1 < (unsigned long)(3) ? 1 : 0);
    if (r_at == 0) goto _lbl_01F70818;
_lbl_01F707E4:
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (192)); }
    r_a0 = (long)(0 + (0x68));
    if (r_v1 == r_a0) goto _lbl_01F70818;
    r_a0 = (long)(0 + (0x65));
    if (r_v1 == r_a0) goto _lbl_01F70818;
    r_a0 = (long)(0 + (0x66));
    if (r_v1 == r_a0) goto _lbl_01F70818;
    r_a0 = (long)(0 + (0x67));
    if (r_v1 != r_a0) goto _lbl_01F709E8;
_lbl_01F70818:
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (0)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (304)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F709E8;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (224)); }
    if (r_v0 != 0) goto _lbl_01F70914;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (240)); }
    r_v1 = (long)(0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (624)) = (int)r_v1; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_v1 = *(int *)((char *)r_s7 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F708A4;
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (304)); }
    r_t0 = (long)(r_s4 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(r_s4 | 0);
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0)); }
    r_t1 = (long)(r_s3 | 0);
    r_t2 = (long)(r_s8 | 0);
    r_t3 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01F70908;
_lbl_01F708A4:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (220)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (220)); }
    if (r_v0 == 0) { r_v0 = (long)(0 + (1)); goto _lbl_01F7090C; }
    r_v0 = (long)(0 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (304)); }
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(r_s3 | 0);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (220)); }
    r_t2 = (long)(r_s8 | 0);
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0)); }
    r_t3 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
_lbl_01F70908:
    r_v0 = (long)(0 + (1));
_lbl_01F7090C:
    if (r_sp) { *(int *)((char *)r_sp + (224)) = (int)r_v0; }
    goto _lbl_01F709E8;
_lbl_01F70914:
    if (r_s3 == r_s8) goto _lbl_01F709E8;
    if (r_s8 == 0) goto _lbl_01F709E8;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_v1 = *(int *)((char *)r_s7 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F70984;
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (304)); }
    r_t0 = (long)(r_s4 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(r_s4 | 0);
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0)); }
    if (r_s3) { r_t1 = *(int *)((char *)r_s3 + (1332)); }
    r_t2 = (long)(r_s8 | 0);
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    goto _lbl_01F709E8;
_lbl_01F70984:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (268)) = (int)r_v0; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (268)); }
    if (r_v0 == 0) goto _lbl_01F709E8;
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (304)); }
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_t2 = (long)(r_s8 | 0);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (268)); }
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0)); }
    if (r_s3) { r_t1 = *(int *)((char *)r_s3 + (1332)); }
    r_t3 = (long)(0 | 0);
    r_v0 = (long)func_01F704A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
_lbl_01F709E8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (272)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (272)) = (int)r_v0; }
_lbl_01F709F4:
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (32)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (272)); }
    r_v0 = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F70774;
    r_v0 = (long)(r_s0 | 0);
_lbl_01F70A0C:
_lbl_01F70A10:
    /* unhandled: ld.b $w2 -0x42($zero) */
    /* unhandled: aver_u.h $w2 $w0 $w23 */
    /* unhandled: xori.b $w2 $w0 0xb6 */
    /* unhandled: ld.b $w1 -0x4c($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w19 */
    /* unhandled: xori.b $w1 $w0 0xb2 */
    /* unhandled: ld.b $w0 -0x50($zero) */
    r_sp = (long)(r_sp + (0x130));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 38: thelp_func_01F70A3C (VMA: 0x01F70A3C, size: 648 bytes) */
void *thelp_func_01F70A3C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0xc0));
    /* unhandled: ext $s7 $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s6 */
    /* unhandled: subu.qb $zero $sp $s4 */
    /* unhandled: ext $s3 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s2 */
    /* unhandled: addu.qb $zero $sp $s0 */
    if (r_sp) { r_s7 = *(int *)((char *)r_sp + (192)); }
    r_s4 = (long)(r_t1 | 0);
    r_s5 = (long)(r_t0 | 0);
    r_s3 = (long)(r_t2 | 0);
    r_s2 = (long)(r_t3 | 0);
    r_s6 = (long)(r_a0 | 0);
    r_s0 = (long)(0 | 0);
    if (r_s4 != 0) { r_s1 = (long)(0 | 0); goto _lbl_01F70A98; }
    r_s1 = (long)(0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70C94;
_lbl_01F70A98:
    if (r_s3 != 0) goto _lbl_01F70AA8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70C94;
_lbl_01F70AA8:
    if (r_s2 != 0) goto _lbl_01F70AB8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70C94;
_lbl_01F70AB8:
    if (r_s7 != 0) goto _lbl_01F70AC8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70C94;
_lbl_01F70AC8:
    if ((long)r_s5 < 0) { r_v0 = (long)(0 | 0); goto _lbl_01F70AE0; }
    r_v0 = (long)(0 | 0);
    r_v0 = (long)((long)r_s5 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_a1 = (long)(r_s2 | 0); goto _lbl_01F70AEC; }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)(0 | 0);
_lbl_01F70AE0:
    /* unhandled: ld.b $w2 -0x41($zero) */
    goto _lbl_01F70C98;
    r_a1 = (long)(r_s2 | 0);
_lbl_01F70AEC:
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 >= 0) goto _lbl_01F70B04;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70C94;
_lbl_01F70B04:
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (12)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_a0 == r_v1) { r_v1 = (long)((unsigned long)r_v0 << (2)); goto _lbl_01F70B20; }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70C94;
    r_v1 = (long)((unsigned long)r_v0 << (2));
_lbl_01F70B20:
    r_v0 = (long)(r_v1 + r_v0);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v1 = (long)(r_v0 + r_s4);
    r_v0 = (long)((unsigned long)r_s5 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (224)); }
    if (r_v0 != 0) goto _lbl_01F70B44;
    r_s1 = (long)(0 + (1));
_lbl_01F70B44:
    if (r_s7) { r_v0 = *(unsigned char *)((char *)r_s7 + (32)); }
    if ((long)r_v0 > 0) goto _lbl_01F70B58;
    r_v0 = (long)(r_s1 | 0);
    goto _lbl_01F70C94;
_lbl_01F70B58:
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)0; }
    r_s8 = (long)(0 | 0);
    goto _lbl_01F70BC8;
_lbl_01F70B64:
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (36)); }
    r_v1 = (long)((unsigned long)r_s8 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if (r_s0 == 0) { r_s8 = (long)(r_s8 + (1)); goto _lbl_01F70BC8; }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F70BC4;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (0)); }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F70BC4;
    r_v0 = (long)(0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)r_v0; }
    goto _lbl_01F70BD8;
_lbl_01F70BC4:
    r_s8 = (long)(r_s8 + (1));
_lbl_01F70BC8:
    if (r_s7) { r_v0 = *(unsigned char *)((char *)r_s7 + (32)); }
    r_v0 = (long)((long)r_s8 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F70B64;
_lbl_01F70BD8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
    if (r_v0 != 0) goto _lbl_01F70BEC;
    r_v0 = (long)(r_s1 | 0);
    goto _lbl_01F70C94;
_lbl_01F70BEC:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F70C40;
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_a3 = *(int *)((char *)r_s7 + (0)); }
    r_t0 = (long)(r_s5 + (1));
    r_a0 = (long)(r_s6 | 0);
    r_t1 = (long)(r_s4 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    goto _lbl_01F70C90;
_lbl_01F70C40:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    if (r_s5 == 0) { r_v0 = (long)(r_s1 | 0); goto _lbl_01F70C94; }
    r_v0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_s2 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_a3 = *(int *)((char *)r_s7 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_t1 = (long)(r_s4 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_v0 = (long)func_01F70AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
_lbl_01F70C90:
    r_v0 = (long)(r_s1 | 0);
_lbl_01F70C94:
    /* unhandled: ld.b $w2 -0x41($zero) */
_lbl_01F70C98:
    /* unhandled: aver_u.h $w2 $w0 $w30 */
    /* unhandled: xori.b $w2 $w0 0xb7 */
    /* unhandled: ld.b $w1 -0x4b($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w20 */
    /* unhandled: xori.b $w1 $w0 0xb3 */
    /* unhandled: ld.b $w0 -0x4f($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w16 */
    r_sp = (long)(r_sp + (0xc0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 39: thelp_func_01F70CC4 (VMA: 0x01F70CC4, size: 656 bytes) */
void *thelp_func_01F70CC4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0xc0));
    /* unhandled: ext $s7 $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s6 */
    /* unhandled: subu.qb $zero $sp $s4 */
    /* unhandled: ext $s3 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s2 */
    /* unhandled: addu.qb $zero $sp $s0 */
    if (r_sp) { r_s7 = *(int *)((char *)r_sp + (192)); }
    r_s4 = (long)(r_t1 | 0);
    r_s5 = (long)(r_t0 | 0);
    r_s3 = (long)(r_t2 | 0);
    r_s2 = (long)(r_t3 | 0);
    r_s6 = (long)(r_a0 | 0);
    r_s0 = (long)(0 | 0);
    if (r_s4 != 0) { r_s1 = (long)(0 | 0); goto _lbl_01F70D28; }
    r_s1 = (long)(0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70F24;
_lbl_01F70D28:
    if (r_s3 != 0) goto _lbl_01F70D38;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70F24;
_lbl_01F70D38:
    if (r_s2 != 0) goto _lbl_01F70D48;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70F24;
_lbl_01F70D48:
    if (r_s7 != 0) goto _lbl_01F70D58;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70F24;
_lbl_01F70D58:
    if ((long)r_s5 < 0) { r_v0 = (long)(0 | 0); goto _lbl_01F70D70; }
    r_v0 = (long)(0 | 0);
    r_v0 = (long)((long)r_s5 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_a1 = (long)(r_s2 | 0); goto _lbl_01F70D7C; }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)(0 | 0);
_lbl_01F70D70:
    /* unhandled: ld.b $w2 -0x41($zero) */
    goto _lbl_01F70F28;
    r_a1 = (long)(r_s2 | 0);
_lbl_01F70D7C:
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 >= 0) goto _lbl_01F70D94;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70F24;
_lbl_01F70D94:
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (12)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_a0 == r_v1) { r_v1 = (long)((unsigned long)r_v0 << (2)); goto _lbl_01F70DB0; }
    r_v1 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F70F24;
    r_v1 = (long)((unsigned long)r_v0 << (2));
_lbl_01F70DB0:
    r_v0 = (long)(r_v1 + r_v0);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v1 = (long)(r_v0 + r_s4);
    r_v0 = (long)((unsigned long)r_s5 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (224)); }
    if (r_v0 != 0) goto _lbl_01F70DD4;
    r_s1 = (long)(0 + (1));
_lbl_01F70DD4:
    if (r_s7) { r_v0 = *(unsigned char *)((char *)r_s7 + (24)); }
    if ((long)r_v0 > 0) goto _lbl_01F70DE8;
    r_v0 = (long)(r_s1 | 0);
    goto _lbl_01F70F24;
_lbl_01F70DE8:
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)0; }
    r_s8 = (long)(0 | 0);
    goto _lbl_01F70E58;
_lbl_01F70DF4:
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (28)); }
    r_v1 = (long)((unsigned long)r_s8 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if (r_s0 == 0) { r_s8 = (long)(r_s8 + (1)); goto _lbl_01F70E58; }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F70E54;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (0)); }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F70E54;
    r_v0 = (long)(0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)r_v0; }
    goto _lbl_01F70E68;
_lbl_01F70E54:
    r_s8 = (long)(r_s8 + (1));
_lbl_01F70E58:
    if (r_s7) { r_v0 = *(unsigned char *)((char *)r_s7 + (24)); }
    r_v0 = (long)((long)r_s8 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F70DF4;
_lbl_01F70E68:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
    if (r_v0 != 0) goto _lbl_01F70E7C;
    r_v0 = (long)(r_s1 | 0);
    goto _lbl_01F70F24;
_lbl_01F70E7C:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F70ED0;
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_a3 = *(int *)((char *)r_s7 + (0)); }
    r_t0 = (long)(r_s5 + (1));
    r_a0 = (long)(r_s6 | 0);
    r_t1 = (long)(r_s4 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    goto _lbl_01F70F20;
_lbl_01F70ED0:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2092)); }
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    if (r_s5 == 0) { r_v0 = (long)(r_s1 | 0); goto _lbl_01F70F24; }
    r_v0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_s2 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F6FE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_a3 = *(int *)((char *)r_s7 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_t1 = (long)(r_s4 | 0);
    r_t2 = (long)(r_s3 | 0);
    r_t3 = (long)(r_s5 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(0 | 0);
    r_t0 = (long)(0 | 0);
    r_v0 = (long)func_01F70D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
_lbl_01F70F20:
    r_v0 = (long)(r_s1 | 0);
_lbl_01F70F24:
    /* unhandled: ld.b $w2 -0x41($zero) */
_lbl_01F70F28:
    /* unhandled: aver_u.h $w2 $w0 $w30 */
    /* unhandled: xori.b $w2 $w0 0xb7 */
    /* unhandled: ld.b $w1 -0x4b($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w20 */
    /* unhandled: xori.b $w1 $w0 0xb3 */
    /* unhandled: ld.b $w0 -0x4f($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w16 */
    r_sp = (long)(r_sp + (0xc0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 40: thelp_func_01F70F54 (VMA: 0x01F70F54, size: 2696 bytes) */
void *thelp_func_01F70F54(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t9 = 0;
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
    (void)r_t1;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x4430));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (3736)); }
    r_s5 = (long)(r_a0 | 0);
    r_s3 = (long)(0 | 0);
    r_s0 = (long)(0 | 0);
    r_s4 = (long)(0 | 0);
    r_s2 = (long)(0 | 0);
    if (r_v1 == 0) { r_s1 = (long)(0 | 0); goto _lbl_01F719AC; }
    r_s1 = (long)(0 | 0);
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (270)); }
    if (r_v0 == 0) goto _lbl_01F70FD8;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a1 = (long)(r_s5 + (0x24));
    r_v0 = (long)func_001AC320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F71AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    goto _lbl_01F719B0;
_lbl_01F70FD8:
    if (r_s5) { *(int *)((char *)r_s5 + (3556)) = (int)0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3556)); }
    if (r_v1 == 0) goto _lbl_01F712EC;
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) goto _lbl_01F70FFC;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3692)); }
    goto _lbl_01F712F0;
_lbl_01F70FFC:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a1 = (long)(r_s5 + (0x24));
    r_v0 = (long)func_001AC320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3588)); }
    r_v0 = (long)(0 + (2));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F710D0; }
    r_v0 = (long)(0 + (1));
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3584)); }
    r_s0 = (long)(r_sp + (0xd4));
    r_s2 = (long)(r_sp + (0xd8));
    r_v0 = (long)(r_v1 + r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3536)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (220)) = (int)r_v0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (208)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3584)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s2) { *(int *)((char *)r_s2 + (0)) = (int)r_v0; }
    goto _lbl_01F7109C;
_lbl_01F7105C:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3584)); }
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0)); }
    r_t0 = (long)(r_sp + (0xd0));
    r_t1 = (long)(0 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_a2 = (long)(r_a2 - r_v0);
    r_v0 = (long)func_001AC650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (208)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3584)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (0)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3584)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s2) { *(int *)((char *)r_s2 + (0)) = (int)r_v0; }
_lbl_01F7109C:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3532)); }
    if (r_sp) { r_a2 = *(int *)((char *)r_sp + (208)); }
    r_v1 = (long)(r_v1 + r_v0);
    r_v0 = (long)((long)r_a2 < (long)r_v1 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F7105C;
    if (r_s5) { r_s0 = *(int *)((char *)r_s5 + (3584)); }
    if (r_s5) { r_s4 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (3536)); }
    r_s3 = (long)(r_v1 - r_s0);
    goto _lbl_01F71328;
    r_v0 = (long)(0 + (1));
_lbl_01F710D0:
    if (r_v1 != r_v0) goto _lbl_01F71178;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3532)); }
    r_s0 = (long)(r_sp + (0xd8));
    r_s2 = (long)(r_sp + (0xd4));
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v0; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s2) { *(int *)((char *)r_s2 + (0)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3536)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (220)) = (int)r_v0; }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3584)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    goto _lbl_01F71154;
_lbl_01F7111C:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (0)); }
    r_t0 = (long)(r_sp + (0xd0));
    r_t1 = (long)(0 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_v0 = (long)func_001AC650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3584)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (208)); }
    r_v0 = (long)(r_v0 - r_v1);
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3584)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0)); }
    r_v0 = (long)(r_v0 - r_v1);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v0; }
_lbl_01F71154:
    if (r_s0) { r_a2 = *(int *)((char *)r_s0 + (0)); }
    if (r_s5) { r_s3 = *(int *)((char *)r_s5 + (3540)); }
    r_at = (long)((long)r_s3 < (long)r_a2 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F7111C;
    if (r_s5) { r_s4 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (3536)); }
    if (r_s5) { r_s0 = *(int *)((char *)r_s5 + (3584)); }
    goto _lbl_01F71328;
_lbl_01F71178:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3592)); }
    r_v0 = (long)(0 + (4));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (3)); goto _lbl_01F7123C; }
    r_v0 = (long)(0 + (3));
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3540)); }
    r_s2 = (long)(r_sp + (0xd8));
    r_s0 = (long)(r_sp + (0xd4));
    r_s3 = (long)(r_sp + (0xdc));
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3532)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s2) { *(int *)((char *)r_s2 + (0)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3580)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v0; }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3580)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s3) { *(int *)((char *)r_s3 + (0)) = (int)r_v0; }
    goto _lbl_01F71208;
_lbl_01F711D0:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (0)); }
    r_t0 = (long)(r_sp + (0xd0));
    r_t1 = (long)(0 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_v0 = (long)func_001AC650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3580)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v0; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3580)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s3) { *(int *)((char *)r_s3 + (0)) = (int)r_v0; }
_lbl_01F71208:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3536)); }
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0)); }
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)((long)r_v0 < (long)r_a3 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F711D0;
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (3580)); }
    if (r_s5) { r_s3 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_s0 = *(int *)((char *)r_s5 + (3532)); }
    r_s4 = (long)(r_v0 - r_s2);
    goto _lbl_01F71328;
    r_v0 = (long)(0 + (3));
_lbl_01F7123C:
    if (r_v1 != r_v0) { r_v0 = (long)(r_s3 + r_s0); goto _lbl_01F7132C; }
    r_v0 = (long)(r_s3 + r_s0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3540)); }
    r_s3 = (long)(r_sp + (0xd8));
    r_s0 = (long)(r_sp + (0xdc));
    r_s2 = (long)(r_sp + (0xd4));
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3532)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s3) { *(int *)((char *)r_s3 + (0)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3536)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v0; }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3580)); }
    r_v0 = (long)(r_v1 - r_v0);
    if (r_s2) { *(int *)((char *)r_s2 + (0)) = (int)r_v0; }
    goto _lbl_01F712C8;
_lbl_01F7128C:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    if (r_s3) { r_a2 = *(int *)((char *)r_s3 + (0)); }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (0)); }
    r_t0 = (long)(r_sp + (0xd0));
    r_t1 = (long)(0 | 0);
    r_a1 = (long)(r_a0 | 0);
    r_v0 = (long)func_001AC650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3580)); }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0)); }
    r_v0 = (long)(r_v0 - r_v1);
    if (r_s2) { *(int *)((char *)r_s2 + (0)) = (int)r_v0; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3580)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0)); }
    r_v0 = (long)(r_v0 - r_v1);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v0; }
_lbl_01F712C8:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0)); }
    if (r_s5) { r_s4 = *(int *)((char *)r_s5 + (3544)); }
    r_at = (long)((long)r_s4 < (long)r_v0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F7128C;
    if (r_s5) { r_s0 = *(int *)((char *)r_s5 + (3532)); }
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (3580)); }
    if (r_s5) { r_s3 = *(int *)((char *)r_s5 + (3540)); }
    goto _lbl_01F71328;
_lbl_01F712EC:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3692)); }
_lbl_01F712F0:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3548)); }
    r_a0 = (long)(r_v1 + r_v0);
    r_at = (long)((long)r_a0 < (long)(0x280) ? 1 : 0);
    if (r_at == 0) goto _lbl_01F71314;
    r_v0 = (long)(0 + (0x280));
    r_v0 = (long)(r_v0 - r_a0);
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s5) { *(int *)((char *)r_s5 + (3692)) = (int)r_v0; }
_lbl_01F71314:
    if (r_s5) { r_s3 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_s0 = *(int *)((char *)r_s5 + (3532)); }
    if (r_s5) { r_s4 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (3536)); }
_lbl_01F71328:
    r_v0 = (long)(r_s3 + r_s0);
_lbl_01F7132C:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    if (r_sp) { *(int *)((char *)r_sp + (192)) = (int)r_v0; }
    if (r_sp) { r_a3 = *(int *)((char *)r_sp + (192)); }
    r_s8 = (long)(r_s4 + r_s2);
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(r_s4 | 0);
    r_t0 = (long)(r_s8 | 0);
    r_v0 = (long)func_001AC470((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_01F71AC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2100)); }
    if (r_v0 == 0) { r_a0 = (long)(0 + (0x14)); goto _lbl_01F7137C; }
    r_a0 = (long)(0 + (0x14));
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (3176)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (8)); }
    r_v0 = (long)func_0017DCA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(0 + (1));
    goto _lbl_01F71388;
    r_a0 = (long)(0 + (0x14));
_lbl_01F7137C:
    r_v0 = (long)func_0017DCA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(0 + (1));
_lbl_01F71388:
    if (r_sp) { *(int *)((char *)r_sp + (172)) = (int)0; }
    goto _lbl_01F71704;
    r_a1 = (long)(0 + (1));
_lbl_01F71394:
    if (r_s2 != r_a1) { r_v0 = (long)(0 + (2)); goto _lbl_01F713B8; }
    r_v0 = (long)(0 + (2));
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001AB8F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F71704; }
    r_s0 = (long)(0 | 0);
    goto _lbl_01F71430;
    r_v0 = (long)(0 + (2));
_lbl_01F713B8:
    if (r_s2 != r_v0) goto _lbl_01F7142C;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001ABA00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F71700;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(0 + (5));
    r_v0 = (long)func_00185E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (32)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (56)); }
    r_s0 = (long)(r_v0 | 0);
    r_v0 = (long)func_002257A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (8)); }
    r_a1 = (long)(0 + (0x62));
    if (r_sp) { *(int *)((char *)r_sp + (172)) = (int)r_v0; }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_001F6EA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F7142C;
    r_a1 = (long)(0 + (0x62));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_001F6EA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { r_v1 = *(char *)((char *)r_v0 + (0)); }
    r_v0 = (long)(0 + (0x31));
    if (r_v1 != r_v0) goto _lbl_01F7142C;
    r_s1 = (long)(r_s1 + (2));
_lbl_01F7142C:
    r_s0 = (long)(0 | 0);
_lbl_01F71430:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2072)); }
    goto _lbl_01F7151C;
    r_v0 = (long)((unsigned long)r_s0 << (5));
_lbl_01F7143C:
    r_v1 = (long)(r_v0 - r_s0);
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 - r_v1);
    r_v1 = (long)((unsigned long)r_v0 << (3));
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_a1 = (long)(r_sp + (0xe0));
    r_a0 = (long)(0 + (0x5d));
    r_a2 = (long)(r_v0 + r_v1);
_lbl_01F7145C:
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (4)); }
    r_a0 = (long)(r_a0 + (-1));
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (4)) = (int)r_v0; }
    r_a2 = (long)(r_a2 + (8));
    if ((long)r_a0 > 0) { r_a1 = (long)(r_a1 + (8)); goto _lbl_01F7145C; }
    r_a1 = (long)(r_a1 + (8));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (896)); }
    r_a1 = (long)(0 + (1));
    if (r_v0 != r_a1) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F71518; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (880)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3648)); }
    r_v1 = (long)(r_a0 + r_v1);
    r_v0 = (long)(r_v0 + r_v1);
    r_v0 = (long)((long)r_v0 < (long)r_s3 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F71514;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (192)); }
    r_at = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F71514;
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (884)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3696)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3644)); }
    r_v1 = (long)(r_a0 + r_v1);
    r_v0 = (long)(r_v0 + r_v1);
    r_v0 = (long)((long)r_v0 < (long)r_s4 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F71514;
    r_at = (long)((long)r_s8 < (long)r_v1 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F71514;
    if (r_s2 != r_a1) { r_a1 = (long)(r_sp + (0xf0)); goto _lbl_01F71508; }
    r_a1 = (long)(r_sp + (0xf0));
    r_a1 = (long)(r_sp + (0xf0));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F72BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F71514;
    r_a1 = (long)(r_sp + (0xf0));
_lbl_01F71508:
    r_a0 = (long)(r_s5 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F72E90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F71514:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F71518:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2072)); }
_lbl_01F7151C:
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (5)); goto _lbl_01F7143C; }
    r_v0 = (long)((unsigned long)r_s0 << (5));
    r_s6 = (long)(0 | 0);
    goto _lbl_01F71668;
    r_v1 = (long)(0 + (0x405c));
_lbl_01F71534:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    r_a0 = (long)(r_sp + (0x3d0));
    r_v1 = (long)(0 + (0x1017));
    r_a1 = (long)(r_v0 + r_a1);
_lbl_01F71548:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (0)); }
    r_v1 = (long)(r_v1 + (-1));
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
    r_a1 = (long)(r_a1 + (4));
    if ((long)r_v1 > 0) { r_a0 = (long)(r_a0 + (4)); goto _lbl_01F71548; }
    r_a0 = (long)(r_a0 + (4));
    r_s7 = (long)(0 | 0);
    goto _lbl_01F71658;
    r_v0 = (long)(0 + (0xcd0));
_lbl_01F7156C:
    /* unhandled: mult $ac2 $s7 $v0 */
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(r_v0 + r_sp);
    r_v0 = (long)(r_v0 + (0x3d0));
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)r_v0; }
    goto _lbl_01F71648;
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F71588:
    r_v0 = (long)(r_v0 + r_s0);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(r_v0 + r_s0);
    r_v1 = (long)((unsigned long)r_v0 << (4));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (552)); }
    if (r_a0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F71648; }
    r_v1 = (long)(0 + (6));
    if (r_a0 == r_v1) goto _lbl_01F71644;
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (676)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3656)); }
    r_a0 = (long)(r_a1 + r_a0);
    r_v1 = (long)(r_v1 + r_a0);
    r_v1 = (long)((long)r_v1 < (long)r_s3 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F71644;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (192)); }
    r_at = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F71644;
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (680)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (3696)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3652)); }
    r_a0 = (long)(r_a1 + r_a0);
    r_v1 = (long)(r_v1 + r_a0);
    r_v1 = (long)((long)r_v1 < (long)r_s4 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F71644;
    r_at = (long)((long)r_s8 < (long)r_a0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F71644;
    r_v1 = (long)(0 + (1));
    if (r_s2 != r_v1) { r_a1 = (long)(r_v0 + (0x24)); goto _lbl_01F71638; }
    r_a1 = (long)(r_v0 + (0x24));
    r_a1 = (long)(r_v0 + (0x24));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F72BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F71644;
    r_a1 = (long)(r_v0 + (0x24));
_lbl_01F71638:
    r_a0 = (long)(r_s5 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F72E90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F71644:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F71648:
    r_v0 = (long)((long)r_s0 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (2)); goto _lbl_01F71588; }
    r_v0 = (long)((unsigned long)r_s0 << (2));
    r_s7 = (long)(r_s7 + (1));
_lbl_01F71658:
    r_v0 = (long)((long)r_s7 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(0 + (0xcd0)); goto _lbl_01F7156C; }
    r_v0 = (long)(0 + (0xcd0));
    r_s6 = (long)(r_s6 + (1));
_lbl_01F71668:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2080)); }
    r_v0 = (long)((long)r_s6 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v1 = (long)(0 + (0x405c)); goto _lbl_01F71534; }
    r_v1 = (long)(0 + (0x405c));
    r_v0 = (long)(0 + (1));
    if (r_s2 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F716C4; }
    r_v0 = (long)(0 + (1));
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5820)); }
    if (r_a0 == 0) goto _lbl_01F716C0;
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3696)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (32)); }
    r_t0 = (long)(0 | 0);
    r_t1 = (long)(0 | 0);
    r_a2 = (long)(r_a3 + r_a2);
    r_v0 = (long)(r_v1 + r_v0);
    r_a2 = (long)(r_a2 + (0x4b));
    r_a3 = (long)(r_v0 + (0x3b));
    r_v0 = (long)func_0025E640((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F716C0:
    r_v0 = (long)(0 + (1));
_lbl_01F716C4:
    if (r_s2 != r_v0) { r_v0 = (long)(0 + (2)); goto _lbl_01F716E0; }
    r_v0 = (long)(0 + (2));
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001AB9D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F71700;
    r_v0 = (long)(0 + (2));
_lbl_01F716E0:
    if (r_s2 != r_v0) goto _lbl_01F71700;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (32)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (56)); }
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (172)); }
    r_v0 = (long)func_002257A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001ABA70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F71700:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F71704:
    r_v0 = (long)((long)r_s2 < (long)(3) ? 1 : 0);
    if (r_v0 != 0) { r_a1 = (long)(0 + (1)); goto _lbl_01F71394; }
    r_a1 = (long)(0 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F71C40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F724A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5864)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3696)); }
    r_a3 = (long)(0 + (0x5a));
    r_t0 = (long)(r_a3 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a1 = (long)(r_v1 + (0x56));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a2 = (long)(r_v0 + (0x3c));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5868)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3696)); }
    r_a3 = (long)(0 + (0x5a));
    r_t0 = (long)(r_a3 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a1 = (long)(r_v1 + (0xb8));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a2 = (long)(r_v0 + (0x3c));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(0 | 0);
    goto _lbl_01F717B4;
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F7177C:
    r_v0 = (long)(r_s5 + r_v0);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3696)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5852)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3692)); }
    r_a3 = (long)(0 + (0xa0));
    r_t0 = (long)(0 + (0x10));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_v1 = (long)(r_v1 + (0x63));
    r_v0 = (long)((unsigned long)r_s0 << (4));
    r_a1 = (long)(r_a1 + (0xb7));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a2 = (long)(r_v1 + r_v0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_s0 + (1));
_lbl_01F717B4:
    r_v0 = (long)((long)r_s0 < (long)(3) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (2)); goto _lbl_01F7177C; }
    r_v0 = (long)((unsigned long)r_s0 << (2));
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (88)); }
    goto _lbl_01F71868;
_lbl_01F717C8:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (0)); }
    r_v0 = (long)(0 + (1));
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (266)); }
    if (r_v1 != r_v0) goto _lbl_01F71860;
    r_v0 = (long)func_001F6DB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (0)); }
    r_s0 = (long)(r_v0 | 0);
    r_v0 = (long)func_001F6DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (0)); }
    r_s1 = (long)(r_v0 | 0);
    r_v0 = (long)func_001F6DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (0)); }
    r_s3 = (long)(r_v0 | 0);
    r_v0 = (long)func_001F6DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (3544)); }
    r_v1 = (long)(r_s1 + r_s3);
    r_v1 = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F71860;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3536)); }
    r_v1 = (long)(r_a0 + r_v1);
    r_at = (long)((long)r_v1 < (long)r_s1 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F71860;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    r_v0 = (long)(r_s0 + r_v0);
    r_v0 = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F71860;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3532)); }
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)((long)r_v0 < (long)r_s0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F71860;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (0)); }
    r_v0 = (long)func_002181F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F71860:
    if (r_s2) { r_s2 = *(int *)((char *)r_s2 + (8)); }
_lbl_01F71868:
    if (r_s2 != 0) goto _lbl_01F717C8;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a1 = (long)(r_s5 + (0x24));
    r_v0 = (long)func_001AC320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5848)); }
    r_a1 = (long)(0 + (2));
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F6850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5848)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5828)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5872)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (56)); }
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (5788)); }
    r_v0 = (long)((long)r_a1 < (long)0 ? 1 : 0);
    r_v0 = (long)(r_v0 ^ (1));
    if (r_v0 == 0) { r_a1 = (long)(0 + (4)); goto _lbl_01F718E8; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5880)); }
    goto _lbl_01F718EC;
    r_a1 = (long)(0 + (4));
_lbl_01F718E8:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5880)); }
_lbl_01F718EC:
    r_v0 = (long)func_002134F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5880)); }
    if (r_s5) { r_s1 = *(int *)((char *)r_s5 + (3696)); }
    if ((long)r_s1 >= 0) { if (r_a0) { r_s0 = *(int *)((char *)r_a0 + (564)); } goto _lbl_01F71908; }
    if (r_a0) { r_s0 = *(int *)((char *)r_a0 + (564)); }
    /* unhandled: negu $s1 $s1 */
_lbl_01F71908:
    r_at = (long)((long)r_s1 < (long)(0x3b) ? 1 : 0);
    if (r_at == 0) { r_s1 = (long)(r_s1 + (-0x3b)); goto _lbl_01F7192C; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3544)); }
    r_v0 = (long)(r_v0 + (0x3b));
    r_a2 = (long)(r_v0 - r_s1);
    r_s1 = (long)(0 | 0);
    goto _lbl_01F71930;
    r_s1 = (long)(r_s1 + (-0x3b));
_lbl_01F7192C:
    r_a2 = (long)(0 | 0);
_lbl_01F71930:
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3540)); }
    r_a3 = (long)(0 + (0x34));
    r_t0 = (long)(0 + (0x22c));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a1 = (long)(r_v0 + (0xa));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s1 != 0) { if (r_gp) { *(int *)((char *)r_gp + (-29648)) = (int)r_s1; } goto _lbl_01F71974; }
    if (r_gp) { *(int *)((char *)r_gp + (-29648)) = (int)r_s1; }
    if (r_s0) { r_a0 = *(unsigned char *)((char *)r_s0 + (19)); }
    r_v0 = (long)(0 & (1));
    r_v1 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(0 + (-5));
    r_v0 = (long)(r_a0 & r_v0);
    r_v0 = (long)(r_v0 | r_v1);
    if (r_s0) { *(char *)((char *)r_s0 + (19)) = (char)r_v0; }
    goto _lbl_01F7198C;
_lbl_01F71974:
    if (r_s0) { r_a0 = *(unsigned char *)((char *)r_s0 + (19)); }
    r_v0 = (long)(0 + (-5));
    r_v0 = (long)(r_a0 & r_v0);
    r_v0 = (long)(r_v0 | r_v1);
    if (r_s0) { *(char *)((char *)r_s0 + (19)) = (char)r_v0; }
_lbl_01F7198C:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5880)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (56)); }
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s5) { *(int *)((char *)r_s5 + (3556)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (3588)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (3592)) = (int)0; }
_lbl_01F719AC:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
_lbl_01F719B0:
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x4430));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 41: thelp_func_01F719DC (VMA: 0x01F719DC, size: 476 bytes) */
void *thelp_func_01F719DC(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
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
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_t2 = (long)(r_a0 | 0);
    if (r_t0 != 0) { if (r_gp) { *(int *)((char *)r_gp + (-29648)) = (int)r_t0; } goto _lbl_01F71A0C; }
    if (r_gp) { *(int *)((char *)r_gp + (-29648)) = (int)r_t0; }
    if (r_a1) { r_a0 = *(unsigned char *)((char *)r_a1 + (19)); }
    r_v0 = (long)(0 & (1));
    r_v1 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(0 + (-5));
    r_v0 = (long)(r_a0 & r_v0);
    r_v0 = (long)(r_v0 | r_v1);
    if (r_a1) { *(char *)((char *)r_a1 + (19)) = (char)r_v0; }
    goto _lbl_01F71A24;
_lbl_01F71A0C:
    if (r_a1) { r_a0 = *(unsigned char *)((char *)r_a1 + (19)); }
    r_v0 = (long)(0 + (-5));
    r_v0 = (long)(r_a0 & r_v0);
    r_v0 = (long)(r_v0 | r_v1);
    if (r_a1) { *(char *)((char *)r_a1 + (19)) = (char)r_v0; }
_lbl_01F71A24:
    r_a0 = (long)(r_a1 | 0);
    if (r_t2) { r_a1 = *(int *)((char *)r_t2 + (32)); }
    r_t0 = (long)(r_t1 | 0);
    r_t1 = (long)(0 | 0);
    return (void *)0x25E640;
    r_sp = (long)(r_sp + (-0x70));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_s3 = *(int *)((char *)r_a0 + (3696)); }
    r_s4 = (long)(r_a1 | 0);
    if ((long)r_s3 >= 0) { r_s5 = (long)(r_a0 | 0); goto _lbl_01F71A74; }
    r_s5 = (long)(r_a0 | 0);
    /* unhandled: negu $s3 $s3 */
_lbl_01F71A74:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_001AB8F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F71B94;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (5812)); }
    if (r_v0 == 0) goto _lbl_01F71AF8;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3548)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3676)); }
    if (r_v0 != 0) { /* unhandled: div $zero $v1 $v0 */ goto _lbl_01F71AA8; }
    /* unhandled: div $zero $v1 $v0 */
    /* unhandled: break 0 7 */
_lbl_01F71AA8:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3692)); }
    /* unhandled: mflo $a0 */
    r_s1 = (long)(0 | 0);
    r_s2 = (long)(r_a0 + (1));
    r_s0 = (long)(r_v1 + r_v0);
    goto _lbl_01F71AEC;
_lbl_01F71AC4:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3676)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (5812)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3544)); }
    r_t0 = (long)(r_s3 + (0x10));
    r_t1 = (long)(0 + (2));
    /* unhandled: mult $ac2 $s1 $v0 */
    r_a0 = (long)(r_s5 | 0);
    r_a2 = (long)(r_s0 + r_v0);
    r_v0 = (long)func_01F71A60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_s1 + (1));
_lbl_01F71AEC:
    r_v0 = (long)((long)r_s1 < (long)r_s2 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F71AC4;
_lbl_01F71AF8:
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (5816)); }
    if (r_a1 == 0) goto _lbl_01F71B58;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3544)); }
    r_t0 = (long)(r_s3 + (0x10));
    r_a0 = (long)(r_s5 | 0);
    r_t1 = (long)(0 | 0);
    r_a2 = (long)(r_v1 + r_v0);
    r_v0 = (long)func_01F71A60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_t1 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (3548)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3684)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (5816)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3544)); }
    r_t0 = (long)(r_s3 + (0x10));
    r_a2 = (long)(r_t1 + r_a2);
    r_v1 = (long)(r_v1 + r_a2);
    r_t1 = (long)(0 + (1));
    r_a0 = (long)(r_s5 | 0);
    r_a2 = (long)(r_v1 - r_v0);
    r_v0 = (long)func_01F71A60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F71B58:
    if (r_s4 == 0) goto _lbl_01F71B8C;
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (1144)); }
    if (r_a1 == 0) goto _lbl_01F71B8C;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001AE110((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (36)); }
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (40)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (44)); }
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (48)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001AE120((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F71B8C:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001AB9D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F71B94:
    /* unhandled: ld.b $w1 -0x41($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 42: thelp_func_01F71BB8 (VMA: 0x01F71BB8, size: 2140 bytes) */
void *thelp_func_01F71BB8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0;
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
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    (void)r_t7;
    r_sp = (long)(r_sp + (-0x90));
    /* unhandled: ext $ra $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s5 = (long)(r_a0 | 0);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (32)); }
    r_a1 = (long)(0 + (1));
    r_s0 = (long)(0 | 0);
    r_s1 = (long)(0 | 0);
    r_v0 = (long)func_001AB8F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F723E8;
    r_s2 = (long)(0 | 0);
    goto _lbl_01F71D24;
    r_v0 = (long)(0 + (0x405c));
_lbl_01F71C14:
    r_s3 = (long)(0 | 0);
    goto _lbl_01F71D14;
    r_v0 = (long)(0 + (0xcd0));
_lbl_01F71C24:
    /* unhandled: mult $ac2 $s3 $v0 */
    r_s4 = (long)(0 | 0);
    r_s6 = (long)(r_s7 + r_v0);
    goto _lbl_01F71D04;
_lbl_01F71C34:
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)((unsigned long)r_s4 << (2));
    r_v0 = (long)(r_v0 + r_s4);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(r_v0 + r_s4);
    r_v1 = (long)(r_s6 + r_a1);
    r_v0 = (long)((unsigned long)r_v0 << (4));
    r_a0 = (long)(r_v1 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (624)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_s4 = (long)(r_s4 + (1)); goto _lbl_01F71D04; }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (636)); }
    if ((long)r_v0 < 0) goto _lbl_01F71D00;
    r_v1 = (long)(r_s7 + r_a1);
    if (r_a0) { r_a3 = *(int *)((char *)r_a0 + (628)); }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (632)); }
    r_v0 = (long)(0 + (0xcd0));
    if (r_s5) { r_t5 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_t3 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (680)); }
    r_v0 = (long)((unsigned long)r_a3 << (2));
    r_a2 = (long)(r_v0 + r_a3);
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3656)); }
    r_a2 = (long)((unsigned long)r_a2 << (3));
    r_a3 = (long)(r_a2 + r_a3);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3544)); }
    r_t0 = (long)(r_v1 + r_t0);
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (3652)); }
    r_a3 = (long)((unsigned long)r_a3 << (4));
    r_a3 = (long)(r_t0 + r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3696)); }
    if (r_a3) { r_t4 = *(int *)((char *)r_a3 + (676)); }
    r_a0 = (long)(r_v0 + r_a0);
    r_t2 = (long)((long)r_a1 >> (1));
    r_a1 = (long)(r_v1 + r_a0);
    if (r_a3) { r_a3 = *(int *)((char *)r_a3 + (680)); }
    r_t0 = (long)(r_a1 + (-1));
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a1 = (long)(r_t5 + r_t4);
    r_a1 = (long)(r_t3 + r_a1);
    r_v0 = (long)(r_v0 + r_a3);
    r_v0 = (long)(r_v1 + r_v0);
    r_a1 = (long)(r_t2 + r_a1);
    r_v0 = (long)(r_a2 + r_v0);
    r_a2 = (long)(r_v0 + (1));
    r_a3 = (long)(r_a1 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F71D00:
    r_s4 = (long)(r_s4 + (1));
_lbl_01F71D04:
    r_v0 = (long)((long)r_s4 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F71C34;
    r_s3 = (long)(r_s3 + (1));
_lbl_01F71D14:
    r_v0 = (long)((long)r_s3 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(0 + (0xcd0)); goto _lbl_01F71C24; }
    r_v0 = (long)(0 + (0xcd0));
    r_s2 = (long)(r_s2 + (1));
_lbl_01F71D24:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2080)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(0 + (0x405c)); goto _lbl_01F71C14; }
    r_v0 = (long)(0 + (0x405c));
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_s4 = (long)(0 | 0);
    r_s7 = (long)(0 | 0);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (4)); }
    r_s3 = (long)(0 | 0);
    goto _lbl_01F71FA8;
_lbl_01F71D4C:
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)((unsigned long)r_s3 << (5));
    r_v1 = (long)(r_v0 - r_s3);
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 - r_v1);
    r_s2 = (long)((unsigned long)r_v0 << (3));
    r_a1 = (long)(r_a2 + r_s2);
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (672)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_s7 = (long)(r_s3 | 0); goto _lbl_01F71D98; }
    r_s7 = (long)(r_s3 | 0);
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (4)); }
    if (r_a0 == r_v0) { r_s0 = (long)(r_s3 | 0); goto _lbl_01F71D94; }
    r_s0 = (long)(r_s3 | 0);
    r_s0 = (long)(r_s1 | 0);
    r_s1 = (long)(r_s3 | 0);
    goto _lbl_01F71D98;
    r_s0 = (long)(r_s3 | 0);
_lbl_01F71D94:
    r_s1 = (long)(r_s3 | 0);
_lbl_01F71D98:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (4)); }
    if (r_a0 == r_v0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F71FA8; }
    r_v0 = (long)((unsigned long)r_s0 << (5));
    r_v1 = (long)(r_v0 - r_s0);
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 - r_v1);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_a0 = (long)(r_a2 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (528)); }
    r_v0 = (long)(0 + (5));
    if (r_v1 != r_v0) goto _lbl_01F71F80;
    r_at = (long)((long)r_s4 < (long)r_s3 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F71DDC;
    r_s7 = (long)(r_s7 + (-1));
_lbl_01F71DDC:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (656)); }
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3696)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (3656)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (660)); }
    r_t0 = (long)(r_t0 + r_v0);
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3652)); }
    r_a3 = (long)(r_a3 + r_t0);
    r_a1 = (long)(r_a1 + r_a0);
    r_v1 = (long)(r_v1 + r_a1);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v1 = (long)(r_v0 + r_v1);
    r_v0 = (long)((long)r_a2 >> (1));
    r_a1 = (long)(r_v0 + r_a3);
    r_s6 = (long)(r_v1 + (4));
    r_a3 = (long)(r_a1 + (1));
    r_a2 = (long)(r_v1 + (1));
    r_t0 = (long)(r_s6 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x405c));
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (2084)); }
    r_t1 = (long)(0 + (0xcd0));
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3692)); }
    r_t5 = (long)(r_a2 + r_a1);
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3656)); }
    if (r_t5) { r_t2 = *(int *)((char *)r_t5 + (28)); }
    if (r_t5) { r_t3 = *(int *)((char *)r_t5 + (32)); }
    r_t6 = (long)(r_a2 + r_a0);
    if (r_t6) { r_a0 = *(int *)((char *)r_t6 + (28)); }
    r_a3 = (long)((long)r_a1 >> (1));
    r_a1 = (long)((unsigned long)r_t3 << (2));
    r_a1 = (long)(r_a1 + r_t3);
    if (r_t6) { r_a2 = *(int *)((char *)r_t6 + (32)); }
    r_a1 = (long)((unsigned long)r_a1 << (3));
    r_a1 = (long)(r_a1 + r_t3);
    r_t4 = (long)(r_t5 + r_t4);
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    r_a1 = (long)((unsigned long)r_a1 << (4));
    r_a1 = (long)(r_t4 + r_a1);
    if (r_a1) { r_t3 = *(int *)((char *)r_a1 + (676)); }
    r_t2 = (long)(r_t6 + r_a0);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_t0 = (long)(r_s6 + (1));
    r_a1 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 + r_a2);
    r_a1 = (long)((unsigned long)r_a1 << (3));
    r_a2 = (long)(r_a1 + r_a2);
    r_a2 = (long)((unsigned long)r_a2 << (4));
    r_a2 = (long)(r_t2 + r_a2);
    if (r_a2) { r_t2 = *(int *)((char *)r_a2 + (676)); }
    r_a1 = (long)(r_v0 + r_t3);
    r_a1 = (long)(r_v1 + r_a1);
    r_a1 = (long)(r_a3 + r_a1);
    r_v0 = (long)(r_v0 + r_t2);
    r_v0 = (long)(r_v1 + r_v0);
    r_v0 = (long)(r_a3 + r_v0);
    r_a3 = (long)(r_v0 + (1));
    r_a2 = (long)(r_s6 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_s6 + (1));
    goto _lbl_01F71F74;
    r_v1 = (long)(0 + (0x405c));
_lbl_01F71EF4:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s5) { r_t2 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3544)); }
    r_v1 = (long)(0 + (0xcd0));
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    r_t4 = (long)(r_v0 + r_a0);
    if (r_t4) { r_t3 = *(int *)((char *)r_t4 + (28)); }
    if (r_t4) { r_t0 = *(int *)((char *)r_t4 + (32)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3696)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a2 = (long)(r_s6 | 0);
    r_v1 = (long)((unsigned long)r_t0 << (2));
    r_v1 = (long)(r_v1 + r_t0);
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(r_v1 + r_t0);
    r_t3 = (long)(r_t4 + r_t3);
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_v1 = (long)(r_t3 + r_v1);
    if (r_v1) { r_t0 = *(int *)((char *)r_v1 + (676)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (680)); }
    r_t0 = (long)(r_t2 + r_t0);
    r_a3 = (long)(r_a3 + r_t0);
    r_v1 = (long)(r_a1 + r_v1);
    r_v0 = (long)(r_v0 + r_v1);
    r_a1 = (long)(r_a3 + (0x25));
    r_t0 = (long)(r_v0 + (-1));
    r_a3 = (long)(r_a1 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s4 = (long)(r_s4 + (1));
_lbl_01F71F74:
    r_at = (long)((long)r_s7 < (long)r_s4 ? 1 : 0);
    if (r_at == 0) { r_v1 = (long)(0 + (0x405c)); goto _lbl_01F71EF4; }
    r_v1 = (long)(0 + (0x405c));
_lbl_01F71F80:
    if (r_s0 == r_s1) goto _lbl_01F71F8C;
    r_s0 = (long)(r_s1 | 0);
_lbl_01F71F8C:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_s4 = (long)(r_s3 | 0);
    r_s7 = (long)(r_s3 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (4)); }
    r_s3 = (long)(r_s3 + (1));
_lbl_01F71FA8:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2072)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F71D4C;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)((unsigned long)r_s0 << (5));
    r_v1 = (long)(r_v0 - r_s0);
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 - r_v1);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_a0 = (long)(r_v0 + r_a0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (528)); }
    r_v0 = (long)(0 + (5));
    if (r_v1 != r_v0) { r_s2 = (long)(0 | 0); goto _lbl_01F721A8; }
    r_s2 = (long)(0 | 0);
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (656)); }
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3696)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (3656)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (660)); }
    r_t0 = (long)(r_t0 + r_v0);
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3652)); }
    r_a3 = (long)(r_a3 + r_t0);
    r_a1 = (long)(r_a1 + r_a0);
    r_v1 = (long)(r_v1 + r_a1);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v1 = (long)(r_v0 + r_v1);
    r_v0 = (long)((long)r_a2 >> (1));
    r_a1 = (long)(r_v0 + r_a3);
    r_s0 = (long)(r_v1 + (4));
    r_a3 = (long)(r_a1 + (1));
    r_a2 = (long)(r_v1 + (1));
    r_t0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_t6 = *(int *)((char *)r_s5 + (2084)); }
    r_v0 = (long)(0 + (0x405c));
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (3656)); }
    r_t4 = (long)(0 + (0xcd0));
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3540)); }
    r_a1 = (long)(r_t6 + (0x1c));
    r_a0 = (long)(r_a1 + r_t5);
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3692)); }
    if (r_a0) { r_t0 = *(int *)((char *)r_a0 + (0)); }
    r_a1 = (long)(r_a1 + r_v0);
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    r_t7 = (long)(r_t6 + (0x2a4));
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (0)); }
    r_t2 = (long)((long)r_a2 >> (1));
    r_t6 = (long)(r_t6 + (0x20));
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_t0 = (long)(r_t7 + r_t5);
    r_t3 = (long)(r_t0 + r_t3);
    r_a1 = (long)(r_t6 + r_t5);
    if (r_a1) { r_t0 = *(int *)((char *)r_a1 + (0)); }
    r_a1 = (long)(r_t7 + r_v0);
    r_a2 = (long)(r_a1 + r_a2);
    r_v0 = (long)(r_t6 + r_v0);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)((unsigned long)r_t0 << (2));
    r_v0 = (long)(r_v0 + r_t0);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(r_v0 + r_t0);
    r_v0 = (long)((unsigned long)r_v0 << (4));
    r_v0 = (long)(r_t3 + r_v0);
    if (r_v0) { r_t0 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)((unsigned long)r_a1 << (2));
    r_v0 = (long)(r_v0 + r_a1);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)(r_v0 + r_a1);
    r_v0 = (long)((unsigned long)r_v0 << (4));
    r_v0 = (long)(r_a2 + r_v0);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    r_a1 = (long)(r_v1 + r_t0);
    r_a1 = (long)(r_a3 + r_a1);
    r_a1 = (long)(r_t2 + r_a1);
    r_v0 = (long)(r_v1 + r_v0);
    r_v0 = (long)(r_a3 + r_v0);
    r_v0 = (long)(r_t2 + r_v0);
    r_t0 = (long)(r_s0 + (1));
    r_a3 = (long)(r_v0 + (1));
    r_a2 = (long)(r_s0 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
    goto _lbl_01F72198;
    r_v1 = (long)(0 + (0x405c));
_lbl_01F72118:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2084)); }
    if (r_s5) { r_t2 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3544)); }
    r_v1 = (long)(0 + (0xcd0));
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    r_t4 = (long)(r_v0 + r_a0);
    if (r_t4) { r_t3 = *(int *)((char *)r_t4 + (28)); }
    if (r_t4) { r_t0 = *(int *)((char *)r_t4 + (32)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3696)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a2 = (long)(r_s0 | 0);
    r_v1 = (long)((unsigned long)r_t0 << (2));
    r_v1 = (long)(r_v1 + r_t0);
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(r_v1 + r_t0);
    r_t3 = (long)(r_t4 + r_t3);
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_v1 = (long)(r_t3 + r_v1);
    if (r_v1) { r_t0 = *(int *)((char *)r_v1 + (676)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (680)); }
    r_t0 = (long)(r_t2 + r_t0);
    r_a3 = (long)(r_a3 + r_t0);
    r_v1 = (long)(r_a1 + r_v1);
    r_v0 = (long)(r_v0 + r_v1);
    r_a1 = (long)(r_a3 + (0x25));
    r_t0 = (long)(r_v0 + (-1));
    r_a3 = (long)(r_a1 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s4 = (long)(r_s4 + (1));
_lbl_01F72198:
    r_at = (long)((long)r_s7 < (long)r_s4 ? 1 : 0);
    if (r_at == 0) { r_v1 = (long)(0 + (0x405c)); goto _lbl_01F72118; }
    r_v1 = (long)(0 + (0x405c));
    r_s2 = (long)(0 | 0);
_lbl_01F721A8:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2072)); }
    goto _lbl_01F723D4;
    r_v0 = (long)((unsigned long)r_s2 << (5));
_lbl_01F721B4:
    r_v1 = (long)(r_v0 - r_s2);
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 - r_v1);
    r_s0 = (long)((unsigned long)r_v0 << (3));
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)(0 + (1));
    r_a0 = (long)(r_v0 + r_s0);
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (532)); }
    if (r_v0 != r_v1) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F723D0; }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (676)); }
    if (r_v0 != r_v1) goto _lbl_01F723CC;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (4)); }
    r_v0 = (long)(0 + (0x48));
    if (r_v1 == r_v0) goto _lbl_01F723CC;
    r_v0 = (long)(0 + (0x256));
    if (r_v1 == r_v0) goto _lbl_01F723CC;
    r_v0 = (long)(0 + (0x1e7));
    if (r_v1 == r_v0) goto _lbl_01F723CC;
    r_v0 = (long)(0 + (0xeb));
    if (r_v1 == r_v0) goto _lbl_01F723CC;
    r_s3 = (long)(0 | 0);
    goto _lbl_01F723C0;
_lbl_01F72224:
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (2076)); }
    r_v0 = (long)((unsigned long)r_s3 << (2));
    r_t1 = (long)(r_s0 + r_a3);
    r_a1 = (long)(r_t1 + r_v0);
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (680)); }
    if ((long)r_v0 < 0) goto _lbl_01F723CC;
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (2072)); }
    r_s1 = (long)(0 + (-1));
    r_v1 = (long)(0 + (1));
    r_t2 = (long)(0 | 0);
    goto _lbl_01F72294;
    r_v0 = (long)((unsigned long)r_t2 << (5));
_lbl_01F72258:
    r_a0 = (long)(r_v0 - r_t2);
    r_v0 = (long)((unsigned long)r_a0 << (2));
    r_v0 = (long)(r_v0 - r_a0);
    r_v0 = (long)((unsigned long)r_v0 << (3));
    r_t0 = (long)(r_a3 + r_v0);
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (680)); }
    if (r_t0) { r_a0 = *(int *)((char *)r_t0 + (4)); }
    if (r_a0 != r_v0) { r_t2 = (long)(r_t2 + (1)); goto _lbl_01F72294; }
    if (r_t0) { r_v0 = *(int *)((char *)r_t0 + (672)); }
    if (r_v0 != r_v1) goto _lbl_01F72290;
    r_s1 = (long)(r_t2 | 0);
    goto _lbl_01F722A0;
_lbl_01F72290:
    r_t2 = (long)(r_t2 + (1));
_lbl_01F72294:
    r_v0 = (long)((long)r_t2 < (long)r_a2 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_t2 << (5)); goto _lbl_01F72258; }
    r_v0 = (long)((unsigned long)r_t2 << (5));
_lbl_01F722A0:
    if ((long)r_s1 < 0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F723C0; }
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (3540)); }
    if (r_t1) { r_v0 = *(int *)((char *)r_t1 + (656)); }
    if (r_t1) { r_a0 = *(int *)((char *)r_t1 + (660)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3696)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (3656)); }
    r_t0 = (long)(r_t0 + r_v0);
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3652)); }
    r_a1 = (long)(r_a1 + r_a0);
    r_v1 = (long)(r_v1 + r_a1);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a3 = (long)(r_a3 + r_t0);
    r_v1 = (long)(r_v0 + r_v1);
    r_v0 = (long)((long)r_a2 >> (1));
    r_a1 = (long)(r_v0 + r_a3);
    r_s4 = (long)(r_v1 + (4));
    r_a3 = (long)(r_a1 + (1));
    r_a2 = (long)(r_v1 + (1));
    r_t0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (2076)); }
    r_v1 = (long)((unsigned long)r_s1 << (5));
    r_a0 = (long)(r_v1 - r_s1);
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3656)); }
    if (r_s5) { r_t2 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3692)); }
    r_v1 = (long)(r_s0 + r_a3);
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    if (r_v1) { r_a2 = *(int *)((char *)r_v1 + (656)); }
    r_t3 = (long)((long)r_a1 >> (1));
    r_t0 = (long)(r_s4 + (1));
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 - r_a0);
    r_s1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(r_a3 + r_s1);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (656)); }
    r_a1 = (long)(r_t2 + r_a2);
    r_a1 = (long)(r_v0 + r_a1);
    r_a1 = (long)(r_t3 + r_a1);
    r_v1 = (long)(r_t2 + r_v1);
    r_v0 = (long)(r_v0 + r_v1);
    r_v0 = (long)(r_t3 + r_v0);
    r_a3 = (long)(r_v0 + (1));
    r_a2 = (long)(r_s4 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2076)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3656)); }
    if (r_s5) { r_t3 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (3696)); }
    r_a0 = (long)(r_a0 + r_s1);
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5936)); }
    if (r_a0) { r_t2 = *(int *)((char *)r_a0 + (656)); }
    r_a1 = (long)((long)r_v1 >> (1));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (660)); }
    r_a2 = (long)(r_s4 + (1));
    r_t2 = (long)(r_t3 + r_t2);
    r_t0 = (long)(r_t0 + r_t2);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v1 = (long)(r_a3 + r_v1);
    r_a1 = (long)(r_a1 + r_t0);
    r_v0 = (long)(r_v0 + r_v1);
    r_t0 = (long)(r_v0 + (-1));
    r_a3 = (long)(r_a1 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F723C0:
    r_v0 = (long)((long)r_s3 < (long)(5) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F72224;
_lbl_01F723CC:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F723D0:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2072)); }
_lbl_01F723D4:
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (5)); goto _lbl_01F721B4; }
    r_v0 = (long)((unsigned long)r_s2 << (5));
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001AB9D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F723E8:
    /* unhandled: xori.b $w2 $w0 0xbf */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 43: thelp_func_01F72414 (VMA: 0x01F72414, size: 1848 bytes) */
void *thelp_func_01F72414(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
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
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0xd0));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (3636)); }
    if (r_v1 == 0) { r_s6 = (long)(r_a0 | 0); goto _lbl_01F72B1C; }
    r_s6 = (long)(r_a0 | 0);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (3640)); }
    if (r_a0 != 0) goto _lbl_01F7246C;
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    goto _lbl_01F72B20;
_lbl_01F7246C:
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (644)); }
    if ((long)r_v1 < 0) goto _lbl_01F72B1C;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (640)); }
    if ((long)r_v1 < 0) goto _lbl_01F72B1C;
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_001AB8F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F72B1C;
    if (r_s6) { r_s5 = *(int *)((char *)r_s6 + (3640)); }
    r_v0 = (long)(0 + (1));
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (516)); }
    if (r_v1 != r_v0) goto _lbl_01F724BC;
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (3648)); }
    if (r_s6) { r_s8 = *(int *)((char *)r_s6 + (3644)); }
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)r_v0; }
    goto _lbl_01F724C8;
_lbl_01F724BC:
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (3656)); }
    if (r_s6) { r_s8 = *(int *)((char *)r_s6 + (3652)); }
    if (r_sp) { *(int *)((char *)r_sp + (176)) = (int)r_v0; }
_lbl_01F724C8:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
    r_s0 = (long)((long)r_v0 >> (1));
    goto _lbl_01F72868;
_lbl_01F724D4:
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (640)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
    if (r_s6) { r_a1 = *(int *)((char *)r_s6 + (3540)); }
    if (r_s6) { r_a2 = *(int *)((char *)r_s6 + (3692)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (644)); }
    if (r_s6) { r_t0 = *(int *)((char *)r_s6 + (3544)); }
    if (r_s6) { r_t2 = *(int *)((char *)r_s6 + (3696)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    r_v0 = (long)(r_a1 + r_v0);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_s4 = (long)(r_a2 + r_v0);
    r_v0 = (long)(r_a3 + r_t0);
    r_s2 = (long)(r_t2 + r_v0);
    r_v0 = (long)(r_a3 + r_s8);
    r_v0 = (long)(r_t0 + r_v0);
    r_v1 = (long)(r_v1 + r_a1);
    r_s1 = (long)(r_a2 + r_v1);
    r_s3 = (long)(r_t2 + r_v0);
    r_a1 = (long)(r_s1 + (-2));
    r_a2 = (long)(r_s2 + (-2));
    r_a3 = (long)(r_s4 + (1));
    r_t0 = (long)(r_s2 + (-1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s1 + (-2));
    r_a3 = (long)(r_s4 + (1));
    r_t0 = (long)(r_s3 + (1));
    r_a2 = (long)(r_s3 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s1 + (-2));
    r_a2 = (long)(r_s2 + (-2));
    r_a3 = (long)(r_s1 + (-1));
    r_t0 = (long)(r_s3 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a2 = (long)(r_s2 + (-2));
    r_a3 = (long)(r_s4 + (1));
    r_t0 = (long)(r_s3 + (1));
    r_a1 = (long)(r_s4 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (588)); }
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) { r_s4 = (long)(r_s5 | 0); goto _lbl_01F72638; }
    r_s4 = (long)(r_s5 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (604)); }
    if (r_v0 != r_v1) goto _lbl_01F725D4;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (516)); }
    r_v0 = (long)(0 + (4));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (3)); goto _lbl_01F725BC; }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F725D4;
_lbl_01F725BC:
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (608)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    goto _lbl_01F72678;
_lbl_01F725D4:
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (600)); }
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (516)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    if (r_s5 == 0) goto _lbl_01F72678;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (516)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F72678;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (12)); }
    r_v0 = (long)(0 + (0x256));
    if (r_v1 == r_v0) { r_s5 = (long)(0 | 0); goto _lbl_01F72630; }
    r_v0 = (long)(0 + (0xeb));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (0x48)); goto _lbl_01F7262C; }
    r_v0 = (long)(0 + (0x48));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (0x1e7)); goto _lbl_01F7262C; }
    r_v0 = (long)(0 + (0x1e7));
    if (r_v1 != r_v0) goto _lbl_01F72678;
_lbl_01F7262C:
    r_s5 = (long)(0 | 0);
_lbl_01F72630:
    goto _lbl_01F72678;
_lbl_01F72638:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (604)); }
    if (r_v0 != r_v1) { r_s5 = (long)(0 | 0); goto _lbl_01F72678; }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (516)); }
    r_v0 = (long)(0 + (4));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (3)); goto _lbl_01F7265C; }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F72674;
_lbl_01F7265C:
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (608)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    goto _lbl_01F72678;
_lbl_01F72674:
    r_s5 = (long)(0 | 0);
_lbl_01F72678:
    if (r_s4 == 0) goto _lbl_01F72868;
    if (r_s5 == 0) goto _lbl_01F72868;
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (516)); }
    r_v0 = (long)(0 + (1));
    if (r_a0 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F726AC; }
    r_v0 = (long)(0 + (1));
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (12)); }
    r_v0 = (long)(0 + (0x256));
    if (r_v1 == r_v0) goto _lbl_01F72868;
    r_v0 = (long)(0 + (1));
_lbl_01F726AC:
    if (r_a0 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F726C8; }
    r_v0 = (long)(0 + (1));
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (12)); }
    r_v0 = (long)(0 + (0xeb));
    if (r_v1 == r_v0) goto _lbl_01F72868;
    r_v0 = (long)(0 + (1));
_lbl_01F726C8:
    if (r_a0 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F726E4; }
    r_v0 = (long)(0 + (1));
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (12)); }
    r_v0 = (long)(0 + (0x48));
    if (r_v1 == r_v0) goto _lbl_01F72868;
    r_v0 = (long)(0 + (1));
_lbl_01F726E4:
    if (r_a0 != r_v0) goto _lbl_01F726FC;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (12)); }
    r_v0 = (long)(0 + (0x1e7));
    if (r_v1 == r_v0) goto _lbl_01F72868;
_lbl_01F726FC:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (640)); }
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (3540)); }
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (3692)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (644)); }
    if (r_s6) { r_a2 = *(int *)((char *)r_s6 + (3544)); }
    if (r_s6) { r_a3 = *(int *)((char *)r_s6 + (3696)); }
    r_v1 = (long)(r_a0 + r_v1);
    r_v0 = (long)(r_v0 + r_v1);
    if (r_sp) { *(int *)((char *)r_sp + (160)) = (int)r_v0; }
    r_v0 = (long)(r_a1 + r_a2);
    r_s7 = (long)(r_a3 + r_v0);
    r_v0 = (long)(r_a1 + r_s8);
    r_v0 = (long)(r_a2 + r_v0);
    r_s4 = (long)(r_a3 + r_v0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (160)); }
    if (r_s1 != r_v0) { r_at = (long)((long)r_s2 < (long)r_s7 ? 1 : 0); goto _lbl_01F72794; }
    r_at = (long)((long)r_s2 < (long)r_s7 ? 1 : 0);
    r_at = (long)((long)r_s2 < (long)r_s7 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F72770;
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s1 + r_s0);
    r_a2 = (long)(r_s3 + (2));
    r_t0 = (long)(r_s7 + (-2));
    r_a3 = (long)(r_a1 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F72868;
_lbl_01F72770:
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s1 + r_s0);
    r_a2 = (long)(r_s4 + (2));
    r_t0 = (long)(r_s2 + (-2));
    r_a3 = (long)(r_a1 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F72868;
_lbl_01F72794:
    if (r_at == 0) goto _lbl_01F72808;
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_s1 = (long)(r_s1 + r_s0);
    r_a2 = (long)(r_s3 + (2));
    r_a3 = (long)(r_s1 + (1));
    r_t0 = (long)(r_s3 + (4));
    r_a1 = (long)(r_s1 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (160)); }
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s1 | 0);
    r_a2 = (long)(r_s3 + (4));
    r_s2 = (long)(r_v0 + r_s0);
    r_s1 = (long)(r_s2 + (1));
    r_t0 = (long)(r_s3 + (5));
    r_a3 = (long)(r_s1 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a2 = (long)(r_s3 + (4));
    r_t0 = (long)(r_s7 + (-2));
    r_a1 = (long)(r_s2 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F72868;
_lbl_01F72808:
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_s3 = (long)(r_v0 + r_s0);
    r_a2 = (long)(r_s4 + (2));
    r_a3 = (long)(r_s3 + (1));
    r_t0 = (long)(r_s4 + (4));
    r_a1 = (long)(r_s3 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    r_s7 = (long)(r_s1 + r_s0);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_s1 = (long)(r_s7 + (1));
    r_a2 = (long)(r_s4 + (4));
    r_t0 = (long)(r_s4 + (5));
    r_a1 = (long)(r_s3 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a2 = (long)(r_s4 + (4));
    r_t0 = (long)(r_s2 + (-2));
    r_a1 = (long)(r_s7 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F72868:
    if (r_s5 != 0) goto _lbl_01F724D4;
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (3640)); }
    r_v0 = (long)(0 + (3));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (516)); }
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (4)); goto _lbl_01F7288C; }
    r_v0 = (long)(0 + (4));
    if (r_v1 != r_v0) goto _lbl_01F72B14;
_lbl_01F7288C:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (604)); }
    if (r_v0 != 0) goto _lbl_01F72B14;
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (12)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    goto _lbl_01F72B0C;
_lbl_01F728B0:
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (640)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (176)); }
    if (r_s6) { r_a1 = *(int *)((char *)r_s6 + (3540)); }
    if (r_s6) { r_a2 = *(int *)((char *)r_s6 + (3692)); }
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (644)); }
    if (r_s6) { r_t0 = *(int *)((char *)r_s6 + (3544)); }
    if (r_s6) { r_t2 = *(int *)((char *)r_s6 + (3696)); }
    r_v0 = (long)(r_v1 + r_v0);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    r_v0 = (long)(r_a1 + r_v0);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_s5 = (long)(r_a2 + r_v0);
    r_v0 = (long)(r_a3 + r_t0);
    r_s3 = (long)(r_t2 + r_v0);
    r_v0 = (long)(r_a3 + r_s8);
    r_v0 = (long)(r_t0 + r_v0);
    r_v1 = (long)(r_v1 + r_a1);
    r_s2 = (long)(r_a2 + r_v1);
    r_s4 = (long)(r_t2 + r_v0);
    r_a1 = (long)(r_s2 + (-2));
    r_a2 = (long)(r_s3 + (-2));
    r_a3 = (long)(r_s5 + (2));
    r_t0 = (long)(r_s3 + (-1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s2 + (-2));
    r_a2 = (long)(r_s4 + (1));
    r_a3 = (long)(r_s5 + (2));
    r_t0 = (long)(r_s4 + (2));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s2 + (-2));
    r_a2 = (long)(r_s3 + (-2));
    r_a3 = (long)(r_s2 + (-1));
    r_t0 = (long)(r_s4 + (2));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s5 + (1));
    r_a3 = (long)(r_s5 + (2));
    r_a2 = (long)(r_s3 + (-2));
    r_t0 = (long)(r_s4 + (2));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (588)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_s5 = (long)(r_s1 | 0); goto _lbl_01F7298C; }
    r_s5 = (long)(r_s1 | 0);
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (600)); }
    if (r_s1) { r_a2 = *(int *)((char *)r_s1 + (516)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F73AB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    goto _lbl_01F72990;
_lbl_01F7298C:
    r_s1 = (long)(0 | 0);
_lbl_01F72990:
    if (r_s5 == 0) goto _lbl_01F72B0C;
    if (r_s1 == 0) goto _lbl_01F72B0C;
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (640)); }
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (3540)); }
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (3692)); }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (644)); }
    if (r_s6) { r_a2 = *(int *)((char *)r_s6 + (3544)); }
    if (r_s6) { r_a3 = *(int *)((char *)r_s6 + (3696)); }
    r_v1 = (long)(r_a0 + r_v1);
    r_v0 = (long)(r_v0 + r_v1);
    if (r_sp) { *(int *)((char *)r_sp + (192)) = (int)r_v0; }
    r_v0 = (long)(r_a1 + r_a2);
    r_s7 = (long)(r_a3 + r_v0);
    r_v0 = (long)(r_a1 + r_s8);
    r_v0 = (long)(r_a2 + r_v0);
    r_s5 = (long)(r_a3 + r_v0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (192)); }
    if (r_s2 != r_v0) { r_at = (long)((long)r_s3 < (long)r_s7 ? 1 : 0); goto _lbl_01F72A38; }
    r_at = (long)((long)r_s3 < (long)r_s7 ? 1 : 0);
    r_at = (long)((long)r_s3 < (long)r_s7 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F72A14;
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s2 + r_s0);
    r_a2 = (long)(r_s4 + (2));
    r_t0 = (long)(r_s7 + (-2));
    r_a3 = (long)(r_a1 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F72B0C;
_lbl_01F72A14:
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s2 + r_s0);
    r_a2 = (long)(r_s5 + (2));
    r_t0 = (long)(r_s3 + (-2));
    r_a3 = (long)(r_a1 + (1));
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F72B0C;
_lbl_01F72A38:
    if (r_at == 0) goto _lbl_01F72AAC;
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_s2 = (long)(r_s2 + r_s0);
    r_a2 = (long)(r_s4 + (2));
    r_a3 = (long)(r_s2 + (1));
    r_t0 = (long)(r_s4 + (4));
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (192)); }
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a1 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s4 + (4));
    r_s3 = (long)(r_v0 + r_s0);
    r_s2 = (long)(r_s3 + (1));
    r_t0 = (long)(r_s4 + (5));
    r_a3 = (long)(r_s2 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a2 = (long)(r_s4 + (4));
    r_t0 = (long)(r_s7 + (-2));
    r_a1 = (long)(r_s3 | 0);
    r_a3 = (long)(r_s2 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F72B0C;
_lbl_01F72AAC:
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_s4 = (long)(r_v0 + r_s0);
    r_a2 = (long)(r_s5 + (2));
    r_a3 = (long)(r_s4 + (1));
    r_t0 = (long)(r_s5 + (4));
    r_a1 = (long)(r_s4 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    r_s7 = (long)(r_s2 + r_s0);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_s2 = (long)(r_s7 + (1));
    r_a2 = (long)(r_s5 + (4));
    r_t0 = (long)(r_s5 + (5));
    r_a1 = (long)(r_s4 | 0);
    r_a3 = (long)(r_s2 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_t1 = *(unsigned char *)((char *)r_s6 + (5940)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_a2 = (long)(r_s5 + (4));
    r_t0 = (long)(r_s3 + (-2));
    r_a1 = (long)(r_s7 | 0);
    r_a3 = (long)(r_s2 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F72B0C:
    if (r_s1 != 0) goto _lbl_01F728B0;
_lbl_01F72B14:
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (32)); }
    r_v0 = (long)func_001AB9D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F72B1C:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
_lbl_01F72B20:
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0xd0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 44: thelp_func_01F72B4C (VMA: 0x01F72B4C, size: 696 bytes) */
void *thelp_func_01F72B4C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
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
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x300));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_a3 = (long)(r_sp + (0x70));
    r_a2 = (long)(0 + (0x52));
    /* unhandled: ext $s0 $sp 0 1 */
    r_s5 = (long)(r_a0 | 0);
_lbl_01F72B7C:
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (0)); }
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (4)); }
    r_a2 = (long)(r_a2 + (-1));
    if (r_a3) { *(int *)((char *)r_a3 + (0)) = (int)r_a0; }
    if (r_a3) { *(int *)((char *)r_a3 + (4)) = (int)r_v1; }
    r_a1 = (long)(r_a1 + (8));
    if ((long)r_a2 > 0) { r_a3 = (long)(r_a3 + (8)); goto _lbl_01F72B7C; }
    r_a3 = (long)(r_a3 + (8));
    if (r_sp) { r_t2 = *(int *)((char *)r_sp + (756)); }
    if ((long)r_t2 < 0) goto _lbl_01F72DE0;
    if (r_sp) { r_t1 = *(int *)((char *)r_sp + (752)); }
    if ((long)r_t1 < 0) goto _lbl_01F72DE0;
    if (r_sp) { r_t3 = *(int *)((char *)r_sp + (628)); }
    r_v1 = (long)(0 + (1));
    if (r_t3 != r_v1) goto _lbl_01F72BD8;
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (3644)); }
    if (r_s5) { r_s0 = *(int *)((char *)r_s5 + (3668)); }
    if (r_s5) { r_s1 = *(int *)((char *)r_s5 + (3672)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3648)); }
    goto _lbl_01F72BEC;
_lbl_01F72BD8:
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (3656)); }
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (3652)); }
    if (r_s5) { r_s0 = *(int *)((char *)r_s5 + (3668)); }
    if (r_s5) { r_s1 = *(int *)((char *)r_s5 + (3672)); }
_lbl_01F72BEC:
    if (r_s5) { r_a2 = *(int *)((char *)r_s5 + (3540)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (3692)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (3544)); }
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (3696)); }
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)(r_a0 + r_v1);
    r_s3 = (long)(r_t1 + r_a1);
    r_s4 = (long)(r_t2 + r_v1);
    r_a3 = (long)(r_a3 + r_s3);
    if ((long)r_a3 < 0) { r_t0 = (long)(r_t0 + r_s4); goto _lbl_01F72DE0; }
    r_t0 = (long)(r_t0 + r_s4);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (20)); }
    r_v1 = (long)((long)r_s3 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v0 = (long)(0 + (1)); goto _lbl_01F72C30; }
    /* unhandled: ld.b $w1 -0x41($zero) */
    goto _lbl_01F72DE4;
_lbl_01F72C30:
    if (r_t3 != r_v0) { r_v0 = (long)(0 + (4)); goto _lbl_01F72C64; }
    r_v0 = (long)(0 + (4));
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (120)); }
    r_v0 = (long)(0 + (0x9b));
    if (r_v1 == r_v0) { r_v0 = (long)(r_v1 + (-0xea)); goto _lbl_01F72C54; }
    r_v0 = (long)(r_v1 + (-0xea));
    r_at = (long)((unsigned long)r_v0 < (unsigned long)(2) ? 1 : 0);
    if (r_at == 0) goto _lbl_01F72C5C;
_lbl_01F72C54:
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (5796)); }
    goto _lbl_01F72C7C;
_lbl_01F72C5C:
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (5804)); }
    goto _lbl_01F72C7C;
_lbl_01F72C64:
    if (r_t3 != r_v0) goto _lbl_01F72C74;
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (5796)); }
    goto _lbl_01F72C7C;
_lbl_01F72C74:
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (5800)); }
_lbl_01F72C7C:
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (620)); }
    r_v0 = (long)(0 + (5));
    if (r_v1 == r_v0) { r_a1 = (long)(0 | 0); goto _lbl_01F72CD0; }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)(0 + (4));
    if (r_v1 == r_v0) { r_a1 = (long)(0 + (1)); goto _lbl_01F72CC8; }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) { r_a1 = (long)(0 + (1)); goto _lbl_01F72CC0; }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) { r_a1 = (long)(0 + (1)); goto _lbl_01F72CB8; }
    r_a1 = (long)(0 + (1));
    r_a1 = (long)(0 | 0);
    goto _lbl_01F72CD0;
_lbl_01F72CB8:
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (624)); }
    goto _lbl_01F72CD4;
_lbl_01F72CC0:
    goto _lbl_01F72CD0;
_lbl_01F72CC8:
    goto _lbl_01F72CD0;
_lbl_01F72CD0:
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (624)); }
_lbl_01F72CD4:
    r_v0 = (long)(0 + (6));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (5)); goto _lbl_01F72D38; }
    r_v0 = (long)(0 + (5));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (4)); goto _lbl_01F72D2C; }
    r_v0 = (long)(0 + (4));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (3)); goto _lbl_01F72D20; }
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (2)); goto _lbl_01F72D14; }
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F72D08;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F72D44;
_lbl_01F72D08:
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5912)); }
    r_v0 = (long)(0 + (1));
    goto _lbl_01F72D48;
_lbl_01F72D14:
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5916)); }
    r_v0 = (long)(0 + (1));
    goto _lbl_01F72D48;
_lbl_01F72D20:
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5920)); }
    r_v0 = (long)(0 + (2));
    goto _lbl_01F72D48;
_lbl_01F72D2C:
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5924)); }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F72D48;
_lbl_01F72D38:
    if (r_s5) { r_t1 = *(unsigned char *)((char *)r_s5 + (5928)); }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F72D48;
_lbl_01F72D44:
    r_t1 = (long)(0 | 0);
_lbl_01F72D48:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (5808)); }
    if (r_a0 == 0) goto _lbl_01F72DA4;
    r_v0 = (long)((unsigned long)r_v0 << (1));
    r_t0 = (long)(r_a1 + r_v0);
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (32)); }
    r_a2 = (long)(r_s3 | 0);
    r_a3 = (long)(r_s4 | 0);
    r_t1 = (long)(0 | 0);
    r_v0 = (long)func_0025E640((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 == 0) goto _lbl_01F72DE0;
    if (r_sp) { r_t0 = *(int *)((char *)r_sp + (128)); }
    if ((long)r_t0 < 0) goto _lbl_01F72DE0;
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (32)); }
    r_a2 = (long)(r_s3 + r_s0);
    r_a3 = (long)(r_s4 + r_s1);
    r_a0 = (long)(r_s2 | 0);
    r_t1 = (long)(0 | 0);
    r_v0 = (long)func_0025E640((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F72DE0;
_lbl_01F72DA4:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(r_s4 | 0);
    r_v0 = (long)func_001AD650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 == 0) goto _lbl_01F72DE0;
    if (r_sp) { r_t0 = *(int *)((char *)r_sp + (128)); }
    if ((long)r_t0 < 0) goto _lbl_01F72DE0;
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (32)); }
    r_a2 = (long)(r_s3 + r_s0);
    r_a3 = (long)(r_s4 + r_s1);
    r_a0 = (long)(r_s2 | 0);
    r_t1 = (long)(0 | 0);
    r_v0 = (long)func_0025E640((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F72DE0:
    /* unhandled: ld.b $w1 -0x41($zero) */
_lbl_01F72DE4:
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x300));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 45: thelp_func_01F72E04 (VMA: 0x01F72E04, size: 368 bytes) */
void *thelp_func_01F72E04(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x300));
    /* unhandled: subu.qb $zero $sp $ra */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_a3 = (long)(r_sp + (0x60));
    r_a2 = (long)(0 + (0x52));
    /* unhandled: ext $s0 $sp 0 1 */
    r_s4 = (long)(r_a0 | 0);
_lbl_01F72E38:
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (0)); }
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (4)); }
    r_a2 = (long)(r_a2 + (-1));
    if (r_a3) { *(int *)((char *)r_a3 + (0)) = (int)r_a0; }
    if (r_a3) { *(int *)((char *)r_a3 + (4)) = (int)r_v1; }
    r_a1 = (long)(r_a1 + (8));
    if ((long)r_a2 > 0) { r_a3 = (long)(r_a3 + (8)); goto _lbl_01F72E38; }
    r_a3 = (long)(r_a3 + (8));
    if (r_sp) { r_t0 = *(int *)((char *)r_sp + (740)); }
    if ((long)r_t0 < 0) goto _lbl_01F72F54;
    if (r_sp) { r_a3 = *(int *)((char *)r_sp + (736)); }
    if ((long)r_a3 < 0) goto _lbl_01F72F54;
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (612)); }
    r_v1 = (long)(0 + (1));
    if (r_a0 != r_v1) goto _lbl_01F72E8C;
    if (r_s4) { r_s2 = *(int *)((char *)r_s4 + (3672)); }
    if (r_s4) { r_s1 = *(int *)((char *)r_s4 + (3648)); }
    goto _lbl_01F72E98;
_lbl_01F72E8C:
    if (r_s4) { r_s1 = *(int *)((char *)r_s4 + (3656)); }
    if (r_s4) { r_s2 = *(int *)((char *)r_s4 + (3672)); }
_lbl_01F72E98:
    if (r_s4) { r_t1 = *(int *)((char *)r_s4 + (3540)); }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (3692)); }
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (3696)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (3544)); }
    r_v1 = (long)(r_t1 - r_s1);
    r_a2 = (long)(r_a2 + r_t1);
    r_a0 = (long)(r_a1 + r_a0);
    r_s3 = (long)(r_a3 + r_a2);
    r_s0 = (long)(r_t0 + r_a0);
    r_a0 = (long)(r_s1 + r_s3);
    r_v1 = (long)((long)r_a0 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F72F54;
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (20)); }
    r_v1 = (long)((long)r_s3 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F72EE4;
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    goto _lbl_01F72F58;
_lbl_01F72EE4:
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (32)); }
    r_v0 = (long)(0xff << 16);
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (56)); }
    r_a1 = (long)(r_v0 | (0xffff));
    r_v0 = (long)func_00225820((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s3 + (-0x32));
    if (r_sp) { *(int *)((char *)r_sp + (752)) = (int)r_v0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (752)); }
    r_v0 = (long)(r_s0 + (0x1f));
    r_s0 = (long)(r_sp + (0xec));
    r_v0 = (long)(r_v0 + r_s2);
    r_v1 = (long)(r_v1 + r_s1);
    r_v1 = (long)(r_v1 + (0x64));
    r_a1 = (long)(r_sp + (0x2f4));
    if (r_sp) { *(int *)((char *)r_sp + (760)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v0; }
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (0)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)(r_v0 + (0x3c));
    if (r_sp) { *(int *)((char *)r_sp + (764)) = (int)r_v0; }
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (32)); }
    r_a3 = (long)(r_sp + (0x2f0));
    r_t0 = (long)(0 + (1));
    r_a1 = (long)(r_s0 | 0);
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (56)); }
    r_a2 = (long)(r_v0 | 0);
    r_v0 = (long)func_00225BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F72F54:
    /* unhandled: aver_u.h $w1 $w0 $w31 */
_lbl_01F72F58:
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x300));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 46: thelp_func_01F72F74 (VMA: 0x01F72F74, size: 1220 bytes) */
void *thelp_func_01F72F74(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0, r_t9 = 0;
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
    (void)r_t9;
    r_sp = (long)(r_sp + (-0xa0));
    /* unhandled: dps.w.ph $ac0 $sp $ra */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (144)); }
    r_s4 = (long)(r_a0 | 0);
    if (r_v0 == 0) { r_s0 = (long)(0 | 0); goto _lbl_01F72FFC; }
    r_s0 = (long)(0 | 0);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-30272)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (40)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (128)); }
    if (r_v0 == 0) goto _lbl_01F72FFC;
    r_v0 = (long)(0xa8 << 16);
    r_a0 = (long)(r_v0 + (0xbb0));
    r_v0 = (long)func_001F26D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F72FF0;
    r_v0 = (long)(0xa8 << 16);
    r_a0 = (long)(r_v0 + (0xbb0));
    r_v0 = (long)func_001F26D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != r_s4) goto _lbl_01F72FFC;
_lbl_01F72FF0:
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3564)); }
    if (r_v0 == 0) goto _lbl_01F73008;
_lbl_01F72FFC:
    if (r_s4) { *(int *)((char *)r_s4 + (3576)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F73410;
_lbl_01F73008:
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (60)); }
    if (r_a0 == 0) goto _lbl_01F73050;
    r_v0 = (long)func_001F6CD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F73050;
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (60)); }
    r_v0 = (long)func_001F6CD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6a30));
    r_v0 = (long)func_0011AA78((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F73050;
    if (r_s4) { *(int *)((char *)r_s4 + (3576)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F73410;
_lbl_01F73050:
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (5848)); }
    r_v0 = (long)(0 + (2));
    if (r_v1) { r_v1 = *(int *)((char *)r_v1 + (300)); }
    if (r_v1 != r_v0) goto _lbl_01F73070;
    if (r_s4) { *(int *)((char *)r_s4 + (3576)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F73410;
_lbl_01F73070:
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (5840)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (132)); }
    if (r_v0 != 0) goto _lbl_01F73090;
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (5844)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (132)); }
    if (r_v0 == 0) { r_a0 = (long)(r_sp + (0x80)); goto _lbl_01F730A0; }
    r_a0 = (long)(r_sp + (0x80));
_lbl_01F73090:
    if (r_s4) { *(int *)((char *)r_s4 + (3576)) = (int)0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F73410;
    r_a0 = (long)(r_sp + (0x80));
_lbl_01F730A0:
    r_a2 = (long)(0 + (0x19));
    r_a3 = (long)(0 + (0x280));
    r_t0 = (long)(0 + (0x1ae));
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_002254F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_sp + (0x98));
    r_v0 = (long)func_00225560((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-30272)); }
    r_a0 = (long)(0 + (1));
    r_s1 = (long)(0 | 0);
    if (r_v0) { r_s3 = *(int *)((char *)r_v0 + (40)); }
    r_s2 = (long)(0 | 0);
    r_v0 = (long)func_00225520((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) goto _lbl_01F73374;
    r_a0 = (long)(0 + (2));
    r_v0 = (long)func_00225520((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) goto _lbl_01F73374;
    if (r_sp) { r_s5 = *(int *)((char *)r_sp + (152)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (136)); }
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)((long)r_s5 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F7312C;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F7316C;
_lbl_01F7312C:
    if (r_sp) { r_s5 = *(int *)((char *)r_sp + (152)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_s6 + r_v0);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (136)); }
    r_v0 = (long)(r_v1 - r_v0);
    r_v0 = (long)(r_v0 + (-0xc));
    r_at = (long)((long)r_v0 < (long)r_s5 ? 1 : 0);
    if (r_at == 0) { r_s6 = (long)(r_sp + (0x9c)); goto _lbl_01F73170; }
    r_s6 = (long)(r_sp + (0x9c));
    r_v0 = (long)(0 + (1));
_lbl_01F7316C:
    r_s6 = (long)(r_sp + (0x9c));
_lbl_01F73170:
    if (r_s6) { r_s5 = *(int *)((char *)r_s6 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (136)); }
    r_v0 = (long)(r_v1 + r_v0);
    r_at = (long)((long)r_s5 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F731A0;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F731E0;
_lbl_01F731A0:
    if (r_s6) { r_s5 = *(int *)((char *)r_s6 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_s6 + r_v0);
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (136)); }
    r_v0 = (long)(r_v1 - r_v0);
    r_v0 = (long)(r_v0 + (-0x11));
    r_at = (long)((long)r_v0 < (long)r_s5 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F731E0;
    r_v0 = (long)(0 + (1));
_lbl_01F731E0:
    if (r_s1 != 0) goto _lbl_01F731F0;
    if (r_s2 == 0) goto _lbl_01F73374;
_lbl_01F731F0:
    r_v0 = (long)func_002261C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 | 0);
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3572)); }
    if (r_s4) { r_s6 = *(int *)((char *)r_s4 + (3576)); }
    if (r_s6 == 0) { r_a2 = (long)(r_s3 - r_v0); goto _lbl_01F73218; }
    r_a2 = (long)(r_s3 - r_v0);
    r_v0 = (long)((unsigned long)r_a2 < (unsigned long)(0x1b) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F73374;
_lbl_01F73218:
    if ((long)r_a2 < 0) { r_v1 = (long)((unsigned long)r_a2 >> (1)); goto _lbl_01F73230; }
    r_v1 = (long)((unsigned long)r_a2 >> (1));
    /* unhandled: mtc1 $a2 $f0 */
    /* unhandled: cvt.s.w $f1 $f0 */
    goto _lbl_01F73248;
    r_v1 = (long)((unsigned long)r_a2 >> (1));
_lbl_01F73230:
    r_v0 = (long)(r_a2 & (1));
    r_v1 = (long)(r_v1 | r_v0);
    /* unhandled: mtc1 $v1 $f0 */
    /* unhandled: cvt.s.w $f1 $f0 */
    /* unhandled: add.s $f1 $f1 $f1 */
_lbl_01F73248:
    r_v0 = (long)(0x41d8 << 16);
    /* unhandled: mtc1 $v0 $f0 */
    /* unhandled: div.s $f1 $f1 $f0 */
    r_v0 = (long)(0x4200 << 16);
    /* unhandled: mtc1 $v0 $f0 */
    /* unhandled: mul.s $f12 $f0 $f1 */
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_at = (long)((long)r_s5 < (long)(0x81) ? 1 : 0);
    if (r_at != 0) { r_s0 = (long)(0 + (1)); goto _lbl_01F73280; }
    r_s0 = (long)(0 + (1));
    r_s5 = (long)(0 + (0x80));
    r_s0 = (long)(0 + (1));
_lbl_01F73280:
    if (r_s6 != 0) goto _lbl_01F7328C;
    if (r_s4) { *(int *)((char *)r_s4 + (3576)) = (int)r_s0; }
_lbl_01F7328C:
    if (r_s4) { *(int *)((char *)r_s4 + (3584)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3580)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3588)) = (int)0; }
    r_v0 = (long)(0 + (-1));
    if (r_v1 != r_v0) { if (r_s4) { *(int *)((char *)r_s4 + (3592)) = (int)0; } goto _lbl_01F732D4; }
    if (r_s4) { *(int *)((char *)r_s4 + (3592)) = (int)0; }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_01F6FCF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { *(int *)((char *)r_s4 + (3584)) = (int)r_v0; }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3584)); }
    if (r_v0 == 0) goto _lbl_01F73308;
    r_v0 = (long)(0 + (1));
    if (r_s4) { *(int *)((char *)r_s4 + (3588)) = (int)r_v0; }
    goto _lbl_01F73304;
_lbl_01F732D4:
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F73304;
    /* unhandled: negu $a1 $s5 */
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F6FCF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { *(int *)((char *)r_s4 + (3584)) = (int)r_v0; }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3584)); }
    if (r_v0 == 0) goto _lbl_01F73304;
    r_v0 = (long)(0 + (2));
    if (r_s4) { *(int *)((char *)r_s4 + (3588)) = (int)r_v0; }
_lbl_01F73304:
_lbl_01F73308:
    r_v0 = (long)(0 + (-1));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F73344; }
    r_v0 = (long)(0 + (1));
    r_a1 = (long)(r_s5 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F6FD40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { *(int *)((char *)r_s4 + (3580)) = (int)r_v0; }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3580)); }
    if (r_v0 == 0) goto _lbl_01F73370;
    r_v0 = (long)(0 + (3));
    if (r_s4) { *(int *)((char *)r_s4 + (3592)) = (int)r_v0; }
    goto _lbl_01F73370;
    r_v0 = (long)(0 + (1));
_lbl_01F73344:
    if (r_v1 != r_v0) goto _lbl_01F73370;
    /* unhandled: negu $a1 $s5 */
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F6FD40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { *(int *)((char *)r_s4 + (3580)) = (int)r_v0; }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3580)); }
    if (r_v0 == 0) goto _lbl_01F73370;
    r_v0 = (long)(0 + (4));
    if (r_s4) { *(int *)((char *)r_s4 + (3592)) = (int)r_v0; }
_lbl_01F73370:
    if (r_s4) { *(int *)((char *)r_s4 + (3572)) = (int)r_s3; }
_lbl_01F73374:
    if (r_s1 != 0) goto _lbl_01F73388;
    if (r_s2 != 0) goto _lbl_01F73388;
    if (r_s4) { *(int *)((char *)r_s4 + (3576)) = (int)0; }
_lbl_01F73388:
    if (r_s0 == 0) goto _lbl_01F73408;
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3580)); }
    if ((long)r_v0 > 0) goto _lbl_01F733A8;
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3584)); }
    if ((long)r_v0 <= 0) goto _lbl_01F73408;
_lbl_01F733A8:
    if (r_s4) { *(int *)((char *)r_s4 + (3604)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3636)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3640)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3620)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3624)) = (int)0; }
    if (r_s4) { *(int *)((char *)r_s4 + (3628)) = (int)0; }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3612)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F733F0;
    if (r_s4) { *(int *)((char *)r_s4 + (3556)) = (int)0; }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5840)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_a1 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s4) { *(int *)((char *)r_s4 + (3612)) = (int)0; }
    goto _lbl_01F733F4;
_lbl_01F733F0:
    if (r_s4) { *(int *)((char *)r_s4 + (3556)) = (int)r_v0; }
_lbl_01F733F4:
    if (r_s4) { r_t9 = *(int *)((char *)r_s4 + (0)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a0 = (long)(r_s4 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F73408:
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3576)); }
_lbl_01F73410:
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0xa0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 47: thelp_func_01F73438 (VMA: 0x01F73438, size: 712 bytes) */
void *thelp_func_01F73438(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0, r_t8 = 0, r_t9 = 0;
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
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    (void)r_t7;
    (void)r_t8;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x90));
    /* unhandled: ext $ra $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s2 = (long)(r_a0 | 0);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (5848)); }
    r_s1 = (long)(r_a1 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (216)); }
    r_s0 = (long)(r_a2 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 != 0) { r_v0 = (long)(0 | 0); goto _lbl_01F734B0; }
    r_v0 = (long)(0 | 0);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (5828)); }
    r_a1 = (long)(r_s1 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (216)); }
    r_a2 = (long)(r_s0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 == 0) goto _lbl_01F734B8;
    r_v0 = (long)(0 | 0);
_lbl_01F734B0:
    /* unhandled: xori.b $w2 $w0 0xbf */
    goto _lbl_01F736D8;
_lbl_01F734B8:
    if (r_s2) { r_t1 = *(int *)((char *)r_s2 + (3648)); }
    if (r_s2) { r_t2 = *(int *)((char *)r_s2 + (3644)); }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (2072)); }
    r_a1 = (long)(0 + (1));
    r_a2 = (long)(0 | 0);
    goto _lbl_01F73590;
    r_v1 = (long)((unsigned long)r_a2 << (5));
_lbl_01F734D4:
    r_a0 = (long)(r_v1 - r_a2);
    r_v1 = (long)((unsigned long)r_a0 << (2));
    r_v1 = (long)(r_v1 - r_a0);
    r_a0 = (long)((unsigned long)r_v1 << (3));
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2076)); }
    r_t6 = (long)(r_v1 + r_a0);
    if (r_t6) { r_v1 = *(int *)((char *)r_t6 + (672)); }
    if (r_v1 != r_a1) { r_a2 = (long)(r_a2 + (1)); goto _lbl_01F73590; }
    if (r_s2) { r_t5 = *(int *)((char *)r_s2 + (3540)); }
    if (r_t6) { r_t4 = *(int *)((char *)r_t6 + (656)); }
    if (r_s2) { r_t7 = *(int *)((char *)r_s2 + (3692)); }
    if (r_s2) { r_s4 = *(int *)((char *)r_s2 + (3544)); }
    if (r_t6) { r_s3 = *(int *)((char *)r_t6 + (660)); }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3696)); }
    r_a3 = (long)(0 | 0);
    r_a0 = (long)(r_t5 + r_t4);
    r_t3 = (long)(r_t7 + r_a0);
    r_a0 = (long)(r_t1 + r_t4);
    r_a0 = (long)(r_t5 + r_a0);
    r_t4 = (long)(r_t7 + r_a0);
    r_a0 = (long)(r_s4 + r_s3);
    r_t5 = (long)(r_v1 + r_a0);
    r_a0 = (long)(r_t2 + r_s3);
    r_a0 = (long)(r_s4 + r_a0);
    r_v1 = (long)(r_v1 + r_a0);
    r_at = (long)((long)r_s1 < (long)r_t3 ? 1 : 0);
    if (r_at != 0) { r_t0 = (long)(0 | 0); goto _lbl_01F73558; }
    r_t0 = (long)(0 | 0);
    r_at = (long)((long)r_t4 < (long)r_s1 ? 1 : 0);
    if (r_at != 0) { r_at = (long)((long)r_s0 < (long)r_t5 ? 1 : 0); goto _lbl_01F7355C; }
    r_at = (long)((long)r_s0 < (long)r_t5 ? 1 : 0);
    r_a3 = (long)(r_a1 | 0);
_lbl_01F73558:
    r_at = (long)((long)r_s0 < (long)r_t5 ? 1 : 0);
_lbl_01F7355C:
    if (r_at != 0) goto _lbl_01F73574;
    r_at = (long)((long)r_v1 < (long)r_s0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F73574;
    r_t0 = (long)(0 + (1));
_lbl_01F73574:
    if (r_a3 != r_a1) goto _lbl_01F7358C;
    if (r_t0 != r_a1) goto _lbl_01F7358C;
    r_v0 = (long)(r_t6 + (0x10));
    goto _lbl_01F736D4;
_lbl_01F7358C:
    r_a2 = (long)(r_a2 + (1));
_lbl_01F73590:
    r_v1 = (long)((long)r_a2 < (long)r_v0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a2 << (5)); goto _lbl_01F734D4; }
    r_v1 = (long)((unsigned long)r_a2 << (5));
    if (r_s2) { r_ra = *(int *)((char *)r_s2 + (3656)); }
    if (r_s2) { r_s3 = *(int *)((char *)r_s2 + (3652)); }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (2080)); }
    r_a0 = (long)(0 + (0x405c));
    r_v1 = (long)(0 + (0xcd0));
    r_v0 = (long)(0 + (1));
    r_s4 = (long)(0 | 0);
    goto _lbl_01F736C4;
_lbl_01F735C0:
    r_a1 = (long)(0 | 0);
    goto _lbl_01F736B4;
_lbl_01F735CC:
    r_a2 = (long)(0 | 0);
    goto _lbl_01F736A4;
    r_t0 = (long)((unsigned long)r_a2 << (2));
_lbl_01F735D8:
    r_t0 = (long)(r_t0 + r_a2);
    if (r_s2) { r_t8 = *(int *)((char *)r_s2 + (2084)); }
    r_t0 = (long)((unsigned long)r_t0 << (3));
    r_t0 = (long)(r_t0 + r_a2);
    r_t9 = (long)((unsigned long)r_t0 << (4));
    r_s5 = (long)(0 | 0);
    r_t0 = (long)(r_t8 + r_t7);
    r_t0 = (long)(r_t0 + r_t6);
    r_t2 = (long)(r_t0 + r_t9);
    if (r_t2) { r_t0 = *(int *)((char *)r_t2 + (552)); }
    if (r_t0 == 0) { r_s6 = (long)(0 | 0); goto _lbl_01F736A0; }
    r_s6 = (long)(0 | 0);
    if (r_s2) { r_t1 = *(int *)((char *)r_s2 + (3540)); }
    if (r_t2) { r_t0 = *(int *)((char *)r_t2 + (676)); }
    if (r_t2) { r_t3 = *(int *)((char *)r_t2 + (680)); }
    if (r_s2) { r_t4 = *(int *)((char *)r_s2 + (3544)); }
    if (r_s2) { r_t5 = *(int *)((char *)r_s2 + (3696)); }
    r_s7 = (long)(r_t1 + r_t0);
    if (r_s2) { r_t2 = *(int *)((char *)r_s2 + (3692)); }
    r_t0 = (long)(r_ra + r_t0);
    r_t0 = (long)(r_t1 + r_t0);
    r_s7 = (long)(r_t2 + r_s7);
    r_t1 = (long)(r_t2 + r_t0);
    r_t2 = (long)(r_s3 + r_t3);
    r_t0 = (long)(r_t4 + r_t3);
    r_t2 = (long)(r_t4 + r_t2);
    r_t0 = (long)(r_t5 + r_t0);
    r_at = (long)((long)r_s1 < (long)r_s7 ? 1 : 0);
    if (r_at != 0) { r_t2 = (long)(r_t5 + r_t2); goto _lbl_01F73660; }
    r_t2 = (long)(r_t5 + r_t2);
    r_at = (long)((long)r_t1 < (long)r_s1 ? 1 : 0);
    if (r_at != 0) { r_at = (long)((long)r_s0 < (long)r_t0 ? 1 : 0); goto _lbl_01F73664; }
    r_at = (long)((long)r_s0 < (long)r_t0 ? 1 : 0);
    r_s5 = (long)(0 + (1));
_lbl_01F73660:
    r_at = (long)((long)r_s0 < (long)r_t0 ? 1 : 0);
_lbl_01F73664:
    if (r_at != 0) goto _lbl_01F7367C;
    r_at = (long)((long)r_t2 < (long)r_s0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F7367C;
    r_s6 = (long)(0 + (1));
_lbl_01F7367C:
    if (r_s5 != r_v0) { r_a2 = (long)(r_a2 + (1)); goto _lbl_01F736A4; }
    if (r_s6 != r_v0) goto _lbl_01F736A0;
    r_v0 = (long)(r_t8 + r_t7);
    r_v0 = (long)(r_v0 + r_t6);
    r_v0 = (long)(r_v0 + r_t9);
    r_v0 = (long)(r_v0 + (0x24));
    goto _lbl_01F736D4;
_lbl_01F736A0:
    r_a2 = (long)(r_a2 + (1));
_lbl_01F736A4:
    r_t0 = (long)((long)r_a2 < (long)(5) ? 1 : 0);
    if (r_t0 != 0) { r_t0 = (long)((unsigned long)r_a2 << (2)); goto _lbl_01F735D8; }
    r_t0 = (long)((unsigned long)r_a2 << (2));
    r_a1 = (long)(r_a1 + (1));
_lbl_01F736B4:
    r_a2 = (long)((long)r_a1 < (long)(5) ? 1 : 0);
    if (r_a2 != 0) goto _lbl_01F735CC;
    r_s4 = (long)(r_s4 + (1));
_lbl_01F736C4:
    r_a1 = (long)((long)r_s4 < (long)r_a3 ? 1 : 0);
    if (r_a1 != 0) goto _lbl_01F735C0;
    r_v0 = (long)(0 | 0);
_lbl_01F736D4:
    /* unhandled: xori.b $w2 $w0 0xbf */
_lbl_01F736D8:
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 48: thelp_func_01F73700 (VMA: 0x01F73700, size: 812 bytes) */
void *thelp_func_01F73700(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x20f0));
    /* unhandled: subu.qb $zero $sp $ra */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (5840)); }
    if (r_v0 != 0) { r_s2 = (long)(r_a0 | 0); goto _lbl_01F73730; }
    r_s2 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F73A0C;
_lbl_01F73730:
    r_v0 = (long)func_01F734C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    if (r_s0 == 0) goto _lbl_01F73A04;
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (516)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F7375C;
    if (r_s2) { r_s1 = *(int *)((char *)r_s2 + (3644)); }
    goto _lbl_01F73764;
_lbl_01F7375C:
    if (r_s2) { r_s1 = *(int *)((char *)r_s2 + (3652)); }
_lbl_01F73764:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3608)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) goto _lbl_01F73788;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3604)); }
    if (r_s0 != r_v1) goto _lbl_01F73788;
    goto _lbl_01F73A0C;
_lbl_01F73788:
    if (r_sp) { *(char *)((char *)r_sp + (96)) = (char)0; }
    if (r_sp) { *(char *)((char *)r_sp + (2144)) = (char)0; }
    if (r_sp) { *(char *)((char *)r_sp + (6240)) = (char)0; }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (516)); }
    r_v0 = (long)(0 + (4));
    if (r_v1 != r_v0) goto _lbl_01F737C4;
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (624)); }
    r_a2 = (long)(r_sp + (0x60));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(r_v0 + (0x5208));
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F737DC;
_lbl_01F737C4:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (624)); }
    r_a2 = (long)(r_sp + (0x60));
    r_a3 = (long)(0 + (0x800));
    r_a0 = (long)(r_s2 | 0);
    r_a1 = (long)(r_v0 + (0x5208));
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F737DC:
    r_v0 = (long)(0x1f8 << 16);
    r_a0 = (long)(r_sp + (0x60));
    r_a1 = (long)(r_v0 + (-0x69c8));
    r_v0 = (long)func_0011B330((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 | 0);
    if (r_s3 == 0) goto _lbl_01F73844;
    r_a1 = (long)(r_sp + (0x60));
    r_s4 = (long)(r_s3 - r_a1);
    r_a0 = (long)(r_sp + (0x860));
    r_a2 = (long)(r_s4 | 0);
    r_v0 = (long)func_0011B170((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s4 + r_sp);
    if (r_v0) { *(char *)((char *)r_v0 + (2144)) = (char)0; }
    r_v0 = (long)(0 + (0x800));
    r_a0 = (long)(r_sp + (0x1860));
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(r_v0 - r_s4);
    r_v0 = (long)func_0011B170((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0x1f8 << 16);
    r_a0 = (long)(r_sp + (0x60));
    r_a1 = (long)(r_v0 + (-0x69c0));
    r_a2 = (long)(r_sp + (0x860));
    r_a3 = (long)(r_sp + (0x1860));
    if (r_sp) { *(char *)((char *)r_sp + (96)) = (char)0; }
    r_v0 = (long)func_0011A498((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F73844:
    if (r_sp) { *(char *)((char *)r_sp + (8288)) = (char)0; }
    if (r_sp) { *(char *)((char *)r_sp + (4192)) = (char)0; }
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (524)); }
    if ((long)r_v0 <= 0) goto _lbl_01F7386C;
    r_a1 = (long)(0 + (0x697b));
    r_a2 = (long)(r_sp + (0x2060));
    r_a3 = (long)(0 + (0x80));
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_001F6E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F7386C:
    r_v0 = (long)(0x1f8 << 16);
    r_a0 = (long)(r_sp + (0x1060));
    r_a1 = (long)(r_v0 + (-0x6ab0));
    r_a2 = (long)(r_sp + (0x60));
    r_a3 = (long)(r_sp + (0x2060));
    r_v0 = (long)func_0011A498((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a2 = *(int *)((char *)r_s0 + (8)); }
    r_v0 = (long)(0 + (0x26d));
    if (r_a2 != r_v0) goto _lbl_01F738B8;
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (516)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (5840)); }
    r_a1 = (long)(r_sp + (0x1060));
    r_a2 = (long)(0 + (0x6d));
    r_v0 = (long)(r_v0 ^ (4));
    r_a3 = (long)((unsigned long)r_v0 < (unsigned long)(1) ? 1 : 0);
    r_v0 = (long)func_01F74CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (8424)) = (int)0; }
    goto _lbl_01F738D4;
_lbl_01F738B8:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (516)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (5840)); }
    r_a1 = (long)(r_sp + (0x1060));
    r_v0 = (long)(r_v0 ^ (4));
    r_a3 = (long)((unsigned long)r_v0 < (unsigned long)(1) ? 1 : 0);
    r_v0 = (long)func_01F74CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (8424)) = (int)0; }
_lbl_01F738D4:
    if (r_sp) { *(int *)((char *)r_sp + (8428)) = (int)0; }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (5840)); }
    r_a1 = (long)(r_s0 + (0x20c));
    r_a2 = (long)(r_sp + (0x20e8));
    r_a3 = (long)(r_sp + (0x20ec));
    r_v0 = (long)func_01F74CF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (3536)); }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (8428)); }
    r_v0 = (long)(r_v0 + (-0x30));
    r_at = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F73908;
    if (r_sp) { *(int *)((char *)r_sp + (8428)) = (int)r_v0; }
_lbl_01F73908:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (8428)); }
    r_at = (long)((long)r_v0 < (long)(0x32) ? 1 : 0);
    if (r_at == 0) goto _lbl_01F73920;
    r_v0 = (long)(0 + (0x32));
    if (r_sp) { *(int *)((char *)r_sp + (8428)) = (int)r_v0; }
_lbl_01F73920:
    if (r_s2) { r_t1 = *(int *)((char *)r_s2 + (3540)); }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3692)); }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (3544)); }
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (3696)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (644)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (640)); }
    if (r_sp) { r_a3 = *(int *)((char *)r_sp + (8424)); }
    r_t0 = (long)(r_t1 + r_v1);
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3532)); }
    r_a2 = (long)(r_v0 + r_a2);
    r_a0 = (long)(r_a0 + r_a2);
    r_a0 = (long)(r_s1 + r_a0);
    r_a1 = (long)(r_a1 + r_t0);
    r_a1 = (long)(r_a1 - r_a3);
    r_a2 = (long)(r_a0 + (2));
    r_v1 = (long)(r_t1 + r_v1);
    r_a1 = (long)(r_a1 + (-2));
    r_a0 = (long)(r_v1 + (-0x18));
    r_v1 = (long)(r_a1 + r_a3);
    r_at = (long)((long)r_a0 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) { r_v1 = (long)(r_t1 + (0x18)); goto _lbl_01F73980; }
    r_v1 = (long)(r_t1 + (0x18));
    r_a1 = (long)(r_a0 - r_a3);
    r_v1 = (long)(r_t1 + (0x18));
_lbl_01F73980:
    r_at = (long)((long)r_a1 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F73990;
    r_a1 = (long)(r_v1 | 0);
_lbl_01F73990:
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (3536)); }
    if (r_sp) { r_t0 = *(int *)((char *)r_sp + (8428)); }
    r_v1 = (long)(r_v0 + r_v1);
    r_a0 = (long)(r_a2 + r_t0);
    r_v1 = (long)(r_v1 + (-0x18));
    r_at = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
    if (r_at == 0) { r_v0 = (long)(r_v0 + (0x18)); goto _lbl_01F739B8; }
    r_a2 = (long)(r_v1 - r_t0);
    r_v0 = (long)(r_v0 + (0x18));
_lbl_01F739B8:
    r_at = (long)((long)r_a2 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F739C8;
    r_a2 = (long)(r_v0 | 0);
_lbl_01F739C8:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (524)); }
    if ((long)r_v0 <= 0) goto _lbl_01F739E8;
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (5840)); }
    r_t1 = (long)(r_s0 + (0x20c));
    r_v0 = (long)func_01F74A10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F739F8;
_lbl_01F739E8:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (5840)); }
    r_t1 = (long)(0 | 0);
    r_v0 = (long)func_01F74A10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01F739F8:
    if (r_s2) { *(int *)((char *)r_s2 + (3604)) = (int)r_s0; }
    if (r_s2) { *(int *)((char *)r_s2 + (3608)) = (int)r_v0; }
    goto _lbl_01F73A0C;
_lbl_01F73A04:
    if (r_s2) { *(int *)((char *)r_s2 + (3608)) = (int)0; }
    r_v0 = (long)(0 | 0);
_lbl_01F73A0C:
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20f0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 49: thelp_func_01F73A2C (VMA: 0x01F73A2C, size: 480 bytes) */
void *thelp_func_01F73A2C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0;
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
    r_t1 = (long)(0 + (3));
    if (r_a2 == r_t1) { r_v0 = (long)(0 | 0); goto _lbl_01F73B64; }
    r_v0 = (long)(0 | 0);
    r_t2 = (long)(0 + (4));
    if (r_a2 == r_t2) goto _lbl_01F73ABC;
    r_a3 = (long)(0 + (1));
    if (r_a2 == r_a3) goto _lbl_01F73A5C;
    goto _lbl_01F73C04;
_lbl_01F73A5C:
    if (r_a0) { r_t1 = *(int *)((char *)r_a0 + (2072)); }
    r_t0 = (long)(0 | 0);
    goto _lbl_01F73AA8;
    r_v1 = (long)((unsigned long)r_t0 << (5));
_lbl_01F73A6C:
    r_a2 = (long)(r_v1 - r_t0);
    r_v1 = (long)((unsigned long)r_a2 << (2));
    r_v1 = (long)(r_v1 - r_a2);
    r_a2 = (long)((unsigned long)r_v1 << (3));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2076)); }
    r_a2 = (long)(r_v1 + r_a2);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (672)); }
    if (r_v1 != r_a3) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F73AA8; }
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (28)); }
    if (r_a1 != r_v1) goto _lbl_01F73AA4;
    r_v0 = (long)(r_a2 + (0x10));
    goto _lbl_01F73C04;
_lbl_01F73AA4:
    r_t0 = (long)(r_t0 + (1));
_lbl_01F73AA8:
    r_v1 = (long)((long)r_t0 < (long)r_t1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (5)); goto _lbl_01F73A6C; }
    r_v1 = (long)((unsigned long)r_t0 << (5));
    goto _lbl_01F73C04;
_lbl_01F73ABC:
    if (r_a0) { r_t6 = *(int *)((char *)r_a0 + (2080)); }
    r_t1 = (long)(0 + (0x405c));
    r_t0 = (long)(0 + (0xcd0));
    r_v1 = (long)(0 | 0);
    goto _lbl_01F73B50;
_lbl_01F73AD4:
    r_t3 = (long)(0 | 0);
    goto _lbl_01F73B40;
_lbl_01F73AE0:
    r_t4 = (long)(0 | 0);
    goto _lbl_01F73B30;
_lbl_01F73AE8:
    if (r_a0) { r_a3 = *(int *)((char *)r_a0 + (2084)); }
    r_a2 = (long)((unsigned long)r_t4 << (2));
    r_a2 = (long)(r_a2 + r_t4);
    r_a2 = (long)((unsigned long)r_a2 << (3));
    r_a2 = (long)(r_a2 + r_t4);
    r_a3 = (long)(r_a3 + r_t5);
    r_a3 = (long)(r_a3 + r_t7);
    r_a2 = (long)((unsigned long)r_a2 << (4));
    r_a3 = (long)(r_a3 + r_a2);
    if (r_a3) { r_a2 = *(int *)((char *)r_a3 + (552)); }
    if (r_a2 != r_t2) { r_t4 = (long)(r_t4 + (1)); goto _lbl_01F73B30; }
    if (r_a3) { r_a2 = *(int *)((char *)r_a3 + (44)); }
    if (r_a1 != r_a2) goto _lbl_01F73B2C;
    r_v0 = (long)(r_a3 + (0x24));
    goto _lbl_01F73B3C;
_lbl_01F73B2C:
    r_t4 = (long)(r_t4 + (1));
_lbl_01F73B30:
    r_a2 = (long)((long)r_t4 < (long)(5) ? 1 : 0);
    if (r_a2 != 0) goto _lbl_01F73AE8;
_lbl_01F73B3C:
    r_t3 = (long)(r_t3 + (1));
_lbl_01F73B40:
    r_a2 = (long)((long)r_t3 < (long)(5) ? 1 : 0);
    if (r_a2 != 0) goto _lbl_01F73AE0;
    r_v1 = (long)(r_v1 + (1));
_lbl_01F73B50:
    r_a2 = (long)((long)r_v1 < (long)r_t6 ? 1 : 0);
    if (r_a2 != 0) goto _lbl_01F73AD4;
    goto _lbl_01F73C04;
_lbl_01F73B64:
    if (r_a0) { r_t3 = *(int *)((char *)r_a0 + (2080)); }
    r_t0 = (long)(0 + (0x405c));
    r_a3 = (long)(0 + (0xcd0));
    r_t5 = (long)(0 | 0);
    goto _lbl_01F73BF8;
_lbl_01F73B7C:
    r_t6 = (long)(0 | 0);
    goto _lbl_01F73BE8;
_lbl_01F73B88:
    r_t7 = (long)(0 | 0);
    goto _lbl_01F73BD8;
_lbl_01F73B90:
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (2084)); }
    r_v1 = (long)((unsigned long)r_t7 << (2));
    r_v1 = (long)(r_v1 + r_t7);
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_v1 = (long)(r_v1 + r_t7);
    r_a2 = (long)(r_a2 + r_t2);
    r_a2 = (long)(r_a2 + r_t4);
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_a2 = (long)(r_a2 + r_v1);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (552)); }
    if (r_v1 != r_t1) { r_t7 = (long)(r_t7 + (1)); goto _lbl_01F73BD8; }
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (44)); }
    if (r_a1 != r_v1) goto _lbl_01F73BD4;
    r_v0 = (long)(r_a2 + (0x24));
    goto _lbl_01F73BE4;
_lbl_01F73BD4:
    r_t7 = (long)(r_t7 + (1));
_lbl_01F73BD8:
    r_v1 = (long)((long)r_t7 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F73B90;
_lbl_01F73BE4:
    r_t6 = (long)(r_t6 + (1));
_lbl_01F73BE8:
    r_v1 = (long)((long)r_t6 < (long)(5) ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F73B88;
    r_t5 = (long)(r_t5 + (1));
_lbl_01F73BF8:
    r_v1 = (long)((long)r_t5 < (long)r_t3 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F73B7C;
_lbl_01F73C04:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 50: thelp_func_01F73C0C (VMA: 0x01F73C0C, size: 1352 bytes) */
void *thelp_func_01F73C0C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t9 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x80));
    /* unhandled: dps.w.ph $ac0 $sp $ra */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    r_s4 = (long)(r_a0 | 0);
    r_a0 = (long)(0 + (-1));
    /* unhandled: addu.qb $zero $sp $s1 */
    r_a2 = (long)(0 + (1));
    /* unhandled: ext $s0 $sp 0 1 */
    r_v0 = (long)(r_a0 | 0);
    if (r_a1 != r_a2) { r_v1 = (long)(0 | 0); goto _lbl_01F73C6C; }
    r_v1 = (long)(0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_01F6FD90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_01F6FDE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5864)); }
    goto _lbl_01F74090;
_lbl_01F73C6C:
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (2100)); }
    if (r_a1 == 0) { r_a3 = (long)(0 + (1)); goto _lbl_01F73F20; }
    r_a3 = (long)(0 + (1));
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (3240)); }
    if (r_a1 == 0) goto _lbl_01F73F1C;
    if (r_a1) { r_a2 = *(int *)((char *)r_a1 + (4)); }
    if (r_a2) { r_s6 = *(short *)((char *)r_a2 + (8)); }
    r_a1 = (long)(0 + (2));
    if (r_a2) { r_a2 = *(unsigned char *)((char *)r_a2 + (119)); }
    if (r_a2 == r_a1) goto _lbl_01F73CA8;
    r_a1 = (long)(0 + (0xa));
    if (r_a2 != r_a1) { r_s3 = (long)(0 | 0); goto _lbl_01F73DBC; }
    r_s3 = (long)(0 | 0);
_lbl_01F73CA8:
    if (r_s4) { r_t1 = *(int *)((char *)r_s4 + (2072)); }
    r_a2 = (long)(0 + (1));
    r_t0 = (long)(0 | 0);
    goto _lbl_01F73DA4;
_lbl_01F73CB8:
    if (r_s4) { r_t2 = *(int *)((char *)r_s4 + (2076)); }
    r_a1 = (long)((unsigned long)r_t0 << (5));
    r_a3 = (long)(r_a1 - r_t0);
    r_a1 = (long)((unsigned long)r_a3 << (2));
    r_a1 = (long)(r_a1 - r_a3);
    r_s0 = (long)((unsigned long)r_a1 << (3));
    r_a3 = (long)(r_t2 + r_s0);
    if (r_a3) { r_a1 = *(int *)((char *)r_a3 + (28)); }
    if (r_s6 != r_a1) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F73DA4; }
    if (r_a3) { r_a1 = *(int *)((char *)r_a3 + (672)); }
    if (r_a1 != r_a2) goto _lbl_01F73DA0;
    if (r_a3) { r_a1 = *(int *)((char *)r_a3 + (656)); }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (3540)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3648)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3532)); }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)((long)r_v1 >> (1));
    r_v1 = (long)(r_v1 + r_a1);
    r_v0 = (long)((long)r_v0 >> (1));
    r_v0 = (long)(r_v1 - r_v0);
    /* unhandled: negu $a1 $v0 */
    r_v0 = (long)func_01F6FD90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (2076)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3644)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3536)); }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (3544)); }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s0 + r_a1);
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (660)); }
    r_v1 = (long)((long)r_v1 >> (1));
    r_v0 = (long)((long)r_v0 >> (1));
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)(r_v1 + r_a1);
    r_v0 = (long)(r_v1 - r_v0);
    /* unhandled: negu $a1 $v0 */
    r_v0 = (long)func_01F6FDE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (2076)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3648)); }
    if (r_s4) { r_t2 = *(int *)((char *)r_s4 + (3540)); }
    if (r_s4) { r_a3 = *(int *)((char *)r_s4 + (3544)); }
    if (r_s4) { r_t0 = *(int *)((char *)r_s4 + (3692)); }
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (3696)); }
    r_a2 = (long)(r_s0 + r_v0);
    if (r_a2) { r_t1 = *(int *)((char *)r_a2 + (656)); }
    r_a0 = (long)((long)r_v1 >> (1));
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3644)); }
    r_v1 = (long)(0 + (1));
    if (r_a2) { r_a2 = *(int *)((char *)r_a2 + (660)); }
    r_t1 = (long)(r_t2 + r_t1);
    r_t0 = (long)(r_t0 + r_t1);
    r_a0 = (long)(r_a0 + r_t0);
    r_a2 = (long)(r_a3 + r_a2);
    r_a1 = (long)(r_a1 + r_a2);
    r_v0 = (long)(r_v0 + r_a1);
    goto _lbl_01F73F1C;
_lbl_01F73DA0:
    r_t0 = (long)(r_t0 + (1));
_lbl_01F73DA4:
    r_a1 = (long)((long)r_t0 < (long)r_t1 ? 1 : 0);
    if (r_a1 != 0) goto _lbl_01F73CB8;
    goto _lbl_01F73F1C;
    r_s3 = (long)(0 | 0);
_lbl_01F73DBC:
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (2080)); }
    goto _lbl_01F73F10;
    r_a1 = (long)(0 + (0x405c));
_lbl_01F73DC8:
    r_s5 = (long)(0 | 0);
    goto _lbl_01F73EFC;
    r_a1 = (long)(0 + (0xcd0));
_lbl_01F73DD8:
    r_a2 = (long)(0 + (3));
    r_t0 = (long)(0 | 0);
    goto _lbl_01F73EEC;
_lbl_01F73DE8:
    if (r_s4) { r_a3 = *(int *)((char *)r_s4 + (2084)); }
    r_a1 = (long)((unsigned long)r_t0 << (2));
    r_a1 = (long)(r_a1 + r_t0);
    r_a1 = (long)((unsigned long)r_a1 << (3));
    r_a1 = (long)(r_a1 + r_t0);
    r_a3 = (long)(r_a3 + r_s0);
    r_a3 = (long)(r_a3 + r_s1);
    r_s2 = (long)((unsigned long)r_a1 << (4));
    r_a3 = (long)(r_a3 + r_s2);
    if (r_a3) { r_a1 = *(int *)((char *)r_a3 + (44)); }
    if (r_s6 != r_a1) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F73EEC; }
    if (r_a3) { r_a1 = *(int *)((char *)r_a3 + (552)); }
    if (r_a1 != r_a2) goto _lbl_01F73EE8;
    if (r_a3) { r_a1 = *(int *)((char *)r_a3 + (676)); }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (3540)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3656)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3532)); }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)((long)r_v1 >> (1));
    r_v1 = (long)(r_v1 + r_a1);
    r_v0 = (long)((long)r_v0 >> (1));
    r_v0 = (long)(r_v1 - r_v0);
    /* unhandled: negu $a1 $v0 */
    r_v0 = (long)func_01F6FD90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (2084)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3652)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3536)); }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (3544)); }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s0 + r_a1);
    r_a1 = (long)(r_a1 + r_s1);
    r_a1 = (long)(r_a1 + r_s2);
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (680)); }
    r_v1 = (long)((long)r_v1 >> (1));
    r_v0 = (long)((long)r_v0 >> (1));
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)(r_v1 + r_a1);
    r_v0 = (long)(r_v1 - r_v0);
    /* unhandled: negu $a1 $v0 */
    r_v0 = (long)func_01F6FDE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (2084)); }
    if (r_s4) { r_t2 = *(int *)((char *)r_s4 + (3540)); }
    if (r_s4) { r_a3 = *(int *)((char *)r_s4 + (3544)); }
    if (r_s4) { r_t0 = *(int *)((char *)r_s4 + (3692)); }
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (3696)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3656)); }
    r_a0 = (long)(r_s0 + r_v0);
    r_a0 = (long)(r_a0 + r_s1);
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3652)); }
    r_a2 = (long)(r_a0 + r_s2);
    if (r_a2) { r_t1 = *(int *)((char *)r_a2 + (676)); }
    r_a0 = (long)((long)r_v1 >> (1));
    r_v1 = (long)(0 + (1));
    if (r_a2) { r_a2 = *(int *)((char *)r_a2 + (680)); }
    r_t1 = (long)(r_t2 + r_t1);
    r_t0 = (long)(r_t0 + r_t1);
    r_a0 = (long)(r_a0 + r_t0);
    r_a2 = (long)(r_a3 + r_a2);
    r_a1 = (long)(r_a1 + r_a2);
    r_v0 = (long)(r_v0 + r_a1);
    goto _lbl_01F73EF8;
_lbl_01F73EE8:
    r_t0 = (long)(r_t0 + (1));
_lbl_01F73EEC:
    r_a1 = (long)((long)r_t0 < (long)(5) ? 1 : 0);
    if (r_a1 != 0) goto _lbl_01F73DE8;
_lbl_01F73EF8:
    r_s5 = (long)(r_s5 + (1));
_lbl_01F73EFC:
    r_a1 = (long)((long)r_s5 < (long)(5) ? 1 : 0);
    if (r_a1 != 0) { r_a1 = (long)(0 + (0xcd0)); goto _lbl_01F73DD8; }
    r_a1 = (long)(0 + (0xcd0));
    r_s3 = (long)(r_s3 + (1));
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (2080)); }
_lbl_01F73F10:
    r_a1 = (long)((long)r_s3 < (long)r_a1 ? 1 : 0);
    if (r_a1 != 0) { r_a1 = (long)(0 + (0x405c)); goto _lbl_01F73DC8; }
    r_a1 = (long)(0 + (0x405c));
_lbl_01F73F1C:
    r_a3 = (long)(0 + (1));
_lbl_01F73F20:
    if (r_v1 == r_a3) goto _lbl_01F7402C;
    if (r_s4) { r_t0 = *(int *)((char *)r_s4 + (2072)); }
    r_a1 = (long)(0 + (0x6d));
    r_t2 = (long)(0 | 0);
    goto _lbl_01F74020;
_lbl_01F73F38:
    if (r_s4) { r_t1 = *(int *)((char *)r_s4 + (2076)); }
    r_v1 = (long)((unsigned long)r_t2 << (5));
    r_a2 = (long)(r_v1 - r_t2);
    r_v1 = (long)((unsigned long)r_a2 << (2));
    r_v1 = (long)(r_v1 - r_a2);
    r_s0 = (long)((unsigned long)r_v1 << (3));
    r_a2 = (long)(r_t1 + r_s0);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (28)); }
    if (r_v1 != r_a1) { r_t2 = (long)(r_t2 + (1)); goto _lbl_01F74020; }
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (672)); }
    if (r_v1 != r_a3) goto _lbl_01F7401C;
    if (r_a2) { r_a1 = *(int *)((char *)r_a2 + (656)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3648)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3532)); }
    r_a0 = (long)(r_s4 | 0);
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (3540)); }
    r_v1 = (long)((long)r_v1 >> (1));
    r_v0 = (long)((long)r_v0 >> (1));
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)(r_v1 + r_a1);
    r_v0 = (long)(r_v1 - r_v0);
    /* unhandled: negu $a1 $v0 */
    r_v0 = (long)func_01F6FD90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (2076)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3644)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3536)); }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (3544)); }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s0 + r_a1);
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (660)); }
    r_v1 = (long)((long)r_v1 >> (1));
    r_v0 = (long)((long)r_v0 >> (1));
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)(r_v1 + r_a1);
    r_v0 = (long)(r_v1 - r_v0);
    /* unhandled: negu $a1 $v0 */
    r_v0 = (long)func_01F6FDE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (2076)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (3648)); }
    if (r_s4) { r_t1 = *(int *)((char *)r_s4 + (3540)); }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (3544)); }
    if (r_s4) { r_a3 = *(int *)((char *)r_s4 + (3692)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3696)); }
    r_a1 = (long)(r_s0 + r_v0);
    if (r_a1) { r_t0 = *(int *)((char *)r_a1 + (656)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3644)); }
    r_a0 = (long)((long)r_a0 >> (1));
    if (r_a1) { r_a1 = *(int *)((char *)r_a1 + (660)); }
    r_t0 = (long)(r_t1 + r_t0);
    r_a3 = (long)(r_a3 + r_t0);
    r_a0 = (long)(r_a0 + r_a3);
    r_a1 = (long)(r_a2 + r_a1);
    r_v1 = (long)(r_v1 + r_a1);
    r_v0 = (long)(r_v0 + r_v1);
    goto _lbl_01F7402C;
_lbl_01F7401C:
    r_t2 = (long)(r_t2 + (1));
_lbl_01F74020:
    r_v1 = (long)((long)r_t2 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F73F38;
_lbl_01F7402C:
    if ((long)r_a0 < 0) goto _lbl_01F7408C;
    if ((long)r_v0 < 0) goto _lbl_01F7408C;
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (3540)); }
    r_v1 = (long)((long)r_a0 < (long)r_a1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F7408C;
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3532)); }
    r_v1 = (long)(r_a1 + r_v1);
    r_at = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F7408C;
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (3544)); }
    r_v1 = (long)((long)r_v0 < (long)r_a1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F7408C;
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3536)); }
    r_v1 = (long)(r_a1 + r_v1);
    r_at = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_at != 0) goto _lbl_01F7408C;
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_002257C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F7408C:
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5864)); }
_lbl_01F74090:
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3692)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3696)); }
    r_a3 = (long)(0 + (0x5a));
    r_t0 = (long)(r_a3 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a1 = (long)(r_v1 + (0x56));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a2 = (long)(r_v0 + (0x3c));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5868)); }
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3692)); }
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (3696)); }
    r_a3 = (long)(0 + (0x5a));
    r_t0 = (long)(r_a3 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a1 = (long)(r_v1 + (0xb8));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a2 = (long)(r_v0 + (0x3c));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(0 | 0);
    goto _lbl_01F74120;
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F740E8:
    r_v0 = (long)(r_s4 + r_v0);
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3696)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (5852)); }
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (3692)); }
    r_a3 = (long)(0 + (0xa0));
    r_t0 = (long)(0 + (0x10));
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_v1 = (long)(r_v1 + (0x63));
    r_v0 = (long)((unsigned long)r_s0 << (4));
    r_a1 = (long)(r_a1 + (0xb7));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a2 = (long)(r_v1 + r_v0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_s0 + (1));
_lbl_01F74120:
    r_v1 = (long)((long)r_s0 < (long)(3) ? 1 : 0);
    if (r_v1 != 0) { r_v0 = (long)((unsigned long)r_s0 << (2)); goto _lbl_01F740E8; }
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 51: thelp_func_01F74154 (VMA: 0x01F74154, size: 148 bytes) */
void *thelp_func_01F74154(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x40));
    /* unhandled: dpa.w.ph $ac0 $sp $ra */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_v0 = (long)(0 + (0x17d2));
    r_s1 = (long)(r_a1 | 0);
    r_s0 = (long)(r_a2 | 0);
    if (r_s1 != r_v0) { r_s2 = (long)(r_a0 | 0); goto _lbl_01F74190; }
    r_s2 = (long)(r_a0 | 0);
    r_v0 = (long)func_01F694A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F74190:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2088)); }
    if (r_a0 == 0) { r_a0 = (long)(r_s2 | 0); goto _lbl_01F741C4; }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a1 = (long)(r_s1 | 0);
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (108)); }
    r_a2 = (long)(r_s0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 == 0) goto _lbl_01F741C0;
    goto _lbl_01F741D4;
_lbl_01F741C0:
    r_a0 = (long)(r_s2 | 0);
_lbl_01F741C4:
    r_a1 = (long)(r_s1 | 0);
    r_a2 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F5AD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F741D4:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 52: thelp_func_01F741E8 (VMA: 0x01F741E8, size: 372 bytes) */
void *thelp_func_01F741E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0, r_t1 = 0;
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
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x80));
    /* unhandled: dps.w.ph $ac0 $sp $ra */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_v0 = (long)(0 + (0x511));
    r_s2 = (long)(r_a2 | 0);
    r_s4 = (long)(r_a0 | 0);
    r_s3 = (long)(r_a1 | 0);
    r_s1 = (long)(r_a3 | 0);
    if (r_s2 != r_v0) { r_s0 = (long)(r_t0 | 0); goto _lbl_01F742C8; }
    r_s0 = (long)(r_t0 | 0);
    r_v0 = (long)func_0021FED0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_v0 ? 1 : 0);
    r_v0 = (long)(r_v0 ^ (1));
    r_a0 = (long)(0 + (0x4016));
    r_s5 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_0025D060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_0021FEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5 != 0) goto _lbl_01F742B0;
    r_a0 = (long)(r_s4 + (0x173c));
    r_v0 = (long)func_00225560((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5828)); }
    r_v0 = (long)func_001F6DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5828)); }
    r_s5 = (long)((long)r_v0 >> (1));
    r_v0 = (long)func_001F6DB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5828)); }
    r_s6 = (long)(r_v0 + r_s5);
    r_v0 = (long)func_001F6DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5828)); }
    r_s5 = (long)((long)r_v0 >> (1));
    r_v0 = (long)func_001F6DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_v0 + r_s5);
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_002257C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(0 + (6));
    r_v0 = (long)func_001861C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x10));
    goto _lbl_01F742CC;
_lbl_01F742B0:
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_001861C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4) { r_a1 = *(int *)((char *)r_s4 + (5952)); }
    if (r_s4) { r_a0 = *(int *)((char *)r_s4 + (5948)); }
    r_v0 = (long)func_002257C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F742C8:
    r_v0 = (long)(0 + (0x10));
_lbl_01F742CC:
    if (r_s2 != r_v0) { r_a0 = (long)(r_s4 | 0); goto _lbl_01F74320; }
    r_a0 = (long)(r_s4 | 0);
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (2100)); }
    if (r_v0 == 0) goto _lbl_01F7431C;
    if (r_s4) { r_v1 = *(int *)((char *)r_s4 + (3560)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) goto _lbl_01F7431C;
    if (r_s4) { *(int *)((char *)r_s4 + (3560)) = (int)r_v0; }
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(0 + (0xc1d));
    r_a2 = (long)(r_v0 + (-0x6a30));
    r_a3 = (long)(0 + (0x1c2));
    r_t0 = (long)(0 + (0x64));
    r_a0 = (long)(r_s4 | 0);
    r_t1 = (long)(0 | 0);
    r_v0 = (long)func_001FBA10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F74334;
_lbl_01F7431C:
    r_a0 = (long)(r_s4 | 0);
_lbl_01F74320:
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_a3 = (long)(r_s1 | 0);
    r_t0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F45E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F74334:
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 53: thelp_func_01F7435C (VMA: 0x01F7435C, size: 468 bytes) */
void *thelp_func_01F7435C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0xc0));
    /* unhandled: mulsa.w.ph $ac0 $sp $ra */
    /* unhandled: ext $s6 $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s5 */
    /* unhandled: subu.qb $zero $sp $s3 */
    /* unhandled: ext $s2 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s1 */
    r_s5 = (long)(r_a0 | 0);
    r_a0 = (long)(0 + (0x8c4));
    r_s4 = (long)(r_a1 | 0);
    r_s3 = (long)(r_a2 | 0);
    r_s2 = (long)(r_a3 | 0);
    r_s1 = (long)(r_t0 | 0);
    r_s6 = (long)(r_t1 | 0);
    r_s8 = (long)(r_t2 | 0);
    r_s7 = (long)(r_t3 | 0);
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01F743C4; }
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F745B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F743C4:
    if (r_s3) { *(int *)((char *)r_s3 + (0)) = (int)r_s0; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1 == 0) { r_v0 = (long)(0 + (1)); goto _lbl_01F743E4; }
    r_v0 = (long)(0 + (1));
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (244)); }
    if (r_v0 == 0) { r_a1 = (long)(0 + (5)); goto _lbl_01F743F4; }
    r_a1 = (long)(0 + (5));
    r_v0 = (long)(0 + (1));
_lbl_01F743E4:
    if (r_s5) { *(int *)((char *)r_s5 + (244)) = (int)r_v0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F74500;
    r_a1 = (long)(0 + (5));
_lbl_01F743F4:
    if (r_v1) { *(int *)((char *)r_v1 + (2216)) = (int)r_a1; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_00185E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (4)); }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (0)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2220)) = (int)r_v1; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(0 + (5));
    r_v0 = (long)func_00185E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (8)); }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (0)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2224)) = (int)r_v1; }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_00185E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_001F6DF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (4)); }
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(r_s4 | 0);
    r_a3 = (long)(r_s2 | 0);
    r_t0 = (long)(r_s1 | 0);
    r_t1 = (long)(r_s6 | 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (8)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_s0) { r_t3 = *(int *)((char *)r_s0 + (0)); }
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (0)); }
    r_t2 = (long)(r_s8 | 0);
    r_v0 = (long)func_01F746F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F74490;
    r_v0 = (long)(0 + (1));
    if (r_s5) { *(int *)((char *)r_s5 + (244)) = (int)r_v0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F74500;
_lbl_01F74490:
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (192)); }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (0)); }
    r_a2 = (long)(0 + (0x4a));
    r_a1 = (long)(0 + (0x24));
    r_a0 = (long)(0 + (0x13));
    if (r_v0) { *(int *)((char *)r_v0 + (2176)) = (int)r_v1; }
    if (r_sp) { r_a3 = *(int *)((char *)r_sp + (216)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    r_v0 = (long)(0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (2180)) = (int)r_a3; }
    if (r_sp) { r_a3 = *(int *)((char *)r_sp + (200)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2184)) = (int)r_a3; }
    if (r_sp) { r_a3 = *(int *)((char *)r_sp + (208)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2188)) = (int)r_a3; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2192)) = (int)r_a2; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2196)) = (int)r_a2; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2200)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2204)) = (int)r_a1; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2208)) = (int)r_a0; }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (2212)) = (int)r_v0; }
_lbl_01F74500:
    /* unhandled: ld.b $w2 -0x42($zero) */
    /* unhandled: aver_u.h $w2 $w0 $w23 */
    /* unhandled: xori.b $w2 $w0 0xb6 */
    /* unhandled: ld.b $w1 -0x4c($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w19 */
    /* unhandled: xori.b $w1 $w0 0xb2 */
    /* unhandled: ld.b $w0 -0x50($zero) */
    r_sp = (long)(r_sp + (0xc0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 54: thelp_func_01F74530 (VMA: 0x01F74530, size: 208 bytes) */
void *thelp_func_01F74530(void *a0, void *a1, void *a2, void *a3) {
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
    r_v0 = (long)(0x1f8 << 16);
    /* unhandled: ext $s0 $sp 0 1 */
    r_a1 = (long)(r_v0 + (-0x69b0));
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)func_0020BAF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0x4e << 16);
    r_v0 = (long)(r_v0 + (0x2260));
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2088)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2092)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2176)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2180)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2184)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2188)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2192)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2196)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2200)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2204)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2208)) = (int)0; }
    r_v0 = (long)(0 + (5));
    if (r_s0) { *(int *)((char *)r_s0 + (2212)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2216)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2220)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2224)) = (int)0; }
    r_v0 = (long)(0 + (3));
    if (r_s0) { *(int *)((char *)r_s0 + (2228)) = (int)0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2232)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (2236)) = (int)0; }
    r_v1 = (long)(0 + (-1));
    if (r_s0) { *(int *)((char *)r_s0 + (2240)) = (int)0; }
    r_a0 = (long)(0 | 0);
    goto _lbl_01F745E0;
    r_v0 = (long)((unsigned long)r_a0 << (2));
_lbl_01F745BC:
    r_v0 = (long)(r_v0 + r_a0);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)(r_s0 + r_v0);
    if (r_v0) { *(int *)((char *)r_v0 + (2096)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (2100)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (2104)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (2108)) = (int)r_v1; }
    r_a0 = (long)(r_a0 + (1));
    if (r_v0) { *(int *)((char *)r_v0 + (2112)) = (int)r_v1; }
_lbl_01F745E0:
    r_v0 = (long)((long)r_a0 < (long)(4) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F745BC; }
    r_v0 = (long)((unsigned long)r_a0 << (2));
    r_v0 = (long)(r_s0 | 0);
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 55: thelp_func_01F74600 (VMA: 0x01F74600, size: 108 bytes) */
void *thelp_func_01F74600(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_s1 == 0) { r_s0 = (long)(r_a1 | 0); goto _lbl_01F74654; }
    r_s0 = (long)(r_a1 | 0);
    r_v0 = (long)(0x4e << 16);
    r_v0 = (long)(r_v0 + (0x2260));
    r_a1 = (long)(r_s1 + (0x8b4));
    if (r_s1) { *(int *)((char *)r_s1 + (0)) = (int)r_v0; }
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_0020BE60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 <= 0) { r_v0 = (long)(r_s1 | 0); goto _lbl_01F74658; }
    r_v0 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F74654:
    r_v0 = (long)(r_s1 | 0);
_lbl_01F74658:
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 56: thelp_func_01F7466C (VMA: 0x01F7466C, size: 428 bytes) */
void *thelp_func_01F7466C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0xf0));
    /* unhandled: ext $s7 $sp 3 1 */
    /* unhandled: mulsa.w.ph $ac0 $sp $s6 */
    /* unhandled: ext $s3 $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s2 */
    if (r_sp) { r_s8 = *(int *)((char *)r_sp + (248)); }
    r_s1 = (long)(r_a2 | 0);
    r_s6 = (long)(r_a0 | 0);
    r_s5 = (long)(r_a1 | 0);
    r_s4 = (long)(r_t1 | 0);
    r_s3 = (long)(r_t2 | 0);
    r_s2 = (long)(r_t3 | 0);
    r_a0 = (long)(r_s1 | 0);
    /* unhandled: subu.qb $zero $sp $s0 */
    r_v0 = (long)func_001F6DF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F8E60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_001F8E70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_t3 = (long)(0 + (1));
    r_a1 = (long)(r_s0 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_t1 = (long)(r_s7 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_a3 = (long)(r_s4 | 0);
    r_t0 = (long)(r_s3 | 0);
    r_t2 = (long)(r_v0 | 0);
    r_v0 = (long)func_0020BB50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a0 = (long)(0 + (0x1dc)); goto _lbl_01F74710; }
    r_a0 = (long)(0 + (0x1dc));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F747E8;
    r_a0 = (long)(0 + (0x1dc));
_lbl_01F74710:
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01F74728; }
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_00215EE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F74728:
    if (r_s6) { *(int *)((char *)r_s6 + (2228)) = (int)r_s0; }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2232)); }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (240)); }
    r_a1 = (long)(r_s5 | 0);
    r_t3 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s6 | 0);
    r_v0 = (long)(r_s4 - r_a0);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (256)); }
    r_t1 = (long)(r_v0 + (-8));
    r_a3 = (long)(r_a0 + (8));
    r_v0 = (long)(r_s3 - r_a0);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2228)); }
    r_t2 = (long)(r_v0 + (-8));
    r_t0 = (long)(r_a3 | 0);
    r_v0 = (long)func_00216240((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F74798;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F747E8;
_lbl_01F74798:
    if (r_s6) { *(int *)((char *)r_s6 + (2240)) = (int)r_s8; }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2228)); }
    r_a1 = (long)(0 + (3));
    r_a2 = (long)(0 + (1));
    r_v0 = (long)func_00217840((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2228)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_00217880((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2228)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_002178A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2228)); }
    r_v0 = (long)(0xff << 16);
    r_a1 = (long)(r_v0 | (0xffff));
    r_a2 = (long)(0 | (0xe7e7));
    r_v0 = (long)func_002178E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (2228)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_00219F00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01F747E8:
    /* unhandled: ld.b $w3 -0x41($zero) */
    /* unhandled: aver_u.h $w3 $w0 $w30 */
    /* unhandled: xori.b $w3 $w0 0xb7 */
    /* unhandled: ld.b $w2 -0x4b($zero) */
    /* unhandled: aver_u.h $w2 $w0 $w20 */
    /* unhandled: xori.b $w2 $w0 0xb3 */
    /* unhandled: ld.b $w1 -0x4f($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w16 */
    r_sp = (long)(r_sp + (0xf0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 57: thelp_func_01F74818 (VMA: 0x01F74818, size: 100 bytes) */
void *thelp_func_01F74818(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t0 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t0;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x20));
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (132)); }
    if (r_v0 != 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01F74840; }
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F7486C;
_lbl_01F74840:
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (2056)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (64)); }
    r_v0 = (long)func_001F6750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (64)); }
    r_a1 = (long)(r_s0 | 0);
    r_a2 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (208)); }
    r_t0 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F7486C:
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 58: thelp_func_01F7487C (VMA: 0x01F7487C, size: 268 bytes) */
void *thelp_func_01F7487C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0, r_t9 = 0;
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
    (void)r_t0;
    (void)r_t1;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x170));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (132)); }
    r_s4 = (long)(r_a1 | 0);
    r_s3 = (long)(r_a2 | 0);
    r_s2 = (long)(r_a3 | 0);
    r_s1 = (long)(r_t0 | 0);
    r_s0 = (long)(r_t1 | 0);
    if (r_v0 != 0) { r_s5 = (long)(r_a0 | 0); goto _lbl_01F748C8; }
    r_s5 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F74964;
_lbl_01F748C8:
    if (r_s4 == 0) { r_a0 = (long)(r_s5 | 0); goto _lbl_01F7494C; }
    r_a0 = (long)(r_s5 | 0);
    r_a0 = (long)(r_sp + (0x70));
    r_v0 = (long)func_0036DDF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (266)); }
    if (r_v0 == 0) goto _lbl_01F74914;
    r_v0 = (long)(0 + (0x26));
    if (r_s4 == r_v0) goto _lbl_01F74948;
    r_v0 = (long)(0 + (0x28));
    if (r_s4 == r_v0) goto _lbl_01F74948;
    r_v0 = (long)(0 + (0x25));
    if (r_s4 == r_v0) goto _lbl_01F74948;
    r_v0 = (long)(0 + (0x27));
    if (r_s4 == r_v0) goto _lbl_01F74948;
_lbl_01F74914:
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2056)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (64)); }
    r_v0 = (long)func_001F6750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (64)); }
    r_a1 = (long)(r_s5 | 0);
    r_a2 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (208)); }
    r_t0 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    /* unhandled: ld.b $w1 -0x41($zero) */
    goto _lbl_01F74968;
_lbl_01F74948:
    r_a0 = (long)(r_s5 | 0);
_lbl_01F7494C:
    r_a1 = (long)(r_s4 | 0);
    r_a2 = (long)(r_s3 | 0);
    r_a3 = (long)(r_s2 | 0);
    r_t0 = (long)(r_s1 | 0);
    r_t1 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F55C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F74964:
    /* unhandled: ld.b $w1 -0x41($zero) */
_lbl_01F74968:
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x170));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 59: thelp_func_01F74988 (VMA: 0x01F74988, size: 620 bytes) */
void *thelp_func_01F74988(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t9 = 0;
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
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0xa0));
    /* unhandled: ext $s5 $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s4 */
    /* unhandled: subu.qb $zero $sp $s2 */
    /* unhandled: ext $s1 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s0 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (64)); }
    r_s4 = (long)(r_a1 | 0);
    r_s3 = (long)(r_a2 | 0);
    r_s2 = (long)(r_a3 | 0);
    r_s1 = (long)(r_t0 | 0);
    r_s0 = (long)(r_t1 | 0);
    if (r_v0 == 0) { r_s5 = (long)(r_a0 | 0); goto _lbl_01F749E4; }
    r_s5 = (long)(r_a0 | 0);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (60)); }
    if (r_s5) { *(int *)((char *)r_s5 + (2056)) = (int)r_v0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (64)); }
    r_a1 = (long)(r_s5 | 0);
    r_v0 = (long)func_001F6750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F749E4:
    if (r_s0 == 0) goto _lbl_01F749F8;
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (0)); }
    if ((long)r_v0 > 0) goto _lbl_01F74A60;
_lbl_01F749F8:
    if (r_s5) { r_t9 = *(int *)((char *)r_s5 + (0)); }
    r_a1 = (long)(r_s4 | 0);
    r_a2 = (long)(r_s3 | 0);
    r_a0 = (long)(r_s5 | 0);
    r_a3 = (long)(r_s2 | 0);
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_t0 = (long)(r_s1 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s5) { *(int *)((char *)r_s5 + (2092)) = (int)0; }
    if (r_s5) { *(int *)((char *)r_s5 + (2088)) = (int)0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2228)); }
    if (r_a0 == 0) goto _lbl_01F74BD0;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2232)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a2 = (long)(r_v0 + (8));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_v0 = (long)((unsigned long)r_v0 << (1));
    r_v1 = (long)(r_s2 - r_v0);
    r_v0 = (long)(r_s1 - r_v0);
    r_a3 = (long)(r_v1 + (-0x10));
    r_t0 = (long)(r_v0 + (-0x10));
    r_a1 = (long)(r_a2 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    goto _lbl_01F74BD4;
_lbl_01F74A60:
    if (r_s5) { r_t9 = *(int *)((char *)r_s5 + (0)); }
    r_a0 = (long)(r_s5 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(r_s4 | 0);
    r_a3 = (long)(r_s3 | 0);
    r_t0 = (long)(0 | 0);
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (32)); }
    r_t1 = (long)(0 | 0);
    r_t2 = (long)(r_s2 | 0);
    r_t3 = (long)(r_s2 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (2232)); }
    r_a0 = (long)(0 + (0x1f4));
    r_v1 = (long)(0 + (0x4a));
    r_a1 = (long)(0 | 0);
    r_t1 = (long)(r_t0 + (0x1e));
    r_a3 = (long)((unsigned long)r_t1 << (1));
    r_a0 = (long)(r_a0 - r_a3);
    /* unhandled: div $zero $a0 $v1 */
    if (r_v1 != 0) { r_a2 = (long)(0 | 0); goto _lbl_01F74AD0; }
    r_a2 = (long)(0 | 0);
    /* unhandled: break 0 7 */
_lbl_01F74AD0:
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (2236)); }
    r_v1 = (long)(r_s1 - r_t0);
    r_t2 = (long)(r_v1 + (-8));
    /* unhandled: mflo $t0 */
    r_a0 = (long)(0 | 0);
    r_v1 = (long)((unsigned long)r_a3 << (3));
    r_v1 = (long)(r_v1 + r_a3);
    r_v1 = (long)((unsigned long)r_v1 << (1));
    r_v1 = (long)(r_v1 + r_a3);
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_a3 = (long)(r_t2 - r_v1);
    r_v1 = (long)(r_a3 | 0);
    goto _lbl_01F74B70;
    r_t2 = (long)((unsigned long)r_a0 << (2));
_lbl_01F74B08:
    r_t5 = (long)(r_s0 + r_t2);
    r_t2 = (long)((unsigned long)r_a2 << (2));
    r_t2 = (long)(r_t2 + r_a2);
    if (r_t5) { r_t3 = *(int *)((char *)r_t5 + (4)); }
    r_t2 = (long)((unsigned long)r_t2 << (2));
    r_t6 = (long)(r_s5 + r_t2);
    r_a2 = (long)(r_a2 + (1));
    if (r_t6) { *(int *)((char *)r_t6 + (2096)) = (int)r_t3; }
    if (r_t5) { r_t2 = *(int *)((char *)r_t5 + (44)); }
    r_t4 = (long)(r_s4 + r_t1);
    r_t3 = (long)(r_s3 + r_a3);
    if (r_t6) { *(int *)((char *)r_t6 + (2104)) = (int)r_t2; }
    if (r_t5) { r_t5 = *(int *)((char *)r_t5 + (24)); }
    r_t2 = (long)(r_a2 + (1));
    r_at = (long)((long)r_t0 < (long)r_t2 ? 1 : 0);
    if (r_t6) { *(int *)((char *)r_t6 + (2100)) = (int)r_t5; }
    if (r_t6) { *(int *)((char *)r_t6 + (2108)) = (int)r_t4; }
    if (r_at == 0) { if (r_t6) { *(int *)((char *)r_t6 + (2112)) = (int)r_t3; } goto _lbl_01F74B68; }
    if (r_t6) { *(int *)((char *)r_t6 + (2112)) = (int)r_t3; }
    if (r_s5) { r_t1 = *(int *)((char *)r_s5 + (2232)); }
    r_a3 = (long)(r_a3 + (0x4c));
    r_a1 = (long)(r_a1 + (1));
    r_t1 = (long)(r_t1 + (0x1e));
    goto _lbl_01F74B6C;
_lbl_01F74B68:
    r_t1 = (long)(r_t1 + (0x68));
_lbl_01F74B6C:
    r_a0 = (long)(r_a0 + (1));
_lbl_01F74B70:
    if (r_s0) { r_t2 = *(unsigned char *)((char *)r_s0 + (0)); }
    r_at = (long)((long)r_a0 < (long)r_t2 ? 1 : 0);
    if (r_at == 0) { r_a0 = (long)(0 + (1)); goto _lbl_01F74B90; }
    r_t2 = (long)((long)r_a0 < (long)(4) ? 1 : 0);
    if (r_t2 != 0) { r_t2 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F74B08; }
    r_t2 = (long)((unsigned long)r_a0 << (2));
    r_a0 = (long)(0 + (1));
_lbl_01F74B90:
    if (r_s5) { *(int *)((char *)r_s5 + (2092)) = (int)r_a2; }
    if (r_s5) { *(int *)((char *)r_s5 + (2088)) = (int)r_a0; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2228)); }
    if (r_a0 == 0) goto _lbl_01F74BD0;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2232)); }
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    r_a2 = (long)(r_v0 + (8));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_v0 = (long)((unsigned long)r_v0 << (1));
    r_v0 = (long)(r_s2 - r_v0);
    r_a3 = (long)(r_v0 + (-0x10));
    r_v0 = (long)(r_v1 - r_a2);
    r_t0 = (long)(r_v0 + (1));
    r_a1 = (long)(r_a2 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F74BD0:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
_lbl_01F74BD4:
    /* unhandled: xori.b $w2 $w0 0xb5 */
    /* unhandled: ld.b $w1 -0x4d($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w18 */
    /* unhandled: xori.b $w1 $w0 0xb1 */
    r_sp = (long)(r_sp + (0xa0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 60: thelp_func_01F74BF4 (VMA: 0x01F74BF4, size: 72 bytes) */
void *thelp_func_01F74BF4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    if (r_a0) { *(int *)((char *)r_a0 + (2176)) = (int)r_a1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2180)) = (int)r_a3; }
    if (r_a0) { *(int *)((char *)r_a0 + (2184)) = (int)r_a2; }
    r_v1 = (long)(0 + (0x4a));
    if (r_a0) { *(int *)((char *)r_a0 + (2188)) = (int)r_t0; }
    if (r_a0) { *(int *)((char *)r_a0 + (2192)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2196)) = (int)r_v1; }
    r_v1 = (long)(0 + (0x24));
    if (r_a0) { *(int *)((char *)r_a0 + (2200)) = (int)r_v1; }
    if (r_a0) { *(int *)((char *)r_a0 + (2204)) = (int)r_v1; }
    r_v1 = (long)(0 + (0x13));
    if (r_a0) { *(int *)((char *)r_a0 + (2208)) = (int)r_v1; }
    r_v1 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (2212)) = (int)r_v1; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 61: thelp_func_01F74C3C (VMA: 0x01F74C3C, size: 52 bytes) */
void *thelp_func_01F74C3C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x10));
    /* unhandled: ext $ra $sp 0 1 */
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (2228)); }
    if (r_a0 == 0) goto _lbl_01F74C64;
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (268)); }
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F74C64:
    /* unhandled: xori.b $w0 $w0 0xbf */
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 62: thelp_func_01F74C70 (VMA: 0x01F74C70, size: 336 bytes) */
void *thelp_func_01F74C70(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2232)); }
    r_s2 = (long)(r_a0 | 0);
    r_s1 = (long)(r_a1 | 0);
    r_v1 = (long)((unsigned long)r_v1 << (1));
    r_v1 = (long)(r_v1 + (0x204));
    if (r_a2) { *(int *)((char *)r_a2 + (0)) = (int)r_v1; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2232)); }
    r_v1 = (long)((unsigned long)r_v1 << (1));
    r_v1 = (long)(r_v1 + (0x10));
    if (r_a3) { *(int *)((char *)r_a3 + (0)) = (int)r_v1; }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (2228)); }
    if (r_a0 == 0) { r_s0 = (long)(r_a3 | 0); goto _lbl_01F74CD8; }
    r_s0 = (long)(r_a3 | 0);
    r_v0 = (long)func_002193D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2240)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    r_a0 = (long)(r_a0 + (2));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v1; }
_lbl_01F74CD8:
    if (r_s1 == 0) goto _lbl_01F74DA8;
    if (r_s1) { r_a2 = *(unsigned char *)((char *)r_s1 + (0)); }
    if ((long)r_a2 <= 0) goto _lbl_01F74DA8;
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (2232)); }
    r_a0 = (long)(0 + (0x1f4));
    r_v1 = (long)(0 + (0x4a));
    r_a1 = (long)(r_a1 + (0x1e));
    r_a1 = (long)((unsigned long)r_a1 << (1));
    r_a0 = (long)(r_a0 - r_a1);
    if (r_v1 != 0) { /* unhandled: div $zero $a0 $v1 */ goto _lbl_01F74D10; }
    /* unhandled: div $zero $a0 $v1 */
    /* unhandled: break 0 7 */
_lbl_01F74D10:
    /* unhandled: mflo $a0 */
    if (r_a0 != 0) { /* unhandled: div $zero $a2 $a0 */ goto _lbl_01F74D20; }
    /* unhandled: div $zero $a2 $a0 */
    /* unhandled: break 0 7 */
_lbl_01F74D20:
    /* unhandled: mflo $v1 */
    if (r_s2) { *(int *)((char *)r_s2 + (2236)) = (int)r_v1; }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2236)); }
    if ((long)r_v1 > 0) goto _lbl_01F74D40;
    r_v1 = (long)(0 + (1));
    if (r_s2) { *(int *)((char *)r_s2 + (2236)) = (int)r_v1; }
    goto _lbl_01F74D68;
_lbl_01F74D40:
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (0)); }
    if (r_a0 != 0) { /* unhandled: div $zero $v1 $a0 */ goto _lbl_01F74D50; }
    /* unhandled: div $zero $v1 $a0 */
    /* unhandled: break 0 7 */
_lbl_01F74D50:
    /* unhandled: mfhi $v1 */
    if ((long)r_v1 <= 0) goto _lbl_01F74D68;
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (2236)); }
    r_v1 = (long)(r_v1 + (1));
    if (r_s2) { *(int *)((char *)r_s2 + (2236)) = (int)r_v1; }
_lbl_01F74D68:
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2240)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    r_a0 = (long)(r_a0 + (2));
    r_a0 = (long)((unsigned long)r_a0 << (1));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (2236)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0)); }
    r_a0 = (long)((unsigned long)r_a1 << (3));
    r_a0 = (long)(r_a0 + r_a1);
    r_a0 = (long)((unsigned long)r_a0 << (1));
    r_a0 = (long)(r_a0 + r_a1);
    r_a0 = (long)((unsigned long)r_a0 << (1));
    r_a0 = (long)(r_a0 + (-8));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_s0) { *(int *)((char *)r_s0 + (0)) = (int)r_v1; }
_lbl_01F74DA8:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 63: thelp_func_01F74DC0 (VMA: 0x01F74DC0, size: 968 bytes) */
void *thelp_func_01F74DC0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t9 = 0;
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
    (void)r_t1;
    (void)r_t2;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0xb0));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (32)); }
    r_s5 = (long)(r_a0 | 0);
    if (r_v1 == 0) { r_s2 = (long)(0 | 0); goto _lbl_01F75158; }
    r_s2 = (long)(0 | 0);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (136)); }
    if (r_v1 == 0) goto _lbl_01F75158;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (132)); }
    if (r_v1 != 0) goto _lbl_01F74E1C;
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    goto _lbl_01F7515C;
_lbl_01F74E1C:
    if (r_s5) { r_t9 = *(int *)((char *)r_s5 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (40)); }
    r_a1 = (long)(0 + (2));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a0 = (long)(r_s5 | 0);
    r_v0 = (long)func_001F7B90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    if (r_s5) { r_s8 = *(int *)((char *)r_s5 + (2208)); }
    if (r_s5) { r_s7 = *(int *)((char *)r_s5 + (2212)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_001AB8F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F75050;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2088)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_s0 = (long)(0 | 0); goto _lbl_01F75048; }
    r_s0 = (long)(0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2092)); }
    goto _lbl_01F7503C;
_lbl_01F74E68:
    r_v0 = (long)(r_v0 + r_s0);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_a1 = (long)(r_s5 + r_v0);
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (2104)); }
    if (r_a0 == 0) { r_s6 = (long)(r_a1 + (0x838)); goto _lbl_01F75034; }
    r_s6 = (long)(r_a1 + (0x838));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (508)); }
    r_v0 = (long)(0 + (5));
    if (r_v1 == r_v0) { r_v0 = (long)(0 | 0); goto _lbl_01F74ED4; }
    r_v0 = (long)(0 | 0);
    r_v0 = (long)(0 + (4));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F74ECC; }
    r_v0 = (long)(0 + (1));
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F74EC4; }
    r_v0 = (long)(0 + (1));
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F74EBC; }
    r_v0 = (long)(0 + (1));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F74ED4;
_lbl_01F74EBC:
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (512)); }
    goto _lbl_01F74ED8;
_lbl_01F74EC4:
    goto _lbl_01F74ED4;
_lbl_01F74ECC:
    goto _lbl_01F74ED4;
_lbl_01F74ED4:
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (512)); }
_lbl_01F74ED8:
    r_v1 = (long)(0 + (6));
    if (r_a0 == r_v1) { r_v1 = (long)(0 | 0); goto _lbl_01F74F3C; }
    r_v1 = (long)(0 | 0);
    r_v1 = (long)(0 + (5));
    if (r_a0 == r_v1) { r_v1 = (long)(0 | 0); goto _lbl_01F74F34; }
    r_v1 = (long)(0 | 0);
    r_v1 = (long)(0 + (4));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (2)); goto _lbl_01F74F2C; }
    r_v1 = (long)(0 + (2));
    r_v1 = (long)(0 + (3));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (1)); goto _lbl_01F74F24; }
    r_v1 = (long)(0 + (1));
    r_v1 = (long)(0 + (2));
    if (r_a0 == r_v1) { r_v1 = (long)(0 + (1)); goto _lbl_01F74F1C; }
    r_v1 = (long)(0 + (1));
    r_v1 = (long)(0 | 0);
    goto _lbl_01F74F3C;
_lbl_01F74F1C:
    if (r_a1) { r_a2 = *(int *)((char *)r_a1 + (2100)); }
    goto _lbl_01F74F40;
_lbl_01F74F24:
    goto _lbl_01F74F3C;
_lbl_01F74F2C:
    goto _lbl_01F74F3C;
_lbl_01F74F34:
    goto _lbl_01F74F3C;
_lbl_01F74F3C:
    if (r_a1) { r_a2 = *(int *)((char *)r_a1 + (2100)); }
_lbl_01F74F40:
    r_a0 = (long)(0 + (4));
    if (r_a2 == r_a0) { r_a0 = (long)(0 + (3)); goto _lbl_01F74F7C; }
    r_a0 = (long)(0 + (3));
    if (r_a2 == r_a0) { r_a0 = (long)(0 + (1)); goto _lbl_01F74F70; }
    r_a0 = (long)(0 + (1));
    if (r_a2 == r_a0) goto _lbl_01F74F64;
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (2212)); }
    goto _lbl_01F74F88;
_lbl_01F74F64:
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (2212)); }
    if (r_s5) { r_s1 = *(int *)((char *)r_s5 + (2176)); }
    goto _lbl_01F74F8C;
_lbl_01F74F70:
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (2212)); }
    if (r_s5) { r_s1 = *(int *)((char *)r_s5 + (2180)); }
    goto _lbl_01F74F8C;
_lbl_01F74F7C:
    if (r_s5) { r_s2 = *(int *)((char *)r_s5 + (2212)); }
    if (r_s5) { r_s1 = *(int *)((char *)r_s5 + (2184)); }
    goto _lbl_01F74F8C;
_lbl_01F74F88:
    r_s1 = (long)(0 | 0);
_lbl_01F74F8C:
    if (r_s1 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F75038; }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (2188)); }
    if (r_a0 == 0) goto _lbl_01F75034;
    if (r_s5) { r_t1 = *(int *)((char *)r_s5 + (12)); }
    if (r_s5) { r_a3 = *(int *)((char *)r_s5 + (20)); }
    if (r_a1) { r_a2 = *(int *)((char *)r_a1 + (2108)); }
    if (r_s5) { r_t2 = *(int *)((char *)r_s5 + (2196)); }
    if (r_s5) { r_t0 = *(int *)((char *)r_s5 + (2232)); }
    r_a3 = (long)(r_t1 + r_a3);
    r_t2 = (long)(r_a2 + r_t2);
    r_a3 = (long)(r_a3 - r_t0);
    r_at = (long)((long)r_t2 < (long)r_a3 ? 1 : 0);
    if (r_at == 0) { r_s4 = (long)(r_a1 + (0x83c)); goto _lbl_01F75034; }
    r_s4 = (long)(r_a1 + (0x83c));
    if (r_a1) { r_a3 = *(int *)((char *)r_a1 + (2112)); }
    r_s3 = (long)(r_a1 + (0x840));
    if (r_s5) { r_t2 = *(int *)((char *)r_s5 + (2192)); }
    if (r_s5) { r_t1 = *(int *)((char *)r_s5 + (16)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (24)); }
    r_t2 = (long)(r_a3 + r_t2);
    r_a1 = (long)(r_t1 + r_a1);
    r_a1 = (long)(r_a1 - r_t0);
    r_at = (long)((long)r_t2 < (long)r_a1 ? 1 : 0);
    if (r_at == 0) goto _lbl_01F75034;
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (32)); }
    r_v1 = (long)((unsigned long)r_v1 << (1));
    r_t0 = (long)(r_v0 + r_v1);
    r_t1 = (long)(0 | 0);
    r_v0 = (long)func_0025E640((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (0)); }
    if (r_s4) { r_a2 = *(int *)((char *)r_s4 + (0)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (32)); }
    r_a0 = (long)(r_s1 | 0);
    r_t1 = (long)(0 | 0);
    if (r_v0) { r_t0 = *(int *)((char *)r_v0 + (16)); }
    r_a2 = (long)(r_a2 + r_s8);
    r_a3 = (long)(r_v1 + r_s7);
    r_v0 = (long)func_0025E640((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75034:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F75038:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2092)); }
_lbl_01F7503C:
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (2)); goto _lbl_01F74E68; }
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F75048:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001AB9D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75050:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001ABA00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F75158;
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (2088)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_s4 = (long)(0 | 0); goto _lbl_01F75150; }
    r_s4 = (long)(0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2092)); }
    goto _lbl_01F75144;
_lbl_01F75078:
    r_v0 = (long)(r_v0 + r_s4);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_s0 = (long)(r_s5 + r_v0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (2104)); }
    if (r_v0 == 0) { r_s3 = (long)(r_s0 + (0x838)); goto _lbl_01F7513C; }
    r_s3 = (long)(r_s0 + (0x838));
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2216)); }
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_v0 = (long)func_00185E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (32)); }
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (56)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)func_002257A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2112)); }
    r_s6 = (long)(r_v0 | 0);
    if (r_s5) { r_v1 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)(0xff << 16);
    r_a1 = (long)(r_v0 | (0xffff));
    if (r_s0) { r_a2 = *(int *)((char *)r_s0 + (2108)); }
    r_v0 = (long)(r_a0 + (0x21));
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (56)); }
    r_s1 = (long)(r_v0 + r_s2);
    r_s0 = (long)(r_a2 + (2));
    r_v0 = (long)func_00225820((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s0 + (-0x32));
    if (r_sp) { *(int *)((char *)r_sp + (160)) = (int)r_v0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (160)); }
    r_a0 = (long)(r_sp + (0xac));
    r_v0 = (long)(0 + (0x3c));
    r_v1 = (long)(r_v1 + (0xae));
    if (r_sp) { *(int *)((char *)r_sp + (168)) = (int)r_v1; }
    if (r_sp) { *(int *)((char *)r_sp + (164)) = (int)r_s1; }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
    if (r_a0) { *(int *)((char *)r_a0 + (0)) = (int)r_v0; }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (0)); }
    r_a0 = (long)(r_v0 + (0x8c));
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_v0 | 0);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (32)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0)); }
    r_a3 = (long)(r_sp + (0xa0));
    r_t0 = (long)(0 + (1));
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (56)); }
    r_a1 = (long)(r_v1 + (0x8c));
    r_v0 = (long)func_00225BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (32)); }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (56)); }
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_002257A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F7513C:
    r_s4 = (long)(r_s4 + (1));
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (2092)); }
_lbl_01F75144:
    r_v0 = (long)((long)r_s4 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s4 << (2)); goto _lbl_01F75078; }
    r_v0 = (long)((unsigned long)r_s4 << (2));
_lbl_01F75150:
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (32)); }
    r_v0 = (long)func_001ABA70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75158:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
_lbl_01F7515C:
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0xb0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 64: thelp_func_01F75188 (VMA: 0x01F75188, size: 40 bytes) */
void *thelp_func_01F75188(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2228)); }
    r_a3 = (long)(0 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (464)) = (int)r_a3; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2228)); }
    if (r_v1) { *(int *)((char *)r_v1 + (468)) = (int)r_a1; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (2228)); }
    if (r_v1) { *(int *)((char *)r_v1 + (472)) = (int)r_a2; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 65: thelp_func_01F751B0 (VMA: 0x01F751B0, size: 92 bytes) */
void *thelp_func_01F751B0(void *a0, void *a1, void *a2, void *a3) {
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
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_sp) { *(int *)((char *)r_sp + (44)) = (int)r_a0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (44)); }
    r_s0 = (long)(r_a1 | 0);
    r_v0 = (long)(0x1f8 << 16);
    r_a1 = (long)(r_v0 + (-0x6998));
    r_v0 = (long)func_0020BAF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0x4e << 16);
    r_v1 = (long)(r_v0 + (0x20e0));
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (44)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0)) = (int)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (44)); }
    if (r_v0) { *(int *)((char *)r_v0 + (2088)) = (int)0; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (44)); }
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F75300((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (44)); }
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 66: thelp_func_01F7520C (VMA: 0x01F7520C, size: 112 bytes) */
void *thelp_func_01F7520C(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_s1 == 0) { r_s0 = (long)(r_a1 | 0); goto _lbl_01F75264; }
    r_s0 = (long)(r_a1 | 0);
    r_v0 = (long)(0x4e << 16);
    r_v0 = (long)(r_v0 + (0x20e0));
    r_a1 = (long)(r_s1 + (0x828));
    if (r_s1) { *(int *)((char *)r_s1 + (0)) = (int)r_v0; }
    r_v0 = (long)func_001F6E00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_0020BE60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 <= 0) { r_v0 = (long)(r_s1 | 0); goto _lbl_01F75268; }
    r_v0 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75264:
    r_v0 = (long)(r_s1 | 0);
_lbl_01F75268:
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 67: thelp_func_01F7527C (VMA: 0x01F7527C, size: 292 bytes) */
void *thelp_func_01F7527C(void *a0, void *a1, void *a2, void *a3) {
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
    r_sp = (long)(r_sp + (-0x70));
    /* unhandled: subu.qb $zero $sp $s3 */
    /* unhandled: ext $s2 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s1 */
    r_s3 = (long)(r_a1 | 0);
    r_s0 = (long)(r_a0 | 0);
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_001F6DF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_001F8E60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_001F8E70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a3 = (long)(0 + (0x1db));
    r_t0 = (long)(0 + (0x15e));
    r_t3 = (long)(0 + (1));
    r_a1 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s3 | 0);
    r_t1 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_t2 = (long)(r_v0 | 0);
    r_v0 = (long)func_0020BB50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_v0 = (long)(0 + (2)); goto _lbl_01F752F8; }
    r_v0 = (long)(0 + (2));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F75384;
    r_v0 = (long)(0 + (2));
_lbl_01F752F8:
    r_v0 = (long)(0 + (1));
    if (r_s0) { r_t9 = *(int *)((char *)r_s0 + (0)); }
    r_t0 = (long)(0 + (8));
    r_a2 = (long)(r_s0 + (0x828));
    r_t2 = (long)(0 + (0x1cb));
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (296)); }
    r_t3 = (long)(0 + (0x12c));
    r_a0 = (long)(r_s0 | 0);
    r_a1 = (long)(r_s0 | 0);
    r_a3 = (long)(0 | 0);
    r_t1 = (long)(r_t0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_v0 != 0) goto _lbl_01F75350;
    r_v0 = (long)(0 + (1));
    if (r_s0) { *(int *)((char *)r_s0 + (244)) = (int)r_v0; }
    r_v0 = (long)(0 | 0);
    goto _lbl_01F75384;
_lbl_01F75350:
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2088)); }
    r_v0 = (long)(0xff << 16);
    r_a1 = (long)(r_v0 | (0xffff));
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_002178E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2088)); }
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_002178A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (2088)); }
    r_a1 = (long)(0 + (1));
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_001F6850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01F75384:
    /* unhandled: ld.b $w1 -0x41($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w19 */
    /* unhandled: xori.b $w1 $w0 0xb2 */
    /* unhandled: ld.b $w0 -0x50($zero) */
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 68: thelp_func_01F753A0 (VMA: 0x01F753A0, size: 544 bytes) */
void *thelp_func_01F753A0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t9 = 0;
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
    (void)r_t9;
    r_sp = (long)(r_sp + (-0xa0));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s2 = (long)(r_a0 | 0);
    if (r_s2) { r_t9 = *(int *)((char *)r_s2 + (0)); }
    r_s3 = (long)(r_a1 | 0);
    r_a1 = (long)(0 + (1));
    r_s1 = (long)(r_a2 | 0);
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (28)); }
    r_s0 = (long)(r_a3 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2088)); }
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(0 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (268)); }
    r_a3 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (64)); }
    if (r_v1 == 0) goto _lbl_01F75590;
    if (r_gp) { r_a0 = *(int *)((char *)r_gp + (-30272)); }
    r_a1 = (long)(0 + (2));
    r_v0 = (long)func_00185E20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (8)); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2088)); }
    r_s3 = (long)(r_v0 + (2));
    r_v0 = (long)func_002193D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (64)); }
    r_s3 = (long)(r_s8 + (0x10));
    r_v0 = (long)func_001F6DB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (64)); }
    r_s4 = (long)(r_v0 | 0);
    r_v0 = (long)func_001F6DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (64)); }
    r_s5 = (long)(r_v0 | 0);
    r_v0 = (long)func_001F6DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (64)); }
    r_s6 = (long)(r_v0 | 0);
    r_v0 = (long)func_001F6DE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    r_v1 = (long)(r_s4 + r_s6);
    r_v0 = (long)(r_s1 + (0x1f8));
    r_v0 = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(r_s1 + (-0x1e0)); goto _lbl_01F75494; }
    r_v0 = (long)(r_s1 + (-0x1e0));
    r_v0 = (long)(r_s1 + (5));
    r_a0 = (long)(r_s4 - r_v0);
    r_v0 = (long)func_00114308((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    goto _lbl_01F754BC;
    r_v0 = (long)(r_s1 + (-0x1e0));
_lbl_01F75494:
    r_v1 = (long)(r_s4 + (0x18));
    r_at = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_at != 0) { r_v0 = (long)((long)r_s6 >> (1)); goto _lbl_01F754B8; }
    r_a0 = (long)(r_v0 - r_s4);
    r_v0 = (long)func_00114308((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    goto _lbl_01F754BC;
    r_v0 = (long)((long)r_s6 >> (1));
_lbl_01F754B8:
    r_s1 = (long)(r_v0 + (-0xed));
_lbl_01F754BC:
    if ((long)r_s1 >= 0) { r_v0 = (long)(r_s0 + (-0x25)); goto _lbl_01F754CC; }
    r_v0 = (long)(r_s0 + (-0x25));
    r_s1 = (long)(0 | 0);
    r_v0 = (long)(r_s0 + (-0x25));
_lbl_01F754CC:
    r_v0 = (long)(r_v0 - r_s3);
    r_at = (long)((long)r_v0 < (long)r_s5 ? 1 : 0);
    if (r_at != 0) { r_v0 = (long)(r_s0 + (0x25)); goto _lbl_01F754F8; }
    r_v0 = (long)(r_s0 + (0x25));
    r_v0 = (long)(r_s0 + (-5));
    r_v0 = (long)(r_v0 - r_s3);
    r_a0 = (long)(r_v0 - r_s5);
    r_v0 = (long)func_00114308((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F7552C;
    r_v0 = (long)(r_s0 + (0x25));
_lbl_01F754F8:
    r_v1 = (long)(r_v0 + r_s3);
    r_v0 = (long)(r_s5 + r_s7);
    r_at = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_at != 0) { r_v1 = (long)((long)r_s7 >> (1)); goto _lbl_01F75524; }
    r_v1 = (long)((long)r_s7 >> (1));
    r_v0 = (long)(r_s0 + (5));
    r_a0 = (long)(r_v0 - r_s5);
    r_v0 = (long)func_00114308((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F7552C;
    r_v1 = (long)((long)r_s7 >> (1));
_lbl_01F75524:
    r_v0 = (long)((long)r_s3 >> (1));
    r_v0 = (long)(r_v1 - r_v0);
_lbl_01F7552C:
    if ((long)r_v0 >= 0) goto _lbl_01F75538;
    r_v0 = (long)(0 | 0);
_lbl_01F75538:
    if (r_s2) { r_t9 = *(int *)((char *)r_s2 + (0)); }
    r_a3 = (long)(0 + (0x1db));
    r_a1 = (long)(r_s1 | 0);
    r_a2 = (long)(r_v0 | 0);
    r_t0 = (long)(r_s3 | 0);
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a0 = (long)(r_s2 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (2088)); }
    r_a1 = (long)(0 + (8));
    r_a3 = (long)(0 + (0x1cb));
    r_t0 = (long)(r_s8 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (36)); }
    r_a2 = (long)(r_a1 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (64)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (60)); }
    if (r_s2) { *(int *)((char *)r_s2 + (2056)) = (int)r_v0; }
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (64)); }
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_001F6750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75590:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0xa0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 69: thelp_func_01F755C0 (VMA: 0x01F755C0, size: 92 bytes) */
void *thelp_func_01F755C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_t0 = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_t0;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x20));
    /* unhandled: addu.qb $zero $sp $ra */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (132)); }
    if (r_v0 != 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01F755E0; }
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F7560C;
_lbl_01F755E0:
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (2056)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (64)); }
    r_v0 = (long)func_001F6750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (64)); }
    r_a1 = (long)(r_s0 | 0);
    r_a2 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (208)); }
    r_t0 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F7560C:
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 70: thelp_func_01F7561C (VMA: 0x01F7561C, size: 268 bytes) */
void *thelp_func_01F7561C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0, r_t9 = 0;
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
    (void)r_t0;
    (void)r_t1;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x170));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (132)); }
    r_s4 = (long)(r_a1 | 0);
    r_s3 = (long)(r_a2 | 0);
    r_s2 = (long)(r_a3 | 0);
    r_s1 = (long)(r_t0 | 0);
    r_s0 = (long)(r_t1 | 0);
    if (r_v0 != 0) { r_s5 = (long)(r_a0 | 0); goto _lbl_01F75668; }
    r_s5 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F75704;
_lbl_01F75668:
    if (r_s4 == 0) { r_a0 = (long)(r_s5 | 0); goto _lbl_01F756EC; }
    r_a0 = (long)(r_s5 | 0);
    r_a0 = (long)(r_sp + (0x70));
    r_v0 = (long)func_0036DDF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(unsigned char *)((char *)r_sp + (266)); }
    if (r_v0 == 0) goto _lbl_01F756B4;
    r_v0 = (long)(0 + (0x26));
    if (r_s4 == r_v0) goto _lbl_01F756E8;
    r_v0 = (long)(0 + (0x28));
    if (r_s4 == r_v0) goto _lbl_01F756E8;
    r_v0 = (long)(0 + (0x25));
    if (r_s4 == r_v0) goto _lbl_01F756E8;
    r_v0 = (long)(0 + (0x27));
    if (r_s4 == r_v0) goto _lbl_01F756E8;
_lbl_01F756B4:
    if (r_s5) { r_a1 = *(int *)((char *)r_s5 + (2056)); }
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (64)); }
    r_v0 = (long)func_001F6750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5) { r_a0 = *(int *)((char *)r_s5 + (64)); }
    r_a1 = (long)(r_s5 | 0);
    r_a2 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (0)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (208)); }
    r_t0 = (long)(0 | 0);
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    /* unhandled: ld.b $w1 -0x41($zero) */
    goto _lbl_01F75708;
_lbl_01F756E8:
    r_a0 = (long)(r_s5 | 0);
_lbl_01F756EC:
    r_a1 = (long)(r_s4 | 0);
    r_a2 = (long)(r_s3 | 0);
    r_a3 = (long)(r_s2 | 0);
    r_t0 = (long)(r_s1 | 0);
    r_t1 = (long)(r_s0 | 0);
    r_v0 = (long)func_001F55C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75704:
    /* unhandled: ld.b $w1 -0x41($zero) */
_lbl_01F75708:
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x170));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 71: thelp_func_01F75728 (VMA: 0x01F75728, size: 140 bytes) */
void *thelp_func_01F75728(void *a0, void *a1, void *a2, void *a3) {
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
    r_s1 = (long)(r_a0 | 0);
    r_a0 = (long)(0 + (0x6b08));
    /* unhandled: ext $s0 $sp 0 1 */
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01F75760; }
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_002D2AA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75760:
    r_a0 = (long)(0 + (0x34));
    if (r_s1) { *(int *)((char *)r_s1 + (5960)) = (int)r_s0; }
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01F75780; }
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_01F759E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75780:
    r_a0 = (long)(0 + (0xc));
    if (r_s1) { *(int *)((char *)r_s1 + (5956)) = (int)r_s0; }
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01F7579C; }
    r_s0 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_001AED20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F7579C:
    if (r_s1) { *(int *)((char *)r_s1 + (5964)) = (int)r_s0; }
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 72: thelp_func_01F757B4 (VMA: 0x01F757B4, size: 96 bytes) */
void *thelp_func_01F757B4(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a0 | 0);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (5956)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_01F75F60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (5960)); }
    r_a1 = (long)(0 + (1));
    r_v0 = (long)func_002D2D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (5964)); }
    if (r_a0 == 0) goto _lbl_01F75804;
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (8)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (8)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F75804:
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 73: thelp_func_01F75814 (VMA: 0x01F75814, size: 88 bytes) */
void *thelp_func_01F75814(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a1 | 0);
    r_v0 = (long)func_0036C320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (1));
    r_v0 = (long)func_0036C2D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 | 0);
    r_a1 = (long)(0 | 0);
    r_a2 = (long)(0 | 0);
    r_v0 = (long)func_0032F1F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (5968)) = (int)r_v0; }
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 74: thelp_func_01F7586C (VMA: 0x01F7586C, size: 60 bytes) */
void *thelp_func_01F7586C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t9 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t9;
    r_sp = (long)(r_sp + (-0x10));
    /* unhandled: ext $ra $sp 0 1 */
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (5968)); }
    if (r_a0 == 0) goto _lbl_01F75894;
    if (r_a0) { r_t9 = *(int *)((char *)r_a0 + (44)); }
    if (r_t9) { r_t9 = *(int *)((char *)r_t9 + (8)); }
    r_a1 = (long)(0 + (1));
    if (r_t9) { r_v0 = (long)((void *(*)(void *, ...))r_t9)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
_lbl_01F75894:
    r_v0 = (long)func_0036C3A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: xori.b $w0 $w0 0xbf */
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 75: thelp_func_01F758A8 (VMA: 0x01F758A8, size: 180 bytes) */
void *thelp_func_01F758A8(void *a0, void *a1, void *a2, void *a3) {
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
    r_s2 = (long)(r_a0 | 0);
    /* unhandled: addu.qb $zero $sp $s1 */
    r_a0 = (long)(0 + (0x34));
    r_s1 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_v0 = (long)func_00100850((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_v0 | 0); goto _lbl_01F758EC; }
    r_s0 = (long)(r_v0 | 0);
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (5956)); }
    r_a0 = (long)(r_s0 | 0);
    r_a2 = (long)(r_a1 | 0);
    r_v0 = (long)func_01F75A40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F758EC:
    if (r_s0) { *(int *)((char *)r_s0 + (32)) = (int)r_s1; }
    if (r_s2) { r_a1 = *(int *)((char *)r_s2 + (5960)); }
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (5964)); }
    if (r_s2) { r_a3 = *(int *)((char *)r_s2 + (5968)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F794C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F76D80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (1));
    if (r_v0 != r_v1) { r_v0 = (long)(0 | 0); goto _lbl_01F75938; }
    r_v0 = (long)(0 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F776B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F771D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s0 | 0);
    goto _lbl_01F75944;
    r_v0 = (long)(0 | 0);
_lbl_01F75938:
    goto _lbl_01F75948;
    r_v0 = (long)(r_s0 | 0);
_lbl_01F75944:
_lbl_01F75948:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 76: thelp_func_01F7595C (VMA: 0x01F7595C, size: 88 bytes) */
void *thelp_func_01F7595C(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (12)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (20)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (28)) = (int)0; }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)0; }
    if (r_a0) { *(char *)((char *)r_a0 + (8)) = (char)0; }
    if (r_a0) { *(char *)((char *)r_a0 + (16)) = (char)0; }
    r_v0 = (long)(0 + (-1));
    if (r_a0) { *(char *)((char *)r_a0 + (24)) = (char)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (32)) = (int)r_v0; }
    r_s0 = (long)(r_a0 | 0);
    if (r_a0) { *(int *)((char *)r_a0 + (36)) = (int)0; }
    r_v0 = (long)func_01F761D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s0 | 0);
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 77: thelp_func_01F759B4 (VMA: 0x01F759B4, size: 1316 bytes) */
void *thelp_func_01F759B4(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (12)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (20)) = (int)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (28)) = (int)0; }
    if (r_a0) { *(char *)((char *)r_a0 + (0)) = (char)0; }
    if (r_a0) { *(char *)((char *)r_a0 + (8)) = (char)0; }
    if (r_a0) { *(char *)((char *)r_a0 + (16)) = (char)0; }
    r_v0 = (long)(0 + (-1));
    if (r_a0) { *(char *)((char *)r_a0 + (24)) = (char)0; }
    if (r_a0) { *(int *)((char *)r_a0 + (32)) = (int)r_v0; }
    r_s0 = (long)(r_a1 | 0);
    r_s1 = (long)(r_a0 | 0);
    if (r_s0 != 0) { if (r_a0) { *(int *)((char *)r_a0 + (36)) = (int)0; } goto _lbl_01F75A18; }
    if (r_a0) { *(int *)((char *)r_a0 + (36)) = (int)0; }
    r_v0 = (long)(r_s1 | 0);
    goto _lbl_01F75EBC;
_lbl_01F75A18:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (0)); }
    if (r_s1) { *(char *)((char *)r_s1 + (0)) = (char)r_v0; }
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (8)); }
    if (r_s1) { *(char *)((char *)r_s1 + (8)) = (char)r_v0; }
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (16)); }
    if (r_s1) { *(char *)((char *)r_s1 + (16)) = (char)r_v0; }
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (24)); }
    if (r_s1) { *(char *)((char *)r_s1 + (24)) = (char)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (32)); }
    if (r_s1) { *(int *)((char *)r_s1 + (32)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (36)); }
    if (r_s1) { *(int *)((char *)r_s1 + (36)) = (int)r_v0; }
    if (r_s1) { r_a0 = *(unsigned char *)((char *)r_s1 + (0)); }
    r_a1 = (long)(0 + (0x90));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (4)) = (int)r_v0; }
    if (r_s1) { r_a0 = *(unsigned char *)((char *)r_s1 + (8)); }
    r_a1 = (long)(0 + (0x88));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (12)) = (int)r_v0; }
    if (r_s1) { r_a0 = *(unsigned char *)((char *)r_s1 + (16)); }
    r_a1 = (long)(0 + (0x7c));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (20)) = (int)r_v0; }
    if (r_s1) { r_a0 = *(unsigned char *)((char *)r_s1 + (24)); }
    r_a1 = (long)(0 + (0x84));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (28)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (0)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (4)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (4)); }
    r_v0 = (long)((unsigned long)r_v1 << (3));
    r_v0 = (long)(r_v0 + r_v1);
    r_a2 = (long)((unsigned long)r_v0 << (4));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(0 | 0);
    goto _lbl_01F75BAC;
    r_v0 = (long)((unsigned long)r_s2 << (3));
_lbl_01F75AB0:
    r_v1 = (long)(r_v0 + r_s2);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (4)); }
    r_s3 = (long)((unsigned long)r_v1 << (4));
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (12)); }
    if ((long)r_v0 <= 0) goto _lbl_01F75B08;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (4)); }
    r_v1 = (long)(r_v1 + r_s3);
    if (r_v1) { *(int *)((char *)r_v1 + (16)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (4)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a0 = (long)(r_v1 + r_s3);
    r_v1 = (long)(r_v0 + r_s3);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (12)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (16)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (16)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75B08:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (4)); }
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (20)); }
    if ((long)r_v0 <= 0) goto _lbl_01F75B58;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (4)); }
    r_v1 = (long)(r_v1 + r_s3);
    if (r_v1) { *(int *)((char *)r_v1 + (24)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (4)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a0 = (long)(r_v1 + r_s3);
    r_v1 = (long)(r_v0 + r_s3);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (20)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (24)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (24)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75B58:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (4)); }
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (28)); }
    /* unhandled: blezl $v0 0x1f75bac */
    r_s2 = (long)(r_s2 + (1));
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (4)); }
    r_v1 = (long)(r_v1 + r_s3);
    if (r_v1) { *(int *)((char *)r_v1 + (32)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (4)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a0 = (long)(r_v1 + r_s3);
    r_v1 = (long)(r_v0 + r_s3);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (28)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (32)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (32)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s2 + (1));
_lbl_01F75BAC:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (0)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (3)); goto _lbl_01F75AB0; }
    r_v0 = (long)((unsigned long)r_s2 << (3));
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (8)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (12)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (12)); }
    r_v0 = (long)((unsigned long)r_v1 << (4));
    r_v0 = (long)(r_v0 + r_v1);
    r_a2 = (long)((unsigned long)r_v0 << (3));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(0 | 0);
    goto _lbl_01F75CE0;
    r_v0 = (long)((unsigned long)r_s3 << (4));
_lbl_01F75BE4:
    r_v1 = (long)(r_v0 + r_s3);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    r_s2 = (long)((unsigned long)r_v1 << (3));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (16)); }
    if ((long)r_v0 <= 0) goto _lbl_01F75C3C;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (20)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a0 = (long)(r_v1 + r_s2);
    r_v1 = (long)(r_v0 + r_s2);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (16)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (20)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (20)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75C3C:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (24)); }
    if ((long)r_v0 <= 0) goto _lbl_01F75C8C;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a0 = (long)(r_v1 + r_s2);
    r_v1 = (long)(r_v0 + r_s2);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (24)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (28)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (28)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75C8C:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (32)); }
    /* unhandled: blezl $v0 0x1f75ce0 */
    r_s3 = (long)(r_s3 + (1));
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (36)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a0 = (long)(r_v1 + r_s2);
    r_v1 = (long)(r_v0 + r_s2);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (32)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (36)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (36)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F75CE0:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (8)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (4)); goto _lbl_01F75BE4; }
    r_v0 = (long)((unsigned long)r_s3 << (4));
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (16)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (20)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (20)); }
    r_v0 = (long)((unsigned long)r_v1 << (5));
    r_v0 = (long)(r_v0 - r_v1);
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(0 | 0);
    goto _lbl_01F75D74;
    r_v0 = (long)((unsigned long)r_s3 << (5));
_lbl_01F75D18:
    r_v0 = (long)(r_v0 - r_s3);
    r_s2 = (long)((unsigned long)r_v0 << (2));
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (20)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (24)); }
    /* unhandled: blezl $v0 0x1f75d74 */
    r_s3 = (long)(r_s3 + (1));
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (20)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (20)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a0 = (long)(r_v1 + r_s2);
    r_v1 = (long)(r_v0 + r_s2);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (24)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (28)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (28)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F75D74:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (16)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (5)); goto _lbl_01F75D18; }
    r_v0 = (long)((unsigned long)r_s3 << (5));
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (24)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (28)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (28)); }
    r_v0 = (long)((unsigned long)r_v1 << (5));
    r_v0 = (long)(r_v0 + r_v1);
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(0 | 0);
    goto _lbl_01F75EA8;
    r_v0 = (long)((unsigned long)r_s3 << (5));
_lbl_01F75DAC:
    r_v1 = (long)(r_v0 + r_s3);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (28)); }
    r_s2 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (16)); }
    if ((long)r_v0 <= 0) goto _lbl_01F75E04;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (28)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (20)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (28)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a0 = (long)(r_v1 + r_s2);
    r_v1 = (long)(r_v0 + r_s2);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (16)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (20)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (20)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75E04:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (28)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (24)); }
    if ((long)r_v0 <= 0) goto _lbl_01F75E54;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (28)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (28)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a0 = (long)(r_v1 + r_s2);
    r_v1 = (long)(r_v0 + r_s2);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (24)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (28)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (28)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75E54:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (28)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (32)); }
    /* unhandled: blezl $v0 0x1f75ea8 */
    r_s3 = (long)(r_s3 + (1));
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (28)); }
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (36)) = (int)r_v0; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (28)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a0 = (long)(r_v1 + r_s2);
    r_v1 = (long)(r_v0 + r_s2);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (32)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (36)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (36)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00117AF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F75EA8:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (24)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (5)); goto _lbl_01F75DAC; }
    r_v0 = (long)((unsigned long)r_s3 << (5));
    r_v0 = (long)(r_s1 | 0);
_lbl_01F75EBC:
    /* unhandled: xori.b $w1 $w0 0xbf */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 78: thelp_func_01F75ED8 (VMA: 0x01F75ED8, size: 620 bytes) */
void *thelp_func_01F75ED8(void *a0, void *a1, void *a2, void *a3) {
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
    r_s1 = (long)(r_a0 | 0);
    if (r_s1 == 0) { r_s0 = (long)(r_a1 | 0); goto _lbl_01F76124; }
    r_s0 = (long)(r_a1 | 0);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (4)); }
    if (r_v0 == 0) goto _lbl_01F75F94;
    r_s2 = (long)(0 | 0);
    goto _lbl_01F75F7C;
    r_v0 = (long)((unsigned long)r_s2 << (3));
_lbl_01F75F1C:
    r_v1 = (long)(r_v0 + r_s2);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (4)); }
    r_s3 = (long)((unsigned long)r_v1 << (4));
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (16)); }
    if (r_a0 == 0) goto _lbl_01F75F40;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75F40:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (4)); }
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (24)); }
    if (r_a0 == 0) goto _lbl_01F75F5C;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75F5C:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (4)); }
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (32)); }
    if (r_a0 == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F75F7C; }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s2 + (1));
_lbl_01F75F7C:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (0)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (3)); goto _lbl_01F75F1C; }
    r_v0 = (long)((unsigned long)r_s2 << (3));
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (4)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75F94:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    if (r_v0 == 0) goto _lbl_01F76024;
    r_s3 = (long)(0 | 0);
    goto _lbl_01F7600C;
    r_v0 = (long)((unsigned long)r_s3 << (4));
_lbl_01F75FAC:
    r_v1 = (long)(r_v0 + r_s3);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    r_s2 = (long)((unsigned long)r_v1 << (3));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (20)); }
    if (r_a0 == 0) goto _lbl_01F75FD0;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75FD0:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (28)); }
    if (r_a0 == 0) goto _lbl_01F75FEC;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F75FEC:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (36)); }
    if (r_a0 == 0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F7600C; }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F7600C:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (8)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (4)); goto _lbl_01F75FAC; }
    r_v0 = (long)((unsigned long)r_s3 << (4));
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (12)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76024:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (20)); }
    if (r_v0 == 0) goto _lbl_01F7607C;
    r_s2 = (long)(0 | 0);
    goto _lbl_01F76064;
    r_v0 = (long)((unsigned long)r_s2 << (5));
_lbl_01F7603C:
    r_v0 = (long)(r_v0 - r_s2);
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (20)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (28)); }
    if (r_a0 == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F76064; }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s2 + (1));
_lbl_01F76064:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (16)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (5)); goto _lbl_01F7603C; }
    r_v0 = (long)((unsigned long)r_s2 << (5));
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (20)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F7607C:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (28)); }
    if (r_v0 == 0) goto _lbl_01F76110;
    r_s3 = (long)(0 | 0);
    goto _lbl_01F760F4;
    r_v0 = (long)((unsigned long)r_s3 << (5));
_lbl_01F76094:
    r_v1 = (long)(r_v0 + r_s3);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (28)); }
    r_s2 = (long)((unsigned long)r_v1 << (2));
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (20)); }
    if (r_a0 == 0) goto _lbl_01F760B8;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F760B8:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (28)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (28)); }
    if (r_a0 == 0) goto _lbl_01F760D4;
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F760D4:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (28)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (36)); }
    if (r_a0 == 0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F760F4; }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F760F4:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (24)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (5)); goto _lbl_01F76094; }
    r_v0 = (long)((unsigned long)r_s3 << (5));
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (28)); }
    r_v0 = (long)func_00116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76110:
    if ((long)r_v0 <= 0) { r_v0 = (long)(r_s1 | 0); goto _lbl_01F76128; }
    r_v0 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00100670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76124:
    r_v0 = (long)(r_s1 | 0);
_lbl_01F76128:
    /* unhandled: xori.b $w1 $w0 0xbf */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 79: thelp_func_01F76144 (VMA: 0x01F76144, size: 2580 bytes) */
void *thelp_func_01F76144(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x50));
    /* unhandled: ext $ra $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)(0x39 << 16);
    r_a0 = (long)(r_v0 + (0x2980));
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0)); }
    r_a2 = (long)(0 + (1));
    r_v0 = (long)func_00226B40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_s0 | 0);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + (8));
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + (0x10));
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + (0x18));
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7e00($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f761ec */
    r_a1 = (long)(r_s0 + (0x24));
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(unsigned char *)((char *)r_s0 + (0)); }
    r_a1 = (long)(0 + (0x90));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (4)) = (int)r_v0; }
    r_s2 = (long)(0 | 0);
    goto _lbl_01F76438;
    r_v0 = (long)((unsigned long)r_s2 << (3));
_lbl_01F76208:
    r_v1 = (long)(r_v0 + r_s2);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_s3 = (long)((unsigned long)r_v1 << (4));
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_v0 + r_s3);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (4));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7dfc($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76374 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (0xc));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (12)); }
    if ((long)r_v0 <= 0) goto _lbl_01F762B4;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (4)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s3);
    if (r_v1) { *(int *)((char *)r_v1 + (16)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_v1 = (long)(r_v0 + r_s3);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (12)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (16)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F762B4:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (0x14));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (20)); }
    if ((long)r_v0 <= 0) goto _lbl_01F76314;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (4)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s3);
    if (r_v1) { *(int *)((char *)r_v1 + (24)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_v1 = (long)(r_v0 + r_s3);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (20)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (24)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76314:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (0x1c));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_v0 = (long)(r_v0 + r_s3);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (28)); }
    if ((long)r_v0 <= 0) goto _lbl_01F76374;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (4)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s3);
    if (r_v1) { *(int *)((char *)r_v1 + (32)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_v1 = (long)(r_v0 + r_s3);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (28)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (32)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76374:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (0x54));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (0x24));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7e00($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76404 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (0x78));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (0xa));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (0x79));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (0xa));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (0x83));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (0x8d));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7df8($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1tl 0x1f76438 */
    r_s2 = (long)(r_s2 + (1));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s3);
    r_a1 = (long)(r_v0 + (8));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s2 + (1));
_lbl_01F76438:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (0)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (3)); goto _lbl_01F76208; }
    r_v0 = (long)((unsigned long)r_s2 << (3));
    if (r_s0) { r_a0 = *(unsigned char *)((char *)r_s0 + (8)); }
    r_a1 = (long)(0 + (0x88));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (12)) = (int)r_v0; }
    r_s3 = (long)(0 | 0);
    goto _lbl_01F766C4;
    r_v0 = (long)((unsigned long)r_s3 << (4));
_lbl_01F76464:
    r_v1 = (long)(r_v0 + r_s3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_s2 = (long)((unsigned long)r_v1 << (3));
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_v0 + r_s2);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (8));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7dfc($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f765d0 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x10));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (16)); }
    if ((long)r_v0 <= 0) goto _lbl_01F76510;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (12)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (20)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (16)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (20)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76510:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x18));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (24)); }
    if ((long)r_v0 <= 0) goto _lbl_01F76570;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (12)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (24)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (28)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76570:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x20));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (32)); }
    if ((long)r_v0 <= 0) goto _lbl_01F765D0;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (12)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (36)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (32)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (36)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F765D0:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (0x54));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x28));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7e00($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76630 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x7c));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (5));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x7d));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7df4($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76660 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (5));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x82));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7df8($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76690 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0xc));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7df0($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1tl 0x1f766c4 */
    r_s3 = (long)(r_s3 + (1));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (4));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F766C4:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (8)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (4)); goto _lbl_01F76464; }
    r_v0 = (long)((unsigned long)r_s3 << (4));
    if (r_s0) { r_a0 = *(unsigned char *)((char *)r_s0 + (16)); }
    r_a1 = (long)(0 + (0x7c));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (20)) = (int)r_v0; }
    r_s3 = (long)(0 | 0);
    goto _lbl_01F768C8;
    r_v0 = (long)((unsigned long)r_s3 << (5));
_lbl_01F766F0:
    r_v0 = (long)(r_v0 - r_s3);
    r_s2 = (long)((unsigned long)r_v0 << (2));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_v0 + r_s2);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (8));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x10));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (0x54));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x20));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7e00($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f767fc */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x74));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7dfc($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f767fc */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x18));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (24)); }
    if ((long)r_v0 <= 0) goto _lbl_01F767FC;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (20)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (24)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (28)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F767FC:
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7dec($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f7682c */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x78));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    r_v0 = (long)(0x4118 << 16);
    /* unhandled: mtc1 $v0 $f0 */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76864 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x14));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7df8($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76894 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0xc));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7df0($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1tl 0x1f768c8 */
    r_s3 = (long)(r_s3 + (1));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (4));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F768C8:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (16)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (5)); goto _lbl_01F766F0; }
    r_v0 = (long)((unsigned long)r_s3 << (5));
    if (r_s0) { r_a0 = *(unsigned char *)((char *)r_s0 + (24)); }
    r_a1 = (long)(0 + (0x84));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (28)) = (int)r_v0; }
    r_s3 = (long)(0 | 0);
    goto _lbl_01F76B24;
    r_v0 = (long)((unsigned long)r_s3 << (5));
_lbl_01F768F4:
    r_v1 = (long)(r_v0 + r_s3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_s2 = (long)((unsigned long)r_v1 << (2));
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_v0 + r_s2);
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (4));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0xc));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7dfc($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76a78 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x10));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (16)); }
    if ((long)r_v0 <= 0) goto _lbl_01F769B8;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (28)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (20)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (16)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (20)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F769B8:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x18));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (24)); }
    if ((long)r_v0 <= 0) goto _lbl_01F76A18;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (28)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (28)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (24)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (28)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76A18:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (1));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x20));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_v0 = (long)(r_v0 + r_s2);
    if (r_v0) { r_v0 = *(unsigned char *)((char *)r_v0 + (32)); }
    if ((long)r_v0 <= 0) goto _lbl_01F76A78;
    r_a1 = (long)(0 + (4));
    r_a0 = (long)(r_v0 & (0xff));
    r_v0 = (long)func_001143F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (28)); }
    r_a0 = (long)(r_s1 | 0);
    r_v1 = (long)(r_v1 + r_s2);
    if (r_v1) { *(int *)((char *)r_v1 + (36)) = (int)r_v0; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_v1 = (long)(r_v0 + r_s2);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (32)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (36)); }
    r_a2 = (long)((unsigned long)r_v0 << (2));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76A78:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (0x54));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x28));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7e00($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76ac0 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x7c));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7dec($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1t 0x1f76af0 */
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (0x80));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: lwc1 $f1 -0x789c($gp) */
    /* unhandled: lwc1 $f0 -0x7df8($gp) */
    /* unhandled: c.olt.s $f1 $f0 */
    /* unhandled: bc1tl 0x1f76b24 */
    r_s3 = (long)(r_s3 + (1));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_a2 = (long)(0 + (4));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)(r_v0 + r_s2);
    r_a1 = (long)(r_v0 + (8));
    r_v0 = (long)func_00226D90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_s3 + (1));
_lbl_01F76B24:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (24)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (5)); goto _lbl_01F768F4; }
    r_v0 = (long)((unsigned long)r_s3 << (5));
    r_a0 = (long)(r_s1 | 0);
    r_v0 = (long)func_00226BF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: xori.b $w1 $w0 0xbf */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 80: thelp_func_01F76B58 (VMA: 0x01F76B58, size: 416 bytes) */
void *thelp_func_01F76B58(void *a0, void *a1, void *a2, void *a3) {
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
    if ((long)r_a3 <= 0) { r_v0 = (long)(0 | 0); goto _lbl_01F76B74; }
    r_v0 = (long)(0 | 0);
    r_at = (long)((long)r_a3 < (long)(6) ? 1 : 0);
    if (r_at != 0) { r_v1 = (long)(0 + (4)); goto _lbl_01F76B80; }
    r_v1 = (long)(0 + (4));
_lbl_01F76B74:
    r_v0 = (long)(0 | 0);
    goto _lbl_01F76CF0;
    r_v1 = (long)(0 + (4));
_lbl_01F76B80:
    r_a1 = (long)(r_a1 & (0xff));
    if (r_a1 == r_v1) goto _lbl_01F76CA8;
    r_v1 = (long)(0 + (3));
    if (r_a1 == r_v1) goto _lbl_01F76C58;
    r_v1 = (long)(0 + (2));
    if (r_a1 == r_v1) goto _lbl_01F76C08;
    r_v1 = (long)(0 + (1));
    if (r_a1 == r_v1) goto _lbl_01F76BB8;
    goto _lbl_01F76CF0;
_lbl_01F76BB8:
    if (r_a0) { r_t1 = *(unsigned char *)((char *)r_a0 + (0)); }
    r_t0 = (long)(0 | 0);
    goto _lbl_01F76BF4;
_lbl_01F76BC4:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (4)); }
    r_v1 = (long)((unsigned long)r_t0 << (3));
    r_v1 = (long)(r_v1 + r_t0);
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_a1 = (long)(r_a1 + r_v1);
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_a2 != r_v1) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F76BF4; }
    r_v0 = (long)(0 + (1));
    if (r_a1) { *(int *)((char *)r_a1 + (4)) = (int)r_a3; }
    goto _lbl_01F76CF0;
    r_t0 = (long)(r_t0 + (1));
_lbl_01F76BF4:
    r_v1 = (long)((long)r_t0 < (long)r_t1 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F76BC4;
    goto _lbl_01F76CF0;
_lbl_01F76C08:
    if (r_a0) { r_t0 = *(unsigned char *)((char *)r_a0 + (8)); }
    r_t1 = (long)(0 | 0);
    goto _lbl_01F76C44;
_lbl_01F76C14:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (12)); }
    r_v1 = (long)((unsigned long)r_t1 << (4));
    r_v1 = (long)(r_v1 + r_t1);
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_a1 = (long)(r_a1 + r_v1);
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_a2 != r_v1) { r_t1 = (long)(r_t1 + (1)); goto _lbl_01F76C44; }
    r_v0 = (long)(0 + (1));
    if (r_a1) { *(int *)((char *)r_a1 + (8)) = (int)r_a3; }
    goto _lbl_01F76CF0;
    r_t1 = (long)(r_t1 + (1));
_lbl_01F76C44:
    r_v1 = (long)((long)r_t1 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F76C14;
    goto _lbl_01F76CF0;
_lbl_01F76C58:
    if (r_a0) { r_t0 = *(unsigned char *)((char *)r_a0 + (16)); }
    r_t1 = (long)(0 | 0);
    goto _lbl_01F76C94;
_lbl_01F76C64:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (20)); }
    r_v1 = (long)((unsigned long)r_t1 << (5));
    r_v1 = (long)(r_v1 - r_t1);
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_a1 = (long)(r_a1 + r_v1);
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_a2 != r_v1) { r_t1 = (long)(r_t1 + (1)); goto _lbl_01F76C94; }
    r_v0 = (long)(0 + (1));
    if (r_a1) { *(int *)((char *)r_a1 + (8)) = (int)r_a3; }
    goto _lbl_01F76CF0;
    r_t1 = (long)(r_t1 + (1));
_lbl_01F76C94:
    r_v1 = (long)((long)r_t1 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F76C64;
    goto _lbl_01F76CF0;
_lbl_01F76CA8:
    if (r_a0) { r_t0 = *(unsigned char *)((char *)r_a0 + (24)); }
    r_t1 = (long)(0 | 0);
    goto _lbl_01F76CE4;
_lbl_01F76CB4:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (28)); }
    r_v1 = (long)((unsigned long)r_t1 << (5));
    r_v1 = (long)(r_v1 + r_t1);
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_a1 = (long)(r_a1 + r_v1);
    if (r_a1) { r_v1 = *(int *)((char *)r_a1 + (0)); }
    if (r_a2 != r_v1) { r_t1 = (long)(r_t1 + (1)); goto _lbl_01F76CE4; }
    r_v0 = (long)(0 + (1));
    if (r_a1) { *(int *)((char *)r_a1 + (4)) = (int)r_a3; }
    goto _lbl_01F76CF0;
    r_t1 = (long)(r_t1 + (1));
_lbl_01F76CE4:
    r_v1 = (long)((long)r_t1 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) goto _lbl_01F76CB4;
_lbl_01F76CF0:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 81: thelp_func_01F76CF8 (VMA: 0x01F76CF8, size: 1108 bytes) */
void *thelp_func_01F76CF8(void *a0, void *a1, void *a2, void *a3) {
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
    r_sp = (long)(r_sp + (-0x120));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (48)); }
    r_s6 = (long)(r_a0 | 0);
    r_s5 = (long)(r_a1 | 0);
    if (r_v0) { r_a1 = *(short *)((char *)r_v0 + (38)); }
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (44)); }
    r_s2 = (long)(0 | 0);
    r_v0 = (long)func_001AECD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 | 0);
    if (r_s3 != 0) goto _lbl_01F76D5C;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F7711C;
_lbl_01F76D5C:
    if (r_s3) { r_s8 = *(int *)((char *)r_s3 + (40)); }
    r_s0 = (long)(0 | 0);
    goto _lbl_01F76F98;
    r_v0 = (long)((unsigned long)r_s0 << (1));
_lbl_01F76D6C:
    r_v0 = (long)(r_v0 + r_s0);
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_a2 = (long)(r_s8 + r_v0);
    if (r_a2) { r_v1 = *(unsigned char *)((char *)r_a2 + (0)); }
    r_v0 = (long)(0 + (0x66));
    if (r_v1 == r_v0) goto _lbl_01F76E5C;
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F76D9C;
    r_s0 = (long)(r_s0 + (1));
    goto _lbl_01F76F98;
_lbl_01F76D9C:
    if (r_a2) { r_s1 = *(short *)((char *)r_a2 + (2)); }
    if (r_a2) { r_s2 = *(short *)((char *)r_a2 + (4)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_a0 = (long)(r_s6 | 0); goto _lbl_01F76E00; }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_a1 = (long)(0 + (2)); goto _lbl_01F76DEC; }
    r_a1 = (long)(0 + (2));
    r_a1 = (long)(0 + (2));
    r_a0 = (long)(r_s6 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_a3 = (long)(r_a1 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F76DFC;
    r_a1 = (long)(0 + (2));
_lbl_01F76DEC:
    r_a3 = (long)(0 + (3));
    r_a0 = (long)(r_s6 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76DFC:
    r_a0 = (long)(r_s6 | 0);
_lbl_01F76E00:
    r_a1 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F76F94;
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_a1 = (long)(0 + (3)); goto _lbl_01F76E44; }
    r_a1 = (long)(0 + (3));
    r_a1 = (long)(0 + (3));
    r_a3 = (long)(0 + (2));
    r_a2 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F76F94;
    r_a1 = (long)(0 + (3));
_lbl_01F76E44:
    r_a2 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_a3 = (long)(r_a1 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F76F94;
_lbl_01F76E5C:
    /* unhandled: lwc1 $f12 8($a2) */
    r_v0 = (long)func_00123350((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    r_v0 = (long)(0 + (-1));
    if (r_s1 == r_v0) goto _lbl_01F76F94;
    r_a1 = (long)(0 + (4));
    r_a3 = (long)(0 + (3));
    r_a0 = (long)(r_s6 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_01F76F94;
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (40)); }
    r_v1 = (long)((unsigned long)r_s1 << (6));
    r_a1 = (long)(r_sp + (0xa0));
    r_a0 = (long)(0 + (8));
    r_a2 = (long)(r_v0 + r_v1);
_lbl_01F76EA4:
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (4)); }
    r_a0 = (long)(r_a0 + (-1));
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (4)) = (int)r_v0; }
    r_a2 = (long)(r_a2 + (8));
    if ((long)r_a0 > 0) { r_a1 = (long)(r_a1 + (8)); goto _lbl_01F76EA4; }
    r_a1 = (long)(r_a1 + (8));
    if (r_sp) { r_a1 = *(short *)((char *)r_sp + (194)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (44)); }
    r_v0 = (long)func_001AECD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s4 = (long)(r_v0 | 0);
    if (r_s4 == 0) goto _lbl_01F76F94;
    r_s1 = (long)(0 | 0);
    goto _lbl_01F76F84;
    r_v0 = (long)((unsigned long)r_s1 << (1));
_lbl_01F76EE8:
    r_v1 = (long)(r_v0 + r_s1);
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (40)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_a3 = (long)(0 + (3));
    r_t0 = (long)(r_v0 + r_v1);
    if (r_t0) { r_v1 = *(unsigned char *)((char *)r_t0 + (0)); }
    if (r_v1 == r_a3) goto _lbl_01F76F54;
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F76F1C;
    r_s1 = (long)(r_s1 + (1));
    goto _lbl_01F76F84;
_lbl_01F76F1C:
    if (r_t0) { r_v1 = *(short *)((char *)r_t0 + (4)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { if (r_t0) { r_a2 = *(short *)((char *)r_t0 + (2)); } goto _lbl_01F76F40; }
    if (r_t0) { r_a2 = *(short *)((char *)r_t0 + (2)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_a3 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F76F80;
_lbl_01F76F40:
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_a3 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F76F80;
_lbl_01F76F54:
    if (r_t0) { r_s7 = *(short *)((char *)r_t0 + (4)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F76F80;
    r_a1 = (long)(0 + (3));
    r_a2 = (long)(r_s7 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_a3 = (long)(r_a1 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F76F80:
    r_s1 = (long)(r_s1 + (1));
_lbl_01F76F84:
    if (r_s4) { r_v0 = *(short *)((char *)r_s4 + (36)); }
    r_v0 = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s1 << (1)); goto _lbl_01F76EE8; }
    r_v0 = (long)((unsigned long)r_s1 << (1));
_lbl_01F76F94:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F76F98:
    if (r_s3) { r_v0 = *(short *)((char *)r_s3 + (36)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (1)); goto _lbl_01F76D6C; }
    r_v0 = (long)((unsigned long)r_s0 << (1));
    if (r_s6) { r_s7 = *(int *)((char *)r_s6 + (40)); }
    r_s2 = (long)(0 | 0);
    goto _lbl_01F770CC;
    r_v0 = (long)((unsigned long)r_s2 << (6));
_lbl_01F76FC0:
    r_a2 = (long)(r_s7 + r_v0);
    r_a1 = (long)(r_sp + (0xe0));
    r_a0 = (long)(0 + (8));
_lbl_01F76FCC:
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (4)); }
    r_a0 = (long)(r_a0 + (-1));
    if (r_a1) { *(int *)((char *)r_a1 + (0)) = (int)r_v1; }
    if (r_a1) { *(int *)((char *)r_a1 + (4)) = (int)r_v0; }
    r_a2 = (long)(r_a2 + (8));
    if ((long)r_a0 > 0) { r_a1 = (long)(r_a1 + (8)); goto _lbl_01F76FCC; }
    r_a1 = (long)(r_a1 + (8));
    if (r_sp) { r_v0 = *(short *)((char *)r_sp + (242)); }
    /* unhandled: blezl $v0 0x1f770cc */
    r_s2 = (long)(r_s2 + (1));
    if (r_v0 == r_s5) goto _lbl_01F770C8;
    if (r_sp) { r_a1 = *(short *)((char *)r_sp + (258)); }
    if (r_s6) { r_a0 = *(int *)((char *)r_s6 + (44)); }
    r_v0 = (long)func_001AECD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    if (r_s1 == 0) goto _lbl_01F770C8;
    r_s3 = (long)(0 | 0);
    goto _lbl_01F770B8;
    r_v0 = (long)((unsigned long)r_s3 << (1));
_lbl_01F77024:
    r_v1 = (long)(r_v0 + r_s3);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (40)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_a1 = (long)(0 + (3));
    r_v1 = (long)(r_v0 + r_v1);
    if (r_v1) { r_v0 = *(unsigned char *)((char *)r_v1 + (0)); }
    if (r_v0 == r_a1) goto _lbl_01F77088;
    r_a3 = (long)(0 + (2));
    if (r_v0 == r_a3) goto _lbl_01F77058;
    r_s3 = (long)(r_s3 + (1));
    goto _lbl_01F770B8;
_lbl_01F77058:
    r_v0 = (long)(0 + (1));
    if (r_s0 != r_v0) { if (r_v1) { r_a2 = *(short *)((char *)r_v1 + (2)); } goto _lbl_01F77074; }
    if (r_v1) { r_a2 = *(short *)((char *)r_v1 + (2)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F770B4;
_lbl_01F77074:
    r_a0 = (long)(r_s6 | 0);
    r_a3 = (long)(r_a1 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_01F770B4;
_lbl_01F77088:
    if (r_v1) { r_s4 = *(short *)((char *)r_v1 + (4)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F770B4;
    r_a1 = (long)(0 + (3));
    r_a2 = (long)(r_s4 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_a3 = (long)(r_a1 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F770B4:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F770B8:
    if (r_s1) { r_v0 = *(short *)((char *)r_s1 + (36)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (1)); goto _lbl_01F77024; }
    r_v0 = (long)((unsigned long)r_s3 << (1));
_lbl_01F770C8:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F770CC:
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (40)); }
    if (r_v0) { r_v0 = *(short *)((char *)r_v0 + (27392)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (6)); goto _lbl_01F76FC0; }
    r_v0 = (long)((unsigned long)r_s2 << (6));
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F77270((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a3 = (long)(0 + (3));
    if (r_s5 != r_a3) { r_v0 = (long)(0 + (1)); goto _lbl_01F7711C; }
    r_v0 = (long)(0 + (1));
    r_a1 = (long)(0 + (2));
    r_a2 = (long)(0 + (0x75));
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (2));
    r_a2 = (long)(0 + (0x1e7));
    r_a3 = (long)(0 + (3));
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F76BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01F7711C:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x120));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 82: thelp_func_01F7714C (VMA: 0x01F7714C, size: 152 bytes) */
void *thelp_func_01F7714C(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a0 | 0);
    r_s1 = (long)(0 | 0);
    goto _lbl_01F771B8;
    r_v0 = (long)((unsigned long)r_s1 << (3));
_lbl_01F77174:
    r_v1 = (long)(r_v0 + r_s1);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (4)); }
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_a0 = (long)(r_s0 | 0);
    r_s2 = (long)(r_v0 + r_v1);
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F77910((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 | 0);
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F77D80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 | 0);
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78410((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s2 | 0);
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78430((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_s1 + (1));
_lbl_01F771B8:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (0)); }
    r_v0 = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s1 << (3)); goto _lbl_01F77174; }
    r_v0 = (long)((unsigned long)r_s1 << (3));
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_v0 = (long)(0 + (1));
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 83: thelp_func_01F771E4 (VMA: 0x01F771E4, size: 1092 bytes) */
void *thelp_func_01F771E4(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a0 | 0);
    r_s1 = (long)(0 | 0);
    goto _lbl_01F77350;
    r_v0 = (long)((unsigned long)r_s1 << (4));
_lbl_01F77218:
    r_v1 = (long)(r_v0 + r_s1);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (12)); }
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_s3 = (long)(r_v0 + r_v1);
    if (r_s3 == 0) { r_s1 = (long)(r_s1 + (1)); goto _lbl_01F77350; }
    r_s2 = (long)(0 | 0);
    goto _lbl_01F7733C;
    r_v0 = (long)((unsigned long)r_s2 << (2));
_lbl_01F7723C:
    r_a0 = (long)(r_s3 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) goto _lbl_01F77308;
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F772D8;
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) goto _lbl_01F772A8;
    if (r_v1 == 0) goto _lbl_01F77278;
    r_s2 = (long)(r_s2 + (1));
    goto _lbl_01F7733C;
_lbl_01F77278:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F77338;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (4)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F77338;
    if (r_s3) { *(int *)((char *)r_s3 + (8)) = (int)r_v0; }
    if (r_s3) { r_s2 = *(unsigned char *)((char *)r_s3 + (40)); }
    goto _lbl_01F77338;
_lbl_01F772A8:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F77338;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (8)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F77338;
    if (r_s3) { *(int *)((char *)r_s3 + (8)) = (int)r_v0; }
    if (r_s3) { r_s2 = *(unsigned char *)((char *)r_s3 + (40)); }
    goto _lbl_01F77338;
_lbl_01F772D8:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F77338;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (8)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F77338;
    if (r_s3) { *(int *)((char *)r_s3 + (8)) = (int)r_v0; }
    if (r_s3) { r_s2 = *(unsigned char *)((char *)r_s3 + (40)); }
    goto _lbl_01F77338;
_lbl_01F77308:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F77338;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (4)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F77338;
    if (r_s3) { *(int *)((char *)r_s3 + (8)) = (int)r_v0; }
    if (r_s3) { r_s2 = *(unsigned char *)((char *)r_s3 + (40)); }
_lbl_01F77338:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F7733C:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (40)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (2)); goto _lbl_01F7723C; }
    r_v0 = (long)((unsigned long)r_s2 << (2));
    r_s1 = (long)(r_s1 + (1));
_lbl_01F77350:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (8)); }
    r_v0 = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s1 << (4)); goto _lbl_01F77218; }
    r_v0 = (long)((unsigned long)r_s1 << (4));
    r_s2 = (long)(0 | 0);
    goto _lbl_01F774A4;
    r_v0 = (long)((unsigned long)r_s2 << (5));
_lbl_01F7736C:
    r_v0 = (long)(r_v0 - r_s2);
    r_v1 = (long)((unsigned long)r_v0 << (2));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (20)); }
    r_s1 = (long)(r_v0 + r_v1);
    if (r_s1 == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F774A4; }
    r_s3 = (long)(0 | 0);
    goto _lbl_01F77490;
    r_v0 = (long)((unsigned long)r_s3 << (2));
_lbl_01F77390:
    r_a0 = (long)(r_s1 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (76)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) goto _lbl_01F7745C;
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F7742C;
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) goto _lbl_01F773FC;
    if (r_v1 == 0) goto _lbl_01F773CC;
    r_s3 = (long)(r_s3 + (1));
    goto _lbl_01F77490;
_lbl_01F773CC:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F7748C;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (4)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F7748C;
    if (r_s1) { *(int *)((char *)r_s1 + (8)) = (int)r_v0; }
    if (r_s1) { r_s3 = *(unsigned char *)((char *)r_s1 + (32)); }
    goto _lbl_01F7748C;
_lbl_01F773FC:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F7748C;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (8)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F7748C;
    if (r_s1) { *(int *)((char *)r_s1 + (8)) = (int)r_v0; }
    if (r_s1) { r_s3 = *(unsigned char *)((char *)r_s1 + (32)); }
    goto _lbl_01F7748C;
_lbl_01F7742C:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F7748C;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (8)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F7748C;
    if (r_s1) { *(int *)((char *)r_s1 + (8)) = (int)r_v0; }
    if (r_s1) { r_s3 = *(unsigned char *)((char *)r_s1 + (32)); }
    goto _lbl_01F7748C;
_lbl_01F7745C:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F7748C;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (4)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F7748C;
    if (r_s1) { *(int *)((char *)r_s1 + (8)) = (int)r_v0; }
    if (r_s1) { r_s3 = *(unsigned char *)((char *)r_s1 + (32)); }
_lbl_01F7748C:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F77490:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (32)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (2)); goto _lbl_01F77390; }
    r_v0 = (long)((unsigned long)r_s3 << (2));
    r_s2 = (long)(r_s2 + (1));
_lbl_01F774A4:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (16)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (5)); goto _lbl_01F7736C; }
    r_v0 = (long)((unsigned long)r_s2 << (5));
    r_s2 = (long)(0 | 0);
    goto _lbl_01F775F8;
    r_v0 = (long)((unsigned long)r_s2 << (5));
_lbl_01F774C0:
    r_v1 = (long)(r_v0 + r_s2);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (28)); }
    r_v1 = (long)((unsigned long)r_v1 << (2));
    r_s1 = (long)(r_v0 + r_v1);
    if (r_s1 == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F775F8; }
    r_s3 = (long)(0 | 0);
    goto _lbl_01F775E4;
    r_v0 = (long)((unsigned long)r_s3 << (2));
_lbl_01F774E4:
    r_a0 = (long)(r_s1 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) goto _lbl_01F775B0;
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F77580;
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) goto _lbl_01F77550;
    if (r_v1 == 0) goto _lbl_01F77520;
    r_s3 = (long)(r_s3 + (1));
    goto _lbl_01F775E4;
_lbl_01F77520:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78BD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F775E0;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (4)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F775E0;
    if (r_s1) { *(int *)((char *)r_s1 + (4)) = (int)r_v0; }
    if (r_s1) { r_s3 = *(unsigned char *)((char *)r_s1 + (40)); }
    goto _lbl_01F775E0;
_lbl_01F77550:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F775E0;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (8)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F775E0;
    if (r_s1) { *(int *)((char *)r_s1 + (4)) = (int)r_v0; }
    if (r_s1) { r_s3 = *(unsigned char *)((char *)r_s1 + (40)); }
    goto _lbl_01F775E0;
_lbl_01F77580:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F775E0;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (8)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F775E0;
    if (r_s1) { *(int *)((char *)r_s1 + (4)) = (int)r_v0; }
    if (r_s1) { r_s3 = *(unsigned char *)((char *)r_s1 + (40)); }
    goto _lbl_01F775E0;
_lbl_01F775B0:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s0 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F775E0;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (4)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) goto _lbl_01F775E0;
    if (r_s1) { *(int *)((char *)r_s1 + (4)) = (int)r_v0; }
    if (r_s1) { r_s3 = *(unsigned char *)((char *)r_s1 + (40)); }
_lbl_01F775E0:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F775E4:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (40)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (2)); goto _lbl_01F774E4; }
    r_v0 = (long)((unsigned long)r_s3 << (2));
    r_s2 = (long)(r_s2 + (1));
_lbl_01F775F8:
    if (r_s0) { r_v0 = *(unsigned char *)((char *)r_s0 + (24)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (5)); goto _lbl_01F774C0; }
    r_v0 = (long)((unsigned long)r_s2 << (5));
    /* unhandled: xori.b $w1 $w0 0xbf */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_v0 = (long)(0 + (1));
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 84: thelp_func_01F77628 (VMA: 0x01F77628, size: 340 bytes) */
void *thelp_func_01F77628(void *a0, void *a1, void *a2, void *a3) {
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
    r_s1 = (long)(r_a0 | 0);
    r_s0 = (long)(0 | 0);
    goto _lbl_01F77690;
    r_v0 = (long)((unsigned long)r_s0 << (3));
_lbl_01F77654:
    r_v1 = (long)(r_v0 + r_s0);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (4)); }
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_a2 = (long)(0 + (0xa));
    r_a1 = (long)(0 | 0);
    r_s2 = (long)(r_v0 + r_v1);
    r_a0 = (long)(r_s2 + (0x79));
    if (r_s2) { *(char *)((char *)r_s2 + (120)) = (char)0; }
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 + (0x83));
    r_a2 = (long)(0 + (0xa));
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
    if (r_s2) { *(char *)((char *)r_s2 + (141)) = (char)0; }
_lbl_01F77690:
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (0)); }
    r_v1 = (long)((long)r_s0 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v0 = (long)((unsigned long)r_s0 << (3)); goto _lbl_01F77654; }
    r_s0 = (long)(0 | 0);
    goto _lbl_01F776E4;
    r_v0 = (long)((unsigned long)r_s0 << (4));
_lbl_01F776AC:
    r_v1 = (long)(r_v0 + r_s0);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (12)); }
    r_v1 = (long)((unsigned long)r_v1 << (3));
    r_a2 = (long)(0 + (5));
    r_a1 = (long)(0 | 0);
    r_s2 = (long)(r_v0 + r_v1);
    r_a0 = (long)(r_s2 + (0x7d));
    if (r_s2) { *(char *)((char *)r_s2 + (124)) = (char)0; }
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 + (0x82));
    r_a2 = (long)(0 + (5));
    r_a1 = (long)(0 | 0);
    r_v0 = (long)func_00117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F776E4:
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (8)); }
    r_v1 = (long)((long)r_s0 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v0 = (long)((unsigned long)r_s0 << (4)); goto _lbl_01F776AC; }
    r_a1 = (long)(0 | 0);
    goto _lbl_01F7771C;
    r_v1 = (long)((unsigned long)r_a1 << (5));
_lbl_01F77700:
    r_v1 = (long)(r_v1 - r_a1);
    r_a0 = (long)((unsigned long)r_v1 << (2));
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (20)); }
    r_a1 = (long)(r_a1 + (1));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_v1) { *(int *)((char *)r_v1 + (116)) = (int)0; }
    if (r_v1) { *(int *)((char *)r_v1 + (120)) = (int)0; }
_lbl_01F7771C:
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (16)); }
    r_v1 = (long)((long)r_a1 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a1 << (5)); goto _lbl_01F77700; }
    r_v1 = (long)((unsigned long)r_a1 << (5));
    r_a1 = (long)(0 | 0);
    goto _lbl_01F77754;
    r_v1 = (long)((unsigned long)r_a1 << (5));
_lbl_01F77738:
    r_a0 = (long)(r_v1 + r_a1);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (28)); }
    r_a0 = (long)((unsigned long)r_a0 << (2));
    r_a1 = (long)(r_a1 + (1));
    r_v1 = (long)(r_v1 + r_a0);
    if (r_v1) { *(int *)((char *)r_v1 + (124)) = (int)0; }
    if (r_v1) { *(int *)((char *)r_v1 + (128)) = (int)0; }
_lbl_01F77754:
    if (r_s1) { r_v1 = *(unsigned char *)((char *)r_s1 + (24)); }
    r_v1 = (long)((long)r_a1 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a1 << (5)); goto _lbl_01F77738; }
    r_v1 = (long)((unsigned long)r_a1 << (5));
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 85: thelp_func_01F7777C (VMA: 0x01F7777C, size: 276 bytes) */
void *thelp_func_01F7777C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    if ((long)r_a1 <= 0) { r_at = (long)((long)r_a1 < (long)(7) ? 1 : 0); goto _lbl_01F77888; }
    r_at = (long)((long)r_a1 < (long)(7) ? 1 : 0);
    if (r_at != 0) { r_t0 = (long)(0 | 0); goto _lbl_01F77798; }
    r_t0 = (long)(0 | 0);
    goto _lbl_01F77888;
_lbl_01F77798:
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (0)); }
    goto _lbl_01F777C8;
_lbl_01F777A0:
    r_a3 = (long)(r_v1 + r_t0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (4)); }
    r_a3 = (long)((unsigned long)r_a3 << (4));
    r_a3 = (long)(r_v1 + r_a3);
    if (r_a3) { r_v1 = *(int *)((char *)r_a3 + (4)); }
    if (r_v1 == r_a2) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F777C4; }
    if (r_a3) { *(int *)((char *)r_a3 + (4)) = (int)r_a1; }
    r_t0 = (long)(r_t0 + (1));
_lbl_01F777C4:
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (0)); }
_lbl_01F777C8:
    r_v1 = (long)((long)r_t0 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (3)); goto _lbl_01F777A0; }
    r_v1 = (long)((unsigned long)r_t0 << (3));
    r_t0 = (long)(0 | 0);
    goto _lbl_01F77800;
_lbl_01F777DC:
    r_a3 = (long)(r_v1 + r_t0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (12)); }
    r_a3 = (long)((unsigned long)r_a3 << (3));
    r_a3 = (long)(r_v1 + r_a3);
    if (r_a3) { r_v1 = *(int *)((char *)r_a3 + (8)); }
    if (r_v1 == r_a2) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F77800; }
    if (r_a3) { *(int *)((char *)r_a3 + (8)) = (int)r_a1; }
    r_t0 = (long)(r_t0 + (1));
_lbl_01F77800:
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (8)); }
    r_v1 = (long)((long)r_t0 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (4)); goto _lbl_01F777DC; }
    r_v1 = (long)((unsigned long)r_t0 << (4));
    r_t0 = (long)(0 | 0);
    goto _lbl_01F7783C;
_lbl_01F77818:
    r_v1 = (long)(r_v1 - r_t0);
    r_a3 = (long)((unsigned long)r_v1 << (2));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (20)); }
    r_a3 = (long)(r_v1 + r_a3);
    if (r_a3) { r_v1 = *(int *)((char *)r_a3 + (8)); }
    if (r_v1 == r_a2) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F7783C; }
    if (r_a3) { *(int *)((char *)r_a3 + (8)) = (int)r_a1; }
    r_t0 = (long)(r_t0 + (1));
_lbl_01F7783C:
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (16)); }
    r_v1 = (long)((long)r_t0 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (5)); goto _lbl_01F77818; }
    r_v1 = (long)((unsigned long)r_t0 << (5));
    r_t0 = (long)(0 | 0);
    goto _lbl_01F77878;
_lbl_01F77854:
    r_a3 = (long)(r_v1 + r_t0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (28)); }
    r_a3 = (long)((unsigned long)r_a3 << (2));
    r_a3 = (long)(r_v1 + r_a3);
    if (r_a3) { r_v1 = *(int *)((char *)r_a3 + (4)); }
    if (r_v1 == r_a2) { r_t0 = (long)(r_t0 + (1)); goto _lbl_01F77878; }
    if (r_a3) { *(int *)((char *)r_a3 + (4)) = (int)r_a1; }
    r_t0 = (long)(r_t0 + (1));
_lbl_01F77878:
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (24)); }
    r_v1 = (long)((long)r_t0 < (long)r_v1 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_t0 << (5)); goto _lbl_01F77854; }
    r_v1 = (long)((unsigned long)r_t0 << (5));
_lbl_01F77888:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 86: thelp_func_01F77890 (VMA: 0x01F77890, size: 224 bytes) */
void *thelp_func_01F77890(void *a0, void *a1, void *a2, void *a3) {
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
    r_s1 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_s1 != 0) { r_s2 = (long)(r_a0 | 0); goto _lbl_01F778B8; }
    r_s2 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77958;
_lbl_01F778B8:
    r_s0 = (long)(0 | 0);
    goto _lbl_01F778F8;
_lbl_01F778C0:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (32)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F778F8; }
    r_v1 = (long)(0 + (4));
    if (r_v0) { *(int *)((char *)r_v0 + (8)) = (int)r_v1; }
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F77BA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F778F8:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (28)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F778C0;
    r_s0 = (long)(0 | 0);
    goto _lbl_01F77944;
_lbl_01F77910:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (32)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F77944; }
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F779F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F77944:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (28)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F77910;
    r_v0 = (long)(0 + (1));
_lbl_01F77958:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 87: thelp_func_01F77970 (VMA: 0x01F77970, size: 432 bytes) */
void *thelp_func_01F77970(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0;
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
    r_sp = (long)(r_sp + (-0x80));
    /* unhandled: dps.w.ph $ac0 $sp $ra */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s3 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_s4 = (long)(r_a0 | 0);
    if (r_s3 != 0) { r_s2 = (long)(r_a2 | 0); goto _lbl_01F779AC; }
    r_s2 = (long)(r_a2 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77AF8;
_lbl_01F779AC:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (128)); }
    if ((long)r_v0 <= 0) { r_s1 = (long)(0 | 0); goto _lbl_01F779C4; }
    r_s1 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F77AF8;
    r_s1 = (long)(0 | 0);
_lbl_01F779C4:
    r_s0 = (long)(0 | 0);
    goto _lbl_01F77A54;
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F779D0:
    r_a0 = (long)(r_s3 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F77A54; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if (r_s6 == 0) goto _lbl_01F77A50;
    if (r_s2) { r_s5 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5 != r_v0) goto _lbl_01F77A50;
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5 != r_v0) goto _lbl_01F77A50;
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (12)); }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (12)); }
    if (r_v1 != r_v0) goto _lbl_01F77A50;
    r_s1 = (long)(0 + (1));
    goto _lbl_01F77A64;
_lbl_01F77A50:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F77A54:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (40)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (2)); goto _lbl_01F779D0; }
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F77A64:
    r_v0 = (long)(0 + (1));
    if (r_s1 != r_v0) goto _lbl_01F77A78;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77AF8;
_lbl_01F77A78:
    if (r_s3) { *(int *)((char *)r_s3 + (128)) = (int)r_v0; }
    if (r_s3) { r_v1 = *(unsigned char *)((char *)r_s3 + (32)); }
    if (r_v1 != 0) { r_s0 = (long)(0 | 0); goto _lbl_01F77A94; }
    r_s0 = (long)(0 | 0);
    goto _lbl_01F77AFC;
    r_s0 = (long)(0 | 0);
_lbl_01F77A94:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (32)); }
    goto _lbl_01F77AE8;
_lbl_01F77A9C:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (36)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F77AE4; }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (12)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (12)); }
    if (r_a0 != r_v1) goto _lbl_01F77AE0;
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (0)); }
    r_a3 = (long)(0 + (1));
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F77C00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_01F77AE0:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F77AE4:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (32)); }
_lbl_01F77AE8:
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F77A9C;
    r_v0 = (long)(0 + (1));
_lbl_01F77AF8:
_lbl_01F77AFC:
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 88: thelp_func_01F77B20 (VMA: 0x01F77B20, size: 92 bytes) */
void *thelp_func_01F77B20(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_a1 != 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01F77B3C; }
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77B6C;
_lbl_01F77B3C:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (124)); }
    if ((long)r_v0 <= 0) goto _lbl_01F77B50;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77B6C;
_lbl_01F77B50:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (36)); }
    r_a2 = (long)(r_v0 + (1));
    r_v0 = (long)thelp_func_01F77D00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (36)); }
    r_v0 = (long)(0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_s0) { *(int *)((char *)r_s0 + (36)) = (int)r_v1; }
_lbl_01F77B6C:
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 89: thelp_func_01F77B7C (VMA: 0x01F77B7C, size: 252 bytes) */
void *thelp_func_01F77B7C(void *a0, void *a1, void *a2, void *a3) {
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
    r_s3 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_s2 = (long)(r_a2 | 0);
    r_s1 = (long)(r_a3 | 0);
    if (r_s3 != 0) { r_s4 = (long)(r_a0 | 0); goto _lbl_01F77BB8; }
    r_s4 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77C58;
_lbl_01F77BB8:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (128)); }
    if ((long)r_v0 <= 0) goto _lbl_01F77BCC;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77C58;
_lbl_01F77BCC:
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 == r_v0) { r_v0 = (long)(r_s1 + (1)); goto _lbl_01F77BE8; }
    r_v0 = (long)(r_s1 + (1));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77C58;
    r_v0 = (long)(r_s1 + (1));
_lbl_01F77BE8:
    if (r_s3) { *(int *)((char *)r_s3 + (128)) = (int)r_v0; }
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (32)); }
    if ((long)r_v0 > 0) { r_s0 = (long)(0 | 0); goto _lbl_01F77C04; }
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F77C58;
    r_s0 = (long)(0 | 0);
_lbl_01F77C04:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (32)); }
    goto _lbl_01F77C48;
_lbl_01F77C0C:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (36)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F77C44; }
    r_a3 = (long)(r_s1 + (1));
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F77C00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F77C44:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (32)); }
_lbl_01F77C48:
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F77C0C;
    r_v0 = (long)(0 + (1));
_lbl_01F77C58:
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 90: thelp_func_01F77C78 (VMA: 0x01F77C78, size: 136 bytes) */
void *thelp_func_01F77C78(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a2 | 0);
    if (r_a1 != 0) { r_s1 = (long)(r_a0 | 0); goto _lbl_01F77CA4; }
    r_s1 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77CEC;
_lbl_01F77CA4:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (124)); }
    if ((long)r_v0 <= 0) goto _lbl_01F77CB8;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77CEC;
_lbl_01F77CB8:
    if (r_a1) { *(int *)((char *)r_a1 + (124)) = (int)r_s0; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (32)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F77CEC; }
    r_v0 = (long)(0 + (1));
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (36)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(r_s0 | 0);
    r_v0 = (long)thelp_func_01F77D00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01F77CEC:
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 91: thelp_func_01F77D00 (VMA: 0x01F77D00, size: 248 bytes) */
void *thelp_func_01F77D00(void *a0, void *a1, void *a2, void *a3) {
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
    r_s1 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_s1 != 0) { r_s2 = (long)(r_a0 | 0); goto _lbl_01F77D28; }
    r_s2 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77DE0;
_lbl_01F77D28:
    r_s0 = (long)(0 | 0);
    goto _lbl_01F77D80;
_lbl_01F77D30:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (24)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F77D80; }
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (20)); }
    if ((long)r_v1 < 0) { r_v1 = (long)(0 + (2)); goto _lbl_01F77D6C; }
    r_v1 = (long)(0 + (2));
    r_v1 = (long)(0 + (3));
    if (r_v0) { *(int *)((char *)r_v0 + (12)) = (int)r_v1; }
    goto _lbl_01F77D70;
    r_v1 = (long)(0 + (2));
_lbl_01F77D6C:
    if (r_v0) { *(int *)((char *)r_v0 + (12)) = (int)r_v1; }
_lbl_01F77D70:
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78030((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F77D80:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (20)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F77D30;
    r_s0 = (long)(0 | 0);
    goto _lbl_01F77DCC;
_lbl_01F77D98:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (24)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F77DCC; }
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s2 | 0);
    r_a2 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F77E80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F77DCC:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (20)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F77D98;
    r_v0 = (long)(0 + (1));
_lbl_01F77DE0:
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 92: thelp_func_01F77DF8 (VMA: 0x01F77DF8, size: 432 bytes) */
void *thelp_func_01F77DF8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0;
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
    r_sp = (long)(r_sp + (-0x80));
    /* unhandled: dps.w.ph $ac0 $sp $ra */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s3 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_s4 = (long)(r_a0 | 0);
    if (r_s3 != 0) { r_s2 = (long)(r_a2 | 0); goto _lbl_01F77E3C; }
    r_s2 = (long)(r_a2 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77F80;
_lbl_01F77E3C:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (120)); }
    if ((long)r_v0 <= 0) { r_s1 = (long)(0 | 0); goto _lbl_01F77E54; }
    r_s1 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F77F80;
    r_s1 = (long)(0 | 0);
_lbl_01F77E54:
    r_s0 = (long)(0 | 0);
    goto _lbl_01F77EE4;
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F77E60:
    r_a0 = (long)(r_s3 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (76)); }
    r_v0 = (long)(0 + (2));
    if (r_v1 != r_v0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F77EE4; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s6 = (long)(r_v0 | 0);
    if (r_s6 == 0) goto _lbl_01F77EE0;
    if (r_s2) { r_s5 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5 != r_v0) goto _lbl_01F77EE0;
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5 != r_v0) goto _lbl_01F77EE0;
    if (r_s6) { r_v1 = *(int *)((char *)r_s6 + (16)); }
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (16)); }
    if (r_v1 != r_v0) goto _lbl_01F77EE0;
    r_s1 = (long)(0 + (1));
    goto _lbl_01F77EF4;
_lbl_01F77EE0:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F77EE4:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (32)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (2)); goto _lbl_01F77E60; }
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F77EF4:
    r_v0 = (long)(0 + (1));
    if (r_s1 != r_v0) goto _lbl_01F77F08;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77F80;
_lbl_01F77F08:
    if (r_s3) { *(int *)((char *)r_s3 + (120)) = (int)r_v0; }
    if (r_s3) { r_v1 = *(unsigned char *)((char *)r_s3 + (24)); }
    if (r_v1 != 0) { r_s0 = (long)(0 | 0); goto _lbl_01F77F24; }
    r_s0 = (long)(0 | 0);
    goto _lbl_01F77F84;
    r_s0 = (long)(0 | 0);
_lbl_01F77F24:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (24)); }
    goto _lbl_01F77F70;
_lbl_01F77F2C:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (28)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (16)); }
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (16)); }
    if (r_a0 != r_v1) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F77F6C; }
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (0)); }
    r_a3 = (long)(0 + (1));
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78090((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F77F6C:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (24)); }
_lbl_01F77F70:
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F77F2C;
    r_v0 = (long)(0 + (1));
_lbl_01F77F80:
_lbl_01F77F84:
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 93: thelp_func_01F77FA8 (VMA: 0x01F77FA8, size: 100 bytes) */
void *thelp_func_01F77FA8(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_a1 != 0) { r_s0 = (long)(r_a0 | 0); goto _lbl_01F77FCC; }
    r_s0 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77FFC;
_lbl_01F77FCC:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (116)); }
    if ((long)r_v0 <= 0) goto _lbl_01F77FE0;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F77FFC;
_lbl_01F77FE0:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (36)); }
    r_a2 = (long)(r_v0 + (1));
    r_v0 = (long)thelp_func_01F78190((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (36)); }
    r_v0 = (long)(0 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_s0) { *(int *)((char *)r_s0 + (36)) = (int)r_v1; }
_lbl_01F77FFC:
    /* unhandled: aver_u.h $w0 $w0 $w31 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 94: thelp_func_01F7800C (VMA: 0x01F7800C, size: 252 bytes) */
void *thelp_func_01F7800C(void *a0, void *a1, void *a2, void *a3) {
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
    r_s3 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_s2 = (long)(r_a2 | 0);
    r_s1 = (long)(r_a3 | 0);
    if (r_s3 != 0) { r_s4 = (long)(r_a0 | 0); goto _lbl_01F78048; }
    r_s4 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F780E8;
_lbl_01F78048:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (120)); }
    if ((long)r_v0 <= 0) goto _lbl_01F7805C;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F780E8;
_lbl_01F7805C:
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 == r_v0) { r_v0 = (long)(r_s1 + (1)); goto _lbl_01F78078; }
    r_v0 = (long)(r_s1 + (1));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F780E8;
    r_v0 = (long)(r_s1 + (1));
_lbl_01F78078:
    if (r_s3) { *(int *)((char *)r_s3 + (120)) = (int)r_v0; }
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (24)); }
    if ((long)r_v0 > 0) { r_s0 = (long)(0 | 0); goto _lbl_01F78094; }
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F780E8;
    r_s0 = (long)(0 | 0);
_lbl_01F78094:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (24)); }
    goto _lbl_01F780DC;
_lbl_01F7809C:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (28)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 | 0);
    if (r_s3 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F780D8; }
    r_a3 = (long)(r_s1 + (1));
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s3 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78090((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F780D8:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (24)); }
_lbl_01F780DC:
    if (r_v0 != 0) goto _lbl_01F7809C;
    r_v0 = (long)(0 + (1));
_lbl_01F780E8:
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 95: thelp_func_01F78108 (VMA: 0x01F78108, size: 136 bytes) */
void *thelp_func_01F78108(void *a0, void *a1, void *a2, void *a3) {
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
    r_s0 = (long)(r_a2 | 0);
    if (r_a1 != 0) { r_s1 = (long)(r_a0 | 0); goto _lbl_01F78134; }
    r_s1 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F7817C;
_lbl_01F78134:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (116)); }
    if ((long)r_v0 <= 0) goto _lbl_01F78148;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F7817C;
_lbl_01F78148:
    if (r_a1) { *(int *)((char *)r_a1 + (116)) = (int)r_s0; }
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (24)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (1)); goto _lbl_01F7817C; }
    r_v0 = (long)(0 + (1));
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (28)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_a2 = (long)(r_s0 | 0);
    r_v0 = (long)thelp_func_01F78190((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (1));
_lbl_01F7817C:
    /* unhandled: ld.b $w0 -0x41($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 96: thelp_func_01F78190 (VMA: 0x01F78190, size: 352 bytes) */
void *thelp_func_01F78190(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0;
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
    r_sp = (long)(r_sp + (-0x90));
    /* unhandled: ext $ra $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s5 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_s5 != 0) { r_s6 = (long)(r_a0 | 0); goto _lbl_01F781CC; }
    r_s6 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F782C4;
_lbl_01F781CC:
    r_s2 = (long)(0 | 0);
    goto _lbl_01F782B0;
    r_v0 = (long)((unsigned long)r_s2 << (3));
_lbl_01F781D8:
    r_v1 = (long)(r_v0 + r_s2);
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (4)); }
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_s0 = (long)(0 | 0);
    r_s1 = (long)(0 | 0);
    r_s3 = (long)(0 | 0);
    r_s4 = (long)(r_v0 + r_v1);
    goto _lbl_01F78238;
_lbl_01F781F8:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (28)); }
    r_v1 = (long)((unsigned long)r_s3 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F78238; }
    if (r_s4) { r_s7 = *(int *)((char *)r_s4 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7 != r_v0) goto _lbl_01F78234;
    r_s0 = (long)(r_s0 + (1));
_lbl_01F78234:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F78238:
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (24)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F781F8;
    r_s3 = (long)(0 | 0);
    goto _lbl_01F78290;
_lbl_01F78250:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (36)); }
    r_v1 = (long)((unsigned long)r_s3 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F78290; }
    if (r_s4) { r_s7 = *(int *)((char *)r_s4 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7 != r_v0) goto _lbl_01F7828C;
    r_s1 = (long)(r_s1 + (1));
_lbl_01F7828C:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F78290:
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (32)); }
    r_v0 = (long)((long)r_s3 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F78250;
    r_v0 = (long)(r_s5 + r_s2);
    r_v1 = (long)(r_s0 + r_s1);
    r_s2 = (long)(r_s2 + (1));
    if (r_v0) { *(char *)((char *)r_v0 + (125)) = (char)r_v1; }
_lbl_01F782B0:
    if (r_s6) { r_v0 = *(unsigned char *)((char *)r_s6 + (0)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (3)); goto _lbl_01F781D8; }
    r_v0 = (long)((unsigned long)r_s2 << (3));
    r_v0 = (long)(0 + (1));
_lbl_01F782C4:
    /* unhandled: xori.b $w2 $w0 0xbf */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 97: thelp_func_01F782F0 (VMA: 0x01F782F0, size: 148 bytes) */
void *thelp_func_01F782F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a1 != 0) { r_v0 = (long)(0 | 0); goto _lbl_01F78300; }
    r_v0 = (long)(0 | 0);
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F7837C;
_lbl_01F78300:
    if (r_a1) { r_a2 = *(int *)((char *)r_a1 + (0)); }
    r_v1 = (long)(0 + (0x52));
    if (r_a2 != r_v1) { r_v1 = (long)(0 + (0x2d)); goto _lbl_01F7831C; }
    r_v1 = (long)(0 + (0x2d));
    r_v0 = (long)(0 + (6));
    goto _lbl_01F7837C;
    r_v1 = (long)(0 + (0x2d));
_lbl_01F7831C:
    if (r_a2 != r_v1) { r_a0 = (long)(0 | 0); goto _lbl_01F7834C; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (32)); }
    r_v0 = (long)(0 + (0xb));
    if (r_v1 != r_v0) { r_v0 = (long)(0 + (6)); goto _lbl_01F78340; }
    r_v0 = (long)(0 + (6));
    r_v0 = (long)(0 + (7));
    goto _lbl_01F78340;
    r_v0 = (long)(0 + (6));
_lbl_01F78340:
    goto _lbl_01F7837C;
    r_a0 = (long)(0 | 0);
_lbl_01F7834C:
    r_v1 = (long)((long)r_a0 < (long)(5) ? 1 : 0);
    goto _lbl_01F78374;
    r_v1 = (long)(r_a1 + r_a0);
_lbl_01F78358:
    if (r_v1) { r_v1 = *(unsigned char *)((char *)r_v1 + (130)); }
    r_at = (long)((long)r_v0 < (long)r_v1 ? 1 : 0);
    if (r_at == 0) { r_a0 = (long)(r_a0 + (1)); goto _lbl_01F78370; }
    r_v0 = (long)(r_v1 | 0);
    r_a0 = (long)(r_a0 + (1));
_lbl_01F78370:
    r_v1 = (long)((long)r_a0 < (long)(5) ? 1 : 0);
_lbl_01F78374:
    if (r_v1 != 0) { r_v1 = (long)(r_a1 + r_a0); goto _lbl_01F78358; }
    r_v1 = (long)(r_a1 + r_a0);
_lbl_01F7837C:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 98: thelp_func_01F78384 (VMA: 0x01F78384, size: 44 bytes) */
void *thelp_func_01F78384(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a1 != 0) { r_v0 = (long)(0 + (1)); goto _lbl_01F783A4; }
    r_v0 = (long)(0 + (1));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F783A8;
    r_v0 = (long)(0 + (1));
_lbl_01F783A4:
    if (r_a1) { *(int *)((char *)r_a1 + (8)) = (int)r_v0; }
_lbl_01F783A8:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 99: thelp_func_01F783B0 (VMA: 0x01F783B0, size: 236 bytes) */
void *thelp_func_01F783B0(void *a0, void *a1, void *a2, void *a3) {
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
    r_s2 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_s2 != 0) { r_s3 = (long)(r_a0 | 0); goto _lbl_01F783DC; }
    r_s3 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F78480;
_lbl_01F783DC:
    r_s0 = (long)(0 | 0);
    goto _lbl_01F7846C;
_lbl_01F783E4:
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (16)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    if (r_s1 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F7846C; }
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (24)); }
    if ((long)r_v0 > 0) { r_v0 = (long)(0 + (5)); goto _lbl_01F7843C; }
    r_v0 = (long)(0 + (5));
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (32)); }
    if ((long)r_v0 > 0) goto _lbl_01F78438;
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (16)); }
    if ((long)r_v0 > 0) goto _lbl_01F78438;
    r_v0 = (long)(0 + (6));
    if (r_s1) { *(int *)((char *)r_s1 + (12)) = (int)r_v0; }
    goto _lbl_01F78440;
_lbl_01F78438:
    r_v0 = (long)(0 + (5));
_lbl_01F7843C:
    if (r_s1) { *(int *)((char *)r_s1 + (12)) = (int)r_v0; }
_lbl_01F78440:
    r_a0 = (long)(r_s3 | 0);
    r_a1 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F78210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s3 | 0);
    r_a1 = (long)(r_s1 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78520((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s1 | 0);
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78780((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F7846C:
    if (r_s2) { r_v0 = *(unsigned char *)((char *)r_s2 + (12)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F783E4;
    r_v0 = (long)(0 + (1));
_lbl_01F78480:
    /* unhandled: xori.b $w1 $w0 0xbf */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 100: thelp_func_01F7849C (VMA: 0x01F7849C, size: 348 bytes) */
void *thelp_func_01F7849C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0;
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
    r_sp = (long)(r_sp + (-0x70));
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s3 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_s4 = (long)(r_a0 | 0);
    if (r_s3 != 0) { r_s2 = (long)(r_a2 | 0); goto _lbl_01F784D8; }
    r_s2 = (long)(r_a2 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F785D4;
_lbl_01F784D8:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (124)); }
    if ((long)r_v0 <= 0) { r_s1 = (long)(0 | 0); goto _lbl_01F784F0; }
    r_s1 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F785D4;
    r_s1 = (long)(0 | 0);
_lbl_01F784F0:
    r_s0 = (long)(0 | 0);
    goto _lbl_01F78548;
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F784FC:
    r_a0 = (long)(r_s3 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 != r_v0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F78548; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F78544;
    if (r_s2) { r_s5 = *(int *)((char *)r_s2 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s5 != r_v0) goto _lbl_01F78544;
    r_s1 = (long)(0 + (1));
    goto _lbl_01F78558;
_lbl_01F78544:
    r_s0 = (long)(r_s0 + (1));
_lbl_01F78548:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (40)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (2)); goto _lbl_01F784FC; }
    r_v0 = (long)((unsigned long)r_s0 << (2));
_lbl_01F78558:
    r_v0 = (long)(0 + (1));
    if (r_s1 != r_v0) goto _lbl_01F7856C;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F785D4;
_lbl_01F7856C:
    if (r_s3) { *(char *)((char *)r_s3 + (124)) = (char)r_v0; }
    if (r_s3) { r_v1 = *(unsigned char *)((char *)r_s3 + (16)); }
    if (r_v1 != 0) { r_s0 = (long)(0 | 0); goto _lbl_01F78588; }
    r_s0 = (long)(0 | 0);
    /* unhandled: ld.b $w1 -0x41($zero) */
    goto _lbl_01F785D8;
    r_s0 = (long)(0 | 0);
_lbl_01F78588:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (16)); }
    goto _lbl_01F785C4;
_lbl_01F78590:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (20)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { r_a2 = *(int *)((char *)r_s2 + (0)); }
    r_a3 = (long)(0 + (1));
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78680((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (16)); }
_lbl_01F785C4:
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F78590;
    r_v0 = (long)(0 + (1));
_lbl_01F785D4:
    /* unhandled: ld.b $w1 -0x41($zero) */
_lbl_01F785D8:
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 101: thelp_func_01F785F8 (VMA: 0x01F785F8, size: 256 bytes) */
void *thelp_func_01F785F8(void *a0, void *a1, void *a2, void *a3) {
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
    r_s3 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    r_s2 = (long)(r_a2 | 0);
    r_s1 = (long)(r_a3 | 0);
    if (r_s3 != 0) { r_s4 = (long)(r_a0 | 0); goto _lbl_01F78638; }
    r_s4 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F786D8;
_lbl_01F78638:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (124)); }
    if ((long)r_v0 <= 0) goto _lbl_01F7864C;
    r_v0 = (long)(0 | 0);
    goto _lbl_01F786D8;
_lbl_01F7864C:
    r_v0 = (long)thelp_func_01F78DD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 == r_v0) { r_v0 = (long)(r_s1 + (1)); goto _lbl_01F78668; }
    r_v0 = (long)(r_s1 + (1));
    r_v0 = (long)(0 | 0);
    goto _lbl_01F786D8;
    r_v0 = (long)(r_s1 + (1));
_lbl_01F78668:
    if (r_s3) { *(char *)((char *)r_s3 + (124)) = (char)r_v0; }
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (16)); }
    if ((long)r_v0 > 0) { r_s0 = (long)(0 | 0); goto _lbl_01F78684; }
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(0 + (1));
    goto _lbl_01F786D8;
    r_s0 = (long)(0 | 0);
_lbl_01F78684:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (16)); }
    goto _lbl_01F786C8;
_lbl_01F7868C:
    if (r_s3) { r_v0 = *(int *)((char *)r_s3 + (20)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (1)); goto _lbl_01F786C4; }
    r_a3 = (long)(r_s1 + (1));
    r_a1 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s4 | 0);
    r_a2 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78680((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + (1));
_lbl_01F786C4:
    if (r_s3) { r_v0 = *(unsigned char *)((char *)r_s3 + (16)); }
_lbl_01F786C8:
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F7868C;
    r_v0 = (long)(0 + (1));
_lbl_01F786D8:
    /* unhandled: aver_u.h $w1 $w0 $w31 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 102: thelp_func_01F786F8 (VMA: 0x01F786F8, size: 1108 bytes) */
void *thelp_func_01F786F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0;
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
    r_sp = (long)(r_sp + (-0xf0));
    /* unhandled: ext $fp $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    r_s5 = (long)(r_a1 | 0);
    /* unhandled: ext $s0 $sp 0 1 */
    if (r_s5 != 0) { r_s6 = (long)(r_a0 | 0); goto _lbl_01F78740; }
    r_s6 = (long)(r_a0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F78B1C;
_lbl_01F78740:
    r_s0 = (long)(0 | 0);
    goto _lbl_01F78960;
    r_v0 = (long)((unsigned long)r_s0 << (3));
_lbl_01F7874C:
    r_v1 = (long)(r_v0 + r_s0);
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (4)); }
    r_v1 = (long)((unsigned long)r_v1 << (4));
    if (r_sp) { *(int *)((char *)r_sp + (192)) = (int)0; }
    r_s8 = (long)(0 | 0);
    r_s1 = (long)(0 | 0);
    r_s4 = (long)(r_v0 + r_v1);
    goto _lbl_01F78844;
_lbl_01F7876C:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (28)); }
    r_v1 = (long)((unsigned long)r_s1 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) { r_s1 = (long)(r_s1 + (1)); goto _lbl_01F78844; }
    if (r_s4) { r_s2 = *(int *)((char *)r_s4 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 != r_v0) goto _lbl_01F78840;
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)0; }
    r_s2 = (long)(0 | 0);
    goto _lbl_01F78824;
    r_v0 = (long)((unsigned long)r_s2 << (2));
_lbl_01F787B8:
    r_a0 = (long)(r_s7 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (76)); }
    r_v0 = (long)(0 + (2));
    if (r_v1 != r_v0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F78824; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 | 0);
    if (r_s3 == 0) goto _lbl_01F78820;
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s3 | 0);
    /* unhandled: mulsa.w.ph $ac0 $sp $v0 */
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v1 != r_v0) goto _lbl_01F78820;
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (16)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F78820;
    r_v0 = (long)(0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (208)) = (int)r_v0; }
    goto _lbl_01F78830;
_lbl_01F78820:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F78824:
    r_v0 = (long)((long)r_s2 < (long)(0xa) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s2 << (2)); goto _lbl_01F787B8; }
    r_v0 = (long)((unsigned long)r_s2 << (2));
_lbl_01F78830:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (208)); }
    if (r_v0 != 0) goto _lbl_01F78840;
    r_s8 = (long)(r_s8 + (1));
_lbl_01F78840:
    r_s1 = (long)(r_s1 + (1));
_lbl_01F78844:
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (24)); }
    r_v0 = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F7876C;
    r_s2 = (long)(0 | 0);
    goto _lbl_01F7893C;
_lbl_01F7885C:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (36)); }
    r_v1 = (long)((unsigned long)r_s2 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F7893C; }
    if (r_s4) { r_s1 = *(int *)((char *)r_s4 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1 != r_v0) goto _lbl_01F78938;
    if (r_sp) { *(int *)((char *)r_sp + (224)) = (int)0; }
    r_s3 = (long)(0 | 0);
    goto _lbl_01F78914;
    r_v0 = (long)((unsigned long)r_s3 << (2));
_lbl_01F788A8:
    r_a0 = (long)(r_s7 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 != r_v0) { r_s3 = (long)(r_s3 + (1)); goto _lbl_01F78914; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 | 0);
    if (r_s1 == 0) goto _lbl_01F78910;
    if (r_s4) { r_v0 = *(int *)((char *)r_s4 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: ld.b $w2 -0x5d($zero) */
    if (r_v1 != r_v0) goto _lbl_01F78910;
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (0)); }
    if (r_v1 != r_v0) goto _lbl_01F78910;
    r_v0 = (long)(0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (224)) = (int)r_v0; }
    goto _lbl_01F78920;
_lbl_01F78910:
    r_s3 = (long)(r_s3 + (1));
_lbl_01F78914:
    r_v0 = (long)((long)r_s3 < (long)(0xa) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s3 << (2)); goto _lbl_01F788A8; }
    r_v0 = (long)((unsigned long)r_s3 << (2));
_lbl_01F78920:
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (224)); }
    if (r_v0 != 0) goto _lbl_01F78938;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (192)); }
    r_v0 = (long)(r_v0 + (1));
    if (r_sp) { *(int *)((char *)r_sp + (192)) = (int)r_v0; }
_lbl_01F78938:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F7893C:
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (32)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F7885C;
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (192)); }
    r_v1 = (long)(r_s8 + r_v0);
    r_v0 = (long)(r_s5 + r_s0);
    r_s0 = (long)(r_s0 + (1));
    if (r_v0) { *(char *)((char *)r_v0 + (130)) = (char)r_v1; }
_lbl_01F78960:
    if (r_s6) { r_v0 = *(unsigned char *)((char *)r_s6 + (0)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s0 << (3)); goto _lbl_01F7874C; }
    r_v0 = (long)((unsigned long)r_s0 << (3));
    r_s1 = (long)(0 | 0);
    goto _lbl_01F78B08;
    r_v0 = (long)((unsigned long)r_s1 << (3));
_lbl_01F7897C:
    r_v1 = (long)(r_v0 + r_s1);
    if (r_s6) { r_v0 = *(int *)((char *)r_s6 + (4)); }
    r_v1 = (long)((unsigned long)r_v1 << (4));
    r_s2 = (long)(0 | 0);
    r_s0 = (long)(r_v0 + r_v1);
    goto _lbl_01F78A38;
_lbl_01F78994:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (28)); }
    r_v1 = (long)((unsigned long)r_s2 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F78A38; }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_s3 = *(int *)((char *)r_s0 + (0)); }
    r_s4 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3 != r_v0) goto _lbl_01F78A34;
    r_a1 = (long)(r_s7 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78F00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F78A34;
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s4 + (1));
    goto _lbl_01F78A28;
    r_a0 = (long)(r_s5 + r_a1);
_lbl_01F78A18:
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (129)); }
    r_a1 = (long)(r_a1 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_a0) { *(char *)((char *)r_a0 + (129)) = (char)r_v1; }
_lbl_01F78A28:
    r_v1 = (long)((long)r_a1 < (long)r_v0 ? 1 : 0);
    if (r_v1 != 0) { r_a0 = (long)(r_s5 + r_a1); goto _lbl_01F78A18; }
    r_a0 = (long)(r_s5 + r_a1);
_lbl_01F78A34:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F78A38:
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (24)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F78994;
    r_s2 = (long)(0 | 0);
    goto _lbl_01F78AF4;
_lbl_01F78A50:
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (36)); }
    r_v1 = (long)((unsigned long)r_s2 << (2));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0)); }
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) { r_s2 = (long)(r_s2 + (1)); goto _lbl_01F78AF4; }
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_s3 = *(int *)((char *)r_s0 + (0)); }
    r_s4 = (long)(r_v0 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3 != r_v0) goto _lbl_01F78AF0;
    r_a1 = (long)(r_s7 | 0);
    r_a0 = (long)(r_s6 | 0);
    r_v0 = (long)func_01F78ED0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F78AF0;
    r_a0 = (long)(r_s6 | 0);
    r_a1 = (long)(r_v0 | 0);
    r_v0 = (long)func_01F78D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s4 + (1));
    goto _lbl_01F78AE4;
    r_a0 = (long)(r_s5 + r_a1);
_lbl_01F78AD4:
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (129)); }
    r_a1 = (long)(r_a1 + (1));
    r_v1 = (long)(r_v1 + (1));
    if (r_a0) { *(char *)((char *)r_a0 + (129)) = (char)r_v1; }
_lbl_01F78AE4:
    r_v1 = (long)((long)r_a1 < (long)r_v0 ? 1 : 0);
    if (r_v1 != 0) { r_a0 = (long)(r_s5 + r_a1); goto _lbl_01F78AD4; }
    r_a0 = (long)(r_s5 + r_a1);
_lbl_01F78AF0:
    r_s2 = (long)(r_s2 + (1));
_lbl_01F78AF4:
    if (r_s5) { r_v0 = *(unsigned char *)((char *)r_s5 + (32)); }
    r_v0 = (long)((long)r_s2 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F78A50;
    r_s1 = (long)(r_s1 + (1));
_lbl_01F78B08:
    if (r_s6) { r_v0 = *(unsigned char *)((char *)r_s6 + (0)); }
    r_v0 = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s1 << (3)); goto _lbl_01F7897C; }
    r_v0 = (long)((unsigned long)r_s1 << (3));
    r_v0 = (long)(0 + (1));
_lbl_01F78B1C:
    /* unhandled: aver_u.h $w2 $w0 $w31 */
    /* unhandled: xori.b $w2 $w0 0xbe */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0xf0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 103: thelp_func_01F78B4C (VMA: 0x01F78B4C, size: 84 bytes) */
void *thelp_func_01F78B4C(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    if (r_a0) { r_t0 = *(unsigned char *)((char *)r_a0 + (0)); }
    r_v0 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    goto _lbl_01F78B8C;
    r_v1 = (long)((unsigned long)r_a3 << (3));
_lbl_01F78B64:
    r_a2 = (long)(r_v1 + r_a3);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (4)); }
    r_a2 = (long)((unsigned long)r_a2 << (4));
    r_a2 = (long)(r_v1 + r_a2);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    if (r_a1 != r_v1) { r_a3 = (long)(r_a3 + (1)); goto _lbl_01F78B8C; }
    r_v0 = (long)(r_a2 | 0);
    goto _lbl_01F78B98;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F78B8C:
    r_v1 = (long)((long)r_a3 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (3)); goto _lbl_01F78B64; }
    r_v1 = (long)((unsigned long)r_a3 << (3));
_lbl_01F78B98:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 104: thelp_func_01F78BA0 (VMA: 0x01F78BA0, size: 80 bytes) */
void *thelp_func_01F78BA0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    if (r_a0) { r_t0 = *(unsigned char *)((char *)r_a0 + (8)); }
    r_v0 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    goto _lbl_01F78BDC;
    r_v1 = (long)((unsigned long)r_a3 << (4));
_lbl_01F78BB4:
    r_a2 = (long)(r_v1 + r_a3);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (12)); }
    r_a2 = (long)((unsigned long)r_a2 << (3));
    r_a2 = (long)(r_v1 + r_a2);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    if (r_a1 != r_v1) { r_a3 = (long)(r_a3 + (1)); goto _lbl_01F78BDC; }
    r_v0 = (long)(r_a2 | 0);
    goto _lbl_01F78BE8;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F78BDC:
    r_v1 = (long)((long)r_a3 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (4)); goto _lbl_01F78BB4; }
    r_v1 = (long)((unsigned long)r_a3 << (4));
_lbl_01F78BE8:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 105: thelp_func_01F78BF0 (VMA: 0x01F78BF0, size: 80 bytes) */
void *thelp_func_01F78BF0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    if (r_a0) { r_t0 = *(unsigned char *)((char *)r_a0 + (16)); }
    r_v0 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    goto _lbl_01F78C2C;
    r_v1 = (long)((unsigned long)r_a3 << (5));
_lbl_01F78C04:
    r_v1 = (long)(r_v1 - r_a3);
    r_a2 = (long)((unsigned long)r_v1 << (2));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (20)); }
    r_a2 = (long)(r_v1 + r_a2);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    if (r_a1 != r_v1) { r_a3 = (long)(r_a3 + (1)); goto _lbl_01F78C2C; }
    r_v0 = (long)(r_a2 | 0);
    goto _lbl_01F78C38;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F78C2C:
    r_v1 = (long)((long)r_a3 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (5)); goto _lbl_01F78C04; }
    r_v1 = (long)((unsigned long)r_a3 << (5));
_lbl_01F78C38:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 106: thelp_func_01F78C40 (VMA: 0x01F78C40, size: 80 bytes) */
void *thelp_func_01F78C40(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    if (r_a0) { r_t0 = *(unsigned char *)((char *)r_a0 + (24)); }
    r_v0 = (long)(0 | 0);
    r_a3 = (long)(0 | 0);
    goto _lbl_01F78C7C;
    r_v1 = (long)((unsigned long)r_a3 << (5));
_lbl_01F78C54:
    r_a2 = (long)(r_v1 + r_a3);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (28)); }
    r_a2 = (long)((unsigned long)r_a2 << (2));
    r_a2 = (long)(r_v1 + r_a2);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (0)); }
    if (r_a1 != r_v1) { r_a3 = (long)(r_a3 + (1)); goto _lbl_01F78C7C; }
    r_v0 = (long)(r_a2 | 0);
    goto _lbl_01F78C88;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F78C7C:
    r_v1 = (long)((long)r_a3 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (5)); goto _lbl_01F78C54; }
    r_v1 = (long)((unsigned long)r_a3 << (5));
_lbl_01F78C88:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 107: thelp_func_01F78C90 (VMA: 0x01F78C90, size: 84 bytes) */
void *thelp_func_01F78C90(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a1 != 0) goto _lbl_01F78CA0;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F78CDC;
_lbl_01F78CA0:
    if (r_a1) { r_a2 = *(unsigned char *)((char *)r_a1 + (32)); }
    r_a0 = (long)(0 | 0);
    goto _lbl_01F78CCC;
    r_v0 = (long)((unsigned long)r_a0 << (2));
_lbl_01F78CB0:
    r_v1 = (long)(r_a1 + r_v0);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (76)); }
    if (r_v0 != 0) { r_a0 = (long)(r_a0 + (1)); goto _lbl_01F78CCC; }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (36)); }
    goto _lbl_01F78CDC;
    r_a0 = (long)(r_a0 + (1));
_lbl_01F78CCC:
    r_v0 = (long)((long)r_a0 < (long)r_a2 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F78CB0; }
    r_v0 = (long)((unsigned long)r_a0 << (2));
    r_v0 = (long)(0 + (-1));
_lbl_01F78CDC:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 108: thelp_func_01F78CE4 (VMA: 0x01F78CE4, size: 96 bytes) */
void *thelp_func_01F78CE4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a1 != 0) goto _lbl_01F78D00;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F78D3C;
_lbl_01F78D00:
    if (r_a1) { r_a2 = *(unsigned char *)((char *)r_a1 + (40)); }
    r_a0 = (long)(0 | 0);
    goto _lbl_01F78D2C;
    r_v0 = (long)((unsigned long)r_a0 << (2));
_lbl_01F78D10:
    r_v1 = (long)(r_a1 + r_v0);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (84)); }
    if (r_v0 != 0) { r_a0 = (long)(r_a0 + (1)); goto _lbl_01F78D2C; }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (44)); }
    goto _lbl_01F78D3C;
    r_a0 = (long)(r_a0 + (1));
_lbl_01F78D2C:
    r_v0 = (long)((long)r_a0 < (long)r_a2 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F78D10; }
    r_v0 = (long)((unsigned long)r_a0 << (2));
    r_v0 = (long)(0 + (-1));
_lbl_01F78D3C:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 109: thelp_func_01F78D44 (VMA: 0x01F78D44, size: 96 bytes) */
void *thelp_func_01F78D44(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    if (r_a1 != 0) goto _lbl_01F78D60;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F78D9C;
_lbl_01F78D60:
    if (r_a1) { r_a2 = *(unsigned char *)((char *)r_a1 + (40)); }
    r_a0 = (long)(0 | 0);
    goto _lbl_01F78D8C;
    r_v0 = (long)((unsigned long)r_a0 << (2));
_lbl_01F78D70:
    r_v1 = (long)(r_a1 + r_v0);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (84)); }
    if (r_v0 != 0) { r_a0 = (long)(r_a0 + (1)); goto _lbl_01F78D8C; }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (44)); }
    goto _lbl_01F78D9C;
    r_a0 = (long)(r_a0 + (1));
_lbl_01F78D8C:
    r_v0 = (long)((long)r_a0 < (long)r_a2 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_a0 << (2)); goto _lbl_01F78D70; }
    r_v0 = (long)((unsigned long)r_a0 << (2));
    r_v0 = (long)(0 + (-1));
_lbl_01F78D9C:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 110: thelp_func_01F78DA4 (VMA: 0x01F78DA4, size: 44 bytes) */
void *thelp_func_01F78DA4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1 != 0) goto _lbl_01F78DC0;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F78DC8;
_lbl_01F78DC0:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (16)); }
_lbl_01F78DC8:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 111: thelp_func_01F78DD0 (VMA: 0x01F78DD0, size: 32 bytes) */
void *thelp_func_01F78DD0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1 != 0) goto _lbl_01F78DE0;
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F78DE8;
_lbl_01F78DE0:
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (12)); }
_lbl_01F78DE8:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 112: thelp_func_01F78DF0 (VMA: 0x01F78DF0, size: 84 bytes) */
void *thelp_func_01F78DF0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_t0;
    if (r_a1 != 0) { r_v0 = (long)(0 + (-1)); goto _lbl_01F78E00; }
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F78E3C;
_lbl_01F78E00:
    if (r_a1) { r_t0 = *(unsigned char *)((char *)r_a1 + (40)); }
    r_a0 = (long)(0 + (1));
    r_a3 = (long)(0 | 0);
    goto _lbl_01F78E30;
    r_v1 = (long)((unsigned long)r_a3 << (2));
_lbl_01F78E14:
    r_a2 = (long)(r_a1 + r_v1);
    if (r_a2) { r_v1 = *(int *)((char *)r_a2 + (84)); }
    if (r_v1 != r_a0) { r_a3 = (long)(r_a3 + (1)); goto _lbl_01F78E30; }
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (44)); }
    goto _lbl_01F78E3C;
    r_a3 = (long)(r_a3 + (1));
_lbl_01F78E30:
    r_v1 = (long)((long)r_a3 < (long)r_t0 ? 1 : 0);
    if (r_v1 != 0) { r_v1 = (long)((unsigned long)r_a3 << (2)); goto _lbl_01F78E14; }
    r_v1 = (long)((unsigned long)r_a3 << (2));
_lbl_01F78E3C:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 113: thelp_func_01F78E44 (VMA: 0x01F78E44, size: 60 bytes) */
void *thelp_func_01F78E44(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1 != 0) { r_v0 = (long)(0 + (-1)); goto _lbl_01F78E60; }
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F78E78;
_lbl_01F78E60:
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (32)); }
    if ((long)r_v1 <= 0) goto _lbl_01F78E78;
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (36)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
_lbl_01F78E78:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 114: thelp_func_01F78E80 (VMA: 0x01F78E80, size: 48 bytes) */
void *thelp_func_01F78E80(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1 != 0) { r_v0 = (long)(0 + (-1)); goto _lbl_01F78E90; }
    r_v0 = (long)(0 + (-1));
    goto _lbl_01F78EA8;
_lbl_01F78E90:
    if (r_a1) { r_v1 = *(unsigned char *)((char *)r_a1 + (24)); }
    if ((long)r_v1 <= 0) goto _lbl_01F78EA8;
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (28)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
_lbl_01F78EA8:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 115: thelp_func_01F78EB0 (VMA: 0x01F78EB0, size: 528 bytes) */
void *thelp_func_01F78EB0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0;
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
    r_sp = (long)(r_sp + (-0x90));
    /* unhandled: ext $ra $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s4 = (long)(r_a0 | 0);
    r_v1 = (long)(0 + (-1));
    r_s2 = (long)(r_a2 | 0);
    if (r_a1) { *(char *)((char *)r_a1 + (0)) = (char)0; }
    r_s3 = (long)(r_a1 | 0);
    r_s6 = (long)(0 | 0);
    r_s0 = (long)(0 | 0);
    r_a0 = (long)(0 | 0);
    goto _lbl_01F78F08;
_lbl_01F78EFC:
    if (r_s3) { *(int *)((char *)r_s3 + (44)) = (int)r_v1; }
    r_a0 = (long)(r_a0 + (1));
    if (r_s3) { *(int *)((char *)r_s3 + (4)) = (int)r_v1; }
_lbl_01F78F08:
    r_v0 = (long)((long)r_a0 < (long)(0xa) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_01F78EFC;
    if (r_s2 != 0) { r_a0 = (long)(r_s4 | 0); goto _lbl_01F78F28; }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F79094;
    r_a0 = (long)(r_s4 | 0);
_lbl_01F78F28:
    r_a1 = (long)(r_s2 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_s1 = (long)(0 | 0);
    goto _lbl_01F79074;
    r_v0 = (long)((unsigned long)r_s1 << (2));
_lbl_01F78F40:
    r_a0 = (long)(r_s2 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (76)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) goto _lbl_01F7902C;
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) goto _lbl_01F78FD0;
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F78F74;
    r_s1 = (long)(r_s1 + (1));
    goto _lbl_01F79074;
_lbl_01F78F74:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) goto _lbl_01F79070;
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) goto _lbl_01F79070;
    if (r_v0 == r_s5) goto _lbl_01F79070;
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v1 = (long)(0 + (2));
    r_a0 = (long)(r_s3 + r_v0);
    if (r_a0) { *(int *)((char *)r_a0 + (44)) = (int)r_v1; }
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (0)); }
    r_s6 = (long)(r_s6 + (1));
    r_s0 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    if (r_s3) { *(char *)((char *)r_s3 + (0)) = (char)r_s6; }
    goto _lbl_01F79070;
_lbl_01F78FD0:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) goto _lbl_01F79070;
    r_a0 = (long)(r_s4 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) goto _lbl_01F79070;
    if (r_v0 == r_s5) goto _lbl_01F79070;
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v1 = (long)(0 + (3));
    r_a0 = (long)(r_s3 + r_v0);
    if (r_a0) { *(int *)((char *)r_a0 + (44)) = (int)r_v1; }
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (0)); }
    r_s6 = (long)(r_s6 + (1));
    r_s0 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    if (r_s3) { *(char *)((char *)r_s3 + (0)) = (char)r_s6; }
    goto _lbl_01F79070;
_lbl_01F7902C:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (36)); }
    r_a0 = (long)(r_s4 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F79070;
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0)); }
    if (r_s2) { r_v1 = *(int *)((char *)r_s2 + (16)); }
    if (r_a0 == r_v1) goto _lbl_01F79070;
    r_v1 = (long)((unsigned long)r_s6 << (2));
    r_s0 = (long)(0 + (1));
    r_v1 = (long)(r_s3 + r_v1);
    if (r_v1) { *(int *)((char *)r_v1 + (44)) = (int)r_s0; }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    r_s6 = (long)(r_s6 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (4)) = (int)r_v0; }
    if (r_s3) { *(char *)((char *)r_s3 + (0)) = (char)r_s6; }
_lbl_01F79070:
    r_s1 = (long)(r_s1 + (1));
_lbl_01F79074:
    if (r_s2) { r_v0 = *(unsigned char *)((char *)r_s2 + (32)); }
    r_at = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) { r_v0 = (long)(r_s0 | 0); goto _lbl_01F79094; }
    r_v0 = (long)(r_s0 | 0);
    r_v0 = (long)((long)r_s1 < (long)(0xa) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s1 << (2)); goto _lbl_01F78F40; }
    r_v0 = (long)((unsigned long)r_s1 << (2));
    r_v0 = (long)(r_s0 | 0);
_lbl_01F79094:
    /* unhandled: xori.b $w2 $w0 0xbf */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 116: thelp_func_01F790C0 (VMA: 0x01F790C0, size: 484 bytes) */
void *thelp_func_01F790C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0;
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
    r_sp = (long)(r_sp + (-0x90));
    /* unhandled: ext $ra $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s1 = (long)(r_a2 | 0);
    if (r_a1) { *(char *)((char *)r_a1 + (0)) = (char)0; }
    r_s2 = (long)(r_a1 | 0);
    r_s3 = (long)(r_a0 | 0);
    r_s6 = (long)(0 | 0);
    if (r_s1 != 0) { r_s0 = (long)(0 | 0); goto _lbl_01F7910C; }
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F79278;
_lbl_01F7910C:
    r_a1 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_s4 = (long)(0 | 0);
    goto _lbl_01F79258;
    r_v0 = (long)((unsigned long)r_s4 << (2));
_lbl_01F79124:
    r_a0 = (long)(r_s1 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (1));
    if (r_v1 == r_v0) goto _lbl_01F79210;
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) goto _lbl_01F791B4;
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F79158;
    r_s4 = (long)(r_s4 + (1));
    goto _lbl_01F79258;
_lbl_01F79158:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) goto _lbl_01F79254;
    r_a0 = (long)(r_s3 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) goto _lbl_01F79254;
    if (r_v0 == r_s5) goto _lbl_01F79254;
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v1 = (long)(0 + (2));
    r_a0 = (long)(r_s2 + r_v0);
    if (r_a0) { *(int *)((char *)r_a0 + (44)) = (int)r_v1; }
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (0)); }
    r_s6 = (long)(r_s6 + (1));
    r_s0 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    if (r_s2) { *(char *)((char *)r_s2 + (0)) = (char)r_s6; }
    goto _lbl_01F79254;
_lbl_01F791B4:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) goto _lbl_01F79254;
    r_a0 = (long)(r_s3 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) goto _lbl_01F79254;
    if (r_v0 == r_s5) goto _lbl_01F79254;
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v1 = (long)(0 + (3));
    r_a0 = (long)(r_s2 + r_v0);
    if (r_a0) { *(int *)((char *)r_a0 + (44)) = (int)r_v1; }
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (0)); }
    r_s6 = (long)(r_s6 + (1));
    r_s0 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    if (r_s2) { *(char *)((char *)r_s2 + (0)) = (char)r_s6; }
    goto _lbl_01F79254;
_lbl_01F79210:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78C20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) goto _lbl_01F79254;
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (12)); }
    if (r_a0 == r_v1) goto _lbl_01F79254;
    r_v1 = (long)((unsigned long)r_s6 << (2));
    r_s0 = (long)(0 + (1));
    r_v1 = (long)(r_s2 + r_v1);
    if (r_v1) { *(int *)((char *)r_v1 + (44)) = (int)r_s0; }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0)); }
    r_s6 = (long)(r_s6 + (1));
    if (r_v1) { *(int *)((char *)r_v1 + (4)) = (int)r_v0; }
    if (r_s2) { *(char *)((char *)r_s2 + (0)) = (char)r_s6; }
_lbl_01F79254:
    r_s4 = (long)(r_s4 + (1));
_lbl_01F79258:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (40)); }
    r_at = (long)((long)r_s4 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) { r_v0 = (long)(r_s0 | 0); goto _lbl_01F79278; }
    r_v0 = (long)(r_s0 | 0);
    r_v0 = (long)((long)r_s4 < (long)(0xa) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s4 << (2)); goto _lbl_01F79124; }
    r_v0 = (long)((unsigned long)r_s4 << (2));
    r_v0 = (long)(r_s0 | 0);
_lbl_01F79278:
    /* unhandled: xori.b $w2 $w0 0xbf */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 117: thelp_func_01F792A4 (VMA: 0x01F792A4, size: 412 bytes) */
void *thelp_func_01F792A4(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0;
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
    r_sp = (long)(r_sp + (-0x90));
    /* unhandled: ext $ra $sp 2 1 */
    /* unhandled: dps.w.ph $ac0 $sp $s7 */
    /* unhandled: subu.qb $zero $sp $s5 */
    /* unhandled: ext $s4 $sp 1 1 */
    /* unhandled: dpa.w.ph $ac0 $sp $s3 */
    /* unhandled: addu.qb $zero $sp $s1 */
    /* unhandled: ext $s0 $sp 0 1 */
    r_s1 = (long)(r_a2 | 0);
    if (r_a1) { *(char *)((char *)r_a1 + (0)) = (char)0; }
    r_s2 = (long)(r_a1 | 0);
    r_s3 = (long)(r_a0 | 0);
    r_s6 = (long)(0 | 0);
    if (r_s1 != 0) { r_s0 = (long)(0 | 0); goto _lbl_01F792FC; }
    r_s0 = (long)(0 | 0);
    r_v0 = (long)(0 | 0);
    goto _lbl_01F79414;
_lbl_01F792FC:
    r_a1 = (long)(r_s1 | 0);
    r_v0 = (long)func_01F78E70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 | 0);
    r_s4 = (long)(0 | 0);
    goto _lbl_01F793F4;
    r_v0 = (long)((unsigned long)r_s4 << (2));
_lbl_01F79314:
    r_a0 = (long)(r_s1 + r_v0);
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (84)); }
    r_v0 = (long)(0 + (3));
    if (r_v1 == r_v0) goto _lbl_01F79398;
    r_v0 = (long)(0 + (2));
    if (r_v1 == r_v0) goto _lbl_01F7933C;
    r_s4 = (long)(r_s4 + (1));
    goto _lbl_01F793F4;
_lbl_01F7933C:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78C70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) goto _lbl_01F793F0;
    r_a0 = (long)(r_s3 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78E30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) goto _lbl_01F793F0;
    if (r_v0 == r_s5) goto _lbl_01F793F0;
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v1 = (long)(0 + (2));
    r_a0 = (long)(r_s2 + r_v0);
    if (r_a0) { *(int *)((char *)r_a0 + (44)) = (int)r_v1; }
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (0)); }
    r_s6 = (long)(r_s6 + (1));
    r_s0 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    if (r_s2) { *(char *)((char *)r_s2 + (0)) = (char)r_s6; }
    goto _lbl_01F793F0;
_lbl_01F79398:
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (44)); }
    r_a0 = (long)(r_s3 | 0);
    r_v0 = (long)func_01F78CC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s7 = (long)(r_v0 | 0);
    if (r_s7 == 0) goto _lbl_01F793F0;
    r_a0 = (long)(r_s3 | 0);
    r_a1 = (long)(r_s7 | 0);
    r_v0 = (long)func_01F78E50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) goto _lbl_01F793F0;
    if (r_v0 == r_s5) goto _lbl_01F793F0;
    r_v0 = (long)((unsigned long)r_s6 << (2));
    r_v1 = (long)(0 + (3));
    r_a0 = (long)(r_s2 + r_v0);
    if (r_a0) { *(int *)((char *)r_a0 + (44)) = (int)r_v1; }
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (0)); }
    r_s6 = (long)(r_s6 + (1));
    r_s0 = (long)(0 + (1));
    if (r_a0) { *(int *)((char *)r_a0 + (4)) = (int)r_v0; }
    if (r_s2) { *(char *)((char *)r_s2 + (0)) = (char)r_s6; }
_lbl_01F793F0:
    r_s4 = (long)(r_s4 + (1));
_lbl_01F793F4:
    if (r_s1) { r_v0 = *(unsigned char *)((char *)r_s1 + (40)); }
    r_at = (long)((long)r_s4 < (long)r_v0 ? 1 : 0);
    if (r_at == 0) { r_v0 = (long)(r_s0 | 0); goto _lbl_01F79414; }
    r_v0 = (long)(r_s0 | 0);
    r_v0 = (long)((long)r_s4 < (long)(0xa) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((unsigned long)r_s4 << (2)); goto _lbl_01F79314; }
    r_v0 = (long)((unsigned long)r_s4 << (2));
    r_v0 = (long)(r_s0 | 0);
_lbl_01F79414:
    /* unhandled: xori.b $w2 $w0 0xbf */
    /* unhandled: ld.b $w1 -0x4a($zero) */
    /* unhandled: aver_u.h $w1 $w0 $w21 */
    /* unhandled: xori.b $w1 $w0 0xb4 */
    /* unhandled: ld.b $w0 -0x4e($zero) */
    /* unhandled: aver_u.h $w0 $w0 $w17 */
    /* unhandled: xori.b $w0 $w0 0xb0 */
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 118: thelp_func_01F79440 (VMA: 0x01F79440, size: 16 bytes) */
void *thelp_func_01F79440(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { *(int *)((char *)r_a0 + (40)) = (int)r_a1; }
    if (r_a0) { *(int *)((char *)r_a0 + (44)) = (int)r_a2; }
    if (r_a0) { *(int *)((char *)r_a0 + (48)) = (int)r_a3; }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* Function 119: thelp_func_01F79450 (VMA: 0x01F79450, size: 112 bytes) */
void *thelp_func_01F79450(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_at = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_at;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    /* unhandled: addi $a1 $v1 0x6e4f */
    /* unhandled: jalx 0x1d1d508 */
    if (r_at != 0) { /* unhandled: addi $t0 $v1 0x6365 */ return (void *)0x1F94E48; }
    r_s2 = (long)(r_s3 | (0x6373));
    return (void *)r_v0;
}

