#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };
union IdxWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DA4;
extern IdxWord D_004E2DAC;
extern unsigned char *D_004E2DB4;
extern int D_004E30A8;
extern int D_004E30AC;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** Dual permutation decoder with bitwise mask application and 4-byte write-back. */
void func_00163700() {
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
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    *D_004E2DB4 = D_004E2DA0.bytes[0]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[2]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[3]; D_004E2DB4++;
}

/** Offset -1 permutation decoder with bitwise mask application and trailing lookup. */
void func_00163840() {
    func_001522C0(D_004E2DA0.bytes, D_004E2DB4 - 1);
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
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DB4--;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.bytes[0] = D_004E2DAC.bytes[0];
    *D_004E2DB4 = D_004E2DA0.bytes[0]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[2]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[3]; D_004E2DB4++;

    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    *D_004E2DB4 = D_004E2DA0.bytes[0]; D_004E2DB4++;
}

/** 2x 2-byte staged lookups with bitwise mask applications and write-backs. */
void func_001639E0() {
    unsigned char *ptr = D_004E2DB4;
    unsigned char *dst = D_004E2DA0.bytes;
    *dst++ = *ptr++; *dst = *ptr;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    *D_004E2DB4 = D_004E2DA0.bytes[0]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1]; D_004E2DB4++;

    ptr = D_004E2DB4;
    dst = D_004E2DA0.bytes;
    *dst++ = *ptr++; *dst = *ptr;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    *D_004E2DB4 = D_004E2DA0.bytes[0]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1]; D_004E2DB4++;
}

/** Initial single-byte lookup at index 1 and mask, followed by 4-phase permutation stream decoder. */
void func_00163B20() {
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    *D_004E2DB4 = D_004E2DA0.bytes[1]; D_004E2DB4++;

    func_001522C0(D_004E2DA0.bytes, D_004E2DB4);
    unsigned char *p = (unsigned char *)&D_004E2DA0;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    unsigned char tmp = p[0];
    p[0] = p[3]; p[3] = tmp; p[2] = p[1];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    tmp = p[0];
    p[0] = p[3]; p[3] = tmp; p[2] = p[1];
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    tmp = p[0];
    p[0] = p[3]; p[3] = tmp; p[2] = p[1];
    D_004E2DA0.bytes[0] = D_004E2DAC.bytes[0];
    tmp = p[0];
    p[0] = p[3]; p[3] = tmp; p[2] = p[1];
    *D_004E2DB4 = D_004E2DA0.bytes[0]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[2]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[3]; D_004E2DB4++;
    D_004E2DB4--;
}
}
