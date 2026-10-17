#ifndef RENDER_MANAGER_KEY_DISPATCH_H
#define RENDER_MANAGER_KEY_DISPATCH_H

struct SubObj28 {
    char pad_00[0x54];
    int field_54;
};

struct ActiveScreen {
    virtual void M00();
};

struct RenderManagerKeyDispatch {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0, M08() = 0, M09() = 0;
    virtual void M10() = 0, M11() = 0, M12() = 0, M13() = 0, M14() = 0;
    virtual void M15() = 0, M16() = 0, M17() = 0, M18() = 0, M19() = 0;
    virtual void M20() = 0, M21() = 0, M22() = 0, M23() = 0, M24() = 0;
    virtual void M25() = 0, M26() = 0, M27() = 0, M28() = 0, M29() = 0;
    virtual void M30() = 0, M31() = 0, M32() = 0, M33() = 0, M34() = 0;
    virtual void M35() = 0, M36() = 0, M37() = 0, M38() = 0, M39() = 0;
    virtual void M40() = 0, M41() = 0, M42() = 0, M43() = 0, M44() = 0;
    virtual void M45() = 0, M46() = 0, M47() = 0, M48() = 0, M49() = 0;
    virtual void M50() = 0, M51() = 0, M52() = 0, M53() = 0, M54() = 0;
    virtual void M55() = 0, M56() = 0, M57() = 0, M58() = 0;
    virtual int MethodF4(int a1, int a2, int a3, int a4, int a5); // offset 244 (0xF4, method 59)

    char pad_04[0x24];
    SubObj28 *field_28;
    int field_2C;
    int field_30;
    char pad_34[0x178];
    void *field_1AC;
};

extern int D_004E89CC;
extern int D_004E89D0;
extern int D_004E89D4;
extern int D_004E89D8;
extern int D_004E89DC;
extern const char D_00491A28[];
extern const char D_00491A38[];

extern "C" {
void func_00A80BB0();
ActiveScreen *func_1F26C0(void *arg);
void *func_1F2700(void *arg, const char *name);
void func_1908B0(void *arg, int val);
void func_18BFA0(void *arg, int val);
void func_1FB860(void *screen, int a1, const char *name, int a3, int a4, int a5, int a6);
void func_1F2900(void *arg, const char *name, int val);
short func_225590(int vkey);

int func_00186a30(RenderManagerKeyDispatch *self, int hwnd, int msg, int wParam, int lParam);
int func_00186c10();
}

#endif
