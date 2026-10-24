/* KCET Hardware CD/DVD Server Subsystem (kt_libcdvd_server.c) */
#include "common.h"
#include "kt_libcdvd_server.h"

/* String functions */
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
int strcmp(const char *, const char *);
int strlen(const char *);
void *memset(void *, int, unsigned int);
void *memcpy(void *, const void *, unsigned int);

/* External data symbols */
extern char D_38C7D8[];
extern char D_48E101[];
extern char D_48F4D0[];
extern char D_48F4E0[];
extern char D_48F500[];
extern char D_48F518[];
extern char D_48F540[];
extern char D_48F560[];
extern char D_48F620[];
extern char D_48F630[];
extern char D_48F668[];
extern char D_48F678[];
extern char D_48F698[];
extern char D_48F6C0[];
extern char D_48F6D8[];
extern char D_48F7E8[];
extern char D_48F858[];
extern char D_48F890[];
extern char D_48F8A0[];
extern char D_48F900[];
extern char D_48F930[];
extern char D_48F970[];
extern char D_48F9A0[];
extern char D_48F9C8[];
extern char D_48F9D8[];
extern char D_48FA00[];
extern char D_48FA18[];
extern char D_48FA28[];
extern char D_48FA68[];
extern char D_48FAB0[];
extern char D_48FB68[];
extern char D_48FBA0[];
extern char D_48FBB8[];
extern char D_48FBE0[];
extern char D_48FBF8[];
extern char D_48FC08[];
extern char D_48FC28[];
extern char D_48FC50[];
extern char D_48FC78[];
extern char D_48FCB0[];
extern char D_48FCC8[];
extern char D_48FCF0[];
extern char D_48FD30[];
extern char D_48FD68[];
extern char D_48FD80[];
extern char D_48FD98[];
extern char D_48FDB0[];
extern char D_48FDC8[];
extern char D_48FE28[];
extern char D_4E2C30[];
extern char D_4E2C38[];
extern char D_4E2C40[];
extern char D_4E2C48[];
extern char D_4E2C50[];
extern char D_4E2C58[];
extern char D_4E2C68[];
extern char D_4E2C70[];
extern char D_4E2C78[];
extern char D_4E2C80[];
extern char D_4EC200[];
extern char D_4ED200[];
extern char D_4ED300[];
extern char D_4ED334[];
extern char D_4ED360[];
extern char D_4ED370[];
extern char D_4ED3E0[];
extern char D_4ED400[];
extern char D_4F1400[];
extern char D_4F1508[];
extern void *jtbl_48FE10[];

extern void *func_001143C0(void *a0, ...);
extern void *func_0011ACD0(void *a0, ...);
extern void *func_00128D10(void *a0, ...);
extern void *func_00128EC8(void *a0, ...);
extern void *func_00129348(void *a0, ...);
extern void *func_00129388(void *a0, ...);
extern void *func_001294E8(void *a0, ...);
extern void *func_00129548(void *a0, ...);
extern void *func_00129560(void *a0, ...);
extern void *func_00129588(void *a0, ...);
extern void *func_0012B8A8(void *a0, ...);
extern void *func_00134DE8(void *a0, ...);
extern void *func_103358(void *a0, ...);
extern void *func_104A00(void *a0, ...);
extern void *func_104D70(void *a0, ...);
extern void *func_104D80(void *a0, ...);
extern void *func_1057B0(void *a0, ...);
extern void *func_10DFB8(void *a0, ...);
extern void *func_10ECA0(void *a0, ...);
extern void *func_10F178(void *a0, ...);
extern void *func_10FD58(void *a0, ...);
extern void *func_114320(void *a0, ...);
extern void *func_118de0(void *a0, ...);
extern void *func_11AFB8(void *a0, ...);
extern void *func_12CEA0(void *a0, ...);
extern void *func_12CF58(void *a0, ...);
extern void *func_12CFC8(void *a0, ...);
extern void *func_12D038(void *a0, ...);
extern void *func_12D4D0(void *a0, ...);
extern void *func_12D5F0(void *a0, ...);
extern void *func_12D8D8(void *a0, ...);
extern void *func_12D990(void *a0, ...);
extern void *func_12DA38(void *a0, ...);
extern void *func_12DA88(void *a0, ...);
extern void *func_12DAC8(void *a0, ...);
extern void *func_12DB08(void *a0, ...);
extern void *func_12DB48(void *a0, ...);
extern void *func_12DB80(void *a0, ...);
extern void *func_12DBA0(void *a0, ...);
extern void *func_12DBC0(void *a0, ...);
extern void *func_12DBE0(void *a0, ...);
extern void *func_12DC00(void *a0, ...);
extern void *func_12DC20(void *a0, ...);
extern void *func_12DC60(void *a0, ...);
extern void *func_134140(void *a0, ...);
extern void *func_1341B8(void *a0, ...);
extern void *func_134210(void *a0, ...);
extern void *func_134378(void *a0, ...);
extern void *func_134440(void *a0, ...);
extern void *func_134480(void *a0, ...);
extern void *func_1344C0(void *a0, ...);
extern void *func_134500(void *a0, ...);

/* func_001295D0 */
void *func_001295D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_t0;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)&D_48F4D0;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    r_a2 = (long)(r_a0 + 0);
    r_a0 = (long)(r_sp + 0);
    r_a1 = (long)(0 + (0x2));
    r_t2 = (long)&D_48F4D0;
    if (r_t2) {
        r_v1 = *(long *)((char *)r_t2 + (0x7));
    }
    if (r_t2) {
        r_v1 = *(long *)((char *)r_t2 + (0x0));
    }
    if (r_t2) {
        r_t0 = *(long *)((char *)r_t2 + (0xF));
    }
    if (r_t2) {
        r_t0 = *(long *)((char *)r_t2 + (0x8));
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x7)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0xF)) = (long)r_t0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x8)) = (long)r_t0;
    }
    r_a3 = (long)(0 + (0x7));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129620 */
void *func_00129620(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    if (r_s1) {
        r_v0 = *(int *)((char *)r_s1 + (0x0));
    }
    if (r_v0 == 0) {
        r_s0 = (long)(r_a1 + 0);
        goto _lbl_L00129658;
    }
    r_s0 = (long)(r_a1 + 0);
    r_v0 = (long)(r_v0 & r_s0);
    if (r_v0 != 0) {
        if (r_s1) {
            *(int *)((char *)r_s1 + (0x0)) = (int)r_s0;
        }
        goto _lbl_L0012965C;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x0)) = (int)r_s0;
    }
    r_a0 = (long)&D_48F4E0;
    r_a0 = (long)&D_48F4E0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00129658:
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x0)) = (int)r_s0;
    }
_lbl_L0012965C:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129670 */
void *func_00129670(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s0 = (long)(r_a1 + 0);
    r_v0 = (long)func_00129348((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)&D_38C7D8;
    r_v0 = (long)func_0012CCD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_001295D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_v0 + 0);
    r_s1 = (long)&D_38C7D8;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_00129620((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_a2 = (long)(r_s0 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return func_001299A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_001296D8 */
void *func_001296D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    return func_00129670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_001296E0 */
void *func_001296E0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F518;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a2 = (long)&D_48F518;
    r_a0 = (long)&D_48F500;
    r_a1 = (long)(0 + (0x130));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_a0 = (long)(0 + 0);
    r_a1 = (long)(0 + (-0x1));
    r_sp = (long)(r_sp + (0x10));
    return func_00129670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_00129718 */
void *func_00129718(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F518;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a2 = (long)&D_48F518;
    r_a0 = (long)&D_48F500;
    r_a1 = (long)(0 + (0x136));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)(0 + (-0x1));
    r_sp = (long)(r_sp + (0x10));
    return func_00129670((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_00129750 */
void *func_00129750(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_v0 = (long)func_0012BB20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)func_00129388((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_00129770 */
void *func_00129770(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129778 */
void *func_00129778(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s0 = (long)(r_a1 + 0);
    r_v0 = (long)func_10ECA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x1));
    if (r_s1 != r_v0) {
        r_a0 = (long)&D_48F540;
        goto _lbl_L001297E0;
    }
    r_a0 = (long)&D_48F540;
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_10F178((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)func_001295D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_a0 = (long)&D_38C7D8;
    r_a0 = (long)&D_38C7D8;
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)func_00129620((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_4ED300;
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)&D_4ED300;
    r_v0 = (long)func_00129620((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s1 + 0);
    goto _lbl_L001297EC;
_lbl_L001297E0:
    r_a0 = (long)&D_48F540;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s1 + 0);
_lbl_L001297EC:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129800 */
void *func_00129800(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_a2 = (long)(r_a0 + 0);
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_48F560;
    r_a3 = (long)&D_48F620;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a0 = (long)&D_48F560;
    r_a3 = (long)&D_48F620;
    r_a1 = (long)(0 + (0x8));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129830 */
void *func_00129830(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_s7;
    (void)r_s8;
    r_sp = (long)(r_sp + (-0x10A0));
    r_v0 = (long)((0xFFFFFFC0 >> 16) << 16);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1080)) = (long)r_s8;
    }
    r_v1 = (long)(r_sp + (0x3F));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1070)) = (long)r_s7;
    }
    r_v0 = (long)(r_v0 | ((0xFFFFFFC0 & 0xFFFF)));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1060)) = (long)r_s6;
    }
    r_s7 = (long)(0 + (0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1050)) = (long)r_s5;
    }
    r_s8 = (long)&D_48F630;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1040)) = (long)r_s4;
    }
    r_s5 = (long)&D_48F668;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1030)) = (long)r_s3;
    }
    r_s4 = (long)(0 + (0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1020)) = (long)r_s2;
    }
    r_s3 = (long)(r_v1 & r_v0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1010)) = (long)r_s1;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1090)) = (long)r_ra;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1000)) = (long)r_s0;
    }
    r_s6 = (long)(0 + (0x2));
    goto _lbl_L001298B8;
_lbl_L00129890:
    r_a0 = (long)(r_s3 + 0);
    r_v0 = (long)func_12DBE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s0)
        goto _lbl_L0012991C;
    if (r_s1 != 0) {
        r_a0 = (long)(0 + 0);
        goto _lbl_L0012992C;
    }
    r_a0 = (long)(0 + 0);
    goto _lbl_L001298BC;
_lbl_L001298B0:
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L001298B8:
    r_a0 = (long)(0 + 0);
_lbl_L001298BC:
    r_a1 = (long)(r_s2 + 0);
    r_v0 = (long)func_12D5F0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != r_s4) {
        r_a0 = (long)&D_48F668;
        goto _lbl_L001298B0;
    }
    r_a0 = (long)&D_48F668;
    r_a0 = (long)(0 + 0);
    r_v0 = (long)func_12DB80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s6)
        goto _lbl_L001298E4;
    if (r_s1 == 0) {
        r_a0 = (long)(0 + 0);
        goto _lbl_L001298BC;
    }
    r_a0 = (long)(0 + 0);
_lbl_L001298E4:
    r_s0 = (long)(0 + (0x1));
    r_v0 = (long)func_12DAC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s0)
        goto _lbl_L001298FC;
    if (r_s1 == 0) {
        r_a0 = (long)(0 + 0);
        goto _lbl_L001298BC;
    }
    r_a0 = (long)(0 + 0);
_lbl_L001298FC:
    if (r_s1 != 0)
        goto _lbl_L0012990C;
    r_a0 = (long)(0 + 0);
    r_v0 = (long)func_001294E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012990C:
    r_a0 = (long)(0 + 0);
    r_v0 = (long)func_12DB80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3 != 0)
        goto _lbl_L00129890;
_lbl_L0012991C:
    if (r_s1 != 0) {
        r_s0 = (long)(0 + (0xE10));
        goto _lbl_L00129930;
    }
    r_s0 = (long)(0 + (0xE10));
    r_a0 = (long)(0 + 0);
    r_v0 = (long)func_001294E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012992C:
    r_s0 = (long)(0 + (0xE10));
_lbl_L00129930:
    r_a0 = (long)(0 + 0);
_lbl_L00129934:
    r_s0 = (long)(r_s0 + (-0x1));
    r_v0 = (long)func_103358((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_12DA38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_48F630;
    r_a1 = (long)(0 + (0x7));
    r_a3 = (long)(0 + (0x1));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0)
        goto _lbl_L00129968;
    r_s7 = (long)(0 + 0);
    goto _lbl_L00129970;
_lbl_L00129968:
    if ((long)r_s0 > 0) {
        r_a0 = (long)(0 + 0);
        goto _lbl_L00129934;
    }
    r_a0 = (long)(0 + 0);
_lbl_L00129970:
    if (r_s7 != 0) {
        r_a0 = (long)(0 + 0);
        goto _lbl_L001298BC;
    }
    r_a0 = (long)(0 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x1090));
    }
    if (r_sp) {
        r_s8 = *(long *)((char *)r_sp + (0x1080));
    }
    if (r_sp) {
        r_s7 = *(long *)((char *)r_sp + (0x1070));
    }
    if (r_sp) {
        r_s6 = *(long *)((char *)r_sp + (0x1060));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x1050));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x1040));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x1030));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x1020));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x1010));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x1000));
    }
    r_sp = (long)(r_sp + (0x10A0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_001299A8 */
void *func_001299A8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_s2 = (long)(r_a1 + 0);
    r_v0 = (long)func_134140((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + (-0x2));
    r_s1 = (long)(r_v0 + (-0x1));
    r_v0 = (long)((long)r_s0 < (long)r_s1 ? 1 : 0);
    if (r_v0 != 0) {
        r_a0 = (long)&D_48F500;
        goto _lbl_L001299FC;
    }
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F678;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F678;
    r_a1 = (long)(0 + (0x203));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L001299FC:
    if ((long)r_s0 < 0) {
        r_a0 = (long)&D_48F500;
        goto _lbl_L00129A10;
    }
    r_a0 = (long)&D_48F500;
    /* unhandled: bgezl */
    r_a0 = (long)(r_s2 + 0);
    r_a0 = (long)&D_48F500;
_lbl_L00129A10:
    r_a2 = (long)&D_48F698;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F698;
    r_a1 = (long)(0 + (0x204));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 + 0);
_lbl_L00129A28:
    r_a1 = (long)(r_s3 + 0);
    r_v0 = (long)func_00129830((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)&D_4EC200;
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)&D_4EC200;
    r_a2 = (long)(0 + (0x1000));
    r_v0 = (long)func_12DC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + 0);
    r_v0 = (long)func_10DFB8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) {
        r_a0 = (long)&D_48F500;
        goto _lbl_L00129A68;
    }
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F6C0;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F6C0;
    r_a1 = (long)(0 + (0x20C));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00129A68:
    r_a0 = (long)(r_s4 + 0);
    r_a1 = (long)(r_s1 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x60));
    return func_0012BA68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_00129A90 */
void *func_00129A90(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CFC));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129AA0 */
void *func_00129AA0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CF8));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129AB0 */
void *func_00129AB0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_a2 = (long)(r_a0 + 0);
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_48F6D8;
    r_a3 = (long)&D_4E2C40;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a0 = (long)&D_48F6D8;
    r_a3 = (long)&D_4E2C40;
    r_a1 = (long)(0 + (0xB));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129AE0 */
void *func_00129AE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_a2 = (long)(r_a0 + 0);
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_48F7E8;
    r_a3 = (long)&D_4E2C40;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a0 = (long)&D_48F7E8;
    r_a3 = (long)&D_4E2C40;
    r_a1 = (long)(0 + (0x4));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129B10 */
