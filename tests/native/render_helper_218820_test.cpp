#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>

extern "C" {
void func_00218820(void *self);
struct CallRecord { void *receiver; uintptr_t arguments[11]; unsigned int argument_count; };
extern int ab8f0_calls, acdf0_calls, ad940_calls, ada70_calls, adc00_calls, ab9d0_calls;
extern int return_ab8f0_val, begin_call_count, handler_call_count, cleanup_call_count;
extern void *g_fixture_self, *begin_next_manager, *handler_next_manager;
extern CallRecord begin_calls[2], handler_calls[2], cleanup_calls[2];
extern int handler_kinds[2], mutate_state_on_begin, begin_next_state;
extern int mutate_manager_on_begin, mutate_manager_on_handler;
}
void reset_mocks();

static unsigned char object_bytes[0x300];
static void *const manager_a = reinterpret_cast<void *>(0xA001);
static void *const manager_b = reinterpret_cast<void *>(0xB002);
static void *const manager_c = reinterpret_cast<void *>(0xC003);

static uintptr_t pointer_value(void *value) { return reinterpret_cast<uintptr_t>(value); }
static void *small_pointer(uintptr_t value) { return reinterpret_cast<void *>(value); }
static void set_pointer(unsigned int offset, void *value) { *reinterpret_cast<void **>(object_bytes + offset) = value; }
static void set_state(int state) { *reinterpret_cast<int *>(object_bytes + 0x1AC) = state; }

static void initialize_object(int state) {
    reset_mocks();
    std::memset(object_bytes, 0, sizeof(object_bytes));
    g_fixture_self = object_bytes;
    set_state(state);
    set_pointer(0x20, manager_a);
    set_pointer(0xC, small_pointer(11));
    set_pointer(0x10, small_pointer(22));
    set_pointer(0x14, small_pointer(3));
    set_pointer(0x18, small_pointer(4));
    object_bytes[0x194] = 0x94;
    for (unsigned int index = 0; index < 6; index++) object_bytes[0x1B0 + index] = 0xB0 + index;
}

static void assert_begin(void *manager) {
    assert(begin_call_count == 1);
    assert(begin_calls[0].receiver == manager);
    assert(begin_calls[0].argument_count == 2);
    assert(begin_calls[0].arguments[0] == pointer_value(manager));
    assert(begin_calls[0].arguments[1] == 1);
}

static void assert_cleanup(void *manager) {
    assert(cleanup_call_count == 1);
    assert(cleanup_calls[0].receiver == manager);
    assert(cleanup_calls[0].argument_count == 1);
    assert(cleanup_calls[0].arguments[0] == pointer_value(manager));
}

static void assert_handler_prefix(const CallRecord &record, void *manager) {
    assert(record.receiver == manager);
    assert(record.arguments[0] == pointer_value(manager));
    assert(record.arguments[1] == 11);
    assert(record.arguments[2] == 22);
    assert(record.arguments[3] == 13);
    assert(record.arguments[4] == 25);
}

static void assert_handler_bytes(const CallRecord &record, int state) {
    static const unsigned char expected[7][6] = {
        {0x94, 0, 0, 0, 0, 0}, {0xB5, 0xB0}, {0xB5, 0xB4, 0xB1, 0xB0},
        {0xB5, 0xB4, 0xB3, 0xB2, 0xB1, 0xB0}, {0xB0, 0xB5},
        {0xB0, 0xB1, 0xB4, 0xB5}, {0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5}
    };
    static const unsigned int lengths[7] = {1, 2, 4, 6, 2, 4, 6};
    for (unsigned int index = 0; index < lengths[state - 1]; index++)
        assert(record.arguments[5 + index] == expected[state - 1][index]);
}

static void assert_handler(int state, void *manager) {
    const CallRecord &record = handler_calls[0];
    assert(handler_call_count == 1);
    int expected_kind = state == 1 ? 0 : state == 2 || state == 5 ? 1 : state == 3 || state == 6 ? 2 : 3;
    assert(handler_kinds[0] == expected_kind);
    assert(record.argument_count == 5 + (state == 1 ? 1 : state <= 2 || state == 5 ? 2 : state == 3 || state == 6 ? 4 : 6));
    assert_handler_prefix(record, manager);
    assert_handler_bytes(record, state);
}

