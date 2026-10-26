#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void func_00217A10(void *self, int arg1, int arg2);
void func_00217A50(void *self, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
}

static int vtable_28_calls = 0;
static void *vtable_28_self = nullptr;
static int vtable_28_arg = 0;

static void *vtable[12];

static void mock_vtable_28(void *self, int arg) {
    vtable_28_calls++;
    vtable_28_self = self;
    vtable_28_arg = arg;
}

void test_case_217A10() {
    vtable_28_calls = 0;
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    vtable[10] = reinterpret_cast<void *>(mock_vtable_28); // slot 10 = 0x28 bytes offset (10 * 4 = 40 = 0x28)
    *reinterpret_cast<void ***>(obj) = vtable;

    func_00217A10(obj, 42, 7);

    assert(*reinterpret_cast<int *>(obj + 0x190) == 42);
    assert(*reinterpret_cast<int *>(obj + 0x1AC) == 1);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x194) == 7);
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
    if (case_num == 0) test_case_217A10();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
