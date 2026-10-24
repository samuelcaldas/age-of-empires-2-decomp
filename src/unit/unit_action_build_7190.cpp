#pragma exceptions off
#include "unit_action_build_7190.h"

struct SpatialFacetEntry {
    float min_angle1;
    float max_angle1;
    float min_angle2;
    float max_angle2;
    float offset_x;
    float offset_y;
    float offset_z;
    float offset_w;
};

extern "C" {
    extern SpatialFacetEntry D_00486C70[25];
    float func_33D590(float dy, float dx);
    int func_277180(void *self);
}

#if defined(__LP64__) || defined(_LP64)
#define MAP_WIDTH_OFFSET  0x10
#define MAP_HEIGHT_OFFSET 0x18
#define MAP_ROWS_OFFSET   0x8E8C
#define ENTITY_PROTO_OFFSET 0x8
#else
#define MAP_WIDTH_OFFSET  0x8
#define MAP_HEIGHT_OFFSET 0xC
#define MAP_ROWS_OFFSET   0x8E8C
#define ENTITY_PROTO_OFFSET 0x4
#endif

static bool validate_tile_bounds(void *map, int x, int y) {
    if (y < 0) return false;
    int height = *(int *)((char *)map + MAP_HEIGHT_OFFSET);
    if (y >= height) return false;
    if (x < 0) return false;
    int width = *(int *)((char *)map + MAP_WIDTH_OFFSET);
    return x < width;
}

static void compute_relative_angle(void *self, void *target, float *cached_angle) {
    if (*cached_angle != -1.0f) {
        return;
    }
    float self_x = *(float *)((char *)self + 0x44);
    float self_y = *(float *)((char *)self + 0x48);
    float target_x = *(float *)((char *)target + 0x44);
    float target_y = *(float *)((char *)target + 0x48);
    float angle = func_33D590(target_y - self_y, target_x - self_x);
    if (angle < 0.0f) {
        angle += 6.283185482f;
    }
    *cached_angle = angle;
}

static int check_facet_angles(int facet, float angle, int *counter) {
    if (facet >= 25) {
        return 0;
    }
    SpatialFacetEntry *entry = &D_00486C70[facet];
    if (angle < entry->min_angle1) {
        return 0;
    }
    if (angle <= entry->max_angle1) {
        *counter += 1;
        return 1;
    }
    if (angle < entry->min_angle2) {
        return 0;
    }
    if (angle <= entry->max_angle2) {
        *counter -= 1;
        return 1;
    }
    return 0;
}

static int check_entity(void *self, void *target, void *entity, void *cur_target,
                        float *cached_angle, int *counter) {
    void *proto = *(void **)((char *)entity + ENTITY_PROTO_OFFSET);
    short type = *(short *)((char *)proto + 0xE);
    if (type != 0x22) {
        return 0;
    }
    if (entity == cur_target) {
        return 0;
    }
    compute_relative_angle(self, target, cached_angle);
    unsigned char facet = *(unsigned char *)((char *)entity + 0x35);
    if (func_277180(self) == 0) {
        return 0;
    }
    return check_facet_angles(facet, *cached_angle, counter);
}

int func_277190(void *self, void *target, int tile_x, int tile_y,
                float min_x, float min_y, float max_x, float max_y,
                void *map, void *cur_target, float *cached_angle, int *counter) {
    (void)min_x; (void)min_y; (void)max_x; (void)max_y;
    if (!validate_tile_bounds(map, tile_x, tile_y)) {
        return 0;
    }

    void **tile_rows = *(void ***)((char *)map + MAP_ROWS_OFFSET);
    char *row = (char *)tile_rows[tile_y];
    char *tile = row + (tile_x * 28);

    unsigned char count = *(unsigned char *)(tile + 0xD);
    void **entity_list = *(void ***)(tile + 0x14);

    for (int i = 0; i < count; ++i) {
        void *entity = entity_list[i];
        if (check_entity(self, target, entity, cur_target, cached_angle, counter)) {
            return 1;
        }
    }
    return 0;
}
