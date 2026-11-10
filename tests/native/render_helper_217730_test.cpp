#include <cassert>
#include <cstring>
#include <iostream>

void *D_004E3058 = (void *)0x12345678;

static int c00185e20_calls = 0;
static void *last_00185e20_arg = nullptr;
static int last_00185e20_val = -1;

static int c00217b50_calls = 0;
static void *last_00217b50_self = nullptr;
static int last_00217b50_flag = -1;

static int method28_calls = 0;
static void *last_method28_self = nullptr;
static int last_method28_arg1 = -1;

static void *mock_vtable[32];

static void mock_method28(void *self, int arg1) {
    method28_calls++;
    last_method28_self = self;
    last_method28_arg1 = arg1;
}

static int mock_res[3] = {42, 100, 200};

extern "C" {
void *func_00185e20(void *arg, int val) {
    c00185e20_calls++;
    last_00185e20_arg = arg;
    last_00185e20_val = val;
    if (val == 999) return nullptr;
    return mock_res;
}

void func_00217B50(void *self, int flag) {
    c00217b50_calls++;
    last_00217b50_self = self;
    last_00217b50_flag = flag;
}

void func_00217730(void *self, int arg1);
void func_002177C0(void *self, int *arr, int arg2, int arg3);
}

static void reset_mocks() {
    c00185e20_calls = 0;
    last_00185e20_arg = nullptr;
    last_00185e20_val = -1;

    c00217b50_calls = 0;
    last_00217b50_self = nullptr;
    last_00217b50_flag = -1;

    method28_calls = 0;
    last_method28_self = nullptr;
    last_method28_arg1 = -1;

    mock_vtable[0x28 / 4] = (void *)mock_method28;
    mock_vtable[0x28 / 4 - 2] = (void *)mock_method28;
}

void test_case_func_00217730_positive() {
    reset_mocks();
    char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void **)obj = mock_vtable;

    func_00217730(obj, 5);

    assert(c00185e20_calls == 1);
    assert(last_00185e20_arg == D_004E3058);
    assert(last_00185e20_val == 5);

    // arr[0..3] should be 42
    for (int i = 0; i < 4; i++) {
        assert(*(int *)(obj + 0x12C + i * 4) == 42);
    }
    // a2 and a3
    assert(*(int *)(obj + 0x13C) == 100);
    assert(*(int *)(obj + 0x140) == 200);

    assert(c00217b50_calls == 1);
    assert(last_00217b50_self == obj);
    assert(last_00217b50_flag == 1);

    assert(method28_calls == 1);
    assert(last_method28_self == obj);
    assert(last_method28_arg1 == 1);
}

void test_case_func_00217730_negative() {
    reset_mocks();
    char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void **)obj = mock_vtable;

    // arg1 < 0 -> defaults to 2
    func_00217730(obj, -10);

    assert(c00185e20_calls == 1);
    assert(last_00185e20_arg == D_004E3058);
    assert(last_00185e20_val == 2);
}

void test_case_func_00217730_null() {
    reset_mocks();
    char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void **)obj = mock_vtable;

    // val 999 triggers mock null return
    func_00217730(obj, 999);

    assert(c00185e20_calls == 1);
    for (int i = 0; i < 4; i++) {
        assert(*(int *)(obj + 0x12C + i * 4) == 0);
    }
    assert(*(int *)(obj + 0x13C) == 0);
    assert(*(int *)(obj + 0x140) == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_func_00217730_positive();
    else if (c == 1) test_case_func_00217730_negative();
    else if (c == 2) test_case_func_00217730_null();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
