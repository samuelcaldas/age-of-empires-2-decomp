#ifndef RENDER_MANAGER_DISPLAY_CHANGE_H
#define RENDER_MANAGER_DISPLAY_CHANGE_H

struct SubObj6C {
    char pad_00[0x34];
    int field_34;
    int field_38;
};

struct SubObj28 {
    char pad_00[0xA4];
    int field_A4;
    int field_A8;
};

struct ActiveScreen {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0, M08() = 0, M09() = 0;
    virtual void M10() = 0, M11() = 0, M12() = 0, M13() = 0, M14() = 0;
    virtual void M15() = 0, M16() = 0, M17() = 0, M18() = 0, M19() = 0;
    virtual void Method58(int a1, int a2) = 0;
};

struct RenderManagerDisplayChange {
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
    virtual void M65() = 0, M66() = 0;
    virtual void Method114() = 0;

    char pad_04[0x24];
    SubObj28 *field_28;
    char pad_2C[0x40];
    SubObj6C *field_6C;
};

extern "C" {
void func_00A80BB0();
ActiveScreen *func_1F26C0(void *arg);
void func_1AB120(void *arg);

int func_001873a0(RenderManagerDisplayChange *self, int a1, int a2, int a3);
int func_00187470();
}

#endif
