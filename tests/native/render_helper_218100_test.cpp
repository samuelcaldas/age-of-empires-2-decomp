#include <cassert>
#include <cstring>
#include <iostream>

static int dd0_calls = 0;
static int last_arg1 = -1;
static int last_arg2 = -1;
static int last_arg3 = -1;

extern "C" {
void func_00217DD0(void *self, int arg1, int arg2, int arg3) {
    dd0_calls++;
    last_arg1 = arg1;
    last_arg2 = arg2;
    last_arg3 = arg3;
}

void func_1F6460(void) {}

int func_00218100(void *self, int arg1, int op, int a3, int a4, int a5);
}

void test_case_218100_basic() {
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    // ptr16C is 0 -> returns 0
    int res = func_00218100(obj, 1, 0, 0, 0, 0);
    assert(res == 0);

    // ptr16C matches arg1 -> dispatches op 2
    *(int *)(obj + 0x16C) = 42;
    dd0_calls = 0;
    res = func_00218100(obj, 42, 2, 0, 0, 0);
    assert(res == 1);
    assert(dd0_calls == 1);
    assert(last_arg1 == 5);
    assert(last_arg3 == 1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_218100_basic();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
