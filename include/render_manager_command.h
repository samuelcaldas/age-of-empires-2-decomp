#ifndef RENDER_MANAGER_COMMAND_H
#define RENDER_MANAGER_COMMAND_H

struct NonVirtualBase {
    char pad[0x1B30];
};

struct Player : NonVirtualBase {
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
    virtual void M50() = 0, M51() = 0;
    virtual void MethodD8(int a1, int a2); // offset 216 (0xD8, method 52)
};

struct SubObj404F {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0, M08() = 0, M09() = 0;
    virtual void M10() = 0, M11() = 0, M12() = 0, M13() = 0, M14() = 0;
    virtual void M15() = 0, M16() = 0, M17() = 0, M18() = 0, M19() = 0;
    virtual void M20() = 0, M21() = 0, M22() = 0, M23() = 0, M24() = 0;
    virtual void M25() = 0, M26() = 0, M27() = 0, M28() = 0, M29() = 0;
    virtual void M30() = 0, M31() = 0, M32() = 0;
    virtual void Method8C(int val); // offset 140 (0x8C, method 33)

    char pad_04[0x50];
    Player **field_54;
};

struct RenderManagerCommand {
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
    virtual int MethodF8(int a1, int a2); // offset 248 (0xF8, method 60)

    char pad_04[0x1A8];
    void *field_1AC;
    char pad_1B0[0x254];
    SubObj404F *field_404;
};

extern int D_004E8990;

extern "C" {
int func_18FFD0(void *arg);
int func_188870(void *self, int a4);

int func_00186c20(RenderManagerCommand *self, int a1, int a2, int a3, int a4);
int func_00186db0();
}

#endif
