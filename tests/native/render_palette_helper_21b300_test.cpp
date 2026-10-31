#include <cassert>
#include <cstring>
#include <iostream>

unsigned short D_004E32DC = 0;
extern "C" char D_00C5C700[0x10000] = {0};

static int c21b440_calls = 0;
static void *last_21b440_ptr14 = nullptr;

static int c21b4c0_calls = 0;
static void *last_21b4c0_ptr14 = nullptr;
static int last_21b4c0_coord0 = -1;

extern "C" {
int func_0021B300(void *self, int arg1, const int *coords);
int func_0021B3C0(void *arg0, void **arg1);
int func_0021B3D0(void);
void func_0021B3E0(void *self);
void func_0021B420(void *self);
int func_0021B430(void *self);

int func_0021B440(void *ptr14, int a1, int a2, int a3, void *buf) {
    c21b440_calls++;
    last_21b440_ptr14 = ptr14;
    return 1;
}

int func_0021B4C0(void *ptr14, int a1, int a2, int a3, void *buf, int coord0) {
    c21b4c0_calls++;
    last_21b4c0_ptr14 = ptr14;
    last_21b4c0_coord0 = coord0;
    return 1;
}
}

static void reset_mocks() {
    D_004E32DC = 0;
    std::memset(D_00C5C700, 0, sizeof(D_00C5C700));
    c21b440_calls = 0;
    last_21b440_ptr14 = nullptr;
    c21b4c0_calls = 0;
    last_21b4c0_ptr14 = nullptr;
    last_21b4c0_coord0 = -1;
}

void test_case_21B300_modes() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    int coords[2] = {100, 200};

    // Mode == 2 -> returns 1
    *(int *)(obj + 0x1C) = 2;
    int res2 = func_0021B300(obj, 0, coords);
    assert(res2 == 1);
    assert(*(int *)(obj + 0x70) == 100);
    assert(*(int *)(obj + 0x74) == 200);
    assert(c21b440_calls == 0);

    // Mode == 1, ptr14 == nullptr -> returns 1
    *(int *)(obj + 0x1C) = 1;
    *(void **)(obj + 0x14) = nullptr;
    int res1_null = func_0021B300(obj, 0, coords);
    assert(res1_null == 1);
    assert(c21b440_calls == 0);

    // Mode == 0 -> returns 1
    *(int *)(obj + 0x1C) = 0;
    *(void **)(obj + 0x14) = (void *)0x5555;
    int res0 = func_0021B300(obj, 0, coords);
    assert(res0 == 1);
    assert(c21b440_calls == 0);

    // Mode == 1, ptr14 != nullptr -> calls 21B440 and 21B4C0, returns 0
    *(int *)(obj + 0x1C) = 1;
    void *ptr14 = (void *)0x5555;
    *(void **)(obj + 0x14) = ptr14;
    int res1 = func_0021B300(obj, 0, coords);
    assert(res1 == 0);
    assert(c21b440_calls == 1);
    assert(last_21b440_ptr14 == ptr14);
    assert(c21b4c0_calls == 1);
    assert(last_21b4c0_ptr14 == ptr14);
    assert(last_21b4c0_coord0 == 100);
}

void test_case_21B3C0_21B3D0_and_resets() {
    void *target = nullptr;
    int res = func_0021B3C0((void *)0x7777, &target);
    assert(res == 0);
    assert(target == (void *)0x7777);

    assert(func_0021B3D0() == 0);

    short val1 = 1234;
    func_0021B420(&val1);
    assert(val1 == 0);

    short val2 = 5678;
    assert(func_0021B430(&val2) == 0);
    assert(val2 == 0);
}

void test_case_21B3E0_alloc_palette_slot() {
    reset_mocks();
    D_004E32DC = 3; // initial counter = 3

    unsigned char slot_obj[0x10];
    std::memset(slot_obj, 0xFF, sizeof(slot_obj));

    func_0021B3E0(slot_obj);

    assert(*(short *)(slot_obj + 0) == 0);
    assert(*(short *)(slot_obj + 2) == 3 * 16); // 48
    assert(*(char **)(slot_obj + 4) == D_00C5C700 + 3 * 1024);
    assert(D_004E32DC == 4); // incremented
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_21B300_modes();
    else if (c == 1) test_case_21B3C0_21B3D0_and_resets();
    else if (c == 2) test_case_21B3E0_alloc_palette_slot();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
