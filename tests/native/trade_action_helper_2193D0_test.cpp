#include <cassert>
#include <cstring>
#include <iostream>

static int c217b50_calls = 0;
static void *last_217b50_self = nullptr;
static int last_217b50_arg1 = -1;

static int c219ba0_calls = 0;
static void *last_219ba0_self = nullptr;
static short last_219ba0_arg1 = -1;

extern "C" {
short func_002193D0(void *self);
short func_002193E0(void *self);
short func_002193F0(void *self);
void func_00219400(void *self, short arg1);
void func_00219410(void *self, short arg1);
void func_00219420(void *self, short arg1);
void func_00219430(void *self, short arg1);

void func_00217B50(void *self, int arg1) {
    c217b50_calls++;
    last_217b50_self = self;
    last_217b50_arg1 = arg1;
}

void func_00219BA0(void *self, short arg1) {
    c219ba0_calls++;
    last_219ba0_self = self;
    last_219ba0_arg1 = arg1;
}
}

static void reset_mocks() {
    c217b50_calls = 0;
    last_217b50_self = nullptr;
    last_217b50_arg1 = -1;
    c219ba0_calls = 0;
    last_219ba0_self = nullptr;
    last_219ba0_arg1 = -1;
}

void test_case_getters() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(short *)(obj + 0x120) = 111;
    *(short *)(obj + 0x122) = 222;
    *(short *)(obj + 0x128) = 333;

    assert(func_002193D0(obj) == 111);
    assert(func_002193E0(obj) == 222);
    assert(func_002193F0(obj) == 333);
}

void test_case_setters_and_forwards() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    // func_00219420: pure setter
    func_00219420(obj, 555);
    assert(*(short *)(obj + 0x128) == 555);

    // func_00219430: setter + call 217B50(self, 1)
    func_00219430(obj, 777);
    assert(*(short *)(obj + 0x128) == 777);
    assert(c217b50_calls == 1);
    assert(last_217b50_self == obj);
    assert(last_217b50_arg1 == 1);

    // func_00219400: forward to 219430
    func_00219400(obj, 888);
    assert(*(short *)(obj + 0x128) == 888);
    assert(c217b50_calls == 2);
    assert(last_217b50_self == obj);
    assert(last_217b50_arg1 == 1);

    // func_00219410: forward to 219BA0
    func_00219410(obj, 999);
    assert(c219ba0_calls == 1);
    assert(last_219ba0_self == obj);
    assert(last_219ba0_arg1 == 999);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_getters();
    else if (c == 1) test_case_setters_and_forwards();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
