/* KCET PlayStation 2 Memory Card Manager (kt_mc_2.c) */
#include "common.h"
#include "kt_mc_2.h"

/* String functions */
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
int strcmp(const char *, const char *);
int strlen(const char *);
void *memset(void *, int, unsigned int);
void *memcpy(void *, const void *, unsigned int);

/* External data symbols */
extern char D_00130748[];
extern char D_00131190[];
extern char D_00131720[];
extern char D_00131DA8[];
extern char D_00132358[];
extern char D_00132840[];
extern char D_001328E0[];
extern char D_00132C70[];
extern char D_00133000[];
extern char D_00133640[];
extern char D_00133698[];
extern char D_001336E0[];
extern char D_00133700[];
extern char D_00133930[];
extern char D_00133A18[];
extern char D_00133DB8[];
extern char D_00133DE8[];
extern char D_38C8B0[];
extern char D_38C8C0[];
extern char D_38C900[];
extern char D_38C930[];
extern char D_38C960[];
extern char D_38C970[];
extern char D_38C980[];
extern char D_38C990[];
extern char D_38CA10[];
extern char D_38CA40[];
extern char D_38CA70[];
extern char D_38CAA0[];
extern char D_38CAD0[];
extern char D_38CB00[];
extern char D_38CB60[];
extern char D_38CB90[];
extern char D_38CBD8[];
extern char D_38CC08[];
extern char D_38CC38[];
extern char D_38CC68[];
extern char D_38CC98[];
extern char D_38CCC8[];
extern char D_38CCE0[];
extern char D_38CD10[];
extern char D_38CD40[];
extern char D_38CD70[];
extern char D_38CDA0[];
extern char D_38CDE0[];
extern char D_38CE10[];
extern char D_38CE40[];
extern char D_38CE70[];
extern char D_38CE90[];
extern char D_48FF90[];
extern char D_48FFB0[];
extern char D_490010[];
extern char D_490048[];
extern char D_490068[];
extern char D_490078[];
extern char D_490088[];
extern char D_4900A8[];
extern char D_4900C0[];
extern char D_490100[];
extern char D_490110[];
extern char D_490130[];
extern char D_4901C8[];
extern char D_4901F8[];
extern char D_490210[];
extern char D_490250[];
extern char D_490288[];
extern char D_4902C8[];
extern char D_4902F0[];
extern char D_490370[];
extern char D_490390[];
extern char D_4903D0[];
extern char D_4903F0[];
extern char D_490420[];
extern char D_490440[];
extern char D_490458[];
extern char D_490490[];
extern char D_4904A0[];
extern char D_4904C0[];
extern char D_4904D8[];
extern char D_4904E8[];
extern char D_490500[];
extern char D_490528[];
extern char D_490558[];
extern char D_4E2CB8[];
extern char D_4E2D00[];
extern char D_4E2D40[];
extern char D_4E2D48[];
extern char D_4E2D50[];
extern char D_4E2D58[];
extern char D_4E2D60[];
extern char D_4F9700[];
extern char D_4F97D8[];
extern char D_4F9840[];
extern char D_4F9E40[];
extern char D_4F9EC0[];
extern char D_509EC0[];
extern char D_509ED0[];
extern char D_509EE0[];

/* External function prototypes */
extern void *func_001143C0(void *a0, ...);
extern void *func_0011ACD0(void *a0, ...);
extern void *func_00126040(void *a0, ...);
extern void *func_00128990(void *a0, ...);
extern void *func_1043B8(void *a0, ...);
extern void *func_1043C8(void *a0, ...);
extern void *func_1043D8(void *a0, ...);
extern void *func_104558(void *a0, ...);
extern void *func_104FA0(void *a0, ...);
extern void *func_10FE50(void *a0, ...);
extern void *func_10FF40(void *a0, ...);
extern void *func_1102A0(void *a0, ...);
extern void *func_1103D8(void *a0, ...);
extern void *func_110410(void *a0, ...);
extern void *func_1104C8(void *a0, ...);
extern void *func_110630(void *a0, ...);
extern void *func_110750(void *a0, ...);
extern void *func_110940(void *a0, ...);
extern void *func_110A78(void *a0, ...);
extern void *func_110C00(void *a0, ...);
extern void *func_110F30(void *a0, ...);
extern void *func_110FF8(void *a0, ...);
extern void *func_1111D8(void *a0, ...);
extern void *func_1113B0(void *a0, ...);
extern void *func_1115E0(void *a0, ...);
extern void *func_114320(void *a0, ...);
extern void *func_116D40(void *a0, ...);
extern void *func_116F40(void *a0, ...);
extern void *func_116F68(void *a0, ...);
extern void *func_117CAC(void *a0, ...);
extern void *func_118de0(void *a0, ...);
extern void *func_1236D0(void *a0, ...);
extern void *func_123790(void *a0, ...);
extern void *func_123818(void *a0, ...);
extern void *func_123848(void *a0, ...);
extern void *func_12DD00(void *a0, ...);
extern void *func_12DE28(void *a0, ...);

/* func_0012DE88 */
void *func_0012DE88(void *a0, void *a1, void *a2, void *a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    return NULL;
}

/* func_0012DE98 */
void *func_0012DE98(void *a0, void *a1, void *a2, void *a3) {
    return func_10FE50(a0, a1, a2, a3);
}

/* func_0012DEB8 */
void *func_0012DEB8(void *a0, void *a1, void *a2, void *a3) {
    int key = (int)(long)a0;
    int *table = (int *)a1;
    int count = (int)(long)a2;
    int i;
    (void)a3;

    if (count <= 0 || table == NULL) {
        return &D_4E2CB8;
    }

    for (i = 0; i < count; i++) {
        if (table[i * 2] == key) {
            return (void *)(long)table[i * 2 + 1];
        }
    }
    return &D_4E2CB8;
}

/* func_0012DF08 */
void *func_0012DF08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x30));
    r_v0 = (long)&D_48FF90;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_a0 = (long)(r_a0 + (0x1));
    r_a1 = (long)(r_sp + 0);
    r_t1 = (long)&D_48FF90;
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x7)); }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x0)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0xF)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0x8)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x17)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x10)); }
    if (r_sp) { *(long *)((char *)r_sp + (0x7)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0xF)) = (long)r_a3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x8)) = (long)r_a3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x17)) = (long)r_t0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_t0; }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x1F)); }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x18)); }
    if (r_sp) { *(long *)((char *)r_sp + (0x1F)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x18)) = (long)r_v1; }
    r_a2 = (long)(0 + (0x4));
    r_v0 = (long)func_12DD00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012DF78 */
void *func_0012DF78(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x30));
    r_v0 = (long)&D_48FFB0;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_a1 = (long)(r_sp + 0);
    r_t1 = (long)&D_48FFB0;
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x7)); }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x0)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0xF)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0x8)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x17)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x10)); }
    if (r_sp) { *(long *)((char *)r_sp + (0x7)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0xF)) = (long)r_a3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x8)) = (long)r_a3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x17)) = (long)r_t0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_t0; }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x1F)); }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x18)); }
    if (r_sp) { *(long *)((char *)r_sp + (0x1F)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x18)) = (long)r_v1; }
    r_a2 = (long)(0 + (0x4));
    r_v0 = (long)func_12DD00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012DFE0 */
void *func_0012DFE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x40));
    r_v0 = (long)&D_490010;
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_a1 = (long)(r_sp + 0);
    r_t1 = (long)&D_490010;
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x7)); }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x0)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0xF)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0x8)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x17)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x10)); }
    if (r_sp) { *(long *)((char *)r_sp + (0x7)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0xF)) = (long)r_a3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x8)) = (long)r_a3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x17)) = (long)r_t0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_t0; }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x1F)); }
    if (r_t1) { r_v1 = *(long *)((char *)r_t1 + (0x18)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0x27)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0x20)); }
    if (r_sp) { *(long *)((char *)r_sp + (0x1F)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x18)) = (long)r_v1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x27)) = (long)r_a3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_a3; }
    r_a2 = (long)(0 + (0x5));
    r_v0 = (long)func_12DD00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_0012E058 */
void *func_0012E058(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a2 = (long)(r_a1 + 0);
    r_a1 = (long)(r_a0 + 0);
    r_a0 = (long)(0 + 0);
    return func_0012DE98((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012E068((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E068 */
void *func_0012E068(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_v0 = (long)((long)r_s2 < (long)(0x3) ? 1 : 0);
    if (r_v0 != 0) { if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; } return func_0012E0B8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a0 = (long)&D_490048;
    r_a1 = (long)((0x490000 >> 16) << 16);
    r_a3 = (long)((0x490000 >> 16) << 16);
    r_a0 = (long)&D_490048;
    return func_0012E0A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E0A8 */
void *func_0012E0A8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a1 = (long)(r_a1 + (0x68));
    r_a3 = (long)(r_a3 + (0x78));
    r_a2 = (long)(0 + (0x230));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012E0B8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E0B8 */
void *func_0012E0B8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s3;
    r_s0 = (long)((0x500000 >> 16) << 16);
    r_s3 = (long)((0x500000 >> 16) << 16);
    return func_0012E118((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012E0C8:
    if (r_a1 == r_v0) { r_v0 = (long)((long)r_a1 < (long)(-0x77) ? 1 : 0); return func_0012E118((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)((long)r_a1 < (long)(-0x77) ? 1 : 0);
    if (r_v0 == 0) { r_v0 = (long)(0 + (-0x79)); goto _lbl_L0012E0E8; }
    r_v0 = (long)(0 + (-0x79));
    if (r_a1 == r_v0) { r_a0 = (long)((0x490000 >> 16) << 16); return func_0012E118((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a0 = (long)((0x490000 >> 16) << 16);
    r_a0 = (long)&D_490088;
    goto _lbl_L0012E0F4;
_lbl_L0012E0E8:
    r_v0 = (long)(0 + (-0x65));
    if (r_a1 == r_v0) { r_a0 = (long)&D_490088; goto _lbl_L0012E104; }
    r_a0 = (long)&D_490088;
_lbl_L0012E0F4:
    r_a0 = (long)&D_490088;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012E118((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012E104:
    r_a0 = (long)&D_4900A8;
    r_a0 = (long)&D_4900A8;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012E118((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012E118((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E118 */
void *func_0012E118(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a0 = (long)&D_4900C0;
    r_a0 = (long)&D_4900C0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_4E2D00;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490078;
    r_a0 = (long)&D_4E2D00;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490078;
    r_a2 = (long)(0 + (0x240));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_L0012E174;
_lbl_L0012E14C:
    r_a0 = (long)(r_a0 + (0xE0));
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_4E2D00;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490078;
    r_a0 = (long)&D_4E2D00;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490078;
    r_a2 = (long)(0 + (0x241));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012E174:
    r_v0 = (long)func_10FF40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012E178((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E178 */
void *func_0012E178(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_a1 = (long)(r_v0 + 0);
    if (r_a1 != 0) { r_v0 = (long)(0 + (-0x78)); return func_0012E0B8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (-0x78));
    r_a0 = (long)(r_s0 + (-0x6900));
    r_a1 = (long)(0 + (0xD4));
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s3 + (-0x6828));
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(0 + (0x50));
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 == 0) { if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); } return func_0012E208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_s1 != 0) { r_a0 = (long)(r_s1 + 0); return func_0012E1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a0 = (long)(r_s1 + 0);
    r_a0 = (long)((unsigned long)r_s2 << (4));
    r_v0 = (long)func_116F40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0x4C)); }
    return func_0012E1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E1C0 */
void *func_0012E1C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_s1 = (long)(r_v0 + 0);
    r_v1 = (long)(r_v1 | (0x1));
    if (r_s1 != 0) { if (r_s0) { *(int *)((char *)r_s0 + (0x4C)) = (int)r_v1; } goto _lbl_L0012E1F0; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x4C)) = (int)r_v1; }
    r_a0 = (long)&D_490100;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490078;
    r_a0 = (long)&D_490100;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490078;
    r_a2 = (long)(0 + (0x24F));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012E1F0:
    r_a0 = (long)(r_s1 + 0);
_lbl_L0012E1F4:
    r_a1 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012F980((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s3 + (-0x6828));
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s2 + 0);
    return func_0012E208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E208 */
void *func_0012E208(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_a2 = (long)(0 + (0x1));
    /* recursive self-call omitted */
    if (r_s3) { *(int *)((char *)r_s3 + (-0x6828)) = (int)r_s1; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x4)) = (int)r_s2; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_s4; }
    r_v0 = (long)func_00128990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((unsigned long)r_v0 >> (16));
    if (r_sp) { *(short *)((char *)r_sp + (0x0)) = (short)r_v0; }
    if (r_sp) { *(short *)((char *)r_sp + (0x2)) = (short)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x3)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x0)); }
    if (r_s0) { *(int *)((char *)r_s0 + (0x23)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x20)) = (int)r_v0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
_lbl_L0012E240:
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_0012E260 */
void *func_0012E260(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)((0x500000 >> 16) << 16);
    if (r_v0) { *(int *)((char *)r_v0 + (-0x680C)) = (int)r_a0; }
    return (void *)r_v0;
}

/* func_0012E270 */
void *func_0012E270(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_v0 = (long)&D_4F97D8;
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a0; }
    r_v0 = (long)&D_4F97D8;
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x3)); }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x0)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0x23)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x20)) = (int)r_v1; }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_0012E298 */
void *func_0012E298(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_v0 = (long)func_0012E0A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x0)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E0B8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012E2D0 */
void *func_0012E2D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x30));
    r_a0 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_a2 = (long)(r_sp | (0x4));
    r_v0 = (long)func_110940((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((0x500000 >> 16) << 16);
    return func_0012E2F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E2F0 */
void *func_0012E2F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_s0 = (long)(r_v1 + (-0x6828));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x4C)); }
    r_v0 = (long)(r_v0 & (0x1));
    if (r_v0 == 0) { if (r_s0) { *(int *)((char *)r_s0 + (0x4)) = (int)0; } goto _lbl_L0012E31C; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x4)) = (int)0; }
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (-0x6828)); }
    r_v0 = (long)func_116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x4C)); }
    r_v1 = (long)(0 + (-0x2));
    r_v0 = (long)(r_v0 & r_v1);
    if (r_s0) { *(int *)((char *)r_s0 + (0x4C)) = (int)r_v0; }
_lbl_L0012E31C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    return func_0012E320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E320 */
void *func_0012E320(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012E330 */
void *func_0012E330(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    if (a0 == NULL) {
        return (void *)1L;
    }
    return (void *)(long)*(int *)a0;
}

/* func_0012E348 */
void *func_0012E348(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    if (a0 == NULL) {
        return NULL;
    }
    return (void *)(long)*((int *)a0 + 1);
}

/* func_0012E360 */
void *func_0012E360(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    if (a0 == NULL) {
        return NULL;
    }
    return (void *)(long)*((int *)a0 + 2);
}

/* func_0012E378 */
void *func_0012E378(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0xC)); }
    r_v0 = (long)(r_s1 & (0x1));
    if (r_v0 == 0) { if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); } goto _lbl_L0012E3B0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0x8)); }
    r_v0 = (long)func_116F68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s1 ^ (0x1));
    if (r_s0) { *(int *)((char *)r_s0 + (0xC)) = (int)r_v0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
_lbl_L0012E3B0:
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012E3C0 */
void *func_0012E3C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s0; }
    return func_0012E3C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E3C8 */
void *func_0012E3C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s2; }
    r_s0 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s1; }
    r_s2 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_v0 = (long)((unsigned long)r_s0 < (unsigned long)(0x3) ? 1 : 0);
    if (r_v0 != 0) { r_s1 = (long)(r_a0 + 0); goto _lbl_L0012E400; }
    r_s1 = (long)(r_a0 + 0);
    r_a0 = (long)&D_490068;
    r_a2 = (long)&D_490110;
    r_a0 = (long)&D_490068;
    r_a2 = (long)&D_490110;
    r_a1 = (long)(0 + (0x2BA));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012E400:
    if (r_s1 != 0) { r_t0 = (long)(r_sp + (0x10)); goto _lbl_L0012E418; }
    r_t0 = (long)(r_sp + (0x10));
    r_a0 = (long)(0 + 0);
    r_v0 = (long)func_0012E2F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_t0 = (long)(r_sp + (0x10));
_lbl_L0012E418:
    r_v1 = (long)(0 + (0x1));
    r_a2 = (long)(0 + (0x1));
    r_v0 = (long)(r_sp + (0x14));
_lbl_L0012E428:
    if (r_v0) { *(int *)((char *)r_v0 + (0x0)) = (int)r_v1; }
    r_a2 = (long)(r_a2 + (-0x1));
    r_v0 = (long)(r_v0 + (-0x4));
    if ((long)r_a2 >= 0) goto _lbl_L0012E428;
    r_a3 = (long)(r_s2 + 0);
    return func_0012E448((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E448 */
void *func_0012E448(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_a0 = (long)(r_sp + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(0 + (0x2));
    r_v0 = (long)func_00126040((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_s0 <= 0) { if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); } goto _lbl_L0012E494; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    r_a0 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s0 + 0);
    r_a1 = (long)(r_sp + 0);
_lbl_L0012E470:
    if (r_a1) { r_v0 = *(unsigned short *)((char *)r_a1 + (0x0)); }
    r_a2 = (long)(r_a2 + (-0x1));
    if (r_a0) { *(short *)((char *)r_a0 + (0x0)) = (short)r_v0; }
    if (r_a1) { r_v1 = *(unsigned short *)((char *)r_a1 + (0x2)); }
    r_a1 = (long)(r_a1 + (0x4));
    if (r_a0) { *(short *)((char *)r_a0 + (0x2)) = (short)r_v1; }
    if (r_a2 != 0) { r_a0 = (long)(r_a0 + (0x10)); goto _lbl_L0012E470; }
    r_a0 = (long)(r_a0 + (0x10));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
_lbl_L0012E494:
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x20)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_0012E4A8 */
void *func_0012E4A8(void *a0, void *a1, void *a2, void *a3) {
    int idx = (int)(long)a0;
    int limit = *(int *)((char *)&D_4F97D8 + 4);
    (void)a1; (void)a2; (void)a3;

    if (idx >= limit) {
        return NULL;
    }
    return (void *)(long)(*(int *)((char *)&D_4F97D8 - 0x6828) + (idx << 4));
}

/* func_0012E4D8 */
void *func_0012E4D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v1 = (long)((0x500000 >> 16) << 16);
    r_a0 = (long)(0 + 0);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (-0x6828)); }
    if (r_v0 == 0) return func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012E4E8 */
void *func_0012E4E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a1 = (long)(r_v1 + (-0x6828));
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (0x4)); }
_lbl_L0012E4F0:
    r_v0 = (long)(r_a0 + 0);
    return (void *)r_v0;
}

/* func_0012E4F8 */
void *func_0012E4F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_00128990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((unsigned long)r_v0 >> (16));
    if (r_sp) { *(short *)((char *)r_sp + (0x10)) = (short)r_v0; }
    if (r_sp) { *(short *)((char *)r_sp + (0x12)) = (short)r_v1; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x13)); }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x10)); }
    if (r_sp) { *(int *)((char *)r_sp + (0x3)) = (int)r_v0; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_v0; }
    if (r_s0 == 0) { if (r_sp) { r_a2 = *(unsigned short *)((char *)r_sp + (0x0)); } goto _lbl_L0012E544; }
    if (r_sp) { r_a2 = *(unsigned short *)((char *)r_sp + (0x0)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x3)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x0)); }
    if (r_sp) { *(int *)((char *)r_sp + (0x3)) = (int)r_v0; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_v0; }
    if (r_sp) { r_a2 = *(unsigned short *)((char *)r_sp + (0x0)); }
_lbl_L0012E544:
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    if (r_sp) { r_v1 = *(unsigned short *)((char *)r_sp + (0x2)); }
    r_v0 = (long)(r_v0 & r_a0);
    r_a1 = (long)(0 + (-0x1));
    r_a1 = (long)((unsigned long)r_a1 << (0));
    r_a1 = (long)(r_a1 | (0xFFFF));
    r_v0 = (long)(r_v0 | r_a2);
    r_v1 = (long)((unsigned long)r_v1 << (16));
    r_v0 = (long)(r_v0 & r_a1);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    r_v0 = (long)(r_v1 | r_v0);
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x20)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_0012E580 */
void *func_0012E580(void *a0, void *a1, void *a2, void *a3) {
    void *entry = func_0012E4E8((void *)((unsigned long)a0 & 0xFFFF0000), a1, a2, a3);
    if (entry == NULL) {
        return NULL;
    }
    return (void *)(long)*(short *)((char *)entry + 4);
}

/* func_0012E5C0 */
void *func_0012E5C0(void *a0, void *a1, void *a2, void *a3) {
    void *entry = func_0012E4E8((void *)((unsigned long)a0 & 0xFFFF0000), a1, a2, a3);
    if (entry == NULL) {
        return NULL;
    }
    return (void *)(long)*(int *)((char *)entry + 8);
}

/* func_0012E600 */
void *func_0012E600(void *a0, void *a1, void *a2, void *a3) {
    void *entry = func_0012E4E8((void *)((unsigned long)a0 & 0xFFFF0000), a1, a2, a3);
    if (entry == NULL) {
        return (void *)-1L;
    }
    return (void *)(long)*(short *)((char *)entry + 6);
}

/* func_0012E640 */
void *func_0012E640(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x30));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a0; }
    r_s0 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (0x0)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    if (r_v1 == 0) { r_v0 = (long)(r_s0 + 0); goto _lbl_L0012E68C; }
    r_v0 = (long)(r_s0 + 0);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0xC)); }
    r_s0 = (long)(r_v0 & (0x3));
    r_v0 = (long)(r_v0 | (0x3));
    r_v0 = (long)(r_v0 ^ (0x3));
    if (r_v1) { *(int *)((char *)r_v1 + (0xC)) = (int)r_v0; }
    r_v0 = (long)(r_s0 + 0);
_lbl_L0012E68C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012E6A0 */
void *func_0012E6A0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_a0 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s1 = (long)(0 + 0);
    r_v0 = (long)func_0012E2F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012E320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a3 = *(short *)((char *)r_sp + (0x0)); }
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)(0 + (-0x1));
    if (r_a3 == r_a0) { if (r_sp) { r_t0 = *(unsigned short *)((char *)r_sp + (0x0)); } goto _lbl_L0012E750; }
    if (r_sp) { r_t0 = *(unsigned short *)((char *)r_sp + (0x0)); }
    if (r_sp) { r_a1 = *(unsigned short *)((char *)r_sp + (0x2)); }
    r_v0 = (long)((unsigned long)r_a1 << (16));
    r_v1 = (long)((long)r_v0 >> (16));
    if (r_v1 == r_a0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L0012E754; }
    r_v0 = (long)(r_s1 + 0);
    if ((long)r_a2 <= 0) { r_a0 = (long)(0 + 0); goto _lbl_L0012E754; }
    r_a0 = (long)(0 + 0);
    if (r_s0) { r_v0 = *(short *)((char *)r_s0 + (0x2)); }
    if (r_v0 != r_v1) { r_a0 = (long)(r_a0 + (0x1)); goto _lbl_L0012E718; }
    r_a0 = (long)(r_a0 + (0x1));
    if (r_s0) { r_v0 = *(short *)((char *)r_s0 + (0x0)); }
    if (r_v0 == r_a3) { r_s1 = (long)(r_s0 + 0); goto _lbl_L0012E750; }
    r_s1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_a0 + (0x1));
_lbl_L0012E718:
    r_v0 = (long)((long)r_a0 < (long)r_a2 ? 1 : 0);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (0x10)); goto _lbl_L0012E750; }
    r_s0 = (long)(r_s0 + (0x10));
    r_v0 = (long)((unsigned long)r_a1 << (16));
    if (r_s0) { r_v1 = *(short *)((char *)r_s0 + (0x2)); }
    r_v0 = (long)((long)r_v0 >> (16));
    if (r_v1 != r_v0) { r_a0 = (long)(r_a0 + (0x1)); goto _lbl_L0012E718; }
    r_a0 = (long)(r_a0 + (0x1));
    r_v0 = (long)((unsigned long)r_t0 << (16));
    if (r_s0) { r_v1 = *(short *)((char *)r_s0 + (0x0)); }
    r_v0 = (long)((long)r_v0 >> (16));
    if (r_v1 != r_v0) { r_a0 = (long)(r_a0 + (0x1)); goto _lbl_L0012E718; }
    r_a0 = (long)(r_a0 + (0x1));
    r_s1 = (long)(r_s0 + 0);
_lbl_L0012E750:
    r_v0 = (long)(r_s1 + 0);
_lbl_L0012E754:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_0012E768 */
void *func_0012E768(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)(r_a0 + 0);
    return (void *)r_v0;
}

/* func_0012E770 */
void *func_0012E770(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_0012ECA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_0012E790 */
void *func_0012E790(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)(0 + (0x3));
    if (r_a1 == r_v0) { r_v0 = (long)((long)r_a1 < (long)(0x4) ? 1 : 0); goto _lbl_L0012E7D0; }
    r_v0 = (long)((long)r_a1 < (long)(0x4) ? 1 : 0);
    if (r_v0 == 0) { r_v0 = (long)(0 + (0x2)); goto _lbl_L0012E7B4; }
    r_v0 = (long)(0 + (0x2));
    if (r_a1 == r_v0) { r_a0 = (long)(r_a0 + (0x104)); goto _lbl_L0012E7C8; }
    r_a0 = (long)(r_a0 + (0x104));
    return (void *)r_v0;
_lbl_L0012E7B4:
    r_v0 = (long)(0 + (0x4));
    if (r_a1 == r_v0) { r_a0 = (long)(r_a0 + (0x184)); goto _lbl_L0012E7DC; }
    r_a0 = (long)(r_a0 + (0x184));
    return (void *)r_v0;
_lbl_L0012E7C8:
    r_a1 = (long)(r_a2 + 0);
    return (void *)strcpy((char *)r_a0, (const char *)r_a1);
_lbl_L0012E7D0:
    r_a0 = (long)(r_a0 + (0x144));
    r_a1 = (long)(r_a2 + 0);
    return (void *)strcpy((char *)r_a0, (const char *)r_a1);
_lbl_L0012E7DC:
    r_a1 = (long)(r_a2 + 0);
    return (void *)strcpy((char *)r_a0, (const char *)r_a1);
    return (void *)r_v0;
}

