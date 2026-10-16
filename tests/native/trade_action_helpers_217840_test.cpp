#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");
static_assert(sizeof(int) == 4, "native fixture requires 32-bit integers");

extern "C" {
void func_00217840(void *, int, int);
void func_00217860(void *, int);
void func_00217880(void *, int);
void func_002178A0(void *, int);
void func_002178C0(void *, int);
void func_002178E0(void *, int, int);
void func_00217900(void *, int, int);
void func_00217920(void *, int, int);
}

static const int OBJECT_SIZE = 0x1A0;
static const int VTABLE_SIZE = 0x30;
static unsigned char object[OBJECT_SIZE] __attribute__((aligned(4)));
static unsigned char expected[OBJECT_SIZE];
static unsigned char vtable[VTABLE_SIZE] __attribute__((aligned(4)));
static int callback_count;
static bool expect_callback;
static int expected_callback_argument;

static void callback(void *self, int argument) {
    assert(expect_callback);
    assert(self == object);
    assert(argument == expected_callback_argument);
    assert(argument == 1);
    assert(callback_count == 0);
    assert(std::memcmp(object, expected, sizeof(object)) == 0);
    callback_count++;
}

static void prepare(bool callback_expected) {
    std::memset(object, 0xA5, sizeof(object));
    std::memset(expected, 0xA5, sizeof(expected));
    std::memset(vtable, 0x5A, sizeof(vtable));
    *reinterpret_cast<void ***>(object) = reinterpret_cast<void **>(vtable);
    *reinterpret_cast<void **>(vtable + 0x28) = reinterpret_cast<void *>(callback);
    std::memcpy(expected, object, sizeof(object));
    callback_count = 0;
    expect_callback = callback_expected;
    expected_callback_argument = 1;
}

static void expect_word(int offset, int value) {
    std::memcpy(expected + offset, &value, sizeof(value));
}

static void expect_byte(int offset, int value) {
    expected[offset] = static_cast<unsigned char>(value);
}

static void verify(bool callback_expected) {
    assert(callback_count == (callback_expected ? 1 : 0));
    assert(std::memcmp(object, expected, sizeof(object)) == 0);
}

typedef void (*TwoArgumentEntry)(void *, int, int);
typedef void (*OneArgumentEntry)(void *, int);

static void run_two_argument_entry(TwoArgumentEntry entry, int first_offset,
                                   int second_offset, int first, int second,
                                   bool byte_second, bool callback_expected) {
    prepare(callback_expected);
    expect_word(first_offset, first);
    if (byte_second) expect_byte(second_offset, second);
    if (!byte_second) expect_word(second_offset, second);
    entry(object, first, second);
    verify(callback_expected);
}

static void run_one_argument_entry(OneArgumentEntry entry, int offset, int value) {
    prepare(true);
    expect_word(offset, value);
    entry(object, value);
    verify(true);
}

static void run_scenario(int first, int second) {
    run_two_argument_entry(func_00217840, 0x144, 0x148, first, second, false, true);
    run_one_argument_entry(func_00217860, 0x14C, first);
    run_one_argument_entry(func_00217880, 0x150, first);
    run_one_argument_entry(func_002178A0, 0x154, first);
    run_one_argument_entry(func_002178C0, 0x158, first);
    run_two_argument_entry(func_002178E0, 0x15C, 0x160, first, second, false, true);
    run_two_argument_entry(func_00217900, 0x164, 0x168, first, second, false, true);
    run_two_argument_entry(func_00217920, 0x188, 0x18C, first, second, true, false);
}

int main() {
    run_scenario(0, 0);
    run_scenario(-1, -128);
    run_scenario(0x7FFFFFFF, 0x1234);
    run_scenario(static_cast<int>(0x80000000u), -257);
    return 0;
}
