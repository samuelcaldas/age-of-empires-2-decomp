#include <cassert>
#include <cstring>
#include "visible_map.h"

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
