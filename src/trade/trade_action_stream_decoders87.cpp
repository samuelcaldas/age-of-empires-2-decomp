#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern int D_004E2DA8;
extern unsigned char *D_004E2DB4;

/** Leaf loop function: decrement D_004E2DA8 by 3, loop, then store bytes 1, 0, 1. */
void func_00174D10() {
    D_004E2DA8 -= 3;
    do {
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
    } while ((D_004E2DA8 -= 4) != 0);
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** Leaf loop function: store index 0, decrement D_004E2DA8 by 4, loop, then store bytes 1, 0, 1. */
void func_00174E00() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA8 -= 4;
    do {
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
    } while ((D_004E2DA8 -= 4) != 0);
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** Leaf loop function: store indices 1, 0, decrement D_004E2DA8 by 5, loop, then store bytes 1, 0, 1. */
void func_00174F00() {
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA8 -= 5;
    do {
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
    } while ((D_004E2DA8 -= 4) != 0);
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}

/** Leaf loop function: store indices 0, 1, 0, decrement D_004E2DA8 by 6, loop, then store bytes 1, 0, 1. */
void func_00175020() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA8 -= 6;
    do {
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
    } while ((D_004E2DA8 -= 4) != 0);
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
}
}