/* func_0012E7E8 */
void *func_0012E7E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x50));
    r_a3 = (long)(0 + (0x44));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_t0 = (long)(0 + (0x58));
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_v0 = (long)(0 + (0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_v1 = (long)(0 + (0x53));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x32));
    if (r_s0) { *(char *)((char *)r_s0 + (0x0)) = (char)r_v0; }
    r_t1 = (long)&D_38C8C0;
    if (r_s0) { *(char *)((char *)r_s0 + (0x1)) = (char)r_v1; }
    r_v0 = (long)&D_38C900;
    if (r_s0) { *(char *)((char *)r_s0 + (0x2)) = (char)r_a0; }
    r_v1 = (long)&D_38C930;
    if (r_s0) { *(char *)((char *)r_s0 + (0x3)) = (char)r_a3; }
    r_t2 = (long)&D_38C960;
    if (r_s0) { *(short *)((char *)r_s0 + (0x6)) = (short)r_a2; }
    r_a0 = (long)(r_s0 + (0xC0));
    if (r_s0) { *(int *)((char *)r_s0 + (0xC)) = (int)r_t0; }
    r_s1 = (long)(r_s0 + (0x104));
    r_t3 = (long)&D_38C8C0;
    if (r_t3) { r_a2 = *(long *)((char *)r_t3 + (0x7)); }
    if (r_t3) { r_a2 = *(long *)((char *)r_t3 + (0x0)); }
    if (r_t3) { r_a3 = *(long *)((char *)r_t3 + (0xF)); }
    if (r_t3) { r_a3 = *(long *)((char *)r_t3 + (0x8)); }
    if (r_t3) { r_t0 = *(long *)((char *)r_t3 + (0x17)); }
    if (r_t3) { r_t0 = *(long *)((char *)r_t3 + (0x10)); }
    if (r_s0) { *(long *)((char *)r_s0 + (0x17)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x10)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x1F)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x18)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x27)) = (long)r_t0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x20)) = (long)r_t0; }
    if (r_t3) { r_a2 = *(long *)((char *)r_t3 + (0x1F)); }
    if (r_t3) { r_a2 = *(long *)((char *)r_t3 + (0x18)); }
    if (r_t3) { r_a3 = *(long *)((char *)r_t3 + (0x27)); }
    if (r_t3) { r_a3 = *(long *)((char *)r_t3 + (0x20)); }
    if (r_t3) { r_t0 = *(long *)((char *)r_t3 + (0x2F)); }
    if (r_t3) { r_t0 = *(long *)((char *)r_t3 + (0x28)); }
    if (r_s0) { *(long *)((char *)r_s0 + (0x2F)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x28)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x37)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x30)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x3F)) = (long)r_t0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x38)) = (long)r_t0; }
    if (r_t3) { r_a2 = *(long *)((char *)r_t3 + (0x37)); }
    if (r_t3) { r_a2 = *(long *)((char *)r_t3 + (0x30)); }
    if (r_t3) { r_a3 = *(long *)((char *)r_t3 + (0x3F)); }
    if (r_t3) { r_a3 = *(long *)((char *)r_t3 + (0x38)); }
    if (r_s0) { *(long *)((char *)r_s0 + (0x47)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x40)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x4F)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x48)) = (long)r_a3; }
    r_s2 = (long)(r_s0 + (0x144));
    r_t1 = (long)&D_38C900;
    if (r_t1) { r_a2 = *(long *)((char *)r_t1 + (0x7)); }
    if (r_t1) { r_a2 = *(long *)((char *)r_t1 + (0x0)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0xF)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0x8)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x17)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x10)); }
    if (r_s0) { *(long *)((char *)r_s0 + (0x57)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x50)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x5F)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x58)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x67)) = (long)r_t0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x60)) = (long)r_t0; }
    if (r_t1) { r_a2 = *(long *)((char *)r_t1 + (0x1F)); }
    if (r_t1) { r_a2 = *(long *)((char *)r_t1 + (0x18)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0x27)); }
    if (r_t1) { r_a3 = *(long *)((char *)r_t1 + (0x20)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x2F)); }
    if (r_t1) { r_t0 = *(long *)((char *)r_t1 + (0x28)); }
    if (r_s0) { *(long *)((char *)r_s0 + (0x6F)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x68)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x77)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x70)) = (long)r_a3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x7F)) = (long)r_t0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x78)) = (long)r_t0; }
    r_a3 = (long)&D_38C930;
    if (r_a3) { r_t3 = *(long *)((char *)r_a3 + (0x7)); }
    if (r_a3) { r_t3 = *(long *)((char *)r_a3 + (0x0)); }
    if (r_a3) { r_v0 = *(long *)((char *)r_a3 + (0xF)); }
    if (r_a3) { r_v0 = *(long *)((char *)r_a3 + (0x8)); }
    if (r_a3) { r_a2 = *(long *)((char *)r_a3 + (0x17)); }
    if (r_a3) { r_a2 = *(long *)((char *)r_a3 + (0x10)); }
    if (r_s0) { *(long *)((char *)r_s0 + (0x87)) = (long)r_t3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x80)) = (long)r_t3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x8F)) = (long)r_v0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x88)) = (long)r_v0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x97)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x90)) = (long)r_a2; }
    if (r_a3) { r_t3 = *(long *)((char *)r_a3 + (0x1F)); }
    if (r_a3) { r_t3 = *(long *)((char *)r_a3 + (0x18)); }
    if (r_a3) { r_v0 = *(long *)((char *)r_a3 + (0x27)); }
    if (r_a3) { r_v0 = *(long *)((char *)r_a3 + (0x20)); }
    if (r_a3) { r_a2 = *(long *)((char *)r_a3 + (0x2F)); }
    if (r_a3) { r_a2 = *(long *)((char *)r_a3 + (0x28)); }
    if (r_s0) { *(long *)((char *)r_s0 + (0x9F)) = (long)r_t3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0x98)) = (long)r_t3; }
    if (r_s0) { *(long *)((char *)r_s0 + (0xA7)) = (long)r_v0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0xA0)) = (long)r_v0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0xAF)) = (long)r_a2; }
    if (r_s0) { *(long *)((char *)r_s0 + (0xA8)) = (long)r_a2; }
    r_v0 = (long)&D_38C960;
    if (r_v0) { r_t0 = *(long *)((char *)r_v0 + (0x7)); }
    if (r_v0) { r_t0 = *(long *)((char *)r_v0 + (0x0)); }
    if (r_v0) { r_t1 = *(long *)((char *)r_v0 + (0xF)); }
    if (r_v0) { r_t1 = *(long *)((char *)r_v0 + (0x8)); }
    if (r_s0) { *(long *)((char *)r_s0 + (0xB7)) = (long)r_t0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0xB0)) = (long)r_t0; }
    if (r_s0) { *(long *)((char *)r_s0 + (0xBF)) = (long)r_t1; }
    if (r_s0) { *(long *)((char *)r_s0 + (0xB8)) = (long)r_t1; }
    r_s3 = (long)(r_s0 + (0x184));
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(0 + (0x2));
    r_v0 = (long)func_0012ECA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_v0 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(0 + (0x3));
    r_v0 = (long)func_0012ECA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_v0 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(0 + (0x4));
    r_v0 = (long)func_0012ECA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s3 + 0);
    r_a1 = (long)(r_v0 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s0 + (0x4));
    r_a1 = (long)(0 + (0x2));
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + (0x8));
    r_a1 = (long)(0 + (0x4));
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + (0x1C4));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    r_a1 = (long)(0 + (0x200));
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012EA40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EA40 */
void *func_0012EA40(void *a0, void *a1, void *a2, void *a3) {
    if (a0 == NULL) {
        return NULL;
    }
    strcpy((char *)a0, (const char *)a1);
    *(int *)((char *)a0 + 0x1C) = (int)(long)a2;
    *(int *)((char *)a0 + 0x18) = (int)(long)a3;
    return a0;
}

/* func_0012EA90 */
void *func_0012EA90(void *a0, void *a1, void *a2, void *a3) {
    if (a0 == NULL) {
        return NULL;
    }
    strcpy((char *)a0, (const char *)a1);
    *(int *)((char *)a0 + 0x1C) = (int)(long)a3;
    *(int *)((char *)a0 + 0x18) = (int)(long)a2;
    return a0;
}

/* func_0012EAE0 */
void *func_0012EAE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_490130;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_490130;
    r_a2 = (long)(0 + (0xB));
    r_v0 = (long)func_12DD00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    return (void *)r_v0;
}

/* func_0012EB00 */
void *func_0012EB00(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (0x10));
    return func_0012F7E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012EB10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EB10 */
void *func_0012EB10(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)func_0012F298((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_a0 = (long)(r_v0 + 0);
    r_sp = (long)(r_sp + (0x20));
    return func_0012E7E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012EB40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EB40 */
void *func_0012EB40(void *a0, void *a1, void *a2, void *a3) {
    (void)a2; (void)a3;
    if (a0 != NULL) {
        *(int *)((char *)a0 + 0x18) = (int)(long)a1;
    }
    return NULL;
}

/* func_0012EB50 */
void *func_0012EB50(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)func_0012F298((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_a0 = (long)(r_v0 + 0);
    r_sp = (long)(r_sp + (0x20));
    return func_0012E7E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012EB80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EB80 */
void *func_0012EB80(void *a0, void *a1, void *a2, void *a3) {
    (void)a2; (void)a3;
    if (a0 != NULL) {
        *(int *)((char *)a0 + 0x1C) = (int)(long)a1;
    }
    return NULL;
}

/* func_0012EB90 */
void *func_0012EB90(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    if (r_s1 == 0) { r_s0 = (long)(r_a1 + 0); goto _lbl_L0012EC00; }
    r_s0 = (long)(r_a1 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x18) ? 1 : 0);
    if (r_v0 == 0) { r_a0 = (long)&D_4901C8; goto _lbl_L0012EBDC; }
    r_a0 = (long)&D_4901C8;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4901F8;
    r_a0 = (long)&D_4901C8;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4901F8;
    r_a2 = (long)(0 + (0x3F8));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012EBDC:
    if (r_s0 == 0) { if (r_s1) { *(char *)((char *)r_s1 + (0x0)) = (char)0; } goto _lbl_L0012EC00; }
    if (r_s1) { *(char *)((char *)r_s1 + (0x0)) = (char)0; }
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)strcpy((char *)r_a0, (const char *)r_a1);
_lbl_L0012EC00:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012EC18 */
void *func_0012EC18(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x30));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (0x0)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E3C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (0x2));
    r_a0 = (long)(r_s0 + 0);
    if (r_v0 != 0) r_a1 = r_v0;
    r_a2 = (long)(0 + 0);
    r_a3 = (long)(0 + 0);
    r_t0 = (long)(0 + (0x1));
    r_v0 = (long)func_0012F610((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012EC70 */
void *func_0012EC70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_0012EB00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return func_0012EDA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012EC90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EC90 */
void *func_0012EC90(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v1 = (long)((0x500000 >> 16) << 16);
    r_a0 = (long)(0 + (0x1));
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (-0x680C)); }
    if (r_v0 == r_a0) { r_v0 = (long)((0x500000 >> 16) << 16); return func_0012ECA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)((0x500000 >> 16) << 16);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (-0x6900)); }
    return func_0012ECA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012ECA8 */
void *func_0012ECA8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    if (r_v1 == 0) r_a0 = 0;
_lbl_L0012ECAC:
    r_v0 = (long)(r_a0 + 0);
    return (void *)r_v0;
    r_sp = (long)(r_sp + (-0x70));
    r_v0 = (long)&D_38C970;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    r_s1 = (long)&D_4F97D8;
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    r_v1 = (long)&D_4F97D8;
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s5 = (long)&D_38C970;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s4 = (long)(0 + (-0x7F));
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_s3 = (long)(0 + (-0x80));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s2 = (long)(0 + (-0x7E));
    if (r_v1) { r_s0 = *(int *)((char *)r_v1 + (0x8)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
_lbl_L0012ED00:
    r_v1 = (long)(r_v1 + r_s5);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0x0)); }
    return (void *)r_v0;
}

/* func_0012ED08 */
void *func_0012ED08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s1 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s1;
    (void)r_s4;
    r_a0 = (long)(r_s1 + (-0x6828));
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v1 = (long)(r_v0 + 0);
    if (r_v1 == r_s4) { r_a0 = (long)(0 + 0); return func_0012ED28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a0 = (long)(0 + 0);
    r_v0 = (long)((long)r_v1 < (long)(-0x7E) ? 1 : 0);
    if (r_v0 == 0) return func_0012ED28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012ED28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012ED28 */
void *func_0012ED28(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    if (r_v1 == r_s3) { r_s0 = (long)(r_s0 + r_v1); goto _lbl_L0012ED58; }
    r_s0 = (long)(r_s0 + r_v1);
    r_a0 = (long)(0 + (0x1));
    goto _lbl_L0012ED6C;
_lbl_L0012ED38:
    if (r_v1 == r_s2) { r_s0 = (long)(r_s0 + (0x1)); goto _lbl_L0012ED68; }
    r_s0 = (long)(r_s0 + (0x1));
    if (r_v1 != 0) { r_s0 = (long)(r_s0 + r_v1); goto _lbl_L0012ED68; }
    r_s0 = (long)(r_s0 + r_v1);
    goto _lbl_L0012ED6C;
_lbl_L0012ED50:
    r_s0 = (long)(r_s0 + (0x1));
    goto _lbl_L0012ED6C;
_lbl_L0012ED58:
    r_v0 = (long)func_0012E118((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    goto _lbl_L0012ED80;
_lbl_L0012ED68:
    r_a0 = (long)(0 + (0x1));
_lbl_L0012ED6C:
    if (r_a0 != 0) { r_v1 = (long)((unsigned long)r_s0 << (2)); return func_0012ECA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)(r_s1 + (-0x6828));
    if (r_v0) { *(int *)((char *)r_v0 + (0x8)) = (int)r_s0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
_lbl_L0012ED80:
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_0012EDA0 */
void *func_0012EDA0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)((0x500000 >> 16) << 16);
    r_sp = (long)(r_sp + (-0x10));
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (-0x6824)); }
    r_a1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    if (r_v1 == 0) { r_v0 = (long)(0 + 0); goto _lbl_L0012EDE4; }
    r_v0 = (long)(0 + 0);
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (0x23)); }
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (0x20)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a1 = (long)(r_a1 + (0xC));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_00130670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (-0x7F));
    if (r_v0 == 0) r_v1 = 0;
    r_v0 = (long)(r_v1 + 0);
_lbl_L0012EDE4:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_0012EDF0 */
void *func_0012EDF0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s0 = (long)(r_a0 + (0xC));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s1 = (long)(0 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012E178((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_a0 = (long)(r_s0 + 0); return func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a0 = (long)(r_s0 + 0);
    r_s1 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012E1C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EE20 */
void *func_0012EE20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_v0 = (long)(r_s1 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012EE38 */
void *func_0012EE38(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0x1C)); }
    r_v0 = (long)(0 + (-0x2));
    r_a0 = (long)(0 + (-0x7E));
    r_v1 = (long)(r_v1 ^ (0x1));
    if (r_v1 != 0) r_v0 = r_a0;
    return (void *)r_v0;
}

/* func_0012EE50 */
void *func_0012EE50(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0x1C)); }
    r_v0 = (long)(0 + (-0x3));
    if (r_v1 == 0) r_v0 = 0;
    return (void *)r_v0;
}

/* func_0012EE60 */
void *func_0012EE60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s0 = (long)(r_a0 + (-0x1));
    r_v0 = (long)((unsigned long)r_s0 < (unsigned long)(0x4) ? 1 : 0);
    if (r_v0 != 0) { if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; } goto _lbl_L0012EE98; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_a0 = (long)&D_490210;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490250;
    r_a0 = (long)&D_490210;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490250;
    r_a2 = (long)(0 + (0x4BF));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012EE98:
    r_v0 = (long)&D_38C8B0;
    r_v1 = (long)((unsigned long)r_s0 << (2));
    r_v0 = (long)&D_38C8B0;
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_v1 = (long)(r_v1 + r_v0);
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012EEC0 */
void *func_0012EEC0(void *a0, void *a1, void *a2, void *a3) {
    int base;
    (void)a2; (void)a3;
    if (a0 == NULL) {
        return NULL;
    }
    base = *(int *)((char *)a0 + 0x1C);
    if (base == 0) {
        return NULL;
    }
    return (void *)(long)(base + ((unsigned long)a1 << 5));
}

/* func_0012EEE0 */
void *func_0012EEE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(0 + 0);
    if (r_s1 == 0) { if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; } return func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s3 = (long)((0x390000 >> 16) << 16);
    if (r_s1) { r_a2 = *(int *)((char *)r_s1 + (0x18)); }
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (-0x3750)); }
    r_v0 = (long)func_0012F208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012EF18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EF18 */
void *func_0012EF18(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s1;
    (void)r_s2;
    r_a1 = (long)(r_s1 + 0);
    if (r_v0 == 0) { r_a2 = (long)(0 + 0); goto _lbl_L0012EF28; }
    r_a2 = (long)(0 + 0);
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (0x18)); }
_lbl_L0012EF28:
    r_v0 = (long)((unsigned long)r_s2 < (unsigned long)(0x5) ? 1 : 0);
    if (r_v0 == 0) { r_v0 = (long)((0x490000 >> 16) << 16); return func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)((0x490000 >> 16) << 16);
    r_v1 = (long)((unsigned long)r_s2 << (2));
    return func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EF38 */
void *func_0012EF38(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_v0 = (long)(r_v0 + (0x270));
    r_v1 = (long)(r_v1 + r_v0);
    if (r_v1) { r_a0 = *(int *)((char *)r_v1 + (0x0)); }
    return (void *)r_v0;
    r_s0 = (long)(r_s1 + 0);
    goto _lbl_L0012EF74;
    if (r_s3) { r_s0 = *(int *)((char *)r_s3 + (-0x3750)); }
    goto _lbl_L0012EF74;
    r_s0 = (long)(r_a2 + (0x104));
    goto _lbl_L0012EF70;
    r_s0 = (long)(r_a2 + (0x144));
    goto _lbl_L0012EF70;
    r_s0 = (long)(r_a2 + (0x184));
_lbl_L0012EF70:
    if (r_a2 == 0) r_s0 = 0;
_lbl_L0012EF74:
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_0012EF98 */
void *func_0012EF98(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s0 = (long)((0x500000 >> 16) << 16);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (-0x6900)); }
    if (r_v0 == 0) return func_0012EFB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012EFB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012EFB0 */
void *func_0012EFB0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_a0 = (long)(r_s0 + (-0x6900));
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v1 = (long)(0 + (-0x80));
    if (r_v0 == r_v1) { if (r_s0) { *(int *)((char *)r_s0 + (-0x6900)) = (int)0; } goto _lbl_L0012EFC8; }
    if (r_s0) { *(int *)((char *)r_s0 + (-0x6900)) = (int)0; }
_lbl_L0012EFC8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012EFD8 */
void *func_0012EFD8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_s7;
    r_sp = (long)(r_sp + (-0x90));
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s7; }
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s6; }
    r_s7 = (long)(0 + (-0x7F));
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    r_s6 = (long)(0 + (-0x80));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    r_s5 = (long)(0 + (-0x7E));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s3 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_s1) { r_s0 = *(int *)((char *)r_s1 + (0x4)); }
    r_v1 = (long)((unsigned long)r_s0 << (2));
_lbl_L0012F020:
    r_a0 = (long)(r_s1 + 0);
    r_v1 = (long)(r_v1 + r_s4);
    r_s2 = (long)(0 + 0);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0x0)); }
    if (r_s1) { *(int *)((char *)r_s1 + (0xAC)) = (int)r_v0; }
    if (r_v0) { r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v1 = (long)(r_v0 + 0);
    if (r_v1 == r_s7) { r_v0 = (long)((long)r_v1 < (long)(-0x7E) ? 1 : 0); goto _lbl_L0012F078; }
    r_v0 = (long)((long)r_v1 < (long)(-0x7E) ? 1 : 0);
    if (r_v0 == 0) goto _lbl_L0012F05C;
    if (r_v1 == r_s6) { r_s3 = (long)(0 + (-0x80)); goto _lbl_L0012F084; }
    r_s3 = (long)(0 + (-0x80));
    r_s0 = (long)(r_s0 + r_v1);
    goto _lbl_L0012F070;
_lbl_L0012F05C:
    if (r_v1 == r_s5) { r_s0 = (long)(r_s0 + (0x1)); goto _lbl_L0012F080; }
    r_s0 = (long)(r_s0 + (0x1));
    if (r_v1 == 0) goto _lbl_L0012F084;
    r_s0 = (long)(r_s0 + r_v1);
_lbl_L0012F070:
    r_s2 = (long)(0 + (0x1));
    goto _lbl_L0012F084;
_lbl_L0012F078:
    r_s0 = (long)(r_s0 + (0x1));
    goto _lbl_L0012F084;
_lbl_L0012F080:
    r_s2 = (long)(0 + (0x1));
_lbl_L0012F084:
    if (r_s2 != 0) { r_v1 = (long)((unsigned long)r_s0 << (2)); goto _lbl_L0012F020; }
    r_v1 = (long)((unsigned long)r_s0 << (2));
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0x8)); }
    r_v0 = (long)(r_s3 + 0);
    if (r_s1) { *(int *)((char *)r_s1 + (0x4)) = (int)r_s0; }
    r_v1 = (long)(r_v1 + (0x1));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x80)); }
    return func_0012F0A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F0A0 */
void *func_0012F0A0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_s7;
    if (r_s1) { *(int *)((char *)r_s1 + (0x8)) = (int)r_v1; }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
}

/* func_0012F0D0 */
void *func_0012F0D0(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    if (a0 != NULL) {
        *(int *)((char *)a0 + 0xC) = 0;
        *(int *)((char *)a0 + 0x0) = 0;
        *(int *)((char *)a0 + 0x8) = 0;
    }
    return NULL;
}

/* func_0012F0F0 */
void *func_0012F0F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_a0 = (long)(r_v0 + (0xB4));
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a3; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x0)) = (int)r_a1; }
    return func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F108 */
