#include <cassert>
#include <cstring>
#include <iostream>

static int c21b130_calls = 0;
static void *last_21b130_self = nullptr;
static int last_21b130_rect1[4] = {0};
static void *last_21b130_target = nullptr;
static int last_21b130_rect3[4] = {0};

extern "C" {
int func_0021AE90(void *self, const int *rect1, void *target, const int *rect3, int arg4, int arg5);

void func_0021B130(void *self, const int *rect1, void *target, const int *rect3) {
    c21b130_calls++;
    last_21b130_self = self;
    std::memcpy(last_21b130_rect1, rect1, sizeof(last_21b130_rect1));
    last_21b130_target = target;
    std::memcpy(last_21b130_rect3, rect3, sizeof(last_21b130_rect3));
}
}

static void reset_mocks() {
    c21b130_calls = 0;
    last_21b130_self = nullptr;
    std::memset(last_21b130_rect1, 0, sizeof(last_21b130_rect1));
    last_21b130_target = nullptr;
    std::memset(last_21b130_rect3, 0, sizeof(last_21b130_rect3));
}

void test_case_target_flags_and_type_checks() {
    reset_mocks();
    unsigned char obj_self[0x100];
    unsigned char obj_target[0x100];
    std::memset(obj_self, 0, sizeof(obj_self));
    std::memset(obj_target, 0, sizeof(obj_target));

    // Target flag 0x4000 -> returns 0
    *(unsigned int *)(obj_target + 0x98) = 0x4000;
    assert(func_0021AE90(obj_self, nullptr, obj_target, nullptr, 0, 0) == 0);

    // Target flag clear, but self_1c != target_1c -> returns 1
    *(unsigned int *)(obj_target + 0x98) = 0;
    *(int *)(obj_self + 0x1C) = 5;
    *(int *)(obj_target + 0x1C) = 10;
    assert(func_0021AE90(obj_self, nullptr, obj_target, nullptr, 0, 0) == 1);

    // Equal but either is 0x14 -> returns 1
    *(int *)(obj_self + 0x1C) = 0x14;
    *(int *)(obj_target + 0x1C) = 0x14;
    assert(func_0021AE90(obj_self, nullptr, obj_target, nullptr, 0, 0) == 1);
}

void test_case_bounding_and_overlap_checks() {
    reset_mocks();
    unsigned char obj_self[0x100];
    std::memset(obj_self, 0, sizeof(obj_self));
    *(int *)(obj_self + 0x3C) = 100; // width = 100
    *(int *)(obj_self + 0x38) = 80;  // height = 80

    // Rect completely outside bounds (x0 >= width)
    int bad_rect[4] = {150, 0, 200, 50};
    assert(func_0021AE90(obj_self, bad_rect, nullptr, nullptr, 0, 0) == 0);

    // Rect completely outside bounds (x1 < 0)
    int bad_rect2[4] = {-50, 0, -10, 50};
    assert(func_0021AE90(obj_self, bad_rect2, nullptr, nullptr, 0, 0) == 0);
}

void test_case_successful_clipping_and_dispatch() {
    reset_mocks();
    unsigned char obj_self[0x100];
    unsigned char obj_target[0x100];
    std::memset(obj_self, 0, sizeof(obj_self));
    std::memset(obj_target, 0, sizeof(obj_target));

    *(int *)(obj_self + 0x1C) = 0x13;   // self_1c = 0x13
    *(int *)(obj_target + 0x1C) = 0x13; // target_1c = 0x13
    *(int *)(obj_self + 0x3C) = 100;
    *(int *)(obj_self + 0x38) = 100;
    *(int *)(obj_target + 0x3C) = 200;
    *(int *)(obj_target + 0x38) = 200;

    // partially outside bounds: should be clipped to [0, 100]
    int rect1[4] = {-20, -10, 150, 120};
    int rect3[4] = {-5, 10, 250, 180};

    int res = func_0021AE90(obj_self, rect1, obj_target, rect3, 0, 0);
    assert(res == 0);
    assert(c21b130_calls == 1);
    assert(last_21b130_self == obj_self);
    assert(last_21b130_target == obj_target);

    // check clipped rect1: [0, 0, 100, 100]
    assert(last_21b130_rect1[0] == 0);
    assert(last_21b130_rect1[1] == 0);
    assert(last_21b130_rect1[2] == 100);
    assert(last_21b130_rect1[3] == 100);

    // check clipped rect3: [0, 10, 200, 180]
    assert(last_21b130_rect3[0] == 0);
    assert(last_21b130_rect3[1] == 10);
    assert(last_21b130_rect3[2] == 200);
    assert(last_21b130_rect3[3] == 180);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_target_flags_and_type_checks();
    else if (c == 1) test_case_bounding_and_overlap_checks();
    else if (c == 2) test_case_successful_clipping_and_dispatch();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
