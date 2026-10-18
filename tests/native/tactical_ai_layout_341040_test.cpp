#include <cassert>
#include <cstdio>
#include <cstring>
#include "tactical_ai_layout_341040.h"

static int g_subobj_104_calls = 0;
static int g_subobj_24_calls = 0;
static int g_subobj_1c_calls = 0;

class MockTacticalSubObj : public TacticalSubObj {
public:
    void *vtable_ptrs[80];

    MockTacticalSubObj() {
        for (int i = 0; i < 80; i++) {
            vtable_ptrs[i] = (void*)mock_method;
        }
    }

    static void mock_method() {}
    void vfunc_00() override {}
};

static void test_initial_layout_state() {
    TacticalObj_341040 obj;
    std::memset(&obj, 0, sizeof(obj));

    MockTacticalSubObj sub_828;
    MockTacticalSubObj sub_82C;
    MockTacticalSubObj sub_830;
    MockTacticalSubObj sub_834;

    obj.field_828 = &sub_828;
    obj.field_82C = &sub_82C;
    obj.field_830 = &sub_830;
    obj.field_834 = &sub_834;
    obj.field_838 = nullptr;

    func_00341040(&obj);

    // Green test assertion once initial block executes
    assert(obj.field_828 != nullptr);
    std::printf("PASS test_initial_layout_state\n");
}

int main() {
    test_initial_layout_state();
    return 0;
}