void *func_0012F108(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    if (r_v0) { *(int *)((char *)r_v0 + (0xB0)) = (int)r_a2; }
    r_a1 = (long)(0 + (0x20));
    if (r_v0) { *(int *)((char *)r_v0 + (0x4)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x8)) = (int)0; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x3)); }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x0)); }
    if (r_v0) { *(int *)((char *)r_v0 + (0xF)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0xC)) = (int)r_v1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x10)) = (int)r_t0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_t1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0xA8)) = (int)r_t2; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x14)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x18)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x1C)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x20)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x24)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x28)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)0; }
    if (r_v0) { *(int *)((char *)r_v0 + (0xAC)) = (int)0; }
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012F168 */
void *func_0012F168(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if ((long)r_a1 <= 0) { if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (0xC)); } goto _lbl_L0012F178; }
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (0xC)); }
    r_a2 = (long)(r_a2 | (0x2));
    return func_0012F188((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012F178:
    r_v0 = (long)(0 + (-0x1));
    r_v1 = (long)(r_a2 | (0x1));
    r_v0 = (long)((long)r_v0 < (long)r_a1 ? 1 : 0);
    if (r_v0 == 0) r_a2 = r_v1;
    return func_0012F188((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F188 */
void *func_0012F188(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    if (r_a0) { *(int *)((char *)r_a0 + (0xC)) = (int)r_a2; }
    return (void *)r_v0;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if ((long)r_a2 < 0) { if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; } goto _lbl_L0012F1B8; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s0 = (long)(0 + (0x1));
    r_v0 = (long)(0 + (0x2));
    if (r_a2 == 0) r_s0 = r_v0;
    return func_0012F208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012F1B8:
    r_v0 = (long)(0 + (-0x1));
    if (r_a1 == r_v0) { r_s0 = (long)(0 + (0x1)); goto _lbl_L0012F1F0; }
    r_s0 = (long)(0 + (0x1));
    if ((long)r_a1 >= 0) { r_v0 = (long)(0 + (-0x2)); goto _lbl_L0012F1DC; }
    r_v0 = (long)(0 + (-0x2));
    if (r_a1 == r_v0) { r_s0 = (long)(0 + (-0x1)); goto _lbl_L0012F1EC; }
    r_s0 = (long)(0 + (-0x1));
    if (r_s1) { r_v0 = *(short *)((char *)r_s1 + (0x4)); }
    goto _lbl_L0012F1F4;
_lbl_L0012F1DC:
    if (r_a1 != 0) { r_s0 = (long)(0 + (-0x1)); goto _lbl_L0012F1F0; }
    r_s0 = (long)(0 + (-0x1));
    r_s0 = (long)(0 + 0);
    goto _lbl_L0012F1F0;
_lbl_L0012F1EC:
    r_s0 = (long)(0 + (0x2));
_lbl_L0012F1F0:
    if (r_s1) { r_v0 = *(short *)((char *)r_s1 + (0x4)); }
_lbl_L0012F1F4:
    if (r_v0 == 0) { r_v0 = (long)((long)r_a1 < (long)(-0x2) ? 1 : 0); return func_0012F208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)((long)r_a1 < (long)(-0x2) ? 1 : 0);
    if (r_s0 != 0) return func_0012F208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_v0 = *(short *)((char *)r_s1 + (0x6)); }
    return (void *)r_v0;
}

/* func_0012F208 */
void *func_0012F208(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_v0 = (long)(~(0 | r_v0));
    r_s0 = (long)((unsigned long)r_v0 < (unsigned long)(0x1) ? 1 : 0);
_lbl_L0012F210:
    r_v0 = (long)((long)r_a1 < (long)(-0x2) ? 1 : 0);
_lbl_L0012F214:
    if (r_v0 != 0) { r_a1 = (long)(0 + (-0x1)); goto _lbl_L0012F230; }
    r_a1 = (long)(0 + (-0x1));
    if ((long)r_a1 < 0) { r_a1 = (long)(0 + (0x1)); goto _lbl_L0012F230; }
    r_a1 = (long)(0 + (0x1));
    if (r_a1 != 0) { r_a1 = (long)(0 + (-0x1)); goto _lbl_L0012F230; }
    r_a1 = (long)(0 + (-0x1));
    r_a1 = (long)(0 + 0);
_lbl_L0012F230:
    if (r_a1 == 0) { if (r_s1) { *(short *)((char *)r_s1 + (0x6)) = (short)r_s0; } goto _lbl_L0012F244; }
    if (r_s1) { *(short *)((char *)r_s1 + (0x6)) = (short)r_s0; }
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012EFB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(short *)((char *)r_s1 + (0x6)) = (short)r_s0; }
_lbl_L0012F244:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_0012F258 */
void *func_0012F258(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_t0 + 0);
    r_s0 = (long)(r_a0 + 0);
    if (r_s0 == 0) { if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; } return func_0012F298((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_v0 = (long)func_0012F6B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s2 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    return func_0012F298((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F298 */
void *func_0012F298(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x40));
    return func_0012EFD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012F2A8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_0012F2C0 */
void *func_0012F2C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (0xAC)); }
    r_a3 = (long)(0 + 0);
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (0xA8)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0x0)); }
    if (r_v0 == r_a2) { r_t0 = (long)(0 + 0); goto _lbl_L0012F304; }
    r_t0 = (long)(0 + 0);
    r_t1 = (long)(0 + 0);
_lbl_L0012F2E0:
    r_a3 = (long)(r_a3 + (0x1));
    r_v0 = (long)((unsigned long)r_a3 << (2));
    r_v0 = (long)(r_v0 + r_a0);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (0x0)); }
    if (r_v1 != r_a2) goto _lbl_L0012F2E0;
    r_v1 = (long)(r_t1 + r_a0);
    goto _lbl_L0012F30C;
_lbl_L0012F304:
    r_t1 = (long)(0 + 0);
    r_v1 = (long)(r_t1 + r_a0);
_lbl_L0012F30C:
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0x0)); }
    if (r_v0 == r_a1) goto _lbl_L0012F334;
_lbl_L0012F318:
    r_v1 = (long)(r_v1 + (0x4));
    r_t0 = (long)(r_t0 + (0x1));
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0x0)); }
    if (r_v0 != r_a1) goto _lbl_L0012F318;
_lbl_L0012F334:
    r_v0 = (long)(r_t0 - r_a3);
    return (void *)r_v0;
}

/* func_0012F340 */
void *func_0012F340(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_s0 = (long)(r_a1 + 0);
    goto _lbl_L0012F37C;
_lbl_L0012F378:
    r_s0 = (long)(r_s0 + (0x40));
_lbl_L0012F37C:
    r_v0 = (long)((long)r_s1 < (long)r_s3 ? 1 : 0);
    if (r_v0 == 0) { r_a0 = (long)(r_s4 + 0); return func_0012F388((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a0 = (long)(r_s4 + 0);
    return func_0012F388((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F388 */
void *func_0012F388(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_a1 = (long)(r_s0 + (0x20));
    r_v0 = (long)strcmp((const char *)r_a0, (const char *)r_a1);
    if (r_v0 != 0) { r_s1 = (long)(r_s1 + (0x1)); return func_0012F340((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s1 = (long)(r_s1 + (0x1));
    r_s2 = (long)(r_s0 + 0);
_lbl_L0012F39C:
    r_v0 = (long)(r_s2 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_0012F3C0 */
void *func_0012F3C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_s2 == 0) { if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; } return func_0012F428((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_a1 == 0) { r_s1 = (long)(0 + 0); return func_0012F428((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s1 = (long)(0 + 0);
    if (r_a1) { r_s0 = *(int *)((char *)r_a1 + (0x1C)); }
    goto _lbl_L0012F404;
_lbl_L0012F400:
    r_s0 = (long)(r_s0 + (0x20));
_lbl_L0012F404:
    r_v0 = (long)((long)r_s1 < (long)r_s4 ? 1 : 0);
    if (r_v0 == 0) { r_a0 = (long)(r_s2 + 0); return func_0012F428((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)((unsigned long)r_s1 << (5));
    r_v0 = (long)strcmp((const char *)r_a0, (const char *)r_a1);
    return func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F418 */
void *func_0012F418(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s3;
    r_a1 = (long)(r_s0 + r_a1);
    if (r_v0 != 0) { r_s1 = (long)(r_s1 + (0x1)); return func_0012F3C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s1 = (long)(r_s1 + (0x1));
    r_s3 = (long)(r_s0 + 0);
    return func_0012F428((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F428 */
void *func_0012F428(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s3;
    (void)r_s4;
    r_v0 = (long)(r_s3 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    return func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F438 */
void *func_0012F438(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_0012F450 */
void *func_0012F450(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a1 + 0);
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_v0 = (long)func_0012ED28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
    if (r_s3 != 0) { if (r_s1) { r_a2 = *(int *)((char *)r_s1 + (0x18)); } return func_0012F4B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s1) { r_a2 = *(int *)((char *)r_s1 + (0x18)); }
    r_s0 = (long)&D_490288;
    r_a0 = (long)(r_s2 + 0);
    r_s0 = (long)&D_490288;
    r_v0 = (long)func_12DE28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_a2 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_4E2D40;
    r_a1 = (long)((0x490000 >> 16) << 16);
    r_a3 = (long)((0x490000 >> 16) << 16);
    r_a0 = (long)&D_4E2D40;
    return func_0012F4B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F4B0 */
void *func_0012F4B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s1 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s1;
    (void)r_s3;
    r_a1 = (long)(r_a1 + (0x68));
    r_a3 = (long)(r_a3 + (0x2C8));
    r_a2 = (long)(0 + (0x664));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_a2 = *(int *)((char *)r_s1 + (0x18)); }
_lbl_L0012F4C4:
    r_a0 = (long)(r_s3 + 0);
    return func_0012F4C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F4C8 */
void *func_0012F4C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012F208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
    if (r_s3 != 0) { r_v0 = (long)(r_s3 + 0); return func_0012F500((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(r_s3 + 0);
    r_s0 = (long)&D_490288;
    r_a0 = (long)(r_s2 + 0);
    r_s0 = (long)&D_490288;
    r_v0 = (long)func_12DE28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_v0 + 0);
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)((0x490000 >> 16) << 16);
    return func_0012F500((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F500 */
void *func_0012F500(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4902C8;
    r_a0 = (long)(r_a0 + (0x2E0));
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4902C8;
    r_a2 = (long)(0 + (0x66A));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s3 + 0);
_lbl_L0012F520:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_0012F540 */
void *func_0012F540(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v1 = *(short *)((char *)r_a0 + (0x4)); }
    r_a1 = (long)(0 + 0);
    r_v0 = (long)(0 + (0x1));
    if (r_v1 == r_v0) { if (r_a0) { r_a3 = *(short *)((char *)r_a0 + (0x6)); } goto _lbl_L0012F580; }
    if (r_a0) { r_a3 = *(short *)((char *)r_a0 + (0x6)); }
    r_v0 = (long)((long)r_v1 < (long)(0x2) ? 1 : 0);
    if (r_v0 == 0) { r_v0 = (long)(0 + (0x3)); goto _lbl_L0012F570; }
    r_v0 = (long)(0 + (0x3));
    if (r_v1 == 0) { r_a1 = (long)(0 + (-0x7F)); goto _lbl_L0012F584; }
    r_a1 = (long)(0 + (-0x7F));
    goto _lbl_L0012F584;
_lbl_L0012F570:
    if (r_v1 == r_v0) { r_a1 = (long)(0 + (-0x7E)); goto _lbl_L0012F584; }
    r_a1 = (long)(0 + (-0x7E));
    goto _lbl_L0012F584;
_lbl_L0012F580:
    r_a1 = (long)(0 + (-0x7F));
_lbl_L0012F584:
    if (r_a1 != 0) { r_v0 = (long)(0 + (0x1)); return func_0012F5C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (0x1));
    if (r_a3 == 0) { r_a1 = (long)(0 + (-0x7E)); return func_0012F5C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a1 = (long)(0 + (-0x7E));
    if ((long)r_a3 > 0) { r_v0 = (long)(0 + (0x2)); goto _lbl_L0012F5B0; }
    r_v0 = (long)(0 + (0x2));
    r_v0 = (long)(0 + (-0x1));
    if (r_a3 == r_v0) { r_a1 = (long)(0 + (-0x7F)); goto _lbl_L0012F5C4; }
    r_a1 = (long)(0 + (-0x7F));
    r_v0 = (long)(0 + (0x1));
    return func_0012F5C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012F5B0:
    if (r_a3 == r_v0) { r_a1 = (long)(0 + (-0x7C)); goto _lbl_L0012F5C0; }
    r_a1 = (long)(0 + (-0x7C));
    r_v0 = (long)(0 + (0x1));
    return func_0012F5C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012F5C0:
    if (r_a2 != 0) r_a1 = 0;
_lbl_L0012F5C4:
    r_v0 = (long)(0 + (0x1));
    return func_0012F5C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F5C8 */
void *func_0012F5C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1 != 0) r_v0 = r_a1;
    return (void *)r_v0;
    if (r_a0) { r_v0 = *(short *)((char *)r_a0 + (0x4)); }
    r_v0 = (long)(r_v0 ^ (0x3));
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x1) ? 1 : 0);
    return (void *)r_v0;
}

/* func_0012F5E0 */
void *func_0012F5E0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v0 = *(short *)((char *)r_a0 + (0x4)); }
    r_v0 = (long)(r_v0 ^ (0x2));
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x1) ? 1 : 0);
    return (void *)r_v0;
}

/* func_0012F5F0 */
void *func_0012F5F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    r_t0 = (long)(r_a1 + 0);
    r_v0 = (long)(0 + 0);
    r_a1 = (long)(0 + (-0xB));
    r_a3 = (long)((long)r_t0 < (long)(0x1) ? 1 : 0);
    r_a1 = (long)((long)r_a1 < (long)r_t0 ? 1 : 0);
    if (r_a3 != 0) r_v0 = r_t0;
    r_v1 = (long)(0 + (-0xA));
    r_sp = (long)(r_sp + (-0x20));
    return func_0012F610((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F610 */
void *func_0012F610(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t0;
    if (r_a1 == 0) r_v0 = r_v1;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_a0 = (long)(r_a0 - r_v0);
    if (r_a0) { r_s0 = *(int *)((char *)r_a0 + (0x0)); }
    r_v0 = (long)(r_s0 + (0x7D));
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x2) ? 1 : 0);
    if (r_v0 != 0) { r_a0 = (long)(r_a2 + 0); goto _lbl_L0012F648; }
    r_a0 = (long)(r_a2 + 0);
    r_v0 = (long)(0 + (-0x7F));
    if (r_s0 != r_v0) { r_v0 = (long)(r_s0 + 0); goto _lbl_L0012F658; }
    r_v0 = (long)(r_s0 + 0);
    r_a0 = (long)(r_a2 + 0);
_lbl_L0012F648:
    r_a1 = (long)(r_t0 + 0);
    r_a2 = (long)(0 + (-0x1));
    r_v0 = (long)func_0012EFD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s0 + 0);
_lbl_L0012F658:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012F668 */
void *func_0012F668(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a0 = (long)(r_a0 ^ (0x2));
    r_v1 = (long)(0 + (0x2000));
    r_v0 = (long)(0 + (0x400));
    if (r_a0 != 0) r_v0 = r_v1;
    return (void *)r_v0;
}

/* func_0012F680 */
void *func_0012F680(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a0 = (long)(r_a0 + (-0x1));
    r_v1 = (long)(0 + (-0x1));
    r_a0 = (long)(r_a0 + r_a1);
    r_v1 = (long)((long)r_v1 < (long)r_a1 ? 1 : 0);
    /* unhandled: div */
    r_v0 = (long)(r_a1 + (0x3FF));
    if (r_v1 != 0) r_v0 = r_a1;
    if (r_a1 == 0) { /* break */ goto _lbl_L0012F6A4; }
    /* break */
_lbl_L0012F6A4:
    r_v0 = (long)((long)r_v0 >> (10));
    return func_0012F6A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F6A8 */
void *func_0012F6A8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    /* unhandled: mflo */
    return (void *)r_v0;
}

/* func_0012F6B0 */
void *func_0012F6B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s6 = 0, r_s7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s6;
    (void)r_s7;
    /* unhandled: mult */
    r_sp = (long)(r_sp + (-0x90));
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s7; }
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s6; }
    r_s7 = (long)(r_a2 + 0);
    return func_0012F6C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F6C8 */
void *func_0012F6C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s5 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_a0 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_ra; }
    r_s1 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    r_s2 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    return func_0012F6F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F6F8 */
void *func_0012F6F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_s7;
    if (r_s3) { r_s0 = *(int *)((char *)r_s3 + (0x1C)); }
    if (r_s3) { r_s4 = *(int *)((char *)r_s3 + (0x18)); }
    r_v0 = (long)func_0012F4B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_s4 <= 0) { r_s6 = (long)(r_v0 + 0); goto _lbl_L0012F744; }
    r_s6 = (long)(r_v0 + 0);
    r_s0 = (long)(r_s0 + (0x1C));
_lbl_L0012F710:
    r_a0 = (long)(r_s3 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012F7B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_a1 = (long)(r_s6 + 0); goto _lbl_L0012F734; }
    r_a1 = (long)(r_s6 + 0);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0x0)); }
    r_s5 = (long)(r_s5 + (0x1));
    r_v0 = (long)func_0012F4C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s2 + r_v0);
_lbl_L0012F734:
    r_s1 = (long)(r_s1 + (0x1));
    r_v0 = (long)((long)r_s1 < (long)r_s4 ? 1 : 0);
    if (r_v0 != 0) { r_s0 = (long)(r_s0 + (0x20)); goto _lbl_L0012F710; }
    r_s0 = (long)(r_s0 + (0x20));
_lbl_L0012F744:
    if (r_s7 != 0) { if (r_s7) { *(int *)((char *)r_s7 + (0x0)) = (int)r_s5; } goto _lbl_L0012F74C; }
    if (r_s7) { *(int *)((char *)r_s7 + (0x0)) = (int)r_s5; }
_lbl_L0012F74C:
    r_v0 = (long)(r_s2 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    return func_0012F768((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F768 */
void *func_0012F768(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
}

/* func_0012F780 */
void *func_0012F780(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)(r_a0 - r_a1);
    r_v1 = (long)(0 + (-0x1));
    r_v1 = (long)((long)r_v1 < (long)r_v0 ? 1 : 0);
    if (r_v1 == 0) r_v0 = 0;
    r_v0 = (long)(r_v0 + (0x1));
    r_v1 = (long)((unsigned long)r_v0 >> (31));
    r_v0 = (long)(r_v0 + r_v1);
    return (void *)r_v0;
}

/* func_0012F7A0 */
void *func_0012F7A0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)((long)r_v0 >> (1));
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    return func_0012F7B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F7B0 */
void *func_0012F7B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a1) { r_a1 = *(short *)((char *)r_a1 + (0x4)); }
    r_v0 = (long)func_0012F610((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_0012F7C8 */
void *func_0012F7C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s1 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s0 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)(r_a3 + 0);
    return func_0012F7E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F7E8 */
void *func_0012F7E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    r_s2 = (long)(r_t0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_a2 = (long)(r_sp + 0);
    r_v0 = (long)func_0012F500((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s4 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x2));
    if (r_s0 != r_v0) { r_s0 = (long)(0 + 0); goto _lbl_L0012F834; }
    r_s0 = (long)(0 + 0);
    if (r_sp) { r_a0 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)(r_s1 + 0);
    r_a0 = (long)(r_a0 + (0x2));
    r_v0 = (long)func_0012F5C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012F5C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    goto _lbl_L0012F838;
_lbl_L0012F834:
    r_v1 = (long)(0 + 0);
_lbl_L0012F838:
    r_v0 = (long)(r_s4 + r_s0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    r_v0 = (long)(r_v0 + r_v1);
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_0012F860 */
void *func_0012F860(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0x8)); }
    return (void *)r_v0;
}

/* func_0012F868 */
void *func_0012F868(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)((unsigned long)r_a2 << (3));
    r_v1 = (long)(r_a1 ^ (0x2));
    if (r_v1 == 0) r_v0 = r_a2;
    if (r_a0) { *(short *)((char *)r_a0 + (0x4)) = (short)r_a1; }
    if (r_a0) { *(int *)((char *)r_a0 + (0x8)) = (int)r_v0; }
    return (void *)r_v0;
}

/* func_0012F880 */
void *func_0012F880(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012F6A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((long)r_v0 < (long)r_s0 ? 1 : 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_v0 = (long)(r_v0 ^ (0x1));
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012F8B0 */
void *func_0012F8B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(r_a1 + 0);
    r_a1 = (long)(0 + (0x32));
    if (r_s2) { r_a0 = *(int *)((char *)r_s2 + (0x34)); }
    r_v0 = (long)func_0012F7A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v1 = (long)(r_s0 + (0x1)); goto _lbl_L0012F900; }
    r_v1 = (long)(r_s0 + (0x1));
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0xB0)); }
    if (r_s3 != 0) r_s0 = r_v1;
    r_a0 = (long)(0 + (0x1));
    if (r_v0) { *(int *)((char *)r_v0 + (0x4)) = (int)r_s0; }
    if (r_s1 == 0) r_s1 = r_a0;
_lbl_L0012F900:
    r_v0 = (long)(r_s1 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_0012F920 */
void *func_0012F920(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v1 = *(unsigned char *)((char *)r_a0 + (0x0)); }
    r_v0 = (long)(0 + (0x2E));
    if (r_v1 != r_v0) { r_a1 = (long)(0 + 0); goto _lbl_L0012F94C; }
    r_a1 = (long)(0 + 0);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (0x1)); }
    if (r_v0 == 0) { r_a1 = (long)(0 + (0x1)); goto _lbl_L0012F94C; }
    r_a1 = (long)(0 + (0x1));
    if (r_v0 != r_v1) { r_v0 = (long)(r_a1 + 0); goto _lbl_L0012F950; }
    r_v0 = (long)(r_a1 + 0);
    if (r_a0) { r_v0 = *(unsigned char *)((char *)r_a0 + (0x2)); }
    r_a1 = (long)((unsigned long)r_v0 < (unsigned long)(0x1) ? 1 : 0);
_lbl_L0012F94C:
    r_v0 = (long)(r_a1 + 0);
_lbl_L0012F950:
    return (void *)r_v0;
}

/* func_0012F958 */
void *func_0012F958(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)(~(0 | r_a0));
    r_v0 = (long)(r_v0 & r_a1);
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x1) ? 1 : 0);
    return (void *)r_v0;
}

/* func_0012F968 */
void *func_0012F968(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0x1C)); }
    r_a1 = (long)((unsigned long)r_a1 << (5));
    return func_0012F970((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F970 */
void *func_0012F970(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a1 = (long)(r_a1 + r_v0);
    if (r_a1) { r_v0 = *(int *)((char *)r_a1 + (0x18)); }
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_v0 ? 1 : 0);
    return (void *)r_v0;
}

/* func_0012F980 */
void *func_0012F980(void *a0, void *a1, void *a2, void *a3) {
    long r_a0 = (long)a0;
    (void)a1; (void)a2; (void)a3;
    if (r_a0 == 0) {
        return (void *)0L;
    }
    if (r_a0 < 4) {
        return (void *)1L;
    }
    return (void *)2L;
}

/* func_0012F9A0 */
void *func_0012F9A0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a0 = (long)&D_4F9840;
    r_a1 = (long)(0 + (0x600));
    r_a0 = (long)&D_4F9840;
    return (void *)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012F9B0 */
void *func_0012F9B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_t7;
    r_sp = (long)(r_sp + (-0xB0));
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s2; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_s4; }
    r_a0 = (long)&D_4902F0;
    r_s4 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0xA0)) = (long)r_ra; }
    r_a0 = (long)&D_4902F0;
    if (r_sp) { *(long *)((char *)r_sp + (0x90)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s0; }
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4 == 0) { r_a0 = (long)((0x490000 >> 16) << 16); return func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a0 = (long)((0x490000 >> 16) << 16);
    if ((long)r_s4 <= 0) { r_s3 = (long)(0 + 0); return func_0012FA80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s3 = (long)(0 + 0);
    r_s5 = (long)((0x490000 >> 16) << 16);
    if (r_s2) { r_t7 = *(unsigned char *)((char *)r_s2 + (0xA)); }
_lbl_L0012FA00:
    r_s1 = (long)(r_s2 + (0x20));
    if (r_s2) { r_s0 = *(unsigned char *)((char *)r_s2 + (0xB)); }
    return func_0012FA08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FA08 */
void *func_0012FA08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s2 = 0, r_s3 = 0, r_s5 = 0, r_t4 = 0, r_t6 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s2;
    (void)r_s3;
    (void)r_s5;
    (void)r_t4;
    (void)r_t6;
    r_a0 = (long)(r_s5 + (0x300));
    if (r_s2) { r_t6 = *(unsigned char *)((char *)r_s2 + (0xC)); }
    r_s3 = (long)(r_s3 + (0x1));
    if (r_s2) { r_v0 = *(unsigned char *)((char *)r_s2 + (0xD)); }
    if (r_s2) { r_v1 = *(unsigned short *)((char *)r_s2 + (0xE)); }
    if (r_s2) { r_t4 = *(int *)((char *)r_s2 + (0x10)); }
    return func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FA20 */
void *func_0012FA20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s2 = 0, r_t5 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s2;
    (void)r_t5;
    if (r_s2) { r_t5 = *(unsigned short *)((char *)r_s2 + (0x14)); }
    if (r_s2) { r_a1 = *(unsigned char *)((char *)r_s2 + (0x1)); }
    if (r_s2) { r_a2 = *(unsigned char *)((char *)r_s2 + (0x2)); }
    if (r_s2) { r_a3 = *(unsigned char *)((char *)r_s2 + (0x3)); }
    return func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FA30 */
void *func_0012FA30(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s2 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s2;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    (void)r_t7;
    if (r_s2) { r_t0 = *(unsigned char *)((char *)r_s2 + (0x4)); }
    if (r_s2) { r_t1 = *(unsigned char *)((char *)r_s2 + (0x5)); }
    if (r_s2) { r_t2 = *(unsigned short *)((char *)r_s2 + (0x6)); }
    if (r_s2) { r_t3 = *(unsigned char *)((char *)r_s2 + (0x9)); }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_t7; }
    r_s2 = (long)(r_s2 + (0x40));
    if (r_sp) { *(int *)((char *)r_sp + (0x8)) = (int)r_s0; }
    if (r_sp) { *(int *)((char *)r_sp + (0x10)) = (int)r_t6; }
    if (r_sp) { *(int *)((char *)r_sp + (0x18)) = (int)r_v0; }
    if (r_sp) { *(int *)((char *)r_sp + (0x20)) = (int)r_v1; }
    if (r_sp) { *(int *)((char *)r_sp + (0x28)) = (int)r_t4; }
    if (r_sp) { *(int *)((char *)r_sp + (0x30)) = (int)r_t5; }
    return func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FA60 */
void *func_0012FA60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t7;
    if (r_sp) { *(int *)((char *)r_sp + (0x38)) = (int)r_s1; }
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((long)r_s3 < (long)r_s4 ? 1 : 0);
    if (r_v1 != 0) { if (r_s2) { r_t7 = *(unsigned char *)((char *)r_s2 + (0xA)); } return func_0012F9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_s2) { r_t7 = *(unsigned char *)((char *)r_s2 + (0xA)); }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0xA0)); }
    return func_0012FA80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012FA7C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0xA0)); }
    return func_0012FA80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FA80 */
void *func_0012FA80(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x90)); }
    r_a0 = (long)(r_a0 + (0x360));
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x40)); }
    r_sp = (long)(r_sp + (0xB0));
    return (void *)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012FAA4:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0xA0)); }
_lbl_L0012FAA8:
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x90)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x40)); }
    r_sp = (long)(r_sp + (0xB0));
    return (void *)r_v0;
}

/* func_0012FAC8 */
void *func_0012FAC8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a2 = (long)((long)r_a1 >> (8));
    r_v1 = (long)(0 + (0x7));
    r_v0 = (long)(r_a0 + (0x7));
_lbl_L0012FAD8:
    if (r_v0) { *(char *)((char *)r_v0 + (0x0)) = (char)0; }
    r_v1 = (long)(r_v1 + (-0x1));
    r_v0 = (long)(r_v0 + (-0x1));
    if ((long)r_v1 >= 0) goto _lbl_L0012FAD8;
    r_v1 = (long)(0 + (0x7));
    r_v0 = (long)(r_a0 + (0xF));
