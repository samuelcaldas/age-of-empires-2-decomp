#include "render_manager_stream_fixture.h"
#include <cassert>
#include <cstdlib>
#include <cstring>

StreamScenario scenario;
RenderManagerStream manager;
static const int STREAM_HANDLE = 0x1234;

void prepare_stream_scenario(int payload_size) {
    scenario = StreamScenario();
    scenario.payload_size = payload_size;
    scenario.payload_read_result = payload_size;
    scenario.dispatch_result = 37;
    manager.device = reinterpret_cast<void *>(0xAA00);
}

extern "C" {
int func_3449B0(void *device) {
    assert(device == manager.device);
    scenario.events += 'O';
    return STREAM_HANDLE;
}
int func_226D40(int stream, void *destination, int size) {
    assert(stream == STREAM_HANDLE && destination != 0);
    const int read_index = scenario.reads++;
    assert(read_index < 3);
    if (read_index < 2) {
        assert(size == 4);
        *static_cast<int *>(destination) = read_index == 0 ? 0xCAFE : scenario.payload_size;
        scenario.events += read_index == 0 ? 'H' : 'S';
        return 4;
    }
    assert(destination == scenario.payload && size == scenario.payload_size);
    assert(scenario.payload != 0);
    scenario.events += 'P';
    if (scenario.payload_read_result >= 0) std::memset(destination, 0x5A, size);
    return scenario.payload_read_result;
}
void func_226D90(int stream, void *destination, int size) {
    assert(stream == STREAM_HANDLE && destination != 0 && size == 4);
    assert(scenario.payload == 0);
    *static_cast<int *>(destination) = 0x4567;
    scenario.events += 'T';
}
void *func_116F40(int size) {
    assert(size == scenario.payload_size && size > 0);
    scenario.events += 'A';
    if (scenario.fail_buffer) return 0;
    scenario.payload = std::malloc(size);
    assert(scenario.payload != 0);
    return scenario.payload;
}
void func_116F68(void *payload) {
    assert(payload == scenario.payload && payload != 0);
    scenario.events += 'F';
    std::free(payload);
    scenario.payload = 0;
}
int func_226BF0(int stream) {
    assert(stream == STREAM_HANDLE && scenario.payload == 0);
    scenario.events += 'C';
    return -71;
}
void *func_100850(int size) {
    assert(size == 0x19F4);
    scenario.events += 'N';
    if (scenario.fail_context) return 0;
    scenario.context = std::malloc(size);
    return scenario.context;
}
void func_239410(void *context, void *parent, int flag) {
    assert(context == scenario.context && flag == 0);
    scenario.parent = parent;
    scenario.events += 'I';
}
int func_3448E0(void *device) {
    assert(device == manager.device);
    scenario.events += 'Q';
    return -42;
}
}
