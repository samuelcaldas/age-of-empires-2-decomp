#include <cassert>
#include <cstring>
#include <iostream>

static int c221b60_calls = 0;
static int last_221b60_type = -1;
static void *mock_ctx = (void *)0x8888;

static int c21d2c0_calls = 0;
static int c21cfb0_calls = 0;
static int c21a680_calls = 0;
static int c21c410_calls = 0;
static int c21c710_calls = 0;

extern "C" {
int func_0021A960(void *self, const int *rect1, void *arg2, const int *rect2, int flags_t0, int arg5);

void *func_00221B60(int type) {
    c221b60_calls++;
    last_221b60_type = type;
    return mock_ctx;
}

void func_0021C610(void *ctx, int mode) {}
void func_0021C4A0(void *ctx, int mode) {}

void func_0021D2C0(void *ctx, int a1, unsigned long long a2, const int *rect, int a4, int a5) {
    c21d2c0_calls++;
}

void func_0021C410(void *ctx, int mode) {
    c21c410_calls++;
}

void func_0021A680(void *arg) {
    c21a680_calls++;
}

void func_0021C1D0(void *ctx, int a1, int a2, int a3, int a4, int a5) {}

void func_0021CFB0(void *ctx, unsigned long long val_20, int s0, int self_28, const int *rect1, const int *rect2, int a6, int a7) {
    c21cfb0_calls++;
}

void func_0021C710(void *ctx, unsigned long long val) {
    c21c710_calls++;
}

void func_0021BFD0(void *ctx, unsigned long long val) {}
void func_0021C0D0(void *ctx, int a1, int a2, int a3, int a4, int a5) {}
}

static void reset_mocks() {
    c221b60_calls = 0;
    last_221b60_type = -1;
    c21d2c0_calls = 0;
    c21cfb0_calls = 0;
    c21a680_calls = 0;
    c21c410_calls = 0;
    c21c710_calls = 0;
}

void test_case_scissor_rect_path() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0; // no 0x200

    int rect1[4] = {10, 20, 30, 40};
    int res = func_0021A960(obj, rect1, nullptr, nullptr, 0x400, 0);

    assert(res == 0);
    assert(c221b60_calls == 1);
    assert(last_221b60_type == 0x13);
    assert(c21d2c0_calls == 1);
}

void test_case_early_return_null() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    int res = func_0021A960(obj, nullptr, nullptr, nullptr, 0, 0);
    assert(res == 1);
    assert(c21cfb0_calls == 0);
}

void test_case_render_context_path() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0; // context path

    unsigned char arg2[0x100];
    std::memset(arg2, 0, sizeof(arg2));
    *(void **)(arg2 + 0x14) = (void *)0x1234; // non-null field14
    *(int *)(arg2 + 0x1C) = 2; // mode = 2

    int rect1[4] = {0, 0, 100, 100};
    int rect2[4] = {10, 10, 50, 50};

    int res = func_0021A960(obj, rect1, arg2, rect2, 1, 0);
    assert(res == 0);
    assert(c21a680_calls == 1);
    assert(c221b60_calls == 1);
    assert(last_221b60_type == 0xF);
    assert(c21cfb0_calls == 1);
}

void test_case_render_direct_path() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0x200; // direct path

    unsigned char arg2[0x100];
    std::memset(arg2, 0, sizeof(arg2));
    *(void **)(arg2 + 0x14) = (void *)0x1234;

    int rect1[4] = {0, 0, 100, 100};
    int rect2[4] = {10, 10, 50, 50};

    int res = func_0021A960(obj, rect1, arg2, rect2, 1, 0);
    assert(res == 0);
    assert(c21a680_calls == 1);
    assert(c21c710_calls == 2);
    assert(c21cfb0_calls == 1);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_scissor_rect_path();
    else if (c == 1) test_case_early_return_null();
    else if (c == 2) test_case_render_context_path();
    else if (c == 3) test_case_render_direct_path();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
