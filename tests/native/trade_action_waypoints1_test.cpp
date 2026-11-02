#include <cassert>
#include <cstdlib>
#include <iostream>
#include "trade_action_waypoints1.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

class TargetObj {
public:
    virtual void vfn0() {}
    virtual void vfn1() {}
    virtual void vfn2() {}
    virtual void vfn3() {}
    virtual void vfn4() {}
    virtual void vfn5() {}
    virtual void vfn6() {}
    virtual void vfn7() {}
    virtual void vfn8() {}
    virtual void vfn9() {}
    virtual void vfn10() {}
    virtual void vfn11() {}
    virtual void vfn12() {}
    virtual void vfn13() {}
    virtual void vfn14() {}
    virtual void vfn15() {}
    virtual void vfn16() {}
    virtual void vfn17() {}
    virtual void vfn18() {}
    virtual void vfn19() {}
    virtual void vfn20() {}
    virtual void vfn21() {}
    virtual void vfn22() {}
    virtual void vfn23() {}
    virtual void vfn24() {}
    virtual void vfn25() {}
    virtual void vfn26() {}
    virtual void vfn27() {}
    virtual void vfn28() {}
    virtual void vfn29() {}
    virtual void vfn30() {}
    virtual void vfn31() {}
    virtual void vfn32() {}
    virtual void vfn33() {}
    virtual void vfn34() {}
    virtual void vfn35() {}
    virtual void vfn36() {}
    virtual void vfn37() {}
    virtual void vfn38() {}
    virtual void vfn39() {}
    virtual void vfn40() {}
    virtual void vfn41() {}
    virtual void vfn42() {}
    virtual void vfn43() {}
    virtual void vfn44() {}
    virtual void vfn45() {}
    virtual void vfn46() {}
    virtual void vfn47() {}
    virtual void vfn48() {}
    virtual void vfn49() {}
    virtual void vfn50() {}
    virtual void vfn51() {}
    virtual void vfn52() {}
    virtual void vfn53() {}
    virtual void vfn54() {}
    virtual void vfn55() {}
    virtual void vfn56() {}
    virtual void vfn57() {}
    virtual void vfn58() {}
    virtual void vfn59() {}
    virtual void vfn60() {}
    virtual void vfn61() {}
    virtual void vfn62() {}
    virtual void vfn63() {}
    virtual void vfn64() {}
    virtual void vfn65() {}
    virtual void vfn66() {}
    virtual void vfn67() {}
    virtual void vfn68() {}
    virtual void vfn69() {}
    virtual void vfn70() {}
    virtual void vfn71() {}
    virtual void vfn72() {}
    virtual void vfn73() {}
    virtual void vfn74() {}
    virtual void vfn75() {}
    virtual void vfn76() {}
    virtual void vfn77() {}
    virtual void vfn78() {}
    virtual void vfn79() {}
    virtual void vfn80() {}
    virtual void vfn81() {}
    virtual void vfn82() {}
    virtual void vfn83() {}
    virtual void vfn84() {}
    virtual void vfn85() {}
    virtual void vfn86() {}
    virtual void vfn87() {}
    virtual void vfn88() {}
    virtual void vfn89() {}
    virtual void vfn90() {}
    virtual void vfn91() {}
    virtual void vfn92() {}
    virtual void vfn93() {}
    virtual void vfn94() {}
    virtual int Target609(short id) { return (id == 99) ? 1 : 0; }
    virtual int Target604(short id) { return (id == 44) ? 1 : 0; }
    virtual int Target603(short id) { return (id == 33) ? 1 : 0; }
    virtual int Target618(short id) { return (id == 18) ? 1 : 0; }

    char pad_04[0x4];
    void *m_world;
};

static short s_last_cmd = 0;
static short s_dispatched_target_id = 0;
static short s_dispatched_obj_type = 0;
static float s_dispatched_x = 0;
static float s_dispatched_y = 0;
static float s_dispatched_z = 0;
static void *s_mock_obj = nullptr;

extern "C" {
void *func_332e60(void *mgr, short id) {
    return s_mock_obj;
}

short func_001471B0(TradeAction *self, short cmd) {
    s_last_cmd = cmd;
    return cmd;
}

int func_14bd90(TradeAction *self, short target_id, short obj_type, float x, float y, float z) {
    s_dispatched_target_id = target_id;
    s_dispatched_obj_type = obj_type;
    s_dispatched_x = x;
    s_dispatched_y = y;
    s_dispatched_z = z;
    return 1;
}
}

int main() {
    TargetObj target;
    char mock_world[3000];
    target.m_world = mock_world;

    TradeAction action = {};
    action.m_target = &target;

    // Test guard: self->m_field48 == 604 with flag 0
    action.m_field48 = 604;
    assert(func_00149FE0(&action, 44, 0) == 0);

    // Test with flag 1 (bypass guard), Target604 returns 1, mock obj null
    s_mock_obj = nullptr;
    int res = func_00149FE0(&action, 44, 1);
    assert(res == 1);
    assert(s_last_cmd == 604);
    assert(s_dispatched_target_id == 44);
    assert(s_dispatched_obj_type == -1);
    assert(s_dispatched_x == 0.0f);
    assert(s_dispatched_y == 0.0f);
    assert(s_dispatched_z == 0.0f);

    // Test Target603
    action.m_field48 = 0;
    res = func_0014A0D0(&action, 33, 0);
    assert(res == 1);
    assert(s_last_cmd == 603);
    assert(s_dispatched_target_id == 33);
    assert(s_dispatched_obj_type == -1);

    // Test Target609
    res = func_0014A1C0(&action, 99, 0);
    assert(res == 1);
    assert(s_last_cmd == 609);

    // Test Target618
    res = func_0014A2B0(&action, 18, 0);
    assert(res == 1);
    assert(s_last_cmd == 618);

    // Test invalid target ID where Target returns 0
    res = func_0014A2B0(&action, 999, 0);
    assert(res == 0);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
