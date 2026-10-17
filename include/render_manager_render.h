#ifndef RENDER_MANAGER_RENDER_H
#define RENDER_MANAGER_RENDER_H

struct SubObj6C {
    char pad_00[0x44];
    unsigned char field_44;
};

struct ActiveScreen {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0;
    virtual void Method28(int a1) = 0;
    virtual void M09() = 0, M10() = 0, M11() = 0, M12() = 0;
    virtual void M13() = 0, M14() = 0, M15() = 0, M16() = 0;
    virtual void M17() = 0, M18() = 0, M19() = 0, M20() = 0;
    virtual void Method5C() = 0;
};

struct RenderManagerRender {
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
    virtual void M55() = 0, M56() = 0, M57() = 0, M58() = 0, M59() = 0;
    virtual void M60() = 0, M61() = 0, M62() = 0, M63() = 0, M64() = 0;
    virtual void M65() = 0, M66() = 0, M67() = 0, M68() = 0;
    virtual void Method11C() = 0;
    virtual void M70() = 0;
    virtual void Method124() = 0;

    char pad_04[0x30];
    int field_34;
    char pad_38[0x34];
    SubObj6C *field_6C;
    char pad_70[0xC];
    int field_7C;
    char pad_80[0x148];
    int field_1C8;
    char pad_1CC[0xC];
    void *field_1D8;
    char pad_1DC[4];
    int field_1E0;
    char pad_1E4[0x224];
    int field_408;
    char pad_40C[0x10C];
    int field_518;
    char pad_51C[0x3E0];
    int field_8FC;
};

extern int D_004E89E0;
extern char D_004E89E4;
extern int D_004E89E8;
extern char D_004E89EC;

extern "C" {
void func_00A80BB0();
ActiveScreen *func_1F26C0(void *arg);
int func_2261C0();
int func_00185c70(void *self);
void func_00184b60(void *self, int timer, int delta);
void func_00185cf0(void *self);
void func_1DB6B0(void *arg);
void func_1AB1C0(void *arg, int val);

int func_00186e50(RenderManagerRender *self);
}

#endif