_lbl_L0012FB00:
    if (r_v0) { *(char *)((char *)r_v0 + (0x0)) = (char)0; }
    r_v1 = (long)(r_v1 + (-0x1));
    r_v0 = (long)(r_v0 + (-0x1));
    if ((long)r_v1 >= 0) goto _lbl_L0012FB00;
    if (r_a0) { *(char *)((char *)r_a0 + (0x15)) = (char)r_a2; }
    if (r_a0) { *(char *)((char *)r_a0 + (0x14)) = (char)r_a1; }
    return (void *)r_v0;
}

/* func_0012FB28 */
void *func_0012FB28(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0xC)); }
    r_v0 = (long)(r_v0 | (0x1));
    if (r_a0) { *(int *)((char *)r_a0 + (0xC)) = (int)r_v0; }
    return (void *)r_v0;
}

/* func_0012FB38 */
void *func_0012FB38(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s1 = (long)(r_a1 + 0);
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_a1 = (long)((unsigned long)r_s1 << (4));
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_s1 <= 0) return func_0012FBA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012FB60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FB60 */
void *func_0012FB60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_s2 = (long)(0 + (-0x1));
_lbl_L0012FB68:
    r_s1 = (long)(r_s1 + (-0x1));
    r_v0 = (long)func_00128990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((unsigned long)r_v0 >> (16));
    if (r_sp) { *(short *)((char *)r_sp + (0x0)) = (short)r_v0; }
    if (r_s0) { *(short *)((char *)r_s0 + (0x2)) = (short)r_v1; }
    if (r_sp) { *(short *)((char *)r_sp + (0x2)) = (short)r_v1; }
    r_v0 = (long)func_00128990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(short *)((char *)r_s0 + (0x4)) = (short)0; }
    r_v1 = (long)(r_v0 + 0);
    if (r_s0) { *(short *)((char *)r_s0 + (0x6)) = (short)r_s2; }
    if (r_s0) { *(short *)((char *)r_s0 + (0x0)) = (short)r_v1; }
    r_v0 = (long)((unsigned long)r_v0 >> (16));
    if (r_sp) { *(short *)((char *)r_sp + (0x2)) = (short)r_v0; }
    r_s0 = (long)(r_s0 + (0x10));
    if (r_s1 != 0) { if (r_sp) { *(short *)((char *)r_sp + (0x0)) = (short)r_v1; } goto _lbl_L0012FB68; }
    if (r_sp) { *(short *)((char *)r_sp + (0x0)) = (short)r_v1; }
    return func_0012FBA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FBA8 */
void *func_0012FBA8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_0012FBC0 */
void *func_0012FBC0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v1 = (long)(0 + (-0xB));
    r_v0 = (long)(0 + (-0xA));
    r_v1 = (long)((long)r_v1 < (long)r_a0 ? 1 : 0);
    if (r_v1 != 0) r_v0 = r_a0;
    return (void *)r_v0;
}

/* func_0012FBD8 */
void *func_0012FBD8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)((0x500000 >> 16) << 16);
    if (r_v0) { *(int *)((char *)r_v0 + (-0x6800)) = (int)0; }
    return (void *)r_v0;
}

/* func_0012FBE8 */
void *func_0012FBE8(void *a0, void *a1, void *a2, void *a3) {
    if (a0 == NULL) {
        return a3;
    }
    if (a1 != NULL) {
        *(int *)((char *)a1 + 0x20) = (int)(long)a0;
    }
    return func_0012F108(a1, a2, a2, a3);
}

/* func_0012FC18 */
void *func_0012FC18(void *a0, void *a1, void *a2, void *a3) {
    (void)a2; (void)a3;
    *(int *)(0x500000 - 0x6804) = 0;
    if (a0 != NULL) {
        return (void *)0L;
    }
    if (a1 != NULL) {
        *(int *)((char *)a1 + 0x8) = 0;
    }
    return (void *)-0x7FL;
}

/* func_0012FC38 */
void *func_0012FC38(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_v1 = (long)(0 + (-0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    if (r_a0 == r_v1) { r_s0 = (long)(r_t1 + 0); return func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_t1 + 0);
    if (r_a1 == r_v1) { r_a1 = (long)(r_s0 + 0); return func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)func_110A78((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FC60 */
void *func_0012FC60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
_lbl_L0012FC64:
    r_a1 = (long)(r_s0 + 0);
_lbl_L0012FC68:
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012FC80 */
void *func_0012FC80(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    r_s5 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_t1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_s0 = (long)(r_t0 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x3C)) = (int)r_s0; }
    r_a2 = (long)(r_s4 + 0);
    r_a3 = (long)(r_s5 + 0);
    r_t0 = (long)(r_s0 + 0);
    r_t1 = (long)(r_s1 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s2; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s3; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s4; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x38)) = (int)r_s5; }
    r_v0 = (long)func_0012FA80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    return func_0012FD10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FD10 */
void *func_0012FD10(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_0012FD18 */
void *func_0012FD18(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_v1 = (long)(0 + (-0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    if (r_a0 == r_v1) { r_s0 = (long)(r_a3 + 0); goto _lbl_L0012FD44; }
    r_s0 = (long)(r_a3 + 0);
    if (r_a1 == r_v1) { r_a1 = (long)(r_s0 + 0); goto _lbl_L0012FD48; }
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)func_1103D8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012FD44:
    r_a1 = (long)(r_s0 + 0);
_lbl_L0012FD48:
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    return func_0012FD58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FD58 */
void *func_0012FD58(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012FD60 */
void *func_0012FD60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s2 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s0; }
    r_a2 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s2; }
    r_v0 = (long)func_0012FB60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_0012FDD0 */
void *func_0012FDD0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_v1 = (long)(0 + (-0x1));
    return func_0012FDE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FDE0 */
void *func_0012FDE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t2;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    if (r_a0 == r_v1) { r_s0 = (long)(r_t2 + 0); goto _lbl_L0012FDFC; }
    r_s0 = (long)(r_t2 + 0);
    if (r_a1 == r_v1) { r_a1 = (long)(r_s0 + 0); goto _lbl_L0012FE00; }
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)func_110C00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012FDFC:
    r_a1 = (long)(r_s0 + 0);
_lbl_L0012FE00:
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    return func_0012FE10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FE10 */
void *func_0012FE10(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012FE18 */
void *func_0012FE18(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_t0;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x80));
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s6; }
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    r_s6 = (long)(r_t0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    r_s5 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_t2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_ra; }
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_0012FE58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FE58 */
void *func_0012FE58(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
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
    r_s0 = (long)(r_t1 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x40)) = (int)r_s0; }
    r_a2 = (long)(r_s4 + 0);
    r_a3 = (long)(r_s5 + 0);
    r_t0 = (long)(r_s6 + 0);
    r_t1 = (long)(r_s0 + 0);
    r_t2 = (long)(r_s1 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s2; }
    return func_0012FE88((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FE88 */
void *func_0012FE88(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s3; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s4; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x38)) = (int)r_s5; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x3C)) = (int)r_s6; }
    r_v0 = (long)func_0012FC18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
}

/* func_0012FEC8 */
void *func_0012FEC8(void *a0, void *a1, void *a2, void *a3) {
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
    r_v0 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_v1 = (long)(0 + (-0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    if (r_a0 == r_v1) { r_s0 = (long)(r_t0 + 0); goto _lbl_L0012FEF4; }
    r_s0 = (long)(r_t0 + 0);
    if (r_a1 == r_v1) { r_a1 = (long)(r_s0 + 0); return func_0012FEF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)func_1102A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012FEF4:
    r_a1 = (long)(r_s0 + 0);
    return func_0012FEF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FEF8 */
void *func_0012FEF8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012FF10 */
void *func_0012FF10(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a1 + 0);
    return func_0012FF28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_0012FF28 */
void *func_0012FF28(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_t0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_s0 = (long)(r_a3 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x38)) = (int)r_s0; }
    r_a2 = (long)(r_s4 + 0);
    r_a3 = (long)(r_s0 + 0);
    r_t0 = (long)(r_s1 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s2; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s3; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s4; }
    r_v0 = (long)func_0012FD10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_0012FF98 */
void *func_0012FF98(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a1 + 0);
    r_v0 = (long)func_110410((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_0012FFC8 */
void *func_0012FFC8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((0x500000 >> 16) << 16);
    r_a0 = (long)(r_s0 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (-0x67FC)) = (int)r_s0; }
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012FDE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00130010 */
void *func_00130010(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a3 + 0);
    r_v0 = (long)func_110750((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    return func_00130038((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130038 */
void *func_00130038(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00130040 */
void *func_00130040(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00130068((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130068 */
void *func_00130068(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s2 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s0; }
    r_a2 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s2; }
    r_v0 = (long)func_0012FE58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_001300B0 */
void *func_001300B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a3 + 0);
    r_v0 = (long)func_110630((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    return func_001300D8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_001300D8 */
void *func_001300D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_001300E0 */
void *func_001300E0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00130108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130108 */
void *func_00130108(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s2 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s0; }
    r_a2 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s2; }
    r_v0 = (long)func_0012FEF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00130150 */
void *func_00130150(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a3 + 0);
    r_v0 = (long)func_1104C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    return func_00130168((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130168 */
void *func_00130168(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00130180 */
void *func_00130180(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s2 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s0; }
    r_a2 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s2; }
    r_v0 = (long)func_0012FF98((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_001301F0 */
void *func_001301F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a3 + 0);
    r_v0 = (long)func_110FF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00130220 */
void *func_00130220(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((0x500000 >> 16) << 16);
    return func_00130250((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130250 */
void *func_00130250(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)(r_v0 + (-0x6828));
    r_a1 = (long)(r_s2 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s0; }
    r_a2 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s2; }
    r_v0 = (long)func_00130038((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    return func_00130280((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130280 */
void *func_00130280(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00130290 */
void *func_00130290(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)func_110F30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_001302C0 */
void *func_001302C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s0 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)&D_4F97D8;
    return func_001302F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_001302F0 */
void *func_001302F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_a1 = (long)(r_s0 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s0; }
    r_a2 = (long)(r_s2 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s1; }
    r_v0 = (long)func_001300D8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_00130320 */
void *func_00130320(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x20));
    r_t2 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_a3 = (long)(r_t0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_t1 + 0);
    r_v1 = (long)(0 + (-0x1));
    if (r_a0 == r_v1) { r_v0 = (long)(0 + 0); goto _lbl_L00130354; }
    r_v0 = (long)(0 + 0);
    if (r_a1 == r_v1) { r_a1 = (long)(r_s0 + 0); goto _lbl_L00130358; }
    r_a1 = (long)(r_s0 + 0);
    r_t0 = (long)(r_t2 + 0);
    r_v0 = (long)func_1111D8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00130354:
    r_a1 = (long)(r_s0 + 0);
_lbl_L00130358:
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00130370 */
void *func_00130370(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    r_s5 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_t1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_001303A8 */
void *func_001303A8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_t0;
    (void)r_t1;
    r_s0 = (long)(r_t0 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x3C)) = (int)r_s0; }
    r_a2 = (long)(r_s4 + 0);
    r_a3 = (long)(r_s5 + 0);
    r_t0 = (long)(r_s0 + 0);
    r_t1 = (long)(r_s1 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s2; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s3; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s4; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x38)) = (int)r_s5; }
    r_v0 = (long)func_00130168((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_00130408 */
void *func_00130408(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a3 + 0);
    r_v0 = (long)func_1115E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00130438 */
void *func_00130438(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    return func_00130440((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130440 */
void *func_00130440(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(r_a2 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s2 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s0; }
    r_a2 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s1; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s2; }
    r_v0 = (long)func_00130250((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_001304A8 */
void *func_001304A8(void *a0, void *a1, void *a2, void *a3) {
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
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_t0 + 0);
    r_v0 = (long)func_1113B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012FA60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    return func_001304D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_001304D0 */
void *func_001304D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_001304D8 */
void *func_001304D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_t0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_s0 = (long)(r_a3 + 0);
    r_v0 = (long)func_0012FA20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F97D8;
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)&D_4F97D8;
    r_a1 = (long)(r_s3 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x38)) = (int)r_s0; }
    r_a2 = (long)(r_s4 + 0);
    r_a3 = (long)(r_s0 + 0);
    r_t0 = (long)(r_s1 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x2C)) = (int)r_s2; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x30)) = (int)r_s3; }
    if (r_v0) { *(int *)((char *)r_v0 + (0x34)) = (int)r_s4; }
    r_v0 = (long)func_001302F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00130560 */
void *func_00130560(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(r_t0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_s3 = (long)(r_a3 + 0);
    r_v0 = (long)func_110940((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)((0x500000 >> 16) << 16);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (-0x6804)); }
    if (r_v1 != 0) { r_a1 = (long)(r_s0 + 0); goto _lbl_L001305C4; }
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s1 + 0);
    r_a3 = (long)(r_s2 + 0);
    r_t0 = (long)(r_s3 + 0);
    r_t1 = (long)(r_s4 + 0);
    r_v0 = (long)func_00130440((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    return func_001305D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L001305C4:
    r_a2 = (long)(r_s1 + 0);
    r_a3 = (long)(r_s2 + 0);
    r_t0 = (long)(r_s3 + 0);
    return func_001305D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_001305D0 */
void *func_001305D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t1;
    r_t1 = (long)(r_s4 + 0);
    r_v0 = (long)func_001304D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
_lbl_L001305DC:
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_001305F8 */
void *func_001305F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_a2) { r_v0 = *(int *)((char *)r_a2 + (0x0)); }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    if (r_v0 != r_t0) { r_s0 = (long)(r_t1 + 0); return func_00130630((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s0 = (long)(r_t1 + 0);
    if (r_a0 == 0) { r_v0 = (long)(0 + (0x1)); return func_00130630((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (0x1));
    if (r_a0 == r_v0) { r_s1 = (long)(0 + (-0x1)); return func_00130630((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s1 = (long)(0 + (-0x1));
    r_v0 = (long)(r_s1 + 0);
    return func_00130670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00130630((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130630 */
void *func_00130630(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x8)); }
    r_v0 = (long)((long)r_v0 < (long)(0xE11) ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)(r_s1 + 0); return func_00130670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(r_s1 + 0);
    r_a0 = (long)&D_490370;
    r_a0 = (long)&D_490370;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (0x8)) = (int)0; }
    goto _lbl_L0013066C;
_lbl_L00130654:
    if (r_a3) { r_a0 = *(int *)((char *)r_a3 + (0x0)); }
    r_a1 = (long)(r_s0 + 0);
    /* recursive self-call omitted */
    r_s1 = (long)(r_v0 + 0);
    goto _lbl_L0013066C;
_lbl_L00130668:
    r_s1 = (long)(0 + (-0x1));
_lbl_L0013066C:
    r_v0 = (long)(r_s1 + 0);
    return func_00130670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130670 */
void *func_00130670(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00130688 */
void *func_00130688(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(r_t1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0x0)); }
    r_v0 = (long)func_0012FA08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0 == 0) { r_a1 = (long)(r_v0 + 0); goto _lbl_L00130764; }
    r_a1 = (long)(r_v0 + 0);
    if ((long)r_s0 > 0) { r_v0 = (long)(0 + (0x1)); goto _lbl_L001306DC; }
    r_v0 = (long)(0 + (0x1));
    r_v0 = (long)(0 + (-0x1));
    if (r_s0 == r_v0) { r_v0 = (long)(r_s3 + 0); goto _lbl_L00130758; }
    r_v0 = (long)(r_s3 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    goto _lbl_L0013076C;
_lbl_L001306DC:
    if (r_s0 != r_v0) { r_v0 = (long)(r_s3 + 0); goto _lbl_L00130768; }
    r_v0 = (long)(r_s3 + 0);
    r_v0 = (long)(0 + (-0xA));
    if (r_a1 == r_v0) { r_s3 = (long)(0 + (-0x7E)); goto _lbl_L00130720; }
    r_s3 = (long)(0 + (-0x7E));
    r_v0 = (long)((long)r_a1 < (long)(-0xA) ? 1 : 0);
    if (r_v0 != 0) { r_a0 = (long)&D_490390; goto _lbl_L0013070C; }
    r_a0 = (long)&D_490390;
    if ((long)r_a1 > 0) { r_v0 = (long)((long)r_a1 < (long)(-0x2) ? 1 : 0); goto _lbl_L0013070C; }
    r_v0 = (long)((long)r_a1 < (long)(-0x2) ? 1 : 0);
    if (r_v0 == 0) { r_v0 = (long)(r_s3 + 0); goto _lbl_L00130768; }
    r_v0 = (long)(r_s3 + 0);
_lbl_L0013070C:
    r_a0 = (long)&D_490390;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (-0x9));
    if (r_s1) { *(int *)((char *)r_s1 + (0x0)) = (int)r_v1; }
    goto _lbl_L00130764;
_lbl_L00130720:
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0xF)); }
    if (r_s2) { r_v0 = *(int *)((char *)r_s2 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E448((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x2));
    if (r_v0 != r_v1) { r_v0 = (long)(r_s3 + 0); goto _lbl_L00130768; }
    r_v0 = (long)(r_s3 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(0 + (-0xA));
    r_v0 = (long)func_001305D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
    goto _lbl_L00130764;
_lbl_L00130758:
    r_v0 = (long)(0 + (-0x9));
    r_s3 = (long)(0 + (-0x7E));
    if (r_s1) { *(int *)((char *)r_s1 + (0x0)) = (int)r_v0; }
_lbl_L00130764:
    r_v0 = (long)(r_s3 + 0);
_lbl_L00130768:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
_lbl_L0013076C:
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00130788 */
void *func_00130788(void *a0, void *a1, void *a2, void *a3) {
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
    r_v1 = (long)&D_4F97D8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_v1 = (long)&D_4F97D8;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_a3 = (long)(r_a0 + 0);
    if (r_v1) { r_v0 = *(int *)((char *)r_v1 + (0x24)); }
    r_v0 = (long)(r_v0 + (0x1));
    if (r_v1) { *(int *)((char *)r_v1 + (0x24)) = (int)r_v0; }
    r_v0 = (long)((long)r_v0 < (long)(0x4) ? 1 : 0);
    if (r_v0 == 0) { r_s0 = (long)(0 + (-0x7E)); goto _lbl_L001307D4; }
    r_s0 = (long)(0 + (-0x7E));
    if (r_a3) { r_a0 = *(short *)((char *)r_a3 + (0xC)); }
    r_t0 = (long)(r_a3 + (0x2C));
    if (r_a3) { r_a1 = *(short *)((char *)r_a3 + (0xE)); }
    r_a2 = (long)(r_a3 + (0x24));
    r_a3 = (long)(r_a3 + (0x28));
    r_v0 = (long)func_110A78((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) r_s0 = 0;
_lbl_L001307D4:
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_001307E8 */
void *func_001307E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012FA08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (-0xA));
    if (r_v0 != r_v1) { r_v0 = (long)(0 + (-0x7E)); goto _lbl_L00130814; }
    r_v0 = (long)(0 + (-0x7E));
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(0 + (-0xA));
    r_v0 = (long)func_001305D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00130814:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00130828 */
void *func_00130828(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x80));
    r_v1 = (long)&D_4F97D8;
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s4; }
    r_v0 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s1; }
    r_s2 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_ra; }
    r_s1 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s0; }
    if (r_v1) { r_s4 = *(int *)((char *)r_v1 + (-0x6828)); }
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s3; }
    r_v1 = (long)&D_4F97D8;
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (-0x6900)); }
    if (r_v1) { r_s3 = *(int *)((char *)r_v1 + (0x4)); }
    r_v0 = (long)(0 + 0);
    if (r_a2 != 0) { if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a0; } goto _lbl_L001308DC; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a0; }
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012EF18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)&D_00130748;
    r_s0 = (long)&D_00130748;
    r_v0 = (long)func_00128990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_t2 = (long)&D_38C980;
    r_v1 = (long)((unsigned long)r_v0 >> (16));
    if (r_sp) { *(short *)((char *)r_sp + (0x10)) = (short)r_v0; }
    if (r_sp) { *(short *)((char *)r_sp + (0x12)) = (short)r_v1; }
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s1 + 0);
    if (r_sp) { r_a3 = *(int *)((char *)r_sp + (0x10)); }
    r_t2 = (long)&D_38C980;
    r_a0 = (long)(r_s2 + 0);
    r_t0 = (long)(0 + 0);
    r_a3 = (long)(r_a3 & r_v0);
    r_t1 = (long)(0 + 0);
    r_v0 = (long)func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { *(int *)((char *)r_s2 + (0xC4)) = (int)r_s4; }
    r_v0 = (long)(0 + (0x1));
    if (r_s2) { *(int *)((char *)r_s2 + (0xBC)) = (int)r_s3; }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x3)); }
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x0)); }
    if (r_s2) { *(int *)((char *)r_s2 + (0xB7)) = (int)r_v1; }
    if (r_s2) { *(int *)((char *)r_s2 + (0xB4)) = (int)r_v1; }
_lbl_L001308DC:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x20)); }
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
}

/* func_00130900 */
void *func_00130900(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_38C980;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_38C980;
    r_v0 = (long)func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00130920 */
void *func_00130920(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { *(int *)((char *)r_a0 + (0xD0)) = (int)0; }
    r_v0 = (long)(0 + (-0x7E));
    return (void *)r_v0;
}

/* func_00130930 */
void *func_00130930(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_s0) { r_a3 = *(short *)((char *)r_s0 + (0xB6)); }
    if (r_s0) { r_a2 = *(short *)((char *)r_s0 + (0xB4)); }
    if (r_s0) { r_t0 = *(int *)((char *)r_s0 + (0xBC)); }
_lbl_L00130954:
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xD0)); }
    r_v0 = (long)((unsigned long)r_a0 < (unsigned long)r_t0 ? 1 : 0);
    if (r_v0 != 0) return func_00130960((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00130960((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130960 */
void *func_00130960(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    (void)r_t1;
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0xC4)); }
    r_v0 = (long)(0 + (0x2));
    goto _lbl_L001309C8;
_lbl_L0013096C:
    r_v0 = (long)((unsigned long)r_a0 << (4));
    r_a1 = (long)(0 + (-0x1));
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_s2 = *(short *)((char *)r_v0 + (0x0)); }
    if (r_a2 == r_a1) { if (r_v0) { r_s1 = *(short *)((char *)r_v0 + (0x2)); } goto _lbl_L001309A4; }
    if (r_v0) { r_s1 = *(short *)((char *)r_v0 + (0x2)); }
    if (r_a3 == r_a1) { r_a0 = (long)(r_s2 + 0); goto _lbl_L001309A8; }
    r_a0 = (long)(r_s2 + 0);
    if (r_a3 != r_s1) { r_a0 = (long)(r_a0 + (0x1)); goto _lbl_L0013099C; }
    r_a0 = (long)(r_a0 + (0x1));
    if (r_a2 == r_s2) { r_a0 = (long)(r_s2 + 0); goto _lbl_L001309A8; }
    r_a0 = (long)(r_s2 + 0);
_lbl_L0013099C:
    if (r_s0) { *(int *)((char *)r_s0 + (0xD0)) = (int)r_a0; }
    return func_00130930((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L001309A4:
    r_a0 = (long)(r_s2 + 0);
_lbl_L001309A8:
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s0 + (0x24));
    r_a3 = (long)(r_s0 + (0x28));
    r_t0 = (long)(r_s0 + (0x2C));
    r_t1 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012FAC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(short *)((char *)r_s0 + (0xE)) = (short)r_s1; }
    if (r_s0) { *(short *)((char *)r_s0 + (0xC)) = (short)r_s2; }
_lbl_L001309C8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_001309E0 */
void *func_001309E0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_a0 = (long)(0 + (-0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0xD0)); }
    if (r_s0) { r_v0 = *(short *)((char *)r_s0 + (0xC)); }
    if (r_s0) { r_s2 = *(int *)((char *)r_s0 + (0xC4)); }
    if (r_v0 == r_a0) { if (r_s0) { r_v1 = *(short *)((char *)r_s0 + (0xE)); } goto _lbl_L00130A34; }
    if (r_s0) { r_v1 = *(short *)((char *)r_s0 + (0xE)); }
    if (r_v1 == r_a0) { r_a0 = (long)(0 + (0x1)); goto _lbl_L00130A34; }
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x1));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    goto _lbl_L00130A48;
_lbl_L00130A34:
    r_v0 = (long)(0 + (-0xA));
    if (r_s0) { *(int *)((char *)r_s0 + (0x24)) = (int)0; }
    if (r_sp) { *(int *)((char *)r_sp + (0x4)) = (int)r_v0; }
    r_v1 = (long)(0 + (-0x7E));
    if (r_s0) { *(int *)((char *)r_s0 + (0x28)) = (int)0; }
_lbl_L00130A48:
    r_v0 = (long)(0 + (-0x7E));
    if (r_v1 != r_v0) return func_00130A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00130A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130A50 */
