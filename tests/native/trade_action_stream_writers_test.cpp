#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

extern "C" {
    extern unsigned char D_004E2DA0[4];
    extern unsigned char *D_004E2DB0;
    extern unsigned char *D_004E2DB4;

    void func_001522C0(unsigned char *a0, unsigned char *a1) {
        memcpy(a0, a1, 4);
    }

    void func_00152B10();
    void func_00152C10();
    void func_00152D10();
    void func_00152E10();
}

unsigned char D_004E2DA0[4];
unsigned char *D_004E2DB0 = NULL;
unsigned char *D_004E2DB4 = NULL;

static void reset_state(unsigned char *in_buf, unsigned char *out_buf, int len) {
    memset(out_buf, 0, len);
    memset(D_004E2DA0, 0, sizeof(D_004E2DA0));
    D_004E2DB0 = in_buf;
    D_004E2DB4 = out_buf;
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int test_case = atoi(argv[1]);
    unsigned char in[32] = {
        0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88
    };
    unsigned char out[32];

    switch (test_case) {
    case 0: {
        // func_00152B10: copies 4 bytes, then stages from in+4, advances in by 2, outputs stage[0..1]
        reset_state(in, out, sizeof(out));
        func_00152B10();
        assert(D_004E2DB0 == in + 6);
        assert(D_004E2DB4 == out + 6);
        for (int i = 0; i < 6; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        // func_00152C10: copies 4 bytes, then stages from in+4, advances in by 2, outputs stage[0..1]
        reset_state(in, out, sizeof(out));
        func_00152C10();
        assert(D_004E2DB0 == in + 6);
        assert(D_004E2DB4 == out + 6);
        for (int i = 0; i < 6; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        // func_00152D10: copies 4 bytes, then stages from in+4, advances in by 2, outputs stage[0..1]
        reset_state(in, out, sizeof(out));
        func_00152D10();
        assert(D_004E2DB0 == in + 6);
        assert(D_004E2DB4 == out + 6);
        for (int i = 0; i < 6; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        // func_00152E10: copies 4 bytes, then stages from in+4, advances in by 3, outputs stage[0..2]
        reset_state(in, out, sizeof(out));
        func_00152E10();
        assert(D_004E2DB0 == in + 7);
        assert(D_004E2DB4 == out + 7);
        for (int i = 0; i < 7; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 3 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
