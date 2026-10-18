#include <cassert>
#include <cstring>
#include "visible_map.h"

enum StreamCall {
    CALL_NONE = 0,
    CALL_READ_WIDTH,
    CALL_READ_HEIGHT,
    CALL_READ_BUFFER,
    CALL_WRITE_WIDTH,
    CALL_WRITE_HEIGHT,
    CALL_WRITE_BUFFER
};

static StreamCall call_log[10];
static int call_count = 0;
static int last_sizes[10];

extern "C" {
    extern int D_004E3058;
    extern int *D_50A5A0[200];
}

int main() {
    VisibleMap map;
    std::memset(&map, 0, sizeof(map));
    func_001387C0(&map, 10, 5);
    assert(map.m_width == 10);
    assert(map.m_height == 5);
    assert(map.m_buffer != nullptr);
    assert(D_50A5A0[0] == map.m_buffer);
    assert(D_50A5A0[4] == map.m_buffer + 4 * 10);
    assert(D_50A5A0[5] == nullptr);

    func_001389E0(&map, 99);
    assert(D_004E3058 == 99);

    func_001389F0(&map);
    assert(map.m_height == 0);
    assert(map.m_buffer == nullptr);
    assert(D_50A5A0[0] == nullptr);

    return 0;
}
