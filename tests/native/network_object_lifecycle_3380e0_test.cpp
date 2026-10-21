#include <cassert>
#include <cstring>
#include "network_object_lifecycle_3380e0.h"

unsigned char D_010990A0;
unsigned char D_01087ED0[5000];
extern "C" {
    extern const char D_00492C50[] = "interface";
    extern const char D_004D20F0[] = "DirectPlay Compatible Interface";
}
static int memset_calls;
static int callback_calls;
static const char *callback_first;
static const char *callback_second;
static int callback_length;
static int callback_flag;

extern "C" {
    void *func_00117CAC(void *destination, int value, unsigned int size) {
        ++memset_calls;
        return std::memset(destination, value, size);
    }
}

static int callback(const char *first, const char *second, int length, int flag) {
    ++callback_calls;
    callback_first = first;
    callback_second = second;
    callback_length = length;
    callback_flag = flag;
    return -1;
}

int main() {
    unsigned char object[5000];
    void *out = 0;
    std::memset(object, 0x7f, sizeof(object));
    memset_calls = 0;
    func_003381A0(object);
    assert(memset_calls == 3);
    assert(object[4] == 0 && object[1092] == 0 && object[1324] == 0);
    assert(object[4412] == 0 && object[4560] == 0);
    assert(*(int *)(object + 1316) == 1);
    assert(*(int *)(object + 4540) == 0 && *(int *)(object + 4556) == 0);

    D_010990A0 = 0;
    assert(func_003380E0(0, &out) == 0);
    assert(out == D_01087ED0 && D_010990A0 == 1);
    assert(func_003380E0(0, &out) == 0);
    assert(D_010990A0 == 2);

    callback_calls = 0;
    assert(func_00338140((void *)callback, 0) == 0);
    assert(callback_calls == 1);
    assert(std::strcmp(callback_second, "DirectPlay Compatible Interface") == 0);
    assert(callback_length == 6 && callback_flag == 0);

    std::memset(object, 0x55, sizeof(object));
    assert(func_00338230(object) == object);
    assert(*(int *)(object + 1308) == 0);
    assert(*(int *)(object + 1316) == 1);
    return 0;
}
