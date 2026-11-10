#pragma exceptions off

union StagingWord {
    unsigned char bytes[4];
    int word;
};

union IdxWord {
    unsigned char bytes[4];
    int word;
};

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DA4;
extern IdxWord D_004E2DAC;
extern unsigned char *D_004E2DB4;

void func_001522C0(unsigned char *destination, unsigned char *source);

/** 2-byte staging lookup followed by single-byte lookup and write. */
void func_0015F450() {
    unsigned char *ptr = D_004E2DB4;
    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    dst[0] = ptr[0];
    dst[1] = ptr[1];

    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];

    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;

    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

/** Single-byte lookup followed by 2-byte staging lookup and write. */
void func_0015F510() {
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;

    unsigned char *ptr = D_004E2DB4;
    unsigned char *dst = (unsigned char *)&D_004E2DA0;
    dst[0] = ptr[0];
    dst[1] = ptr[1];

    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];

    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
}

/** 2-phase dual-byte lookup and permutation before writing 4 bytes. */
void func_0015F5D0() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB4);

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

    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[3];
    D_004E2DB4++;
}

/** Offset -1 2-phase dual lookup, permutation, write, and trailing lookup. */
void func_0015F6F0() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 1);

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

    tmp = p[0];
    p[0] = p[3];
    p[3] = tmp;
    p[2] = p[1];

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

    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}
}
