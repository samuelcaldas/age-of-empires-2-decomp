#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern int D_004E2DA4;
extern int D_004E2DA8;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** 4-byte decoded transfer followed by 3-byte decoded transfer with D_004E2DA4. */
void func_0016D430() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 4;
    D_004E2DA0.word |= D_004E2DA4;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[3];
    D_004E2DB4--;
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

/** 4-byte stream decoding loop decrementing D_004E2DA8 by 4 with D_004E2DA4. */
void func_0016D540() {
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.word |= D_004E2DA4;
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

/** 1-byte staged transfer, D_004E2DA8--, followed by 4-byte decoding loop with D_004E2DA4. */
void func_0016D5F0() {
    D_004E2DA0.bytes[0] = *D_004E2DB0;
    D_004E2DB0++;
    D_004E2DA0.word |= D_004E2DA4;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA8--;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.word |= D_004E2DA4;
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

/** 2-byte decoded transfer, D_004E2DA8 -= 2, followed by 4-byte decoding loop with D_004E2DA4. */
void func_0016D6F0() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 2;
    D_004E2DA0.word |= D_004E2DA4;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    D_004E2DA8 -= 2;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        D_004E2DA0.word |= D_004E2DA4;
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
