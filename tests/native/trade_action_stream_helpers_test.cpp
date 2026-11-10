#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

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

    void func_0017DBD0(int a0, int a1, int a2, int a3);
    void func_0017DC40(int a0, int a1, int a2, int a3, int t0, int t1, int t2);
    void func_0017DCA0(int a0);
    int func_0017DCF0();
    void func_0017DD10(int a0, int a1);
    void func_0017DD90(int a0, int a1);
    void func_0017DDD0(int a0);
}

StagingWord D_004E2DA0;
CounterWord D_004E2DA8;
int D_0038FB10[8];
int D_004E3070;
int D_004E3074;
int D_004E3078;
int D_004E307C;
int D_004E3098;
int D_004E30BC;
int D_004E30D4;
int D_004E30D8;
int D_004E30DC;
int D_004E30E0;
int D_004E30E4;
int D_004E30E8;
int D_004E30F0;
int D_004E30F4;
int D_004E30F8;

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int test_case = atoi(argv[1]);

    switch (test_case) {
    case 0: {
        // func_0017DBD0: distributes 4 words across D_0038FB10
        memset(D_0038FB10, 0, sizeof(D_0038FB10));
        func_0017DBD0(10, 20, 30, 40);
        assert(D_0038FB10[0] == 10 && D_0038FB10[2] == 10);
        assert(D_0038FB10[4] == 20 && D_0038FB10[6] == 20);
        assert(D_0038FB10[1] == 30 && D_0038FB10[3] == 30);
        assert(D_0038FB10[5] == 40 && D_0038FB10[7] == 40);
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        // func_0017DC40: sets 7 fields
        func_0017DC40(1, 2, 3, 4, 5, 6, 7);
        assert(D_004E3074 == 1);
        assert(D_004E3078 == 2);
        assert(D_004E307C == 3);
        assert(D_004E30DC == 5);
        assert(D_004E30E0 == 7);
        assert(D_004E30E4 == 4);
        assert(D_004E30E8 == 6);
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        // func_0017DCA0: byte shuffle
        func_0017DCA0(0x12345678);
        assert(D_004E30BC == D_004E30D4);
        assert(D_004E30BC == D_004E30D8);
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        // func_0017DCF0: reads byte 0 of D_004E30BC
        D_004E30BC = 0x12345678;
        int res = func_0017DCF0();
        assert(res == 0x78);
        printf("CASE 3 PASSED\n");
        return 0;
    }
    case 4: {
        // func_0017DD10: double byte shuffle into D_004E30F0 and D_004E30F4
        func_0017DD10(0x11223344, 0x55667788);
        assert(D_004E30F0 != 0);
        assert(D_004E30F4 != 0);
        printf("CASE 4 PASSED\n");
        return 0;
    }
    case 5: {
        // func_0017DD90: bitmask flags
        func_0017DD90(1, 1);
        assert(D_004E3070 == 1);
        assert(D_004E30F8 == 3);
        func_0017DD90(1, 0);
        assert(D_004E3070 == 0);
        assert(D_004E30F8 == 1);
        func_0017DD90(0, 1);
        assert(D_004E3070 == 1);
        assert(D_004E30F8 == 2);
        func_0017DD90(0, 0);
        assert(D_004E3070 == 0);
        assert(D_004E30F8 == 0);
        printf("CASE 5 PASSED\n");
        return 0;
    }
    case 6: {
        // func_0017DDD0: stores to D_004E3098
        func_0017DDD0(0xDEADBEEF);
        assert(D_004E3098 == (int)0xDEADBEEF);
        printf("CASE 6 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
