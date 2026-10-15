#ifndef UNIT_ACTION_CORE_H
#define UNIT_ACTION_CORE_H

#include "sub_list.h"

struct ActionTarget {
    char pad_00[0x24];
    short m_owner;
    char pad_26[0x34 - 0x26];
    short m_id;
};

struct ActionItemField4 {
    char pad_00[0x8];
    short m_field8;
    char pad_0A[0x3C - 0x0A];
    short m_field3C;
};

struct ActionItemFieldA0 {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* vA();
    virtual void* Method34(void *self, void *world, float x, float y, float z);
};

struct ActionNodeItem {
    char pad_00[0x62];
    short m_field62;
    char pad_64[0xA0 - 0x64];
    ActionItemFieldA0 *m_fieldA0;
};

#define V_SLOT_10(base) \
    virtual void* v##base##0(); virtual void* v##base##1(); virtual void* v##base##2(); virtual void* v##base##3(); virtual void* v##base##4(); \
    virtual void* v##base##5(); virtual void* v##base##6(); virtual void* v##base##7(); virtual void* v##base##8(); virtual void* v##base##9();

struct Action {
    V_SLOT_10(0)
    virtual void* v10(); virtual void* v11(); virtual void* v12(); virtual void* v13(); virtual void* v14(); virtual void* v15(); virtual void* v16();
    virtual void* Method17(float x, float y, float z);
    virtual void* v18(); virtual void* v19();
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    virtual void* v50(); virtual void* v51(); virtual void* v52(); virtual void* v53(); virtual void* v54(); virtual void* v55(); virtual void* v56();
    virtual void* Method57(void *param, int code);

    ActionItemField4 *m_field4;
    WorldContainer *m_world;
    void *m_fieldC;
    ActionTarget *m_target;
    char pad_14[0x8];
    int m_field1C;
    char pad_20[0x4];
    short m_field24;
    short m_field26;
    short m_field28;
    short m_field2A;
    short m_field2C;
    short m_field2E;
    int m_field30;
    char m_field34;
    char m_field35;
    char m_field36;
    char m_field37;
    char m_field38;
    char m_field39;
    char m_field3A;
    char m_field3B;
    short m_field3C;
    char pad_3E[0x2];
    int m_field40;
    float m_x;
    float m_y;
    float m_z;
    char pad_50[0x8];
    int *m_field58;
    short m_field5C;
    char pad_5E[0x6];
    int m_field64;
};

extern "C" {
    int func_208260();
    void func_2082A0(void *world);
    void* func_332e60(void *container, int param);
    void func_00226F70(void *stream, void *buffer, int size);
    char func_26AD20(void *action, int flag);
    void func_1823E0(void *fieldC, void *stream);

    ActionNodeItem* func_00266780(Action *self);
    void func_00266840(Action *self);
    void* func_002668C0(void *self, int param);
    void* func_002668D0(void *self, short idx);
    void func_00266920(Action *self, void *stream);
}

#endif // UNIT_ACTION_CORE_H
