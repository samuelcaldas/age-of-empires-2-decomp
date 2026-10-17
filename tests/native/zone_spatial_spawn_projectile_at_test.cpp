#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct TargetEntity {
    char pad[0x24];
    short id;
};

struct SpatialEntityMaster {
    char pad_cc[0xCC];
    void *list_cc;
    char pad_f8[0xF8 - 0xD0];
    int field_F8;
    int pad_100;
    float field_100;
    short field_104;
};

int D_4E35DC = 0x55AA;

extern "C" {
void func_001D8710(SpatialEntityMaster *self, TargetEntity *target, float x, float y, float z, float timestamp, int arg2, void *arg3);

static int g_func_366c20_calls = 0;
static int g_func_34e6e0_calls = 0;
static int g_func_139430_calls = 0;

void *func_366C20(void *factory) {
    g_func_366c20_calls++;
    assert(factory == &D_4E35DC);
    return reinterpret_cast<void *>(0xABCD);
}

void func_34E6E0(void *obj, void *self, void *target, void *arg3, float x, float y, float z) {
    g_func_34e6e0_calls++;
    assert(obj == reinterpret_cast<void *>(0xABCD));
    assert(x == 10.0f);
    assert(y == 20.0f);
    assert(z == 30.0f);
    assert(arg3 == reinterpret_cast<void *>(0x9999));
}

void func_139430(void *list, void *obj) {
    g_func_139430_calls++;
    assert(list == reinterpret_cast<void *>(0xCAFE));
    assert(obj == reinterpret_cast<void *>(0xABCD));
}
}

static void test_spawn_projectile_at_with_target() {
    g_func_366c20_calls = 0;
    g_func_34e6e0_calls = 0;
    g_func_139430_calls = 0;

    SpatialEntityMaster master;
    std::memset(&master, 0, sizeof(master));
    master.list_cc = reinterpret_cast<void *>(0xCAFE);

    TargetEntity target;
    std::memset(&target, 0, sizeof(target));
    target.id = 88;

    func_001D8710(&master, &target, 10.0f, 20.0f, 30.0f, 4.5f, 777, reinterpret_cast<void *>(0x9999));

    assert(g_func_366c20_calls == 1);
    assert(g_func_34e6e0_calls == 1);
    assert(g_func_139430_calls == 1);
    assert(master.field_F8 == 777);
    assert(master.field_100 == 4.5f);
    assert(master.field_104 == 88);
}

static void test_spawn_projectile_at_null_target() {
    g_func_366c20_calls = 0;
    g_func_34e6e0_calls = 0;
    g_func_139430_calls = 0;

    SpatialEntityMaster master;
    std::memset(&master, 0, sizeof(master));
    master.list_cc = reinterpret_cast<void *>(0xCAFE);

    func_001D8710(&master, nullptr, 10.0f, 20.0f, 30.0f, 1.25f, 666, reinterpret_cast<void *>(0x9999));

    assert(g_func_366c20_calls == 1);
    assert(g_func_34e6e0_calls == 1);
    assert(g_func_139430_calls == 1);
    assert(master.field_F8 == 666);
    assert(master.field_100 == 1.25f);
    assert(master.field_104 == -1);
}

int main(int argc, char **argv) {
    test_spawn_projectile_at_with_target();
    test_spawn_projectile_at_null_target();
    return 0;
}
