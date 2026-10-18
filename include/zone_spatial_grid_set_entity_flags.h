#ifndef ZONE_SPATIAL_GRID_SET_ENTITY_FLAGS_H
#define ZONE_SPATIAL_GRID_SET_ENTITY_FLAGS_H

struct EntitySubObject {
    char pad_00[6];
    unsigned char flags;
};

struct SpatialEntity {
    char pad_00[0x50];
    EntitySubObject *sub_obj;
};

extern "C" {
void func_001EE050(void *self, SpatialEntity *entity, int flag);
}

#endif
