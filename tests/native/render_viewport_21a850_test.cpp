#include <cassert>
#include <cstring>
#include <iostream>

static int c1143c0_calls = 0;
static void *last_1143c0_ptr = nullptr;
static int last_1143c0_size = -1;

static int c21ae90_calls = 0;
static void *last_21ae90_self = nullptr;
static int last_21ae90_rect[4] = {0};
static void *last_21ae90_arg3 = nullptr;
static int mock_21ae90_ret = 888;

static int c21acd0_calls = 0;
static void *last_21acd0_arg0 = nullptr;
static void *last_21acd0_self = nullptr;

static int c21ad70_calls = 0;
static void *last_21ad70_self = nullptr;

static int c21a960_calls = 0;
static void *last_21a960_self = nullptr;
static int last_21a960_rect[4] = {0};
static void *last_21a960_arg3 = nullptr;
static const int *last_21a960_rect_t0 = nullptr;
static int last_21a960_arg5 = -1;
static void *last_21a960_buffer = nullptr;
static int mock_21a960_ret = 999;

extern "C" {
int func_0021A850(void *self, int x, int y, void *arg3, const int *rect_t0, int arg5);

void func_1143C0(void *ptr, int size) {
    c1143c0_calls++;
    last_1143c0_ptr = ptr;
    last_1143c0_size = size;
    std::memset(ptr, 0, size);
}

int func_0021AE90(void *self, const int *local_rect, void *arg3, const int *rect_t0, int arg5, int zero) {
    c21ae90_calls++;
    last_21ae90_self = self;
    std::memcpy(last_21ae90_rect, local_rect, sizeof(last_21ae90_rect));
    last_21ae90_arg3 = arg3;
    return mock_21ae90_ret;
}

void func_0021ACD0(void *arg0, void *self) {
    c21acd0_calls++;
    last_21acd0_arg0 = arg0;
    last_21acd0_self = self;
}

void func_0021AD70(void *self) {
    c21ad70_calls++;
    last_21ad70_self = self;
}

int func_0021A960(void *self, const int *local_rect, void *arg3, const int *rect_t0, int arg5, void *buffer) {
    c21a960_calls++;
    last_21a960_self = self;
    std::memcpy(last_21a960_rect, local_rect, sizeof(last_21a960_rect));
    last_21a960_arg3 = arg3;
    last_21a960_rect_t0 = rect_t0;
    last_21a960_arg5 = arg5;
    last_21a960_buffer = buffer;
    return mock_21a960_ret;
}
}

static void reset_mocks() {
    c1143c0_calls = 0;
    last_1143c0_ptr = nullptr;
    last_1143c0_size = -1;

    c21ae90_calls = 0;
    last_21ae90_self = nullptr;
    std::memset(last_21ae90_rect, 0, sizeof(last_21ae90_rect));
    last_21ae90_arg3 = nullptr;
    mock_21ae90_ret = 888;

    c21acd0_calls = 0;
    last_21acd0_arg0 = nullptr;
    last_21acd0_self = nullptr;

    c21ad70_calls = 0;
    last_21ad70_self = nullptr;

    c21a960_calls = 0;
    last_21a960_self = nullptr;
    std::memset(last_21a960_rect, 0, sizeof(last_21a960_rect));
    last_21a960_arg3 = nullptr;
    last_21a960_rect_t0 = nullptr;
    last_21a960_arg5 = -1;
    last_21a960_buffer = nullptr;
    mock_21a960_ret = 999;
}

void test_case_flag_800_direct_dispatch() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0x800; // flag active

    int in_rect[4] = {10, 20, 50, 70}; // width = 40, height = 50
    int res = func_0021A850(obj, 100, 200, (void *)0x3333, in_rect, 42);

    assert(res == 888);
    assert(c1143c0_calls == 1);
    assert(last_1143c0_size == 100);

    assert(c21ae90_calls == 1);
    assert(last_21ae90_self == obj);
    assert(last_21ae90_arg3 == (void *)0x3333);
    // local_rect translated to (100, 200):
    assert(last_21ae90_rect[0] == 100);
    assert(last_21ae90_rect[1] == 200);
    assert(last_21ae90_rect[2] == 100 + 40); // 140
    assert(last_21ae90_rect[3] == 200 + 50); // 250

    assert(c21acd0_calls == 0);
    assert(c21ad70_calls == 0);
    assert(c21a960_calls == 0);
}

void test_case_default_flags_with_arg3() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0; // flag inactive

    int in_rect[4] = {5, 5, 25, 35}; // width = 20, height = 30
    void *arg3_ptr = (void *)0x4444;

    int res = func_0021A850(obj, 50, 60, arg3_ptr, in_rect, 77);
    assert(res == 999);

    assert(c21ae90_calls == 0);
    assert(c21acd0_calls == 1);
    assert(last_21acd0_arg0 == arg3_ptr);
    assert(last_21acd0_self == obj);

    assert(c21ad70_calls == 1);
    assert(last_21ad70_self == obj);

    assert(c21a960_calls == 1);
    assert(last_21a960_self == obj);
    assert(last_21a960_rect[0] == 50);
    assert(last_21a960_rect[1] == 60);
    assert(last_21a960_rect[2] == 50 + 20); // 70
    assert(last_21a960_rect[3] == 60 + 30); // 90
    assert(last_21a960_arg3 == arg3_ptr);
    assert(last_21a960_rect_t0 == in_rect);
    assert(last_21a960_arg5 == 77);
    assert(last_21a960_buffer == last_1143c0_ptr);
}

void test_case_default_flags_null_arg3() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));
    *(unsigned int *)(obj + 0x98) = 0;

    int in_rect[4] = {0, 0, 10, 10};
    int res = func_0021A850(obj, 0, 0, nullptr, in_rect, 0);
    assert(res == 999);

    assert(c21acd0_calls == 0);
    assert(c21ad70_calls == 1);
    assert(c21a960_calls == 1);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_flag_800_direct_dispatch();
    else if (c == 1) test_case_default_flags_with_arg3();
    else if (c == 2) test_case_default_flags_null_arg3();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
