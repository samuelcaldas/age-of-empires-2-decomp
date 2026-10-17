#pragma exceptions off

extern "C" {
int func_2261C0();
void *func_1AAB70(int);
int func_1860D0(void *self);
int func_2260C0(void *ctx, int a1, int a2, int a3);
extern int D_004E315C;

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

struct ScreenManager {
    void *vtable;
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

int func_001847c0(ScreenManager *m) {
    int v0 = func_2261C0();
    func_1AAB70(v0);
    m->ctx->width = 640;
    m->ctx->height = 448;
    m->field_B2C = 0;
    m->ctx->field_A0 = 2;
    m->field_9B4 = 2.0f;
    m->field_105C = 3;
    m->ctx->field_8C = 10;
    m->ctx->field_94 = 10;

    typedef int (*VMethod)(void *self);
    VMethod m_6c = *(VMethod *)(*(char **)m + 0x6C);
    if (!m_6c(m)) { m->field_64 = 2; return 0; }

    VMethod m_134 = *(VMethod *)(*(char **)m + 0x134);
    m_134(m);

    VMethod m_70 = *(VMethod *)(*(char **)m + 0x70);
    if (!m_70(m)) { m->field_64 = 5; return 0; }

    VMethod m_74 = *(VMethod *)(*(char **)m + 0x74);
    if (!m_74(m)) { m->field_64 = 6; return 0; }

    VMethod m_78 = *(VMethod *)(*(char **)m + 0x78);
    if (!m_78(m)) {
        if (m->field_64 == 0) m->field_64 = 7;
        return 0;
    }

    VMethod m_7c = *(VMethod *)(*(char **)m + 0x7C);
    if (!m_7c(m)) { m->field_64 = 0x11; return 0; }

    VMethod m_90 = *(VMethod *)(*(char **)m + 0x90);
    if (!m_90(m)) { m->field_64 = 7; return 0; }

    VMethod m_130 = *(VMethod *)(*(char **)m + 0x130);
    if (!m_130(m)) { m->field_64 = 7; return 0; }

    VMethod m_80 = *(VMethod *)(*(char **)m + 0x80);
    if (!m_80(m)) { m->field_64 = 8; return 0; }

    VMethod m_84 = *(VMethod *)(*(char **)m + 0x84);
    if (!m_84(m)) { m->field_64 = 0x10; return 0; }

    VMethod m_88 = *(VMethod *)(*(char **)m + 0x88);
    if (!m_88(m)) { m->field_64 = 9; return 0; }

    VMethod m_8c = *(VMethod *)(*(char **)m + 0x8C);
    if (!m_8c(m)) { m->field_64 = 0xB; return 0; }

    typedef void (*VMethod14)(void *self, int);
    VMethod14 m_14 = *(VMethod14 *)(*(char **)m + 0x14);
    m_14(m, 0);

    VMethod m_98 = *(VMethod *)(*(char **)m + 0x98);
    m_98(m);

    typedef void (*VMethodD8)(void *self, void *c, int, int, int);
    VMethodD8 m_d8 = *(VMethodD8 *)(*(char **)m + 0xD8);
    m_d8(m, m->field_2C, 0, 0, 0);

    m->field_30 = 1;
    func_1860D0(m);
    m->field_68 = func_2260C0(m->field_2C, 1, 5000, 0);
    m->field_24 = D_004E315C;
    return 1;
}
}
