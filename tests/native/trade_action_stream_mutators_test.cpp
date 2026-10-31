#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

union Buffer4 {
    unsigned char b[4];
    int w;
    unsigned int u;
};

extern "C" {
    extern unsigned char *D_004E2DB0;
    extern unsigned char *D_004E2DB4;
    extern Buffer4 D_004E2DA0;
    extern int D_004E2DA4;

    void func_001522C0(unsigned char *buf, unsigned char *src) {
        memcpy(buf, src, 4);
    }

    void func_0015A1D0();
    void func_0015A210();
    void func_0015A280();
    void func_0015A2F0();
    void func_0015A380();
    void func_0015A410();
    void func_0015A4B0();
    void func_0015A550();
    void func_0015A630();
}

Buffer4 D_004E2DA0;
unsigned char *D_004E2DB0 = NULL;
unsigned char *D_004E2DB4 = NULL;
int D_004E2DA4 = 0;

static void reset_state(unsigned char *in_buf, unsigned char *out_buf, int len, int mask) {
    memset(out_buf, 0, len);
    D_004E2DB0 = in_buf;
    D_004E2DB4 = out_buf;
    D_004E2DA4 = mask;
    D_004E2DA0.w = 0;
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int test_case = atoi(argv[1]);
    unsigned char in[16] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80 };
    unsigned char out[16];

    switch (test_case) {
    case 0: {
        reset_state(in, out, sizeof(out), 0x01);
        func_0015A1D0();
        assert(D_004E2DB0 == in + 1);
        assert(D_004E2DB4 == out + 1);
        assert(out[0] == (0x10 | 0x01));
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        reset_state(in, out, sizeof(out), 0x02);
        func_0015A210();
        assert(D_004E2DB0 == in + 2);
        assert(D_004E2DB4 == out + 2);
        assert(out[0] == (0x10 | 0x02));
        assert(out[1] == 0x20);
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        reset_state(in, out, sizeof(out), 0x04);
        func_0015A280();
        assert(D_004E2DB0 == in + 2);
        assert(D_004E2DB4 == out + 2);
        assert(out[0] == (0x10 | 0x04));
        assert(out[1] == 0x20);
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        reset_state(in, out, sizeof(out), 0x08);
        func_0015A2F0();
        assert(D_004E2DB0 == in + 3);
        assert(D_004E2DB4 == out + 3);
        assert(out[0] == (0x10 | 0x08));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        printf("CASE 3 PASSED\n");
        return 0;
    }
    case 4: {
        reset_state(in, out, sizeof(out), 0x10);
        func_0015A380();
        assert(D_004E2DB0 == in + 3);
        assert(D_004E2DB4 == out + 3);
        assert(out[0] == (0x10 | 0x10));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        printf("CASE 4 PASSED\n");
        return 0;
    }
    case 5: {
        reset_state(in, out, sizeof(out), 0x01);
        func_0015A410();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        assert(out[0] == (0x10 | 0x01));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        assert(out[3] == 0x40);
        printf("CASE 5 PASSED\n");
        return 0;
    }
    case 6: {
        reset_state(in, out, sizeof(out), 0x02);
        func_0015A4B0();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        assert(out[0] == (0x10 | 0x02));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        assert(out[3] == 0x40);
        printf("CASE 6 PASSED\n");
        return 0;
    }
    case 7: {
        reset_state(in, out, sizeof(out), 0x01);
        func_0015A550();
        assert(D_004E2DB0 == in + 5);
        assert(D_004E2DB4 == out + 5);
        assert(out[0] == (0x10 | 0x01));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        assert(out[3] == 0x40);
        assert(out[4] == (0x50 | 0x01));
        printf("CASE 7 PASSED\n");
        return 0;
    }
    case 8: {
        reset_state(in, out, sizeof(out), 0x02);
        func_0015A630();
        assert(D_004E2DB0 == in + 5);
        assert(D_004E2DB4 == out + 5);
        assert(out[0] == (0x10 | 0x02));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        assert(out[3] == 0x40);
        assert(out[4] == (0x50 | 0x02));
        printf("CASE 8 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
