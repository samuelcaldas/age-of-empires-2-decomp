#pragma once

class TacticalSubObj {
public:
    virtual void vfunc_00() = 0;
};

class TacticalObj_341040 {
public:
    TacticalSubObj *vtable;
    char pad_4[8];
    int field_C;
    int field_10;
    char pad_14[0x814];
    TacticalSubObj *field_828;
    TacticalSubObj *field_82C;
    TacticalSubObj *field_830;
    TacticalSubObj *field_834;
    TacticalSubObj *field_838;
    int field_83C;
    int field_840;
    void *field_844;
    char pad_848[4];
    int field_84C;
    int field_850;
    char pad_854[0x10];
};

extern "C" {
void func_00341040(TacticalObj_341040 *self);
int func_00342170(TacticalObj_341040 *self, int a1, int a2, int a3, int t0);
}
