#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_record_raycast_hit.h"

struct HitResult {
    void *node;
    int id;
    float x;
    float y;
};

struct SpatialGrid {
    char pad_00[0x12B590];
    HitResult *results;
    int *out_count;
    int max_count;
};

int main() {
    SpatialGrid *grid = (SpatialGrid *)std::malloc(sizeof(SpatialGrid));
    std::memset(grid, 0, sizeof(SpatialGrid));

    HitResult results[4];
    std::memset(results, 0, sizeof(results));
    int count = 0;

    grid->results = results;
    grid->out_count = &count;
    grid->max_count = 2;

    HitNode n1;
    std::memset(&n1, 0, sizeof(n1));
    n1.coord = 0x1234;

    HitNode n2;
    std::memset(&n2, 0, sizeof(n2));
    n2.coord = 0x5678;

    HitNode n3;
    std::memset(&n3, 0, sizeof(n3));
    n3.coord = 0x9ABC;

    Point2D p1 = {1.5f, 2.5f};
    Point2D p2 = {3.5f, 4.5f};
    Point2D p3 = {5.5f, 6.5f};

    // First hit
    int res1 = func_001F02A0(grid, &n1, &p1);
    assert(res1 == 1);
    assert(count == 1);
    assert(results[0].node == &n1);
    assert(results[0].id == 0x1234);
    assert(results[0].x == 1.5f);
    assert(results[0].y == 2.5f);

    // Second hit
    int res2 = func_001F02A0(grid, &n2, &p2);
    assert(res2 == 1);
    assert(count == 2);
    assert(results[1].node == &n2);
    assert(results[1].id == 0x5678);
    assert(results[1].x == 3.5f);
    assert(results[1].y == 4.5f);

    // Third hit exceeds max_count
    int res3 = func_001F02A0(grid, &n3, &p3);
    assert(res3 == 0);
    assert(count == 2);

    std::free(grid);
    return 0;
}
