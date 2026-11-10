#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void func_00217A10(void *self, int arg1, char arg2);
void func_00217A50(void *self, int a1, char a2, char a3, char a4, char a5, char a6, char a7);
void func_00217AD0(void *self, int a1);
void func_00217AE0(void *self);

static int g_b50_calls = 0;
static void *g_b50_self = nullptr;
static int g_b50_arg = 0;
void func_00217B50(void *self, int arg1) {
    g_b50_calls++;
    g_b50_self = self;
    g_b50_arg = arg1;
}

static int g_1f3dc0_calls = 0;
static void *g_1f3dc0_self = nullptr;
void func_1F3DC0(void *self) {
    g_1f3dc0_calls++;
    g_1f3dc0_self = self;
}
}

static int vtable_28_calls = 0;
static void *vtable_28_self = nullptr;
static int vtable_28_arg = 0;
static void mock_vtable_28(void *self, int arg) {
    vtable_28_calls++;
    vtable_28_self = self;
    vtable_28_arg = arg;
}

static int vtable_1c_calls = 0;
static void *vtable_1c_self = nullptr;
static int vtable_1c_arg = 0;
static void mock_vtable_1c(void *self, int arg) {
    vtable_1c_calls++;
    vtable_1c_self = self;
    vtable_1c_arg = arg;
}

static void *vtable_main[16];
static void *vtable_obj[16];

void test_case_217A10() {
    vtable_28_calls = 0;
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    vtable_main[8] = reinterpret_cast<void *>(mock_vtable_28);
    vtable_main[10] = reinterpret_cast<void *>(mock_vtable_28);
    *reinterpret_cast<void ***>(obj) = vtable_main;

    // Non-zero arg1
    func_00217A10(obj, 42, 7);
    assert(*reinterpret_cast<int *>(obj + 0x190) == 42);
    assert(*reinterpret_cast<int *>(obj + 0x1AC) == 1);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x194) == 7);
    assert(vtable_28_calls == 1);
    assert(vtable_28_self == obj);
    assert(vtable_28_arg == 1);

    // Zero arg1
    func_00217A10(obj, 0, 9);
    assert(*reinterpret_cast<int *>(obj + 0x190) == 0);
    assert(*reinterpret_cast<int *>(obj + 0x1AC) == 0);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x194) == 9);
    assert(vtable_28_calls == 2);
}

void test_case_217A50() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    // Case 1 -> 1
    g_b50_calls = 0;
    func_00217A50(obj, 1, 10, 11, 12, 13, 14, 15);
    assert(*reinterpret_cast<int *>(obj + 0x1AC) == 1);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x1B0) == 10);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x1B1) == 11);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x1B2) == 12);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x1B3) == 13);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x1B4) == 14);
    assert(*reinterpret_cast<unsigned char *>(obj + 0x1B5) == 15);
    assert(*reinterpret_cast<int *>(obj + 0x1BC) == 1);
    assert(g_b50_calls == 1 && g_b50_self == obj && g_b50_arg == 1);

    // Case 3 -> 2
    func_00217A50(obj, 3, 0, 0, 0, 0, 0, 0);
    assert(*reinterpret_cast<int *>(obj + 0x1BC) == 2);

    // Case 4 -> 3
    func_00217A50(obj, 4, 0, 0, 0, 0, 0, 0);
    assert(*reinterpret_cast<int *>(obj + 0x1BC) == 3);

    // Case 0 -> 0
    func_00217A50(obj, 0, 0, 0, 0, 0, 0, 0);
    assert(*reinterpret_cast<int *>(obj + 0x1BC) == 0);

    // Case out of bounds 99 -> 0
    func_00217A50(obj, 99, 0, 0, 0, 0, 0, 0);
    assert(*reinterpret_cast<int *>(obj + 0x1BC) == 0);
}

void test_case_217AD0() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    g_b50_calls = 0;

    func_00217AD0(obj, 0x12345);
    assert(*reinterpret_cast<int *>(obj + 0x1C0) == 0x12345);
    assert(g_b50_calls == 1 && g_b50_self == obj && g_b50_arg == 1);
}

void test_case_217AE0() {
    unsigned char obj[0x200];
    unsigned char target[0x100];
    std::memset(obj, 0, sizeof(obj));
    std::memset(target, 0, sizeof(target));

    vtable_obj[5] = reinterpret_cast<void *>(mock_vtable_1c);
    vtable_obj[7] = reinterpret_cast<void *>(mock_vtable_1c);
    *reinterpret_cast<void ***>(target) = vtable_obj;

    // Early return if field 0x170 == 0
    g_1f3dc0_calls = 0;
    vtable_1c_calls = 0;
    *reinterpret_cast<int *>(obj + 0x170) = 0;
    *reinterpret_cast<void **>(obj + 0x16C) = target;
    func_00217AE0(obj);
    assert(g_1f3dc0_calls == 1);
    assert(vtable_1c_calls == 0);

    // Early return if field 0x16C == nullptr
    g_1f3dc0_calls = 0;
    *reinterpret_cast<int *>(obj + 0x170) = 1;
    *reinterpret_cast<void **>(obj + 0x16C) = nullptr;
    func_00217AE0(obj);
    assert(g_1f3dc0_calls == 1);
    assert(vtable_1c_calls == 0);

    // Call with 0x84 != 0
    *reinterpret_cast<void **>(obj + 0x16C) = target;
    *reinterpret_cast<int *>(obj + 0x84) = 1;
    *reinterpret_cast<int *>(obj + 0x1A8) = 777;
    func_00217AE0(obj);
    assert(vtable_1c_calls == 1);
    assert(vtable_1c_self == target);
    assert(vtable_1c_arg == 777);

    // Call with 0x84 == 0
    *reinterpret_cast<int *>(obj + 0x84) = 0;
    func_00217AE0(obj);
    assert(vtable_1c_calls == 2);
    assert(vtable_1c_self == target);
    assert(vtable_1c_arg == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_217A10();
    else if (case_num == 1) test_case_217A50();
    else if (case_num == 2) test_case_217AD0();
    else if (case_num == 3) test_case_217AE0();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