void *func_00129B10(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s4 = (long)(0 + (0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_s0 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_s2) {
        r_s3 = *(int *)((char *)r_s2 + (0x0));
    }
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s4) {
        r_s1 = (long)(0 + 0);
        goto _lbl_L00129BB0;
    }
    r_s1 = (long)(0 + 0);
    r_v0 = (long)func_12DBC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_a0 = (long)&D_48F858;
    r_a0 = (long)&D_48F858;
    r_a1 = (long)(0 + (0x7));
    r_a2 = (long)(r_s1 + 0);
    r_a3 = (long)(0 + (-0x1));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0) {
        r_v0 = (long)(r_s3 & r_v0);
        goto _lbl_L00129B80;
    }
    r_v0 = (long)(r_s3 & r_v0);
    r_s0 = (long)(0 + (0x3));
    if (r_v0 != 0)
        r_s0 = 0;
    goto _lbl_L00129BB0;
_lbl_L00129B80:
    if (r_s1 == r_s4) {
        r_v0 = (long)((long)r_s1 < (long)(0x2) ? 1 : 0);
        goto _lbl_L00129BAC;
    }
    r_v0 = (long)((long)r_s1 < (long)(0x2) ? 1 : 0);
    if (r_v0 != 0) {
        r_s0 = (long)(0 + (0x2));
        goto _lbl_L00129BB0;
    }
    r_s0 = (long)(0 + (0x2));
    r_v0 = (long)(0 + (0x5));
    if (r_s1 == r_v0) {
        r_v0 = (long)(0 + (0xFF));
        goto _lbl_L00129BA4;
    }
    r_v0 = (long)(0 + (0xFF));
    if (r_s1 != r_v0) {
        if (r_s2) {
            *(int *)((char *)r_s2 + (0x4)) = (int)r_s1;
        }
        goto _lbl_L00129BB4;
    }
    if (r_s2) {
        *(int *)((char *)r_s2 + (0x4)) = (int)r_s1;
    }
_lbl_L00129BA4:
    r_s0 = (long)(0 + (0x3));
    goto _lbl_L00129BB0;
_lbl_L00129BAC:
    r_s0 = (long)(0 + (0x1));
_lbl_L00129BB0:
    if (r_s2) {
        *(int *)((char *)r_s2 + (0x4)) = (int)r_s1;
    }
_lbl_L00129BB4:
    r_v0 = (long)(r_s0 + 0);
    if (r_s2) {
        *(int *)((char *)r_s2 + (0x8)) = (int)r_s0;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129BE0 */
void *func_00129BE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_s0 = (long)(r_a3 + 0);
    if (r_t0 == 0) {
        if (r_sp) {
            *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
        }
        goto _lbl_L00129C1C;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_v0 = (long)&D_4E2C48;
    r_s3 = (long)&D_4E2C48;
    goto _lbl_L00129C24;
_lbl_L00129C1C:
    r_v0 = (long)&D_4E2C38;
    r_s3 = (long)&D_4E2C38;
_lbl_L00129C24:
    if (r_s2 == 0) {
        r_a0 = (long)&D_48F500;
        goto _lbl_L00129C38;
    }
    r_a0 = (long)&D_48F500;
    if (r_s1 != 0) {
        r_a0 = (long)(r_s1 + 0);
        goto _lbl_L00129C50;
    }
    r_a0 = (long)(r_s1 + 0);
    r_a0 = (long)&D_48F500;
_lbl_L00129C38:
    r_a2 = (long)&D_48F890;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F890;
    r_a1 = (long)(0 + (0x2A4));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 + 0);
_lbl_L00129C50:
    r_a1 = (long)(r_s3 + 0);
    r_v0 = (long)strcpy((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s1 + r_v0);
    r_a0 = (long)(0 + (0x5C));
    if (r_v0) {
        r_v1 = *(signed char *)((char *)r_v0 + (-0x1));
    }
    if (r_v1 == r_a0)
        goto _lbl_L00129C90;
    r_a1 = (long)&D_4E2C30;
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)&D_4E2C30;
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
_lbl_L00129C90:
    r_a0 = (long)(r_s4 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s4 + 0);
    r_a2 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_11AFB8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_s2 + r_s0);
    r_a0 = (long)(r_s1 + 0);
    if (r_v0 != 0)
        r_a1 = r_s2;
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a1 = (long)&D_4E2C50;
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)&D_4E2C50;
    r_v0 = (long)strcat((char *)r_a0, (const char *)r_a1);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s3 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_t1 = (long)(r_v0 + 0);
    r_v0 = (long)((long)r_t1 < (long)r_s0 ? 1 : 0);
    if (r_v0 == 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x50));
        }
        goto _lbl_L00129D3C;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    r_t2 = (long)&D_48E101;
_lbl_L00129CF8:
    r_t0 = (long)(r_s1 + r_t1);
    r_a0 = (long)&D_48E101;
    if (r_t0) {
        r_a1 = *(unsigned char *)((char *)r_t0 + (0x0));
    }
    r_a2 = (long)(0 + (0x5C));
    r_t1 = (long)(r_t1 + (0x1));
    r_a0 = (long)(r_a1 + r_a0);
    r_v1 = (long)(r_a1 + (-0x20));
    if (r_a0) {
        r_v0 = *(unsigned char *)((char *)r_a0 + (0x0));
    }
    r_a3 = (long)((long)r_t1 < (long)r_s0 ? 1 : 0);
    r_v0 = (long)(r_v0 & (0x2));
    if (r_v0 == 0)
        r_v1 = r_a1;
    r_v1 = (long)(r_v1 & (0xFF));
    r_v0 = (long)(r_v1 ^ (0x2F));
    if (r_v0 != 0)
        r_a2 = r_v1;
    if (r_a3 != 0) {
        if (r_t0) {
            *(char *)((char *)r_t0 + (0x0)) = (char)r_a2;
        }
        goto _lbl_L00129CF8;
    }
    if (r_t0) {
        *(char *)((char *)r_t0 + (0x0)) = (char)r_a2;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
_lbl_L00129D3C:
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129D58 */
void *func_00129D58(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    r_s2 = (long)(r_a0 + 0);
    r_v0 = (long)func_0012A0A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012A0B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0011ACD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_s0 + r_v0);
    r_s0 = (long)(r_s0 + (0x9));
    r_s0 = (long)((unsigned long)r_s0 < (unsigned long)(0x100) ? 1 : 0);
    if (r_s0 != 0) {
        r_s0 = (long)&D_4ED200;
        goto _lbl_L00129DC8;
    }
    r_s0 = (long)&D_4ED200;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F8A0;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F8A0;
    r_a1 = (long)(0 + (0x2C7));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)&D_4ED200;
_lbl_L00129DC8:
    r_a1 = (long)(r_s2 + 0);
    r_s0 = (long)&D_4ED200;
    r_a2 = (long)(r_s3 + 0);
    r_a3 = (long)(r_s1 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_t0 = (long)(0 + 0);
    r_v0 = (long)func_00129BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129E08 */
void *func_00129E08(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    r_s1 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012A0A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012A0B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_a2 = (long)(r_s0 + 0);
    r_t0 = (long)(r_s3 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    r_a3 = (long)(r_v0 + 0);
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x50));
    return func_00129BE0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_00129E68 */
void *func_00129E68(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)(0 + (0x1));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129E70 */
void *func_00129E70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CF4));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129E80 */
void *func_00129E80(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_00129E70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)((unsigned long)r_s0 < (unsigned long)(0x2) ? 1 : 0);
    if (r_v0 != 0) {
        r_v1 = (long)((0x4F0000 >> 16) << 16);
        goto _lbl_L00129EC4;
    }
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F900;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F900;
    r_a1 = (long)(0 + (0x2EF));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((0x4F0000 >> 16) << 16);
_lbl_L00129EC4:
    r_v0 = (long)(r_s1 + 0);
    if (r_v1) {
        *(int *)((char *)r_v1 + (-0x2CF4)) = (int)r_s0;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129EE0 */
void *func_00129EE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CEC));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129EF0 */
void *func_00129EF0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_v0 = (long)(0 + (0x1));
    if (r_a0 == r_v0) {
        if (r_sp) {
            *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
        }
        goto _lbl_L00129F40;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_v0 = (long)((long)r_a0 < (long)(0x2) ? 1 : 0);
    if (r_v0 == 0) {
        r_v0 = (long)(0 + (0x2));
        goto _lbl_L00129F1C;
    }
    r_v0 = (long)(0 + (0x2));
    if (r_a0 == 0) {
        r_a0 = (long)&D_48F500;
        goto _lbl_L00129F38;
    }
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    goto _lbl_L00129F28;
_lbl_L00129F1C:
    if (r_a0 == r_v0) {
        r_a0 = (long)&D_48F500;
        goto _lbl_L00129F48;
    }
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
_lbl_L00129F28:
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a1 = (long)(0 + (0x302));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L00129F38:
    r_v0 = (long)(0 + (0x800));
    goto _lbl_L00129F4C;
_lbl_L00129F40:
    r_v0 = (long)(0 + (0x918));
    goto _lbl_L00129F4C;
_lbl_L00129F48:
    r_v0 = (long)(0 + (0x924));
_lbl_L00129F4C:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129F58 */
void *func_00129F58(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CF0));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129F68 */
void *func_00129F68(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s0 + (-0x1));
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x2) ? 1 : 0);
    if (r_v0 != 0) {
        r_v1 = (long)((0x4F0000 >> 16) << 16);
        goto _lbl_L00129FB0;
    }
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F930;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F930;
    r_a1 = (long)(0 + (0x318));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((0x4F0000 >> 16) << 16);
_lbl_L00129FB0:
    r_v0 = (long)(r_s1 + 0);
    if (r_v1) {
        *(int *)((char *)r_v1 + (-0x2CF0)) = (int)r_s0;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129FD0 */
void *func_00129FD0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CE8));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_00129FE0 */
void *func_00129FE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)((unsigned long)r_s0 < (unsigned long)(0x2) ? 1 : 0);
    if (r_v0 != 0) {
        r_v1 = (long)((0x4F0000 >> 16) << 16);
        goto _lbl_L0012A024;
    }
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F970;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48F970;
    r_a1 = (long)(0 + (0x32B));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((0x4F0000 >> 16) << 16);
_lbl_L0012A024:
    r_v0 = (long)(r_s1 + 0);
    if (r_v1) {
        *(int *)((char *)r_v1 + (-0x2CE8)) = (int)r_s0;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A040 */
void *func_0012A040(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CE4));
    }
    r_v0 = (long)(r_v0 ^ (0x1));
    r_v0 = (long)((unsigned long)r_v0 < (unsigned long)(0x1) ? 1 : 0);
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A058 */
void *func_0012A058(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_0012A040((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (-0x2CE4)) = (int)r_s0;
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A088 */
void *func_0012A088(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)&D_4ED300;
    r_v0 = (long)&D_4ED300;
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x24)) = (int)r_a1;
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x20)) = (int)r_a0;
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A0A0 */
void *func_0012A0A0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CE0));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A0B0 */
void *func_0012A0B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CDC));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A0C0 */
void *func_0012A0C0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CD4));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A0D0 */
void *func_0012A0D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CD8));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A0E0 */
void *func_0012A0E0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x1C));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A0E8 */
void *func_0012A0E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_a0 = (long)((unsigned long)0 < (unsigned long)r_a0 ? 1 : 0);
    r_v0 = (long)((0x4F0000 >> 16) << 16);
    if (r_v0) {
        *(int *)((char *)r_v0 + (-0x2CD0)) = (int)r_a0;
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A0F8 */
void *func_0012A0F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CD0));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A108 */
void *func_0012A108(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s2 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s0 = (long)(r_a1 + 0);
    if (r_s0 == 0) {
        if (r_sp) {
            *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
        }
        goto _lbl_L0012A160;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_v0 = (long)func_00129D58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s1 + 0);
    r_v0 = (long)func_12DC00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        r_s2 = (long)(0 + (0x1));
        goto _lbl_L0012A160;
    }
    r_s2 = (long)(0 + (0x1));
    r_a0 = (long)&D_48F9A0;
    r_a1 = (long)(r_s1 + 0);
    r_a0 = (long)&D_48F9A0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s2 + 0);
    goto _lbl_L0012A164;
_lbl_L0012A160:
    r_v0 = (long)(r_s2 + 0);
_lbl_L0012A164:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A180 */
void *func_0012A180(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    if (r_a1) {
        r_a0 = *(int *)((char *)r_a1 + (0x2C));
    }
    if (r_a0 == 0) {
        r_v0 = (long)(0 + (0x2));
        goto _lbl_L0012A1A0;
    }
    r_v0 = (long)(0 + (0x2));
    r_a1 = (long)(r_a1 + (0x48));
    r_v0 = (long)func_0012A108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012A1A0:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A1B0 */
void *func_0012A1B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    r_a0 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s4 = (long)(r_v0 + (0x34));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_v0) {
        r_s0 = *(int *)((char *)r_v0 + (0x6C));
    }
    if (r_v0) {
        r_v1 = *(int *)((char *)r_v0 + (0x28));
    }
    if (r_v0) {
        r_a2 = *(int *)((char *)r_v0 + (0x3C));
    }
    if (r_v0) {
        r_s3 = *(int *)((char *)r_v0 + (0x30));
    }
    if (r_v0) {
        r_a3 = *(int *)((char *)r_v0 + (0x20));
    }
    r_v1 = (long)(r_v1 + r_a2);
    if (r_v0) {
        r_s2 = *(int *)((char *)r_v0 + (0x24));
    }
    if (r_v0) {
        r_a1 = *(int *)((char *)r_v0 + (0x38));
    }
    r_s1 = (long)(r_a3 + r_v1);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x8)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)r_s3;
    }
    if (r_a1 != 0)
        r_s2 = r_a1;
    r_v0 = (long)func_00129EF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: mult */
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_s1;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x10)) = (int)r_v0;
    }
    r_s0 = (long)&D_48F9C8;
    goto _lbl_L0012A230;
_lbl_L0012A220:
    r_a0 = (long)&D_48F9C8;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012A230:
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_a3 = (long)(r_s4 + 0);
    r_v0 = (long)func_12D8D8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        goto _lbl_L0012A220;
_lbl_L0012A250:
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_12D990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x50));
        }
        goto _lbl_L0012A250;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    r_v0 = (long)(0 + (0x1));
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A288 */
void *func_0012A288(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x20));
    }
    if (r_a0) {
        r_v1 = *(int *)((char *)r_a0 + (0x28));
    }
    if (r_a0) {
        r_a1 = *(int *)((char *)r_a0 + (0x3C));
    }
    r_v0 = (long)(r_v0 + r_v1);
    r_v0 = (long)(r_v0 + r_a1);
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A2A0 */
void *func_0012A2A0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_0012A288((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    if (r_s0) {
        r_v0 = *(int *)((char *)r_s0 + (0x6C));
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (0xC)) = (int)r_s1;
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x8)) = (int)0;
    }
    r_s0 = (long)&D_48F9C8;
    goto _lbl_L0012A2E0;
_lbl_L0012A2D0:
    r_a0 = (long)&D_48F9C8;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012A2E0:
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_12DC20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        goto _lbl_L0012A2D0;
_lbl_L0012A2F0:
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_12D990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x20));
        }
        goto _lbl_L0012A2F0;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    r_v0 = (long)(0 + (0x1));
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A320 */
void *func_0012A320(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x6C));
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x8)) = (int)0;
    }
    r_s0 = (long)&D_48F9C8;
    goto _lbl_L0012A350;
