#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_elevation_mesh_instance.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(CombatSubsystemMeshInstance, m_vtable) == 0x00, "vtable");
static_assert(offsetof(CombatSubsystemMeshInstance, m_field_DC) == 0xDC, "field_DC");

void *D_4DEBF0[4] = {reinterpret_cast<void *>(0x12345678), 0, 0, 0};

static int s_base_ctor_calls = 0;
static void *s_base_ctor_self = 0;

extern "C" void *func_1A2C20(void *self) {
    s_base_ctor_calls++;
    s_base_ctor_self = self;
    return self;
}

static void test_constructor() {
    CombatSubsystemMeshInstance instance;
    std::memset(&instance, 0xCC, sizeof(instance));

    s_base_ctor_calls = 0;
    s_base_ctor_self = 0;

    void *ret = func_003285D0(&instance);

    assert(ret == &instance);
    assert(s_base_ctor_calls == 1);
    assert(s_base_ctor_self == &instance);
    assert(instance.m_vtable == reinterpret_cast<void *>(D_4DEBF0));
    assert(instance.m_field_DC == 0);
}

int main() {
    test_constructor();
    return 0;
}
