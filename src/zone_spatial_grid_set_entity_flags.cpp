#pragma exceptions off
#include "zone_spatial_grid_set_entity_flags.h"

extern "C" void func_001EE050(void *self, SpatialEntity *entity, int flag) {
    EntitySubObject *sub = entity->sub_obj;
    if (sub != 0) {
        sub->flags = (sub->flags & 0x0F) | (unsigned char)flag;
    }
}
