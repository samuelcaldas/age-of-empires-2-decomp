#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CD620(void *self, int width_param, int height_param, int arg4);

static int g_alloc_handle_calls = 0;
static int g_activate_handle_calls = 0;
static int g_last_activated_handle = -1;
static int g_c97d0_calls = 0;
static int g_c97d0_w = -1, g_c97d0_h = -1;
static int g_ctor_calls = 0;
static int g_gen_calls = 0;
static int g_delete_calls = 0;

int func_1AAB30(void) {
    g_alloc_handle_calls++;
    return 0x42;
}

void func_1AAB70(int handle) {
    g_activate_handle_calls++;
    g_last_activated_handle = handle;
}

void func_001C97D0(void *self, int p1, void *world, int p3, int width, int height) {
    g_c97d0_calls++;
    g_c97d0_w = width;
    g_c97d0_h = height;
}

static char g_gen_mem[0x2F7F8];
void *func_100850(int size) {
    assert(size == 0x2F7F8);
    std::memset(g_gen_mem, 0, sizeof(g_gen_mem));
    return g_gen_mem;
}

static void mock_gen_exec(void *obj) {
    assert(obj == g_gen_mem);
    g_gen_calls++;
}

static void mock_gen_delete(void *obj, int flag) {
    assert(obj == g_gen_mem);
    assert(flag == 1);
    g_delete_calls++;
}

static void *g_gen_vtable[10] = {
    nullptr, nullptr, (void *)&mock_gen_delete, (void *)&mock_gen_exec, nullptr
};

void func_22F2F0(void *obj, int arg4, int p3) {
    g_ctor_calls++;
    assert(p3 == -1);
    *reinterpret_cast<void ***>(obj) = g_gen_vtable;
}

static char g_sys_mem[0x60];
void *D_004E3180 = g_sys_mem;
}

struct WorldObject { char pad_0[0x31]; unsigned char mode; };
struct SystemManager { char pad_0[0x4C]; int handle, f_50, f_54; };
struct ZoneLayout { char pad_0[8]; int width, height; char pad_10[0x8ED8]; WorldObject *m_world; };

static void setup_test(ZoneLayout *zm, WorldObject *world, SystemManager *sys, int handle) {
    std::memset(zm, 0, sizeof(ZoneLayout));
    std::memset(world, 0, sizeof(WorldObject));
    std::memset(sys, 0, sizeof(SystemManager));
    world->mode = 1;
    zm->width = 16;
    zm->height = 12;
    zm->m_world = world;
    sys->handle = handle;
    D_004E3180 = sys;
    g_alloc_handle_calls = 0; g_activate_handle_calls = 0;
    g_c97d0_calls = 0; g_ctor_calls = 0; g_gen_calls = 0; g_delete_calls = 0;
}

static void test_mode_guard_and_handle_alloc() {
    ZoneLayout zm; WorldObject world; SystemManager sys;
    setup_test(&zm, &world, &sys, -1); // handle == -1 -> triggers alloc

    func_001CD620(&zm, 20, 20, 5);
    // Mode restored to original 1
    assert(world.mode == 1);
    // Allocated handle 0x42
    assert(g_alloc_handle_calls == 1);
    assert(sys.f_54 == 0x42);
    assert(g_activate_handle_calls == 2);
    // Generator lifecycle executed
    assert(g_c97d0_calls == 1);
    assert(g_c97d0_w == 20 && g_c97d0_h == 20);
    assert(g_ctor_calls == 1);
    assert(g_gen_calls == 1);
    assert(g_delete_calls == 1);
}

static void test_handle_reuse_and_bounds_defaults() {
    ZoneLayout zm; WorldObject world; SystemManager sys;
    setup_test(&zm, &world, &sys, 0x77); // valid handle -> no alloc

    func_001CD620(&zm, -1, -1, 9);
    assert(world.mode == 1);
    assert(g_alloc_handle_calls == 0); // Reused
    assert(sys.f_54 == 0x77);
    // Negative parameters defaulted to zm dimensions (16, 12)
    assert(g_c97d0_calls == 1);
    assert(g_c97d0_w == 16 && g_c97d0_h == 12);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "handle_reuse") {
        test_handle_reuse_and_bounds_defaults();
    } else {
        test_mode_guard_and_handle_alloc();
        test_handle_reuse_and_bounds_defaults();
    }
    return 0;
}
