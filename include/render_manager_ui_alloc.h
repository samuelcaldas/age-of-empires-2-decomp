#ifndef RENDER_MANAGER_UI_ALLOC_H
#define RENDER_MANAGER_UI_ALLOC_H

struct EngineCtx47C0 {
    char pad_00[0x38];
    unsigned char f38;
    char pad_39[0x83];
    char fbc[1];
};

class RenderManagerUiAlloc {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void slot_88();
    char pad_04[0x24];
    EngineCtx47C0 *ctx_28;
    int field_2C;
    char pad_30[0x17C];
    void *field_1AC;
    void *field_1B0;
    void *field_1B4;
    void *field_1B8;
    void *field_1BC;
    void *field_1C0;
    char pad_1C4[0x240];
    void *field_404;
    char pad_408[0xC3C];
    char field_1044[0x14];
};

extern void *D_004E8944;
extern void *D_004E8948;
extern void *D_004E8984;
extern void *D_004E8988;

extern "C" {
void *func_100850(int size);
void func_18A010(void *obj, int f2c, unsigned char f38, void *d8944, void *fbc);
void func_189F20(void *obj, void *f1044);
void func_189E00(void *obj, void *f1b0);
void func_189E40(void *obj, void *f1b8);
void func_189E60(void *obj, void *f1bc);
void func_189E70(void *obj, void *f1c0);
void func_189E50(void *obj, void *f1b4);
void func_32FBC0(void *f404, void *obj);
void func_192CD0(void *obj, void *arg);
void func_18A570(void *obj, int one);

int func_00185660(RenderManagerUiAlloc *self);
void func_00185760(RenderManagerUiAlloc *self);
}

#endif
