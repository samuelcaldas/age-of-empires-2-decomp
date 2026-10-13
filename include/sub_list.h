#ifndef SUB_LIST_H
#define SUB_LIST_H

#include "base_list.h"

#define V_SLOT_10(base) \
    virtual void* v##base##0(); virtual void* v##base##1(); virtual void* v##base##2(); virtual void* v##base##3(); virtual void* v##base##4(); \
    virtual void* v##base##5(); virtual void* v##base##6(); virtual void* v##base##7(); virtual void* v##base##8(); virtual void* v##base##9();

struct Vec3 {
    float x;
    float y;
    float z;
};

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
    char pad_CF;
    float m_fieldD0;
};

struct ScaleInfo {
    char pad_00[0x70];
    float m_scale;
};

struct WorldContainer {
    char pad_00[0x6C];
    int m_count;
    NodeItem **m_items;
    char pad_74[0xB94 - 0x74];
    void *m_fieldB94;
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

struct TargetEntity {
    V_SLOT_10(0)
    V_SLOT_10(1)
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    virtual void Method50(void *player, short id, int zero);
    virtual void Method51(void *player);

    char pad_04[0x20];
    short m_id;
};

class SubList {
public:
    virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3(void *player = 0); virtual void* v4();
    virtual void* v5(); virtual void* v6(); virtual void* v7(); virtual void* v8(); virtual void* v9();
    virtual void* v10(); virtual void* v11(); virtual void* v12(); virtual void* v13(); virtual void* v14();
    virtual void* v15(); virtual void* v16();
    virtual void* v17(void *a = 0, void *b = 0, void *c = 0);
    virtual void* v18(); virtual void* v19();
    virtual void* v20(); virtual void* v21(int a1); virtual void* v22(void *item); virtual void* v23();
    virtual void* v24();
    virtual void* v25(); virtual void* v26(void *item); virtual void* v27(); virtual void* v28(); virtual void* v29();
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
    virtual void* v130(); virtual void* v131(); virtual void* v132(); virtual void* v133(); virtual void* v134();
    virtual void* v135(); virtual Vec3 v136(); virtual void* v137(); virtual void* v138(); virtual void* v139();
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

    union {
        short m_field4_short;
        struct NodeItem *m_field4;
    };
    struct WorldContainer *m_field8;
    unsigned char m_fieldC;
    char pad_D[3];
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    union { int m_field20; float m_field20_float; };
    union { int m_field24; float m_field24_float; };
    union { int m_field28; float m_field28_float; };
    int m_field2C;
    void *m_field30;
    ListItem *m_field34;
    union {
        void *m_field38;
        struct {
            char pad_38;
            unsigned char m_field39;
        };
    };
    unsigned char m_field3C;
    unsigned char m_field3D;
    char pad_3E[0x44 - 0x3E];
    float m_field44;
    float m_field48;
    char pad_4C[0x64 - 0x4C];
    int m_field64;
    float m_field68;
    char pad_6C[0x7C - 0x6C];
    float m_field7C;
    char pad_80[0x8C - 0x80];
    short m_field8C_short;
    char pad_8E[0x90 - 0x8E];
    Vec3 m_field90;
    Vec3 m_field9C;
    char pad_A8[0xB4 - 0xA8];
    int m_fieldB4;
    char pad_B8[0xC0 - 0xB8];
    int m_fieldC0;
    char pad_C4[0xC5 - 0xC4];
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
    void* func_0013AE00(void *other, int mode, float x, float y, float z);
    int func_0013AF70();
    float func_0013AFC0();
    int func_0013AFD0();
    int func_0013B020();
    int func_0013B070(int id);
    void func_0013B0B0(short action_id, SubList *other, float x, float y, float z);
    Vec3 func_0013B360();
    float func_0013B380();
    short func_0013B390();
    int func_0013B3A0();
    int func_0013B3B0();
    Vec3 func_0013B3C0();
    float func_0013B3E0();
    int func_0013B3F0();
    int func_0013B400();
    int func_0013B410();
    void func_0013B420(WorldContainer *world);
    int func_0013B470();
    float func_0013B480();
    float func_0013B490();
    float func_0013B4A0();
    float func_0013B4B0();
    float func_0013B4C0();
    int func_0013B4D0();
    float func_0013B4E0();
    float func_0013B4F0();
    float func_0013B500();
    int func_0013B510();
    int func_0013B520();
    int func_0013B530();
    void func_0013B540();
    int func_0013B550();
    int func_0013B560();
    int func_0013B570();
    int func_0013B580();
    int func_0013B590();
    int func_0013B5A0();
    int func_0013B5B0();
    int func_0013B5C0();
    int func_0013B5D0();
    int func_0013B5E0();
    int func_0013B5F0();
    int func_0013B600();
    int func_0013B610();
    int func_0013B620();
    int func_0013B630();
    int func_0013B640();
    int func_0013B650();
    int func_0013B660();
    int func_0013B670();
    int func_0013B680();
    int func_0013B690();
    int func_0013B6A0();
    float func_0013B6B0();
    int func_0013B6C0();
    int func_0013B6D0();
    void func_0013B6E0();
    int func_0013B6F0();
    int func_0013B700();
    void func_0013B710(void *param1, void *param2, int do_setup);
    void func_0013B740(void *param1, int do_setup);
    void func_0013B820();
};

extern "C" {
    int func_0013B8A0(SubList *self, void *stream, void *player);
    int func_0013BA60(SubList *self, void *player);
    void func_0013BAD0(SubList *self);
    void func_0013BAE0(SubList *self);
    void func_0013BB70(SubList *self, void *stream);
    short func_0013BD10(SubList *self);
    void func_0013BD20(SubList *self);
    int func_0013BD30(SubList *self);
    int func_0013BD40(SubList *self);
    int func_0013BD50(SubList *self);
    int func_0013BD60(SubList *self);
    int func_0013BD70(SubList *self);
    void func_0013BD80(SubList *self, char val);
    int func_0013BD90(SubList *self);
    int func_0013BE10(SubList *self);
    int func_0013BE90(SubList *self);
    void func_0013BF50(SubList *self, void *new_target);
    void func_0013C010(SubList *self, void *new_target);
    void func_0013C0D0(SubList *self, void *param1);
    void func_0013C250(SubList *self);
}

struct PlayerContext {
    V_SLOT_10(0)
    virtual void* v10(); virtual void* v11(); virtual void* v12(); virtual void* v13(); virtual void* v14();
    virtual void* v15(); virtual void* v16();
    virtual void* Method17(int val);

    char pad_04[12];
    int m_target_type;
};

#undef V_SLOT_10

#endif // SUB_LIST_H
