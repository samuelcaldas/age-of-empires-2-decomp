#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern int D_004E2DA8;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
extern int D_004E30A8;
extern int D_004E30B0;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** Offset -1 2-byte decoded transfer with shift and D_004E2DA8 -= 5, 4-byte decoded transfer loop, followed by offset -1 3-byte decoded transfer. */
void func_00171850() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB0 - 1);
    D_004E2DB0 += 2;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word |= D_004E30B0;
    D_004E2DA0.word = (unsigned int)D_004E2DA0.word >> 8;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    D_004E2DA8 -= 5;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        unsigned char tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30B0;
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

/** 3-byte decoded transfer and D_004E2DA8 -= 6, 4-byte decoded transfer loop, followed by offset -1 3-byte decoded transfer. */
void func_00171A50() {
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
    D_004E2DA8 -= 6;
    do {
        func_001522C0(D_004E2DA0.bytes, D_004E2DB0);
        D_004E2DB0 += 4;
        unsigned char *p = (unsigned char *)&D_004E2DA0;
        unsigned char tmp = p[0];
        p[0] = p[3];
        p[3] = tmp;
        p[2] = p[1];
        D_004E2DA0.word &= D_004E30A8;
        D_004E2DA0.word |= D_004E30B0;
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

/** Leaf function: 1-byte store to D_004E2DB4 from staged index 0. */
void func_00171C50() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** Leaf function: 2-byte store to D_004E2DB4 from staged index 1 and 0. */
void func_00171C70() {
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}
}
