#include <cassert>
#include "zone_spatial_grid_check_point_in_aabb_list.h"
#include "zone_spatial_grid_zero_vector3.h"
#include "zone_spatial_grid_identity_helper.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct AABB {
    float min_x;
    float min_y;
    float max_x;
    float max_y;
    float z;
};

struct Point2D {
    float x;
    float y;
};

struct AABBList {
    char pad[0x20];
    int count;
    char pad2[0x4];
    AABB *items;
};

struct Vector3Int {
    int x;
    int y;
    int z;
};

static void test_check_aabb() {
    AABB boxes[2];
    boxes[0].min_x = 0.0f; boxes[0].min_y = 0.0f; boxes[0].max_x = 10.0f; boxes[0].max_y = 10.0f; boxes[0].z = 0.0f;
    boxes[1].min_x = 20.0f; boxes[1].min_y = 20.0f; boxes[1].max_x = 30.0f; boxes[1].max_y = 30.0f; boxes[1].z = 0.0f;

    AABBList list;
    for (int i = 0; i < sizeof(list); i++) ((char *)&list)[i] = 0;
    list.count = 2;
    list.items = boxes;

    Point2D p_in; p_in.x = 5.0f; p_in.y = 5.0f;
    assert(func_001E6140(&list, &p_in) == 1);

    Point2D p_out; p_out.x = 15.0f; p_out.y = 15.0f;
    assert(func_001E6140(&list, &p_out) == 0);
}

static void test_zero_and_identity() {
    Vector3Int v;
    v.x = 10; v.y = 20; v.z = 30;
    func_001E62A0(&v);
    assert(v.x == 0 && v.y == 0 && v.z == 0);

    char buf[16];
    assert(func_001E62B0(buf) == buf);
}

int main(int argc, char **argv) {
    test_check_aabb();
    test_zero_and_identity();
    return 0;
}
