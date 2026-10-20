#ifndef MODE_QUERY_TERTIARY_329130_H
#define MODE_QUERY_TERTIARY_329130_H

struct SecondarySubsystem {
    char pad[0x1B30];
    virtual void dummy0() = 0;
    virtual void dummy1() = 0;
    virtual void dummy2() = 0;
    virtual void dummy3() = 0;
    virtual void dummy4() = 0;
    virtual void dummy5() = 0;
    virtual void dummy6() = 0;
    virtual void dummy7() = 0;
    virtual void dummy8() = 0;
    virtual void dummy9() = 0;
    virtual void dummy10() = 0;
    virtual void dummy11() = 0;
    virtual void dummy12() = 0;
    virtual void dummy13() = 0;
    virtual void dummy14() = 0;
    virtual void dummy15() = 0;
    virtual void dummy16() = 0;
    virtual void dummy17() = 0;
    virtual void dummy18() = 0;
    virtual void dummy19() = 0;
    virtual void dummy20() = 0;
    virtual void dummy21() = 0;
    virtual void dummy22() = 0;
    virtual void dummy23() = 0;
    virtual void dummy24() = 0;
    virtual void dummy25() = 0;
    virtual void dummy26() = 0;
    virtual void dummy27() = 0;
    virtual void dummy28() = 0;
    virtual void dummy29() = 0;
    virtual void dummy30() = 0;
    virtual void dummy31() = 0;
    virtual void dummy32() = 0;
    virtual void dummy33() = 0;
    virtual void dummy34() = 0;
    virtual void dummy35() = 0;
    virtual void dummy36() = 0;
    virtual void dummy37() = 0;
    virtual void dummy38() = 0;
    virtual void dummy39() = 0;
    virtual void dummy40() = 0;
    virtual void dummy41() = 0;
    virtual void dummy42() = 0;
    virtual void dummy43() = 0;
    virtual int query(int zero, float fx, float fy) = 0;
};

struct GlobalContextNotify {
    virtual void g0() = 0;
    virtual void g1() = 0;
    virtual void g2() = 0;
    virtual void g3() = 0;
    virtual void notify(int a1, int a2) = 0;
};

struct ModeQueryTertiaryDescriptor {
    char pad[0x120];
    SecondarySubsystem *m_subsystem;
};

extern "C" {
    extern void *D_004E2EA0;
    extern void *D_004E3180;

    int func_1A5010(void *a0, int a1, int a2, short *out_x, short *out_y, void *out_extra);
    int func_00329130(void *self, int a1, int a2);
}

#endif // MODE_QUERY_TERTIARY_329130_H
