#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdint>

class BreakException {
public:
    int code;
    void *self;
    BreakException(int c, void *s) : code(c), self(s) {}
};

extern "C" {
void func_00217B50(void *self, int arg1);
void test_harness_break_hook(int code, void *self) {
    throw BreakException(code, self);
}

static int _213fa0_calls = 0;
static void *_213fa0_arg0 = nullptr;
static int _213fa0_arg1 = 0;
static int _213fa0_arg2 = 0;

static int _1f3b20_calls = 0;
static int vtable_1C_calls = 0;
static int vtable_1C_arg = -1;
static void *vtable_1C_receiver = nullptr;
static void *mutation_target = nullptr;

int func_00213FA0(void *arg0, int arg1, int arg2) {
    _213fa0_calls++;
    _213fa0_arg0 = arg0;
    _213fa0_arg1 = arg1;
    _213fa0_arg2 = arg2;
    return 1;
}

int func_001F3B20(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    _1f3b20_calls++;
    if (mutation_target) {
        *reinterpret_cast<void **>((char *)arg0 + 0x16C) = mutation_target;
    }
    return 1;
}

static void mock_vtable_1C(void *self) {
    vtable_1C_calls++;
    vtable_1C_receiver = self;
}

static void mock_vtable_1C_arg(void *self, void *arg) {
    vtable_1C_calls++;
    vtable_1C_receiver = self;
    vtable_1C_arg = (int)(uintptr_t)arg;
}

static void *vtable[20];
}

static void reset_mocks() {
    _213fa0_calls = 0;
    _213fa0_arg0 = nullptr;
    _213fa0_arg1 = 0;
    _213fa0_arg2 = 0;
    _1f3b20_calls = 0;
    vtable_1C_calls = 0;
    vtable_1C_arg = -1;
    vtable_1C_receiver = nullptr;
    mutation_target = nullptr;
}

void test_case_arg1_zero_skips_213fa0() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x140) = 2;
    *reinterpret_cast<short *>(obj + 0x120) = 10;
    *reinterpret_cast<short *>(obj + 0x124) = 5;

    func_00217B50(obj, 0);
    assert(_213fa0_calls == 0);
}

void test_case_128_retained() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<short *>(obj + 0x120) = 10;
    *reinterpret_cast<short *>(obj + 0x128) = 4;

    func_00217B50(obj, 0);
    assert(*reinterpret_cast<short *>(obj + 0x128) == 4);
}

void test_case_1a8_clearing_path() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    unsigned char sub_obj[0x100];
    std::memset(sub_obj, 0, sizeof(sub_obj));
    vtable[7] = reinterpret_cast<void *>(mock_vtable_1C_arg);
    *reinterpret_cast<void ***>(sub_obj) = vtable;

    *reinterpret_cast<void **>(obj + 0x16C) = sub_obj;
    *reinterpret_cast<int *>(obj + 0x170) = 1;
    *reinterpret_cast<int *>(obj + 0x140) = 2;
    *reinterpret_cast<int *>(obj + 0x18) = 20;
    *reinterpret_cast<int *>(obj + 0x1BC) = 0;
    *reinterpret_cast<short *>(obj + 0x120) = 5;
    *reinterpret_cast<int *>(obj + 0x1A8) = 1;
    *reinterpret_cast<int *>(obj + 0x84) = 1;

    func_00217B50(obj, 0);

    assert(_1f3b20_calls == 1);
    assert(*reinterpret_cast<int *>(obj + 0x1A8) == 0);
    assert(vtable_1C_calls == 1);
    assert(vtable_1C_arg == 0);
}

