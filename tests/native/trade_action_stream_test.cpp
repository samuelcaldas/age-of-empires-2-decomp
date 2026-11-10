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

    void func_001522E0();
    void func_001522F0();
    void func_00152320();
    void func_00152380();
    void func_001523E0();
    void func_00152460();
    void func_001524E0();
    void func_00152590();
    void func_00152640();
    void func_001526F0();
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
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
        0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x01
    };
    unsigned char out[32];

    switch (test_case) {
    case 0: {
        // func_001522E0: no-op
        reset_state(in, out, sizeof(out));
        func_001522E0();
        assert(D_004E2DB0 == in);
        assert(D_004E2DB4 == out);
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        // func_001522F0: 1 byte copy
        reset_state(in, out, sizeof(out));
        func_001522F0();
        assert(D_004E2DB0 == in + 1);
        assert(D_004E2DB4 == out + 1);
        assert(out[0] == in[0]);
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        // func_00152320: stage 4 bytes, in += 2, out 2 bytes from stage
        reset_state(in, out, sizeof(out));
        func_00152320();
        assert(D_004E2DB0 == in + 2);
        assert(D_004E2DB4 == out + 2);
        assert(out[0] == in[0]);
        assert(out[1] == in[1]);
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        // func_00152380: stage 4 bytes, in += 2, out 2 bytes from stage
        reset_state(in, out, sizeof(out));
        func_00152380();
        assert(D_004E2DB0 == in + 2);
        assert(D_004E2DB4 == out + 2);
        assert(out[0] == in[0]);
        assert(out[1] == in[1]);
        printf("CASE 3 PASSED\n");
        return 0;
    }
    case 4: {
        // func_001523E0: stage 4 bytes, in += 3, out 3 bytes from stage
        reset_state(in, out, sizeof(out));
        func_001523E0();
        assert(D_004E2DB0 == in + 3);
        assert(D_004E2DB4 == out + 3);
        assert(out[0] == in[0]);
        assert(out[1] == in[1]);
        assert(out[2] == in[2]);
        printf("CASE 4 PASSED\n");
        return 0;
    }
    case 5: {
        // func_00152460: stage 4 bytes, in += 3, out 3 bytes from stage
        reset_state(in, out, sizeof(out));
        func_00152460();
        assert(D_004E2DB0 == in + 3);
        assert(D_004E2DB4 == out + 3);
        assert(out[0] == in[0]);
        assert(out[1] == in[1]);
        assert(out[2] == in[2]);
        printf("CASE 5 PASSED\n");
        return 0;
    }
    case 6: {
        // func_001524E0: 4 bytes copy
        reset_state(in, out, sizeof(out));
        func_001524E0();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        for (int i = 0; i < 4; i++) assert(out[i] == in[i]);
        printf("CASE 6 PASSED\n");
        return 0;
    }
    case 7: {
        // func_00152590: 4 bytes copy
        reset_state(in, out, sizeof(out));
        func_00152590();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        for (int i = 0; i < 4; i++) assert(out[i] == in[i]);
        printf("CASE 7 PASSED\n");
        return 0;
    }
    case 8: {
        // func_00152640: 4 bytes copy
        reset_state(in, out, sizeof(out));
        func_00152640();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        for (int i = 0; i < 4; i++) assert(out[i] == in[i]);
        printf("CASE 8 PASSED\n");
        return 0;
    }
    case 9: {
        // func_001526F0: 4 bytes copy
        reset_state(in, out, sizeof(out));
        func_001526F0();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        for (int i = 0; i < 4; i++) assert(out[i] == in[i]);
        printf("CASE 9 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
