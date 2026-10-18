#pragma once

class TacticalSubObj {
public:
    virtual void vfunc_00() = 0;
};

class TacticalObj_341040 {
public:
    char pad_0[0x828];
    TacticalSubObj *field_828;
    TacticalSubObj *field_82C;
    TacticalSubObj *field_830;
    TacticalSubObj *field_834;
    TacticalSubObj *field_838;
    char pad_83C[0x28];
};

extern "C" {
void func_00341040(TacticalObj_341040 *self);
}
