#ifndef UNIT_ACTION_REBIND_H
#define UNIT_ACTION_REBIND_H

#include "unit_action_properties.h"

struct ActionRebind {
    // 17 dummy slots before Method19: virtual index 17, MWCC physical offset 76 (0x4C)
    V_SLOT_10(0)
    virtual void* v10(); virtual void* v11(); virtual void* v12();
    virtual void* Method13();
    virtual void* v14(); virtual void* v15(); virtual void* v16();
    virtual void Method19(int target);
    virtual void* v20(); virtual void* v21(); virtual void* v22(); virtual void* v23(); virtual void* v24();
    virtual void* v25(); virtual void* v26(); virtual void* v27();
    virtual void Method28(int code);
    virtual void* v29();
    V_SLOT_10(3)
    V_SLOT_10(4)
    virtual void* v50(); virtual void* v51(); virtual void* v52(); virtual void* v53(); virtual void* v54();
    virtual void* v55(); virtual void* v56(); virtual void* v57();
    virtual void Method58();
    virtual void* v59();
    virtual void* v60();
    virtual void Method61(void *world, int a2, int a3, int a4);
    virtual void Method62(void *world, int a2, int a3, int a4);
    virtual void* v63(); virtual void* v64(); virtual void* v65(); virtual void* v66(); virtual void* v67(); virtual void* v68(); virtual void* v69();
    V_SLOT_10(7)
    V_SLOT_10(8)
    virtual void Method90(short a1, short a2, int a3, void *ba0, int zero1, int zero2);

    void *m_field4;
    WorldExtended *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    char pad_20[0x4];
    short m_field24;
    short m_field26;
    short m_field28;
    short m_field2A;
    short m_field2C;
    short m_field2E;
    float m_field30;
    char m_field34;
    char m_field35;
    unsigned char m_field36;
    unsigned char m_field37;
    unsigned char m_field38;
    unsigned char m_field39;
    char m_field3A;
    char m_field3B;
    short m_field3C;
    char pad_3E[0x2];
    int m_field40;
    float m_x;
    float m_y;
    float m_z;
};

extern "C" {
    extern void *D_004E3244;

    void func_2643C0(void *action);
    void func_207AB0(void *world, short id, int delta);
    void func_207C30(void *world, short id, int delta);
    void func_1EDF20(void *obj, void *action);
    void func_1EDA80(void *obj, void *action);
    void func_264330(void *action);
    void func_205F70(void *world, void *action);
    void func_26A540(void *action, int flag);
    int func_123350(float val);

    void func_00267A80(ActionRebind *self, void *new_entity);
    void func_00267C20(ActionRebind *self, void *new_entity);
    void func_267DD0(ActionRebind *self);
}

#endif // UNIT_ACTION_REBIND_H
