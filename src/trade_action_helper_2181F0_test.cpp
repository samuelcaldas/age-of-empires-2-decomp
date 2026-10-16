#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void func_002181F0(void *self);

static int aba00_calls = 0;
static int _2257a0_calls = 0;
static int aba70_calls = 0;
static int vtable_30_calls = 0;
static int vtable_120_calls = 0;
static int vtable_34_calls = 0;
static int return_s0_val = 123;

int func_001ABA00(void *arg0) {
    aba00_calls++;
    return return_s0_val;
}

int func_002257A0(void *arg0, int arg1) {
    _2257a0_calls++;
    return 456;
}

int func_001ABA70(void *arg0) {
    aba70_calls++;
    return 1;
}

static void mock_vtable_30(void *self) {
    vtable_30_calls++;
}
static void mock_vtable_120(void *self, void *a1, void *a2, void *a3, void *a4) {
    vtable_120_calls++;
}
static void mock_vtable_34(void *self) { vtable_34_calls++; }

static void *vtable[100];
}

static void reset_mocks() {
    aba00_calls = 0;
    _2257a0_calls = 0;
    aba70_calls = 0;
    vtable_30_calls = 0;
    vtable_120_calls = 0;
    vtable_34_calls = 0;
    return_s0_val = 123;
}

void test_case_2181F0_null_field88() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_002181F0(obj);
    assert(*reinterpret_cast<int *>(obj + 0x38) == 0);
    assert(vtable_30_calls == 0);
}

void test_case_2181F0_s0_zero() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    vtable[12] = reinterpret_cast<void *>(mock_vtable_30);   // 0x30
    vtable[13] = reinterpret_cast<void *>(mock_vtable_34);   // 0x34
    *reinterpret_cast<void ***>(obj) = vtable;

    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(obj + 0x88) = (void *)0x8888;
    return_s0_val = 0;

    func_002181F0(obj);

    assert(vtable_30_calls == 1);
    assert(aba00_calls == 1);
    assert(vtable_34_calls == 1);
    assert(_2257a0_calls == 0);
}

void test_case_2181F0_zero_iterations() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    vtable[12] = reinterpret_cast<void *>(mock_vtable_30);   // 0x30
    vtable[72] = reinterpret_cast<void *>(mock_vtable_120);  // 0x120
    vtable[13] = reinterpret_cast<void *>(mock_vtable_34);   // 0x34
    *reinterpret_cast<void ***>(obj) = vtable;

    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(obj + 0x88) = (void *)0x8888;
    *reinterpret_cast<short *>(obj + 0x124) = 13;
    *reinterpret_cast<short *>(obj + 0x126) = 12; // limit126 (12) < s2 (13) -> zero iterations

    func_002181F0(obj);

    assert(vtable_30_calls == 1);
    assert(aba00_calls == 1);
    assert(vtable_120_calls == 0);
    assert(vtable_34_calls == 1);
}

void test_case_2181F0_full_flow() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    vtable[12] = reinterpret_cast<void *>(mock_vtable_30);   // 0x30
    vtable[72] = reinterpret_cast<void *>(mock_vtable_120);  // 0x120
    vtable[13] = reinterpret_cast<void *>(mock_vtable_34);   // 0x34
    *reinterpret_cast<void ***>(obj) = vtable;

    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    *reinterpret_cast<void **>(obj + 0x88) = (void *)0x8888;
    *reinterpret_cast<int *>(obj + 0x8C) = 1;
    *reinterpret_cast<int *>(obj + 0x90) = 1;
    *reinterpret_cast<short *>(obj + 0x124) = 10;
    *reinterpret_cast<short *>(obj + 0x126) = 10; // 1 iteration

    func_002181F0(obj);

    assert(*reinterpret_cast<int *>(obj + 0x38) == 0);
    assert(vtable_30_calls == 1);
    assert(aba00_calls == 1);
    assert(_2257a0_calls >= 2);
    assert(vtable_120_calls == 1);
    assert(aba70_calls == 1);
    assert(vtable_34_calls == 1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_2181F0_null_field88();
    else if (case_num == 1) test_case_2181F0_s0_zero();
    else if (case_num == 2) test_case_2181F0_zero_iterations();
    else if (case_num == 3) test_case_2181F0_full_flow();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
