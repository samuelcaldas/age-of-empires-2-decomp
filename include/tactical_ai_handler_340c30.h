#pragma once

class TacticalObj_340C30 {
public:
    virtual void vfunc_00() = 0;
    virtual void vfunc_04() = 0;
    virtual void vfunc_08() = 0;
    virtual void vfunc_0c() = 0;
    virtual void vfunc_10() = 0;
    virtual void vfunc_1c(int a) = 0;

    char pad_4[0x80];
    int field_84;
    char pad_88[0x7B4];
    int field_83C;
    int field_840;
    void *field_844;
    char pad_848[4];
    int field_84C;
    char pad_850[4];
    int field_854;
    int field_858;
};

extern "C" {
void func_00340C30(TacticalObj_340C30 *self);
}
