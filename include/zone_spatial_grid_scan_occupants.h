#ifndef ZONE_SPATIAL_GRID_SCAN_OCCUPANTS_H
#define ZONE_SPATIAL_GRID_SCAN_OCCUPANTS_H

struct Point2D {
    float x;
    float y;
};

struct Polygon {
    int num_points;
    Point2D *points;
};

extern "C" {
int func_001E4F50(const Polygon *poly, float px, float py);
}

#endif // ZONE_SPATIAL_GRID_SCAN_OCCUPANTS_H
