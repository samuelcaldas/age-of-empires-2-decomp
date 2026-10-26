#include <cassert>
#include <cstring>
#include <iostream>

static int c221b60_calls = 0;
static void *mock_ctx = (void *)0x9999;

static int c21df50_calls = 0;
static void *last_21df50_ctx = nullptr;
static int last_21df50_f1c = -1;
static int last_21df50_s1 = -1;
static int last_21df50_aligned_3c = -1;
static long long last_21df50_f38 = -1;

static int c223f50_calls = 0;

static int c21e370_calls = 0;
static int last_21e370_v0 = -1;
static int last_21e370_f1c = -1;
static int last_21e370_a3 = -1;
static int last_21e370_t0 = -1;
static int last_21e370_t1 = -1;
static int last_21e370_t2 = -1;
static int last_21e370_t3 = -1;

extern "C" {
int func_0021ACD0(void *arg0, void *arg1);
int func_0021AD70(void *self);
int func_0021AE10(void *self);

void *func_00221B60(int type) {
    c221b60_calls++;
    return mock_ctx;
}

void func_0021DF50(void *ctx, int a1, int f1c, int a3, int s1, int a5, int a6, int aligned_3c, long long f38) {
    c21df50_calls++;
    last_21df50_ctx = ctx;
    last_21df50_f1c = f1c;
    last_21df50_s1 = s1;
    last_21df50_aligned_3c = aligned_3c;
    last_21df50_f38 = f38;
}

void func_00223F50(void) {
    c223f50_calls++;
}

void func_0021E370(int a0, int v0, int f1c, int a3, int t0, int t1, int t2, int t3) {
    c21e370_calls++;
    last_21e370_v0 = v0;
    last_21e370_f1c = f1c;
    last_21e370_a3 = a3;
    last_21e370_t0 = t0;
    last_21e370_t1 = t1;
    last_21e370_t2 = t2;
    last_21e370_t3 = t3;
}
}

static void reset_mocks() {
    c221b60_calls = 0;
    c21df50_calls = 0;
    last_21df50_ctx = nullptr;
    last_21df50_f1c = -1;
    last_21df50_s1 = -1;
    last_21df50_aligned_3c = -1;
    last_21df50_f38 = -1;

    c223f50_calls = 0;

    c21e370_calls = 0;
    last_21e370_v0 = -1;
    last_21e370_f1c = -1;
    last_21e370_a3 = -1;
    last_21e370_t0 = -1;
    last_21e370_t1 = -1;
    last_21e370_t2 = -1;
    last_21e370_t3 = -1;
}

void test_case_21ACD0_setup_context() {
    reset_mocks();
    unsigned char obj0[0x100];
    unsigned char obj1[0x100];
    std::memset(obj0, 0, sizeof(obj0));
    std::memset(obj1, 0, sizeof(obj1));

    // Case: flags0 without 0x800 -> returns 0
    *(unsigned int *)(obj0 + 0x98) = 0;
    *(unsigned int *)(obj1 + 0x98) = 0;
    assert(func_0021ACD0(obj0, obj1) == 0);
    assert(c221b60_calls == 0);

    // Case: flags0 with 0x800, flags1 with 0x200 -> returns 0
    *(unsigned int *)(obj0 + 0x98) = 0x800;
    *(unsigned int *)(obj1 + 0x98) = 0x200;
    assert(func_0021ACD0(obj0, obj1) == 0);
    assert(c221b60_calls == 0);

    // Case: flags0 with 0x800, flags1 without 0x200 -> executes setup
    *(unsigned int *)(obj1 + 0x98) = 0;
    *(int *)(obj0 + 0x54) = 54;
    *(short *)(obj0 + 0x1C) = 12;
    *(int *)(obj0 + 0x3C) = 101; // (101 + 3) & ~3 = 104
    *(short *)(obj0 + 0x38) = 38;

    assert(func_0021ACD0(obj0, obj1) == 0);
    assert(c221b60_calls == 1);
    assert(c21df50_calls == 1);
    assert(last_21df50_ctx == mock_ctx);
    assert(last_21df50_f1c == 12);
    assert(last_21df50_s1 == 54);
    assert(last_21df50_aligned_3c == 104);
    assert((short)last_21df50_f38 == 38);
}

void test_case_21AD70_begin_frame() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    // Case: no 0x200 -> returns 0 immediately
    *(unsigned int *)(obj + 0x98) = 0;
    assert(func_0021AD70(obj) == 0);
    assert(c223f50_calls == 0);
    assert(c21e370_calls == 0);

    // Case: 0x200 active, no 0x800
    *(unsigned int *)(obj + 0x98) = 0x200;
    *(int *)(obj + 0x54) = 540;
    *(int *)(obj + 0x1C) = 10;
    *(int *)(obj + 0x3C) = 640;
    *(int *)(obj + 0x38) = 480;

    assert(func_0021AD70(obj) == 0);
    assert(c223f50_calls == 1);
    assert(c21e370_calls == 1);
    assert(last_21e370_v0 == 540);
    assert(last_21e370_f1c == 10);
    assert(last_21e370_a3 == 640);
    assert(last_21e370_t0 == 480);
    assert(last_21e370_t1 == 0x50000);
    assert(last_21e370_t2 == 2);
    assert(last_21e370_t3 == 2);

    // Case: both 0x200 and 0x800 active -> v0 becomes 0xA3000, t2/t3 become 0
    reset_mocks();
    *(unsigned int *)(obj + 0x98) = 0x200 | 0x800;
    assert(func_0021AD70(obj) == 0);
    assert(c21e370_calls == 1);
    assert(last_21e370_v0 == 0xA3000);
    assert(last_21e370_t2 == 0);
    assert(last_21e370_t3 == 0);
}

void test_case_21AE10_end_frame() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    // Case: no 0x200 -> returns 0
    *(unsigned int *)(obj + 0x98) = 0;
    assert(func_0021AE10(obj) == 0);
    assert(c223f50_calls == 0);
    assert(c21e370_calls == 0);

    // Case: 0x200 active
    *(unsigned int *)(obj + 0x98) = 0x200;
    *(int *)(obj + 0x1C) = 99;

    assert(func_0021AE10(obj) == 0);
    assert(c223f50_calls == 1);
    assert(c21e370_calls == 1);
    assert(last_21e370_v0 == 0);
    assert(last_21e370_f1c == 99);
    assert(last_21e370_a3 == 640);
    assert(last_21e370_t0 == 512);
    assert(last_21e370_t1 == 0x50000);
    assert(last_21e370_t2 == 2);
    assert(last_21e370_t3 == 2);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_21ACD0_setup_context();
    else if (c == 1) test_case_21AD70_begin_frame();
    else if (c == 2) test_case_21AE10_end_frame();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
