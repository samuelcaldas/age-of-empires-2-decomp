#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct MapBounds {
    char pad[8];
    int width;
    int height;
};

struct MapObj {
    char pad[0x3C];
    MapBounds *bounds;
};

struct WorldObj {
    char pad[0xB98];
    MapObj *map;
};

class EntityMotion {
public:
    virtual void m0() {}
    virtual void m1() {}
    virtual void m2() {}
    virtual void m3() {}
    virtual void m4() {}
    virtual void m5() {}
    virtual void m6() {}
    virtual void m7() {}
    virtual void m8() {}
    virtual void m9() {}
    virtual void m10() {}
    virtual void m11() {}
    virtual void m12() {}
    virtual void m13() {}
    virtual void m14() {}
    virtual float CheckTerrain(float x, float y, float z) {
        g_check_terrain_calls++;
        return g_mock_terrain_z;
    }
    virtual void m16() {}
    virtual void m17() {}
    virtual void m18() {}
    virtual void m19() {}
    virtual void m20() {}
    virtual void m21() {}
    virtual void m22() {}
    virtual void m23() {}
    virtual void m24() {}
    virtual void m25() {}
    virtual void m26() {}
    virtual void m27() {}
    virtual void m28() {}
    virtual void m29() {}
    virtual void OnOutOfBounds() {
        g_out_of_bounds_calls++;
    }

    char pad_4[4];
    WorldObj *world;
    char pad_44[0x44 - 0xC];
    float x;
    float y;
    float z;
    char pad_70[0x70 - 0x50];
    float vx;
    float vy;
    float vz;

    static int g_check_terrain_calls;
    static int g_out_of_bounds_calls;
    static float g_mock_terrain_z;
};

int EntityMotion::g_check_terrain_calls = 0;
int EntityMotion::g_out_of_bounds_calls = 0;
float EntityMotion::g_mock_terrain_z = 0.0f;

extern "C" {
int func_001D8800(EntityMotion *self);
}

static void test_step_in_bounds_terrain_match() {
    EntityMotion::g_check_terrain_calls = 0;
    EntityMotion::g_out_of_bounds_calls = 0;
    EntityMotion::g_mock_terrain_z = 5.0f;

    MapBounds bounds = { {}, 100, 100 };
    MapObj map = { {}, &bounds };
    WorldObj world = { {}, &map };

    EntityMotion entity;
    std::memset(&entity.pad_4, 0, sizeof(EntityMotion) - sizeof(void *));
    entity.world = &world;
    entity.x = 10.0f;
    entity.y = 20.0f;
    entity.z = 5.0f;
    entity.vx = 1.0f;
    entity.vy = 1.0f;
    entity.vz = 0.0f;

    int res = func_001D8800(&entity);
    assert(res == 1);
    assert(EntityMotion::g_check_terrain_calls == 1);
    assert(EntityMotion::g_out_of_bounds_calls == 0);
}

static void test_step_out_of_bounds_calls_handler() {
    EntityMotion::g_check_terrain_calls = 0;
    EntityMotion::g_out_of_bounds_calls = 0;
    EntityMotion::g_mock_terrain_z = 0.0f;

    MapBounds bounds = { {}, 100, 100 };
    MapObj map = { {}, &bounds };
    WorldObj world = { {}, &map };

    EntityMotion entity;
    std::memset(&entity.pad_4, 0, sizeof(EntityMotion) - sizeof(void *));
    entity.world = &world;
    entity.x = -5.0f; // out of bounds!
    entity.y = 20.0f;
    entity.z = 5.0f;
    entity.vx = 0.0f;
    entity.vy = 0.0f;
    entity.vz = 0.0f;

    int res = func_001D8800(&entity);
    assert(res == 0);
    assert(EntityMotion::g_out_of_bounds_calls == 1);
    assert(EntityMotion::g_check_terrain_calls == 1);
}

int main(int argc, char **argv) {
    test_step_in_bounds_terrain_match();
    test_step_out_of_bounds_calls_handler();
    return 0;
}
