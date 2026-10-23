#include "hist_overlay.h"

/* Forward declarations */
void hist_func_01D98000(void *p);
void hist_func_01D98034(void *p);
void hist_func_01D98200(void *p, int a1, int a2, int a3);
void hist_func_01D984AC(void *p);
void hist_func_01D9879C(void *p, void *a1);
void hist_func_01D98D8C(void *p);
void hist_func_01D98DFC(void *p);
void hist_func_01D98EF8(void *p, int a1);
void hist_func_01D98F44(void *p, int a1);
void hist_func_01D99044(void *p, int a1);
void hist_func_01D992D4(void *p, int a1);
void hist_func_01D99414(void *p);
void hist_func_01D99480(void *p);

extern void func_002138D0(void *a);
extern void func_001AB8F0(void *a, int b);
extern void func_001AB9D0(void *a);
extern void func_001ACDF0(void *a);
extern void func_001AD940(void *a);
extern void func_001ADA70(void *a);
extern void func_001ADC00(void *a);
extern void func_001AD450(void *a);
extern void func_001AD270(void *a);
extern void func_0025D060(void *a);
extern void func_001F6750(void *a);
extern void func_001F6DB0(void *a);
extern void func_001F6DD0(void *a);
extern void func_001F6DE0(void *a);
extern void func_001F6DC0(void *a);
extern void func_002257C0(void *a);
extern void func_00215910(void *a);
extern void func_001F7250(void *a);
extern void func_001F8B70(void *a);
extern void func_001F8B80(void *a);
extern void func_001FC100(void *a);
extern void func_00217A10(void *a);
extern void func_00217900(void *a);
extern void func_002178C0(void *a);
extern void func_00211B70(void *a);
extern void func_00211B80(void *a);
extern void func_002104F0(void *a);
extern void func_00219D20(void *a);
extern void func_001F6EA0(void *a);
extern void func_00114378(void *a);
extern void func_00219580(void *a);
extern void func_00100850(void *a);
extern void func_00212F90(void *a);
extern void func_002130A0(void *a);
extern void func_00185E20(void *a);
extern void func_002177C0(void *a);
extern void func_0025F2B0(void *a);
extern void func_0025D6D0(void *a);
extern void func_00213FB0(void *a);
extern void func_001F86F0(void *a);
extern void func_00117CAC(void *a);
extern void func_00223080(void *a);
extern void func_001F6E00(void *a);
extern void func_0025DE30(void *a);
extern void func_002230C0(void *a);
extern void func_00215950(void *a);
extern void func_00100670(void *a);
extern void func_001886B0(void *a);
extern void func_001F8140(void *a);
extern void func_001FBF30(void *a);
extern void func_00188680(void *a);
extern void func_00219CD0(void *a);
extern void func_00219BA0(void *a);
extern void func_002134F0(void *a);
extern void func_00256800(void *a);
extern void func_001F2900(void *a);
extern void func_001F2CB0(void *a);
extern void func_001FBD30(void *a);
extern void func_00213B40(void *a);
extern void func_00216460(void *a);
extern void func_00213FD0(void *a);
extern void func_00213AE0(void *a);

/* Function 1: hist_func_01D98000 (Constructor / setup) */
void hist_func_01D98000(void *p) {
    func_002138D0(p);
    *(void **)p = (void *)0x004E26C0;
}

/* Function 2: hist_func_01D98034 (Initialization / setup controls) */
void hist_func_01D98034(void *p) {
    typedef void (*Method)(void *, ...);
    void *obj;
    Method *vtable;

    obj = *(void **)((char *)p + 64);
    if (obj != NULL) {
        vtable = *(Method **)obj;
        vtable[17](obj, (char *)p + 36);
    }
    vtable = *(Method **)p;
    vtable[12](p);
    func_001AB8F0(*(void **)((char *)p + 32), 1);
    func_001AB9D0((char *)p + 32);
}

/* Function 3: hist_func_01D98200 (Coordinate and scroll layout calculations) */
void hist_func_01D98200(void *p, int a1, int a2, int a3) {
    func_001ACDF0(p);
    func_001AD940((char *)p + 4);
    func_001ADA70((char *)p + 8);
    func_001ADC00((char *)p + 12);
    func_001AD450(p);
    func_001AD270(p);
    func_001ACDF0(p);
    func_001AD940((char *)p + 4);
    func_001ADA70((char *)p + 8);
    func_001ADC00((char *)p + 12);
    func_001AD940((char *)p + 4);
}

