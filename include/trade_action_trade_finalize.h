#ifndef TRADE_ACTION_TRADE_FINALIZE_H
#define TRADE_ACTION_TRADE_FINALIZE_H

class TradeAction;

struct ActionTimer {
    char pad_00[0xAC];
    float m_fieldAC;
};

struct ActionTarget {
    char pad_00[8];
    void **m_vtable2;
};

class TradeAction {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual int vfn2(int a1, int *a2);
    virtual int vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void* vfn9();
    virtual int vfn10();
    virtual int vfn11();
    virtual float vfn12();
    virtual int vfn13();
    virtual void vfn14();
    virtual int vfn15();
    virtual int vfn16();
    virtual int vfn17();
    virtual int vfn18();
    virtual int vfn19();
    virtual int vfn20();
    virtual int vfn21();
    virtual int vfn22();
    virtual void vfn23();
    virtual int vfn24();
    virtual void Method70(int a1); // offset 112 = 0x70

    char pad_04[53];
    unsigned char m_field39;       // offset 57 (0x39)
    unsigned char m_field3A;       // offset 58 (0x3A)
    char pad_3B[104 - 59];
    short m_field68;               // offset 104 (0x68)
    short m_field6A;               // offset 106 (0x6A)
};

extern "C" {
    int func_2660C0(void *self);
    void func_266920(void *a1);
    void func_00226F70(void *a1, void *data, int size);
    int func_001AAB30();

    int func_00151C70(TradeAction *self);
    void func_00151E10(TradeAction *self, void *a1);
    void func_00151E60(TradeAction *self);
    void func_00151E80(void *self);
}

#endif // TRADE_ACTION_TRADE_FINALIZE_H
