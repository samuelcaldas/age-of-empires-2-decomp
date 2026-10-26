#include "render_helper_2184D0_support.h"
#include <csignal>
#include <csetjmp>
#include <iostream>

using namespace helper_2184d0_test;

namespace {

sigjmp_buf trap_environment;
volatile sig_atomic_t trap_caught = 0;

void capture_trap(int) {
    trap_caught = 1;
    siglongjmp(trap_environment, 1);
}


// Positive span with zero step traps on PS2; host C++ division is undefined and is not tested here.
void test_zero_step_and_span_produces_one_call() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    set_field(object, 0x184, static_cast<short>(0));
    set_field(object, 0x186, static_cast<short>(0));
    set_field(object, 0x14, 0);
    set_field(object, 0x18, 0);
    func_002184D0(object);
    assert(state.handler_calls == 1);
    assert(state.cleanup_calls == 1);
    assert((state.events == std::vector<int>{1, 2, 3, 4}));
}

void test_three_positions_use_start_and_step() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    set_field(object, 0x0c, static_cast<void *>(reinterpret_cast<void *>(7)));
    set_field(object, 0x10, static_cast<void *>(reinterpret_cast<void *>(11)));
    set_field(object, 0x184, static_cast<short>(2));
    set_field(object, 0x186, static_cast<short>(2));
    set_field(object, 0x14, 5);
    set_field(object, 0x18, 2);
    func_002184D0(object);
    assert((state.positions_x == std::vector<int>{7, 9, 11}));
    assert((state.positions_y == std::vector<int>{11, 11, 11}));
    assert(state.cleanup_calls == 1);
}

void test_failed_clip_restores_saved_manager_after_mutations() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    mutate_manager(manager, 100);
    state.begin_return = 0;
    state.mutate_begin = true;
    func_002184D0(object);
    assert((state.events == std::vector<int>{1, 2}));
    assert(state.handler_calls == 0);
    assert(state.cleanup_calls == 0);
    assert_manager(manager, 100);
}

void test_begin_mutations_are_reloaded_for_grid_counts() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    set_field(object, 0x184, static_cast<short>(2));
    set_field(object, 0x186, static_cast<short>(2));
    set_field(object, 0x14, 2);
    set_field(object, 0x18, 2);
    state.mutate_begin = true;
    func_002184D0(object);
    assert(state.begin_calls == 1);
    assert(state.begin_arguments[0] == manager);
    assert(state.begin_arguments[1] == reinterpret_cast<void *>(0));
    assert(state.begin_arguments[2] == reinterpret_cast<void *>(0));
    assert(state.begin_arguments[3] == reinterpret_cast<void *>(1));
    assert(state.begin_arguments[4] == reinterpret_cast<void *>(1));
    assert(state.clip_calls == 1);
    assert(state.clip_arguments[0] == manager);
    assert(state.clip_arguments[1] == reinterpret_cast<void *>(1));
    assert(state.handler_calls == 3);
    assert(state.cleanup_calls == 1);
    assert(state.cleanup_argument == manager);
    assert((state.events == std::vector<int>{1, 2, 3, 3, 3, 4}));
}

void test_handler_mutations_change_later_positions_and_arguments() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    unsigned char replacement_manager[0x100];
    initialize(object, manager);
    mutate_manager(manager, 100);
    std::memset(replacement_manager, 0, sizeof(replacement_manager));
    state.handler_manager_replacement = replacement_manager;
    set_field(object, 0x0c, static_cast<void *>(reinterpret_cast<void *>(5)));
    set_field(object, 0x184, static_cast<short>(2));
    set_field(object, 0x186, static_cast<short>(2));
    set_field(object, 0x14, 5);
    set_field(object, 0x18, 2);
    state.mutate_handler = true;
    func_002184D0(object);
    assert((state.positions_x == std::vector<int>{5, 13, 28}));
    assert(state.handler_fields[0] == reinterpret_cast<void *>(0x8888));
    assert(state.handler_fields[1] == reinterpret_cast<void *>(0x8889));
    assert(state.handler_fields[2] == reinterpret_cast<void *>(0x888a));
    assert(state.handler_managers[0] == manager);
    assert(state.handler_managers[1] == replacement_manager);
    assert(state.handler_managers[2] == replacement_manager);
    assert_manager(manager, 600);
    assert_manager(replacement_manager, 100);
    assert(state.cleanup_calls == 1);
}

void test_field_188_three_exits_without_callbacks() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    set_field(object, 0x180, static_cast<void *>(nullptr));
    set_field(object, 0x188, 3);
    set_field(object, 0x10, static_cast<void *>(reinterpret_cast<void *>(0x1234)));
    func_002184D0(object);
    assert(state.events.empty());
    assert(state.begin_calls == 0);
    assert(state.clip_calls == 0);
    assert(state.handler_calls == 0);
    assert(state.cleanup_calls == 0);
}

void run_core_case(int test_case) {
    switch (test_case) {
        case 0: test_zero_step_and_span_produces_one_call(); break;
        case 1: test_three_positions_use_start_and_step(); break;
        case 2: test_failed_clip_restores_saved_manager_after_mutations(); break;
        case 3: test_begin_mutations_are_reloaded_for_grid_counts(); break;
        case 4: test_handler_mutations_change_later_positions_and_arguments(); break;
        case 5: test_field_188_three_exits_without_callbacks(); break;
        default: run_extra_case(test_case); break;
    }
}

}  // namespace

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    const int test_case = std::stoi(argv[1]);
    if (test_case == 10 || test_case == 11) {
        std::signal(SIGTRAP, capture_trap);
        if (sigsetjmp(trap_environment, 1) != 0) {
            assert(trap_caught == 1);
            assert(state.break_code == 7);
            assert((state.events == std::vector<int>{1, 2}));
            assert(state.handler_calls == 0);
            assert(state.cleanup_calls == 0);
            assert_manager(state.manager, 900);
            std::cout << "PASS\\n";
            return 0;
        }
        run_core_case(test_case);
        assert(false && "positive-span zero step must trap");
    }
    run_core_case(test_case);
    std::cout << "PASS\\n";
    return 0;
}
