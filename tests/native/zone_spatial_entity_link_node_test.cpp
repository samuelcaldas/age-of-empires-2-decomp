#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "zone_spatial_entity_link_node.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Point2i {
    int x;
    int y;
    int z;
};

struct SpatialEntity {
    char pad[0x90];
    Vector3 pos;
};

static int s_func_1fe340_calls = 0;
static Vector3 s_passed_pos;
static Vector3 s_passed_dest;

extern "C" {
void func_1FE340(void *p0, void *p1, void *p2, void *p3, int p4, int p5, int p6, int p7) {
    s_func_1fe340_calls++;
    if (p2) {
        s_passed_pos = *(Vector3 *)p2;
    }
    if (p3) {
        s_passed_dest = *(Vector3 *)p3;
    }
}
}

static void test_link_node_converts_point_and_calls() {
    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.pos.x = 10.0f;
    ent.pos.y = 20.0f;
    ent.pos.z = 30.0f;

    Point2i pt;
    pt.x = 5;
    pt.y = 8;
    pt.z = 0;

    s_func_1fe340_calls = 0;
    func_001DDB70(&ent, &pt);

    assert(s_func_1fe340_calls == 1);
    assert(s_passed_pos.x == 10.0f);
    assert(s_passed_pos.y == 20.0f);
    assert(s_passed_pos.z == 30.0f);

    assert(s_passed_dest.x == 5.0f);
    assert(s_passed_dest.y == 0.0f);
    assert(s_passed_dest.z == 8.0f);
}

int main() {
    test_link_node_converts_point_and_calls();
    std::printf("zone_spatial_entity_link_node_test passed\n");
    return 0;
}
