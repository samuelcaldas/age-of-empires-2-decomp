#include <cassert>
#include <cstring>
#include <iostream>

static int c1003b0_calls = 0;
static int c21b6a0_calls = 0;
static int c21b420_calls = 0;
static int c21a550_calls = 0;

extern "C" {
char D_00C5C2D0[0x420] = {0};

void *func_0021B640(void *self);
void func_0021B6A0(void *self);
int func_0021B730(void *unused, void **out_ptr);
void *func_0021B760(void *self);

void *func_0021A520(void *self) {
    return self;
}

void *func_0021B3E0(void *self) {
    return self;
}

void *func_1003B0(void *array, void *ctor_fn, void *dtor_fn, int elem_size, int count) {
    c1003b0_calls++;
    return array;
}

void func_0021B420(void *self) {
    c21b420_calls++;
    *(short *)self = 0;
}

void func_0021A550(void *self) {
    c21a550_calls++;
    *(int *)self = 0;
}
}

static void reset_mocks() {
    c1003b0_calls = 0;
    c21b6a0_calls = 0;
    c21b420_calls = 0;
    c21a550_calls = 0;
    std::memset(D_00C5C2D0, 0, sizeof(D_00C5C2D0));
}

void test_case_constructor_and_reset() {
    reset_mocks();
    unsigned char obj[0x420];
    std::memset(obj, 0x55, sizeof(obj));

    void *ret = func_0021B640(obj);
    assert(ret == obj);
    assert(c1003b0_calls == 2); // 2 arrays constructed
    assert(c21b420_calls == 6);  // 6 palette slots reset
    assert(c21a550_calls == 6);  // 6 viewports reset

    // Test func_0021B730
    void *global_ptr = nullptr;
    int res = func_0021B730(nullptr, &global_ptr);
    assert(res == 0);
    assert(global_ptr == D_00C5C2D0);
}

void test_case_alloc_slot() {
    reset_mocks();
    unsigned char obj[0x420];
    std::memset(obj, 0, sizeof(obj));

    // Initially slot 0 is free (0x3F0 has short == 0)
    void *slot0 = func_0021B760(obj);
    assert(slot0 == obj + 0x3F0);
    assert(*(short *)slot0 == 1); // marked allocated

    // Next call allocates slot 1 (0x3F0 + 8)
    void *slot1 = func_0021B760(obj);
    assert(slot1 == obj + 0x3F0 + 8);
    assert(*(short *)slot1 == 1);

    // Allocate remaining 4 slots
    void *slot2 = func_0021B760(obj);
    void *slot3 = func_0021B760(obj);
    void *slot4 = func_0021B760(obj);
    void *slot5 = func_0021B760(obj);
    assert(slot5 == obj + 0x3F0 + 5 * 8);

    // Now all 6 slots are busy -> returns nullptr
    void *slot_fail = func_0021B760(obj);
    assert(slot_fail == nullptr);
}

void test_case_skip_occupied_slot() {
    reset_mocks();
    unsigned char obj[0x420];
    std::memset(obj, 0xFF, sizeof(obj));

    // Slots 0, 1, 2 are busy (non-zero)
    // Slot 3 is free (0x0000)
    *(unsigned short *)(obj + 0x3F0 + 0 * 8) = 0x8000;
    *(unsigned short *)(obj + 0x3F0 + 1 * 8) = 0x0002;
    *(unsigned short *)(obj + 0x3F0 + 2 * 8) = 0xFFFF;
    *(unsigned short *)(obj + 0x3F0 + 3 * 8) = 0x0000;
    *(unsigned short *)(obj + 0x3F0 + 4 * 8) = 0x0001;
    *(unsigned short *)(obj + 0x3F0 + 5 * 8) = 0x0001;

    void *slot = func_0021B760(obj);
    assert(slot == obj + 0x3F0 + 3 * 8);
    assert(*(unsigned short *)slot == 1);

    // Now slot 3 is also busy, so next allocation must fail
    void *slot_fail = func_0021B760(obj);
    assert(slot_fail == nullptr);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_constructor_and_reset();
    else if (c == 1) test_case_alloc_slot();
    else if (c == 2) test_case_skip_occupied_slot();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