_lbl_L0012A340:
    r_a0 = (long)&D_48F9C8;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012A350:
    r_v0 = (long)func_12DB08((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        goto _lbl_L0012A340;
_lbl_L0012A360:
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_12D990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x10));
        }
        goto _lbl_L0012A360;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    r_v0 = (long)(0 + (0x1));
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A388 */
void *func_0012A388(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x6C));
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x8)) = (int)0;
    }
    r_s0 = (long)&D_48F9C8;
    goto _lbl_L0012A3B8;
_lbl_L0012A3A8:
    r_a0 = (long)&D_48F9C8;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012A3B8:
    r_v0 = (long)func_12DA88((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        goto _lbl_L0012A3A8;
_lbl_L0012A3C8:
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_12D990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x10));
        }
        goto _lbl_L0012A3C8;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    r_v0 = (long)(0 + (0x1));
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A3F0 */
void *func_0012A3F0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x6C));
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x8)) = (int)0;
    }
    r_s0 = (long)&D_48F9C8;
    goto _lbl_L0012A420;
_lbl_L0012A410:
    r_a0 = (long)&D_48F9C8;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012A420:
    r_v0 = (long)func_12DAC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        goto _lbl_L0012A410;
_lbl_L0012A430:
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_12D990((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x10));
        }
        goto _lbl_L0012A430;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    r_v0 = (long)(0 + (0x1));
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A458 */
void *func_0012A458(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)&D_48FA00;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s1;
    }
    r_a1 = (long)(0 + (0x5));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s0;
    }
    r_a3 = (long)(0 + (-0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_a0 = (long)&D_48F9D8;
    r_s1 = (long)(0 + 0);
    if (r_s0) {
        r_a2 = *(int *)((char *)r_s0 + (0x40));
    }
    r_t2 = (long)&D_48FA00;
    if (r_t2) {
        r_v1 = *(long *)((char *)r_t2 + (0x7));
    }
    if (r_t2) {
        r_v1 = *(long *)((char *)r_t2 + (0x0));
    }
    if (r_t2) {
        r_t0 = *(long *)((char *)r_t2 + (0xF));
    }
    if (r_t2) {
        r_t0 = *(long *)((char *)r_t2 + (0x8));
    }
    if (r_t2) {
        r_t1 = *(int *)((char *)r_t2 + (0x10));
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x7)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0xF)) = (long)r_t0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x8)) = (long)r_t0;
    }
    if (r_sp) {
        *(int *)((char *)r_sp + (0x10)) = (int)r_t1;
    }
    r_a0 = (long)&D_48F9D8;
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 >= 0) {
        r_v0 = (long)((unsigned long)r_v0 << (2));
        goto _lbl_L0012A4E0;
    }
    r_v0 = (long)((unsigned long)r_v0 << (2));
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FA18;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FA18;
    r_a1 = (long)(0 + (0x4C0));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s1 + 0);
    goto _lbl_L0012A4F8;
_lbl_L0012A4E0:
    r_v1 = (long)(r_sp + r_v0);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (0x0));
    }
    r_a0 = (long)(r_s0 + 0);
    if (r_v0) {
        r_v0 = (long)((void *(*)(void *, ...))r_v0)((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    }
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(r_s1 + 0);
_lbl_L0012A4F8:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x20));
    }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A510 */
void *func_0012A510(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_v0 = (long)func_12DBA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_48FA28;
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_48FA28;
    r_a1 = (long)(0 + (0x8));
    r_a3 = (long)(0 + (0x2));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A548 */
void *func_0012A548(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_a2 = (long)(r_a0 + 0);
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_48FA68;
    r_a3 = (long)&D_48FAB0;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a0 = (long)&D_48FA68;
    r_a3 = (long)&D_48FAB0;
    r_a1 = (long)(0 + (0x9));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A578 */
void *func_0012A578(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s5;
    }
    r_s0 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    r_s5 = (long)&D_48FB68;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)(0 + (-0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)(0 + (0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(0 + (0x2));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_ra;
    }
    r_s1 = (long)(r_s0 + 0);
    goto _lbl_L0012A5C4;
_lbl_L0012A5B8:
    r_s0 = (long)(0 + (0x2));
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_s1 + (0x1));
_lbl_L0012A5C4:
    r_v0 = (long)((long)r_s1 < (long)(0x3C) ? 1 : 0);
    if (r_v0 == 0) {
        r_v0 = (long)(r_s0 + 0);
        goto _lbl_L0012A624;
    }
    r_v0 = (long)(r_s0 + 0);
    r_v0 = (long)func_12DA38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_v0 + 0);
    r_a0 = (long)&D_48FB68;
    r_a1 = (long)(0 + (0x7));
    r_a3 = (long)(0 + 0);
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if (r_s0 != r_s4)
        goto _lbl_L0012A600;
    r_s0 = (long)(0 + (0x5));
    goto _lbl_L0012A620;
_lbl_L0012A600:
    if (r_s0 == r_s3) {
        r_s0 = (long)(0 + 0);
        goto _lbl_L0012A620;
    }
    r_s0 = (long)(0 + 0);
    if (r_s0 != r_s2)
        goto _lbl_L0012A5B8;
    r_a0 = (long)(0 + (0x1));
    r_v0 = (long)func_12DB80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != r_s0) {
        r_s0 = (long)(0 + 0);
        goto _lbl_L0012A5B8;
    }
    r_s0 = (long)(0 + 0);
_lbl_L0012A620:
    r_v0 = (long)(r_s0 + 0);
_lbl_L0012A624:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A648 */
void *func_0012A648(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)(0 + (0x1));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A650 */
void *func_0012A650(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s3 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    r_s1 = (long)(0 + (0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    goto _lbl_L0012A680;
_lbl_L0012A678:
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012A680:
    r_s2 = (long)(0 + (0x1));
    r_v0 = (long)func_12DA38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s2)
        goto _lbl_L0012A6F4;
    r_a0 = (long)(0 + (0x1));
    r_v0 = (long)func_12DB80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x2));
    if (r_s0 != r_v0) {
        r_a0 = (long)&D_4ED300;
        goto _lbl_L0012A6F4;
    }
    r_a0 = (long)&D_4ED300;
    r_a0 = (long)&D_4ED300;
    r_v0 = (long)func_00129B10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    if (r_v1 == r_s2) {
        r_v0 = (long)((long)r_v1 < (long)(0x2) ? 1 : 0);
        goto _lbl_L0012A6F4;
    }
    r_v0 = (long)((long)r_v1 < (long)(0x2) ? 1 : 0);
    if (r_v0 == 0)
        goto _lbl_L0012A6D4;
    if (r_v1 == 0) {
        r_s1 = (long)(0 + 0);
        goto _lbl_L0012A6E4;
    }
    r_s1 = (long)(0 + 0);
    r_s3 = (long)(0 + 0);
    goto _lbl_L0012A6F4;
_lbl_L0012A6D4:
    if (r_v1 != r_s0) {
        r_v0 = (long)(0 + (0x3));
        goto _lbl_L0012A6EC;
    }
    r_v0 = (long)(0 + (0x3));
    r_s1 = (long)(0 + 0);
    goto _lbl_L0012A6F0;
_lbl_L0012A6E4:
    r_s3 = (long)(0 + (0x1));
    goto _lbl_L0012A6F4;
_lbl_L0012A6EC:
    r_s1 = (long)(0 + 0);
_lbl_L0012A6F0:
    r_s3 = (long)(0 + 0);
_lbl_L0012A6F4:
    if (r_s1 != 0)
        goto _lbl_L0012A678;
    if (r_s3 != 0) {
        r_v0 = (long)(r_s3 + 0);
        goto _lbl_L0012A714;
    }
    r_v0 = (long)(r_s3 + 0);
    r_a0 = (long)&D_48FBA0;
    r_a0 = (long)&D_48FBA0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s3 + 0);
_lbl_L0012A714:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A730 */
void *func_0012A730(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)(0 + 0);
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A738 */
void *func_0012A738(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)(0 + (0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)&D_48FBB8;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_s1 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s0 = (long)(0 + 0);
    goto _lbl_L0012A778;
_lbl_L0012A770:
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012A778:
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012A458((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s4) {
        r_a0 = (long)&D_48FBB8;
        goto _lbl_L0012A7A4;
    }
    r_a0 = (long)&D_48FBB8;
    r_s0 = (long)(r_s0 + (0x1));
    r_a1 = (long)(r_s0 + 0);
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)((long)r_s0 < (long)(0x5) ? 1 : 0);
    if (r_v1 != 0)
        goto _lbl_L0012A770;
    r_s1 = (long)(0 + (0x5));
_lbl_L0012A7A4:
    r_v0 = (long)func_0012A510((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x3));
    r_v1 = (long)(r_v0 + 0);
    if (r_v1 != r_a0) {
        r_v0 = (long)((long)r_s1 < (long)(0x5) ? 1 : 0);
        goto _lbl_L0012A7D4;
    }
    r_v0 = (long)((long)r_s1 < (long)(0x5) ? 1 : 0);
    r_s1 = (long)(r_s1 + (0x1));
    r_v0 = (long)((long)r_s1 < (long)(0x5) ? 1 : 0);
    if (r_v0 != 0) {
        r_s0 = (long)(0 + 0);
        goto _lbl_L0012A778;
    }
    r_s0 = (long)(0 + 0);
    if (r_v1 == r_a0) {
        r_v1 = (long)(0 + (0x2));
        goto _lbl_L0012A7E0;
    }
    r_v1 = (long)(0 + (0x2));
_lbl_L0012A7D4:
    if (r_v0 != 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x50));
        }
        goto _lbl_L0012A7E4;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    r_v1 = (long)(0 + (0x2));
_lbl_L0012A7E0:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
_lbl_L0012A7E4:
    r_v0 = (long)(r_v1 + 0);
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A808 */
void *func_0012A808(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s5;
    }
    r_s4 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s5 = (long)(0 + (0x5));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_ra;
    }
    r_s2 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s3 = (long)(0 + 0);
    r_v0 = (long)func_0012A0E0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (-0x1));
    if (r_v0 == 0)
        r_s5 = r_v1;
    r_v0 = (long)func_0012A0F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        r_s2 = r_s5;
    r_s5 = (long)(r_s2 + 0);
    goto _lbl_L0012A878;
_lbl_L0012A858:
    if (r_s0 == r_v0) {
        r_v0 = (long)(r_s0 + 0);
        goto _lbl_L0012A988;
    }
    r_v0 = (long)(r_s0 + 0);
    if (r_s2 == 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x60));
        }
        goto _lbl_L0012A98C;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x60));
    }
    r_v0 = (long)func_0012AAA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((long)0 < (long)r_s2 ? 1 : 0);
    r_s2 = (long)(r_s2 - r_v0);
_lbl_L0012A878:
    r_v0 = (long)func_12DA38((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x1));
    if (r_v0 == r_v1) {
        r_s0 = (long)(0 + (0x5));
        goto _lbl_L0012A978;
    }
    r_s0 = (long)(0 + (0x5));
    r_v0 = (long)func_0012A648((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        goto _lbl_L0012A8BC;
    r_v0 = (long)func_0012A650((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) {
        r_s0 = (long)(0 + (0x6));
        goto _lbl_L0012A978;
    }
    r_s0 = (long)(0 + (0x6));
    r_v0 = (long)func_0012A730((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        r_s0 = (long)(0 + (0x7));
        goto _lbl_L0012A978;
    }
    r_s0 = (long)(0 + (0x7));
_lbl_L0012A8BC:
    r_v0 = (long)func_0012A578((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if (r_s0 == 0) {
        if (r_s1) {
            r_s0 = *(int *)((char *)r_s1 + (0x14));
        }
        goto _lbl_L0012A914;
    }
    if (r_s1) {
        r_s0 = *(int *)((char *)r_s1 + (0x14));
    }
    r_s3 = (long)(r_s3 + (0x1));
    r_v0 = (long)((long)r_s3 < (long)(0x1F) ? 1 : 0);
    if (r_v0 != 0) {
        r_s2 = (long)(r_s5 + 0);
        goto _lbl_L0012A978;
    }
    r_s2 = (long)(r_s5 + 0);
    r_v0 = (long)func_12DB48((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x1));
    if (r_v0 != r_v1) {
        r_a0 = (long)(0 + 0);
        goto _lbl_L0012A978;
    }
    r_a0 = (long)(0 + 0);
    r_s3 = (long)(0 + 0);
    r_v0 = (long)func_001294E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_12DAC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + 0);
    r_v0 = (long)func_001294E8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_s5 + 0);
    goto _lbl_L0012A978;
_lbl_L0012A914:
    r_v0 = (long)(0 + (0x2));
    if (r_s0 != r_v0)
        goto _lbl_L0012A960;
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012A180((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x1));
    if (r_v1 == r_v0) {
        if (r_s1) {
            r_v0 = *(int *)((char *)r_s1 + (0x4C));
        }
        goto _lbl_L0012A948;
    }
    if (r_s1) {
        r_v0 = *(int *)((char *)r_s1 + (0x4C));
    }
    if (r_v1 == r_s0) {
        r_s0 = (long)(0 + (0x9));
        goto _lbl_L0012A960;
    }
    r_s0 = (long)(0 + (0x9));
    r_s2 = (long)(0 + 0);
    goto _lbl_L0012A97C;
_lbl_L0012A948:
    if (r_s1) {
        r_v1 = *(int *)((char *)r_s1 + (0x48));
    }
    r_v0 = (long)(r_v0 + (0x7FF));
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x28)) = (int)0;
    }
    r_v0 = (long)((unsigned long)r_v0 >> (11));
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x20)) = (int)r_v1;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x24)) = (int)r_v0;
    }
_lbl_L0012A960:
    if ((long)r_s4 < 0) {
        r_s0 = (long)(0 + (0x1));
        goto _lbl_L0012A978;
    }
    r_s0 = (long)(0 + (0x1));
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x40)) = (int)r_s4;
    }
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012A738((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
_lbl_L0012A978:
    r_v0 = (long)(0 + (0x1));
_lbl_L0012A97C:
    if (r_s0 != r_v0) {
        r_v0 = (long)(0 + (0x4));
        goto _lbl_L0012A858;
    }
    r_v0 = (long)(0 + (0x4));
    r_v0 = (long)(r_s0 + 0);
_lbl_L0012A988:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x60));
    }
_lbl_L0012A98C:
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012A9B0 */
void *func_0012A9B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)(0 + (0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_s0) {
        r_v1 = *(int *)((char *)r_s0 + (0x14));
    }
    if (r_s0) {
        r_s4 = *(int *)((char *)r_s0 + (0x30));
    }
    if (r_s0) {
        r_s2 = *(int *)((char *)r_s0 + (0x38));
    }
    if (r_v1 == r_v0) {
        if (r_s0) {
            r_s3 = *(int *)((char *)r_s0 + (0x3C));
        }
        goto _lbl_L0012AA1C;
    }
    if (r_s0) {
        r_s3 = *(int *)((char *)r_s0 + (0x3C));
    }
    r_v0 = (long)(0 + (0x2));
    if (r_v1 == r_v0) {
        r_a0 = (long)&D_48FBE0;
        goto _lbl_L0012AA14;
    }
    r_a0 = (long)&D_48FBE0;
    r_a0 = (long)&D_48FBE0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a1 = (long)(0 + (0x70C));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012AA14:
    if (r_s0) {
        r_s1 = *(int *)((char *)r_s0 + (0x2C));
    }
    goto _lbl_L0012AA44;
_lbl_L0012AA1C:
    r_v0 = (long)func_0012A0D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 != 0) {
        r_s1 = (long)(r_v0 + 0);
        goto _lbl_L0012AA30;
    }
    r_s1 = (long)(r_v0 + 0);
    if (r_s0) {
        r_s2 = *(int *)((char *)r_s0 + (0x24));
    }