void test_case_16c_mutation() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    unsigned char sub_obj[0x100];
    std::memset(sub_obj, 0, sizeof(sub_obj));
    vtable[7] = reinterpret_cast<void *>(mock_vtable_1C);
    *reinterpret_cast<void ***>(sub_obj) = vtable;

    unsigned char new_sub_obj[0x100];
    std::memset(new_sub_obj, 0, sizeof(new_sub_obj));
    void *new_vtable[20];
    new_vtable[7] = reinterpret_cast<void *>(mock_vtable_1C);
    *reinterpret_cast<void ***>(new_sub_obj) = new_vtable;

    *reinterpret_cast<void **>(obj + 0x16C) = sub_obj;
    mutation_target = new_sub_obj;

    *reinterpret_cast<int *>(obj + 0x170) = 1;
    *reinterpret_cast<int *>(obj + 0x140) = 2;
    *reinterpret_cast<int *>(obj + 0x18) = 8;
    *reinterpret_cast<int *>(obj + 0x1BC) = 0;
    *reinterpret_cast<short *>(obj + 0x120) = 10;
    *reinterpret_cast<short *>(obj + 0x122) = 2;
    *reinterpret_cast<int *>(obj + 0x1A8) = 0;
    *reinterpret_cast<int *>(obj + 0x84) = 1;

    func_00217B50(obj, 1);
    assert(_1f3b20_calls == 1);
    assert(vtable_1C_calls == 1);
    assert(vtable_1C_receiver == new_sub_obj);
}

void test_case_84_zero_blocks_vtable_1c() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    unsigned char sub_obj[0x100];
    std::memset(sub_obj, 0, sizeof(sub_obj));
    vtable[7] = reinterpret_cast<void *>(mock_vtable_1C);
    *reinterpret_cast<void ***>(sub_obj) = vtable;

    *reinterpret_cast<void **>(obj + 0x16C) = sub_obj;
    *reinterpret_cast<int *>(obj + 0x170) = 1;
    *reinterpret_cast<int *>(obj + 0x140) = 2;
    *reinterpret_cast<int *>(obj + 0x18) = 20;
    *reinterpret_cast<int *>(obj + 0x1BC) = 0;
    *reinterpret_cast<short *>(obj + 0x120) = 5;
    *reinterpret_cast<int *>(obj + 0x1A8) = 1;
    *reinterpret_cast<int *>(obj + 0x84) = 0;

    func_00217B50(obj, 0);

    assert(_1f3b20_calls == 1);
    assert(vtable_1C_calls == 0);
}

void test_case_tail_store_sentinel() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x14) = (int)0x12345678;
    *reinterpret_cast<int *>(obj + 0x178) = 0;

    func_00217B50(obj, 0);
    assert(*reinterpret_cast<int *>(obj + 0x178) == (int)0x12345678);
}

void test_case_f140_zero_bypass() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x140) = 0; // f140 == 0 bypasses division, sets 0x122 to 1
    *reinterpret_cast<int *>(obj + 0x18) = 8;   // distinct numerator
    *reinterpret_cast<int *>(obj + 0x1bc) = 0;
    *reinterpret_cast<int *>(obj + 0x1c0) = 0;
    *reinterpret_cast<short *>(obj + 0x120) = 10;
    *reinterpret_cast<short *>(obj + 0x122) = (short)0x5555;
    *reinterpret_cast<int *>(obj + 0x14) = (int)0x12345678;

    func_00217B50(obj, 0);

    assert(*reinterpret_cast<int *>(obj + 0x17C) == 2); // f140 + 2 = 2 stored at 0x17C
    assert(*reinterpret_cast<short *>(obj + 0x122) == 1); // f140 == 0 sets 0x122 = 1 (distinguished from quotient 4)
    assert(*reinterpret_cast<int *>(obj + 0x178) == (int)0x12345678); // tail store completed
}

void test_case_normal_numerator_zero() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x140) = 2; // v1 = 4; denom = 4 != 0
    *reinterpret_cast<int *>(obj + 0x18) = 0;   // numerator = 0
    *reinterpret_cast<int *>(obj + 0x1bc) = 0;
    *reinterpret_cast<int *>(obj + 0x1c0) = 0;
    *reinterpret_cast<short *>(obj + 0x120) = 10;
    *reinterpret_cast<int *>(obj + 0x14) = (int)0x12345678;
    *reinterpret_cast<short *>(obj + 0x122) = (short)0x5555;

    func_00217B50(obj, 0);

    assert(*reinterpret_cast<int *>(obj + 0x17C) == 4);
    assert(*reinterpret_cast<short *>(obj + 0x122) == 1); // val122 (0) <= 0 clamped to 1
    assert(*reinterpret_cast<int *>(obj + 0x178) == (int)0x12345678);
}

