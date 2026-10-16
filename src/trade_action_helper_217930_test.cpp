#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdint>

extern "C" {
void func_00217930(void *self, void *arg1, int arg2);
void func_25DE30(void *arg, int val);
void *func_25F2B0(int val);
void func_25D6D0(void *target, void *arg1, int arg2);
void func_25DF80(void *target, int *out1, int *out2, int *out3, int *out4, int extra);

// Mock tracking state
static int dealloc_called = 0;
static void *dealloc_arg = nullptr;
static int alloc_calls = 0;
static int alloc_arg_passed = 0;
static void *alloc_return_value = nullptr;
static int d6d0_calls = 0;
static void *d6d0_target = nullptr;
static void *d6d0_arg1 = nullptr;
static int d6d0_arg2 = 0;
static int df80_calls = 0;
static void *df80_target = nullptr;
static int df80_extra = -1;
static char *callback_zero_target = nullptr;

void func_25DE30(void *arg, int val) {
    dealloc_called++;
    dealloc_arg = arg;
    assert(val == 1);
    if (callback_zero_target) {
        *callback_zero_target = '\0';
    }
}

void *func_25F2B0(int val) {
    alloc_calls++;
    alloc_arg_passed = val;
    return alloc_return_value;
}

void func_25D6D0(void *target, void *arg1, int arg2) {
    d6d0_calls++;
    d6d0_target = target;
    d6d0_arg1 = arg1;
    d6d0_arg2 = arg2;
}

void func_25DF80(void *target, int *out1, int *out2, int *out3, int *out4, int extra) {
    df80_calls++;
    df80_target = target;
    df80_extra = extra;
    *out1 = (int)0x1234000A; // 10 low
    *out2 = (int)0x56780014; // 20 low
    *out3 = (int)0x9ABC0023; // 35 low
    *out4 = (int)0xDEF0002D; // 45 low
}
}

static inline void *get_target180(char *s0) {
    unsigned int val;
    const char *src = s0 + 0x180;
    char *dst = (char *)&val;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    return (void *)(unsigned long)val;
}

static void reset_mocks() {
    dealloc_called = 0;
    dealloc_arg = nullptr;
    alloc_calls = 0;
    alloc_arg_passed = 0;
    alloc_return_value = nullptr;
    d6d0_calls = 0;
    d6d0_target = nullptr;
    d6d0_arg1 = nullptr;
    d6d0_arg2 = 0;
    df80_calls = 0;
    df80_target = nullptr;
    df80_extra = -1;
    callback_zero_target = nullptr;
}

void test_case_no_allocation_when_arg2_minus_one_and_null_arg() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    void *existing_target = (void *)0x12345678;
    uint32_t existing_val = (uint32_t)(uintptr_t)existing_target;
    __builtin_memcpy(obj + 0x180, &existing_val, sizeof(existing_val));

    func_00217930(obj, nullptr, -1);

    assert(dealloc_called == 1);
    assert(dealloc_arg == existing_target);
    assert(get_target180((char *)obj) == nullptr);
    assert(*reinterpret_cast<short *>(obj + 0x184) == 0);
    assert(*reinterpret_cast<short *>(obj + 0x186) == 0);
    assert(alloc_calls == 0);
    assert(df80_calls == 0);
}

void test_case_allocation_returns_null_still_calls_df80() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    char valid_str = 'a';
    alloc_return_value = nullptr;

    func_00217930(obj, &valid_str, 5);

    assert(alloc_calls == 1);
    assert(alloc_arg_passed == 0x14); // decimal 20 = 0x14
    assert(d6d0_calls == 0);
    assert(df80_calls == 1);
    assert(df80_target == nullptr);
    assert(df80_extra == 0);
    assert(get_target180((char *)obj) == nullptr);
}

void test_case_successful_allocation_and_delta() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    char valid_str = 'a';
    void *dummy_target = (void *)0x87654321;
    alloc_return_value = dummy_target;

    func_00217930(obj, &valid_str, 5);

    assert(dealloc_called == 0);
    assert(alloc_calls == 1);
    assert(alloc_arg_passed == 0x14);
    assert(d6d0_calls == 1);
    assert(d6d0_target == dummy_target);
    assert(d6d0_arg1 == &valid_str);
    assert(d6d0_arg2 == 5);
    assert(df80_calls == 1);
    assert(df80_target == dummy_target);
    assert(df80_extra == 0);
    // low 16-bit: out2 (35) - out0 (10) = 25
    // low 16-bit: out3 (45) - out1 (20) = 25
    assert(*reinterpret_cast<short *>(obj + 0x184) == 25);
    assert(*reinterpret_cast<short *>(obj + 0x186) == 25);
    assert(get_target180((char *)obj) == dummy_target);
}

void test_case_cleanup_callback_modifies_arg1_before_bypass_check() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    void *existing_target = (void *)0x12345678;
    uint32_t existing_val = (uint32_t)(uintptr_t)existing_target;
    __builtin_memcpy(obj + 0x180, &existing_val, sizeof(existing_val));

    char str_val = 'X';
    callback_zero_target = &str_val;

    // arg2 = -1, str_val starts as 'X' (non-zero), but cleanup callback will zero it out FIRST
    func_00217930(obj, &str_val, -1);

    assert(dealloc_called == 1);
    assert(str_val == '\0');
    // Because cleanup ran first and zeroed out str_val, the subsequent bypass check (arg2 == -1 && *arg1 == 0) sees '\0' and correctly bypasses allocation!
    assert(alloc_calls == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_no_allocation_when_arg2_minus_one_and_null_arg();
    else if (case_num == 1) test_case_allocation_returns_null_still_calls_df80();
    else if (case_num == 2) test_case_successful_allocation_and_delta();
    else if (case_num == 3) test_case_cleanup_callback_modifies_arg1_before_bypass_check();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