_lbl_L0012AA30:
    r_v0 = (long)func_0012CBE8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        r_v1 = *(int *)((char *)r_s0 + (0x20));
    }
    r_v1 = (long)(r_v1 - r_v0);
    r_s3 = (long)(r_s3 + r_v1);
_lbl_L0012AA44:
    r_a0 = (long)(r_s1 + 0);
    r_a2 = (long)((unsigned long)r_s2 << (11));
    r_a3 = (long)((unsigned long)r_s3 << (11));
    r_a1 = (long)(r_s4 + 0);
    r_v0 = (long)func_00128D10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        r_v1 = *(int *)((char *)r_s0 + (0x6C));
    }
    r_a1 = (long)(r_v0 + 0);
    r_a0 = (long)(0 + (0x1));
    r_v0 = (long)(0 + (0x9));
    if (r_v1) {
        *(int *)((char *)r_v1 + (0xC)) = (int)r_s4;
    }
    if (r_a1 != 0)
        r_v0 = r_a0;
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x14)) = (int)0;
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x8)) = (int)r_a0;
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x10)) = (int)r_a1;
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AAA0 */
void *func_0012AAA0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    r_s0 = (long)&D_4ED300;
    r_s0 = (long)&D_4ED300;
    if (r_s0) {
        r_a0 = *(int *)((char *)r_s0 + (0x34));
    }
    r_v0 = (long)func_134440((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        r_a0 = *(int *)((char *)r_s0 + (0x38));
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return func_0012CCD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_0012AAD8 */
void *func_0012AAD8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    r_v0 = (long)&D_4ED300;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(0 + (-0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s1 = (long)&D_4ED300;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_s1) {
        r_s0 = *(int *)((char *)r_s1 + (0x34));
    }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_104D80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s0) {
        if (r_s1) {
            r_s2 = *(int *)((char *)r_s1 + (0x38));
        }
        goto _lbl_L0012AB0C;
    }
    if (r_s1) {
        r_s2 = *(int *)((char *)r_s1 + (0x38));
    }
_lbl_L0012AB0C:
    r_v0 = (long)(r_s2 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AB28 */
void *func_0012AB28(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_v0 = (long)func_0012AAD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if ((long)r_v0 < 0)
        goto _lbl_L0012AB48;
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_134480((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012AB48:
    r_v0 = (long)func_0012BC40((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    /* unhandled: sync */
    /* unhandled: ei */
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_v0 = (long)(0 + (0x1));
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AB68 */
void *func_0012AB68(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    r_v0 = (long)&D_4ED334;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)&D_4ED334;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)&D_48F500;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)&D_4E2C68;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_s1 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_a0 = (long)(0 + (0x1));
_lbl_L0012ABA0:
    r_a1 = (long)(0 + 0);
    r_a2 = (long)(0 + 0);
    r_v0 = (long)func_134210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if ((long)r_s0 >= 0) {
        r_v0 = (long)((unsigned long)r_s1 << (2));
        goto _lbl_L0012ABCC;
    }
    r_v0 = (long)((unsigned long)r_s1 << (2));
    r_a0 = (long)&D_48F500;
    r_a1 = (long)(0 + (0x782));
    r_a2 = (long)&D_4E2C68;
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)r_s1 << (2));
_lbl_L0012ABCC:
    r_v0 = (long)(r_v0 + r_s4);
    r_s1 = (long)(r_s1 + (0x1));
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x0)) = (int)r_s0;
    }
_lbl_L0012ABD8:
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_104D70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == r_s0) {
        r_v0 = (long)((unsigned long)r_s1 < (unsigned long)(0x2) ? 1 : 0);
        goto _lbl_L0012ABD8;
    }
    r_v0 = (long)((unsigned long)r_s1 < (unsigned long)(0x2) ? 1 : 0);
    if (r_v0 != 0) {
        r_a0 = (long)(0 + (0x1));
        goto _lbl_L0012ABA0;
    }
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)&func_0012AB28;
    r_a0 = (long)(0 + (0x3));
    r_a1 = (long)&func_0012AB28;
    r_a2 = (long)(0 + (-0x1));
    r_v0 = (long)func_104A00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if ((long)r_s0 >= 0) {
        r_a0 = (long)&D_48F500;
        goto _lbl_L0012AC24;
    }
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C68;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C68;
    r_a1 = (long)(0 + (0x78E));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012AC24:
    r_v0 = (long)func_134140((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)&D_4ED300;
    r_v0 = (long)(r_v0 + (-0x1));
    r_v1 = (long)&D_4ED300;
    r_a0 = (long)(0 + (0x3));
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x40)) = (int)r_s0;
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x3C)) = (int)r_v0;
    }
    r_v0 = (long)func_1057B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(~(0 | r_s0));
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_v0 ? 1 : 0);
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AC78 */
void *func_0012AC78(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    r_v0 = (long)&D_4ED300;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s0 = (long)&D_4ED300;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_s0) {
        r_a1 = *(int *)((char *)r_s0 + (0x40));
    }
    if ((long)r_a1 < 0) {
        r_s0 = (long)(r_s0 + (0x34));
        goto _lbl_L0012ACB4;
    }
    r_s0 = (long)(r_s0 + (0x34));
    r_a0 = (long)(0 + (0x3));
    r_v0 = (long)func_00134DE8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (-0x1));
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x40)) = (int)r_v1;
    }
    r_s0 = (long)(r_s0 + (0x34));
_lbl_L0012ACB4:
    r_s1 = (long)(0 + 0);
    r_s2 = (long)(0 + (-0x1));
_lbl_L0012ACC0:
    if (r_s0) {
        r_v0 = *(int *)((char *)r_s0 + (0x0));
    }
    r_s1 = (long)(r_s1 + (0x1));
    if ((long)r_v0 < 0) {
        r_a0 = (long)(r_v0 + 0);
        goto _lbl_L0012ACD8;
    }
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_1344C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012ACD8:
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x0)) = (int)r_s2;
    }
    r_v0 = (long)((unsigned long)r_s1 < (unsigned long)(0x2) ? 1 : 0);
    if (r_v0 != 0) {
        r_s0 = (long)(r_s0 + (0x4));
        goto _lbl_L0012ACC0;
    }
    r_s0 = (long)(r_s0 + (0x4));
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AD00 */
void *func_0012AD00(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_a0 = (long)(0 + (0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_a1 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    r_a2 = (long)(0 + 0);
    r_v0 = (long)func_134210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if ((long)r_s0 >= 0) {
        r_v0 = (long)((0x4F0000 >> 16) << 16);
        goto _lbl_L0012AD44;
    }
    r_v0 = (long)((0x4F0000 >> 16) << 16);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FBF8;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FBF8;
    r_a1 = (long)(0 + (0x7F8));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((0x4F0000 >> 16) << 16);
_lbl_L0012AD44:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (-0x2CBC)) = (int)r_s0;
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AD58 */
void *func_0012AD58(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_v0 = (long)&D_4ED300;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    r_s0 = (long)&D_4ED300;
    if (r_s0) {
        r_a0 = *(int *)((char *)r_s0 + (0x44));
    }
    if ((long)r_a0 < 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x10));
        }
        goto _lbl_L0012AD8C;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    r_v0 = (long)func_1344C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (-0x1));
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x44)) = (int)r_v1;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
_lbl_L0012AD8C:
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AD98 */
void *func_0012AD98(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)((0x4F0000 >> 16) << 16);
    r_sp = (long)(r_sp + (-0x10));
    if (r_v0) {
        r_a0 = *(int *)((char *)r_v0 + (-0x2CAC));
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_v0 = (long)func_134500((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4ED370;
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_v0 = (long)&D_4ED370;
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012ADC8 */
void *func_0012ADC8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a0 = (long)&D_4ED370;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + (0x70));
    r_a0 = (long)&D_4ED370;
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((0x4F0000 >> 16) << 16);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    if (r_v0) {
        r_a0 = *(int *)((char *)r_v0 + (-0x2CAC));
    }
    r_sp = (long)(r_sp + (0x10));
    return func_0012CCD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_0012ADF8 */
void *func_0012ADF8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x20));
    r_a0 = (long)&D_4ED370;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_a1 = (long)(0 + (0x70));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    r_a0 = (long)&D_4ED370;
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x1));
    r_a1 = (long)(0 + (0x1));
    r_a2 = (long)(0 + 0);
    r_v0 = (long)func_134210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if ((long)r_s0 >= 0) {
        r_v0 = (long)((0x4F0000 >> 16) << 16);
        goto _lbl_L0012AE4C;
    }
    r_v0 = (long)((0x4F0000 >> 16) << 16);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FBF8;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FBF8;
    r_a1 = (long)(0 + (0x81D));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((0x4F0000 >> 16) << 16);
_lbl_L0012AE4C:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (-0x2CAC)) = (int)r_s0;
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AE60 */
void *func_0012AE60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)((0x4F0000 >> 16) << 16);
    if (r_v0) {
        r_a0 = *(int *)((char *)r_v0 + (-0x2CAC));
    }
    return func_0012CCD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_0012AE70 */
void *func_0012AE70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)&D_4ED3E0;
    r_v0 = (long)&D_4ED3E0;
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012AE80 */
void *func_0012AE80(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_s6;
    (void)r_s7;
    r_sp = (long)(r_sp + (-0x90));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x70)) = (long)r_s7;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_s6;
    }
    r_s7 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s5;
    }
    r_s6 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s5 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x80)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_s6) {
        r_s1 = *(int *)((char *)r_s6 + (0x0));
    }
    if (r_s7) {
        r_s4 = *(int *)((char *)r_s7 + (0x0));
    }
    r_v0 = (long)func_12D038((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_12CF58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s3 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012A040((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        goto _lbl_L0012AF20;
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_12D4D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0)
        goto _lbl_L0012AF20;
    if (r_s2 != 0) {
        r_s1 = (long)(0 + (0x2));
        goto _lbl_L0012AF10;
    }
    r_s1 = (long)(0 + (0x2));
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_12CEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(0 + (0x1));
    if (r_v0 != r_v1) {
        r_a0 = (long)&D_48FC08;
        goto _lbl_L0012AF18;
    }
    r_a0 = (long)&D_48FC08;
    r_s1 = (long)(0 + (0x2));
_lbl_L0012AF10:
    r_s4 = (long)(0 + (0x1));
    goto _lbl_L0012AF20;
_lbl_L0012AF18:
    r_a0 = (long)&D_48FC08;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012AF20:
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_12CEA0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
    r_a0 = (long)(0 + (0x1));
    if (r_v1 == r_a0) {
        r_v0 = (long)((long)r_v1 < (long)(0x2) ? 1 : 0);
        goto _lbl_L0012AF98;
    }
    r_v0 = (long)((long)r_v1 < (long)(0x2) ? 1 : 0);
    if (r_v0 == 0) {
        r_v0 = (long)(0 + (0x2));
        goto _lbl_L0012AF50;
    }
    r_v0 = (long)(0 + (0x2));
    if (r_v1 == 0)
        goto _lbl_L0012AF60;
    r_s5 = (long)(0 + (0x1));
    goto _lbl_L0012B0C0;
_lbl_L0012AF50:
    if (r_v1 == r_v0)
        goto _lbl_L0012B034;
    r_s5 = (long)(0 + (0x1));
    goto _lbl_L0012B0C0;
_lbl_L0012AF60:
    if (r_s1 != r_a0) {
        r_v0 = (long)(0 + (0x2));
        goto _lbl_L0012AF70;
    }
    r_v0 = (long)(0 + (0x2));
    if (r_s3 == 0) {
        r_a0 = (long)&D_48FC28;
        goto _lbl_L0012AF84;
    }
    r_a0 = (long)&D_48FC28;
_lbl_L0012AF70:
    if (r_s1 != r_v0) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    if (r_s2 != 0) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    r_a0 = (long)&D_48FC28;
_lbl_L0012AF84:
    r_s5 = (long)(0 + (0x1));
    r_a0 = (long)&D_48FC28;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    goto _lbl_L0012B0C4;
_lbl_L0012AF98:
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012CC58((void *)r_a0);
    if (r_v0 == 0) {
        r_v0 = (long)(0 + (0x1));
        goto _lbl_L0012AFDC;
    }
    r_v0 = (long)(0 + (0x1));
    if (r_s2 != 0) {
        r_a0 = (long)&D_48FC50;
        goto _lbl_L0012AFCC;
    }
    r_a0 = (long)&D_48FC50;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C70;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C70;
    r_a1 = (long)(0 + (0x899));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_48FC50;
_lbl_L0012AFCC:
    r_s1 = (long)(0 + (0x2));
    r_a0 = (long)&D_48FC50;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x1));
_lbl_L0012AFDC:
    if (r_s1 != r_v0) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    if (r_s2 == 0) {
        r_a0 = (long)&D_48FC78;
        goto _lbl_L0012B008;
    }
    r_a0 = (long)&D_48FC78;
    if (r_s3 == 0) {
        r_s1 = (long)(0 + (0x2));
        goto _lbl_L0012B00C;
    }
    r_s1 = (long)(0 + (0x2));
    r_v0 = (long)func_0012A0D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    r_a0 = (long)&D_48FC78;
_lbl_L0012B008:
    r_s1 = (long)(0 + (0x2));
_lbl_L0012B00C:
    r_a0 = (long)&D_48FC78;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4 != 0) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    r_a0 = (long)&D_48FCB0;
    r_s4 = (long)(0 + (0x1));
    r_a0 = (long)&D_48FCB0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    goto _lbl_L0012B0C4;
_lbl_L0012B034:
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012CC78((void *)r_a0);
    if (r_v0 == 0) {
        r_v0 = (long)(0 + (0x2));
        goto _lbl_L0012B078;
    }
    r_v0 = (long)(0 + (0x2));
    if (r_s3 != 0) {
        r_a0 = (long)&D_48FCC8;
        goto _lbl_L0012B068;
    }
    r_a0 = (long)&D_48FCC8;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C78;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C78;
    r_a1 = (long)(0 + (0x8AA));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_48FCC8;
_lbl_L0012B068:
    r_s1 = (long)(0 + (0x1));
    r_a0 = (long)&D_48FCC8;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x2));
_lbl_L0012B078:
    if (r_s1 != r_v0) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    if (r_s2 != 0) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    r_a0 = (long)&D_48FCF0;
    r_s1 = (long)(0 + (0x1));
    r_a0 = (long)&D_48FCF0;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s4 != r_s1) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    r_v0 = (long)func_0012A0D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        if (r_s6) {
            *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
        }
        goto _lbl_L0012B0C4;
    }
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
    r_a0 = (long)&D_48FD30;
    r_s4 = (long)(0 + 0);
    r_a0 = (long)&D_48FD30;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012B0C0:
    if (r_s6) {
        *(int *)((char *)r_s6 + (0x0)) = (int)r_s1;
    }
