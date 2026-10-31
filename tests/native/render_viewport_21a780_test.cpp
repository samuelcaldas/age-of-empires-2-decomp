#include <cassert>
#include <cstring>
#include <iostream>

static int c21ae90_calls = 0;
static void *last_21ae90_self = nullptr;
static int last_21ae90_arg1 = -1;
static void *last_21ae90_arg2 = nullptr;
static int last_21ae90_arg3 = -1;
static int last_21ae90_arg4 = -1;
static int last_21ae90_arg5 = -1;
static int mock_21ae90_ret = 888;

static int c21acd0_calls = 0;
static void *last_21acd0_arg0 = nullptr;
static void *last_21acd0_self = nullptr;

static int c21ad70_calls = 0;
static void *last_21ad70_self = nullptr;

static int c21a960_calls = 0;
static void *last_21a960_self = nullptr;
static int last_21a960_arg1 = -1;
static void *last_21a960_arg2 = nullptr;
static int last_21a960_arg3 = -1;
static int last_21a960_arg4 = -1;
static int last_21a960_arg5 = -1;
static int mock_21a960_ret = 777;

static int c21ae10_calls = 0;
static void *last_21ae10_self = nullptr;

extern "C" {
int func_0021A780(void *self, int arg1, void *arg2, int arg3, int arg4, int arg5);

int func_0021AE90(void *self, int arg1, void *arg2, int arg3, int arg4, int arg5) {
    c21ae90_calls++;
    last_21ae90_self = self;
    last_21ae90_arg1 = arg1;
    last_21ae90_arg2 = arg2;
    last_21ae90_arg3 = arg3;
    last_21ae90_arg4 = arg4;
    last_21ae90_arg5 = arg5;
    return mock_21ae90_ret;
}

void func_0021ACD0(void *arg0, void *self) {
    c21acd0_calls++;
    last_21acd0_arg0 = arg0;
    last_21acd0_self = self;
}

void func_0021AD70(void *self) {
    c21ad70_calls++;
    last_21ad70_self = self;
}

int func_0021A960(void *self, int arg1, void *arg2, int arg3, int arg4, int arg5) {
    c21a960_calls++;
    last_21a960_self = self;
    last_21a960_arg1 = arg1;
    last_21a960_arg2 = arg2;
    last_21a960_arg3 = arg3;
    last_21a960_arg4 = arg4;
    last_21a960_arg5 = arg5;
    return mock_21a960_ret;
}

void func_0021AE10(void *self) {
    c21ae10_calls++;
    last_21ae10_self = self;
}
}

static void reset_mocks() {
    c21ae90_calls = 0;
    last_21ae90_self = nullptr;
    last_21ae90_arg1 = -1;
    last_21ae90_arg2 = nullptr;
    last_21ae90_arg3 = -1;
    last_21ae90_arg4 = -1;
    last_21ae90_arg5 = -1;
    mock_21ae90_ret = 888;

    c21acd0_calls = 0;
    last_21acd0_arg0 = nullptr;
    last_21acd0_self = nullptr;

    c21ad70_calls = 0;
    last_21ad70_self = nullptr;

    c21a960_calls = 0;
    last_21a960_self = nullptr;
    last_21a960_arg1 = -1;
    last_21a960_arg2 = nullptr;
    last_21a960_arg3 = -1;
    last_21a960_arg4 = -1;
    last_21a960_arg5 = -1;
    mock_21a960_ret = 777;

    c21ae10_calls = 0;
    last_21ae10_self = nullptr;
}

void test_case_flag_800_early_return() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0x800;

    int res = func_0021A780(obj, 10, (void *)0x2222, 30, 40, 50);
    assert(res == 888);

    assert(c21ae90_calls == 1);
    assert(last_21ae90_self == obj);
    assert(last_21ae90_arg1 == 10);
    assert(last_21ae90_arg2 == (void *)0x2222);
    assert(last_21ae90_arg3 == 30);
    assert(last_21ae90_arg4 == 40);
    assert(last_21ae90_arg5 == 50);

    assert(c21acd0_calls == 0);
    assert(c21ad70_calls == 0);
    assert(c21a960_calls == 0);
    assert(c21ae10_calls == 0);
}

void test_case_default_flags_with_arg2() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0;

    void *arg2_ptr = (void *)0x3333;
    int res = func_0021A780(obj, 1, arg2_ptr, 2, 3, 4);
    assert(res == 777);

    assert(c21ae90_calls == 0);
    assert(c21acd0_calls == 1);
    assert(last_21acd0_arg0 == arg2_ptr);
    assert(last_21acd0_self == obj);

    assert(c21ad70_calls == 1);
    assert(last_21ad70_self == obj);

    assert(c21a960_calls == 1);
    assert(last_21a960_self == obj);
    assert(last_21a960_arg1 == 1);
    assert(last_21a960_arg2 == arg2_ptr);
    assert(last_21a960_arg3 == 2);
    assert(last_21a960_arg4 == 3);
    assert(last_21a960_arg5 == 4);

    assert(c21ae10_calls == 1);
    assert(last_21ae10_self == obj);
}

void test_case_default_flags_null_arg2() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0;

    int res = func_0021A780(obj, 1, nullptr, 2, 3, 4);
    assert(res == 777);

    assert(c21acd0_calls == 0);
    assert(c21ad70_calls == 1);
    assert(last_21ad70_self == obj);

    assert(c21a960_calls == 1);
    assert(last_21a960_self == obj);
    assert(last_21a960_arg1 == 1);
    assert(last_21a960_arg2 == nullptr);
    assert(last_21a960_arg3 == 2);
    assert(last_21a960_arg4 == 3);
    assert(last_21a960_arg5 == 4);

    assert(c21ae10_calls == 1);
    assert(last_21ae10_self == obj);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_flag_800_early_return();
    else if (c == 1) test_case_default_flags_with_arg2();
    else if (c == 2) test_case_default_flags_null_arg2();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
