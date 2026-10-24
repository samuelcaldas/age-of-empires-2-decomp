#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };
union IdxWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DA4;
extern int D_004E2DA8;
extern IdxWord D_004E2DAC;
extern unsigned char *D_004E2DB4;

void func_001522C0(unsigned char *destination, unsigned char *source);

/** Non-leaf loop function: single staged lookup, D_004E2DA8 -= 3, loop func_00176D40, trailing 2-byte lookup & stores. */
void func_00177C20() {
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA8 -= 3;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 3);
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while ((D_004E2DA8 -= 4) != 0);
    unsigned char *ptr = D_004E2DB4 - 1;
    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    *dst++ = *ptr++; *dst = *ptr;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** Non-leaf loop function: 2-byte staged lookup, D_004E2DA8 -= 4, loop func_00176D40, trailing 2-byte lookup & stores. */
void func_00177DF0() {
    unsigned char *ptr = D_004E2DB4 - 1;
    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    *dst++ = *ptr++; *dst = *ptr;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA8 -= 4;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 3);
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while ((D_004E2DA8 -= 4) != 0);
    ptr = D_004E2DB4 - 1;
    dst = (unsigned char *)&D_004E2DA0;
    *dst++ = *ptr++; *dst = *ptr;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** Non-leaf loop function: func_00175280, D_004E2DA8 -= 5, loop func_00176D40, trailing 2-byte lookup & stores. */
void func_00178010() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 2);
    {
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
        D_004E2DA8 -= 5;
    }
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 3);
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while ((D_004E2DA8 -= 4) != 0);
    unsigned char *ptr = D_004E2DB4 - 1;
    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    *dst++ = *ptr++; *dst = *ptr;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** Non-leaf loop function: D_004E2DA8 -= 3, loop func_00176D40, then func_00175380. */
void func_001782A0() {
    D_004E2DA8 -= 3;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 3);
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while ((D_004E2DA8 -= 4) != 0);
    func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 3);
    {
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
    }
}
}
