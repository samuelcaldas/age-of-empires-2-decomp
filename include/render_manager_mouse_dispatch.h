#ifndef RENDER_MANAGER_MOUSE_DISPATCH_H
#define RENDER_MANAGER_MOUSE_DISPATCH_H

struct POINT {
    int x;
    int y;
};

struct RenderManagerMouseDispatch {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0, M08() = 0, M09() = 0;
    virtual void M10() = 0, M11() = 0, M12() = 0, M13() = 0, M14() = 0;
    virtual void M15() = 0, M16() = 0, M17() = 0, M18() = 0, M19() = 0;
    virtual void M20() = 0, M21() = 0, M22() = 0, M23() = 0, M24() = 0;
    virtual void M25() = 0, M26() = 0, M27() = 0, M28() = 0, M29() = 0;
    virtual void M30() = 0, M31() = 0, M32() = 0, M33() = 0, M34() = 0;
    virtual void M35() = 0, M36() = 0, M37() = 0, M38() = 0, M39() = 0;
    virtual void M40() = 0;
    virtual void MethodAC();                              // offset 172 (0xAC, method 41)
    virtual void M42() = 0, M43() = 0, M44() = 0, M45() = 0, M46() = 0;
    virtual void M47() = 0, M48() = 0, M49() = 0, M50() = 0, M51() = 0;
    virtual void M52() = 0, M53() = 0, M54() = 0, M55() = 0, M56() = 0;
    virtual void M57() = 0;
    virtual void MethodF0(int x, int y, int b1, int b2, int b3, int b4); // offset 240 (0xF0, method 58)

    char pad_04[0x28];
    int field_2C;
    int field_30;
    char pad_34[0x1A4];
    void *field_1D8;
    char pad_1DC[0xC];
    int field_1E8;
};

extern "C" {
void func_1DB790(void *arg, int val);
void func_1DB7F0(void *arg);
void func_00185f80(void *self, int flags, unsigned int coords, POINT *pt, int *b1, int *b2, int *b3, int *b4);

int func_00186950(RenderManagerMouseDispatch *self, int a1, int a2, int flags, unsigned int coords);
int func_00186a20();
}

#endif