void *func_00130A50(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_t0 = *(int *)((char *)r_sp + (0x4)); }
    r_a0 = (long)((unsigned long)r_s1 << (4));
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (0x24)); }
    r_a0 = (long)(r_s2 + r_a0);
    if (r_s0) { r_a2 = *(int *)((char *)r_s0 + (0x28)); }
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0x2C)); }
    r_v0 = (long)func_0012F0A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s1 + (0x1));
    r_v1 = (long)(0 + (-0x1));
    if (r_s0) { *(int *)((char *)r_s0 + (0xD0)) = (int)r_v0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
_lbl_L00130A80:
    r_v0 = (long)(r_v1 + 0);
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00130A98 */
void *func_00130A98(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_a0) { r_s0 = *(int *)((char *)r_a0 + (0xB0)); }
    return func_00130AA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130AA8 */
void *func_00130AA8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    if (r_s0 == 0) { r_v1 = (long)(0 + (-0x1)); goto _lbl_L00130B00; }
    r_v1 = (long)(0 + (-0x1));
    if (r_a0) { r_v0 = *(short *)((char *)r_a0 + (0xB4)); }
    if (r_v0 == r_v1) { if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0xBC)); } goto _lbl_L00130AEC; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0xBC)); }
    if (r_a0) { r_v0 = *(short *)((char *)r_a0 + (0xB6)); }
    if (r_v0 == r_v1) { if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0xBC)); } goto _lbl_L00130AEC; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0xBC)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0xB7)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0xB4)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v1 = (long)(0 + (0x1));
    goto _lbl_L00130AF0;
_lbl_L00130AEC:
    if (r_a0) { r_a0 = *(int *)((char *)r_a0 + (0xC4)); }
_lbl_L00130AF0:
    r_v0 = (long)(0 + (0x1));
    if (r_s0) { *(int *)((char *)r_s0 + (0x8)) = (int)r_a0; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x0)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x4)) = (int)r_v1; }
_lbl_L00130B00:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_v0 = (long)(0 + (-0x80));
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00130B18 */
void *func_00130B18(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s2 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s3 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s1 = (long)(r_a3 + 0);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (-0x6900)); }
    r_s0 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_v0 = (long)(0 + 0);
    if (r_v1 != 0) { if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; } return func_00130BB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012EF18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)&func_001309E0 + 0x50;
    r_t2 = (long)&D_38C990;
    r_a3 = (long)((0xFFFF0000 >> 16) << 16);
    r_a3 = (long)((unsigned long)r_a3 >> (0));
    r_a2 = (long)(r_s0 + 0);
    r_t1 = (long)(r_s1 + 0);
    r_t0 = (long)(r_s3 + 0);
    r_t2 = (long)&D_38C990;
    r_a3 = (long)(r_v0 & r_a3);
    r_a1 = (long)&func_001309E0 + 0x50;
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F9840;
    if (r_s2) { *(int *)((char *)r_s2 + (0xD0)) = (int)0; }
    r_v0 = (long)&D_4F9840;
    r_v1 = (long)&D_4E2D48;
    if (r_s2) { *(int *)((char *)r_s2 + (0xCC)) = (int)r_v0; }
    r_a0 = (long)(r_s2 + (0x38));
    r_t0 = (long)&D_4E2D48;
    if (r_t0) { r_v0 = *(signed char *)((char *)r_t0 + (0x0)); }
    return func_00130BB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130BB0 */
void *func_00130BB0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    if (r_t0) { r_a2 = *(signed char *)((char *)r_t0 + (0x1)); }
    if (r_s2) { *(char *)((char *)r_s2 + (0x38)) = (char)r_v0; }
    if (r_s2) { *(char *)((char *)r_s2 + (0x39)) = (char)r_a2; }
    r_a1 = (long)(r_s3 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_v0 = (long)(0 + (0x1));
_lbl_L00130BC8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    return func_00130BD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130BD8 */
void *func_00130BD8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00130BE8 */
void *func_00130BE8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_38C990;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_38C990;
    r_v0 = (long)func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00130C08 */
void *func_00130C08(void *a0, void *a1, void *a2, void *a3) {
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
    r_t0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_t1 = (long)(r_t0 + 0);
    r_a2 = (long)(r_t0 + (0x24));
    r_a3 = (long)(r_t0 + (0x28));
    if (r_t0) { r_a0 = *(short *)((char *)r_t0 + (0xC)); }
    if (r_t0) { r_a1 = *(short *)((char *)r_t0 + (0xE)); }
    r_t0 = (long)(r_t0 + (0x2C));
    r_v0 = (long)func_0012FAC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00130C40 */
void *func_00130C40(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00130C60 */
void *func_00130C60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x80));
    r_a3 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s3 = (long)(r_a1 + 0);
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_a0 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_ra; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a2 = (long)(r_sp | (0x4));
    r_t0 = (long)(r_s1 + 0);
    r_s5 = (long)(0 + (0x1));
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s2 != r_v0) { r_v0 = (long)(r_s2 + 0); goto _lbl_L00130D18; }
    r_v0 = (long)(r_s2 + 0);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if (r_sp) { r_t0 = *(int *)((char *)r_sp + (0x4)); }
    if (r_s1) { r_a1 = *(int *)((char *)r_s1 + (0x24)); }
    r_a0 = (long)(r_s0 + 0);
    if (r_s1) { r_a2 = *(int *)((char *)r_s1 + (0x28)); }
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0x2C)); }
    r_v0 = (long)func_0012F0A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012F388((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s5) { r_a0 = (long)(r_s1 + 0); goto _lbl_L00130D14; }
    r_a0 = (long)(r_s1 + 0);
    if (r_s1) { *(int *)((char *)r_s1 + (0x20)) = (int)r_v0; }
    r_a1 = (long)(r_s4 + 0);
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
_lbl_L00130D14:
    r_v0 = (long)(r_s2 + 0);
_lbl_L00130D18:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
}

/* func_00130D40 */
void *func_00130D40(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a2 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)&D_00131DA8;
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_00130AA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00130D68 */
void *func_00130D68(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)(0 + (-0x7E));
    return (void *)r_v0;
}

/* func_00130D70 */
void *func_00130D70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130BB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    return (void *)r_v0;
}

/* func_00130D88 */
void *func_00130D88(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (0x10));
    r_v0 = (long)(0 + (-0x7E));
    return (void *)r_v0;
}

/* func_00130D98 */
void *func_00130D98(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_00131DA8;
    r_v0 = (long)func_00130BD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00130DB8 */
void *func_00130DB8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x30));
    r_t1 = (long)&D_4F9840;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_t1 = (long)&D_4F9840;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_a3 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    r_a2 = (long)(r_s0 + (0x38));
    r_t2 = (long)(r_s0 + 0);
    if (r_s0) { r_a0 = *(short *)((char *)r_s0 + (0xC)); }
    r_t0 = (long)(0 + (0x18));
    if (r_s0) { r_a1 = *(short *)((char *)r_s0 + (0xE)); }
    r_v0 = (long)func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00130DF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130DF0 */
void *func_00130DF0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_s1 = (long)(0 + (0x18));
    if (r_s0) { *(int *)((char *)r_s0 + (0x18)) = (int)r_s1; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00130E10 */
void *func_00130E10(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s3 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xD));
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00130E48((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00130E48 */
void *func_00130E48(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    r_t0 = (long)(r_s0 + 0);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L00130F04; }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_s2 = (long)(0 + 0);
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)&D_38CA10; goto _lbl_L00130ED8; }
    r_a0 = (long)&D_38CA10;
    if ((long)r_a1 <= 0) { r_v0 = (long)&D_4F9840; goto _lbl_L00130E94; }
    r_v0 = (long)&D_4F9840;
    r_v0 = (long)&D_4F9840;
    if (r_s0) { *(int *)((char *)r_s0 + (0x30)) = (int)r_v0; }
_lbl_L00130E94:
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x30)); }
    if (r_v0 == 0) { r_v0 = (long)(0 + (0x1)); goto _lbl_L00130ED0; }
    r_v0 = (long)(0 + (0x1));
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0x34)); }
    r_a1 = (long)(0 + (0x2));
    r_v0 = (long)func_0012F7A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_a1 = (long)&D_00131190; goto _lbl_L00130EC8; }
    r_a1 = (long)&D_00131190;
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)&D_00131190;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    goto _lbl_L00130EE8;
_lbl_L00130EC8:
    r_s2 = (long)(0 + (-0x79));
    goto _lbl_L00130EE8;
_lbl_L00130ED0:
    if (r_s0) { *(int *)((char *)r_s0 + (0xB4)) = (int)r_v0; }
    goto _lbl_L00130EE8;
_lbl_L00130ED8:
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CA10;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
_lbl_L00130EE8:
    r_a3 = (long)(r_s1 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s1 + 0);
_lbl_L00130F04:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00130F20 */
void *func_00130F20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&func_00130D68;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&func_00130D68;
    r_v0 = (long)func_00130D88((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00130F40 */
void *func_00130F40(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(0 + (-0x7E));
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)&D_00131DA8;
    r_a0 = (long)(0 + 0);
    if (r_v0 != 0) r_a0 = r_s0;
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)&D_00131DA8;
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00130FA8 */
void *func_00130FA8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a3 = (long)(r_a0 + 0);
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)(r_a1 + 0);
    r_v0 = (long)&D_4E2D48;
    r_a1 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)&D_4E2D48;
    r_v0 = (long)func_00130280((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00130FD8 */
void *func_00130FD8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a3 = (long)&D_4E2D48;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a3 = (long)&D_4E2D48;
    if (r_a0) { r_a1 = *(short *)((char *)r_a0 + (0xC)); }
    if (r_a0) { r_a2 = *(short *)((char *)r_a0 + (0xE)); }
    r_v0 = (long)func_00130DF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00131000 */
void *func_00131000(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x70));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s4 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x12));
    r_t0 = (long)(r_s1 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s0 != r_v0) { r_v0 = (long)(r_s0 + 0); goto _lbl_L001310AC; }
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)&D_38CA40; goto _lbl_L00131080; }
    r_a0 = (long)&D_38CA40;
    if (r_s1) { *(int *)((char *)r_s1 + (0xC4)) = (int)r_a1; }
    goto _lbl_L00131090;
_lbl_L00131080:
    r_a2 = (long)(r_s2 + 0);
    r_a0 = (long)&D_38CA40;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
_lbl_L00131090:
    r_a3 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s3 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s4 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s0 + 0);
_lbl_L001310AC:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_001310D0 */
void *func_001310D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_00131DA8;
    r_v0 = (long)func_00130E48((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_001310F0 */
void *func_001310F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { r_s3 = *(int *)((char *)r_s1 + (0xC4)); }
    r_s0 = (long)(r_v0 + 0);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0x10)); }
    r_t0 = (long)(0 + (0x1));
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(0 + 0);
    r_a3 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012F5F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012F6C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a1 = (long)(r_s2 + 0); goto _lbl_L00131178; }
    r_a1 = (long)(r_s2 + 0);
    r_a0 = (long)&D_4903D0;
    r_s4 = (long)(0 + (-0x7B));
    r_a0 = (long)&D_4903D0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s2 + 0);
_lbl_L00131178:
    r_a2 = (long)(r_s4 + 0);
    r_a3 = (long)(r_s3 + 0);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012F6F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)&D_00131DA8;
    r_a1 = (long)(r_s1 + 0);
    r_a0 = (long)(r_v0 + 0);
    r_a2 = (long)&D_00131DA8;
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_001311C0 */
void *func_001311C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_s0 + (0x38));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_s0) { r_s1 = *(short *)((char *)r_s0 + (0xE)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xC)); }
    if (r_s0) { r_s2 = *(short *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_v0 = (long)(0 + (-0x7E)); goto _lbl_L00131224; }
    r_v0 = (long)(0 + (-0x7E));
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_a3 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012FBA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00131224:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00131240 */
void *func_00131240(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x70));
    r_v0 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s4 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)(r_v1 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(0 + (-0x7E)); goto _lbl_L001312A0; }
    r_s0 = (long)(0 + (-0x7E));
    r_s2 = (long)(0 + (-0x7E));
    goto _lbl_L001312E4;
_lbl_L001312A0:
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xB));
    r_t0 = (long)(r_s1 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s0 != r_v0) { r_v0 = (long)(r_s0 + 0); goto _lbl_L00131324; }
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 >= 0) { r_a0 = (long)&D_38CA70; goto _lbl_L001312E4; }
    r_a0 = (long)&D_38CA70;
    r_a2 = (long)(r_s3 + 0);
    r_a0 = (long)&D_38CA70;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
_lbl_L001312E4:
    if (r_s2 == 0) { r_a3 = (long)(r_s0 + 0); goto _lbl_L00131304; }
    r_a3 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s4 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    goto _lbl_L00131320;
_lbl_L00131304:
    r_v0 = (long)func_0012F7E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)&D_00131720;
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)&D_00131720;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
_lbl_L00131320:
    r_v0 = (long)(r_s0 + 0);
_lbl_L00131324:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_00131348 */
void *func_00131348(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_4F9E40;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)&D_4F9E40;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xC)); }
    if (r_s1) { r_s4 = *(short *)((char *)r_s1 + (0xE)); }
    if (r_s1) { r_s3 = *(short *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_v0 = (long)(0 + (-0x7E)); goto _lbl_L001313E8; }
    r_v0 = (long)(0 + (-0x7E));
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s1 + (0x38));
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_s0 = (long)(0 + (0x18));
    r_a1 = (long)&D_4E2D50;
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)&D_4E2D50;
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_t1 = (long)&D_4F9840;
    if (r_s1) { r_a3 = *(int *)((char *)r_s1 + (0x14)); }
    r_a0 = (long)(r_s3 + 0);
    r_a1 = (long)(r_s4 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_t1 = (long)&D_4F9840;
    r_t0 = (long)(0 + (0x18));
    r_t2 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) { *(int *)((char *)r_s1 + (0x18)) = (int)r_s0; }
_lbl_L001313E8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00131408 */
void *func_00131408(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x70));
    r_v0 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s4 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)(r_v1 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(0 + (-0x7E)); goto _lbl_L00131468; }
    r_s0 = (long)(0 + (-0x7E));
    r_s3 = (long)(0 + (-0x7E));
    goto _lbl_L001314B4;
_lbl_L00131468:
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xD));
    r_t0 = (long)(r_s1 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s0 != r_v0) { r_v0 = (long)(r_s0 + 0); goto _lbl_L001314D0; }
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)&D_38CAA0; goto _lbl_L001314A4; }
    r_a0 = (long)&D_38CAA0;
    if (r_s1) { *(int *)((char *)r_s1 + (0xD0)) = (int)r_a1; }
    goto _lbl_L001314B4;
_lbl_L001314A4:
    r_a2 = (long)(r_s2 + 0);
    r_a0 = (long)&D_38CAA0;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
_lbl_L001314B4:
    r_a3 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s3 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s4 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s0 + 0);
_lbl_L001314D0:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_001314F0 */
void *func_001314F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    if (r_a0) { r_a1 = *(short *)((char *)r_a0 + (0xC)); }
    if (r_a0) { r_a2 = *(short *)((char *)r_a0 + (0xE)); }
    if (r_a0) { r_a3 = *(int *)((char *)r_a0 + (0x10)); }
    r_v0 = (long)func_00130DF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00131518 */
void *func_00131518(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_00131DA8;
    r_v0 = (long)func_00130E48((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00131538 */
void *func_00131538(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_s7;
    (void)r_s8;
    r_sp = (long)(r_sp + (-0xA0));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_s8; }
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s7; }
    r_s8 = (long)(0 + (-0x7E));
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s6; }
    r_s7 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x90)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (0xF)); }
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3) { r_s2 = *(int *)((char *)r_s3 + (0x10)); }
    r_a0 = (long)(r_v0 + 0);
    if (r_s3) { r_s6 = *(int *)((char *)r_s3 + (0xCC)); }
    if (r_s2) { r_s5 = *(int *)((char *)r_s2 + (0x18)); }
    if (r_s3) { r_s4 = *(int *)((char *)r_s3 + (0xD0)); }
    r_v0 = (long)func_0012F428((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_a0 = (long)(r_s2 + 0); goto _lbl_L00131640; }
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_0012ED28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s6 + 0);
    r_a2 = (long)(r_s4 + 0);
    r_v0 = (long)func_0012F188((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) goto _lbl_L00131620;
    r_s7 = (long)(0 + (-0x78));
    goto _lbl_L00131640;
_lbl_L001315D0:
    r_v0 = (long)((long)r_s1 < (long)(0x5) ? 1 : 0);
    if (r_v0 == 0) { r_a0 = (long)(r_s2 + 0); goto _lbl_L00131640; }
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012ED28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s5 + 0);
    r_v0 = (long)func_0012F208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_s1 = (long)(r_s1 + (0x1)); goto _lbl_L001315D0; }
    r_s1 = (long)(r_s1 + (0x1));
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s6 + 0);
    r_a2 = (long)(r_s4 + 0);
    r_v0 = (long)func_0012F188((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_s1 = (long)(r_s1 + (0x1)); goto _lbl_L001315D0; }
    r_s1 = (long)(r_s1 + (0x1));
    r_s7 = (long)(0 + (-0x78));
    goto _lbl_L00131640;
_lbl_L00131620:
    r_a0 = (long)(0 + (0x1));
    r_v0 = (long)func_0012ECA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_a2 = (long)(r_s5 + 0);
    r_v0 = (long)func_0012F208((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_s1 = (long)(0 + (0x2)); goto _lbl_L001315D0; }
    r_s1 = (long)(0 + (0x2));
_lbl_L00131640:
    r_v0 = (long)(0 + (-0x78));
    if (r_s7 != r_v0) { r_a2 = (long)&D_00131DA8; goto _lbl_L00131680; }
    r_a2 = (long)&D_00131DA8;
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (0x34)); }
    r_a1 = (long)(0 + (0x10));
    r_v0 = (long)func_0012F7A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)(0 + (0x1)); goto _lbl_L0013167C; }
    r_v0 = (long)(0 + (0x1));
    r_a1 = (long)&func_00131348 + 0x38;
    if (r_s3) { *(int *)((char *)r_s3 + (0xB4)) = (int)r_v0; }
    r_a0 = (long)(r_s3 + 0);
    r_a1 = (long)&func_00131348 + 0x38;
    r_v0 = (long)func_00130D88((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s8 + 0);
    goto _lbl_L0013169C;
_lbl_L0013167C:
    r_a2 = (long)&D_00131DA8;
_lbl_L00131680:
    r_a0 = (long)(r_s7 + 0);
    r_a1 = (long)(r_s3 + 0);
    r_a2 = (long)&D_00131DA8;
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s8 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s8 + 0);
_lbl_L0013169C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x90)); }
    if (r_sp) { r_s8 = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
}

/* func_001316D0 */
void *func_001316D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_s7;
    (void)r_s8;
    r_sp = (long)(r_sp + (-0xA0));
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_s8; }
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s7; }
    r_s8 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    r_s7 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s3 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x90)) = (long)r_ra; }
    r_s1 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s6; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_a3) { r_a0 = *(short *)((char *)r_a3 + (0x4)); }
    if (r_s1) { r_s6 = *(int *)((char *)r_s1 + (0x18)); }
    r_v0 = (long)func_0012F4B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_s6 <= 0) { r_s5 = (long)(r_v0 + 0); goto _lbl_L00131790; }
    r_s5 = (long)(r_v0 + 0);
    r_s2 = (long)(0 + 0);
_lbl_L00131728:
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012F7B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_a1 = (long)(r_s8 + 0); goto _lbl_L00131780; }
    r_a1 = (long)(r_s8 + 0);
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0x1C)); }
    r_a2 = (long)(r_s7 + 0);
    r_a0 = (long)(r_a0 + r_s2);
    r_v0 = (long)func_0012F188((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(0 + 0); goto _lbl_L00131764; }
    r_s0 = (long)(0 + 0);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0x10)); }
    r_a1 = (long)(r_s5 + 0);
    r_v0 = (long)func_0012F4C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
_lbl_L00131764:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0x1C)); }
    r_a1 = (long)(r_s5 + 0);
    r_v0 = (long)(r_s2 + r_v0);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0x1C)); }
    r_v0 = (long)func_0012F4C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_v0 - r_s0);
    r_s4 = (long)(r_s4 + r_v0);
_lbl_L00131780:
    r_s3 = (long)(r_s3 + (0x1));
    r_v0 = (long)((long)r_s3 < (long)r_s6 ? 1 : 0);
    if (r_v0 != 0) { r_s2 = (long)(r_s2 + (0x20)); goto _lbl_L00131728; }
    r_s2 = (long)(r_s2 + (0x20));
_lbl_L00131790:
    r_v0 = (long)(r_s4 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x90)); }
    if (r_sp) { r_s8 = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
}

/* func_001317C8 */
void *func_001317C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    r_s3 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (0xF)); }
    if (r_s3) { r_a0 = *(int *)((char *)r_s3 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)&D_4F9840; goto _lbl_L00131820; }
    r_v0 = (long)&D_4F9840;
    r_s2 = (long)(0 + (-0x7E));
    goto _lbl_L001318A0;
_lbl_L00131820:
    if (r_s3) { r_v1 = *(int *)((char *)r_s3 + (0x30)); }
    if (r_v1 == 0) { r_a0 = (long)&D_4F9840; goto _lbl_L00131894; }
    r_a0 = (long)&D_4F9840;
    if (r_s3) { r_s0 = *(int *)((char *)r_s3 + (0x10)); }
    r_a1 = (long)(0 + (0x18));
    r_a3 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s0 + 0);
    r_v0 = (long)func_00131518((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_s4 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(0 + 0);
    r_a3 = (long)(0 + 0);
    r_t0 = (long)(0 + (0x1));
    r_v0 = (long)func_0012F5F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_s4 <= 0) { r_s0 = (long)(r_v0 + 0); goto _lbl_L00131878; }
    r_s0 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s1 + 0);
    r_s2 = (long)(0 + (-0x7B));
    r_v0 = (long)func_0012F6A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((long)r_v0 < (long)r_s4 ? 1 : 0);
    if (r_v0 == 0) r_s2 = 0;
_lbl_L00131878:
    r_a2 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s3 + 0);
    r_a3 = (long)(0 + 0);
    r_v0 = (long)func_0012F6F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    goto _lbl_L001318A0;
_lbl_L00131894:
    r_a0 = (long)&D_4903F0;
    r_a0 = (long)&D_4903F0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L001318A0:
    r_a2 = (long)&D_00131DA8;
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s3 + 0);
    r_a2 = (long)&D_00131DA8;
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_001318D8 */
void *func_001318D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_v0 = (long)(0 + (0x1)); goto _lbl_L00131918; }
    r_v0 = (long)(0 + (0x1));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x10)); }
    if (r_v0) { r_v0 = *(int *)((char *)r_v0 + (0x18)); }
_lbl_L00131918:
    if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (0xBC)) = (int)0; }
    r_v0 = (long)(0 + (-0x7E));
    if (r_s0) { *(int *)((char *)r_s0 + (0xB8)) = (int)0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00131938 */
void *func_00131938(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
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
    r_sp = (long)(r_sp + (-0xA0));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s6; }
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    r_s6 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x90)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_s8; }
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s7; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0xB8)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xC)); }
    if (r_s0) { r_s8 = *(short *)((char *)r_s0 + (0xE)); }
    if (r_s0) { r_s7 = *(short *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    if (r_s0) { r_s3 = *(int *)((char *)r_s0 + (0x10)); }
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s5 = (long)(r_v0 + 0);
    if (r_s0) { r_s2 = *(int *)((char *)r_s0 + (0x1C)); }
    r_v0 = (long)&D_00131DA8;
    r_s4 = (long)&D_00131DA8;
    r_v0 = (long)(r_s2 + 0);
    goto _lbl_L001319BC;
_lbl_L001319B0:
    r_s1 = (long)(r_s1 + (0x1));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x1C)); }
    if (r_s0) { *(int *)((char *)r_s0 + (0xB8)) = (int)r_s1; }
_lbl_L001319BC:
    r_v0 = (long)((long)r_s1 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { r_a0 = (long)(r_s3 + 0); goto _lbl_L001319E0; }
    r_a0 = (long)(r_s3 + 0);
    if (r_s0) { *(int *)((char *)r_s0 + (0x20)) = (int)r_s6; }
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s4 + 0);
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x90)); }
    goto _lbl_L00131AA0;
_lbl_L001319E0:
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012F7B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)((long)r_s1 < (long)r_s2 ? 1 : 0); goto _lbl_L001319B0; }
    r_v0 = (long)((long)r_s1 < (long)r_s2 ? 1 : 0);
    if (r_v0 == 0) { r_v1 = (long)&D_4F9E40; goto _lbl_L001319B0; }
    r_v1 = (long)&D_4F9E40;
    r_v0 = (long)&D_4E2D48;
    r_s2 = (long)&D_4F9E40;
    r_s4 = (long)&D_4E2D48;
    r_t0 = (long)&D_4E2D48;
    r_a3 = (long)&D_4F9E40;
    if (r_t0) { r_a1 = *(signed char *)((char *)r_t0 + (0x0)); }
    if (r_t0) { r_a2 = *(signed char *)((char *)r_t0 + (0x1)); }
    if (r_a3) { *(char *)((char *)r_a3 + (0x0)) = (char)r_a1; }
    if (r_a3) { *(char *)((char *)r_a3 + (0x1)) = (char)r_a2; }
    r_a0 = (long)(r_s5 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a1 = (long)(r_s1 + 0); goto _lbl_L00131A48; }
    r_a1 = (long)(r_s1 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s0 + (0x39));
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)(r_s4 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)(r_s1 + 0);
_lbl_L00131A48:
    r_a0 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012ED08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(0 + (0x2));
    r_a1 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0xB4)); }
    if (r_v1 != 0) { r_s1 = (long)(0 + (0x202)); goto _lbl_L00131A84; }
    r_s1 = (long)(0 + (0x202));
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0x34)); }
    r_a1 = (long)(0 + (0x100));
    r_v0 = (long)func_0012F7A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a0 = (long)(r_s7 + 0); goto _lbl_L00131A88; }
    r_a0 = (long)(r_s7 + 0);
    r_s1 = (long)(0 + (0x202));
_lbl_L00131A84:
    r_a0 = (long)(r_s7 + 0);
