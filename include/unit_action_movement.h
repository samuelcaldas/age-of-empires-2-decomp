#ifndef UNIT_ACTION_MOVEMENT_H
#define UNIT_ACTION_MOVEMENT_H

#include "unit_action_core.h"

struct ActionMovement {
    V_SLOT_10(0)
    virtual void* v10(); virtual void* v11(); virtual void* v12(); virtual void* v13(); virtual void* v14(); virtual void* v15(); virtual void* v16();
    virtual void* Method17(float x, float y, float z);
    virtual void* v18(); virtual void* v19();
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    virtual void* v50(); virtual void* v51(); virtual void* v52(); virtual void* v53(); virtual void* v54(); virtual void* v55(); virtual void* v56();
    virtual void* Method57(void *param, int code);
    virtual void* v58(); virtual void* v59();
    virtual void Method62(void *world, int a2, int a3, int a4);

    void *m_field4;
    void *m_world;
    void *m_fieldC;
    void *m_target;
    int m_field14;
    int m_field18;
    int m_field1C;
    char pad_20[0x17];
    char m_field37;
    char pad_38[0xC];
    float m_x;
    float m_y;
    float m_z;
    char pad_50[0x4];
    int m_field54;
};

extern "C" {
    extern void *D_004E3244;
    extern void *D_004E3180;

    float func_3675D0();
    void func_1EDF20(void *obj, void *action);
    void func_1EE720(void *obj, void *action);
    void func_1D0B40(void *sub, int field18, void *action);
    void func_205F70(void *world, void *action);

    void func_00266C50(ActionMovement *self);
}

#endif // UNIT_ACTION_MOVEMENT_H
