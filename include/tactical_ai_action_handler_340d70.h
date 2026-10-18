#pragma once

class TacticalObj_340D70 {
public:
    virtual void vfunc_00() = 0;
    virtual void vfunc_04() = 0;
    virtual void vfunc_08() = 0;
    virtual void vfunc_0c() = 0;
    virtual void vfunc_10() = 0;
    virtual void vfunc_1c(int a) = 0;

    virtual void vf_01() = 0; virtual void vf_02() = 0; virtual void vf_03() = 0; virtual void vf_04b() = 0;
    virtual void vf_05() = 0; virtual void vf_06() = 0; virtual void vf_07() = 0; virtual void vf_08b() = 0;
    virtual void vf_09() = 0; virtual void vf_10b() = 0; virtual void vf_11() = 0; virtual void vf_12() = 0;
    virtual void vf_13() = 0; virtual void vf_14b() = 0; virtual void vf_15() = 0; virtual void vf_16() = 0;
    virtual void vf_17() = 0; virtual void vf_18b() = 0; virtual void vf_19() = 0; virtual void vf_20b() = 0;
    virtual void vf_21() = 0; virtual void vf_22() = 0; virtual void vf_23() = 0; virtual void vf_24b() = 0;
    virtual void vf_25() = 0; virtual void vf_26() = 0; virtual void vf_27() = 0; virtual void vf_28b() = 0;
    virtual void vf_29() = 0; virtual void vf_30b() = 0; virtual void vf_31() = 0; virtual void vf_32() = 0;
    virtual void vf_33() = 0; virtual void vf_34b() = 0; virtual void vf_35() = 0; virtual void vf_36() = 0;
    virtual void vf_37() = 0; virtual void vf_38b() = 0; virtual void vf_39() = 0; virtual void vf_40b() = 0;
    virtual void vf_41() = 0; virtual void vf_42() = 0; virtual void vf_43() = 0; virtual void vf_44b() = 0;

    virtual void vfunc_d0(void *a1, int a2, int a3, int t0) = 0;

    char pad_4[0x82C];
    void *field_830;
    char pad_834[8];
    int field_83C;
    int field_840;
    void *field_844;
    char pad_848[4];
    int field_84C;
    int field_850;
    int field_854;
    int field_858;
};

extern "C" {
int func_00340D70(TacticalObj_340D70 *self, int cmd, int arg2);
}