_lbl_L00131A88:
    r_a1 = (long)(r_s8 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_a3 = (long)(r_s1 + 0);
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012FD58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x90)); }
_lbl_L00131AA0:
    if (r_sp) { r_s8 = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
}

/* func_00131AD0 */
void *func_00131AD0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s2 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x2));
    r_t0 = (long)(r_s1 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s0 != r_v0) { r_v0 = (long)(r_s0 + 0); goto _lbl_L00131B70; }
    r_v0 = (long)(r_s0 + 0);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)(0 + 0); goto _lbl_L00131B44; }
    r_a0 = (long)(0 + 0);
    if (r_s1) { *(int *)((char *)r_s1 + (0x84)) = (int)r_a1; }
    goto _lbl_L00131B58;
_lbl_L00131B44:
    r_a0 = (long)&D_38CAD0;
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CAD0;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
_lbl_L00131B58:
    r_a3 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s0 + 0);
_lbl_L00131B70:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00131B88 */
void *func_00131B88(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_v0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)(0 + 0);
    r_a3 = (long)(r_v0 + 0);
    if (r_v0) { *(int *)((char *)r_v0 + (0x7C)) = (int)0; }
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0x84)); }
    r_a2 = (long)(0 + 0);
    r_v0 = (long)func_00132538((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00131BB8 */
void *func_00131BB8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a1 = (long)(r_a0 + 0);
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a0 = (long)&D_00131DA8;
    r_v0 = (long)func_00132590((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00131BE0 */
void *func_00131BE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_a3 = (long)(r_s0 + 0);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0x10)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xB8)); }
    if (r_v1) { r_a1 = *(int *)((char *)r_v1 + (0x1C)); }
    r_v0 = (long)((unsigned long)r_v0 << (5));
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0x84)); }
    r_v0 = (long)(r_v0 + r_a1);
    if (r_v0) { r_s1 = *(int *)((char *)r_v0 + (0x1C)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0x18)); }
    r_a2 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012FE88((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (0xC4)) = (int)r_s1; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00131C38 */
void *func_00131C38(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x6));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L00131CEC; }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)(0 + 0); goto _lbl_L00131CC0; }
    r_a0 = (long)(0 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC4)); }
    if (r_a1 == r_v0) { r_a3 = (long)(r_s1 + 0); goto _lbl_L00131CD8; }
    r_a3 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xBC)); }
    r_v0 = (long)(r_v0 + (0x1));
    if (r_s0) { *(int *)((char *)r_s0 + (0xBC)) = (int)r_v0; }
    goto _lbl_L00131CD8;
_lbl_L00131CC0:
    r_a0 = (long)&D_38CB00;
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CB00;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_a3 = (long)(r_s1 + 0);
_lbl_L00131CD8:
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s1 + 0);
_lbl_L00131CEC:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00131D08 */
void *func_00131D08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (0x84)); }
    r_v0 = (long)func_0012FE10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00131D28 */
void *func_00131D28(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s3 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x3));
    r_t0 = (long)(r_s1 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s0 != r_v0) { r_v0 = (long)(r_s0 + 0); return func_00131DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(r_s0 + 0);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_s2 = (long)(0 + 0);
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)((0x390000 >> 16) << 16); goto _lbl_L00131DBC; }
    r_a0 = (long)((0x390000 >> 16) << 16);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xBC)); }
    if (r_v0 == 0) { r_a1 = (long)&func_00131D08 + 0x18; return func_00131DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a1 = (long)&func_00131D08 + 0x18;
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)&func_00131D08 + 0x18;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    return func_00131DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00131DBC:
    r_a2 = (long)(r_v0 + 0);
    return func_00131DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00131DC0 */
void *func_00131DC0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_a0 = (long)(r_a0 + (-0x34D0));
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
_lbl_L00131DCC:
    r_a3 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s0 + 0);
_lbl_L00131DE8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00131E08 */
void *func_00131E08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x20));
    if (r_a0) { *(int *)((char *)r_a0 + (0xC8)) = (int)0; }
    r_v0 = (long)(0 + (-0x7E));
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00131E20 */
void *func_00131E20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    r_v0 = (long)&D_00131DA8;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0xC8)); }
    if (r_v1 != 0) { r_s1 = (long)&D_00131DA8; goto _lbl_L00131E4C; }
    r_s1 = (long)&D_00131DA8;
    r_v1 = (long)(0 + (-0x7E));
    return func_00131EA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00131E4C:
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xE));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_v1 != r_v0) { if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); } return func_00131EA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_v0 + 0);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 >= 0) { r_v0 = (long)(0 + 0); return func_00131EA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + 0);
    r_a0 = (long)&D_38CB60;
    r_a0 = (long)&D_38CB60;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00131EA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00131EA8 */
void *func_00131EA8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_a0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s1 + 0);
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
_lbl_L00131EC0:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
_lbl_L00131EC4:
    r_v0 = (long)(r_v1 + 0);
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_00131ED8 */
void *func_00131ED8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    r_a1 = 0x00131780 & 0xFFFF0000;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_a1 = 0x00131780;
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s1 = (long)(0 + 0);
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xBC)); }
    r_s2 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012F7C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x1));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (0x2)); return func_00131F30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(0 + (0x2));
    if (r_v1 == r_v0) { r_s1 = (long)(0 + (-0x7A)); return func_00131F30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_s1 = (long)(0 + (-0x7A));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xB8)); }
    if (r_s0) { *(int *)((char *)r_s0 + (0xBC)) = (int)0; }
    r_v0 = (long)(r_v0 + (0x1));
    return func_00131F30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00131F30 */
void *func_00131F30(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    if (r_s0) { *(int *)((char *)r_s0 + (0xB8)) = (int)r_v0; }
_lbl_L00131F34:
    if (r_s1 == 0) { r_v0 = (long)(r_s2 + 0); goto _lbl_L00131F48; }
    r_v0 = (long)(r_s2 + 0);
    if (r_s0) { *(int *)((char *)r_s0 + (0x20)) = (int)r_s1; }
    r_s2 = (long)(0 + (-0x7E));
    r_v0 = (long)(r_s2 + 0);
_lbl_L00131F48:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_00131F60 */
void *func_00131F60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0x20)); }
    r_v0 = (long)(0 + (-0x80));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0xB0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (0x0)) = (int)r_a1; }
    return (void *)r_v0;
}

/* func_00131F78 */
void *func_00131F78(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0xC8)); }
    return (void *)r_v0;
}

/* func_00131F80 */
void *func_00131F80(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_v0 ? 1 : 0);
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_t0 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x0)); }
    if (r_a0) { r_t1 = *(int *)((char *)r_a0 + (0x18)); }
    r_a1 = (long)(r_a1 & r_v0);
    r_v0 = (long)func_00131E08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00131FC0 */
void *func_00131FC0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x30));
    r_t2 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_v1 = (long)(r_a3 + 0);
    if (r_sp) { *(int *)((char *)r_sp + (0x10)) = (int)r_a1; }
    r_a2 = (long)((unsigned long)r_t0 << (5));
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0x1C)); }
    r_t0 = (long)(r_t2 + 0);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x10)); }
    r_a3 = (long)((0xFFFF0000 >> 16) << 16);
    r_a3 = (long)((unsigned long)r_a3 >> (0));
    r_a2 = (long)(r_a1 + r_a2);
    if (r_sp) { *(int *)((char *)r_sp + (0x8)) = (int)r_v1; }
    r_a3 = (long)(r_v0 & r_a3);
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)0; }
    r_a1 = (long)(0 + 0);
    r_t2 = (long)(0 + 0);
    r_t3 = (long)(0 + 0);
    r_v0 = (long)func_00131F80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00132018 */
void *func_00132018(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x20));
    r_v1 = (long)((unsigned long)r_a3 << (5));
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_t1 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_a1 = (long)((0xFFFF0000 >> 16) << 16);
    r_a1 = (long)((unsigned long)r_a1 >> (0));
    if (r_sp) { r_t0 = *(int *)((char *)r_sp + (0x0)); }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0x1C)); }
    r_a1 = (long)(r_t0 & r_a1);
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) { r_t2 = *(int *)((char *)r_v0 + (0x1C)); }
    if (r_v0) { r_t0 = *(int *)((char *)r_v0 + (0x18)); }
    r_v0 = (long)func_00131EA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00132060 */
void *func_00132060(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s4 = (long)(r_t2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)(r_t1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)(r_t0 + 0);
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_s1 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_a1 = (long)(r_a3 + 0);
    r_v0 = (long)func_0012ED08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x0)); }
    r_a2 = (long)((0xFFFF0000 >> 16) << 16);
    r_a2 = (long)((unsigned long)r_a2 >> (0));
    r_a0 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s1 + 0);
    r_t0 = (long)(r_s2 + 0);
    r_t1 = (long)(r_s3 + 0);
    r_t2 = (long)(r_s4 + 0);
    r_a1 = (long)(r_v0 + 0);
    r_a2 = (long)(r_v1 & r_a2);
    r_v0 = (long)func_00131F30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_001320E8 */
void *func_001320E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x30));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(int *)((char *)r_sp + (0x10)) = (int)r_a2; }
    r_t3 = (long)(r_t1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_a2 = (long)(r_t0 + 0);
    r_t0 = (long)(r_a3 + 0);
    r_t1 = (long)(0 + (0x1));
    if (r_sp) { r_v1 = *(int *)((char *)r_sp + (0x10)); }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_t2; }
    r_t2 = (long)(r_a2 + 0);
    r_a3 = (long)(r_v1 & r_v0);
    if (r_sp) { *(int *)((char *)r_sp + (0x8)) = (int)0; }
    r_a2 = (long)(0 + 0);
    r_v0 = (long)func_00131F80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00132138 */
void *func_00132138(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
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
    r_sp = (long)(r_sp + (-0xA0));
    r_v0 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_s7; }
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s6; }
    r_s7 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s5; }
    r_s6 = (long)(r_t3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    r_s5 = (long)(r_t2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s4 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)(r_t1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s1 = (long)(r_t0 + 0);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (-0x6900)); }
    r_s0 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x90)) = (long)r_ra; }
    r_a0 = (long)(0 + 0);
    if (r_v1 != 0) { if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a3; } goto _lbl_L00132228; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a3; }
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012EF18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)&func_00132060 + 0x40;
    r_t2 = (long)&D_38CB90;
    r_a3 = (long)((0xFFFF0000 >> 16) << 16);
    r_a3 = (long)((unsigned long)r_a3 >> (0));
    if (r_sp) { r_t1 = *(int *)((char *)r_sp + (0xA8)); }
    r_a3 = (long)(r_v0 & r_a3);
    r_a1 = (long)&func_00132060 + 0x40;
    r_a2 = (long)(r_s1 + 0);
    r_t2 = (long)&D_38CB90;
    r_a0 = (long)(r_s0 + 0);
    r_t0 = (long)(0 + 0);
    r_v0 = (long)func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3 != 0) { r_v0 = (long)&D_4E2D48; goto _lbl_L001321EC; }
    r_v0 = (long)&D_4E2D48;
    r_a1 = (long)(r_s4 + 0);
    r_a0 = (long)(r_s0 + (0x58));
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_s2 = (long)(0 + (0x1));
    r_v0 = (long)&D_4E2D48;
_lbl_L001321EC:
    r_a1 = (long)(r_s7 + 0);
    r_t0 = (long)&D_4E2D48;
    if (r_t0) { r_v1 = *(signed char *)((char *)r_t0 + (0x0)); }
    if (r_t0) { r_a2 = *(signed char *)((char *)r_t0 + (0x1)); }
    if (r_s0) { *(char *)((char *)r_s0 + (0x38)) = (char)r_v1; }
    if (r_s0) { *(char *)((char *)r_s0 + (0x39)) = (char)r_a2; }
    r_a0 = (long)(r_s0 + (0x38));
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    if (r_s0) { *(int *)((char *)r_s0 + (0xC8)) = (int)r_s3; }
    r_a0 = (long)(0 + (0x1));
    if (r_s0) { *(int *)((char *)r_s0 + (0x78)) = (int)r_s5; }
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0xA0)); }
    if (r_s0) { *(int *)((char *)r_s0 + (0x7C)) = (int)r_s6; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x80)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (0xB8)) = (int)r_s2; }
_lbl_L00132228:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x90)); }
    r_v0 = (long)(r_a0 + 0);
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
}

/* func_00132258 */
void *func_00132258(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_38CB90;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_38CB90;
    r_v0 = (long)func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132278 */
void *func_00132278(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132298 */
void *func_00132298(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a2 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)&D_001328E0;
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_00130AA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_001322C0 */
void *func_001322C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130BB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_001322E0 */
void *func_001322E0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_001328E0;
    r_v0 = (long)func_00130BD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132300 */
void *func_00132300(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_s1 = (long)(r_s0 + (0x38));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_a0 = (long)(r_s1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_s0) { r_s2 = *(short *)((char *)r_s0 + (0xC)); }
    if (r_s0) { r_s3 = *(short *)((char *)r_s0 + (0xE)); }
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0x14)); } goto _lbl_L00132348; }
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0x14)); }
    r_a0 = (long)&D_490420;
    r_a0 = (long)&D_490420;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0x14)); }
_lbl_L00132348:
    r_t1 = (long)&D_4F9840;
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s3 + 0);
    r_a2 = (long)(r_s1 + 0);
    r_t2 = (long)(r_s0 + 0);
    r_t1 = (long)&D_4F9840;
    r_t0 = (long)(0 + (0x1));
    r_v0 = (long)func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x1));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_s0) { *(int *)((char *)r_s0 + (0x18)) = (int)r_v1; }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00132390 */
void *func_00132390(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a0 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xD));
    r_t0 = (long)(r_s1 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s0 != r_v0) { r_s2 = (long)(0 + (0x1)); goto _lbl_L00132454; }
    r_s2 = (long)(0 + (0x1));
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)(0 + 0); goto _lbl_L0013242C; }
    r_a0 = (long)(0 + 0);
    if (r_a1 != r_s2) { r_a0 = (long)(0 + (-0x77)); goto _lbl_L00132440; }
    r_a0 = (long)(0 + (-0x77));
    r_v1 = (long)((0x500000 >> 16) << 16);
    if (r_v1) { r_v0 = *(unsigned short *)((char *)r_v1 + (-0x67AC)); }
    r_v0 = (long)(r_v0 & (0x20));
    if (r_v0 != 0) { r_a3 = (long)(r_s0 + 0); goto _lbl_L00132444; }
    r_a3 = (long)(r_s0 + 0);
    r_v0 = (long)((0x4E2D58 >> 16) << 16);
    /* unhandled: lbu */
    if (r_s1) { *(char *)((char *)r_s1 + (0x38)) = (char)r_v1; }
    goto _lbl_L00132444;
_lbl_L0013242C:
    r_a0 = (long)&D_38CBD8;
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CBD8;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
_lbl_L00132440:
    r_a3 = (long)(r_s0 + 0);
_lbl_L00132444:
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
_lbl_L00132454:
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00132478 */
void *func_00132478(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s2 = (long)(0 + (-0x7E));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x1C)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0xB8)); }
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)r_v1 ? 1 : 0);
    if (r_v0 != 0) { if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0xC8)); } goto _lbl_L001324BC; }
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0xC8)); }
    r_a1 = (long)&D_001328E0;
    r_a1 = (long)&D_001328E0;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    goto _lbl_L001324E0;
_lbl_L001324BC:
    if (r_s1 == 0) { r_a0 = (long)(r_s0 + (0x58)); goto _lbl_L001324E0; }
    r_a0 = (long)(r_s0 + (0x58));
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0x1C)); }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0x18)); }
    if (r_s0) { *(int *)((char *)r_s0 + (0x80)) = (int)r_v1; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x78)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x7C)) = (int)0; }
_lbl_L001324E0:
    r_v0 = (long)(r_s2 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_00132500 */
void *func_00132500(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { *(int *)((char *)r_a0 + (0xBC)) = (int)0; }
    r_v0 = (long)(0 + (-0x7E));
    return (void *)r_v0;
}

/* func_00132510 */
void *func_00132510(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_4F9E40;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)&D_4F9E40;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_a0 = (long)(r_s2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    return func_00132538((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00132538 */
void *func_00132538(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_a1 = (long)(r_s1 + (0x38));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s0 = (long)(r_s1 + (0x58));
    if (r_s1) { r_s3 = *(short *)((char *)r_s1 + (0xC)); }
    if (r_s1) { r_s4 = *(short *)((char *)r_s1 + (0xE)); }
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)&D_4E2D48;
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)&D_4E2D48;
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a0 = (long)(r_s3 + 0); goto _lbl_L0013258C; }
    r_a0 = (long)(r_s3 + 0);
    r_a0 = (long)&D_490440;
    r_a0 = (long)&D_490440;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s3 + 0);
_lbl_L0013258C:
    r_a1 = (long)(r_s4 + 0);
    return func_00132590((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00132590 */
void *func_00132590(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_a2 = (long)(r_s2 + 0);
    r_t0 = (long)(r_s1 + 0);
    r_a3 = (long)(0 + (0x1));
    r_v0 = (long)func_0012FD58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_001325C0 */
void *func_001325C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s3 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x2));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L001326A0; }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_s2 = (long)(0 + 0);
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)&D_38CC08; goto _lbl_L0013263C; }
    r_a0 = (long)&D_38CC08;
    if (r_s0) { *(int *)((char *)r_s0 + (0x84)) = (int)r_a1; }
    goto _lbl_L0013264C;
_lbl_L0013263C:
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CC08;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
_lbl_L0013264C:
    r_v0 = (long)(0 + (-0x77));
    if (r_s2 != r_v0) { r_a3 = (long)(r_s1 + 0); goto _lbl_L00132688; }
    r_a3 = (long)(r_s1 + 0);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0x34)); }
    r_a1 = (long)(0 + (0x40));
    r_v0 = (long)func_0012F7A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_a3 = (long)(r_s1 + 0); goto _lbl_L00132688; }
    r_a3 = (long)(r_s1 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_00131DC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_v0 = (long)&D_00132840; goto _lbl_L00132684; }
    r_v0 = (long)&D_00132840;
    r_s2 = (long)(0 + (0x1));
    r_s3 = (long)&D_00132840;
_lbl_L00132684:
    r_a3 = (long)(r_s1 + 0);
_lbl_L00132688:
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s1 + 0);
_lbl_L001326A0:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_001326C0 */
void *func_001326C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_v0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)(0 + 0);
    r_a3 = (long)(r_v0 + 0);
    if (r_v0) { r_a0 = *(int *)((char *)r_v0 + (0x84)); }
    if (r_v0) { r_a1 = *(int *)((char *)r_v0 + (0x7C)); }
    r_v0 = (long)func_00132538((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_001326F0 */
void *func_001326F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_a1 == 0) { if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; } goto _lbl_L0013270C; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_0012FFC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    goto _lbl_L00132714;
_lbl_L0013270C:
    r_v0 = (long)(0 + (-0x7E));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
_lbl_L00132714:
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132720 */
void *func_00132720(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a1 = (long)(r_a0 + 0);
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a0 = (long)&D_001328E0;
    r_v0 = (long)func_00132590((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132748 */
void *func_00132748(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s0 = (long)(r_a1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x7C)); }
    if (r_v0 != 0) { r_s1 = (long)(r_a0 + 0); goto _lbl_L00132770; }
    r_s1 = (long)(r_a0 + 0);
    r_v1 = (long)(0 + (-0x7E));
    goto _lbl_L001327E4;
_lbl_L00132770:
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x4));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_v1 != r_v0) { if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); } goto _lbl_L001327E8; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_v0 + 0);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 >= 0) { r_v0 = (long)(0 + 0); goto _lbl_L001327CC; }
    r_v0 = (long)(0 + 0);
    r_a0 = (long)&D_38CC38;
    r_a0 = (long)&D_38CC38;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L001327CC:
    r_a0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s1 + 0);
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
_lbl_L001327E4:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
_lbl_L001327E8:
    r_v0 = (long)(r_v1 + 0);
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_00132800 */
void *func_00132800(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_a3 = (long)(r_s0 + 0);
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0x80)); }
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0x84)); }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (0x78)); }
    r_a2 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012FF28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (0xC4)) = (int)r_s1; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00132848 */
void *func_00132848(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s3 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x5));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L00132914; }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_s2 = (long)(0 + 0);
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a2 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a2 < 0) { r_a1 = (long)(r_a2 + 0); goto _lbl_L001328E4; }
    r_a1 = (long)(r_a2 + 0);
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (0xC4)); }
    if (r_a2 == r_a1) { r_a0 = (long)&D_490458; goto _lbl_L001328F8; }
    r_a0 = (long)&D_490458;
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xBC)); }
    r_a0 = (long)&D_490458;
    r_v0 = (long)(r_v0 + (0x1));
    if (r_s0) { *(int *)((char *)r_s0 + (0xBC)) = (int)r_v0; }
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a3 = (long)(r_s1 + 0);
    goto _lbl_L001328FC;
_lbl_L001328E4:
    r_a0 = (long)&D_38CC68;
    r_a0 = (long)&D_38CC68;
    r_a2 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
_lbl_L001328F8:
    r_a3 = (long)(r_s1 + 0);
_lbl_L001328FC:
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s1 + 0);
_lbl_L00132914:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00132930 */
void *func_00132930(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    if (r_a1) { r_a0 = *(int *)((char *)r_a1 + (0x84)); }
    r_v0 = (long)func_0012FE10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132950 */
void *func_00132950(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    r_v0 = (long)&D_001328E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s1 = (long)&D_001328E0;
    r_a0 = (long)(0 + (0x1));
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0x3));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_v1 != r_v0) { if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); } goto _lbl_L001329E4; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_v0 + 0);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 >= 0) { r_v0 = (long)(0 + 0); goto _lbl_L001329C8; }
    r_v0 = (long)(0 + 0);
    r_a0 = (long)&D_38CC98;
    r_a0 = (long)&D_38CC98;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L001329C8:
    r_a0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s1 + 0);
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
_lbl_L001329E4:
    r_v0 = (long)(r_v1 + 0);
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_001329F8 */
void *func_001329F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0xBC)); }
    r_v0 = (long)func_0012F7C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x1));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (0x2)); goto _lbl_L00132A5C; }
    r_v0 = (long)(0 + (0x2));
    if (r_v1 == r_v0) { r_v0 = (long)(0 + (-0x78)); goto _lbl_L00132A74; }
    r_v0 = (long)(0 + (-0x78));
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x1C)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0xC8)); }
    r_v0 = (long)(r_v0 + (0x1));
    if (r_v1 == 0) { if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0; } goto _lbl_L00132A44; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0; }
    r_v0 = (long)(r_v1 + (0x20));
    if (r_s0) { *(int *)((char *)r_s0 + (0xC8)) = (int)r_v0; }
_lbl_L00132A44:
    r_a1 = (long)&func_001322C0;
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)&func_001322C0;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    goto _lbl_L00132A8C;
_lbl_L00132A5C:
    r_a1 = (long)&D_00132358;
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)&D_00132358;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    goto _lbl_L00132A8C;
_lbl_L00132A74:
    r_a1 = (long)&D_001328E0;
    if (r_s0) { *(int *)((char *)r_s0 + (0x20)) = (int)r_v0; }
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)&D_001328E0;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
_lbl_L00132A8C:
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00132A98 */
void *func_00132A98(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0x20)); }
    r_a2 = (long)(0 + (0x1));
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0xB0)); }
    r_v0 = (long)(0 + (-0x80));
    if (r_v1 == 0) r_v1 = r_a2;
    if (r_a1) { *(int *)((char *)r_a1 + (0x0)) = (int)r_v1; }
    return (void *)r_v0;
}

/* func_00132AB8 */
void *func_00132AB8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    return func_00132AD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00132AD8 */
void *func_00132AD8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_s1 = (long)(r_a3 + 0);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (-0x6900)); }
    r_s0 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_v0 = (long)(0 + 0);
    if (r_v1 != 0) { if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; } goto _lbl_L00132B34; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012EF18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)&func_00132950 + 0x48;
    r_t2 = (long)&D_38CCC8;
    r_a3 = (long)((0xFFFF0000 >> 16) << 16);
    r_a3 = (long)((unsigned long)r_a3 >> (0));
    r_a3 = (long)(r_v0 & r_a3);
    r_a0 = (long)(r_s3 + 0);
    r_a1 = (long)&func_00132950 + 0x48;
    r_a2 = (long)(r_s0 + 0);
    r_t0 = (long)(r_s2 + 0);
    r_t1 = (long)(r_s1 + 0);
    r_t2 = (long)&D_38CCC8;
    r_v0 = (long)func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x1));
_lbl_L00132B34:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00132B50 */
void *func_00132B50(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_38CCC8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_38CCC8;
    r_v0 = (long)func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132B70 */
void *func_00132B70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132B90 */
void *func_00132B90(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a2 = (long)&func_00132AB8 + 0x8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)&func_00132AB8 + 0x8;
    r_a1 = (long)(0 + (0x1));
    r_v0 = (long)func_00130AA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132BB8 */
void *func_00132BB8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_v0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)(r_v0 + 0);
    if (r_v0) { r_a0 = *(short *)((char *)r_v0 + (0xC)); }
    if (r_v0) { r_a1 = *(short *)((char *)r_v0 + (0xE)); }
    r_v0 = (long)func_00130108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132BE0 */
void *func_00132BE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    r_a3 = (long)(0 + (0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    r_a2 = (long)(r_sp | (0x4));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L00132C64; }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if (r_a1 != 0) { r_a2 = (long)(r_v0 + 0); goto _lbl_L00132C4C; }
    r_a2 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x1));
    if (r_a2) { *(short *)((char *)r_a2 + (0x6)) = (short)r_v0; }
    goto _lbl_L00132C58;
