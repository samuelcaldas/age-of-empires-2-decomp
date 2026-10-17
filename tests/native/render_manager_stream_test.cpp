#include "render_manager_stream_fixture.h"
#include <cassert>
#include <cstdlib>

static void test_stream_payload(int flag) {
    prepare_stream_scenario(16);
    int result = func_00184ed0(&manager, 0, flag);
    assert(result == 37);
    assert(scenario.events == "OHSAPFTVC");
    assert(scenario.payload == 0);
}

static void test_nonpositive_payload(int size) {
    prepare_stream_scenario(size);
    scenario.dispatch_result = 0;
    assert(func_00184ed0(&manager, 0, 1) == 0);
    assert(scenario.events == "OHSTVC");
}

static void test_buffer_allocation_failure() {
    prepare_stream_scenario(16);
    scenario.fail_buffer = true;
    assert(func_00184ed0(&manager, 0, 1) == 0);
    assert(scenario.events == "OHSAC");
}

static void test_payload_read_result_is_ignored() {
    prepare_stream_scenario(16);
    scenario.payload_read_result = -1;
    scenario.dispatch_result = -19;
    assert(func_00184ed0(&manager, 0, 1) == -19);
    assert(scenario.events == "OHSAPFTVC");
}

static void test_context_factory(bool allocation_fails) {
    prepare_stream_scenario(0);
    scenario.fail_context = allocation_fails;
    void *parent = reinterpret_cast<void *>(0xBB00);
    void *result = func_00184fb0(&manager, parent);
    assert(result == scenario.context);
    if (allocation_fails) {
        assert(result == 0 && scenario.events == "N");
        return;
    }
    assert(result != 0 && scenario.parent == parent);
    assert(scenario.events == "NI");
    std::free(result);
}

static void test_device_status(bool present) {
    prepare_stream_scenario(0);
    if (!present) manager.device = 0;
    assert(func_00185000(&manager) == (present ? -42 : 0));
    assert(scenario.events == (present ? "Q" : ""));
}

int main(int count, char **arguments) {
    if (count != 2) return 1;
    switch (std::atoi(arguments[1])) {
    case 0: test_stream_payload(1); return 0;
    case 1: test_nonpositive_payload(0); return 0;
    case 2: test_nonpositive_payload(-4); return 0;
    case 3: test_buffer_allocation_failure(); return 0;
    case 4: test_payload_read_result_is_ignored(); return 0;
    case 5: test_context_factory(false); return 0;
    case 6: test_context_factory(true); return 0;
    case 7: test_device_status(true); return 0;
    case 8: test_device_status(false); return 0;
    case 9: test_stream_payload(-1); return 0;
    case 10: test_stream_payload(2); return 0;
    default: return 1;
    }
}
