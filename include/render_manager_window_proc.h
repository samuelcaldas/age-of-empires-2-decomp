#ifndef RENDER_MANAGER_WINDOW_PROC_H
#define RENDER_MANAGER_WINDOW_PROC_H

struct SubObj6C {
    char pad_00[0x58];
    int field_58;
};

struct ActiveScreen {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0, M08() = 0, M09() = 0;
    virtual void M10() = 0, M11() = 0, M12() = 0, M13() = 0, M14() = 0;
    virtual void M15() = 0, M16() = 0, M17() = 0;
    virtual int Method50(int a1, int a2, int a3, int a4); // offset 80 (0x50, method 18)
    virtual void M19() = 0, M20() = 0, M21() = 0, M22() = 0, M23() = 0;
    virtual void M24() = 0, M25() = 0, M26() = 0, M27() = 0, M28() = 0;
    virtual void M29() = 0, M30() = 0, M31() = 0, M32() = 0, M33() = 0;
    virtual void M34() = 0, M35() = 0, M36() = 0, M37() = 0, M38() = 0;
    virtual void M39() = 0, M40() = 0, M41() = 0, M42() = 0, M43() = 0;
    virtual void M44() = 0, M45() = 0, M46() = 0, M47() = 0, M48() = 0;
    virtual void M49() = 0, M50_() = 0, M51() = 0, M52() = 0, M53() = 0;
    virtual void M54() = 0, M55() = 0, M56() = 0, M57() = 0, M58() = 0;
    virtual void M59() = 0;
    virtual void MethodF8(); // offset 248 (0xF8, method 60)
};

struct RenderManagerWindowProc {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0, M08() = 0, M09() = 0;
    virtual void M10() = 0, M11() = 0, M12() = 0, M13() = 0, M14() = 0;
    virtual void M15() = 0, M16() = 0, M17() = 0, M18() = 0, M19() = 0;
    virtual void M20() = 0, M21() = 0, M22() = 0, M23() = 0, M24() = 0;
    virtual void M25() = 0, M26() = 0, M27() = 0, M28() = 0, M29() = 0;
    virtual void M30() = 0, M31() = 0, M32() = 0, M33() = 0, M34() = 0;
    virtual void M35() = 0, M36() = 0, M37() = 0, M38() = 0, M39() = 0;
    virtual void M40() = 0, M41() = 0;
    virtual int MethodB0(int a1, int a2, int a3, int a4); // offset 176 (0xB0, method 42)
    virtual int MethodB4(int a1, int a2, int a3, int a4); // offset 180 (0xB4, method 43)
    virtual int MethodB8(int a1, int a2, int a3, int a4); // offset 184 (0xB8, method 44)
    virtual int MethodBC(int a1, int a2, int a3, int a4); // offset 188 (0xBC, method 45)
    virtual int MethodC0(int a1, int a2, int a3, int a4); // offset 192 (0xC0, method 46)
    virtual void M47() = 0;
    virtual int MethodC8(int a1, int a2, int a3, int a4); // offset 200 (0xC8, method 48)
    virtual void M49() = 0, M50() = 0, M51() = 0;
    virtual int MethodD8(int a1, int a2, int a3, int a4); // offset 216 (0xD8, method 52)
    virtual int MethodDC(int a1, int a2, int a3, int a4); // offset 220 (0xDC, method 53)
    virtual int MethodE0(int a1, int a2, int a3, int a4); // offset 224 (0xE0, method 54)
    virtual int MethodE4(int a1, int a2, int a3, int a4); // offset 228 (0xE4, method 55)
    virtual int MethodE8(int a1, int a2, int a3, int a4); // offset 232 (0xE8, method 56)

    char pad_04[0x28];
    int field_2C;
    int field_30;
    char pad_34[0x38];
    SubObj6C *field_6C;
    char pad_70[0x13C];
    void *field_1AC;
    char pad_1B0[0x38];
    int field_1E8;
};

extern int D_004E897C;
extern int D_004E8998;
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
int func_225510(int a1, int a2, int a3, int a4);
void func_001860d0(void *self);

int func_001861d0(RenderManagerWindowProc *self, int a1, int a2, int a3, int a4);
}

#endif
