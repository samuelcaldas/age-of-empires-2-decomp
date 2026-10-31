#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
int func_00218100(void *self, void *arg1, int op, short arg3, int arg4);

static int g_dd0_calls = 0;
static void *g_dd0_self = NULL;
static int g_dd0_arg1 = 0;
static int g_dd0_arg2 = 0;
static int g_dd0_arg3 = 0;

void func_00217DD0(void *self, int arg1, int arg2, int arg3) {
    g_dd0_calls++;
    g_dd0_self = self;
    g_dd0_arg1 = arg1;
    g_dd0_arg2 = arg2;
    g_dd0_arg3 = arg3;
}

static int g_1f6460_calls = 0;
static void *g_1f6460_self = NULL;
static void *g_1f6460_arg1 = NULL;
static int g_1f6460_op = 0;
static short g_1f6460_arg3 = 0;
static int g_1f6460_arg4 = 0;
static int g_1f6460_ret = 42;

int func_1F6460(void *self, void *arg1, int op, short arg3, int arg4) {
    g_1f6460_calls++;
    g_1f6460_self = self;
    g_1f6460_arg1 = arg1;
    g_1f6460_op = op;
    g_1f6460_arg3 = arg3;
    g_1f6460_arg4 = arg4;
    return g_1f6460_ret;
}
}

void test_null_target() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    int dummy = 123;
    int ret = func_00218100(obj, &dummy, 0, 0, 0);
    assert(ret == 42);
    assert(g_1f6460_calls == 1);
    assert(g_1f6460_self == obj);
    assert(g_1f6460_arg1 == &dummy);
    assert(g_dd0_calls == 0);
}

void test_mismatch_target() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    int target = 456;
    int other = 789;
    *reinterpret_cast<void **>(obj + 0x16C) = &target;
    int ret = func_00218100(obj, &other, 1, 10, 20);
    assert(ret == 42);
    assert(g_1f6460_calls == 1);
    assert(g_1f6460_op == 1);
    assert(g_1f6460_arg3 == 10);
    assert(g_1f6460_arg4 == 20);
    assert(g_dd0_calls == 0);
}

void test_match_op_0() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    int target = 456;
    *reinterpret_cast<void **>(obj + 0x16C) = &target;
    int ret = func_00218100(obj, &target, 0, 0, 0);
    assert(ret == 1);
    assert(g_dd0_calls == 1);
    assert(g_dd0_self == obj);
    assert(g_dd0_arg1 == 3);
    assert(g_dd0_arg2 == 0);
    assert(g_dd0_arg3 == 1);
    assert(g_1f6460_calls == 0);
}

void test_match_op_1() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    int target = 456;
    *reinterpret_cast<void **>(obj + 0x16C) = &target;
    int ret = func_00218100(obj, &target, 1, 0, 0);
    assert(ret == 1);
    assert(g_dd0_calls == 1);
    assert(g_dd0_self == obj);
    assert(g_dd0_arg1 == 2);
    assert(g_dd0_arg2 == 0);
    assert(g_dd0_arg3 == 1);
    assert(g_1f6460_calls == 0);
}

void test_match_op_2() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    int target = 456;
    *reinterpret_cast<void **>(obj + 0x16C) = &target;
    int ret = func_00218100(obj, &target, 2, 0, 0);
    assert(ret == 1);
    assert(g_dd0_calls == 1);
    assert(g_dd0_self == obj);
    assert(g_dd0_arg1 == 5);
    assert(g_dd0_arg2 == 0);
    assert(g_dd0_arg3 == 1);
    assert(g_1f6460_calls == 0);
}

void test_match_op_3() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    int target = 456;
    *reinterpret_cast<void **>(obj + 0x16C) = &target;
    int ret = func_00218100(obj, &target, 3, 0, 0);
    assert(ret == 1);
    assert(g_dd0_calls == 1);
    assert(g_dd0_self == obj);
    assert(g_dd0_arg1 == 4);
    assert(g_dd0_arg2 == 0);
    assert(g_dd0_arg3 == 1);
    assert(g_1f6460_calls == 0);
}

void test_match_op_4() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    int target = 456;
    *reinterpret_cast<void **>(obj + 0x16C) = &target;
    int ret = func_00218100(obj, &target, 4, 1234, 0);
    assert(ret == 1);
    assert(g_dd0_calls == 1);
    assert(g_dd0_self == obj);
    assert(g_dd0_arg1 == 1);
    assert(g_dd0_arg2 == 1234);
    assert(g_dd0_arg3 == 0);
    assert(g_1f6460_calls == 0);
}

void test_match_op_unknown() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    int target = 456;
    *reinterpret_cast<void **>(obj + 0x16C) = &target;
    int ret = func_00218100(obj, &target, 99, 11, 22);
    assert(ret == 42);
    assert(g_1f6460_calls == 1);
    assert(g_1f6460_op == 99);
    assert(g_1f6460_arg3 == 11);
    assert(g_1f6460_arg4 == 22);
    assert(g_dd0_calls == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_num = argv[1][0] - '0';
    switch (case_num) {
    case 0: test_null_target(); break;
    case 1: test_mismatch_target(); break;
    case 2: test_match_op_0(); break;
    case 3: test_match_op_1(); break;
    case 4: test_match_op_2(); break;
    case 5: test_match_op_3(); break;
    case 6: test_match_op_4(); break;
    case 7: test_match_op_unknown(); break;
    default: return 2;
    }
    std::cout << "PASS" << std::endl;
    return 0;
}
