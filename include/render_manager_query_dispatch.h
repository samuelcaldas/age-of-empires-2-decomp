#ifndef RENDER_MANAGER_QUERY_DISPATCH_H
#define RENDER_MANAGER_QUERY_DISPATCH_H

struct RenderManagerQueryDispatch {
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
    virtual void M60() = 0;
    virtual int MethodFC(int a1, int a2); // offset 252 (0xFC, method 61)
    virtual int Method100();              // offset 256 (0x100, method 62)
};

extern "C" {
int func_00186dc0(RenderManagerQueryDispatch *self, int a1, int a2, int a3, int a4);
int func_00186e00();
int func_00186e10(RenderManagerQueryDispatch *self);
int func_00186e40();
}

#endif
