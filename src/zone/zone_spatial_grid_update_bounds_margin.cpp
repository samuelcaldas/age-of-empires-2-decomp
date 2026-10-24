#pragma exceptions off
#include "zone_spatial_grid_update_bounds_margin.h"

struct EntityData {
    char pad_00[0x20];
    float size_x;
    float size_y;
    char pad_28[0x82 - 0x28];
    unsigned char mode;
};

struct Entity {
    char pad_00[4];
    EntityData *data;
    char pad_08[0x44 - 0x8];
    float pos_x;
    float pos_y;
    char pad_4C[4];
    void *sub_obj;
};

extern "C" int func_001EDF30(SpatialGrid *self, Entity *entity) {
    EntityData *data = entity->data;
    unsigned char mode = data->mode;
    if (mode <= 0) {
        return 0;
    }
    if (mode < 3) {
        float size_x = data->size_x;
        float pos_x = entity->pos_x;
        float size_y = data->size_y;
        float pos_y = entity->pos_y;

        int min_x = func_123350(pos_x - size_x);
        int min_y = func_123350(pos_y - size_y);
        int max_x = func_123350(pos_x + size_x) - 1;
        int max_y = func_123350(pos_y + size_y) - 1;

        func_1EE660(self, min_x, min_y, max_x, max_y, (int)(long)entity);

        if (mode == 1) {
            return 1;
        }

        if (entity->sub_obj != 0) {
            func_1EE780(self, (int)(long)entity->sub_obj, 0, 0, 0);
            entity->sub_obj = 0;
            return 1;
        }
        return 0;
    }
    return 0;
}
