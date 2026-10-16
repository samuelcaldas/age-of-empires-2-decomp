#ifndef UNIT_ACTION_REBIND_H
#define UNIT_ACTION_REBIND_H

#include "unit_action_properties.h"

struct ActionRebind {
    // 17 dummy slots before Method19: virtual index 17, MWCC physical offset 76 (0x4C)
    V_SLOT_10(0)
    virtual void* v10(); virtual void* v11(); virtual void* v12();
    virtual void* Method13();
    virtual void* v14(); virtual void Method15(float x, float y, float z); virtual void* v16();
    virtual void Method19(int target);
    virtual void* v18(); virtual void* v19();
    virtual void* v20(); virtual void* v21(); virtual void* v22(); virtual void* v23(); virtual void* v24();
    virtual void* v25();
    virtual void Method28(int code);
    virtual void Method29();
    virtual void Method30();
    virtual void* v29();
    virtual void* v30();
    virtual void* v31();
    virtual float Method32();
    virtual void* v33(); virtual void Method34(int code); virtual void* v35(); virtual void* v36();
    virtual void* v37(); virtual void* v38(); virtual void* v39();
    V_SLOT_10(4)
    virtual void* v50(); virtual void* v51(); virtual void* v52(); virtual void* v53(); virtual void* v54();
    virtual void* v55(); virtual void Method58(); virtual void* v57();
    virtual void* v58();
    virtual void Method61(void *world, int a2, int a3, int a4);
    virtual void Method62(void *world, int a2, int a3, int a4);
    virtual void* v61(); virtual void* v62(); virtual void* v63(); virtual void* v64(); virtual void* v65();
    virtual void* v66(); virtual void* v67(); virtual void* v68(); virtual void* v69();
    V_SLOT_10(7)
    virtual void* v80(); virtual void* v81(); virtual void* v82(); virtual void* v83(); virtual void* v84();
    virtual void* v85(); virtual void* v86(); virtual int Method87(); virtual void* v88(); virtual void* v89();
    virtual void Method90(short a1, short a2, int a3, void *ba0, int zero1, int zero2);

    void *m_field4;
    WorldExtended *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    int m_field20;
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
