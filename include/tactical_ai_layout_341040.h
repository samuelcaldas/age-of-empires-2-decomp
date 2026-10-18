#pragma once

class TacticalSubObj {
public:
    virtual void vfunc_00() = 0;
};

class TacticalObj_341040 {
public:
    TacticalSubObj *vtable;
    char pad_4[0x824];
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
    char pad_850[0x14];
};

extern "C" {
void func_00341040(TacticalObj_341040 *self);
void func_00342170(TacticalObj_341040 *self);
}
