#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
int func_00217EC0(void *self, int arg1, int arg2, int arg3, int arg4, int arg5);
void func_00217DD0(void *self, int arg1, int arg2, int arg3);

static int helper_7DD0_calls = 0;
static int helper_7DD0_arg1 = 0;
static int helper_7DD0_arg2 = 0;
static int helper_7DD0_arg3 = 0;
static int vtable_C8_calls = 0;
static void *vtable_C8_self = nullptr;
static void *vtable_C8_args[5];
static void *vtable[60];

void func_00217DD0(void *self, int arg1, int arg2, int arg3) {
    helper_7DD0_calls++;
    helper_7DD0_arg1 = arg1;
    helper_7DD0_arg2 = arg2;
    helper_7DD0_arg3 = arg3;
    assert(arg2 == 0);
    assert(arg3 == 1);
}

static void mock_vtable_C8(void *self, void *a1, void *a2, void *a3, void *a4, void *a5) {
    vtable_C8_calls++;
    vtable_C8_self = self;
    vtable_C8_args[0] = a1;
    vtable_C8_args[1] = a2;
    vtable_C8_args[2] = a3;
    vtable_C8_args[3] = a4;
    vtable_C8_args[4] = a5;
}
}

static void reset_mocks() {
    helper_7DD0_calls = 0;
    helper_7DD0_arg1 = 0;
    helper_7DD0_arg2 = -1;
    helper_7DD0_arg3 = 0;
    vtable_C8_calls = 0;
    vtable_C8_self = nullptr;
    std::memset(vtable_C8_args, 0, sizeof(vtable_C8_args));
}

void test_case_all_switch_cases_and_defaults() {
    int expected_ids[10] = {-1, 5, 4, 7, 6, -1, 3, -1, 2, -1};
    int arg1_vals[10] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

    for (int i = 0; i < 10; i++) {
        reset_mocks();
        unsigned char obj[0x200];
        std::memset(obj, 0, sizeof(obj));

        unsigned char sub_obj[0x100];
        std::memset(sub_obj, 0, sizeof(sub_obj));
        vtable[50] = reinterpret_cast<void *>(mock_vtable_C8);
        *reinterpret_cast<void ***>(sub_obj) = vtable;

        *reinterpret_cast<void **>(obj + 0x40) = sub_obj;
        *reinterpret_cast<int *>(obj + 0x8C) = 1;

        int arg1 = arg1_vals[i];
        int res = func_00217EC0(obj, arg1, 11, 22, 33, 44);

        int exp_id = expected_ids[i];
        if (exp_id == -1) {
            assert(res == 0);
            assert(helper_7DD0_calls == 0);
        } else {
            assert(res == 1);
            assert(helper_7DD0_calls == 1);
            assert(helper_7DD0_arg1 == exp_id);
            assert(helper_7DD0_arg2 == 0);
            assert(helper_7DD0_arg3 == 1);
            assert(vtable_C8_calls == 1);
        }
    }
}

void test_case_guard_returns_byte() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    unsigned char guard_obj[0x200];
    std::memset(guard_obj, 0, sizeof(guard_obj));
    *reinterpret_cast<unsigned char *>(guard_obj + 0x16C) = 7;
    *reinterpret_cast<void **>(obj + 0x16C) = guard_obj;

    int res = func_00217EC0(obj, 33, 11, 22, 33, 44);
    assert(res == 7);
    assert(helper_7DD0_calls == 0);
}

void test_case_gates_block_vtable() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    *reinterpret_cast<int *>(obj + 0x8C) = 1;
    int res = func_00217EC0(obj, 33, 11, 22, 33, 44);
    assert(res == 1);
    assert(helper_7DD0_calls == 1);
    assert(vtable_C8_calls == 0);

    reset_mocks();
    unsigned char sub_obj[0x100];
    std::memset(sub_obj, 0, sizeof(sub_obj));
    *reinterpret_cast<void **>(obj + 0x40) = sub_obj;
    *reinterpret_cast<int *>(obj + 0x8C) = 0;
    res = func_00217EC0(obj, 33, 11, 22, 33, 44);
    assert(res == 1);
    assert(helper_7DD0_calls == 1);
    assert(vtable_C8_calls == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_all_switch_cases_and_defaults();
    else if (case_num == 1) test_case_guard_returns_byte();
    else if (case_num == 2) test_case_gates_block_vtable();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
