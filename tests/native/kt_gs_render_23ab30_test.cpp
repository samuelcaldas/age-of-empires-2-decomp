#include "kt_gs_render_23ab30.h"
#include <cassert>
#include <cstring>
#include <iostream>

static void* last_format_dst = nullptr;
static void* last_format_src = nullptr;
static void* last_set_dst = nullptr;

extern "C" {
    void zone_spatial_grid_format_path_string(void* dst, void* src) {
        last_format_dst = dst;
        last_format_src = src;
    }

    void zone_spatial_grid_set_string(void* dst) {
        last_set_dst = dst;
    }
}

int main() {
    u8 buffer[0x2000];
    std::memset(buffer, 0, sizeof(buffer));

    // Test func_0023AB30 & func_0023AB40
    func_0023AB30(buffer, 0x42);
    assert(buffer[8] == 0x42);
    assert(func_0023AB40(buffer) == 0x42);

    func_0023AB30(buffer, 0x99);
    assert(buffer[8] == 0x99);
    assert(func_0023AB40(buffer) == 0x99);

    // Test func_0023AB50 with non-null arg1
    u8 dummy_arg[16];
    last_format_dst = nullptr;
    last_format_src = nullptr;
    last_set_dst = nullptr;

    func_0023AB50(buffer, dummy_arg);
    assert(last_format_dst == buffer + 0x1054);
    assert(last_format_src == dummy_arg);
    assert(last_set_dst == nullptr);

    // Test func_0023AB50 with null arg1
    last_format_dst = nullptr;
    last_format_src = nullptr;
    last_set_dst = nullptr;

    func_0023AB50(buffer, nullptr);
    assert(last_set_dst == buffer + 0x1054);
    assert(last_format_dst == nullptr);
    assert(last_format_src == nullptr);

    std::cout << "kt_gs_render_23ab30 native tests passed." << std::endl;
    return 0;
}
