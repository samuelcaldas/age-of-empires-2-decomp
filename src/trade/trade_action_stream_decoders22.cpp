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

/** Single-byte lookup at index 0, bitwise mask application, and write-back. */
void func_00163020() {
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4++;
}

/** Single-byte lookup at index 1, bitwise mask application, and write-back. */
void func_00163080() {
    D_004E2DAC.bytes[0] = *D_004E2DB4;
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4++;
}

/** 2-byte staged lookup, bitwise mask application, and 2-byte write-back. */
void func_001630E0() {
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
}

/** 2-byte staged lookup, shifted bitwise mask application, and 2-byte write-back. */
void func_00163180() {
    unsigned char *ptr = D_004E2DB4;
    unsigned char *dst = D_004E2DA0.bytes;
    *dst++ = *ptr++; *dst = *ptr;
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[0];
    D_004E2DA0.bytes[0] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DAC.bytes[0] = D_004E2DA0.bytes[1];
    D_004E2DA0.bytes[1] = D_004E2DA4[D_004E2DAC.word];
    D_004E2DA0.word <<= 8;
    D_004E2DA0.word |= D_004E30AC;
    D_004E2DA0.word &= D_004E30A8;
    D_004E2DA0.word = (unsigned int)D_004E2DA0.word >> 8;
    *D_004E2DB4 = D_004E2DA0.bytes[0]; D_004E2DB4++;
    *D_004E2DB4 = D_004E2DA0.bytes[1]; D_004E2DB4++;
}
}
