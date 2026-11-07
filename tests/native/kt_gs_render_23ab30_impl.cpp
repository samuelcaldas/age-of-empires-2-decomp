#include "kt_gs_render_23ab30.h"

extern "C" {
    void zone_spatial_grid_format_path_string(void* dst, void* src);
    void zone_spatial_grid_set_string(void* dst);
}

void func_0023AB30(void* obj, u8 val) {
    *((u8*)obj + 8) = val;
}

u8 func_0023AB40(void* obj) {
    return *((u8*)obj + 8);
}

void func_0023AB50(void* obj, void* arg1) {
    u8* p = (u8*)obj + 0x1054;
    if (arg1 != 0) {
        zone_spatial_grid_format_path_string(p, arg1);
    } else {
        zone_spatial_grid_set_string(p);
    }
}
