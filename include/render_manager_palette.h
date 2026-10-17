#ifndef RENDER_MANAGER_PALETTE_H
#define RENDER_MANAGER_PALETTE_H

struct SubObj6C {
    char pad_00[0x44];
    unsigned char field_44;
    unsigned char field_45;
    char pad_46[0x16];
    char field_5C[0x100];
};

struct RenderManagerPalette {
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
    virtual void M50() = 0, M51() = 0, M52() = 0, M53() = 0;
    virtual void MethodE0(int a1, int a2, int a3, int a4) = 0;
    virtual void M55() = 0, M56() = 0, M57() = 0, M58() = 0, M59() = 0;
    virtual void M60() = 0, M61() = 0, M62() = 0, M63() = 0, M64() = 0;
    virtual void M65() = 0, M66() = 0, M67() = 0;
    virtual int  Method118() = 0;

    char pad_04[0x68];
    SubObj6C *field_6C;
    void *field_70;
    char pad_74[0x154];
    int field_1C8;
};

extern "C" {
void func_1AB180(void *arg);
void func_1AB370(void *arg0, int arg1, int arg2, void *arg3);
int  func_1AB1B0(void *arg);
void func_1ABD90(void *arg0, int arg1, int arg2);
void func_1AB1C0(void *arg0, int arg1);

int func_00187480(RenderManagerPalette *self, int a1, int a2, int a3, int a4);
int func_00187560(RenderManagerPalette *self);
int func_001875d0(RenderManagerPalette *self);
int func_00187650();
}

#endif
