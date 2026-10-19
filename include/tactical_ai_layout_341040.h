#pragma once

class TacticalSubObj {
public:
    virtual void vfunc_00() = 0;
    virtual void vfunc_01() {}
    virtual void vfunc_02() {}
    virtual void vfunc_03() {}
    virtual void vfunc_04() {}
    virtual void vfunc_05() {}
    virtual void vfunc_06() {}
    virtual void vfunc_07() {}
    virtual void vfunc_08() {}
    virtual void vfunc_09() {}
    virtual void vfunc_10() {}
    virtual void vfunc_11() {}
    virtual void vfunc_12() {}
    virtual void vfunc_13() {}
    virtual void vfunc_14() {}
    virtual void vfunc_15() {}
    virtual void vfunc_16() {}
    virtual void vfunc_17() {}
    virtual void vfunc_18() {}
    virtual void vfunc_19() {}
    virtual void vfunc_20() {}
    virtual void vfunc_21() {}
    virtual void vfunc_22() {}
    virtual void vfunc_23() {}
    virtual void vfunc_24() {}
    virtual void vfunc_25() {}
    virtual void vfunc_26() {}
    virtual void vfunc_27() {}
    virtual void vfunc_28() {}
    virtual void vfunc_29() {}
    virtual void vfunc_30() {}
    virtual void vfunc_31() {}
    virtual void vfunc_32() {}
    virtual void vfunc_33() {}
    virtual void vfunc_34() {}
    virtual void vfunc_35() {}
    virtual void vfunc_36() {}
    virtual void vfunc_37() {}
    virtual void vfunc_38() {}
    virtual void vfunc_39() {}
    virtual void vfunc_40() {}
    virtual void vfunc_41() {}
    virtual void vfunc_42() {}
    virtual void vfunc_43() {}
    virtual void vfunc_44() {}
    virtual void vfunc_45() {}
    virtual void vfunc_46() {}
    virtual void vfunc_47() {}
    virtual void vfunc_48() {}
    virtual void vfunc_49() {}
    virtual void vfunc_50() {}
    virtual void vfunc_51() {}
    virtual void vfunc_52() {}
    virtual void vfunc_53() {}
    virtual void vfunc_54() {}
    virtual void vfunc_55() {}
    virtual void vfunc_56() {}
    virtual void vfunc_57() {}
    virtual void vfunc_58() {}
    virtual void vfunc_59() {}
    virtual void vfunc_60() {}
    virtual void vfunc_61() {}
    virtual void vfunc_62() {}
    virtual void vfunc_63() {}
    virtual void vfunc_64() {}
    virtual void vfunc_65() {}
    virtual void vfunc_66() {}
    virtual void vfunc_67() {}
    virtual void vfunc_68() {}
    virtual void vfunc_69() {}
    virtual void vfunc_70() {}
    virtual void vfunc_71() {}
    virtual void vfunc_72() {}
    virtual void vfunc_73() {}
    // In Metrowerks CodeWarrior PS2, vtable offsets 0x00 and 0x04 hold offset-to-top and RTTI metadata.
    // Thus vfunc_00 begins at offset 0x08, and the 75th method in class declaration order lands at
    // byte offset 0x130 (304 bytes / 76*4), matching AOK.ELF opcode 0x8f390130 (lw t9, 304(t9)).
    virtual void vfunc_76(int p) { (void)p; }
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
