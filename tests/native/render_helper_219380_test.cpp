#include <cassert>
#include <cstring>
#include <iostream>

static int method_d0_calls = 0;
static void *last_target = nullptr;
static void *last_self = nullptr;
static int last_arg2 = -1;
static int last_arg3 = -1;
static int last_arg4 = -1;
static int method_d0_return = 42;

extern "C" {
int func_00219380(void *self);

static int mock_method_d0(void *target, void *self, int arg2, int arg3, int arg4) {
    method_d0_calls++;
    last_target = target;
    last_self = self;
    last_arg2 = arg2;
    last_arg3 = arg3;
    last_arg4 = arg4;
    return method_d0_return;
}

static void *vtable[60];
}

static void reset_mocks() {
    method_d0_calls = 0;
    last_target = nullptr;
    last_self = nullptr;
    last_arg2 = -1;
    last_arg3 = -1;
    last_arg4 = -1;
    method_d0_return = 42;
    vtable[0xD0 / 4] = (void *)mock_method_d0;
    vtable[50] = (void *)mock_method_d0;
}

void test_case_target_null() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(void **)(obj + 0x40) = nullptr;

    int res = func_00219380(obj);
    assert(res == 0);
    assert(method_d0_calls == 0);
}

void test_case_target_valid_dispatch() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    unsigned char target_obj[0x100];
    std::memset(target_obj, 0, sizeof(target_obj));
    *(void ***)target_obj = vtable;

    *(void **)(obj + 0x40) = target_obj;
    method_d0_return = 12345;

    int res = func_00219380(obj);
    assert(res == 12345);
    assert(method_d0_calls == 1);
    assert(last_target == target_obj);
    assert(last_self == obj);
    assert(last_arg2 == 1);
    assert(last_arg3 == 0);
    assert(last_arg4 == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_target_null();
    else if (c == 1) test_case_target_valid_dispatch();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
