#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };
union StagingPtr { unsigned char bytes[4]; unsigned char *ptr; int word; };
union IdxWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0; extern StagingPtr D_004E2DA4;
extern int D_004E2DA8; extern IdxWord D_004E2DAC;
extern unsigned char *D_004E2DB0, *D_004E2DB4;
extern int D_004E3070, D_004E3074, D_004E3078, D_004E307C, D_004E3080;
extern int D_004E3084, D_004E3088, D_004E308C, D_004E3090, D_004E3094;
extern int D_004E3098, D_004E309C, D_004E30A0, D_004E30A4, D_004E30A8;
extern int D_004E30AC, D_004E30B0, D_004E30B4, D_004E30B8, D_004E30BC;
extern int D_004E30C0, D_004E30C4, D_004E30C8, D_004E30CC, D_004E30D0;
extern int D_004E30D4, D_004E30D8, D_004E30DC, D_004E30E0, D_004E30E4;
extern int D_004E30E8, D_004E30EC, D_004E30F0, D_004E30F4, D_004E30F8;

extern void (*D_0038FF30[])();
void func_001522C0(unsigned char *destination, unsigned char *source);
void func_00181e40();

void func_0017e350(int x, int y, int w, int h, int p4, int p5, int p6, int p7) {
    D_004E2DA8 = p4;
    D_004E2DA0.word = w;
    int t0 = D_004E2DA0.word;
    int a2 = D_004E2DA8;
    int a0 = D_004E30DC;
    D_004E2DA4.word = t0 + a2 - 1;
    int t5 = D_004E2DA4.word;
    D_004E3070 = t5 - a0;
    if (D_004E3070 < 0) return;

    D_004E2DAC.word = 0;
    int t4 = D_004E30E0;
    D_004E3070 = t0 - t4;
    if (D_004E3070 > 0) return;
    D_004E3070 = t0 - a0;
    if (D_004E3070 < 0) {
        D_004E2DAC.word = a0;
        int dac = D_004E2DAC.word;
        D_004E2DA0.word = 0;
        D_004E2DAC.word = dac - t0;
        D_004E2DA8 = a2 - D_004E2DAC.word;
        D_004E2DAC.word <<= 2;
    }
    D_004E3070 = t5 - t4;
    if (D_004E3070 > 0) {
        D_004E2DA4.word = D_004E2DA4.word - D_004E30E0;
        D_004E2DA8 = D_004E2DA8 - D_004E2DA4.word;
    }

    D_004E2DA0.word = y;
    int a0_x = D_004E2DA0.word;
    int v1_right = D_004E30E8;
    D_004E2DA4.word = 0;
    D_004E3070 = a0_x - v1_right;
    if (D_004E3070 > 0) return;
    int v1_left = D_004E30E4;
    D_004E3070 = a0_x - v1_left;
    if (D_004E3070 < 0) {
        D_004E2DA4.word = v1_left - a0_x;
        D_004E2DA0.word = v1_left;
    }

    D_004E2DB0 = (unsigned char *)D_004E3078;
    D_004E2DB4 = *(unsigned char **)(D_004E2DB0 + (D_004E2DA8 << 2));
    D_004E3070 = (int)D_004E2DB4;
    if (D_004E3070 == 0) return;

    D_004E30B8 = (int)D_004E2DB4;
    D_004E2DB0 = (unsigned char *)D_004E3074;
    D_004E30C0 = 0;
    func_001522C0((unsigned char *)&D_004E2DA0, (unsigned char *)(D_004E2DB0 + (D_004E2DA0.word << 2)));

    while (D_004E30B8 != 0) {
        D_004E2DB4 = (unsigned char *)D_004E30B8;
        D_004E3070 = D_004E2DA8 - *(unsigned short *)(D_004E2DB4 + 8);
        if (D_004E3070 < 0) break;
        D_004E3070 = D_004E2DAC.word - *(unsigned short *)(D_004E2DB4 + 10);
        if (D_004E3070 <= 0) {
            void (*proc)() = D_0038FF30[D_004E2DA4.word & 3];
            proc();
            if (D_004E30C0 != 1) break;
        }
        D_004E30B8 = *(int *)D_004E2DB4;
    }
}
}
