#include <cassert>
#include <cstring>
#include <iostream>

static int method124_calls = 0;
static void *last_124_self = nullptr;
static short last_124_arg1 = -1;
static int last_124_arg2 = -1;
static int last_124_arg3 = -1;
static int last_124_arg4 = -1;
static int last_124_arg5 = -1;
static int method124_return = 100;

static int c2198a0_calls = 0;
static void *last_2198a0_self = nullptr;
static short last_2198a0_arg1 = -1;
static int last_2198a0_arg2 = -1;
static int last_2198a0_arg3 = -1;
static int last_2198a0_arg4 = -1;
static int c2198a0_return = 200;

extern "C" {
int func_00219530(void *self, int arg1, int arg2, int arg3);
int func_00219550(void *self, int arg1, int arg2, int arg3);
int func_00219580(void *self, int arg1, int arg2);
int func_002195A0(void *self, short arg1, int arg2, int arg3, int arg4);

static int mock_method_124(void *self, short arg1, int arg2, int arg3, int arg4, int arg5) {
    method124_calls++;
    last_124_self = self;
    last_124_arg1 = arg1;
    last_124_arg2 = arg2;
    last_124_arg3 = arg3;
    last_124_arg4 = arg4;
    last_124_arg5 = arg5;
    return method124_return;
}

int func_002198A0(void *self, short arg1, int arg2, int arg3, int arg4) {
    c2198a0_calls++;
    last_2198a0_self = self;
    last_2198a0_arg1 = arg1;
    last_2198a0_arg2 = arg2;
    last_2198a0_arg3 = arg3;
    last_2198a0_arg4 = arg4;
    return c2198a0_return;
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
    method124_return = 100;

    c2198a0_calls = 0;
    last_2198a0_self = nullptr;
    last_2198a0_arg1 = -1;
    last_2198a0_arg2 = -1;
    last_2198a0_arg3 = -1;
    last_2198a0_arg4 = -1;
    c2198a0_return = 200;

    vtable[0x124 / 4] = (void *)mock_method_124;
}

void test_case_2195A0_and_219530() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x120) = 77;

    // Direct 2195A0 call
    int res_a = func_002195A0(obj, 15, 20, 30, 40);
    assert(res_a == 100);
    assert(method124_calls == 1);
    assert(last_124_self == obj);
    assert(last_124_arg1 == 15);
    assert(last_124_arg2 == 20);
    assert(last_124_arg3 == 0);
    assert(last_124_arg4 == 30);
    assert(last_124_arg5 == 40);

    // 219530 forwarding to 2195A0 with field 0x120
    method124_return = 101;
    int res_30 = func_00219530(obj, 25, 35, 45);
    assert(res_30 == 101);
    assert(method124_calls == 2);
    assert(last_124_self == obj);
    assert(last_124_arg1 == 77); // from obj + 0x120
    assert(last_124_arg2 == 25);
    assert(last_124_arg3 == 0);
    assert(last_124_arg4 == 35);
    assert(last_124_arg5 == 45);
}

void test_case_219550_and_219580() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x120) = 88;

    // 219550 call
    int res_50 = func_00219550(obj, 10, 20, 30);
    assert(res_50 == 100);
    assert(method124_calls == 1);
    assert(last_124_self == obj);
    assert(last_124_arg1 == 88);
    assert(last_124_arg2 == 10);
    assert(last_124_arg3 == 20);
    assert(last_124_arg4 == 30);
    assert(last_124_arg5 == 0);

    // 219580 call
    int res_80 = func_00219580(obj, 50, 60);
    assert(res_80 == 200);
    assert(c2198a0_calls == 1);
    assert(last_2198a0_self == obj);
    assert(last_2198a0_arg1 == 88);
    assert(last_2198a0_arg2 == 50);
    assert(last_2198a0_arg3 == 60);
    assert(last_2198a0_arg4 == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_2195A0_and_219530();
    else if (c == 1) test_case_219550_and_219580();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
