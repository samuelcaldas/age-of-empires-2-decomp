#ifndef RENDER_MANAGER_IDLE_H
#define RENDER_MANAGER_IDLE_H

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
    virtual void Method54();                              // offset 84 (0x54, method 19)
};

struct RenderManagerIdle {
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
    virtual void M57() = 0, M58() = 0, M59() = 0, M60() = 0, M61() = 0;
    virtual void M62() = 0, M63() = 0, M64() = 0, M65() = 0, M66() = 0;
    virtual void M67() = 0, M68() = 0, M69() = 0, M70() = 0, M71() = 0;
    virtual void Method128();                             // offset 296 (0x128, method 72)
    virtual void Method12C();                             // offset 300 (0x12C, method 73)

    char pad_04[0x18];
    int field_1C;
    char pad_20[0xC];
    int field_2C;
    int field_30;
    int field_34;
    char pad_38[0x34];
    SubObj6C *field_6C;
    char pad_70[0x18];
    int field_88;
    char pad_8C[0x120];
    void *field_1AC;
    char pad_1B0[0x18];
    int field_1C8;
    char pad_1CC[0x734];
    int field_900;
    int field_904;
};

extern int D_004E8940;
extern int D_004E8958;
extern int D_004E89C0;

extern "C" {
void func_00A80BB0();
ActiveScreen *func_1F26C0(void *arg);
int func_2261C0();
void func_00184b60(int obj, int timer, int delta);
int func_1880E0(void *self);
int func_18AFE0(void *arg);

int func_00186770(RenderManagerIdle *self);
int func_00186930(RenderManagerIdle *self);
}

#endif
