#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern int D_004E30A8;
extern int D_004E30AC;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** 1-byte staging, mask application, and backward store at index 0. */
void func_001699F0() {
    D_004E2DA0.bytes[0] = *D_004E2DB0;
    D_004E2DB0++;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** 1-byte staging, mask application, and backward store at index 1. */
void func_00169A40() {
    D_004E2DA0.bytes[1] = *D_004E2DB0;
    D_004E2DB0++;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** 2-byte decoded stream transfer with bitwise mask application. */
void func_00169A90() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** Offset -1 2-byte decoded stream transfer with shifted mask application. */
void func_00169B10() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0 - 1);
    D_004E2DB0 += 2;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word = (unsigned int)D_004E2DA0.word >> 8;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}
}
