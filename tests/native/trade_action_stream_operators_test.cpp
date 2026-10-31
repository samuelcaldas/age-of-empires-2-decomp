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
    extern int D_004E30A8;
    extern int D_004E30B0;

    void func_001522C0(unsigned char *buf, unsigned char *src) {
        memcpy(buf, src, 4);
    }

    void func_0015C2F0();
    void func_0015C490();
    void func_0015C4E0();
    void func_0015C530();
    void func_0015C5B0();
    void func_0015C640();
    void func_0015C6E0();
    void func_0015C780();
    void func_0015C850();
}

Buffer4 D_004E2DA0;
unsigned char *D_004E2DB0 = NULL;
unsigned char *D_004E2DB4 = NULL;
int D_004E2DA8 = 0;
int D_004E2DA4 = 0;
int D_004E30A8 = 0;
int D_004E30B0 = 0;

static void reset_state(unsigned char *in_buf, unsigned char *out_buf, int len, int count, int mask, int and_mask, int or_mask) {
    memset(out_buf, 0, len);
    D_004E2DB0 = in_buf;
    D_004E2DB4 = out_buf;
    D_004E2DA8 = count;
    D_004E2DA4 = mask;
    D_004E30A8 = and_mask;
    D_004E30B0 = or_mask;
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
        // func_0015C2F0: 3 bytes lead + 4 bytes stream loop + 3 bytes trail
        reset_state(in, out, sizeof(out), 10, 0x01, 0, 0);
        func_0015C2F0();
        assert(D_004E2DA8 == 0);
        assert(D_004E2DB0 == in + 10);
        assert(D_004E2DB4 == out + 10);
        assert(out[0] == (0x10 | 0x01));
        assert(out[1] == 0x20);
        assert(out[2] == 0x30);
        assert(out[3] == (0x40 | 0x01));
        assert(out[4] == 0x50);
        assert(out[5] == 0x60);
        assert(out[6] == 0x70);
        assert(out[7] == (0x80 | 0x01));
        assert(out[8] == 0x11);
        assert(out[9] == 0x22);
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        // func_0015C490: 1 byte lead into byte 0, and/or mask, write byte 0
        reset_state(in, out, sizeof(out), 0, 0, 0x000000FF, 0x00000002);
        func_0015C490();
        assert(D_004E2DB0 == in + 1);
        assert(D_004E2DB4 == out + 1);
        assert(out[0] == (0x10 | 0x02));
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        // func_0015C4E0: 1 byte lead into byte 1, and/or mask, write byte 1
        reset_state(in, out, sizeof(out), 0, 0, 0x0000FF00, 0x00000400);
        func_0015C4E0();
        assert(D_004E2DB0 == in + 1);
        assert(D_004E2DB4 == out + 1);
        assert(out[0] == (0x10 | 0x04));
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        // func_0015C530: 2 bytes, and/or mask, write bytes 0 and 1
        reset_state(in, out, sizeof(out), 0, 0, 0x0000FFFF, 0x00000101);
        func_0015C530();
        assert(D_004E2DB0 == in + 2);
        assert(D_004E2DB4 == out + 2);
        assert(out[0] == (0x10 | 0x01));
        assert(out[1] == (0x20 | 0x01));
        printf("CASE 3 PASSED\n");
        return 0;
    }
    case 4: {
        // func_0015C5B0: read in-1, and/or mask, shift 8, write bytes 0 and 1
        reset_state(in + 1, out, sizeof(out), 0, 0, 0x00FFFF00, 0x00000100);
        func_0015C5B0();
        assert(D_004E2DB0 == in + 3);
        assert(D_004E2DB4 == out + 2);
        assert(out[0] == (0x20 | 0x01));
        assert(out[1] == 0x30);
        printf("CASE 4 PASSED\n");
        return 0;
    }
    case 5: {
        // func_0015C640: 3 bytes, and/or mask, write bytes 0, 1, 2
        reset_state(in, out, sizeof(out), 0, 0, 0x00FFFFFF, 0x00020000);
        func_0015C640();
        assert(D_004E2DB0 == in + 3);
        assert(D_004E2DB4 == out + 3);
        assert(out[0] == 0x10);
        assert(out[1] == 0x20);
        assert(out[2] == (0x30 | 0x02));
        printf("CASE 5 PASSED\n");
        return 0;
    }
    case 6: {
        // func_0015C6E0: read in-1, 3 bytes, write bytes 1, 2, 3
        reset_state(in + 1, out, sizeof(out), 0, 0, 0xFFFFFF00, 0x01000000);
        func_0015C6E0();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 3);
        assert(out[0] == 0x20);
        assert(out[1] == 0x30);
        assert(out[2] == (0x40 | 0x01));
        printf("CASE 6 PASSED\n");
        return 0;
    }
    case 7: {
        // func_0015C780: 2 bytes then 1 byte
        reset_state(in, out, sizeof(out), 0, 0, 0x0000FFFF, 0x00000101);
        func_0015C780();
        assert(D_004E2DB0 == in + 3);
        assert(D_004E2DB4 == out + 3);
        assert(out[0] == (0x10 | 0x01));
        assert(out[1] == (0x20 | 0x01));
        assert(out[2] == (0x30 | 0x01));
        printf("CASE 7 PASSED\n");
        return 0;
    }
    case 8: {
        // func_0015C850: 1 byte then 2 bytes
        reset_state(in, out, sizeof(out), 0, 0, 0x0000FFFF, 0x00000202);
        func_0015C850();
        assert(D_004E2DB0 == in + 3);
        assert(D_004E2DB4 == out + 3);
        assert(out[0] == (0x10 | 0x02));
        assert(out[1] == (0x20 | 0x02));
        assert(out[2] == (0x30 | 0x02));
        printf("CASE 8 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
