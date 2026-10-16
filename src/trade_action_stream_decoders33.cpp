#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DB0;
extern unsigned char *D_004E2DB4;
void func_001522C0(unsigned char *destination, unsigned char *source);

/** 4-byte decoded stream transfer with opposite cursor advance. */
void func_00167EB0() {
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
}

/** 4-byte decoded plus 1-byte direct stream transfer with opposite cursor advance. */
void func_00167F40() {
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
    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB4--;
    D_004E2DB0++;
}

/** 4-byte decoded plus 1-byte direct stream transfer with opposite cursor advance (variant B). */
void func_00168000() {
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
    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB4--;
    D_004E2DB0++;
}

/** 4-byte decoded plus 1-byte direct stream transfer with opposite cursor advance (variant C). */
void func_001680C0() {
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
    *D_004E2DB4 = *D_004E2DB0;
    D_004E2DB4--;
    D_004E2DB0++;
}
}