/* Function 4: hist_func_01D984AC (UI element refresh / rendering helper) */
void hist_func_01D984AC(void *p) {
    typedef void (*Method)(void *, ...);
    Method *vtable = *(Method **)p;
    func_0025D060(p);
    func_001F6750(p);
    func_001F6DB0(p);
    func_001F6DD0(p);
    func_001F6DE0(p);
    func_001F6DC0(p);
    func_002257C0(p);
    func_0025D060(p);
    func_001F6750(p);
    func_001F6DB0(p);
    func_001F6DD0(p);
    func_001F6DE0(p);
    func_001F6DC0(p);
    func_002257C0(p);
    vtable[15](p);
}

/* Function 5: hist_func_01D9879C (Main event and dialog action handler) */
void hist_func_01D9879C(void *p, void *a1) {
    typedef void (*Method)(void *, ...);
    Method *vtable = *(Method **)p;

    func_00215910(p);
    func_001F7250(p);
    func_001F8B70(p);
    func_001F8B80(p);

    vtable[12](p, a1);
    vtable[14](p, a1);

    func_001FC100(p);
    func_00217A10(p);
    func_00217900(p);
    func_002178C0(p);
    func_00211B70(p);
    func_00211B80(p);
    func_002104F0(p);
    func_00219D20(p);
    func_001F6EA0(p);
    func_00114378(p);
    func_00219580(p);
    func_00100850(p);
    func_00212F90(p);
    func_002130A0(p);
    func_00185E20(p);
    func_00185E20(p);
    func_00185E20(p);
    func_00185E20(p);
    func_002177C0(p);
    func_0025F2B0(p);
    func_0025D6D0(p);
    func_00213FB0(p);
    func_00213FB0(p);
    func_001F86F0(p);
    func_001F6750(p);
}

/* Function 6: hist_func_01D98D8C (Destructor helper) */
void hist_func_01D98D8C(void *p) {
    *(void **)p = (void *)0x004E26C0;
    func_00117CAC(p);
    func_00223080(p);
}

/* Function 7: hist_func_01D98DFC (Resource teardown and release) */
void hist_func_01D98DFC(void *p) {
    int i;
    for (i = 0; i < 8; i++) {
        func_001F6E00((char *)p + i * 4);
    }
    func_0025DE30(p);
    func_00117CAC(p);
    func_002230C0(p);
    func_00215950(p);
    func_00100670(p);
}

/* Function 8: hist_func_01D98EF8 (Sound and effect trigger) */
void hist_func_01D98EF8(void *p, int a1) {
    func_001886B0(p);
    func_001F8140(p);
}

/* Function 9: hist_func_01D98F44 (List navigation handler) */
void hist_func_01D98F44(void *p, int a1) {
    typedef void (*Method)(void *, ...);
    Method *vtable = *(Method **)p;

    vtable[10](p);
    func_001F6750(p);
    vtable[11](p);
    func_001F6750(p);
    vtable[12](p);
    func_001F6750(p);
    func_001FBF30(p);
}

/* Function 10: hist_func_01D99044 (Page selection and display update) */
void hist_func_01D99044(void *p, int a1) {
    typedef void (*Method)(void *, ...);
    Method *vtable = *(Method **)p;

    func_00188680(p);
    func_00219CD0(p);
    vtable[8](p);
    vtable[9](p);
    vtable[10](p);
    vtable[11](p);
    func_00219BA0(p);
    func_002134F0(p);
    func_002134F0(p);
    vtable[12](p);
    vtable[13](p);
    vtable[14](p);
    vtable[15](p);
    vtable[16](p);
    vtable[17](p);
    func_00188680(p);
    func_00100850(p);
    func_00256800(p);
    func_001F2900(p);
    func_001F2CB0(p);
    func_001FBD30(p);
}

/* Function 11: hist_func_01D992D4 (Text format and string display) */
void hist_func_01D992D4(void *p, int a1) {
    func_00100850(p);
    func_00213B40(p);
    func_00216460(p);
    func_00213FB0(p);
    func_00213FD0(p);
}

/* Function 12: hist_func_01D99414 (History close and dialog exit) */
void hist_func_01D99414(void *p) {
    func_00213AE0(p);
    func_00100670(p);
}

/* Function 13: hist_func_01D99480 (Jump table and dispatch router) */
void hist_func_01D99480(void *p) {
    /* Router dispatcher */
}

/* HIST_CD.BIN .rodata section: Historical Encyclopedia Text and Index Tables (179,264 bytes) */
const unsigned int hist_data[HIST_DATA_WORD_COUNT] = {
#include "hist_data.inc"
};
