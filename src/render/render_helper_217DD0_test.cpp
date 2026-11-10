#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void func_00217DD0(void *self, int arg1, int arg2, int arg3);
void func_00217B50(void *self, int arg3);

static int helper_7B50_calls = 0;
static void *helper_7B50_self = nullptr;
static int helper_7B50_arg3 = 0;
static int vtable_28_calls = 0;
static void *vtable_28_self = nullptr;
static int vtable_28_arg = 0;
static void *vtable[12];

void func_00217B50(void *self, int arg3) {
    helper_7B50_calls++;
    helper_7B50_self = self;
    helper_7B50_arg3 = arg3;
}

static void mock_vtable_28(void *self, int arg) {
    vtable_28_calls++;
    vtable_28_self = self;
    vtable_28_arg = arg;
}
}

static void reset_mocks() {
    helper_7B50_calls = 0;
    helper_7B50_self = nullptr;
    helper_7B50_arg3 = 0;
    vtable_28_calls = 0;
    vtable_28_self = nullptr;
    vtable_28_arg = 0;
}

void test_case_switch_case_1() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    vtable[8] = reinterpret_cast<void *>(mock_vtable_28);
    vtable[10] = reinterpret_cast<void *>(mock_vtable_28);
    *reinterpret_cast<void ***>(obj) = vtable;
    *reinterpret_cast<short *>(obj + 0x124) = 10;

    // case 0: adds arg2 (e.g. 5) to field 0x124, arg3 is flag (e.g. 42)
    func_00217DD0(obj, 0, 5, 42);

    assert(*reinterpret_cast<short *>(obj + 0x124) == 15);
    assert(helper_7B50_calls == 1);
    assert(helper_7B50_self == obj);
    assert(helper_7B50_arg3 == 42);
    assert(vtable_28_calls == 1);
    assert(vtable_28_self == obj);
    assert(vtable_28_arg == 1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_switch_case_1();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