_lbl_L0012B0C4:
    r_v0 = (long)(r_s5 + 0);
    if (r_s7) {
        *(int *)((char *)r_s7 + (0x0)) = (int)r_s4;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x80));
    }
    if (r_sp) {
        r_s7 = *(long *)((char *)r_sp + (0x70));
    }
    if (r_sp) {
        r_s6 = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B0F8 */
void *func_0012B0F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_s3 = (long)(r_sp + (0x4));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s1;
    }
    if (r_a0) {
        r_s1 = *(int *)((char *)r_a0 + (0x0));
    }
    if (r_a0) {
        r_s2 = *(int *)((char *)r_a0 + (0x4));
    }
    if (r_s1) {
        r_v0 = *(int *)((char *)r_s1 + (0x14));
    }
    if (r_s1) {
        r_v1 = *(int *)((char *)r_s1 + (0x18));
    }
    if (r_sp) {
        *(int *)((char *)r_sp + (0x0)) = (int)r_v0;
    }
    if (r_sp) {
        *(int *)((char *)r_sp + (0x4)) = (int)r_v1;
    }
_lbl_L0012B12C:
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012AE80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        r_s0 = (long)(0 + (0x8));
        goto _lbl_L0012B200;
    }
    r_s0 = (long)(0 + (0x8));
    if (r_sp) {
        r_v1 = *(int *)((char *)r_sp + (0x0));
    }
    r_a0 = (long)(r_s2 + 0);
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x14)) = (int)r_v1;
    }
    if (r_sp) {
        r_v0 = *(int *)((char *)r_sp + (0x4));
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x18)) = (int)r_v0;
    }
    r_v0 = (long)func_12D038((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x2C)) = (int)r_v0;
    }
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_12CF58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s1 + (0x20));
    r_a2 = (long)(r_s1 + (0x24));
    r_v0 = (long)func_0012CBA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_v1 = *(int *)((char *)r_sp + (0x4));
    }
    if (r_v1 == 0) {
        r_v0 = (long)(0 + (0x1));
        goto _lbl_L0012B1C0;
    }
    r_v0 = (long)(0 + (0x1));
    if (r_v1 == r_v0) {
        r_a0 = (long)&D_48FD68;
        goto _lbl_L0012B1B0;
    }
    r_a0 = (long)&D_48FD68;
    r_a0 = (long)&D_48FD68;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a1 = (long)(0 + (0x8DB));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012B1B0:
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012A9B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_L0012B1CC;
_lbl_L0012B1C0:
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(0 + (0x1));
    r_v0 = (long)func_0012A808((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012B1CC:
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012A0F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 == 0) {
        if (r_sp) {
            r_v0 = *(int *)((char *)r_sp + (0x4));
        }
        goto _lbl_L0012B200;
    }
    if (r_sp) {
        r_v0 = *(int *)((char *)r_sp + (0x4));
    }
    if (r_v0 != 0) {
        r_v1 = (long)(0 + (0x1));
        goto _lbl_L0012B200;
    }
    r_v1 = (long)(0 + (0x1));
    if (r_s0 == r_v1) {
        r_v0 = (long)(0 + (0x4));
        goto _lbl_L0012B200;
    }
    r_v0 = (long)(0 + (0x4));
    if (r_s0 == r_v0) {
        r_v0 = (long)(0 + (0x2));
        goto _lbl_L0012B200;
    }
    r_v0 = (long)(0 + (0x2));
    if (r_sp) {
        *(int *)((char *)r_sp + (0x4)) = (int)r_v1;
    }
    if (r_sp) {
        *(int *)((char *)r_sp + (0x0)) = (int)r_v0;
    }
    goto _lbl_L0012B12C;
_lbl_L0012B200:
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x10));
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B220 */
void *func_0012B220(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_v0 = (long)func_12CF58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012CC78((void *)r_a0);
    if (r_v0 != 0) {
        r_v0 = (long)(0 + 0);
        goto _lbl_L0012B248;
    }
    r_v0 = (long)(0 + 0);
    r_v0 = (long)func_0012A0C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012B248:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B258 */
void *func_0012B258(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
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
    r_sp = (long)(r_sp + (-0xA0));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x80)) = (long)r_s8;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x70)) = (long)r_s7;
    }
    r_s8 = (long)(r_a3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_s6;
    }
    r_s7 = (long)(r_t3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s5;
    }
    r_s6 = (long)(r_t2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    r_s5 = (long)(r_t1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)(r_t0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s2 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x90)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_0012AE70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x30)) = (int)r_s2;
    }
    r_s1 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012B220((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(0 + (0x1));
    if (r_s0) {
        *(char *)((char *)r_s0 + (0x34)) = (char)0;
    }
    if (r_s0) {
        *(char *)((char *)r_s0 + (0x35)) = (char)r_a0;
    }
    r_v1 = (long)&D_4ED300;
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x28)) = (int)r_v0;
    }
    r_v1 = (long)&D_4ED300;
    r_a0 = (long)(r_s1 + 0);
    if (r_v1) {
        r_v0 = *(unsigned char *)((char *)r_v1 + (0x14));
    }
    if (r_s0) {
        *(char *)((char *)r_s0 + (0x36)) = (char)r_v0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x0)) = (int)r_s0;
    }
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (0xC));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x38)) = (int)r_s4;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x3C)) = (int)r_s5;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_s6;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)r_s7;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x4)) = (int)r_s3;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x8)) = (int)r_s8;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0;
    }
    r_v0 = (long)func_0012B0F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x90));
    }
    if (r_sp) {
        r_s8 = *(long *)((char *)r_sp + (0x80));
    }
    if (r_sp) {
        r_s7 = *(long *)((char *)r_sp + (0x70));
    }
    if (r_sp) {
        r_s6 = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B338 */
void *func_0012B338(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s1;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s0;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    r_s0 = (long)(r_a2 + 0);
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x30)) = (int)0;
    }
    r_a0 = (long)(r_s2 + 0);
    if (r_sp) {
        *(int *)((char *)r_sp + (0x0)) = (int)r_t0;
    }
    if (r_sp) {
        *(int *)((char *)r_sp + (0x4)) = (int)r_t1;
    }
    r_v0 = (long)func_0012B220((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x28)) = (int)r_v0;
    }
    r_v0 = (long)((0x4F0000 >> 16) << 16);
    if (r_v0) {
        r_v1 = *(int *)((char *)r_v0 + (-0x2CF4));
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x3C)) = (int)r_s0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x1C)) = (int)r_v1;
    }
    if (r_s2 == 0) {
        if (r_s1) {
            *(int *)((char *)r_s1 + (0x38)) = (int)0;
        }
        goto _lbl_L0012B3D0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x38)) = (int)0;
    }
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_sp + 0);
    r_a2 = (long)(r_sp | (0x4));
    r_v0 = (long)func_0012AE80((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        r_s2 = (long)(0 + (0x8));
        goto _lbl_L0012B450;
    }
    r_s2 = (long)(0 + (0x8));
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_12D038((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x2C)) = (int)r_v0;
    }
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_12CF58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_a1 = (long)(r_s1 + (0x20));
    r_a2 = (long)(r_s1 + (0x24));
    r_v0 = (long)func_0012CBA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_v0 = *(int *)((char *)r_sp + (0x0));
    }
    goto _lbl_L0012B3E8;
_lbl_L0012B3D0:
    r_v0 = (long)(0 + (0x1));
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x20)) = (int)0;
    }
    if (r_sp) {
        *(int *)((char *)r_sp + (0x0)) = (int)r_v0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x2C)) = (int)0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x28)) = (int)0;
    }
    if (r_sp) {
        r_v0 = *(int *)((char *)r_sp + (0x0));
    }
_lbl_L0012B3E8:
    if (r_sp) {
        r_v1 = *(int *)((char *)r_sp + (0x4));
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x14)) = (int)r_v0;
    }
    if (r_v1 == 0) {
        if (r_s1) {
            *(int *)((char *)r_s1 + (0x18)) = (int)r_v1;
        }
        goto _lbl_L0012B440;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x18)) = (int)r_v1;
    }
    r_v0 = (long)(0 + (0x1));
    if (r_v1 == r_v0) {
        r_a0 = (long)&D_48FD80;
        goto _lbl_L0012B424;
    }
    r_a0 = (long)&D_48FD80;
    r_a0 = (long)&D_48FD80;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a1 = (long)(0 + (0x95B));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012B424:
    if (r_s1) {
        r_s0 = *(int *)((char *)r_s1 + (0x6C));
    }
    r_s2 = (long)(0 + (0x1));
    r_a0 = (long)(r_s1 + 0);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x8)) = (int)r_s2;
    }
    r_v0 = (long)func_0012A288((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)r_v0;
    }
    goto _lbl_L0012B450;
_lbl_L0012B440:
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(0 + (0x4));
    r_v0 = (long)func_0012A808((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
_lbl_L0012B450:
    r_v0 = (long)(r_s2 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x10));
    }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B470 */
void *func_0012B470(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x20));
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_a1 = (long)(r_t0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x20)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x28)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x2C)) = (int)0;
    }
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CF4));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_a2;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x30)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x38)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x3C)) = (int)0;
    }
    if (r_a3 == 0) {
        if (r_s0) {
            *(int *)((char *)r_s0 + (0x18)) = (int)r_a3;
        }
        goto _lbl_L0012B4F0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)r_a3;
    }
    r_v0 = (long)(0 + (0x1));
    if (r_a3 == r_v0) {
        r_a0 = (long)&D_48FD98;
        goto _lbl_L0012B4E0;
    }
    r_a0 = (long)&D_48FD98;
    r_a0 = (long)&D_48FD98;
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C58;
    r_a1 = (long)(0 + (0x98A));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012B4E0:
    if (r_s0) {
        r_v0 = *(int *)((char *)r_s0 + (0x6C));
    }
    r_v1 = (long)(0 + (0x1));
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x8)) = (int)r_v1;
    }
    goto _lbl_L0012B4FC;
_lbl_L0012B4F0:
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012A808((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v1 = (long)(r_v0 + 0);
_lbl_L0012B4FC:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x10));
    }
    r_v0 = (long)(r_v1 + 0);
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x20));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B510 */
void *func_0012B510(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_t0 = (long)(0 + (0x5));
    r_v0 = (long)func_0012B470((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B530 */
void *func_0012B530(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_t0 = (long)(0 + (0x6));
    r_v0 = (long)func_0012B470((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B550 */
void *func_0012B550(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_t0 = (long)(0 + (0x7));
    r_v0 = (long)func_0012B470((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B570 */
void *func_0012B570(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s1 = (long)(r_a2 + 0);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x28)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x30)) = (int)0;
    }
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CF4));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x38)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)r_v0;
    }
    if (r_a1 == 0) {
        if (r_s0) {
            *(int *)((char *)r_s0 + (0x3C)) = (int)0;
        }
        goto _lbl_L0012B620;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x3C)) = (int)0;
    }
    r_v0 = (long)(0 + (0x2));
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x2C)) = (int)r_a1;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_v0;
    }
    r_a1 = (long)(0 + (-0x1));
    r_v0 = (long)func_0012A808((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x1));
    if (r_a1 != r_v0) {
        if (r_s0) {
            r_v1 = *(int *)((char *)r_s0 + (0x6C));
        }
        goto _lbl_L0012B628;
    }
    if (r_s0) {
        r_v1 = *(int *)((char *)r_s0 + (0x6C));
    }
    if (r_s0) {
        r_v0 = *(long *)((char *)r_s0 + (0x4F));
    }
    if (r_s0) {
        r_v0 = *(long *)((char *)r_s0 + (0x48));
    }
    if (r_s0) {
        r_v1 = *(long *)((char *)r_s0 + (0x57));
    }
    if (r_s0) {
        r_v1 = *(long *)((char *)r_s0 + (0x50));
    }
    if (r_s0) {
        r_a0 = *(long *)((char *)r_s0 + (0x5F));
    }
    if (r_s0) {
        r_a0 = *(long *)((char *)r_s0 + (0x58));
    }
    if (r_s0) {
        r_a2 = *(long *)((char *)r_s0 + (0x67));
    }
    if (r_s0) {
        r_a2 = *(long *)((char *)r_s0 + (0x60));
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x7)) = (long)r_v0;
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x0)) = (long)r_v0;
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0xF)) = (long)r_v1;
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x8)) = (long)r_v1;
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x17)) = (long)r_a0;
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x10)) = (long)r_a0;
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x1F)) = (long)r_a2;
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x18)) = (long)r_a2;
    }
    if (r_s0) {
        r_v0 = *(int *)((char *)r_s0 + (0x68));
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x20)) = (int)r_v0;
    }
    if (r_s0) {
        r_v1 = *(int *)((char *)r_s0 + (0x6C));
    }
    goto _lbl_L0012B628;
_lbl_L0012B620:
    r_a1 = (long)(0 + (0x9));
    if (r_s0) {
        r_v1 = *(int *)((char *)r_s0 + (0x6C));
    }
_lbl_L0012B628:
    r_v0 = (long)(r_a1 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (0xC)) = (int)r_s1;
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x8)) = (int)0;
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B648 */
void *func_0012B648(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
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
    r_sp = (long)(r_sp + (-0xE0));
    if (r_sp) {
        *(long *)((char *)r_sp + (0xC0)) = (long)r_s8;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0xB0)) = (long)r_s7;
    }
    r_s8 = (long)&D_4E2C80;
    if (r_sp) {
        *(long *)((char *)r_sp + (0xA0)) = (long)r_s6;
    }
    r_s7 = (long)&jtbl_48FE10;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x90)) = (long)r_s5;
    }
    r_s6 = (long)&D_48FDB0;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x80)) = (long)r_s4;
    }
    r_s5 = (long)&D_48FDC8;
    if (r_sp) {
        *(long *)((char *)r_sp + (0xD0)) = (long)r_ra;
    }
    r_s4 = (long)&D_4ED300;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x70)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s0;
    }
_lbl_L0012B688:
    r_v0 = (long)func_0012BC10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_134500((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AD98((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)&D_4ED300;
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x5C)) = (int)0;
    }
    r_v0 = (long)func_0012BE70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    if (r_s1 != 0) {
        if (r_s1) {
            r_a1 = *(int *)((char *)r_s1 + (0x0));
        }
        goto _lbl_L0012B6D4;
    }
    if (r_s1) {
        r_a1 = *(int *)((char *)r_s1 + (0x0));
    }
    r_v0 = (long)&D_48F500;
    r_a1 = (long)(0 + (0xA0B));
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_4E2C80;
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        r_a1 = *(int *)((char *)r_s1 + (0x0));
    }
_lbl_L0012B6D4:
    if (r_s1) {
        r_s2 = *(int *)((char *)r_s1 + (0x14));
    }
    r_v1 = (long)(r_a1 + (-0x1));
    if (r_s1) {
        r_s3 = *(int *)((char *)r_s1 + (0x28));
    }
    if (r_s1) {
        r_t0 = *(int *)((char *)r_s1 + (0x20));
    }
    r_v0 = (long)((unsigned long)r_v1 < (unsigned long)(0x6) ? 1 : 0);
    if (r_s1) {
        r_a3 = *(int *)((char *)r_s1 + (0x24));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x6C)) = (int)r_s2;
    }
    if (r_v0 == 0) {
        if (r_s2) {
            *(int *)((char *)r_s2 + (0x4)) = (int)r_a1;
        }
        goto _lbl_L0012B710;
    }
    if (r_s2) {
        *(int *)((char *)r_s2 + (0x4)) = (int)r_a1;
    }
    r_v0 = (long)((unsigned long)r_v1 << (2));
    r_v1 = (long)&jtbl_48FE10;
    r_v0 = (long)(r_v0 + r_v1);
    if (r_v0) {
        r_a0 = *(int *)((char *)r_v0 + (0x0));
    }
    return (void *)r_v0;