void test_case_division_by_zero_aborts_denom_zero_1() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x140) = -2; // f140 = -2 -> v1 = 0; f1c0 = 0 -> denom = 0
    *reinterpret_cast<int *>(obj + 0x1c0) = 0;
    *reinterpret_cast<int *>(obj + 0x14) = (int)0x12345678;
    *reinterpret_cast<int *>(obj + 0x178) = (int)0x87654321;
    *reinterpret_cast<int *>(obj + 0x17C) = (int)0x9999; // distinct sentinel before trap
    *reinterpret_cast<short *>(obj + 0x122) = (short)0x1111;
    *reinterpret_cast<short *>(obj + 0x124) = (short)0x2222;
    *reinterpret_cast<short *>(obj + 0x126) = (short)0x3333;
    *reinterpret_cast<short *>(obj + 0x128) = (short)0x4444;

    bool caught = false;
    try {
        func_00217B50(obj, 1);
    } catch (const BreakException &ex) {
        caught = true;
        assert(ex.code == 7);
        assert(ex.self == obj);
        // Validate pre-trap state and distinct untouched sentinels/callbacks state at the exact moment of trap
        assert(*reinterpret_cast<int *>(obj + 0x17C) == 0); // v1 = 0 stored at 0x17C before trap (asserting written value)
        assert(*reinterpret_cast<int *>(obj + 0x178) == (int)0x87654321); // tail store untouched (skipped)
        assert(*reinterpret_cast<short *>(obj + 0x122) == (short)0x1111); // untouched 0x122 sentinel
        assert(*reinterpret_cast<short *>(obj + 0x124) == (short)0x2222); // untouched 0x124 sentinel
        assert(*reinterpret_cast<short *>(obj + 0x126) == (short)0x3333); // untouched 0x126 sentinel
        assert(*reinterpret_cast<short *>(obj + 0x128) == (short)0x4444); // untouched 0x128 sentinel
        assert(_213fa0_calls == 0);
        assert(_1f3b20_calls == 0);
        assert(vtable_1C_calls == 0);
    }
    assert(caught);
}

void test_case_division_by_zero_aborts_denom_zero_2() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x140) = -3; // f140 = -3 -> v1 = -1; f1c0 = 1 -> denom = -1 + (2*1 - 1) = 0
    *reinterpret_cast<int *>(obj + 0x1c0) = 1;
    *reinterpret_cast<int *>(obj + 0x14) = (int)0x12345678;
    *reinterpret_cast<int *>(obj + 0x178) = (int)0x87654321;
    *reinterpret_cast<int *>(obj + 0x17C) = (int)0x9999; // distinct sentinel before trap
    *reinterpret_cast<short *>(obj + 0x122) = (short)0x1111;
    *reinterpret_cast<short *>(obj + 0x124) = (short)0x2222;
    *reinterpret_cast<short *>(obj + 0x126) = (short)0x3333;
    *reinterpret_cast<short *>(obj + 0x128) = (short)0x4444;

    bool caught = false;
    try {
        func_00217B50(obj, 1);
    } catch (const BreakException &ex) {
        caught = true;
        assert(ex.code == 7);
        assert(ex.self == obj);
        assert(*reinterpret_cast<int *>(obj + 0x17C) == -1); // v1 = -1 stored at 0x17C before trap
        assert(*reinterpret_cast<int *>(obj + 0x178) == (int)0x87654321);
        assert(*reinterpret_cast<short *>(obj + 0x122) == (short)0x1111);
        assert(*reinterpret_cast<short *>(obj + 0x124) == (short)0x2222);
        assert(*reinterpret_cast<short *>(obj + 0x126) == (short)0x3333);
        assert(*reinterpret_cast<short *>(obj + 0x128) == (short)0x4444);
        assert(_213fa0_calls == 0);
        assert(_1f3b20_calls == 0);
        assert(vtable_1C_calls == 0);
    }
    assert(caught);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_arg1_zero_skips_213fa0();
    else if (case_num == 1) test_case_128_retained();
    else if (case_num == 2) test_case_1a8_clearing_path();
    else if (case_num == 3) test_case_16c_mutation();
    else if (case_num == 4) test_case_84_zero_blocks_vtable_1c();
    else if (case_num == 5) test_case_tail_store_sentinel();
    else if (case_num == 6) test_case_f140_zero_bypass();
    else if (case_num == 7) test_case_normal_numerator_zero();
    else if (case_num == 8) test_case_division_by_zero_aborts_denom_zero_1();
    else if (case_num == 9) test_case_division_by_zero_aborts_denom_zero_2();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
