#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void *func_0021A520(void *self);
void func_0021A550(void *self);
int func_0021A570(void *self);
int func_0021A580(void *self, int arg1);
}

void test_case_constructor_and_init() {
    unsigned char obj[0x40];
    std::memset(obj, 0xAA, sizeof(obj));

    void *ret = func_0021A520(obj);
    assert(ret == obj);

    assert(*(int *)(obj + 0x0) == 0);
    assert(*(int *)(obj + 0x4) == 0);
    assert(*(int *)(obj + 0x8) == 0);
    assert(*(int *)(obj + 0xC) == 0);
    assert(*(int *)(obj + 0x10) == 0);
    // Bytes after 0x14 should remain untouched
    assert(*(unsigned char *)(obj + 0x14) == 0xAA);
}

void test_case_reset_and_set_field14() {
    unsigned char obj[0x40];
    std::memset(obj, 0, sizeof(obj));

    *(int *)(obj + 0x0) = 999;
    int res70 = func_0021A570(obj);
    assert(res70 == 0);
    assert(*(int *)(obj + 0x0) == 0);

    // arg1 != 0
    int res80_nonzero = func_0021A580(obj, 42);
    assert(res80_nonzero == 0);
    assert(*(int *)(obj + 0x14) == 42);

    // arg1 == 0
    int res80_zero = func_0021A580(obj, 0);
    assert(res80_zero == 1);
    assert(*(int *)(obj + 0x14) == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_constructor_and_init();
    else if (c == 1) test_case_reset_and_set_field14();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
