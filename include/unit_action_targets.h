#ifndef UNIT_ACTION_TARGETS_H
#define UNIT_ACTION_TARGETS_H

#include "unit_action_core.h"

typedef short (*Method110Fn)(void *world, void *action, int a2, int a3);
typedef void (*Method114Fn)(void *world, void *action, int a2, int a3, short a4);

struct WorldSub1B30 {
    char pad_00[272];
    Method110Fn Method110;
    Method114Fn Method114;
};

struct WorldExtended {
    char pad_00[0x70];
    void **m_entities;
    char pad_74[0xBA0 - 0x74];
    void *m_fieldBA0;
    char pad_BA4[0x1B30 - 0xBA4];
    WorldSub1B30 *m_field1B30;
};

struct ActionExtended {
    // 17 dummy slots before Method19 so it lands at slot 19 (offset 76 = 0x4C)
    V_SLOT_10(0)
    virtual void* v10(); virtual void* v11(); virtual void* v12(); virtual void* v13(); virtual void* v14();
    virtual void* v15(); virtual void* v16();
    virtual void Method19(int target);
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    V_SLOT_10(5)
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
    void func_1827B0(void *fieldC, int target);
    void func_182610(void *fieldC, int target, int code, int zero1, int zero2, unsigned char field35);
    int func_2634A0(int target);
    void func_26A460(void *action);
    void func_205F70(void *world, void *action);
    void func_2643C0(void *action);
    void func_264290(void *action);
    char func_26AD20(void *action, int flag);

    float func_00267380(ActionExtended *self, float val);
    void func_002673D0(ActionExtended *self, int target_id);
    void func_002674C0(ActionExtended *self, int arg1, int arg2);
    void func_00267500(ActionExtended *self, int arg1);
    void func_00267530(ActionExtended *self, WorldExtended *world);
}

#endif // UNIT_ACTION_TARGETS_H
