#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern unsigned char *D_004E2DB4;

/** Leaf function: 1-byte store to D_004E2DB4 from staged index 1. */
void func_00173670() {
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** Leaf function: 2-byte store to D_004E2DB4 from staged index 0 and 1. */
void func_00173690() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** Leaf function: 2-byte store to D_004E2DB4 from staged index 1 and 0. */
void func_001736D0() {
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}

/** Leaf function: 2-byte store to D_004E2DB4 from staged index 0 and 1. */
void func_00173710() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}
}
