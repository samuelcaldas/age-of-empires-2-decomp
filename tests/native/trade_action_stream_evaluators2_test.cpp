#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

union StreamStagingWord {
    unsigned char bytes[4];
    int word;
};

extern "C" {
    extern StreamStagingWord D_004E2DA0;
    extern int D_004E30A8;
    extern int D_004E30B0;
    extern unsigned char *D_004E2DB0;
    extern unsigned char *D_004E2DB4;

    void func_001522C0(unsigned char *destination, unsigned char *source) {
        memcpy(destination, source, 4);
    }

    void func_0015C920();
    void func_0015C9D0();
    void func_0015CAC0();
    void func_0015CBB0();
    void func_0015CC90();
    void func_0015CD90();
}

StreamStagingWord D_004E2DA0;
int D_004E30A8 = 0;
int D_004E30B0 = 0;
unsigned char *D_004E2DB0 = NULL;
unsigned char *D_004E2DB4 = NULL;

static void reset_state(unsigned char *in_buf, unsigned char *out_buf, int len, int and_mask, int or_mask) {
    memset(out_buf, 0, len);
    D_004E2DB0 = in_buf;
    D_004E2DB4 = out_buf;
    D_004E30A8 = and_mask;
    D_004E30B0 = or_mask;
    D_004E2DA0.word = 0;
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
        // func_0015C920: stage_masked_input(4, 0) + 4 stores
        reset_state(in, out, sizeof(out), 0x00FF00FF, 0x01000100);
        func_0015C920();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        assert(out[0] == (0x10 & 0xFF) | 0x00);
        assert(out[1] == (0x20 & 0x00) | 0x01);
        assert(out[2] == (0x30 & 0xFF) | 0x00);
        assert(out[3] == (0x40 & 0x00) | 0x01);
        printf("CASE 0 PASSED\n");
        return 0;
    }
    case 1: {
        // func_0015C9D0: stage_masked_input(3, -1) + 3 stores, then byte 0 + 1 store
        // note: stage_masked_input with -1 source_offset needs in >= 1
        reset_state(in + 1, out, sizeof(out), 0x00FF00FF, 0x02000200);
        func_0015C9D0();
        assert(D_004E2DB0 == in + 1 + 3 + 1);
        assert(D_004E2DB4 == out + 4);
        printf("CASE 1 PASSED\n");
        return 0;
    }
    case 2: {
        // func_0015CAC0: stage_masked_input(2, 0) + 2 stores, stage_masked_input(2, 0) + 2 stores
        reset_state(in, out, sizeof(out), 0x00FF00FF, 0x04000400);
        func_0015CAC0();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        printf("CASE 2 PASSED\n");
        return 0;
    }
    case 3: {
        // func_0015CBB0: byte 1 + 1 store, stage_masked_input(3, 0) + 3 stores
        reset_state(in, out, sizeof(out), 0x00FF00FF, 0x08000800);
        func_0015CBB0();
        assert(D_004E2DB0 == in + 4);
        assert(D_004E2DB4 == out + 4);
        printf("CASE 3 PASSED\n");
        return 0;
    }
    case 4: {
        // func_0015CC90: stage_masked_input(4, 0) + 4 stores, then byte 0 + 1 store
        reset_state(in, out, sizeof(out), 0x00FF00FF, 0x10001000);
        func_0015CC90();
        assert(D_004E2DB0 == in + 5);
        assert(D_004E2DB4 == out + 5);
        printf("CASE 4 PASSED\n");
        return 0;
    }
    case 5: {
        // func_0015CD90: stage_masked_input(3, -1) + 3 stores, stage_masked_input(2, 0) + 2 stores
        reset_state(in + 1, out, sizeof(out), 0x00FF00FF, 0x20002000);
        func_0015CD90();
        assert(D_004E2DB0 == in + 1 + 3 + 2);
        assert(D_004E2DB4 == out + 5);
        printf("CASE 5 PASSED\n");
        return 0;
    }
    default:
        return 1;
    }
}
