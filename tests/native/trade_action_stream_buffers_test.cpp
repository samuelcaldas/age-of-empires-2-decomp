#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

extern "C" {
    extern unsigned char D_004E2DA0[4];
    extern int D_004E2DA8;
    extern unsigned char *D_004E2DB0;
    extern unsigned char *D_004E2DB4;

    void func_001522C0(unsigned char *a0, unsigned char *a1) {
        memcpy(a0, a1, 4);
    }

    void func_00152F30();
    void func_00153050();
    void func_00153170();
    void func_00153290();
    void func_00153350();
}

unsigned char D_004E2DA0[4];
int D_004E2DA8 = 0;
unsigned char *D_004E2DB0 = NULL;
unsigned char *D_004E2DB4 = NULL;

static void reset_state(unsigned char *in_buf, unsigned char *out_buf, int len) {
    memset(out_buf, 0, len);
    memset(D_004E2DA0, 0, sizeof(D_004E2DA0));
    D_004E2DA8 = 0;
    D_004E2DB0 = in_buf;
    D_004E2DB4 = out_buf;
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int test_case = atoi(argv[1]);
    unsigned char in[32] = {
        0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80,
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
        0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x01
    };
    unsigned char out[32];

    switch (test_case) {
    case 0: {
        // func_00152F30: copies 4 bytes, stages from in+4, advances in by 3, outputs stage[0..2]
        reset_state(in, out, sizeof(out));
        func_00152F30();
        assert(D_004E2DB0 == in + 7);
        assert(D_004E2DB4 == out + 7);
        for (int i = 0; i < 7; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        // func_00153050: copies 4 bytes, stages from in+4, advances in by 3, outputs stage[0..2]
        reset_state(in, out, sizeof(out));
        func_00153050();
        assert(D_004E2DB0 == in + 7);
        assert(D_004E2DB4 == out + 7);
        for (int i = 0; i < 7; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        // func_00153170: copies 4 bytes, stages from in+4, advances in by 3, outputs stage[0..2]
        reset_state(in, out, sizeof(out));
        func_00153170();
        assert(D_004E2DB0 == in + 7);
        assert(D_004E2DB4 == out + 7);
        for (int i = 0; i < 7; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        // func_00153290: 4-byte unrolled loop while (D_004E2DA8 -= 4) != 0
        reset_state(in, out, sizeof(out));
        D_004E2DA8 = 8;
        func_00153290();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB0 == in + 8);
        assert(D_004E2DB4 == out + 8);
        for (int i = 0; i < 8; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 3 PASSED\n");
        return 0;
    }
    case 4: {
        // func_00153350: 1 byte copy + 4-byte unrolled loop
        reset_state(in, out, sizeof(out));
        D_004E2DA8 = 9;
        func_00153350();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB0 == in + 9);
        assert(D_004E2DB4 == out + 9);
        for (int i = 0; i < 9; i++) {
            assert(out[i] == in[i]);
        }
        printf("CASE 4 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
