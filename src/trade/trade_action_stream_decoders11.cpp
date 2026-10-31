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

/** Look up a single byte via D_004E2DA4 table using current output byte and advance cursor. */
void func_0015F0F0() {
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

/** Look up two consecutive bytes via D_004E2DA4 table and advance cursor by two. */
void func_0015F130() {
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

/** Look up two consecutive bytes individually via D_004E2DA4 table. */
void func_0015F1B0() {
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}
}
