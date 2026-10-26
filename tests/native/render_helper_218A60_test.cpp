#include <cassert>
#include <cstring>
#include <iostream>

static int c219c00_calls = 0;
static int c219c90_calls = 0;
static int c11acd0_calls = 0;
static int c219040_calls = 0;
static int c2257a0_calls = 0;

static int last_zero1 = -1;
static int last_zero2 = -1;
static void *mock_loc120 = (void *)0x1111;
static void *mock_s3 = (void *)0x3333;
static unsigned char loc124_buf[0x10];

extern "C" {
void func_00218A60(void *self, void *arg1, short arg2, short arg3, int selector);

int func_00219C00(void *self, int arg1, void **loc120, void **loc124, void **loc128, void **loc12C) {
    c219c00_calls++;
    *loc120 = mock_loc120;
    *loc124 = loc124_buf;
    return 1;
}

void *func_00219C90(void *self, int arg1) {
    c219c90_calls++;
    return mock_s3;
}

int func_0011ACD0(void *arg0) {
    c11acd0_calls++;
    return 1;
}

int func_00219040(void *self, void *arg1, short arg2, short arg3, void *loc100, int zero1, int zero2) {
    c219040_calls++;
    last_zero1 = zero1;
    last_zero2 = zero2;
    if (loc100) {
        int *pair = reinterpret_cast<int *>(loc100);
        pair[0] = 123;
        pair[1] = 456;
    }
    return 1;
}

int func_002257A0(void *arg0, int arg1) {
    c2257a0_calls++;
    return arg1 + 1;
}

int func_00225200(void *arg0) { return 1; }
int func_00225820(void *arg0, void *arg1) { return 1; }
int func_00225980(void *arg0) { return 1; }
int func_002258D0(void *arg0, void *arg1, int arg2) { return 1; }
}

static void reset_mocks() {
    c219c00_calls = 0;
    c219c90_calls = 0;
    c11acd0_calls = 0;
    c219040_calls = 0;
    c2257a0_calls = 0;
    last_zero1 = -1;
    last_zero2 = -1;
    mock_loc120 = (void *)0x1111;
    mock_s3 = (void *)0x3333;
    std::memset(loc124_buf, 0, sizeof(loc124_buf));
    *reinterpret_cast<int *>(loc124_buf + 4) = 0;
}

void test_case_218A60_selector_0_and_1() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));

    *reinterpret_cast<int *>(obj + 0x12C) = 42;

    // Selector 0
    func_00218A60(obj, (void *)0x5555, 1, 2, 0);
    assert(c219c00_calls == 1);
    assert(c219040_calls == 1);
    assert(last_zero1 == 0);
    assert(last_zero2 == 0);
    assert(c11acd0_calls == 2); // exactly local120 and s3, with no bogus local100 free

    // Selector 1
    func_00218A60(obj, (void *)0x5555, 1, 2, 1);
    assert(c219c00_calls == 2);
    assert(c219040_calls == 2);
    assert(last_zero1 == 0);
    assert(last_zero2 == 0);
}

void test_case_218A60_both_null_early_return() {
    reset_mocks();
    mock_loc120 = nullptr;
    mock_s3 = nullptr;

    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));

    func_00218A60(obj, (void *)0x5555, 1, 2, 0);

    assert(c219c00_calls == 1);
    assert(c219c90_calls == 1);
    assert(c11acd0_calls == 0);
    assert(c219040_calls == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_218A60_selector_0_and_1();
    else if (case_num == 1) test_case_218A60_both_null_early_return();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
