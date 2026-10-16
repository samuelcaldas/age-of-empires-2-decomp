#pragma exceptions off

#include "zone_spatial_view_check_status.h"

extern "C" {
void func_26AD60(void *self, int flag);
float func_1DD650(void *self);
extern float D_004E2960;
}

struct SpatialEntityState {
    char pad[0x106];
    unsigned char field_106;
};

extern "C" float func_001D8AB0(SpatialEntityState *self) {
    if (self->field_106 != 0) {
        func_26AD60(self, 0x20);
        return D_004E2960;
    }
    return func_1DD650(self);
}