_lbl_L0012B710:
    r_a0 = (long)&D_48FDB0;
    r_s0 = (long)(0 + (0x1));
    r_v0 = (long)func_118de0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_L0012B7D4;
    r_t2 = (long)(r_t0 + 0);
    r_t3 = (long)(r_a3 + 0);
    if (r_s1) {
        r_a1 = *(int *)((char *)r_s1 + (0xC));
    }
    r_a0 = (long)(r_s0 + 0);
    if (r_s1) {
        r_a2 = *(int *)((char *)r_s1 + (0x10));
    }
    r_a3 = (long)(r_s2 + 0);
    if (r_s1) {
        r_t0 = *(int *)((char *)r_s1 + (0x18));
    }
    if (r_s1) {
        r_t1 = *(int *)((char *)r_s1 + (0x1C));
    }
    r_v0 = (long)func_0012B258((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    goto _lbl_L0012B7D4;
    r_t1 = (long)(r_a3 + 0);
    if (r_s1) {
        r_a1 = *(int *)((char *)r_s1 + (0xC));
    }
    if (r_s1) {
        r_a2 = *(int *)((char *)r_s1 + (0x1C));
    }
    r_a0 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012B338((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    goto _lbl_L0012B7D4;
    r_a0 = (long)(r_s0 + 0);
    r_a2 = (long)(r_t0 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012B510((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    goto _lbl_L0012B7D4;
    r_a0 = (long)(r_s0 + 0);
    r_a2 = (long)(r_t0 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012B530((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    goto _lbl_L0012B7D4;
    r_a0 = (long)(r_s0 + 0);
    r_a2 = (long)(r_t0 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012B550((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    goto _lbl_L0012B7D4;
    r_t1 = (long)(r_a3 + 0);
    if (r_s1) {
        r_a1 = *(int *)((char *)r_s1 + (0xC));
    }
    if (r_s1) {
        r_a2 = *(int *)((char *)r_s1 + (0x10));
    }
    r_a0 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012B570((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
_lbl_L0012B7D4:
    r_v0 = (long)func_0012ADC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a2 = (long)(r_s0 + 0);
    r_a0 = (long)(r_sp + 0);
    r_a1 = (long)(0 + (0x8));
    r_v0 = (long)&D_48FDC8;
    if (r_v0) {
        r_v1 = *(long *)((char *)r_v0 + (0x7));
    }
    if (r_v0) {
        r_v1 = *(long *)((char *)r_v0 + (0x0));
    }
    if (r_v0) {
        r_t0 = *(long *)((char *)r_v0 + (0xF));
    }
    if (r_v0) {
        r_t0 = *(long *)((char *)r_v0 + (0x8));
    }
    if (r_v0) {
        r_t1 = *(long *)((char *)r_v0 + (0x17));
    }
    if (r_v0) {
        r_t1 = *(long *)((char *)r_v0 + (0x10));
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x7)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0xF)) = (long)r_t0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x8)) = (long)r_t0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x17)) = (long)r_t1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_t1;
    }
    if (r_v0) {
        r_v1 = *(long *)((char *)r_v0 + (0x1F));
    }
    if (r_v0) {
        r_v1 = *(long *)((char *)r_v0 + (0x18));
    }
    if (r_v0) {
        r_t0 = *(long *)((char *)r_v0 + (0x27));
    }
    if (r_v0) {
        r_t0 = *(long *)((char *)r_v0 + (0x20));
    }
    if (r_v0) {
        r_t1 = *(long *)((char *)r_v0 + (0x2F));
    }
    if (r_v0) {
        r_t1 = *(long *)((char *)r_v0 + (0x28));
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x1F)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x18)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x27)) = (long)r_t0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_t0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x2F)) = (long)r_t1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x28)) = (long)r_t1;
    }
    if (r_v0) {
        r_v1 = *(long *)((char *)r_v0 + (0x37));
    }
    if (r_v0) {
        r_v1 = *(long *)((char *)r_v0 + (0x30));
    }
    if (r_v0) {
        r_t0 = *(long *)((char *)r_v0 + (0x3F));
    }
    if (r_v0) {
        r_t0 = *(long *)((char *)r_v0 + (0x38));
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x37)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_v1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x3F)) = (long)r_t0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x38)) = (long)r_t0;
    }
    r_a3 = (long)(0 + (0x8));
    r_v0 = (long)func_00129588((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        r_a0 = *(int *)((char *)r_s1 + (0x2C));
    }
    r_a1 = (long)(r_s2 + 0);
    if (r_s2) {
        *(int *)((char *)r_s2 + (0x0)) = (int)r_v0;
    }
    r_v0 = (long)func_00129560((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012BE30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s3 == 0) {
        r_v0 = (long)&D_4ED300;
        goto _lbl_L0012B688;
    }
    r_v0 = (long)&D_4ED300;
    if (r_v0) {
        r_a0 = *(int *)((char *)r_v0 + (0x4C));
    }
    r_v0 = (long)func_134440((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    goto _lbl_L0012B688;
    r_sp = (long)(r_sp + (-0x40));
    r_a1 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_a2 = (long)(0 + 0);
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_a0 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_v0 = (long)func_134210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if ((long)r_s0 >= 0) {
        r_v0 = (long)&D_4ED300;
        goto _lbl_L0012B8F8;
    }
    r_v0 = (long)&D_4ED300;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FBF8;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FBF8;
    r_a1 = (long)(0 + (0xA66));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)&D_4ED300;
_lbl_L0012B8F8:
    r_a0 = (long)(0 + 0);
    r_s1 = (long)&D_4ED300;
    r_a1 = (long)(0 + 0);
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x48)) = (int)r_s0;
    }
    r_a2 = (long)(0 + 0);
    r_v0 = (long)func_134210((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if ((long)r_s0 >= 0) {
        r_a0 = (long)&func_0012B648;
        goto _lbl_L0012B938;
    }
    r_a0 = (long)&func_0012B648;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FBF8;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FBF8;
    r_a1 = (long)(0 + (0xA6B));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)&func_0012B648;
_lbl_L0012B938:
    r_a1 = (long)&D_4ED400;
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x4C)) = (int)r_s0;
    }
    r_a0 = (long)&func_0012B648;
    r_a1 = (long)&D_4ED400;
    r_a3 = (long)(r_s2 + 0);
    r_a2 = (long)(0 + (0x4000));
    r_t0 = (long)(0 + 0);
    r_t1 = (long)(0 + 0);
    r_v0 = (long)func_134378((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    /* unhandled: bgezl */
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x50)) = (int)r_s0;
    }
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FE28;
    r_a0 = (long)&D_48F500;
    r_a2 = (long)&D_48FE28;
    r_a1 = (long)(0 + (0xA70));
    r_v0 = (long)func_114320((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x50)) = (int)r_s0;
    }
_lbl_L0012B984:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B9A0 */
void *func_0012B9A0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s0 = (long)&D_4ED300;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s0 = (long)&D_4ED300;
    r_s1 = (long)(0 + (-0x1));
    if (r_s0) {
        r_a0 = *(int *)((char *)r_s0 + (0x50));
    }
    r_v0 = (long)func_1341B8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        r_a0 = *(int *)((char *)r_s0 + (0x48));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x50)) = (int)r_s1;
    }
    r_v0 = (long)func_1344C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        r_a0 = *(int *)((char *)r_s0 + (0x4C));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x48)) = (int)r_s1;
    }
    r_v0 = (long)func_1344C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x4C)) = (int)r_s1;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012B9F8 */
void *func_0012B9F8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s0 = (long)&D_4ED300;
    r_s0 = (long)&D_4ED300;
    if (r_s1) {
        r_a1 = *(int *)((char *)r_s1 + (0x0));
    }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_00129620((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        r_v0 = *(int *)((char *)r_s1 + (0x4));
    }
    if (r_s1) {
        r_v1 = *(int *)((char *)r_s1 + (0x14));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)r_v0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x20)) = (int)r_v1;
    }
    if (r_s1) {
        r_v0 = *(int *)((char *)r_s1 + (0x8));
    }
    if (r_s1) {
        r_v1 = *(int *)((char *)r_s1 + (0x18));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_v0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x24)) = (int)r_v1;
    }
    if (r_s1) {
        r_v0 = *(int *)((char *)r_s1 + (0xC));
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x10)) = (int)r_v0;
    }
    if (r_s1) {
        r_v1 = *(int *)((char *)r_s1 + (0x10));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)r_v1;
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BA68 */
void *func_0012BA68(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    r_v0 = (long)&D_4ED300;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s1 = (long)&D_4ED300;
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_a1 = (long)(0 + (0x6C));
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(0 + (0x1));
    r_a0 = (long)(r_s0 + 0);
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x8)) = (int)r_v0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x4)) = (int)0;
    }
    r_v0 = (long)func_0012B9F8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(0 + (-0x1));
    r_a0 = (long)(0 + 0);
    r_v1 = (long)(r_s1 + (0x34));
_lbl_L0012BAB8:
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x0)) = (int)r_a1;
    }
    r_a0 = (long)(r_a0 + (0x1));
    r_v1 = (long)(r_v1 + (0x4));
    r_v0 = (long)((unsigned long)r_a0 < (unsigned long)(0x2) ? 1 : 0);
    if (r_v0 != 0)
        goto _lbl_L0012BAB8;
    r_v0 = (long)(0 + (-0x1));
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x3C)) = (int)r_v0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x4C)) = (int)r_v0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x40)) = (int)r_v0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x44)) = (int)r_v0;
    }
    if (r_s1) {
        *(int *)((char *)r_s1 + (0x48)) = (int)r_v0;
    }
    r_v0 = (long)func_0012ADF8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AD00((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AB68((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return func_0012B648((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_0012BB20 */
void *func_0012BB20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_v0 = (long)func_0012B9A0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AC78((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012AD58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return func_0012AE60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_0012BB50 */
void *func_0012BB50(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)(0 + (-0x1));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    if (r_a1 != r_v0) {
        r_s0 = (long)(r_a0 + 0);
        goto _lbl_L0012BB7C;
    }
    r_s0 = (long)(r_a0 + 0);
    r_a1 = (long)(r_sp + 0);
    r_v0 = (long)func_0012A108((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_v1 = *(int *)((char *)r_sp + (0x0));
    }
    r_a1 = (long)(0 + 0);
    if (r_v0 != 0)
        r_a1 = r_v1;
_lbl_L0012BB7C:
    r_v1 = (long)&D_4ED300;
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    r_v1 = (long)&D_4ED300;
    r_v0 = (long)(r_a1 + 0);
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x28)) = (int)r_s0;
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x2C)) = (int)r_a1;
    }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BBA0 */
void *func_0012BBA0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_12CF58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_12D038((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s2 != 0) {
        r_s1 = (long)(r_v0 + 0);
        goto _lbl_L0012BBE0;
    }
    r_s1 = (long)(r_v0 + 0);
    if (r_s1 != 0)
        r_s0 = r_v0;
    r_s1 = (long)(r_s0 + 0);
    r_v0 = (long)(0 + (-0x1));
    goto _lbl_L0012BBE8;
_lbl_L0012BBE0:
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012CB60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012BBE8:
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012BB50((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BC10 */
void *func_0012BC10(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CB8));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BC20 */
void *func_0012BC20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2CB4));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BC30 */
void *func_0012BC30(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    r_v0 = (long)(0 + (0x16));
    if (r_v1) {
        *(int *)((char *)r_v1 + (-0x2C98)) = (int)r_v0;
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BC40 */
void *func_0012BC40(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)&D_4ED300;
    r_v0 = (long)&D_4ED300;
    if (r_v0) {
        r_v1 = *(int *)((char *)r_v0 + (0x68));
    }
    if (r_v1 == 0) {
        r_v1 = (long)(r_v1 + (-0x1));
        goto _lbl_L0012BC58;
    }
    r_v1 = (long)(r_v1 + (-0x1));
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x68)) = (int)r_v1;
    }
_lbl_L0012BC58:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BC60 */
void *func_0012BC60(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F0000 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (-0x2C98));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BC70 */
void *func_0012BC70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    /* unhandled: mtlo1 */
    if ((long)r_a1 <= 0) {
        r_v1 = (long)(0 + (0x1));
        goto _lbl_L0012BC9C;
    }
    r_v1 = (long)(0 + (0x1));
    r_a2 = (long)(0 + (0xA));
_lbl_L0012BC80:
    r_v0 = (long)(r_a0 & (0xF));
    r_a1 = (long)(r_a1 + (-0x1));
    /* unhandled: madd1 */
    r_a0 = (long)((long)r_a0 >> (4));
    /* unhandled: mult */
    if ((long)r_a1 > 0)
        goto _lbl_L0012BC80;
_lbl_L0012BC9C:
    /* unhandled: mflo1 */
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BCA8 */
void *func_0012BCA8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    r_s0 = (long)(r_a1 + 0);
    r_a1 = (long)(0 + (0x2));
    if (r_s0) {
        r_v0 = *(unsigned char *)((char *)r_s0 + (0x0));
    }
    if (r_s1) {
        *(char *)((char *)r_s1 + (0x0)) = (char)r_v0;
    }
    if (r_s0) {
        r_a0 = *(unsigned char *)((char *)r_s0 + (0x1));
    }
    r_v0 = (long)func_0012BC70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(char *)((char *)r_s1 + (0x1)) = (char)r_v0;
    }
    r_a1 = (long)(0 + (0x2));
    if (r_s0) {
        r_a0 = *(unsigned char *)((char *)r_s0 + (0x2));
    }
    r_v0 = (long)func_0012BC70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(char *)((char *)r_s1 + (0x2)) = (char)r_v0;
    }
    r_a1 = (long)(0 + (0x2));
    if (r_s0) {
        r_a0 = *(unsigned char *)((char *)r_s0 + (0x3));
    }
    r_v0 = (long)func_0012BC70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(char *)((char *)r_s1 + (0x3)) = (char)r_v0;
    }
    r_a1 = (long)(0 + (0x2));
    if (r_s0) {
        r_a0 = *(unsigned char *)((char *)r_s0 + (0x5));
    }
    r_v0 = (long)func_0012BC70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(char *)((char *)r_s1 + (0x5)) = (char)r_v0;
    }
    r_a1 = (long)(0 + (0x2));
    if (r_s0) {
        r_a0 = *(unsigned char *)((char *)r_s0 + (0x6));
    }
    r_v0 = (long)func_0012BC70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(char *)((char *)r_s1 + (0x6)) = (char)r_v0;
    }
    r_a1 = (long)(0 + (0x2));
    if (r_s0) {
        r_a0 = *(unsigned char *)((char *)r_s0 + (0x7));
    }
    r_v0 = (long)func_0012BC70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1) {
        *(char *)((char *)r_s1 + (0x7)) = (char)r_v0;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BD40 */
void *func_0012BD40(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s0;
    }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_a0 = (long)(r_sp + 0);
    r_v0 = (long)func_0012BD88((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_sp + 0);
    r_v0 = (long)func_0012BCA8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)(r_s1 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x10));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BD88 */
