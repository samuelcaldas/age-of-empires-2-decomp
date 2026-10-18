#include <cassert>
#include <cstring>
#include "zone_spatial_grid_link_header_remove.h"
#include "zone_spatial_grid_link_header_prepend.h"
#include "zone_spatial_grid_buffer_manager_init.h"
#include "zone_spatial_grid_buffer_manager_destructor.h"
#include "zone_spatial_grid_buffer_manager_setup.h"
#include "zone_spatial_grid_buffer_manager_insert.h"

extern "C" {
void func_100670(void *ptr) {}
void func_116F68(void *ptr) { delete[] (char *)ptr; }
void *func_1143F8(int count, int elem_size) { return new char[count * elem_size]; }
}

int main() {
    struct SpatialGridBufferManager {
        void *buffer;
        char pad_04[0xAF0];
        short cap;
        short count;
    } mgr;

    void *res = func_001ECB70(&mgr);
    assert(res == &mgr);
    assert(mgr.count == 0);
    assert(mgr.cap == 0);
    assert(mgr.buffer == nullptr);

    int dummy_buf = 0;
    func_001ECBE0(&mgr, &dummy_buf);
    assert(mgr.cap == 0xC8);
    assert(mgr.count == 0);
    assert(mgr.buffer == &dummy_buf);

    func_001ECB90(&mgr, 0);

    return 0;
}