_lbl_L00132C4C:
    r_a0 = (long)&D_38CCE0;
    r_a0 = (long)&D_38CCE0;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00132C58:
    if (r_v0 != 0) { if (r_s0) { *(int *)((char *)r_s0 + (0x20)) = (int)r_v0; } goto _lbl_L00132C60; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x20)) = (int)r_v0; }
_lbl_L00132C60:
    r_v0 = (long)(r_s1 + 0);
_lbl_L00132C64:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_00132C78 */
void *func_00132C78(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0x20)); }
    r_v0 = (long)(0 + (-0x80));
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0xB0)); }
    if (r_v1) { *(int *)((char *)r_v1 + (0x0)) = (int)r_a1; }
    return (void *)r_v0;
}

/* func_00132C90 */
void *func_00132C90(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
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
    r_sp = (long)(r_sp + (-0xA0));
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_s7; }
    r_s5 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s6; }
    r_s7 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    r_s6 = (long)(r_t1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s4 = (long)(r_a3 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s1 = (long)(r_t0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x90)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_s1 != 0) { if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; } goto _lbl_L00132D00; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_a0 = (long)&D_4E2D60;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490490;
    r_a0 = (long)&D_4E2D60;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490490;
    r_a2 = (long)(0 + (0x1804));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00132D00:
    r_v0 = (long)(r_s1 & (0x3F));
    if (r_v0 == 0) { r_a0 = (long)&D_4904A0; goto _lbl_L00132D28; }
    r_a0 = (long)&D_4904A0;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490490;
    r_a0 = (long)&D_4904A0;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_490490;
    r_a2 = (long)(0 + (0x1805));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00132D28:
    if (r_s0 != 0) { if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (-0x6900)); } goto _lbl_L00132D3C; }
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (-0x6900)); }
    r_v0 = (long)&D_4E2D50;
    r_s0 = (long)&D_4E2D50;
    if (r_s5) { r_v0 = *(int *)((char *)r_s5 + (-0x6900)); }
_lbl_L00132D3C:
    if (r_v0 != 0) { r_v0 = (long)(r_s7 + 0); return func_00132D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(r_s7 + 0);
    r_a0 = (long)(r_s3 + 0);
    r_s7 = (long)(0 + (0x1));
    r_v0 = (long)func_0012EF18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00132D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00132D50 */
void *func_00132D50(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
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
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)&D_00132C70;
    r_t2 = (long)&D_38CD10;
    r_a3 = (long)((0xFFFF0000 >> 16) << 16);
    r_a3 = (long)((unsigned long)r_a3 >> (0));
    r_t0 = (long)(r_s0 + 0);
    r_t1 = (long)(r_s4 + 0);
    r_t2 = (long)&D_38CD10;
    r_a3 = (long)(r_v0 & r_a3);
    r_a1 = (long)&D_00132C70;
    r_a2 = (long)(r_s3 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2) { *(int *)((char *)r_s2 + (0xC0)) = (int)r_s1; }
    r_a0 = (long)(r_s4 + 0);
    if (r_s2) { *(int *)((char *)r_s2 + (0xC4)) = (int)r_s6; }
    r_a1 = (long)(0 + (0x200));
    r_v0 = (long)func_0012F7A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x1));
    if (r_s2) { *(int *)((char *)r_s2 + (0x14)) = (int)r_v0; }
    if (r_s2) { *(int *)((char *)r_s2 + (0xC8)) = (int)r_v1; }
    r_v0 = (long)(r_s7 + 0);
_lbl_L00132DA8:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x90)); }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
}

/* func_00132DD8 */
void *func_00132DD8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_t0 = (long)&D_4F9840;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_t0 = (long)&D_4F9840;
    r_a3 = (long)(0 + 0);
    r_t1 = (long)(0 + (0x18));
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)(r_a1 & r_v0);
    r_v0 = (long)func_00132AD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    if (r_v1 == 0) { r_v0 = (long)((0x500000 >> 16) << 16); goto _lbl_L00132E18; }
    r_v0 = (long)((0x500000 >> 16) << 16);
    if (r_v0) { *(int *)((char *)r_v0 + (-0x6838)) = (int)0; }
_lbl_L00132E18:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_v0 = (long)(r_v1 + 0);
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00132E28 */
void *func_00132E28(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_38CD10;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_38CD10;
    r_v0 = (long)func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132E48 */
void *func_00132E48(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132E68 */
void *func_00132E68(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a2 = (long)&D_00133000;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)&D_00133000;
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_00130AA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132E90 */
void *func_00132E90(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130BB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132EB0 */
void *func_00132EB0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_00133000;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_00133000;
    r_v0 = (long)func_00130BD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132ED0 */
void *func_00132ED0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0xC8)); }
    if (r_v0 == 0) { r_a1 = (long)&func_00132F08; goto _lbl_L00132EF4; }
    r_a1 = (long)&func_00132F08;
    r_a1 = (long)&func_00132F08;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    goto _lbl_L00132EFC;
_lbl_L00132EF4:
    r_v0 = (long)(0 + (-0x7E));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
_lbl_L00132EFC:
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00132F08 */
void *func_00132F08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_t2 = (long)(r_s0 + 0);
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0xC4)); }
    if (r_s0) { r_a0 = *(short *)((char *)r_s0 + (0xC)); }
    if (r_s0) { r_a1 = *(short *)((char *)r_s0 + (0xE)); }
    r_t0 = (long)(r_s1 + 0);
    if (r_s0) { r_a2 = *(int *)((char *)r_s0 + (0x10)); }
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0x14)); }
    if (r_s0) { r_t1 = *(int *)((char *)r_s0 + (0xC0)); }
    r_v0 = (long)func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (0x18)) = (int)r_s1; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00132F58 */
void *func_00132F58(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)&D_00133000;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)&D_00133000;
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xD));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L00133020; }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)(0 + 0); goto _lbl_L00132FF4; }
    r_a0 = (long)(0 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x1C)); }
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0x18)); }
    r_v0 = (long)(r_v0 + r_a1);
    r_v1 = (long)((long)r_a1 < (long)r_v1 ? 1 : 0);
    if (r_v1 == 0) { if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0; } goto _lbl_L00132FE4; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0; }
    if (r_s0) { *(int *)((char *)r_s0 + (0x14)) = (int)0; }
    goto _lbl_L00133008;
_lbl_L00132FE4:
    r_v0 = (long)(0 + (0x1));
    r_s1 = (long)(0 + (-0x1));
    if (r_s0) { *(int *)((char *)r_s0 + (0x14)) = (int)r_v0; }
    goto _lbl_L00133008;
_lbl_L00132FF4:
    r_a0 = (long)&D_38CD40;
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CD40;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
_lbl_L00133008:
    r_a3 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s1 + 0);
_lbl_L00133020:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00133038 */
void *func_00133038(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_s1) { r_s0 = *(int *)((char *)r_s1 + (0x1C)); }
    if (r_s0 != 0) { r_s2 = (long)(0 + 0); goto _lbl_L00133064; }
    r_s2 = (long)(0 + 0);
    r_s2 = (long)(0 + (0x1));
    goto _lbl_L0013308C;
_lbl_L00133064:
    r_a0 = (long)(0 + (0x40));
    r_a1 = (long)((unsigned long)r_s0 << (6));
    r_v0 = (long)func_116D40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { if (r_s1) { *(int *)((char *)r_s1 + (0xC4)) = (int)r_s0; } goto _lbl_L00133080; }
    if (r_s1) { *(int *)((char *)r_s1 + (0xC4)) = (int)r_s0; }
    r_s2 = (long)(0 + (-0x7A));
    goto _lbl_L0013308C;
_lbl_L00133080:
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xB0)); }
    if (r_s1) { *(int *)((char *)r_s1 + (0xC0)) = (int)r_v0; }
    r_v0 = (long)func_0012F970((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0013308C:
    r_a2 = (long)&D_00133000;
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)&D_00133000;
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_001330C0 */
void *func_001330C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00132D50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_001330E0 */
void *func_001330E0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)&D_00133000;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)&D_00133000;
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xD));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L001331A0; }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)(0 + 0); goto _lbl_L00133174; }
    r_a0 = (long)(0 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC8)); }
    if (r_v0 == 0) { if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x1C)); } goto _lbl_L00133160; }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0x1C)); }
    if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_a1; }
    goto _lbl_L0013316C;
_lbl_L00133160:
    r_a0 = (long)(0 + (-0x7A));
    r_v0 = (long)(r_a1 ^ r_v0);
    if (r_v0 == 0) r_a0 = 0;
_lbl_L0013316C:
    if (r_s0) { *(int *)((char *)r_s0 + (0x14)) = (int)0; }
    goto _lbl_L00133188;
_lbl_L00133174:
    r_a0 = (long)&D_38CD70;
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CD70;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
_lbl_L00133188:
    r_a3 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s1 + 0);
_lbl_L001331A0:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_001331B8 */
void *func_001331B8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0x20)); }
    r_a1 = (long)(0 + (0x1));
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (0xB0)); }
    r_v0 = (long)(0 + (-0x80));
    if (r_v1 == 0) r_v1 = r_a1;
    if (r_a2) { *(int *)((char *)r_a2 + (0x0)) = (int)r_v1; }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0x1C)); }
    if (r_a2) { *(int *)((char *)r_a2 + (0x4)) = (int)r_a1; }
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0xC0)); }
    if (r_a2) { *(int *)((char *)r_a2 + (0x8)) = (int)r_v1; }
    return (void *)r_v0;
}

/* func_001331E8 */
void *func_001331E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s1 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s2 = (long)(r_a3 + 0);
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (-0x6900)); }
    r_s0 = (long)(r_a2 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_ra; }
    r_v0 = (long)(0 + 0);
    if (r_v1 != 0) { if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; } goto _lbl_L00133278; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012EF18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)&func_001330E0;
    r_t2 = (long)&D_38CDA0;
    r_a3 = (long)((0xFFFF0000 >> 16) << 16);
    r_a3 = (long)((unsigned long)r_a3 >> (0));
    r_a3 = (long)(r_v0 & r_a3);
    r_a1 = (long)&func_001330E0;
    r_a2 = (long)(r_s0 + 0);
    r_t0 = (long)(r_s3 + 0);
    r_t1 = (long)(r_s2 + 0);
    r_t2 = (long)&D_38CDA0;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4F9840;
    r_v1 = (long)(0 + (0x18));
    r_v0 = (long)&D_4F9840;
    if (r_s1) { *(int *)((char *)r_s1 + (0xC0)) = (int)r_v1; }
    if (r_s1) { *(int *)((char *)r_s1 + (0xBC)) = (int)r_v0; }
    r_v0 = (long)(0 + (0x1));
_lbl_L00133278:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
}

/* func_00133298 */
void *func_00133298(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_38CDA0;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_38CDA0;
    r_v0 = (long)func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_001332B8 */
void *func_001332B8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_001332D8 */
void *func_001332D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a2 = (long)&D_00133700;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)&D_00133700;
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_00130AA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133300 */
void *func_00133300(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130BB0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133320 */
void *func_00133320(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_00133700;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_00133700;
    r_v0 = (long)func_00130BD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133340 */
void *func_00133340(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_t2 = (long)(r_s0 + 0);
    if (r_s0) { r_s1 = *(int *)((char *)r_s0 + (0xC0)); }
    if (r_s0) { r_a0 = *(short *)((char *)r_s0 + (0xC)); }
    if (r_s0) { r_a1 = *(short *)((char *)r_s0 + (0xE)); }
    r_t0 = (long)(r_s1 + 0);
    if (r_s0) { r_a2 = *(int *)((char *)r_s0 + (0x10)); }
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0x14)); }
    if (r_s0) { r_t1 = *(int *)((char *)r_s0 + (0xBC)); }
    r_v0 = (long)func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (0x18)) = (int)r_s1; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00133390 */
void *func_00133390(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x70));
    r_v0 = (long)&D_00133700;
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s4 = (long)&D_00133700;
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_a2 = (long)(r_sp | (0x4));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a3 = (long)(0 + (0xD));
    r_t0 = (long)(r_s1 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s2 != r_v0) { r_v0 = (long)(r_s2 + 0); goto _lbl_L00133490; }
    r_v0 = (long)(r_s2 + 0);
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_s3 = (long)(0 + 0);
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)&D_38CDE0; goto _lbl_L00133464; }
    r_a0 = (long)&D_38CDE0;
    if (r_a1 != 0) { if (r_s1) { r_s0 = *(int *)((char *)r_s1 + (0xBC)); } goto _lbl_L00133418; }
    if (r_s1) { r_s0 = *(int *)((char *)r_s1 + (0xBC)); }
    r_s3 = (long)(0 + (-0x77));
    goto _lbl_L00133474;
_lbl_L00133418:
    r_v0 = (long)&D_4E2D48;
    r_a3 = (long)&D_4E2D48;
    if (r_a3) { r_v1 = *(signed char *)((char *)r_a3 + (0x0)); }
    if (r_a3) { r_a1 = *(signed char *)((char *)r_a3 + (0x1)); }
    if (r_s1) { *(char *)((char *)r_s1 + (0x38)) = (char)r_v1; }
    if (r_s1) { *(char *)((char *)r_s1 + (0x39)) = (char)r_a1; }
    r_a0 = (long)(r_s1 + (0x38));
    r_a1 = (long)(r_s0 + (0x20));
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    if (r_s0) { r_v1 = *(unsigned short *)((char *)r_s0 + (0x14)); }
    r_v1 = (long)(r_v1 & (0x20));
    if (r_v1 != 0) { r_a3 = (long)(r_s2 + 0); goto _lbl_L00133478; }
    r_a3 = (long)(r_s2 + 0);
    r_a1 = (long)&D_00133698;
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)&D_00133698;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    goto _lbl_L00133474;
_lbl_L00133464:
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CDE0;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
_lbl_L00133474:
    r_a3 = (long)(r_s2 + 0);
_lbl_L00133478:
    r_a0 = (long)(r_s3 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_a2 = (long)(r_s4 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s2 + 0);
_lbl_L00133490:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
}

/* func_001334B0 */
void *func_001334B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
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
    r_sp = (long)(r_sp + (-0x90));
    r_v0 = (long)&D_4F9E40;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s2 = (long)&D_4F9E40;
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_ra; }
    r_s1 = (long)(r_s0 + (0x38));
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s7; }
    r_a0 = (long)(r_s1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s6; }
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    if (r_s0) { r_s3 = *(int *)((char *)r_s0 + (0xC0)); }
    if (r_s0) { r_s6 = *(short *)((char *)r_s0 + (0xE)); }
    if (r_s0) { r_s5 = *(short *)((char *)r_s0 + (0xC)); }
    if (r_s0) { r_s7 = *(int *)((char *)r_s0 + (0xBC)); }
    if (r_s0) { r_s4 = *(int *)((char *)r_s0 + (0x14)); }
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a1 = (long)(r_s1 + 0); goto _lbl_L00133514; }
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)(0 + (-0x7E));
    goto _lbl_L00133550;
_lbl_L00133514:
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)&D_4E2D50;
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)&D_4E2D50;
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s5 + 0);
    r_a1 = (long)(r_s6 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_a3 = (long)(r_s4 + 0);
    r_t1 = (long)(r_s7 + 0);
    r_t0 = (long)(r_s3 + 0);
    r_t2 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012FC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { *(int *)((char *)r_s0 + (0x18)) = (int)r_s3; }
_lbl_L00133550:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    return func_00133568((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00133568 */
void *func_00133568(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
}

/* func_00133580 */
void *func_00133580(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)((0x130000 >> 16) << 16);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_ra; }
    return func_00133598((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00133598 */
void *func_00133598(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    r_s2 = (long)(r_v0 + (0x3700));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_a0 = (long)(r_s0 + (0x38));
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a0 = (long)(0 + (0x1)); goto _lbl_L001335C0; }
    r_a0 = (long)(0 + (0x1));
    r_v0 = (long)(0 + (0x1));
    r_s1 = (long)(0 + (-0x7E));
    if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0; }
    goto _lbl_L00133638;
_lbl_L001335C0:
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xD));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); goto _lbl_L0013363C; }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 < 0) { r_a0 = (long)(0 + 0); goto _lbl_L00133610; }
    r_a0 = (long)(0 + 0);
    if (r_s0) { *(int *)((char *)r_s0 + (0x1C)) = (int)r_a1; }
    goto _lbl_L00133624;
_lbl_L00133610:
    r_a0 = (long)&D_38CE10;
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38CE10;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
_lbl_L00133624:
    r_a3 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
_lbl_L00133638:
    r_v0 = (long)(r_s1 + 0);
_lbl_L0013363C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
}

/* func_00133658 */
void *func_00133658(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { *(int *)((char *)r_a0 + (0xB8)) = (int)0; }
    r_v0 = (long)(0 + (-0x7E));
    return (void *)r_v0;
}

/* func_00133668 */
void *func_00133668(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_s1) { r_s0 = *(int *)((char *)r_s1 + (0xB8)); }
_lbl_L00133684:
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0x1C)); }
    r_v0 = (long)((long)r_s0 < (long)r_v0 ? 1 : 0);
    if (r_v0 != 0) { if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xBC)); } goto _lbl_L001336AC; }
    if (r_s1) { r_v0 = *(int *)((char *)r_s1 + (0xBC)); }
    r_a1 = (long)&D_00133698;
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)&D_00133698;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    goto _lbl_L0013370C;
_lbl_L001336AC:
    r_v1 = (long)((unsigned long)r_s0 << (6));
    r_v0 = (long)(r_v0 + r_v1);
    r_s2 = (long)(r_v0 + (0x20));
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012F768((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (0x1)); goto _lbl_L001336D0; }
    r_s0 = (long)(r_s0 + (0x1));
    if (r_s1) { *(int *)((char *)r_s1 + (0xB8)) = (int)r_s0; }
    goto _lbl_L00133684;
_lbl_L001336D0:
    r_s0 = (long)&D_4F9E40;
    r_a1 = (long)(r_s1 + (0x38));
    r_s0 = (long)&D_4F9E40;
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)&D_4E2D48;
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)&D_4E2D48;
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)(r_s2 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    if (r_s1) { *(int *)((char *)r_s1 + (0xC4)) = (int)r_s0; }
    r_v0 = (long)(0 + (-0x7E));
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
_lbl_L0013370C:
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_00133720 */
void *func_00133720(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_v0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a3 = (long)(r_v0 + 0);
    if (r_v0) { r_a0 = *(short *)((char *)r_v0 + (0xC)); }
    if (r_v0) { r_a1 = *(short *)((char *)r_v0 + (0xE)); }
    if (r_v0) { r_a2 = *(int *)((char *)r_v0 + (0xC4)); }
    r_v0 = (long)func_00130068((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133750 */
void *func_00133750(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    r_v0 = (long)&D_00133700;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_s1 = (long)&D_00133700;
    r_a0 = (long)(0 + (0x1));
    r_a2 = (long)(r_sp | (0x4));
    r_a3 = (long)(0 + (0xF));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_v1 != r_v0) { if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); } goto _lbl_L001337E4; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_v0 + 0);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    if ((long)r_a1 >= 0) { r_v0 = (long)(0 + 0); goto _lbl_L001337C8; }
    r_v0 = (long)(0 + 0);
    r_a0 = (long)&D_38CE40;
    r_a0 = (long)&D_38CE40;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L001337C8:
    r_a0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s1 + 0);
    r_a3 = (long)(0 + (-0x7E));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
_lbl_L001337E4:
    r_v0 = (long)(r_v1 + 0);
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_001337F8 */
void *func_001337F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_00133640;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_00133640;
    r_v0 = (long)func_00133598((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133818 */
void *func_00133818(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_a1 = (long)&func_001334B0;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_a1 = (long)&func_001334B0;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_v1 = *(int *)((char *)r_s0 + (0xB8)); }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_v1 = (long)(r_v1 + (0x1));
    if (r_s0) { *(int *)((char *)r_s0 + (0xB8)) = (int)r_v1; }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00133850 */
void *func_00133850(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s0 = (long)&D_4F9E40;
    r_s1 = (long)(r_a0 + 0);
    r_s0 = (long)&D_4F9E40;
    r_a1 = (long)(r_s1 + (0x38));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    if (r_s1) { *(int *)((char *)r_s1 + (0xC4)) = (int)r_s0; }
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_00133568((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00133898 */
void *func_00133898(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_001336E0;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_001336E0;
    r_v0 = (long)func_00133598((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_001338B8 */
void *func_001338B8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_v1 = *(int *)((char *)r_a0 + (0x20)); }
    r_a2 = (long)(0 + (0x1));
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0xB0)); }
    r_v0 = (long)(0 + (-0x80));
    if (r_v1 == 0) r_v1 = r_a2;
    if (r_a1) { *(int *)((char *)r_a1 + (0x0)) = (int)r_v1; }
    return (void *)r_v0;
}

/* func_001338D8 */
void *func_001338D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a1; }
    r_a3 = (long)(0 + (0x32));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)(r_a1 & r_v0);
    r_v0 = (long)func_00130960((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_00133908 */
void *func_00133908(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
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
    r_sp = (long)(r_sp + (-0xA0));
    if (r_sp) { *(long *)((char *)r_sp + (0x80)) = (long)r_s7; }
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_s6; }
    r_s7 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s5; }
    r_s6 = (long)&D_4F9700;
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s4; }
    r_s5 = (long)(r_t1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s3; }
    r_s4 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s2; }
    r_s3 = (long)(r_t0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_s1 = (long)(r_a1 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x90)) = (long)r_ra; }
    r_s0 = (long)(r_a2 + 0);
    if (r_s0 != 0) { if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a3; } goto _lbl_L00133978; }
    if (r_sp) { *(int *)((char *)r_sp + (0x0)) = (int)r_a3; }
    r_a0 = (long)&D_4904C0;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a0 = (long)&D_4904C0;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a2 = (long)(0 + (0x1C04));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00133978:
    if (r_s2 != 0) { if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (-0x6900)); } goto _lbl_L001339A4; }
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (-0x6900)); }
    r_a0 = (long)&D_4904E8;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a0 = (long)&D_4904E8;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a2 = (long)(0 + (0x1C06));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s7) { r_v0 = *(int *)((char *)r_s7 + (-0x6900)); }
_lbl_L001339A4:
    if (r_v0 != 0) { r_v0 = (long)(r_s4 + 0); goto _lbl_L00133ABC; }
    r_v0 = (long)(r_s4 + 0);
    r_a0 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012EF18((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_v0 = *(int *)((char *)r_sp + (0x0)); }
    r_a1 = (long)&D_00133930;
    r_t2 = (long)&D_38CE70;
    r_a3 = (long)((0xFFFF0000 >> 16) << 16);
    r_a3 = (long)((unsigned long)r_a3 >> (0));
    r_a3 = (long)(r_v0 & r_a3);
    r_a1 = (long)&D_00133930;
    r_a2 = (long)(r_s3 + 0);
    r_t1 = (long)(r_s5 + 0);
    r_t2 = (long)&D_38CE70;
    r_a0 = (long)(r_s6 + 0);
    r_t0 = (long)(0 + 0);
    r_v0 = (long)func_0012EF38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1 != 0) { r_v0 = (long)&D_4E2D58; goto _lbl_L001339F4; }
    r_v0 = (long)&D_4E2D58;
    r_s1 = (long)&D_4E2D58;
_lbl_L001339F4:
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x20) ? 1 : 0);
    if (r_v0 != 0) { r_a1 = (long)(r_s0 + 0); goto _lbl_L00133A2C; }
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)&D_490500;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a0 = (long)&D_490500;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a2 = (long)(0 + (0x1C12));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
_lbl_L00133A2C:
    r_a0 = (long)(r_s6 + (0x88));
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x20) ? 1 : 0);
    if (r_v0 != 0) { r_a1 = (long)(r_s2 + 0); goto _lbl_L00133A6C; }
    r_a1 = (long)(r_s2 + 0);
    r_a0 = (long)&D_490528;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a0 = (long)&D_490528;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a2 = (long)(0 + (0x1C15));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s2 + 0);
_lbl_L00133A6C:
    r_a0 = (long)(r_s6 + (0x38));
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x20) ? 1 : 0);
    if (r_v0 != 0) { r_a0 = (long)(r_s6 + (0x58)); goto _lbl_L00133AAC; }
    r_a0 = (long)(r_s6 + (0x58));
    r_a0 = (long)&D_490558;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a0 = (long)&D_490558;
    r_a1 = (long)&D_490068;
    r_a3 = (long)&D_4904D8;
    r_a2 = (long)(0 + (0x1C18));
    r_v0 = (long)func_123790((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s6 + (0x58));
_lbl_L00133AAC:
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_s4 = (long)(0 + (0x1));
    r_v0 = (long)(r_s4 + 0);
_lbl_L00133ABC:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x90)); }
    if (r_sp) { r_s7 = *(long *)((char *)r_sp + (0x80)); }
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x70)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
}

/* func_00133AE8 */
void *func_00133AE8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)&D_38CE70;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_38CE70;
    r_v0 = (long)func_0012EE20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133B08 */