static void assert_normal_case(int state) {
    initialize_object(state);
    func_00218820(object_bytes);
    assert_begin(manager_a);
    assert_handler(state, manager_a);
    assert_cleanup(manager_a);
}

static void test_case_218820_zero_state() {
    initialize_object(0);
    func_00218820(object_bytes);
    assert(begin_call_count == 0);
    assert(handler_call_count == 0);
    assert(cleanup_call_count == 0);
}

static void test_case_218820_case_0() { assert_normal_case(1); }
static void test_case_218820_case_1() { assert_normal_case(2); }
static void test_case_218820_case_2() { assert_normal_case(3); }
static void test_case_218820_case_3() { assert_normal_case(4); }
static void test_case_218820_case_4() { assert_normal_case(5); }
static void test_case_218820_case_5() { assert_normal_case(6); }
static void test_case_218820_case_6() { assert_normal_case(7); }

static void assert_cleanup_state(int state) {
    initialize_object(state);
    func_00218820(object_bytes);
    assert_begin(manager_a);
    assert(handler_call_count == 0);
    assert(acdf0_calls + ad940_calls + ada70_calls + adc00_calls == 0);
    assert_cleanup(manager_a);
}

static void test_case_218820_state_8_fallback() { assert_cleanup_state(8); }
static void test_case_218820_out_of_range() { assert_cleanup_state(9); }
static void test_case_218820_coordinates() { assert_normal_case(1); }

static void test_case_218820_begin_returns_zero() {
    initialize_object(1);
    return_ab8f0_val = 0;
    func_00218820(object_bytes);
    assert_begin(manager_a);
    assert(handler_call_count == 0);
    assert_cleanup(manager_a);
}

static void test_case_218820_null_manager() {
    initialize_object(1);
    set_pointer(0x20, nullptr);
    func_00218820(object_bytes);
    assert_begin(nullptr);
    assert_handler(1, nullptr);
    assert_cleanup(nullptr);
}

static void test_case_218820_state_1_to_7() {
    initialize_object(1);
    mutate_state_on_begin = 1;
    begin_next_state = 7;
    func_00218820(object_bytes);
    assert_begin(manager_a);
    assert_handler(7, manager_a);
    assert_cleanup(manager_a);
}

static void assert_transition_cleanup(int next_state) {
    initialize_object(1);
    mutate_state_on_begin = 1;
    begin_next_state = next_state;
    func_00218820(object_bytes);
    assert_begin(manager_a);
    assert(handler_call_count == 0);
    assert_cleanup(manager_a);
}

static void test_case_218820_state_1_to_0() { assert_transition_cleanup(0); }
static void test_case_218820_state_1_to_8() { assert_transition_cleanup(8); }

static void test_case_218820_manager_changes() {
    initialize_object(1);
    mutate_manager_on_begin = 1;
    begin_next_manager = manager_b;
    mutate_manager_on_handler = 1;
    handler_next_manager = manager_c;
    func_00218820(object_bytes);
    assert_begin(manager_a);
    assert(handler_calls[0].arguments[0] == pointer_value(manager_b));
    assert_handler(1, manager_b);
    assert(cleanup_calls[0].arguments[0] == pointer_value(manager_c));
    assert_cleanup(manager_c);
}

static void test_case_218820_negative_state() { assert_cleanup_state(-1); }
static void test_case_218820_int_min_state() { assert_cleanup_state(INT32_MIN); }

int main(int argc, char **argv) {
    static void (*const cases[])() = {
        test_case_218820_zero_state, test_case_218820_case_0, test_case_218820_case_1,
        test_case_218820_case_2, test_case_218820_case_3, test_case_218820_case_4,
        test_case_218820_case_5, test_case_218820_case_6, test_case_218820_state_8_fallback,
        test_case_218820_out_of_range, test_case_218820_coordinates, test_case_218820_begin_returns_zero,
        test_case_218820_null_manager, test_case_218820_state_1_to_7, test_case_218820_state_1_to_0,
        test_case_218820_state_1_to_8, test_case_218820_manager_changes, test_case_218820_negative_state,
        test_case_218820_int_min_state
    };
    if (argc != 2) return 1;
    int case_number = std::stoi(argv[1]);
    if (case_number < 0 || case_number >= static_cast<int>(sizeof(cases) / sizeof(cases[0]))) return 1;
    cases[case_number]();
    std::cout << "PASS\n";
    return 0;
}
