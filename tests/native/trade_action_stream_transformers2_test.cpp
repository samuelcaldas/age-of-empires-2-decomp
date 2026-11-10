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
    extern int D_004E2DA8;
    extern Buffer4 D_004E2DA0;
    extern int D_004E2DA4;

    void func_001522C0(unsigned char *buf, unsigned char *src) {
        memcpy(buf, src, 4);
    }

    void func_0015B0E0();
    void func_0015B1E0();
    void func_0015B300();
    void func_0015B430();
    void func_0015B530();
}

Buffer4 D_004E2DA0;
unsigned char *D_004E2DB0 = NULL;
unsigned char *D_004E2DB4 = NULL;
int D_004E2DA8 = 0;
int D_004E2DA4 = 0;

static void reset_state(unsigned char *in_buf, unsigned char *out_buf, int len, int count, int mask) {
    memset(out_buf, 0, len);
    D_004E2DB0 = in_buf;
    D_004E2DB4 = out_buf;
    D_004E2DA8 = count;
    D_004E2DA4 = mask;
    D_004E2DA0.w = 0;
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
        // func_0015B0E0: 1 byte lead, then loop 4 bytes
        reset_state(in, out, sizeof(out), 5, 0x01);
        func_0015B0E0();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB0 == in + 5);
        assert(D_004E2DB4 == out + 5);
        assert(out[0] == (0x10 | 0x01));
        assert(out[1] == (0x20 | 0x01));
        assert(out[2] == 0x30);
        assert(out[3] == 0x40);
        assert(out[4] == 0x50);
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        // func_0015B1E0: 2 bytes lead, then loop 4 bytes
        reset_state(in, out, sizeof(out), 6, 0x02);
        func_0015B1E0();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB0 == in + 6);
        assert(D_004E2DB4 == out + 6);
        assert(out[0] == (0x10 | 0x02));
        assert(out[1] == 0x20);
        assert(out[2] == (0x30 | 0x02));
        assert(out[3] == 0x40);
        assert(out[4] == 0x50);
        assert(out[5] == 0x60);
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        // func_0015B300: 3 bytes lead, then loop 4 bytes
        reset_state(in, out, sizeof(out), 7, 0x04);
        func_0015B300();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB0 == in + 7);
        assert(D_004E2DB4 == out + 7);
        assert(out[0] == (0x10 | 0x04));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        assert(out[3] == (0x40 | 0x04));
        assert(out[4] == 0x50);
        assert(out[5] == 0x60);
        assert(out[6] == 0x70);
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        // func_0015B430: loop 4 bytes, then 1 byte trail
        reset_state(in, out, sizeof(out), 5, 0x08);
        func_0015B430();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB0 == in + 5);
        assert(D_004E2DB4 == out + 5);
        assert(out[0] == (0x10 | 0x08));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        assert(out[3] == 0x40);
        assert(out[4] == (0x50 | 0x08));
        printf("CASE 3 PASSED\n");
        return 0;
    }
    case 4: {
        // func_0015B530: 1 byte lead, loop 4 bytes, 1 byte trail
        reset_state(in, out, sizeof(out), 6, 0x10);
        func_0015B530();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB0 == in + 6);
        assert(D_004E2DB4 == out + 6);
        assert(out[0] == (0x10 | 0x10));
        assert(out[1] == (0x20 | 0x10));
        assert(out[2] == 0x30);
        assert(out[3] == 0x40);
        assert(out[4] == 0x50);
        assert(out[5] == (0x60 | 0x10));
        printf("CASE 4 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
