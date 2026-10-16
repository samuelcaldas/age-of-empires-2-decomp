#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern int D_004E30A8;
extern int D_004E30B0;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** Offset -1 2-byte decoded transfer with shift, D_004E30A8 mask, and D_004E30B0 OR-flag. */
void func_0016EA50() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0 - 1);
    D_004E2DB0 += 2;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30B0;
    D_004E2DA0.word = (unsigned int)D_004E2DA0.word >> 8;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** Leaf function: dual sequential 1-byte staged transfers with D_004E30A8 and D_004E30B0. */
void func_0016EAE0() {
    D_004E2DA0.bytes[0] = *D_004E2DB0;
    D_004E2DB0++;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30B0;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA0.bytes[1] = *D_004E2DB0;
    D_004E2DB0++;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30B0;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** 3-byte decoded stream transfer with D_004E30A8 mask and D_004E30B0 OR-flag. */
void func_0016EB80() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
    D_004E2DB0 += 3;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30B0;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4--;
}

/** Offset -1 3-byte decoded stream transfer with D_004E30A8 mask and D_004E30B0 OR-flag. */
void func_0016EC20() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0 - 1);
    D_004E2DB0 += 3;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30B0;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[2];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[3];
    D_004E2DB4--;
}
}
