#ifndef ZONE_SPATIAL_GRID_DISPATCH_EDGE_NORTH_H
#define ZONE_SPATIAL_GRID_DISPATCH_EDGE_NORTH_H

struct SpatialGridItem {
    float minX;
    float minY;
    float maxX;
    float maxY;
    int f10;
};

struct SpatialGrid {
    char pad[0x20];
    int f20;
    int pad24;
    SpatialGridItem *f28;
};

extern "C" {
unsigned char func_001E5520(SpatialGrid *self, float *pt, int a2, float *out_pt, int *out_t0, int *out_t1);
}

#endif // ZONE_SPATIAL_GRID_DISPATCH_EDGE_NORTH_H
