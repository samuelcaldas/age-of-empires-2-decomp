#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DB4;

/** Leaf function: sequential store of staged indices 0, 1, 0, 0, 1, 0 to D_004E2DB4. */
void func_00172250() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** Leaf function: stores staged indices 1, 0, 4-byte permutation, and 4 backward stores. */
void func_001722F0() {
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    unsigned char *p = (unsigned char *)&D_004E2DA0;
    unsigned char tmp = p[0];
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
}

/** Leaf function: store staged index 0, 4-byte permutation, and 5 backward stores. */
void func_001723A0() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    unsigned char *p = (unsigned char *)&D_004E2DA0;
    unsigned char tmp = p[0];
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
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** Leaf function: 4-byte permutation and 7 stores of indices 0, 1, 2, 3, 0, 1, 0 to D_004E2DB4. */
void func_00172450() {
    unsigned char *p = (unsigned char *)&D_004E2DA0;
    unsigned char tmp = p[0];
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
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}
}