void *func_0012BD88(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    r_sp = (long)(r_sp + (-0x50));
    r_v0 = (long)&D_4ED360;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)&D_4ED360;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s2 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_v0 = (long)func_0012BC60((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0)
        goto _lbl_L0012BDC8;
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_10FD58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s2 = (long)(r_v0 + 0);
_lbl_L0012BDC8:
    if (r_s2 == 0) {
        r_v0 = (long)(0 + (0x1));
        goto _lbl_L0012BDD8;
    }
    r_v0 = (long)(0 + (0x1));
    if (r_s2 == r_v0)
        goto _lbl_L0012BDE4;
_lbl_L0012BDD8:
    r_s1 = (long)(r_s0 + 0);
    r_s0 = (long)(r_s3 + 0);
    goto _lbl_L0012BDEC;
_lbl_L0012BDE4:
    r_s1 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012BC30((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012BDEC:
    if (r_s0) {
        r_v1 = *(long *)((char *)r_s0 + (0x7));
    }
    if (r_s0) {
        r_v1 = *(long *)((char *)r_s0 + (0x0));
    }
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x7)) = (long)r_v1;
    }
    r_v0 = (long)(r_s2 + 0);
    if (r_s1) {
        *(long *)((char *)r_s1 + (0x0)) = (long)r_v1;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BE20 */
void *func_0012BE20(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_a0 = (long)&D_4F1400;
    r_a1 = (long)(0 + (0x108));
    r_a0 = (long)&D_4F1400;
    return (void *)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_0012BE30 */
void *func_0012BE30(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    if (r_a0 == 0)
        goto _lbl_L0012BE68;
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x0));
    }
    if (r_v0 == 0)
        goto _lbl_L0012BE68;
    if (r_a0) {
        r_v1 = *(int *)((char *)r_a0 + (0x4));
    }
    if (r_v1 == 0) {
        if (r_a0) {
            r_v0 = *(int *)((char *)r_a0 + (0x8));
        }
        goto _lbl_L0012BE54;
    }
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x8));
    }
    if (r_v1) {
        *(int *)((char *)r_v1 + (0x8)) = (int)r_v0;
    }
_lbl_L0012BE54:
    if (r_v0 != 0) {
        if (r_v0) {
            *(int *)((char *)r_v0 + (0x4)) = (int)r_v1;
        }
        goto _lbl_L0012BE5C;
    }
    if (r_v0) {
        *(int *)((char *)r_v0 + (0x4)) = (int)r_v1;
    }
_lbl_L0012BE5C:
    if (r_a0) {
        *(int *)((char *)r_a0 + (0x8)) = (int)0;
    }
    if (r_a0) {
        *(int *)((char *)r_a0 + (0x0)) = (int)0;
    }
    if (r_a0) {
        *(int *)((char *)r_a0 + (0x4)) = (int)0;
    }
_lbl_L0012BE68:
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BE70 */
void *func_0012BE70(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)((0x4F1400 >> 16) << 16);
    r_a2 = (long)(0 + 0);
    if (r_v0) {
        r_v1 = *(int *)((char *)r_v0 + ((0x4F1400 & 0xFFFF)));
    }
    r_a0 = (long)&D_4F1400;
    if (r_v1 != 0) {
        r_a1 = (long)(0 + 0);
        goto _lbl_L0012BEA8;
    }
    r_a1 = (long)(0 + 0);
    r_a1 = (long)(r_a1 + (0x1));
_lbl_L0012BE90:
    r_v0 = (long)((long)r_a1 < (long)(0x4) ? 1 : 0);
    if (r_v0 == 0) {
        r_a0 = (long)(r_a0 + (0x38));
        goto _lbl_L0012BEB8;
    }
    r_a0 = (long)(r_a0 + (0x38));
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x0));
    }
    if (r_v0 == 0) {
        r_a1 = (long)(r_a1 + (0x1));
        goto _lbl_L0012BE90;
    }
    r_a1 = (long)(r_a1 + (0x1));
_lbl_L0012BEA8:
    if (r_a0) {
        r_v0 = *(int *)((char *)r_a0 + (0x4));
    }
    if (r_v0 != 0) {
        r_a1 = (long)(r_a1 + (0x1));
        goto _lbl_L0012BE90;
    }
    r_a1 = (long)(r_a1 + (0x1));
    r_a2 = (long)(r_a0 + 0);
_lbl_L0012BEB8:
    r_v0 = (long)(r_a2 + 0);
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BEC0 */
void *func_0012BEC0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    r_v0 = (long)&D_4F1400;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_a1 = (long)&D_4F1400;
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s1 = (long)(0 + (0x4));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    if (r_a0 == 0) {
        r_s0 = (long)(0 + 0);
        goto _lbl_L0012BF14;
    }
    r_s0 = (long)(0 + 0);
    r_v1 = (long)(r_a1 + 0);
    r_a2 = (long)(r_a1 + (0xE0));
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (0x0));
    }
_lbl_L0012BEF0:
    if (r_v0 == 0) {
        r_v1 = (long)(r_v1 + (0x38));
        goto _lbl_L0012BF08;
    }
    r_v1 = (long)(r_v1 + (0x38));
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (0x14));
    }
    if (r_v0 == r_a0) {
        r_v0 = (long)(r_s0 + 0);
        goto _lbl_L0012BFA4;
    }
    r_v0 = (long)(r_s0 + 0);
    r_v1 = (long)(r_v1 + (0x38));
_lbl_L0012BF08:
    r_v0 = (long)((long)r_v1 < (long)r_a2 ? 1 : 0);
    if (r_v0 != 0) {
        if (r_v1) {
            r_v0 = *(int *)((char *)r_v1 + (0x0));
        }
        goto _lbl_L0012BEF0;
    }
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + (0x0));
    }
_lbl_L0012BF14:
    if (r_a1) {
        r_v0 = *(int *)((char *)r_a1 + (0x0));
    }
    r_a0 = (long)(0 + 0);
    goto _lbl_L0012BF38;
_lbl_L0012BF20:
    r_a1 = (long)(0 + 0);
    goto _lbl_L0012BF98;
_lbl_L0012BF28:
    r_v0 = (long)((long)r_a0 < (long)(0x4) ? 1 : 0);
    if (r_v0 == 0) {
        r_a1 = (long)(r_a1 + (0x38));
        goto _lbl_L0012BF44;
    }
    r_a1 = (long)(r_a1 + (0x38));
    if (r_a1) {
        r_v0 = *(int *)((char *)r_a1 + (0x0));
    }
_lbl_L0012BF38:
    if (r_v0 != 0) {
        r_a0 = (long)(r_a0 + (0x1));
        goto _lbl_L0012BF28;
    }
    r_a0 = (long)(r_a0 + (0x1));
    r_s0 = (long)(r_a1 + 0);
_lbl_L0012BF44:
    if (r_s0 == 0) {
        r_v0 = (long)(r_s0 + 0);
        goto _lbl_L0012BFA4;
    }
    r_v0 = (long)(r_s0 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(0 + (0x38));
    r_v0 = (long)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)func_0012BE70((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a1 = (long)(r_v0 + 0);
    if (r_a1 == 0) {
        if (r_s0) {
            *(int *)((char *)r_s0 + (0x4)) = (int)r_a1;
        }
        goto _lbl_L0012BF9C;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x4)) = (int)r_a1;
    }
    if (r_a1) {
        r_v1 = *(int *)((char *)r_a1 + (0x8));
    }
    if (r_v1 == 0) {
        r_a0 = (long)(0 + 0);
        goto _lbl_L0012BF94;
    }
    r_a0 = (long)(0 + 0);
_lbl_L0012BF78:
    r_a0 = (long)(r_a0 + (0x1));
    r_v0 = (long)((long)r_s1 < (long)r_a0 ? 1 : 0);
    if (r_v0 != 0) {
        r_a1 = (long)(r_v1 + 0);
        goto _lbl_L0012BF20;
    }
    r_a1 = (long)(r_v1 + 0);
    if (r_a1) {
        r_v0 = *(int *)((char *)r_a1 + (0x8));
    }
    if (r_v0 != 0) {
        r_v1 = (long)(r_v0 + 0);
        goto _lbl_L0012BF78;
    }
    r_v1 = (long)(r_v0 + 0);
_lbl_L0012BF94:
    if (r_a1) {
        *(int *)((char *)r_a1 + (0x8)) = (int)r_s0;
    }
_lbl_L0012BF98:
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x4)) = (int)r_a1;
    }
_lbl_L0012BF9C:
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x8)) = (int)0;
    }
    r_v0 = (long)(r_s0 + 0);
_lbl_L0012BFA4:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BFB8 */
void *func_0012BFB8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v0 = (long)&D_4F1400;
    r_a2 = (long)(0 + 0);
    r_a1 = (long)&D_4F1400;
    r_a3 = (long)(r_a1 + (0xE0));
_lbl_L0012BFC8:
    if (r_a1) {
        r_a0 = *(int *)((char *)r_a1 + (0x0));
    }
    r_v1 = (long)(r_a2 + (0x1));
    r_a1 = (long)(r_a1 + (0x38));
    if (r_a0 != 0)
        r_a2 = r_v1;
    r_v0 = (long)((long)r_a1 < (long)r_a3 ? 1 : 0);
    if (r_v0 != 0)
        goto _lbl_L0012BFC8;
    r_v0 = (long)(r_a2 + 0);
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012BFF0 */
void *func_0012BFF0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    r_sp = (long)(r_sp + (-0x30));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s1 = (long)(r_a2 + 0);
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_ra;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x28)) = (int)r_s1;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x0)) = (int)r_a1;
    }
    r_v0 = (long)func_00129548((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x2C)) = (int)r_v0;
    }
    r_v0 = (long)func_0012BC10((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_134440((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s1 == 0) {
        if (r_sp) {
            r_ra = *(long *)((char *)r_sp + (0x20));
        }
        goto _lbl_L0012C04C;
    }
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    r_v0 = (long)func_0012BC20((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x20));
    }
    r_a0 = (long)(r_v0 + 0);
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return func_0012CCD8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012C04C:
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x30));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C060 */
void *func_0012C060(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_a1 = (long)(0 + (0x18));
    return (void *)func_001143C0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    return (void *)r_v0;
}

/* func_0012C068 */
void *func_0012C068(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_s8 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
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
    r_sp = (long)(r_sp + (-0xA0));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x80)) = (long)r_s8;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x70)) = (long)r_s7;
    }
    r_s8 = (long)(r_t2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_s6;
    }
    r_s7 = (long)(r_t1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s5;
    }
    r_s6 = (long)(r_t0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    r_s5 = (long)(r_a3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a2 + 0);
    if (r_sp) {
        r_s0 = *(int *)((char *)r_sp + (0xA0));
    }
    r_s1 = (long)(r_t3 + 0);
    if (r_s0 == 0) {
        if (r_sp) {
            *(long *)((char *)r_sp + (0x90)) = (long)r_ra;
        }
        goto _lbl_L0012C0F0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x90)) = (long)r_ra;
    }
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012C060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)r_s3;
    }
    r_a2 = (long)(r_s1 + 0);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x10)) = (int)r_s4;
    }
    r_a0 = (long)(r_s0 + 0);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_s2;
    }
    r_a1 = (long)(0 + (0x1));
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)r_s5;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)r_s6;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x20)) = (int)r_s7;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x24)) = (int)r_s8;
    }
    r_v0 = (long)func_0012BFF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012C0F0:
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x90));
    }
    if (r_sp) {
        r_s8 = *(long *)((char *)r_sp + (0x80));
    }
    if (r_sp) {
        r_s7 = *(long *)((char *)r_sp + (0x70));
    }
    if (r_sp) {
        r_s6 = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C128 */
void *func_0012C128(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_s7 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
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
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s0;
    }
    r_s1 = (long)(r_a0 + 0);
    r_s0 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x80)) = (long)r_s7;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x70)) = (long)r_s6;
    }
    r_s7 = (long)(r_t3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_s5;
    }
    r_s6 = (long)(r_t2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s4;
    }
    r_s5 = (long)(r_t1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s3;
    }
    r_s4 = (long)(r_t0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s2;
    }
    r_s3 = (long)(r_a3 + 0);
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x90)) = (long)r_ra;
    }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012BEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_a2 = (long)(r_s0 + 0);
    r_a3 = (long)(r_s3 + 0);
    r_t0 = (long)(r_s4 + 0);
    r_t1 = (long)(r_s5 + 0);
    r_t2 = (long)(r_s6 + 0);
    r_t3 = (long)(r_s7 + 0);
    if (r_sp) {
        *(int *)((char *)r_sp + (0x0)) = (int)r_v0;
    }
    r_v0 = (long)func_0012C068((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x90));
    }
    if (r_sp) {
        r_s7 = *(long *)((char *)r_sp + (0x80));
    }
    if (r_sp) {
        r_s6 = *(long *)((char *)r_sp + (0x70));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x10));
    }
    r_sp = (long)(r_sp + (0xA0));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C1D0 */
void *func_0012C1D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    r_s1 = (long)(r_a0 + 0);
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_t1 = (long)(r_s0 + 0);
    r_t2 = (long)(r_v0 + 0);
    r_a3 = (long)(0 + 0);
    r_t0 = (long)(0 + 0);
    r_t3 = (long)(0 + (0x1));
    r_v0 = (long)func_0012C128((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C240 */
void *func_0012C240(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x50));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_ra;
    }
    r_s1 = (long)(r_a0 + 0);
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s1 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_t1 = (long)(r_s0 + 0);
    r_t2 = (long)(r_v0 + 0);
    r_a3 = (long)(0 + 0);
    r_t0 = (long)(0 + 0);
    r_t3 = (long)(0 + 0);
    r_v0 = (long)func_0012C128((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x50));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C2B0 */
void *func_0012C2B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0, r_t3 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
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
    (void)r_t3;
    r_sp = (long)(r_sp + (-0x90));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s2;
    }
    r_s4 = (long)(r_a3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x70)) = (long)r_s6;
    }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_s5;
    }
    r_s6 = (long)(r_t0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s3;
    }
    r_s5 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s1;
    }
    r_s3 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s0;
    }
    r_a0 = (long)(r_s4 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x80)) = (long)r_ra;
    }
    r_s0 = (long)(0 + 0);
    r_v0 = (long)func_0012BEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    if (r_s1 == 0) {
        r_a1 = (long)(r_s2 + 0);
        goto _lbl_L0012C33C;
    }
    r_a1 = (long)(r_s2 + 0);
    r_s0 = (long)(r_s1 + (0x30));
    r_a0 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012CC98((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    if (r_sp) {
        *(int *)((char *)r_sp + (0x0)) = (int)r_s1;
    }
    r_a1 = (long)(r_s5 + 0);
    r_a2 = (long)(r_s4 + 0);
    r_t3 = (long)(r_s6 + 0);
    r_a3 = (long)(0 + 0);
    r_t0 = (long)(0 + 0);
    r_t1 = (long)(0 + (0x1));
    r_t2 = (long)(0 + 0);
    r_v0 = (long)func_0012C068((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
_lbl_L0012C33C:
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x80));
    }
    if (r_sp) {
        r_s6 = *(long *)((char *)r_sp + (0x70));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x10));
    }
    r_sp = (long)(r_sp + (0x90));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C368 */
void *func_0012C368(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_t0 = (long)(0 + 0);
    r_v0 = (long)func_0012C2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C388 */
void *func_0012C388(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_t0 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_t0;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_t0 = (long)(0 + (0x1));
    r_v0 = (long)func_0012C2B0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C3A8 */
void *func_0012C3A8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_s6 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
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
    r_sp = (long)(r_sp + (-0x80));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_s6;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s5;
    }
    r_s6 = (long)(r_t0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    r_s5 = (long)(r_a3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s3 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s1 = (long)(r_t1 + 0);
    r_s0 = (long)(r_t2 + 0);
    if (r_s0 == 0) {
        if (r_sp) {
            *(long *)((char *)r_sp + (0x70)) = (long)r_ra;
        }
        goto _lbl_L0012C420;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x70)) = (long)r_ra;
    }
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012C060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)r_s3;
    }
    r_a2 = (long)(r_s1 + 0);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_s2;
    }
    r_a0 = (long)(r_s0 + 0);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)r_s4;
    }
    r_a1 = (long)(0 + (0x2));
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x20)) = (int)r_s5;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x24)) = (int)r_s6;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x10)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)0;
    }
    r_v0 = (long)func_0012BFF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
