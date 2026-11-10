#include <cassert>
#include <cstdlib>
#include <iostream>
#include "zone_spatial_grid_zero_vector3.h"

struct Vector3Int {
    int x;
    int y;
    int z;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }

    int case_id = std::atoi(argv[1]);
    Vector3Int v;

    switch (case_id) {
        case 0: {
            v.x = 10;
            v.y = 20;
            v.z = 30;
            Vector3Int *res = func_001E62A0(&v);
            assert(res == &v);
            assert(v.x == 0);
            assert(v.y == 0);
            assert(v.z == 0);
            break;
        }
        case 1: {
            v.x = 0;
            v.y = 0;
            v.z = 0;
            Vector3Int *res = func_001E62A0(&v);
            assert(res == &v);
            assert(v.x == 0);
            assert(v.y == 0);
            assert(v.z == 0);
            break;
        }
        case 2: {
            v.x = -100;
            v.y = -200;
            v.z = -300;
            Vector3Int *res = func_001E62A0(&v);
            assert(res == &v);
            assert(v.x == 0);
            assert(v.y == 0);
            assert(v.z == 0);
            break;
        }
        default:
            return 2;
    }

    return 0;
}
