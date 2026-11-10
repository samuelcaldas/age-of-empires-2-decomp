#pragma exceptions off

extern "C" {
int func_2261c0();
void *func_1AAB70(int);
int func_001860d0(void *self);
int func_2260C0(void *ctx, int a1, int a2, int a3);
extern int D_004E315C;
}

struct ScreenContext {
    char pad_0[0x8C];
    int field_8C;
    int pad_90;
    int field_94;
    char pad_98[8];
    short field_A0;
    char pad_A2[0x12];
    int width;
    int height;
};

class ScreenManager {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void method14(int);
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual int method6C();
    virtual int method70();
    virtual int method74();
    virtual int method78();
    virtual int method7C();
    virtual int method80();
    virtual int method84();
    virtual int method88();
    virtual int method8C();
    virtual int method90();
    virtual void v94();
    virtual int method98();
    virtual void v9C(); virtual void vA0(); virtual void vA4(); virtual void vA8();
    virtual void vAC(); virtual void vB0(); virtual void vB4(); virtual void vB8();
    virtual void vBC(); virtual void vC0(); virtual void vC4(); virtual void vC8();
    virtual void vCC(); virtual void vD0(); virtual void vD4();
    virtual void methodD8(void *c, int, int, int);
    virtual void vDC(); virtual void vE0(); virtual void vE4(); virtual void vE8();
    virtual void vEC(); virtual void vF0(); virtual void vF4(); virtual void vF8();
    virtual void vFC(); virtual void v100(); virtual void v104(); virtual void v108();
    virtual void v10C(); virtual void v110(); virtual void v114(); virtual void v118();
    virtual void v11C(); virtual void v120(); virtual void v124(); virtual void v128();
    virtual void v12C();
    virtual int method130();
    virtual int method134();

    char pad_4[0x20];
    int field_24;
    ScreenContext *ctx;
    void *field_2C;
    int field_30;
    char pad_34[0x30];
    int field_64;
    int field_68;
    char pad_6C[0x948];
    float field_9B4;
    char pad_9B8[0x174];
    int field_B2C;
    char pad_B30[0x52C];
    int field_105C;
};

extern "C" {
int func_001847C0(ScreenManager *m) {
    int v0 = func_2261c0();
    func_1AAB70(v0);
    m->ctx->width = 640;
    m->ctx->height = 448;
    m->field_B2C = 0;
    m->ctx->field_A0 = 2;
    m->field_9B4 = 2.0f;
    m->field_105C = 3;
    m->ctx->field_8C = 10;
    m->ctx->field_94 = 10;

    if (!m->method6C()) { m->field_64 = 2; return 0; }
    m->method134();
    if (!m->method70()) { m->field_64 = 5; return 0; }
    if (!m->method74()) { m->field_64 = 6; return 0; }
    if (!m->method78()) {
        if (m->field_64 == 0) m->field_64 = 7;
        return 0;
    }
    if (!m->method7C()) { m->field_64 = 0x11; return 0; }
    if (!m->method90()) { m->field_64 = 7; return 0; }
    if (!m->method130()) { m->field_64 = 7; return 0; }
    if (!m->method80()) { m->field_64 = 8; return 0; }
    if (!m->method84()) { m->field_64 = 0x10; return 0; }
    if (!m->method88()) { m->field_64 = 9; return 0; }
    if (!m->method8C()) { m->field_64 = 0xB; return 0; }
    m->method14(0);
    m->method98();
    m->methodD8(m->field_2C, 0, 0, 0);

    m->field_30 = 1;
    func_001860d0(m);
    m->field_68 = func_2260C0(m->field_2C, 1, 5000, 0);
    m->field_24 = D_004E315C;
    return 1;
}

#if !defined(__mips__)
extern "C" {
int func_2261C0();
int func_1860D0(void *self);
int func_2261c0() { return func_2261C0(); }
int func_001860d0(void *self) { return func_1860D0(self); }
int func_001847c0(ScreenManager *m) {
    return func_001847C0(m);
}
}
#endif
}
