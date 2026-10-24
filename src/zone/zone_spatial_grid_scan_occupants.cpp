#pragma exceptions off

#include "zone_spatial_grid_scan_occupants.h"

extern "C" int func_001E4F50(const Polygon *poly, float px, float py) {
    int inside = 0;
    int n = poly->num_points;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        float yi = poly->points[i].y;
        float yj = poly->points[j].y;
        if (((yi <= py && py < yj) || (yj <= py && py < yi))) {
            float xi = poly->points[i].x;
            float xj = poly->points[j].x;
            if (px < (xj - xi) * (py - yi) / (yj - yi) + xi) {
                inside = !inside;
            }
        }
        j = i;
    }
    return inside;
}
