#include <cassert>
#include "zone_spatial_grid_evaluate_edge_cross.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialGrid {
    int dummy;
};

// Mock functions
static int g_called_edge = -1;
static void *g_p1 = nullptr;
static void *g_p2 = nullptr;
static void *g_p3 = nullptr;

extern "C" {
unsigned char func_1E59F0(SpatialGrid *self, void *p1, void *p2, void *p3) {
    g_called_edge = 0;
    g_p1 = p1;
    g_p2 = p2;
    g_p3 = p3;
    return 10;
}
unsigned char func_1E5BC0(SpatialGrid *self, void *p1, void *p2, void *p3) {
    g_called_edge = 1;
    g_p1 = p1;
    g_p2 = p2;
    g_p3 = p3;
    return 20;
}
unsigned char func_1E5D90(SpatialGrid *self, void *p1, void *p2, void *p3) {
    g_called_edge = 2;
    g_p1 = p1;
    g_p2 = p2;
    g_p3 = p3;
    return 30;
}
unsigned char func_1E5F60(SpatialGrid *self, void *p1, void *p2, void *p3) {
    g_called_edge = 3;
    g_p1 = p1;
    g_p2 = p2;
    g_p3 = p3;
    return 40;
}
}

static void test_evaluate_edge_cross() {
    SpatialGrid sg;
    int a = 1, b = 2, c = 3;

    assert(func_001E5960(&sg, &a, 0, &b, &c) == 10);
    assert(g_called_edge == 0);
    assert(g_p1 == &a && g_p2 == &b && g_p3 == &c);

    assert(func_001E5960(&sg, &a, 1, &b, &c) == 20);
    assert(g_called_edge == 1);

    assert(func_001E5960(&sg, &a, 2, &b, &c) == 30);
    assert(g_called_edge == 2);

    assert(func_001E5960(&sg, &a, 3, &b, &c) == 40);
    assert(g_called_edge == 3);

    // Default case returns 0
    g_called_edge = -1;
    assert(func_001E5960(&sg, &a, 4, &b, &c) == 0);
    assert(g_called_edge == -1);

    assert(func_001E5960(&sg, &a, -1, &b, &c) == 0);
    assert(g_called_edge == -1);
}

int main(int argc, char **argv) {
    test_evaluate_edge_cross();
    return 0;
}