_lbl_L0012C420:
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x70));
    }
    if (r_sp) {
        r_s6 = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x80));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C450 */
void *func_0012C450(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s2 = (long)(r_a0 + 0);
    r_s0 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s5;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    r_s5 = (long)(r_t0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)(r_a3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s3 = (long)(r_a2 + 0);
    r_s1 = (long)(r_t1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_ra;
    }
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012BEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s2 + 0);
    r_a1 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_a3 = (long)(r_s1 + 0);
    r_t0 = (long)(r_s4 + 0);
    r_t1 = (long)(r_s5 + 0);
    r_t2 = (long)(r_v0 + 0);
    r_v0 = (long)func_0012C3A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C4D8 */
void *func_0012C4D8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_t0 = (long)(r_s1 + 0);
    r_t1 = (long)(r_v0 + 0);
    r_a2 = (long)(0 + 0);
    r_a3 = (long)(0 + 0);
    r_v0 = (long)func_0012C450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C538 */
void *func_0012C538(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_t0 = 0, r_t1 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_t0;
    (void)r_t1;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s0 = (long)(r_a0 + 0);
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s2 + 0);
    r_t0 = (long)(r_s1 + 0);
    r_t1 = (long)(r_v0 + 0);
    r_a2 = (long)(0 + 0);
    r_a3 = (long)(0 + (0x1));
    r_v0 = (long)func_0012C450((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C598 */
void *func_0012C598(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0, r_s5 = 0, r_t0 = 0, r_t1 = 0, r_t2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    (void)r_s5;
    (void)r_t0;
    (void)r_t1;
    (void)r_t2;
    r_sp = (long)(r_sp + (-0x70));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s4 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_s5;
    }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s5 = (long)(r_a3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s3 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_a0 = (long)(r_s4 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x60)) = (long)r_ra;
    }
    r_s0 = (long)(0 + 0);
    r_v0 = (long)func_0012BEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    if (r_s1 == 0) {
        r_a1 = (long)(r_s2 + 0);
        goto _lbl_L0012C614;
    }
    r_a1 = (long)(r_s2 + 0);
    r_s0 = (long)(r_s1 + (0x30));
    r_a0 = (long)(r_s0 + 0);
    r_a2 = (long)(r_s3 + 0);
    r_v0 = (long)func_0012CC98((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(r_s4 + 0);
    r_t1 = (long)(r_s5 + 0);
    r_t2 = (long)(r_s1 + 0);
    r_a2 = (long)(0 + 0);
    r_a3 = (long)(0 + (0x1));
    r_t0 = (long)(0 + 0);
    r_v0 = (long)func_0012C3A8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
_lbl_L0012C614:
    r_v0 = (long)(r_s0 + 0);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x60));
    }
    if (r_sp) {
        r_s5 = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x70));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C640 */
void *func_0012C640(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + 0);
    r_a3 = (long)(0 + 0);
    r_v0 = (long)func_0012C598((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C668 */
void *func_0012C668(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    r_a2 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + 0);
    r_a3 = (long)(0 + (0x1));
    r_v0 = (long)func_0012C598((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C690 */
void *func_0012C690(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_0012C6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C6B0 */
void *func_0012C6B0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + (0x1));
    r_v0 = (long)func_0012C6D0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C6D0 */
void *func_0012C6D0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s2 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012BEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if (r_s0 == 0) {
        r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
        goto _lbl_L0012C73C;
    }
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012C060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_s1;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x10)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)0;
    }
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x20)) = (int)r_v0;
    }
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x24)) = (int)r_v0;
    }
    r_a2 = (long)(r_s2 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(0 + (0x3));
    r_v0 = (long)func_0012BFF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
_lbl_L0012C73C:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C758 */
void *func_0012C758(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_0012C798((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C778 */
void *func_0012C778(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + (0x1));
    r_v0 = (long)func_0012C798((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C798 */
void *func_0012C798(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s2 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012BEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if (r_s0 == 0) {
        r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
        goto _lbl_L0012C804;
    }
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012C060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_s1;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x10)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)0;
    }
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x20)) = (int)r_v0;
    }
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x24)) = (int)r_v0;
    }
    r_a2 = (long)(r_s2 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(0 + (0x4));
    r_v0 = (long)func_0012BFF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
_lbl_L0012C804:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C820 */
void *func_0012C820(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + 0);
    r_v0 = (long)func_0012C860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C840 */
void *func_0012C840(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a1 = (long)(0 + (0x1));
    r_v0 = (long)func_0012C860((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C860 */
void *func_0012C860(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    r_sp = (long)(r_sp + (-0x40));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    r_s1 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_ra;
    }
    r_s2 = (long)(r_a1 + 0);
    r_v0 = (long)func_0012BEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if (r_s0 == 0) {
        r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
        goto _lbl_L0012C8CC;
    }
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012C060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_s1;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x10)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)0;
    }
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x20)) = (int)r_v0;
    }
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x24)) = (int)r_v0;
    }
    r_a2 = (long)(r_s2 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(0 + (0x5));
    r_v0 = (long)func_0012BFF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
_lbl_L0012C8CC:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x40));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C8E8 */
void *func_0012C8E8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a3 = (long)(0 + 0);
    r_v0 = (long)func_0012C928((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C908 */
void *func_0012C908(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_a3 = (long)(0 + (0x1));
    r_v0 = (long)func_0012C928((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C928 */
void *func_0012C928(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    r_s2 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    r_s1 = (long)(r_a2 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_s4 = (long)(r_a3 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s3 = (long)(r_a1 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012BEC0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    if (r_s0 == 0) {
        r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
        goto _lbl_L0012C9A8;
    }
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
    r_a0 = (long)(r_s1 + 0);
    r_v0 = (long)func_0012C060((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0xC)) = (int)r_s2;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x10)) = (int)r_s3;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x14)) = (int)r_s1;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x18)) = (int)0;
    }
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x1C)) = (int)0;
    }
    r_v0 = (long)func_00129F58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x20)) = (int)r_v0;
    }
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_s0) {
        *(int *)((char *)r_s0 + (0x24)) = (int)r_v0;
    }
    r_a2 = (long)(r_s4 + 0);
    r_a0 = (long)(r_s0 + 0);
    r_a1 = (long)(0 + (0x6));
    r_v0 = (long)func_0012BFF0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_v0 = (long)((unsigned long)0 < (unsigned long)r_s0 ? 1 : 0);
_lbl_L0012C9A8:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012C9C8 */
void *func_0012C9C8(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    long r_s0 = 0, r_s1 = 0, r_s2 = 0, r_s3 = 0, r_s4 = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    (void)r_s0;
    (void)r_s1;
    (void)r_s2;
    (void)r_s3;
    (void)r_s4;
    r_sp = (long)(r_sp + (-0x60));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_s0;
    }
    r_s0 = (long)(r_a0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x20)) = (long)r_s2;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x10)) = (long)r_s1;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x50)) = (long)r_ra;
    }
    r_s1 = (long)(0 + 0);
    if (r_sp) {
        *(long *)((char *)r_sp + (0x40)) = (long)r_s4;
    }
    if (r_sp) {
        *(long *)((char *)r_sp + (0x30)) = (long)r_s3;
    }
    r_v0 = (long)func_12CF58((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_a0 = (long)(r_s0 + 0);
    r_s2 = (long)(r_v0 + 0);
    r_v0 = (long)func_12CFC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s0 = (long)(r_v0 + 0);
    r_v0 = (long)func_00129FD0((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_v0 != 0) {
        r_v0 = (long)(0 + 0);
        goto _lbl_L0012CA10;
    }
    r_v0 = (long)(0 + 0);
    r_v0 = (long)(0 + (0x1));
_lbl_L0012CA10:
    r_s3 = (long)(r_v0 + 0);
    r_s4 = (long)(0 + (0x1));
_lbl_L0012CA18:
    if (r_v0 == 0)
        goto _lbl_L0012CA30;
    if (r_v0 == r_s4)
        goto _lbl_L0012CA54;
    goto _lbl_L0012CA6C;
_lbl_L0012CA30:
    if (r_s0 == 0) {
        r_v0 = (long)(0 + (0x1));
        goto _lbl_L0012CA6C;
    }
    r_v0 = (long)(0 + (0x1));
    r_a0 = (long)(r_s0 + 0);
    r_v0 = (long)func_0012CC48((void *)r_a0);
    r_a0 = (long)(r_v0 + 0);
    r_v0 = (long)func_00128EC8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)(r_v0 + 0);
    r_v0 = (long)(0 + (0x1));
    goto _lbl_L0012CA6C;
_lbl_L0012CA54:
    if (r_s2 == 0) {
        r_v0 = (long)(0 + 0);
        goto _lbl_L0012CA6C;
    }
    r_v0 = (long)(0 + 0);
    r_a0 = (long)(r_s2 + 0);
    r_v0 = (long)func_0012CB90((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    r_s1 = (long)((unsigned long)r_v0 << (11));
    r_v0 = (long)(0 + 0);
_lbl_L0012CA6C:
    if (r_s1 != 0) {
        r_v0 = (long)(r_s1 + 0);
        goto _lbl_L0012CA80;
    }
    r_v0 = (long)(r_s1 + 0);
    if (r_v0 != r_s3)
        goto _lbl_L0012CA18;
    r_v0 = (long)(r_s1 + 0);
_lbl_L0012CA80:
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x50));
    }
    if (r_sp) {
        r_s4 = *(long *)((char *)r_sp + (0x40));
    }
    if (r_sp) {
        r_s3 = *(long *)((char *)r_sp + (0x30));
    }
    if (r_sp) {
        r_s2 = *(long *)((char *)r_sp + (0x20));
    }
    if (r_sp) {
        r_s1 = *(long *)((char *)r_sp + (0x10));
    }
    if (r_sp) {
        r_s0 = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x60));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012CAA0 */
void *func_0012CAA0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_sp = (long)(r_sp + (-0x10));
    if (r_sp) {
        *(long *)((char *)r_sp + (0x0)) = (long)r_ra;
    }
    r_v0 = (long)func_0012BFB8((void *)r_a0, (void *)r_a1, (void *)r_a2, (void *)r_a3);
    if (r_sp) {
        r_ra = *(long *)((char *)r_sp + (0x0));
    }
    r_sp = (long)(r_sp + (0x10));
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012CAC0 */
void *func_0012CAC0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F1508 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + ((0x4F1508 & 0xFFFF)));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012CAD0 */
void *func_0012CAD0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F150C >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + ((0x4F150C & 0xFFFF)));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012CAE0 */
void *func_0012CAE0(void *a0, void *a1, void *a2, void *a3) {
    long r_v0 = 0, r_v1 = 0;
    long r_a0 = (long)a0, r_a1 = (long)a1, r_a2 = (long)a2, r_a3 = (long)a3;
    long r_ra = 0, r_gp = 0;
    unsigned char stack_mem[256];
    long r_sp = (long)stack_mem + 128;
    (void)r_v0;
    (void)r_v1;
    (void)r_a0;
    (void)r_a1;
    (void)r_a2;
    (void)r_a3;
    (void)r_sp;
    (void)r_ra;
    (void)r_gp;
    r_v1 = (long)((0x4F1514 >> 16) << 16);
    if (r_v1) {
        r_v0 = *(int *)((char *)r_v1 + ((0x4F1514 & 0xFFFF)));
    }
    return (void *)r_v0;
    return (void *)r_v0;
}

/* func_0012CAF0 */
void *func_0012CAF0(void *a0, void *a1, void *a2, void *a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    return (void *)(long)*(int *)(0x4F1518);
}

/* func_0012CB00 */
void *func_0012CB00(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    return (void *)((unsigned long)a0 & 0x7);
}

/* func_0012CB08 */
void *func_0012CB08(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    return (void *)((unsigned long)a0 & 0x8000);
}

/* func_0012CB10 */
void *func_0012CB10(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    return (void *)((unsigned long)a0 & 0xFFFF7FFF);
}

/* func_0012CB20 */
void *func_0012CB20(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    if (a0 == NULL) {
        return NULL;
    }
    return (void *)(long)*(unsigned short *)a0;
}

/* func_0012CB38 */
void *func_0012CB38(void *a0, void *a1, void *a2, void *a3) {
    void *val = func_0012CB20(a0, a1, a2, a3);
    return func_0012CB10(val, a1, a2, a3);
}

/* func_0012CB60 */
void *func_0012CB60(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    if (a0 == NULL) {
        return NULL;
    }
    return (void *)(((unsigned long)*(long *)a0 >> 16) & 0xFFFFFF);
}

/* func_0012CB90 */
void *func_0012CB90(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    if (a0 == NULL) {
        return NULL;
    }
    return (void *)((unsigned long)*(long *)a0 >> 8);
}

/* func_0012CBA8 */
void *func_0012CBA8(void *a0, void *a1, void *a2, void *a3) {
    (void)a3;
    if (a0 != NULL) {
        if (a1 != NULL) {
            *(int *)a1 = (int)(((unsigned long)*(long *)a0 >> 16) & 0xFFFFFF);
        }
        if (a2 != NULL) {
            *(int *)a2 = (int)((unsigned long)*(long *)a0 >> 8);
        }
    }
    return (void *)(a0 != NULL ? 1L : 0L);
}

/* func_0012CBE8 */
void *func_0012CBE8(void *a0, void *a1, void *a2, void *a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    return (void *)(long)*(int *)(0x4F1510);
}

/* func_0012CBF8 */
int func_0012CBF8(const unsigned char *data) {
    int value = 0;
    /* Avoid null-pointer arithmetic while preserving target address calculation. */
    const unsigned char *payload = (const unsigned char *)((unsigned long long)data + 2);
    if (data) {
        value = payload[0] + ((unsigned int)payload[1] << 8);
    }
    return value;
}

/* func_0012CC20 */
void *func_0012CC20(void *a0, void *a1, void *a2, void *a3) {
    (void)a1; (void)a2; (void)a3;
    if (a0 == NULL) {
        return NULL;
    }
    return (void *)(long)(func_0011ACD0((char *)a0 + 4) + 5);
}

/* func_0012CC48 */
const unsigned char *func_0012CC48(const unsigned char *data) {
    return data ? data + 4 : 0;
}

/* func_0012CC58 */
int func_0012CC58(const char *data) {
    return data && data[0] == '0';
}

/* func_0012CC78 */
int func_0012CC78(const char *data) {
    return data && data[0] == '@';
}

/* func_0012CC98 */
void *func_0012CC98(void *a0, void *a1, void *a2, void *a3) {
    unsigned long res = 0x40;
    (void)a3;
    if (a0 != NULL) {
        *(short *)a0 = (short)res;
        res = 0x40 | (((unsigned long)a1 & 0xFFFFFF) << 16) | (((unsigned long)a2) << 8);
        *(long *)a0 = (long)res;
    }
    return (void *)res;
}

/* func_0012CCD8 */
void *func_0012CCD8(void *a0, void *a1, void *a2, void *a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    return func_001143C0(&D_4F1508, (void *)0x14);
}
