#include <cassert>
#include <cstddef>
#include <cstring>
#include <cstdlib>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct ProjectileConfig {
    char pad[0x20];
    float radius_x;
    float radius_y;
};

struct CollisionTarget {
    char pad[8];
    void *entity;
};

struct ProjectileMotion {
    void **vtable;
    ProjectileConfig *config;
    char pad_44[0x44 - 0x8];
    float x;
    float y;
    float z;
};

struct HitList {
    int count;
};

void *D_00948FD0[4];
int D_004E324C = 0;

extern "C" {
void *func_001D8900(ProjectileMotion *self, float tx, float ty, float tz);

static int g_func_1db890_calls = 0;
static int g_func_1ed050_calls = 0;
static int g_func_1ecfd0_calls = 0;

void *func_100850(unsigned int size) {
    return std::malloc(size);
}

void func_1ECFC0(void *self) {
    HitList *l = reinterpret_cast<HitList *>(self);
    l->count = 0;
}

void func_1DB890(void *self, void *target_pos, void *cur_pos, int a3, int t0, int t1, float f12) {
    g_func_1db890_calls++;
}

float func_3675D0(void *obj) {
    return 10.0f; // radius = 10.0f
}

void func_1ED050(void *list, void *target, int zero, float f12, float f13) {
    g_func_1ed050_calls++;
    HitList *l = reinterpret_cast<HitList *>(list);
    l->count++;
}

void func_1ECFD0(void *list, int flag) {
    g_func_1ecfd0_calls++;
    std::free(list);
}
}

static void test_collision_zero_radius() {
    g_func_1db890_calls = 0;

    ProjectileConfig cfg;
    std::memset(&cfg, 0, sizeof(cfg));
    cfg.radius_x = 0.0f;
    cfg.radius_y = 5.0f;

    ProjectileMotion motion;
    std::memset(&motion, 0, sizeof(motion));
    motion.config = &cfg;

    void *res = func_001D8900(&motion, 1.0f, 2.0f, 3.0f);
    assert(res == nullptr);
    assert(g_func_1db890_calls == 0);
}

static void test_collision_with_hit() {
    g_func_1db890_calls = 0;
    g_func_1ed050_calls = 0;
    g_func_1ecfd0_calls = 0;

    ProjectileConfig cfg;
    std::memset(&cfg, 0, sizeof(cfg));
    cfg.radius_x = 5.0f;
    cfg.radius_y = 5.0f;

    ProjectileMotion motion;
    std::memset(&motion, 0, sizeof(motion));
    motion.config = &cfg;
    motion.z = 20.0f;

    // Entity at z = 22.0f (diff = 2.0f <= self_radius = 10.0f)
    char ent_data[0x60];
    std::memset(ent_data, 0, sizeof(ent_data));
    *reinterpret_cast<float *>(ent_data + 0x4C) = 22.0f;

    CollisionTarget target;
    std::memset(&target, 0, sizeof(target));
    target.entity = ent_data;

    D_00948FD0[0] = &target;
    D_004E324C = 1;

    void *res = func_001D8900(&motion, 1.0f, 2.0f, 3.0f);
    assert(res != nullptr);
    assert(g_func_1db890_calls == 1);
    assert(g_func_1ed050_calls == 1);
    assert(g_func_1ecfd0_calls == 0);

    HitList *l = reinterpret_cast<HitList *>(res);
    assert(l->count == 1);
    std::free(res);
}

int main(int argc, char **argv) {
    test_collision_zero_radius();
    test_collision_with_hit();
    return 0;
}
