#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern int D_004E2DA8;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** Loop decoder decrementing D_004E2DA8 by 4 until zero. */
void func_001688C0() {
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while (D_004E2DA8 -= 4);
}

/** 1-byte direct stream transfer, D_004E2DA8--, followed by loop decoder. */
void func_00168960() {
    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB4--;
    D_004E2DB0++;
    D_004E2DA8--;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while (D_004E2DA8 -= 4);
}

/** 2-byte decoded stream transfer, D_004E2DA8 -= 2, followed by loop decoder. */
void func_00168A30() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 2;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    D_004E2DA8 -= 2;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while (D_004E2DA8 -= 4);
}

/** 3-byte decoded stream transfer, D_004E2DA8 -= 3, followed by loop decoder. */
void func_00168B20() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 3;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4--;
    D_004E2DA8 -= 3;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        *D_004E2DB4 = D_004E2DA0.bytes[0];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[1];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[2];
        D_004E2DB4--;
        *D_004E2DB4 = D_004E2DA0.bytes[3];
        D_004E2DB4--;
    } while (D_004E2DA8 -= 4);
}
}
