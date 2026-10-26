#pragma once

class MemoryCardScreen;

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
    virtual void vfunc_76(int p) { (void)p; }
};

class MemoryCardDialog {
public:
    TacticalSubObj *vtable;           // 0x000: vtable at 0x4DF3F0
    char pad_4[8];                    // 0x004
    int field_C;                      // 0x00C
    int field_10;                     // 0x010
    char pad_14[0x814];               // 0x014 to 0x828
    TacticalSubObj *field_828;        // 0x828
    TacticalSubObj *field_82C;        // 0x82C
    TacticalSubObj *field_830;        // 0x830: OK button (0xFA1)
    TacticalSubObj *field_834;        // 0x834: Cancel button (0xFA2, hotkey 0x1B)
    TacticalSubObj *field_838;        // 0x838: Name text input field
    int field_83C;                    // 0x83C
    int field_840;                    // 0x840: active mode
    void *field_844;                  // 0x844: pointer to parent MemoryCardScreen
    char pad_848[4];                  // 0x848
    int field_84C;                    // 0x84C: active modal step/mode (0-29)
    int field_850;                    // 0x850
    int field_854;                    // 0x854
    int field_858;                    // 0x858: active / idle dispatch flag
};

extern "C" {
void func_00340490(MemoryCardDialog *self, MemoryCardScreen *screen, int a2, int mode);
void func_00341040(MemoryCardDialog *self);
int func_00342170(MemoryCardDialog *self, int a1, int a2, int a3, int t0);
void func_00340C30(void *self);
int func_00340CF0(void *self);
int func_00219BA0(void *self);
int func_1F6EA0(void *self, int code);
int func_1FBD30(void *self, int a1, int a2, int a3, int t0);
}
