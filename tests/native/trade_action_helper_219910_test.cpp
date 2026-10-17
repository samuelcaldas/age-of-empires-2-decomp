#include <cassert>
#include <cstring>
#include <iostream>

static int method124_calls = 0;
static void *last_124_self = nullptr;
static int last_124_arg1 = -1;
static int last_124_arg2 = -1;
static int last_124_arg3 = -1;
static int last_124_arg4 = -1;
static int last_124_arg5 = -1;
static int mock_method124_ret = 0;

static int c219990_calls = 0;
static void *last_219990_self = nullptr;
static int last_219990_arg1 = -1;
static int mock_219990_ret = 1;

extern "C" {
int func_00219910(void *self, int arg1, int arg2, int arg3, int arg4);

int func_00219990(void *self, int arg1) {
    c219990_calls++;
    last_219990_self = self;
    last_219990_arg1 = arg1;
    return mock_219990_ret;
}

static int mock_method_124(void *self, int arg1, int arg2, int arg3, int arg4, int arg5) {
    method124_calls++;
    last_124_self = self;
    last_124_arg1 = arg1;
    last_124_arg2 = arg2;
    last_124_arg3 = arg3;
    last_124_arg4 = arg4;
    last_124_arg5 = arg5;
    return mock_method124_ret;
}

static void *vtable[100];
}

static void reset_mocks() {
    method124_calls = 0;
    last_124_self = nullptr;
    last_124_arg1 = -1;
    last_124_arg2 = -1;
    last_124_arg3 = -1;
    last_124_arg4 = -1;
    last_124_arg5 = -1;
    mock_method124_ret = 0;

    c219990_calls = 0;
    last_219990_self = nullptr;
    last_219990_arg1 = -1;
    mock_219990_ret = 1;

    vtable[0x124 / 4] = (void *)mock_method_124;
}

void test_case_method124_fails() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(int *)(obj + 0x198) = 42; // initial flag

    mock_method124_ret = 0; // failure
    int res = func_00219910(obj, 5, 10, 15, 20);

    assert(res == 0);
    assert(method124_calls == 1);
    assert(last_124_self == obj);
    assert(last_124_arg1 == 5);
    assert(last_124_arg2 == 10);
    assert(last_124_arg3 == 15);
    assert(last_124_arg4 == 20);
    assert(last_124_arg5 == 0);

    assert(c219990_calls == 0);
    assert(*(int *)(obj + 0x198) == 42); // restored
}

void test_case_method124_succeeds() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(int *)(obj + 0x198) = 99; // initial flag

    mock_method124_ret = 1; // success
    int res = func_00219910(obj, 5, 10, 15, 20);

    assert(res == 1);
    assert(method124_calls == 1);
    assert(c219990_calls == 1);
    assert(last_219990_self == obj);
    assert(last_219990_arg1 == 6); // arg1 + 1 (5 + 1)
    assert(*(int *)(obj + 0x198) == 99); // restored
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_method124_fails();
    else if (c == 1) test_case_method124_succeeds();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
