#ifndef ZONE_SPATIAL_GRID_RECORD_RAYCAST_HIT_H
#define ZONE_SPATIAL_GRID_RECORD_RAYCAST_HIT_H

struct SpatialGrid;
struct HitNode {
    char pad_00[0x18];
    unsigned int coord;
};
struct Point2D {
    float x;
    float y;
};

extern "C" {
int func_001F02A0(SpatialGrid *self, HitNode *node, Point2D *pos);
}

#endif
