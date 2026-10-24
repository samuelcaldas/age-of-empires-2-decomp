#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };
union IdxWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DA4;
extern int D_004E2DA8;
extern IdxWord D_004E2DAC;
extern unsigned char *D_004E2DB4;
extern int D_004E30A8;
extern int D_004E30AC;

void func_001522C0(unsigned char *destination, unsigned char *source);

/** Non-leaf loop function: func_00178ee0 sequence, D_004E2DA8 -= 4, loop func_00179390 sequence, single lookup byte 1. */
void func_0017c170() {
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
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30AC;
        tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DA0.bytes[0] = D_004E2DAC.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
        D_004E2DA8 -= 4;
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
        tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30AC;
        tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while ((D_004E2DA8 -= 4) != 0);
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** Non-leaf loop function: D_004E2DA8 -= 2, loop func_00179390 sequence, 2-byte staged lookup & bitwise. */
void func_0017c480() {
    D_004E2DA8 -= 2;
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
        tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30AC;
        tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
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
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}
}
