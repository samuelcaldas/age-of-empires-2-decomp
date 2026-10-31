#pragma exceptions off
#include "trade_action_stream_dispatch.h"

union StagingWord { unsigned char bytes[4]; int word; };
union StagingPtr { unsigned char bytes[4]; unsigned char *ptr; int word; };
union IdxWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0; extern StagingPtr D_004E2DA4;
extern int D_004E2DA8; extern IdxWord D_004E2DAC;
extern unsigned char *D_004E2DB0, *D_004E2DB4;
extern int D_004E3070, D_004E3074, D_004E3078, D_004E3090, D_004E309C;
extern int D_004E30B4, D_004E30B8, D_004E30C0, D_004E30C8;
extern int D_004E30DC, D_004E30E0, D_004E30E4, D_004E30E8;
extern const char D_00390B30[]; extern void (*D_0038FF30[])();
extern const char D_00491180[], D_004911B0[];

void func_001522C0(unsigned char *destination, unsigned char *source);
void func_118de0(const char *str);
int func_0011a498(char *buffer, const char *format, ...);

void func_0017DDE0(int x1, int x2, int y, int code) {
    char buf1[256], buf2[256];

    D_004E2DA0.word = y;
    int cur_y = D_004E2DA0.word;
    D_004E3070 = cur_y - D_004E30DC;
    if (D_004E3070 < 0) return;
    D_004E3070 = cur_y - D_004E30E0;
    if (D_004E3070 > 0) return;

    D_004E2DA0.word = x1;
    D_004E2DA4.word = x2;
    int a1_val = D_004E2DA0.word;
    int a0_val = D_004E2DA4.word;
    D_004E3070 = a1_val - a0_val;
    if (D_004E3070 > 0) {
        D_004E2DA0.word = a0_val;
        D_004E2DA4.word = a1_val;
        x1 = D_004E2DA0.word;
        x2 = D_004E2DA4.word;
    }

    D_004E3070 = D_004E2DA4.word - D_004E30E4;
    if (D_004E3070 < 0) return;
    D_004E3070 = D_004E2DA0.word - D_004E30E8;
    if (D_004E3070 > 0) return;
    D_004E3070 = D_004E2DA0.word - D_004E30E4;
    if (D_004E3070 < 0) {
        D_004E2DA0.word = D_004E30E4;
        x1 = D_004E2DA0.word;
    }
    D_004E3070 = D_004E2DA4.word - D_004E30E8;
    if (D_004E3070 > 0) {
        D_004E2DA4.word = D_004E30E8;
        x2 = D_004E2DA4.word;
    }

    D_004E2DA8 = y;
    D_004E2DB0 = (unsigned char *)D_004E3078;
    D_004E2DB4 = *(unsigned char **)(D_004E2DB0 + (D_004E2DA8 << 2));
    D_004E3070 = (int)D_004E2DB4;
    if (D_004E3070 == 0) return;

    D_004E30B8 = (int)D_004E2DB4;
    D_004E2DB0 = (unsigned char *)D_004E3074;
    D_004E2DAC.word = D_004E2DA0.word;
    int orig_da4 = D_004E2DA4.word;
    D_004E2DA4.word = orig_da4 - D_004E2DA0.word;
    D_004E2DA0.word = y;
    D_004E2DA8 = orig_da4;
    D_004E30C0 = 0;
    D_004E2DA4.word = D_004E2DA4.word + 1;
    D_004E30B4 = D_004E2DA4.word;
    func_001522C0((unsigned char *)&D_004E2DA0, (unsigned char *)(D_004E2DB0 + (D_004E2DA0.word << 2)));

    D_004E309C = D_004E2DA0.word;
    D_004E2DA0.word = D_004E2DA0.word + D_004E2DAC.word;
    D_004E3090 = D_004E2DA0.word;

    while (true) {
        D_004E3070 = D_004E2DA8 - *(unsigned short *)(D_004E2DB4 + 8);
        if (D_004E3070 < 0) return;
        D_004E3070 = D_004E2DAC.word - *(unsigned short *)(D_004E2DB4 + 10);
        if (D_004E3070 <= 0) break;
        D_004E2DB4 = *(unsigned char **)D_004E2DB4;
        D_004E3070 = (int)D_004E2DB4;
        if (D_004E3070 == 0) return;
    }

    D_004E3070 = D_004E2DAC.word - *(unsigned short *)(D_004E2DB4 + 8);
    if (D_004E3070 >= 0) {
        D_004E3070 = D_004E2DA8 - *(unsigned short *)(D_004E2DB4 + 10);
        if (D_004E3070 <= 0) {
            D_004E2DA0.bytes[0] = (unsigned char)code;
            D_004E2DA0.bytes[1] = D_004E2DA0.bytes[0];
            D_004E2DA8 = D_004E30B4;
            D_004E2DA0.word <<= 16;
            D_004E3070 = D_004E2DA8 - 128;
            D_004E2DAC.word = D_004E2DA8;
            D_004E2DAC.word &= 0x7F;
            if (D_004E3070 >= 0) {
                D_004E2DAC.bytes[0] |= 0x80;
            }

            D_004E2DA0.bytes[0] = (unsigned char)code;
            D_004E2DB4 = (unsigned char *)D_004E3090;
            D_004E2DA0.bytes[1] = D_004E2DA0.bytes[0];
            D_004E2DA4.word = (int)D_004E2DB4;
            D_004E2DA4.word &= 3;
            D_004E2DA4.bytes[0] |= (unsigned char)D_00390B30[D_004E2DAC.word];
            void (*proc)() = D_0038FF30[D_004E2DA4.word];
            proc();

            if (D_004E30C0 == 1) {
                goto advance_loop;
            }
            if (D_004E30C0 == 0) return;
            func_118de0(D_00491180);
            func_0011a498(buf1, D_004911B0, D_004E30C0);
            func_118de0(buf1);
        }
    }
    D_004E30B8 = (int)D_004E2DB4;
    goto loop_body;

advance_loop:
    while (true) {
        D_004E2DA4.word = D_004E30B8;
        D_004E2DA4.ptr = *(unsigned char **)D_004E2DA4.ptr;
        D_004E3070 = D_004E2DA4.word;
        if (D_004E3070 == 0) return;
        D_004E30B8 = D_004E2DA4.word;
        D_004E30C0 = 0;

loop_body:
        D_004E2DAC.word = x2;
        D_004E2DB4 = (unsigned char *)x1;
        D_004E2DA4.word = D_004E30B8;
        D_004E2DA8 = D_004E30B4;

        unsigned short *p8 = (unsigned short *)(D_004E2DA4.ptr + 8);
        unsigned short *p10 = (unsigned short *)(D_004E2DA4.ptr + 10);

        D_004E3070 = D_004E2DAC.word - *p8;
        if (D_004E3070 < 0) return;

        D_004E3070 = (int)D_004E2DB4 - *p10;
        if (D_004E3070 > 0) continue;

        D_004E2DA0.word = 0;
        D_004E3070 = (int)D_004E2DB4 - *p8;
        if (D_004E3070 < 0) {
            D_004E2DA0.word = *p8;
            D_004E2DA0.word -= (int)D_004E2DB4;
            D_004E2DA8 -= D_004E2DA0.word;
        }
        D_004E30C8 = D_004E2DA0.word;

        D_004E3070 = D_004E2DAC.word - *p10;
        if (D_004E3070 > 0) {
            D_004E2DA0.word = D_004E2DAC.word;
            D_004E30C0 = 1;
            D_004E2DA0.word -= *p10;
            D_004E2DA8 -= D_004E2DA0.word;
        }

        D_004E2DA0.bytes[0] = (unsigned char)code;
        D_004E2DA0.bytes[1] = D_004E2DA0.bytes[0];
        D_004E2DB4 = (unsigned char *)D_004E3090;
        D_004E3070 = D_004E2DA8 - 128;
        D_004E2DAC.word = D_004E2DA8;
        D_004E2DAC.word &= 0x7F;
        D_004E2DA0.word <<= 16;
        if (D_004E3070 >= 0) {
            D_004E2DAC.bytes[0] |= 0x80;
        }

        D_004E2DB4 = D_004E2DB4 + D_004E30C8;
        D_004E2DA0.bytes[0] = (unsigned char)code;
        D_004E2DA0.bytes[1] = D_004E2DA0.bytes[0];
        D_004E2DA4.word = (int)D_004E2DB4;
        D_004E2DA4.word &= 3;
        D_004E2DA4.bytes[0] |= (unsigned char)D_00390B30[D_004E2DAC.word];
        void (*proc)() = D_0038FF30[D_004E2DA4.word];
        proc();

        if (D_004E30C0 == 1) continue;
        if (D_004E30C0 == 0) return;

        func_118de0(D_00491180);
        func_0011a498(buf2, D_004911B0, D_004E30C0);
        func_118de0(buf2);
        return;
    }
}
}
