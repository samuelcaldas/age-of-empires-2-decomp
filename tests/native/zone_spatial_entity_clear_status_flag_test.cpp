#include <cassert>
#include <iostream>
#include "zone_spatial_entity_clear_status_flag.h"

static void *g_flag_obj = 0;
static int g_flag_val = 0;

extern "C" {
int func_26AD20(void *action, int flag) {
    g_flag_obj = action;
    g_flag_val = flag;
    return 1;
}
}

struct MockSpatialEntity {
    virtual int getState() { return 0; }
    virtual void pad01() {} virtual void pad02() {} virtual void pad03() {} virtual void pad04() {}
    virtual void pad05() {} virtual void pad06() {} virtual void pad07() {} virtual void pad08() {}
    virtual void pad09() {} virtual void pad0a() {} virtual void pad0b() {} virtual void pad0c() {}
    virtual void pad0d() {} virtual void pad0e() {} virtual void pad0f() {} virtual void pad10() {}
    virtual void pad11() {} virtual void pad12() {} virtual void pad13() {} virtual void pad14() {}
    virtual void pad15() {} virtual void pad16() {} virtual void pad17() {} virtual void pad18() {}
    virtual void pad19() {} virtual void pad1a() {} virtual void pad1b() {} virtual void pad1c() {}
    virtual void pad1d() {} virtual void pad1e() {} virtual void pad1f() {} virtual void pad20() {}
    virtual void pad21() {} virtual void pad22() {} virtual void pad23() {} virtual void pad24() {}
    virtual void pad25() {} virtual void pad26() {} virtual void pad27() {} virtual void pad28() {}
    virtual void pad29() {} virtual void pad2a() {} virtual void pad2b() {} virtual void pad2c() {}
    virtual void pad2d() {} virtual void pad2e() {} virtual void pad2f() {} virtual void pad30() {}
    virtual void pad31() {} virtual void pad32() {} virtual void pad33() {} virtual void pad34() {}
    virtual void pad35() {} virtual void pad36() {} virtual void pad37() {} virtual void pad38() {}
    virtual void pad39() {} virtual void pad3a() {} virtual void pad3b() {} virtual void pad3c() {}
    virtual void pad3d() {} virtual void pad3e() {} virtual void pad3f() {} virtual void pad40() {}
    virtual void pad41() {} virtual void pad42() {} virtual void pad43() {} virtual void pad44() {}
    virtual void pad45() {} virtual void pad46() {} virtual void pad47() {} virtual void pad48() {}
    virtual void pad49() {} virtual void pad4a() {} virtual void pad4b() {} virtual void pad4c() {}
    virtual void pad4d() {} virtual void pad4e() {} virtual void pad4f() {} virtual void pad50() {}
    virtual int func14C() { return m_state; }

    int m_state;
};

int main() {
    MockSpatialEntity entity;

    // Test 1: state = 6 -> (state - 6) == 0 < 2 -> returns 0, does not call func_26AD20
    entity.m_state = 6;
    g_flag_obj = 0;
    int res = func_001DEAE0((SpatialEntity *)&entity);
    assert(res == 0);
    assert(g_flag_obj == 0);

    // Test 2: state = 7 -> (state - 6) == 1 < 2 -> returns 0
    entity.m_state = 7;
    res = func_001DEAE0((SpatialEntity *)&entity);
    assert(res == 0);
    assert(g_flag_obj == 0);

    // Test 3: state = 5 -> (state - 6) >= 2 -> calls func_26AD20(self, 0x40)
    entity.m_state = 5;
    res = func_001DEAE0((SpatialEntity *)&entity);
    assert(res == 1);
    assert(g_flag_obj == &entity);
    assert(g_flag_val == 0x40);

    std::cout << "zone_spatial_entity_clear_status_flag_test passed\n";
    return 0;
}
