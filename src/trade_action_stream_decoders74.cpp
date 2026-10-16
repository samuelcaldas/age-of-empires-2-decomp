#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern int D_004E2DA8;
extern unsigned char *D_004E2DB4;

/** Leaf loop: store staged index 0, D_004E2DA8--, and 4-byte decoded transfer loop. */
void func_00172830() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA8--;
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
}

/** Leaf loop: store staged indices 1, 0, D_004E2DA8 -= 2, and 4-byte decoded transfer loop. */
void func_001728F0() {
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    D_004E2DA8 -= 2;
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
}

/** Leaf loop: store staged indices 0, 1, 0, D_004E2DA8 -= 3, and 4-byte decoded transfer loop. */
void func_001729C0() {
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[1];
    D_004E2DB4--;
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
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
}

/** Leaf loop: D_004E2DA8--, 4-byte decoded transfer loop, followed by store of staged index 0. */
void func_00172AB0() {
    D_004E2DA8--;
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
    *D_004E2DB4 = D_004E2DA0.bytes[0];
    D_004E2DB4--;
}
}