void *func_00133B08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_v0 = (long)func_00130A50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133B28 */
void *func_00133B28(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a2 = (long)&D_00133DE8;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a2 = (long)&D_00133DE8;
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_00130AA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133B50 */
void *func_00133B50(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s0 = (long)(r_s1 + (0x58));
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_a1 = (long)(r_s0 + 0); goto _lbl_L00133BA8; }
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s1 + (0x38));
    r_s0 = (long)(0 + (0x1));
    r_v0 = (long)strcmp((const char *)r_a0, (const char *)r_a1);
    if (r_v0 != 0) { if (r_s1) { *(int *)((char *)r_s1 + (0xB4)) = (int)r_s0; } goto _lbl_L00133BB0; }
    if (r_s1) { *(int *)((char *)r_s1 + (0xB4)) = (int)r_s0; }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0x34)); }
    r_a1 = (long)(0 + (0x80));
    r_s0 = (long)(0 + (0x3));
    r_v0 = (long)func_0012F7A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x1));
    if (r_v0 != 0) r_s0 = r_v1;
    goto _lbl_L00133BAC;
_lbl_L00133BA8:
    r_s0 = (long)(0 + (0x2));
_lbl_L00133BAC:
    if (r_s1) { *(int *)((char *)r_s1 + (0xB4)) = (int)r_s0; }
_lbl_L00133BB0:
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1) { *(int *)((char *)r_s1 + (0xB8)) = (int)0; }
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00133BD0 */
void *func_00133BD0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    r_a1 = (long)(0 + (-0x7E));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_ra; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_s1) { r_s0 = *(int *)((char *)r_s1 + (0xB8)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xB4)); }
_lbl_L00133BF0:
    r_v1 = (long)((long)r_s0 < (long)(0x3) ? 1 : 0);
    if (r_v1 == 0) { r_v0 = (long)((long)r_a0 >> r_s0); goto _lbl_L00133C10; }
    r_v0 = (long)((long)r_a0 >> r_s0);
    r_v0 = (long)(r_v0 & (0x1));
    if (r_v0 == 0) { r_s0 = (long)(r_s0 + (0x1)); goto _lbl_L00133BF0; }
    r_s0 = (long)(r_s0 + (0x1));
    if (r_v1 != 0) { if (r_s1) { *(int *)((char *)r_s1 + (0xB8)) = (int)r_s0; } goto _lbl_L00133C28; }
    if (r_s1) { *(int *)((char *)r_s1 + (0xB8)) = (int)r_s0; }
_lbl_L00133C10:
    r_a1 = (long)&D_00133DE8;
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)&D_00133DE8;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_v0 + 0);
    if (r_s1) { *(int *)((char *)r_s1 + (0xB8)) = (int)r_s0; }
_lbl_L00133C28:
    r_v0 = (long)(r_a1 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
}

/* func_00133C40 */
void *func_00133C40(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x80));
    r_v0 = (long)((0xFFFF0000 >> 16) << 16);
    r_v0 = (long)((unsigned long)r_v0 >> (0));
    if (r_sp) { *(long *)((char *)r_sp + (0x60)) = (long)r_s6; }
    if (r_sp) { *(long *)((char *)r_sp + (0x50)) = (long)r_s5; }
    if (r_sp) { *(long *)((char *)r_sp + (0x40)) = (long)r_s4; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_s3; }
    r_s4 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s2; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x70)) = (long)r_ra; }
    r_s0 = (long)&D_4F9E40;
    r_s2 = (long)&D_4F9E40;
    r_s3 = (long)(r_s1 + (0x88));
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xF)); }
    if (r_s1) { r_a0 = *(int *)((char *)r_s1 + (0xC)); }
    r_a0 = (long)(r_a0 & r_v0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_v0 + 0);
    if (r_s1) { r_s5 = *(short *)((char *)r_s1 + (0xC)); }
    r_v0 = (long)((0x4E2D58 >> 16) << 16);
    if (r_s1) { r_s6 = *(short *)((char *)r_s1 + (0xE)); }
    /* unhandled: lbu */
    r_a0 = (long)(0 + (0x1));
    if (r_s0) { *(char *)((char *)r_s0 + (-0x61C0)) = (char)r_v1; }
    if (r_s1) { r_v1 = *(int *)((char *)r_s1 + (0xB8)); }
    if (r_v1 == r_a0) goto _lbl_L00133D1C;
    if (r_v1 == 0) { r_v0 = (long)(0 + (0x2)); goto _lbl_L00133CD0; }
    r_v0 = (long)(0 + (0x2));
    if (r_v1 == r_v0) goto _lbl_L00133D5C;
    r_s4 = (long)(0 + (0x1));
    goto _lbl_L00133DA8;
_lbl_L00133CD0:
    r_a0 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a0 = (long)(r_s2 + 0); goto _lbl_L00133D0C; }
    r_a0 = (long)(r_s2 + 0);
    r_s0 = (long)&D_4E2D48;
    r_s0 = (long)&D_4E2D48;
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s1 + (0x38));
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s2 + 0);
_lbl_L00133D0C:
    r_a1 = (long)(r_s1 + (0x58));
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    goto _lbl_L00133DA8;
_lbl_L00133D1C:
    r_a0 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_s4 = (long)(0 + (0x1)); goto _lbl_L00133DA8; }
    r_s4 = (long)(0 + (0x1));
    r_v0 = (long)&D_4E2D48;
    r_a0 = (long)(r_s2 + 0);
    r_t0 = (long)&D_4E2D48;
    r_a3 = (long)&D_4F9E40;
    if (r_t0) { r_v1 = *(signed char *)((char *)r_t0 + (0x0)); }
    if (r_t0) { r_a2 = *(signed char *)((char *)r_t0 + (0x1)); }
    if (r_a3) { *(char *)((char *)r_a3 + (0x0)) = (char)r_v1; }
    if (r_a3) { *(char *)((char *)r_a3 + (0x1)) = (char)r_a2; }
    r_a1 = (long)(r_s1 + (0x38));
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    goto _lbl_L00133DA8;
_lbl_L00133D5C:
    r_a0 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012F418((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) { r_a1 = (long)(r_s3 + 0); goto _lbl_L00133D9C; }
    r_a1 = (long)(r_s3 + 0);
    r_s0 = (long)&D_4E2D48;
    r_a0 = (long)(r_s2 + 0);
    r_s0 = (long)&D_4E2D48;
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s1 + (0x38));
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)(r_s3 + 0);
_lbl_L00133D9C:
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_s3 = (long)(r_s1 + (0x58));
_lbl_L00133DA8:
    if (r_s4 == 0) { r_a1 = (long)&D_00133DB8; goto _lbl_L00133DC4; }
    r_a1 = (long)&D_00133DB8;
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)&D_00133DB8;
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x70)); }
    goto _lbl_L00133DE0;
_lbl_L00133DC4:
    r_a0 = (long)(r_s5 + 0);
    r_a1 = (long)(r_s6 + 0);
    r_a2 = (long)(r_s2 + 0);
    r_a3 = (long)(r_s3 + 0);
    r_t0 = (long)(r_s1 + 0);
    r_v0 = (long)func_00130320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x70)); }
_lbl_L00133DE0:
    if (r_sp) { r_s6 = *(long *)((char *)r_sp + (0x60)); }
    if (r_sp) { r_s5 = *(long *)((char *)r_sp + (0x50)); }
    if (r_sp) { r_s4 = *(long *)((char *)r_sp + (0x40)); }
    if (r_sp) { r_s3 = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s2 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
}

/* func_00133E08 */
void *func_00133E08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x40));
    r_a3 = (long)(0 + (0x13));
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_s0; }
    r_a1 = (long)(r_sp + 0);
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x20)) = (long)r_s1; }
    if (r_sp) { *(long *)((char *)r_sp + (0x30)) = (long)r_ra; }
    r_a0 = (long)(0 + (0x1));
    r_a2 = (long)(r_sp | (0x4));
    r_t0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001303A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (-0x7E));
    if (r_s1 != r_v0) { r_v0 = (long)(r_s1 + 0); return func_00133F28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)(r_s1 + 0);
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xF)); }
    if (r_s0) { r_v0 = *(int *)((char *)r_s0 + (0xC)); }
    r_a0 = (long)((0xFFFF0000 >> 16) << 16);
    r_a0 = (long)((unsigned long)r_a0 >> (0));
    r_a0 = (long)(r_v0 & r_a0);
    r_v0 = (long)func_0012E4E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_a1 = *(int *)((char *)r_sp + (0x4)); }
    r_a2 = (long)(r_v0 + 0);
    if (r_a1 == 0) { r_a0 = (long)(0 + 0); goto _lbl_L00133E8C; }
    r_a0 = (long)(0 + 0);
    if ((long)r_a1 <= 0) { r_v0 = (long)(0 + (-0x4)); goto _lbl_L00133E7C; }
    r_v0 = (long)(0 + (-0x4));
    r_a1 = (long)(0 + (-0x4));
    if (r_sp) { *(int *)((char *)r_sp + (0x4)) = (int)r_v0; }
_lbl_L00133E7C:
    r_a0 = (long)&D_38CE90;
    r_a0 = (long)&D_38CE90;
    r_v0 = (long)func_0012F438((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
_lbl_L00133E8C:
    r_v0 = (long)(0 + (-0x77));
    if (r_a0 != r_v0) { r_a2 = (long)((0x130000 >> 16) << 16); return func_00133F28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a2 = (long)((0x130000 >> 16) << 16);
    if (r_s0) { r_a3 = *(int *)((char *)r_s0 + (0xB8)); }
    if (r_a3 == 0) { r_v0 = (long)((unsigned long)r_a3 < (unsigned long)(0x2) ? 1 : 0); return func_00133F28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_v0 = (long)((unsigned long)r_a3 < (unsigned long)(0x2) ? 1 : 0);
    if (r_v0 == 0) { r_a3 = (long)(r_s1 + 0); return func_00133F28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a3 = (long)(r_s1 + 0);
    if (r_s0) { *(int *)((char *)r_s0 + (0xBC)) = (int)r_a0; }
    r_a2 = (long)(0 + 0);
    if (r_a3 == 0) { if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (0xB4)); } goto _lbl_L00133EFC; }
    if (r_s0) { r_a1 = *(int *)((char *)r_s0 + (0xB4)); }
    r_a0 = (long)((0x490000 >> 16) << 16);
    r_v0 = (long)((long)r_a1 >> r_a2);
_lbl_L00133EC8:
    r_v0 = (long)(r_v0 & (0x1));
    if (r_v0 == 0) { r_v0 = (long)(0 + (0x2)); goto _lbl_L00133EE4; }
    r_v0 = (long)(0 + (0x2));
    r_v1 = (long)(0 + (0x1));
    r_v0 = (long)(r_v0 - r_a2);
    r_v1 = (long)((unsigned long)r_v1 << r_v0);
    r_a1 = (long)(r_a1 | r_v1);
_lbl_L00133EE4:
    r_a2 = (long)(r_a2 + (0x1));
    r_v0 = (long)((unsigned long)r_a2 < (unsigned long)r_a3 ? 1 : 0);
    if (r_v0 != 0) { r_v0 = (long)((long)r_a1 >> r_a2); goto _lbl_L00133EC8; }
    r_v0 = (long)((long)r_a1 >> r_a2);
    r_a2 = (long)(r_a3 + (0x1));
    goto _lbl_L00133F04;
_lbl_L00133EFC:
    r_a0 = (long)((0x490000 >> 16) << 16);
    r_a2 = (long)(r_a3 + (0x1));
_lbl_L00133F04:
    r_v0 = (long)((long)r_a2 < (long)(0x2) ? 1 : 0);
    if (r_v0 == 0) { r_a3 = (long)(0 + (0x1)); return func_00133F28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    r_a3 = (long)(0 + (0x1));
_lbl_L00133F10:
    r_v1 = (long)((unsigned long)r_a3 << r_a2);
    r_a1 = (long)(r_a1 | r_v1);
    r_a2 = (long)(r_a2 + (0x1));
    r_a1 = (long)(r_a1 ^ r_v1);
    r_v0 = (long)((long)r_a2 < (long)(0x2) ? 1 : 0);
    if (r_v0 != 0) goto _lbl_L00133F10;
    return func_00133F28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00133F28 */
void *func_00133F28(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_s1;
_lbl_L00133F2C:
    if (r_s0) { *(int *)((char *)r_s0 + (0xB4)) = (int)r_a1; }
    r_a0 = (long)(r_a0 + (0x588));
    r_s1 = (long)(0 + (-0x7E));
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s1 + 0);
    goto _lbl_L00133F5C;
_lbl_L00133F44:
    r_a3 = (long)(r_s1 + 0);
_lbl_L00133F48:
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_a2 + (0x3DE8));
    r_v0 = (long)func_0012FA30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s1 + 0);
_lbl_L00133F5C:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x30)); }
    if (r_sp) { r_s1 = *(long *)((char *)r_sp + (0x20)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x10)); }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
}

/* func_00133F70 */
void *func_00133F70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_v0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_ra; }
    r_a1 = (long)&D_00133A18;
    r_a1 = (long)&D_00133A18;
    if (r_v0) { r_v1 = *(int *)((char *)r_v0 + (0xB8)); }
    r_v1 = (long)(r_v1 + (0x1));
    if (r_v0) { *(int *)((char *)r_v0 + (0xB8)) = (int)r_v1; }
    r_v0 = (long)func_0012F108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
}

/* func_00133FA0 */
void *func_00133FA0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0xBC)); }
    if (r_a1 != 0) { if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (0xB0)); } goto _lbl_L00133FB0; }
    if (r_a0) { r_a2 = *(int *)((char *)r_a0 + (0xB0)); }
    if (r_a0) { r_a1 = *(int *)((char *)r_a0 + (0x20)); }
_lbl_L00133FB0:
    r_v1 = (long)(0 + (0x1));
    r_v0 = (long)(0 + (-0x80));
    if (r_a1 == 0) r_a1 = r_v1;
    if (r_a2) { *(int *)((char *)r_a2 + (0x0)) = (int)r_a1; }
    return (void *)r_v0;
}

/* func_00133FC8 */
void *func_00133FC8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_a2 = (long)((0x10010 >> 16) << 16);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_a1 = (long)(0 + 0);
    r_s0 = (long)&D_4F9EC0;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)&D_4F9EC0;
    r_a2 = (long)(r_a2 | ((0x10010 & 0xFFFF)));
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_117CAC((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)&D_509EC0;
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    r_a0 = (long)&D_509EC0;
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)func_1043B8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00134010((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00134010 */
void *func_00134010(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_v0 = (long)&D_509EC0;
    r_v0 = (long)&D_509EC0;
    return (void *)r_v0;
}

/* func_00134020 */
void *func_00134020(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_a1 = (long)(0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_a2 = (long)(0 + 0);
    r_s0 = (long)&D_509EC0;
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)&D_509EC0;
    r_a3 = (long)(0 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_104558((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_1043D8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + 0);
    r_v0 = (long)func_104FA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_123818((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) { r_a0 = *(int *)((char *)r_s0 + (0x4)); }
    r_v0 = (long)func_123848((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)func_1043C8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return func_00134080((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00134080 */
void *func_00134080(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_00133F28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) { r_s0 = (long)(r_s0 & (0x1)); goto _lbl_L001340D0; }
    r_s0 = (long)(r_s0 & (0x1));
    r_v0 = (long)&D_509ED0;
    r_a0 = (long)((unsigned long)r_s0 << (3));
    r_v0 = (long)&D_509ED0;
    r_v0 = (long)(r_a0 + r_v0);
    if (r_gp) { r_a3 = *(int *)((char *)r_gp + (-0x7780)); }
    if (r_v0) { r_a1 = *(long *)((char *)r_v0 + (0x0)); }
    r_v1 = (long)&D_509EE0;
    r_v1 = (long)&D_509EE0;
    if (r_gp) { r_a2 = *(int *)((char *)r_gp + (-0x777C)); }
    if (r_a3) { *(long *)((char *)r_a3 + (0x0)) = (long)r_a1; }
    r_a0 = (long)(r_a0 + r_v1);
    if (r_a0) { r_v0 = *(long *)((char *)r_a0 + (0x0)); }
    if (r_a2) { *(long *)((char *)r_a2 + (0x0)) = (long)r_v0; }
_lbl_L001340D0:
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
}

/* func_001340E0 */
void *func_001340E0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7778)); }
    r_v0 = (long)(r_v0 & (0x1));
    return (void *)r_v0;
}

/* func_001340F0 */
void *func_001340F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    if (r_gp) { r_v0 = *(int *)((char *)r_gp + (-0x7778)); }
    r_v1 = (long)(0 + (-0x2));
    r_a1 = (long)((unsigned long)0 < (unsigned long)r_a1 ? 1 : 0);
    r_a2 = (long)(0 + (0x80));
    r_v0 = (long)(r_v0 & r_v1);
    r_v0 = (long)(r_v0 | r_a1);
    if (r_a1 == 0) { if (r_gp) { *(int *)((char *)r_gp + (-0x7778)) = (int)r_v0; } return func_00134140((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3); }
    if (r_gp) { *(int *)((char *)r_gp + (-0x7778)) = (int)r_v0; }
    r_a1 = (long)(0 + (-0x81));
    r_v1 = (long)(0 + (0x1));
_lbl_L00134118:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0x0)); }
    r_v1 = (long)(r_v1 + (-0x1));
    r_v0 = (long)(r_v0 | (0x63));
    r_v0 = (long)(r_v0 & r_a1);
    if (r_a0) { *(int *)((char *)r_a0 + (0x0)) = (int)r_v0; }
    if (r_a0) { *(char *)((char *)r_a0 + (0x1)) = (char)r_a2; }
    if ((long)r_v1 >= 0) { r_a0 = (long)(r_a0 + (0x28)); goto _lbl_L00134118; }
    r_a0 = (long)(r_a0 + (0x28));
    return (void *)r_v0;
}

/* func_00134140 */
void *func_00134140(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    r_a1 = (long)(0 + (-0x2));
    r_v1 = (long)(0 + (0x1));
_lbl_L00134148:
    if (r_a0) { r_v0 = *(int *)((char *)r_a0 + (0x0)); }
    r_v1 = (long)(r_v1 + (-0x1));
    r_v0 = (long)(r_v0 & r_a1);
    r_v0 = (long)(r_v0 | (0x2));
    if (r_a0) { *(int *)((char *)r_a0 + (0x0)) = (int)r_v0; }
    if (r_a0) { *(char *)((char *)r_a0 + (0x1)) = (char)0; }
    if ((long)r_v1 >= 0) { r_a0 = (long)(r_a0 + (0x28)); goto _lbl_L00134148; }
    r_a0 = (long)(r_a0 + (0x28));
    return (void *)r_v0;
}

/* func_00134170 */
void *func_00134170(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t6 = 0, r_t7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t6;
    (void)r_t7;
    r_sp = (long)(r_sp + (-0x20));
    r_t7 = (long)&D_509ED0;
    if (r_sp) { *(long *)((char *)r_sp + (0x0)) = (long)r_s0; }
    r_t6 = (long)&D_509EE0;
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) { *(long *)((char *)r_sp + (0x10)) = (long)r_ra; }
    r_a2 = (long)&D_509ED0;
    r_a1 = (long)&D_509EE0;
    r_v1 = (long)(r_s0 + 0);
    r_a0 = (long)(0 + (0x1));
_lbl_L00134198:
    if (r_v1) { r_v0 = *(long *)((char *)r_v1 + (0x10)); }
    r_a0 = (long)(r_a0 + (-0x1));
    if (r_a2) { *(long *)((char *)r_a2 + (0x0)) = (long)r_v0; }
    r_a2 = (long)(r_a2 + (0x8));
    if (r_v1) { r_v0 = *(long *)((char *)r_v1 + (0x18)); }
    r_v1 = (long)(r_v1 + (0x28));
    if (r_a1) { *(long *)((char *)r_a1 + (0x0)) = (long)r_v0; }
    if ((long)r_a0 >= 0) goto _lbl_L00134198;
    return func_001341B8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_001341B8 */
void *func_001341B8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t1 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_t1;
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    (void)r_t7;
    r_a1 = (long)(r_a1 + (0x8));
    r_t5 = (long)(r_t6 + (-0x6120));
    if (r_t6) { r_a0 = *(long *)((char *)r_t6 + (-0x6120)); }
    if (r_t5) { r_a1 = *(long *)((char *)r_t5 + (0x8)); }
    r_a2 = (long)((0xFF800FFF >> 16) << 16);
    r_a2 = (long)(r_a2 | ((0xFF800FFF & 0xFFFF)));
    r_v1 = (long)((unsigned long)r_a0 << (20));
    r_v1 = (long)((long)r_v1 >> (0));
    if (r_t7) { r_t1 = *(long *)((char *)r_t7 + (-0x6130)); }
    r_v0 = (long)((unsigned long)r_a1 << (20));
_lbl_L001341E0:
    r_v0 = (long)((long)r_v0 >> (0));
    r_v1 = (long)(r_v1 & (0x7FF));
    r_v0 = (long)(r_v0 & (0x7FF));
    r_v1 = (long)(r_v1 + (-0x1));
    r_v0 = (long)(r_v0 + (-0x1));
    r_v1 = (long)(r_v1 & (0x7FF));
    r_v0 = (long)(r_v0 & (0x7FF));
_lbl_L001341FC:
    r_t4 = (long)(r_t7 + (-0x6130));
    r_a1 = (long)(r_a1 & r_a2);
    r_v1 = (long)((unsigned long)r_v1 << (12));
    r_a0 = (long)(r_a0 & r_a2);
    r_v0 = (long)((unsigned long)r_v0 << (12));
    return func_00134210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
}

/* func_00134210 */
void *func_00134210(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0, r_t4 = 0, r_t5 = 0, r_t6 = 0, r_t7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0; (void)r_v1; (void)r_a0; (void)r_a1; (void)r_a2; (void)r_a3; (void)r_sp; (void)r_ra; (void)r_gp;
    (void)r_s0;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    (void)r_t4;
    (void)r_t5;
    (void)r_t6;
    (void)r_t7;
    if (r_t4) { r_t2 = *(long *)((char *)r_t4 + (0x8)); }
    r_a1 = (long)(r_a1 | r_v0);
    r_a0 = (long)(r_a0 | r_v1);
    r_v0 = (long)((unsigned long)r_t1 >> (11));
    r_v1 = (long)((unsigned long)r_a0 >> (12));
    r_a2 = (long)((unsigned long)r_a1 >> (12));
    r_a3 = (long)((unsigned long)r_t2 >> (11));
    r_t0 = (long)((0xFF800FFF >> 16) << 16);
    r_t0 = (long)(r_t0 | ((0xFF800FFF & 0xFFFF)));
    r_t0 = (long)((unsigned long)r_t0 << (16));
    r_t0 = (long)(r_t0 | (0xFFFF));
    r_t0 = (long)((unsigned long)r_t0 << (16));
    r_t0 = (long)(r_t0 | (0xFFFF));
    r_t3 = (long)((0xFFC007FF >> 16) << 16);
    r_t3 = (long)(r_t3 | ((0xFFC007FF & 0xFFFF)));
    r_t3 = (long)((unsigned long)r_t3 << (16));
    r_t3 = (long)(r_t3 | (0xFFFF));
    r_t3 = (long)((unsigned long)r_t3 << (16));
    r_t3 = (long)(r_t3 | (0xFFFF));
    r_v1 = (long)(r_v1 & (0x7FF));
    r_v0 = (long)(r_v0 & (0x7FF));
    r_a2 = (long)(r_a2 & (0x7FF));
    r_a3 = (long)(r_a3 & (0x7FF));
    r_v1 = (long)((unsigned long)r_v1 << (12));
    r_a0 = (long)(r_a0 & r_t0);
    r_v0 = (long)((unsigned long)r_v0 << (11));
_lbl_L00134278:
    r_t1 = (long)(r_t1 & r_t3);
    r_a1 = (long)(r_a1 & r_t0);
    r_t2 = (long)(r_t2 & r_t3);
    r_a2 = (long)((unsigned long)r_a2 << (12));
    r_a3 = (long)((unsigned long)r_a3 << (11));
    r_a0 = (long)(r_a0 | r_v1);
    r_t1 = (long)(r_t1 | r_v0);
    r_a1 = (long)(r_a1 | r_a2);
    r_t2 = (long)(r_t2 | r_a3);
    if (r_t6) { *(long *)((char *)r_t6 + (-0x6120)) = (long)r_a0; }
    if (r_t7) { *(long *)((char *)r_t7 + (-0x6130)) = (long)r_t1; }
    if (r_t5) { *(long *)((char *)r_t5 + (0x8)) = (long)r_a1; }
    if (r_t4) { *(long *)((char *)r_t4 + (0x8)) = (long)r_t2; }
    r_v0 = (long)func_1236D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x1));
    if (r_v0 != r_v1) { r_v0 = (long)((0x12000050 >> 16) << 16); goto _lbl_L001342CC; }
    r_v0 = (long)((0x12000050 >> 16) << 16);
    r_v1 = (long)((0x12000060 >> 16) << 16);
    r_v0 = (long)(r_v0 | ((0x12000050 & 0xFFFF)));
    r_v1 = (long)(r_v1 | ((0x12000060 & 0xFFFF)));
    goto _lbl_L001342D8;
_lbl_L001342CC:
    r_v1 = (long)((0x12000080 >> 16) << 16);
    r_v0 = (long)(r_v0 | ((0x12000070 & 0xFFFF)));
    r_v1 = (long)(r_v1 | ((0x12000080 & 0xFFFF)));
_lbl_L001342D8:
    if (r_gp) { *(int *)((char *)r_gp + (-0x7780)) = (int)r_v0; }
    if (r_gp) { *(int *)((char *)r_gp + (-0x777C)) = (int)r_v1; }
    r_a0 = (long)(r_s0 + 0);
    if (r_sp) { r_ra = *(long *)((char *)r_sp + (0x10)); }
    if (r_sp) { r_s0 = *(long *)((char *)r_sp + (0x0)); }
    r_a1 = (long)(0 + (0x1));
    r_sp = (long)(r_sp + (0x20));
    return func_00133F28((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}
