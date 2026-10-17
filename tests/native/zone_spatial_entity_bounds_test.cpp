#include <cassert>
#include "zone_spatial_entity_update_velocity_threshold.h"
#include "zone_spatial_entity_dispatch_registration.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static int s_func_151C80_called = 0;
extern "C" void func_151C80(void *ent) {
    s_func_151C80_called++;
}

extern "C" float func_333EB0(void *world) {
    return 1.0f;
}

extern "C" void func_1FCC40(void *v, void *ent, float f0) {
}

extern "C" float func_1B3860(float val) {
    return 5.0f;
}

static int s_func_1EE040_flag = -1;
extern "C" void func_1EE040(void *mgr, void *ent, int flag) {
    s_func_1EE040_flag = flag;
}

void *D_004D6F34 = (void *)0x12345678;

static int mock_method270_true() {
    return 1;
}

static int mock_method270_false() {
    return 0;
}

static void *s_mock_vtable[256];

static void test_velocity_threshold_null() {
    char ent_buffer[0x100];
    for (int i = 0; i < sizeof(ent_buffer); i++) ent_buffer[i] = 0;

    s_func_151C80_called = 0;
    func_001DD710((SpatialEntity *)ent_buffer);
    assert(*(float *)(ent_buffer + 0x68) == 0.0f);
    assert(s_func_151C80_called == 1);
}

static void test_dispatch_registration() {
    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method270_true;

    char ent_buffer[0x100];
    for (int i = 0; i < sizeof(ent_buffer); i++) ent_buffer[i] = 0;
    *(void **)ent_buffer = s_mock_vtable;

    s_func_1EE040_flag = -1;
    func_001DD790((SpatialEntity *)ent_buffer);
    assert(s_func_1EE040_flag == 0x10);

    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method270_false;
    s_func_1EE040_flag = -1;
    func_001DD790((SpatialEntity *)ent_buffer);
    assert(s_func_1EE040_flag == 0);
}

int main(int argc, char **argv) {
    test_velocity_threshold_null();
    test_dispatch_registration();
    return 0;
}
