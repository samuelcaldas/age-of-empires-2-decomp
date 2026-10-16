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

/** 2-byte staged lookup and write with D_004E2DA8 decrement, loop decoder, and trailing lookup. */
void func_001618C0() {
    unsigned char *ptr = D_004E2DB4;
    unsigned char *dst = D_004E2DA0.bytes;
    *dst++ = *ptr++;
    *dst = *ptr;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1]; D_004E2DB4++;
    D_004E2DA8 -= 3;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB4);
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
    } while (D_004E2DA8 -= 4);
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

/** Offset -1 decoder with D_004E2DA8 decrement, loop decoder, and trailing lookup. */
void func_00161AB0() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 1);
    {
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        unsigned char b0 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = b0;
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
        D_004E2DA8 -= 4;
    }
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB4);
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
    } while (D_004E2DA8 -= 4);
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

/** Decrement D_004E2DA8, loop decoder, and trailing 2-byte staged lookup. */
void func_00161D20() {
    D_004E2DA8 -= 2;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB4);
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
    } while (D_004E2DA8 -= 4);
    unsigned char *src = D_004E2DB4;
    unsigned char *p = (unsigned char *)&D_004E2DA0;
    p[0] = src[0]; p[1] = src[1];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
}

/** Initial single-byte lookup with D_004E2DA8 decrement, loop decoder, and trailing 2-byte lookup. */
void func_00161ED0() {
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    D_004E2DA8 -= 3;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB4);
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        unsigned char tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
        D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
        D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
        D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
        tmp = p[0];
        p[0] = p[3]; p[3] = tmp; p[2] = p[1];
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4++;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4++;
    } while (D_004E2DA8 -= 4);
    unsigned char *src = D_004E2DB4;
    unsigned char *p = (unsigned char *)&D_004E2DA0;
    p[0] = src[0]; p[1] = src[1];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
}
}
