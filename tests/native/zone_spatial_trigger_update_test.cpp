#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialTargetObject {
    char pad[0x38];
    unsigned char flag_38;
};

extern "C" {
void func_001D8480(SpatialTargetObject *self, void *arg1);

static int g_func_194d70_calls = 0;
static void *g_last_arg1 = nullptr;

void func_194D70(void *self, void *arg1) {
    g_func_194d70_calls++;
    g_last_arg1 = arg1;
}
}

static void test_trigger_update_flag_zero() {
    g_func_194d70_calls = 0;
    SpatialTargetObject obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.flag_38 = 0;

    func_001D8480(&obj, reinterpret_cast<void *>(0x1234));
    assert(g_func_194d70_calls == 0);
}

static void test_trigger_update_null_arg1() {
    g_func_194d70_calls = 0;
    SpatialTargetObject obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.flag_38 = 1;

    func_001D8480(&obj, nullptr);
    assert(g_func_194d70_calls == 0);
}

static void test_trigger_update_valid() {
    g_func_194d70_calls = 0;
    SpatialTargetObject obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.flag_38 = 1;

    func_001D8480(&obj, reinterpret_cast<void *>(0x1234));
    assert(g_func_194d70_calls == 1);
    assert(g_last_arg1 == reinterpret_cast<void *>(0x1234));
}

int main(int argc, char **argv) {
    test_trigger_update_flag_zero();
    test_trigger_update_null_arg1();
    test_trigger_update_valid();
    return 0;
}
