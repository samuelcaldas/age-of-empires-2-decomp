#pragma exceptions off

union StagingWord { unsigned char bytes[4]; int word; };
union CounterWord { unsigned char bytes[4]; int word; };

extern "C" {
extern StagingWord D_004E2DA0;
extern CounterWord D_004E2DA8;
extern int D_0038FB10[8];
extern int D_004E3070;
extern int D_004E3074;
extern int D_004E3078;
extern int D_004E307C;
extern int D_004E3098;
extern int D_004E30BC;
extern int D_004E30D4;
extern int D_004E30D8;
extern int D_004E30DC;
extern int D_004E30E0;
extern int D_004E30E4;
extern int D_004E30E8;
extern int D_004E30F0;
extern int D_004E30F4;
extern int D_004E30F8;

void func_0017dbd0(int a0, int a1, int a2, int a3) {
    D_004E2DA0.word = a0;
    D_0038FB10[0] = D_004E2DA0.word;
    D_0038FB10[2] = D_004E2DA0.word;
    D_004E2DA0.word = a1;
    D_0038FB10[4] = D_004E2DA0.word;
    D_0038FB10[6] = D_004E2DA0.word;
    D_004E2DA0.word = a2;
    D_0038FB10[1] = D_004E2DA0.word;
    D_0038FB10[3] = D_004E2DA0.word;
    D_004E2DA0.word = a3;
    D_0038FB10[5] = D_004E2DA0.word;
    D_0038FB10[7] = D_004E2DA0.word;
}

void func_0017dc40(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    D_004E2DA0.word = a0;
    D_004E3074 = D_004E2DA0.word;
    D_004E2DA0.word = a1;
    D_004E3078 = D_004E2DA0.word;
    D_004E2DA0.word = a2;
    D_004E307C = D_004E2DA0.word;
    D_004E2DA0.word = t0;
    D_004E30DC = D_004E2DA0.word;
    D_004E2DA0.word = t2;
    D_004E30E0 = D_004E2DA0.word;
    D_004E2DA0.word = a3;
    D_004E30E4 = D_004E2DA0.word;
    D_004E2DA0.word = t1;
    D_004E30E8 = D_004E2DA0.word;
}

void func_0017dca0(int a0) {
    D_004E2DA0.word = a0;
    unsigned char b = D_004E2DA0.bytes[0];
    unsigned char *p = (unsigned char *)&D_004E2DA0;
    D_004E2DA8.bytes[0] = b;
    D_004E2DA0.bytes[1] = b;
    unsigned char tmp = p[0];
    p[0] = p[3];
    p[3] = tmp;
    p[2] = p[1];
    b = D_004E2DA8.bytes[0];
    D_004E2DA0.bytes[0] = b;
    D_004E2DA0.bytes[1] = b;
    int val = D_004E2DA0.word;
    D_004E30BC = val;
    D_004E30D4 = val;
    D_004E30D8 = val;
}

int func_0017dcf0() {
    D_004E2DA0.word = D_004E30BC;
    D_004E2DA0.word = D_004E2DA0.bytes[0];
    return D_004E2DA0.word;
}

void func_0017dd10(int a0, int a1) {
    D_004E2DA0.word = a0;
    unsigned char b = D_004E2DA0.bytes[0];
    unsigned char *p = (unsigned char *)&D_004E2DA0;
    D_004E2DA8.bytes[0] = b;
    D_004E2DA0.bytes[1] = b;
    unsigned char tmp = p[0];
    p[0] = p[3];
    p[3] = tmp;
    p[2] = p[1];
    b = D_004E2DA8.bytes[0];
    D_004E2DA0.bytes[0] = b;
    D_004E2DA0.bytes[1] = b;
    D_004E30F0 = D_004E2DA0.word;
    D_004E2DA0.word = a1;
    b = D_004E2DA0.bytes[0];
    D_004E2DA8.bytes[0] = b;
    D_004E2DA0.bytes[1] = b;
    tmp = p[0];
    p[0] = p[3];
    p[3] = tmp;
    p[2] = p[1];
    b = D_004E2DA8.bytes[0];
    D_004E2DA0.bytes[0] = b;
    D_004E2DA0.bytes[1] = b;
    D_004E30F4 = D_004E2DA0.word;
}

void func_0017dd90(int a0, int a1) {
    D_004E2DA0.word = 0;
    if (a0 != 0) {
        D_004E2DA0.word |= 1;
    }
    D_004E3070 = a1;
    if (a1 != 0) {
        D_004E2DA0.word |= 2;
    }
    D_004E30F8 = D_004E2DA0.word;
}

void func_0017ddd0(int a0) {
    D_004E2DA0.word = a0;
    D_004E3098 = D_004E2DA0.word;
}
}
