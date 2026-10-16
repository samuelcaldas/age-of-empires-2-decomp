#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern int D_004E2DA4;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** 4-byte decoded transfer followed by 2-byte decoded transfer with D_004E2DA4. */
void func_0016D000() {
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
    D_004E2DB0 += 2;
    D_004E2DA0.word |= D_004E2DA4;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** 4-byte decoded transfer followed by 3-byte decoded transfer with D_004E2DA4. */
void func_0016D100() {
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

/** Secondary 4-byte transfer followed by 3-byte transfer with D_004E2DA4. */
void func_0016D210() {
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

/** Tertiary 4-byte transfer followed by 3-byte transfer with D_004E2DA4. */
void func_0016D320() {
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
}
