#ifndef SUB_LIST_H
#define SUB_LIST_H

#include "base_list.h"

#define V_SLOT_10(base) \
    virtual void* v##base##0(); virtual void* v##base##1(); virtual void* v##base##2(); virtual void* v##base##3(); virtual void* v##base##4(); \
    virtual void* v##base##5(); virtual void* v##base##6(); virtual void* v##base##7(); virtual void* v##base##8(); virtual void* v##base##9();

struct SubListHelper {
    virtual void* v0();
    virtual void* Method3(void *self, void *field4, void *other, float x, float y, float z, int mode, int b);
};

struct NodeItem {
    unsigned char m_field0;
    char pad_1[0xD];
    short m_fieldE;
    char pad_10[0xA0 - 0x10];
    void *m_fieldA0;
    float m_fieldA4;
    char pad_A8[0xC8 - 0xA8];
    SubListHelper *m_fieldC8;
    short m_fieldCC_short;
    unsigned char m_fieldCE;
};

struct ScaleInfo {
    char pad_00[0x70];
    float m_scale;
};

struct WorldContainer {
    char pad_00[0x6C];
    int m_count;
    NodeItem **m_items;
    char pad_74[0xB98 - 0x74];
    void *m_fieldB98;
    char pad_B9C[0xBAC - 0xB9C];
    ScaleInfo *m_fieldBAC;
};

struct SpatialObj1 {
    virtual void* v0(); virtual void* v1(); virtual void* v2();
    virtual void* v3(); virtual void* v4(); virtual void* v5();
    virtual void* v6(); virtual void* v7();
    virtual int v8();
    virtual void* v9(); virtual void* v10(); virtual void* v11();
    virtual void* v12(); virtual void* v13(); virtual void* v14();
    virtual void* v15(); virtual void* v16(); virtual void* v17();
    virtual void* v18(); virtual void* v19(); virtual void* v20();
    virtual void* v21();
    short m_field4;
    short type;
    char pad_08[4];
    unsigned char m_fieldC;
    char pad_0D[0x24 - 0xD];
    float f24;
};

struct OtherObj {
    char pad_00[4];
    NodeItem *m_field4;
    char pad_08[0x24 - 8];
    short m_field24_short;
};

class SubList {
public:
    virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3(); virtual void* v4();
    virtual void* v5(); virtual void* v6(); virtual void* v7(); virtual void* v8(); virtual void* v9();
    V_SLOT_10(1)
    virtual void* v20(); virtual void* v21(); virtual void* v22(); virtual void* v23();
    virtual void* v24(void *item);
    virtual void* v25(); virtual void* v26(); virtual void* v27(); virtual void* v28(); virtual void* v29();
    V_SLOT_10(3)
    virtual void* v40(); virtual void* v41();
    virtual void* v42(void *other, float x, float y, float z);
    virtual void* v43(); virtual void* v44(); virtual void* v45(); virtual void* v46(); virtual void* v47(); virtual void* v48(); virtual void* v49();
    V_SLOT_10(5)
    V_SLOT_10(6)
    virtual void* v70();
    virtual float GetRange();
    virtual void* v72(); virtual void* v73();
    virtual void* v74(); virtual void* v75(); virtual void* v76(); virtual void* v77(); virtual void* v78(); virtual void* v79();
    V_SLOT_10(8)
    V_SLOT_10(9)
    V_SLOT_10(10)
    V_SLOT_10(11)
    V_SLOT_10(12)
    V_SLOT_10(13)
    V_SLOT_10(14)
    V_SLOT_10(15)
    V_SLOT_10(16)
    V_SLOT_10(17)
    V_SLOT_10(18)
    virtual void* v190(void *p, int a, int b);
    virtual void* v191(void *p, int a, int b); virtual void* v192(); virtual void* v193(short arg); virtual void* v194(void *p);
    virtual void* v195(); virtual void* v196(void *p);
    virtual void* v197(short action_id, void *other, float x, float y, float z);
    virtual void* v198();
    virtual void* v199();

    struct NodeItem *m_field4;
    struct WorldContainer *m_field8;
    char pad_C[0x1C - 0xC];
    int m_field1C;
    char pad_20[0x39 - 0x20];
    unsigned char m_field39;
    char pad_3A[0x64 - 0x3A];
    int m_field64;
    char pad_68[0xC5 - 0x68];
    unsigned char m_fieldC5;
    char pad_C6[2];
    void *m_fieldC8;
    BaseList *m_fieldCC;

    int SetupSpatial();
    int Setup(void *stream);
    void* CreateSubList();
    void Action();
    void Save(void *stream);
    void Free();
    void Teardown();
    void Noop();
    void Notify(void *other);
    NodeItem* func_0013A700(void *other, float x, float y, float z);
    void func_0013A870(short index);
    void func_0013A910(short id);
    void func_0013A9B0(void *item);
    void func_0013A9D0(void *item);
    void func_0013AA20(void *item);
    void func_0013AA40();
    int func_0013AA80();
    void func_0013AB90(int arg1);
    void func_0013ABF0(int msg);
    int func_0013AC40();
    int func_0013AC70();
    int func_0013ACA0();
    void* func_0013ADC0();
};

#undef V_SLOT_10

#endif // SUB_LIST_H
