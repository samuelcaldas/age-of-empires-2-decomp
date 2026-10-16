#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern int D_004E2DA4;
extern int D_004E2DA8;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern int D_004E30A8;
extern int D_004E30AC;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** 3-byte decoded transfer, D_004E2DA8 -= 6, loop decoder, then offset -1 3-byte decoded transfer. */
void func_0016C610() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4--;
    D_004E2DA8 -= 6;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30AC;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while (D_004E2DA8 -= 4);
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0 - 1);
    D_004E2DB0 += 3;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30AC;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[3];
    D_004E2DB4--;
}

/** 1-byte staged transfer with D_004E2DA4 bitwise OR and backward store to D_004E2DB4. */
void func_0016C7E0() {
    D_004E2DA0.bytes[0] = *D_004E2DB0;
    D_004E2DB0++;
    D_004E2DA0.word |= D_004E2DA4;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** 2-byte decoded transfer via func_001522C0 with D_004E2DA4 bitwise OR and backward store. */
void func_0016C820() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.word |= D_004E2DA4;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** 3-byte decoded transfer via func_001522C0 with D_004E2DA4 bitwise OR and backward store. */
void func_0016C890() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.word |= D_004E2DA4;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4--;
}
}
