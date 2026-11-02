#pragma exceptions off

#include "zone_spatial_grid_dispatch_edge.h"

struct SpatialGrid;

extern "C" {
unsigned char func_1E5510(SpatialGrid *self, float *p1, float *p2, int *p3, int *p4, int *p5);
unsigned char func_1E5620(SpatialGrid *self, float *p1, float *p2, int *p3, int *p4, int *p5);
unsigned char func_1E5730(SpatialGrid *self, float *p1, float *p2, int *p3, int *p4, int *p5);
unsigned char func_1E5840(SpatialGrid *self, float *p1, float *p2, int *p3, int *p4, int *p5);

unsigned char func_001E5460(SpatialGrid *self, float *p1, int a2, float *p3, int *p4, int *p5, int *p6) {
    switch (a2) {
    case 0:
        return func_1E5510(self, p1, p3, p4, p5, p6);
    case 1:
        return func_1E5620(self, p1, p3, p4, p5, p6);
    case 2:
        return func_1E5730(self, p1, p3, p4, p5, p6);
    case 3:
        return func_1E5840(self, p1, p3, p4, p5, p6);
    }
    return 0;
}

}
