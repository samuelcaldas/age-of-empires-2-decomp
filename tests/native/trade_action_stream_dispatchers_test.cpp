#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

extern "C" {
    extern unsigned char D_004E2DA0[4];
    extern int D_004E2DA8;
    extern unsigned char *D_004E2DB4;

    void func_00159500();
    void func_00159580();
    void func_00159620();
    void func_001596E0();
    void func_001597B0();
    void func_00159850();
    void func_00159900();
    void func_001599D0();
}

unsigned char D_004E2DA0[4] = { 0x11, 0x22, 0x33, 0x44 };
int D_004E2DA8 = 0;
unsigned char *D_004E2DB4 = NULL;

static void reset_state(unsigned char *out_buf, int len) {
    memset(out_buf, 0, len);
    D_004E2DB4 = out_buf;
    D_004E2DA0[0] = 0xAA;
    D_004E2DA0[1] = 0xBB;
    D_004E2DA0[2] = 0xCC;
    D_004E2DA0[3] = 0xDD;
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int test_case = atoi(argv[1]);
    unsigned char buf[64];

    switch (test_case) {
    case 0: {
        // Test func_00159500: copies 4 bytes per iteration
        reset_state(buf, sizeof(buf));
        D_004E2DA8 = 8;
        func_00159500();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB4 == buf + 8);
        assert(buf[0] == 0xAA && buf[1] == 0xBB && buf[2] == 0xCC && buf[3] == 0xDD);
        assert(buf[4] == 0xAA && buf[5] == 0xBB && buf[6] == 0xCC && buf[7] == 0xDD);
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        // Test func_00159580: writes byte 1 then loops 4 bytes
        reset_state(buf, sizeof(buf));
        D_004E2DA8 = 5;
        func_00159580();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB4 == buf + 5);
        assert(buf[0] == 0xBB);
        assert(buf[1] == 0xAA && buf[2] == 0xBB && buf[3] == 0xCC && buf[4] == 0xDD);
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        // Test func_00159620: writes bytes 0, 1 then loops 4 bytes
        reset_state(buf, sizeof(buf));
        D_004E2DA8 = 6;
        func_00159620();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB4 == buf + 6);
        assert(buf[0] == 0xAA && buf[1] == 0xBB);
        assert(buf[2] == 0xAA && buf[3] == 0xBB && buf[4] == 0xCC && buf[5] == 0xDD);
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        // Test func_001596E0: writes bytes 0, 1, 2 then loops 4 bytes
        reset_state(buf, sizeof(buf));
        D_004E2DA8 = 7;
        func_001596E0();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB4 == buf + 7);
        assert(buf[0] == 0xAA && buf[1] == 0xBB && buf[2] == 0xCC);
        assert(buf[3] == 0xAA && buf[4] == 0xBB && buf[5] == 0xCC && buf[6] == 0xDD);
        printf("CASE 3 PASSED\n");
        return 0;
    }
    case 4: {
        // Test func_001597B0: loops then writes byte 0
        reset_state(buf, sizeof(buf));
        D_004E2DA8 = 5;
        func_001597B0();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB4 == buf + 5);
        assert(buf[0] == 0xAA && buf[1] == 0xBB && buf[2] == 0xCC && buf[3] == 0xDD);
        assert(buf[4] == 0xAA);
        printf("CASE 4 PASSED\n");
        return 0;
    }
    case 5: {
        // Test func_001599D0: writes bytes 1, 0, 1, loops, then writes byte 0
        reset_state(buf, sizeof(buf));
        D_004E2DA8 = 8;
        func_001599D0();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB4 == buf + 8);
        assert(buf[0] == 0xBB && buf[1] == 0xAA && buf[2] == 0xBB);
        assert(buf[3] == 0xAA && buf[4] == 0xBB && buf[5] == 0xCC && buf[6] == 0xDD);
        assert(buf[7] == 0xAA);
        printf("CASE 5 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
