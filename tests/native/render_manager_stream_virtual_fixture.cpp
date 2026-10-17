#include "render_manager_stream_fixture.h"
#include <cassert>
#include <cstdlib>
#include <cstddef>

static_assert(sizeof(void *) == 4, "Native fixture requires the PS2 pointer width");
static_assert(offsetof(RenderManagerStream, device) == 0x24, "Device layout mismatch");

void RenderManagerStream::reserved_00() { std::abort(); }
void RenderManagerStream::reserved_01() { std::abort(); }
void RenderManagerStream::reserved_02() { std::abort(); }
void RenderManagerStream::reserved_03() { std::abort(); }
void RenderManagerStream::reserved_04() { std::abort(); }
void RenderManagerStream::reserved_05() { std::abort(); }
void RenderManagerStream::reserved_06() { std::abort(); }
void RenderManagerStream::reserved_07() { std::abort(); }
void RenderManagerStream::reserved_08() { std::abort(); }
void RenderManagerStream::reserved_09() { std::abort(); }
void RenderManagerStream::reserved_10() { std::abort(); }
void RenderManagerStream::reserved_11() { std::abort(); }
void RenderManagerStream::reserved_12() { std::abort(); }
void RenderManagerStream::reserved_13() { std::abort(); }

int RenderManagerStream::restore_stream(int stream) {
    assert(this == &manager && stream == 0x1234);
    assert(scenario.payload == 0);
    scenario.events += 'V';
    return scenario.dispatch_result;
}
