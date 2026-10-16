#include <cassert>
#include <cstring>
#include <iostream>

static int c219c90_calls = 0;
static int vtable_calls = 0;
static int c225200_calls = 0;
static int c11acd0_calls = 0;
static int c2252e0_calls = 0;
static int c225db0_calls = 0;

static void *mock_s2 = (void *)0x2222;
static int mock_225200_ret = 5;
static int mock_11acd0_ret = 12;
static int mock_loc198_w = 20;
static int mock_loc198_h = 30;

extern "C" {
void func_00219040(void *self, void *arg1, short arg2, short arg3, void *loc100, void *arg5, int arg6);

void *func_00219C90(void *self, int arg1) {
    c219c90_calls++;
    return mock_s2;
}

static void *mock_vfn_128(void *self, int arg1) {
    vtable_calls++;
    return mock_s2;
}

int func_00225200(void *arg0) {
    c225200_calls++;
    return mock_225200_ret;
}

int func_0011ACD0(void *arg0) {
    c11acd0_calls++;
    return mock_11acd0_ret;
}

int func_002252E0(void *buf, void *s2, short arg2) {
    c2252e0_calls++;
    return 1;
}

int func_00225DB0(void *arg0, void *arg1, short arg2, void *loc198) {
    c225db0_calls++;
    if (loc198) {
        int *pair = (int *)loc198;
        pair[0] = mock_loc198_w;
        pair[1] = mock_loc198_h;
    }
    return 1;
}

static void *vtable[100];
}

static void reset_mocks() {
    c219c90_calls = 0;
    vtable_calls = 0;
    c225200_calls = 0;
    c11acd0_calls = 0;
    c2252e0_calls = 0;
    c225db0_calls = 0;
    mock_s2 = (void *)0x2222;
    mock_225200_ret = 5;
    mock_11acd0_ret = 12;
    mock_loc198_w = 20;
    mock_loc198_h = 30;
    vtable[0x128 / 4] = (void *)mock_vfn_128;
}

void test_case_s2_null_path() {
    reset_mocks();
    mock_s2 = nullptr;
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(int *)(obj + 0x148) = 1; // s1 = 1
    *(int *)(obj + 0xC) = 100;
    *(int *)(obj + 0x1BC) = 10;
    *(int *)(obj + 0x17C) = 4;
    *(int *)(obj + 0x10) = 50;
    *(int *)(obj + 0x144) = 3;

    int rect[4] = {0};
    int arg5_out = -1;
    func_00219040(obj, (void *)0x1111, 2, 3, rect, &arg5_out, 0);

    assert(vtable_calls == 1);
    assert(c219c90_calls == 0);
    assert(c225200_calls == 0);
    assert(c225db0_calls == 0);
    assert(rect[0] == 110);
    assert(rect[2] == 110 + 0 - 1);
    assert(arg5_out == 5);
}

void test_case_field12a_zero_path() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(int *)(obj + 0x14C) = 2; // s1 = 2
    *(short *)(obj + 0x12A) = 0;
    *(int *)(obj + 0xC) = 100;
    *(int *)(obj + 0x14) = 40;
    *(int *)(obj + 0x1BC) = 5;
    *(int *)(obj + 0x17C) = 6;
    *(int *)(obj + 0x10) = 200;
    *(int *)(obj + 0x144) = 3;

    int rect[4] = {0};
    int arg5_out = -1;
    func_00219040(obj, (void *)0x1111, 1, 2, rect, &arg5_out, 1);

    assert(c219c90_calls == 1);
    assert(vtable_calls == 0);
    assert(c225200_calls == 1);
    assert(c11acd0_calls == 1);
    assert(c225db0_calls == 1);
    assert(arg5_out == 5);
}

void test_case_field12a_large_branch() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(int *)(obj + 0x148) = 5; // s1 = 5
    *(short *)(obj + 0x12A) = 4;
    mock_225200_ret = 8; // >= field12A (4)
    *(int *)(obj + 0xC) = 50;
    *(int *)(obj + 0x14) = 10;
    *(int *)(obj + 0x1BC) = 4;
    *(int *)(obj + 0x17C) = 3;
    *(int *)(obj + 0x1C0) = 2;
    *(int *)(obj + 0x144) = 4;
    *(short *)(obj + 0x120) = 8;
    *(int *)(obj + 0x10) = 80;
    *(int *)(obj + 0x18) = 20;

    int rect[4] = {0};
    int arg5_out = -1;
    func_00219040(obj, (void *)0x1111, 2, 1, rect, &arg5_out, 0);

    assert(c2252e0_calls == 1);
    assert(rect[0] != 0);
    assert(rect[1] != 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_s2_null_path();
    else if (c == 1) test_case_field12a_zero_path();
    else if (c == 2) test_case_field12a_large_branch();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
