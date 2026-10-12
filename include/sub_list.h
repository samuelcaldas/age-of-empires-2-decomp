#ifndef SUB_LIST_H
#define SUB_LIST_H

#include "base_list.h"

#define V_SLOT_10(base) \
    virtual void* v##base##0(); virtual void* v##base##1(); virtual void* v##base##2(); virtual void* v##base##3(); virtual void* v##base##4(); \
    virtual void* v##base##5(); virtual void* v##base##6(); virtual void* v##base##7(); virtual void* v##base##8(); virtual void* v##base##9();

class SubList {
public:
    virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3(); virtual void* v4();
    virtual void* v5(); virtual void* v6(); virtual void* v7(); virtual void* v8(); virtual void* v9();
    V_SLOT_10(1)
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    V_SLOT_10(5)
    V_SLOT_10(6)
    V_SLOT_10(7)
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
    virtual void* v191(); virtual void* v192(); virtual void* v193(); virtual void* v194();
    virtual void* v195(); virtual void* v196(); virtual void* v197(); virtual void* v198();
    virtual void* v199();

    char pad_4[0xC5 - 4];
    unsigned char m_fieldC5;
    char pad_C6[6];
    void *m_fieldCC;

    int SetupSpatial();
    int Setup(void *stream);
    void* CreateSubList();
    void Action();
    void Save(void *stream);
    void Free();
    void Teardown();
    void Noop();
    void Notify(void *other);
};

#undef V_SLOT_10

#endif // SUB_LIST_H
