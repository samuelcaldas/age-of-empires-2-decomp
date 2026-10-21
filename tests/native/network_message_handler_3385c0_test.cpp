#include <cassert>
#include <cstring>
#include "network_message_handler_3385c0.h"

static int compare_calls;
static int copy_calls;
static int send_calls;
static int compare_result;
static int send_result;
static int send_size;
static void *send_buffer;

extern "C" {
    int func_117A64(const char *left, const char *right, int size) {
        ++compare_calls;
        return std::strncmp(left, right, static_cast<unsigned int>(size));
    }
    void *func_11ABBC(char *destination, const char *source) {
        ++copy_calls;
        return std::strcpy(destination, source);
    }
    void *func_117AF8(void *destination, const void *source, int size) {
        ++copy_calls;
        return std::memcpy(destination, source, static_cast<unsigned int>(size));
    }
    int func_00337840(const void *buffer, int size) {
        ++send_calls;
        send_buffer = const_cast<void *>(buffer);
        send_size = size;
        return send_result;
    }
    int func_00338470(void *, void *, int) { return 0; }
    int func_003382D0(void *, int) { return 0; }
    void *func_00338310(void *, int) { return 0; }
    void func_00338190(void *, void *) {}
    void *func_11B170(void *destination, const void *source, int size) {
        return std::memcpy(destination, source, static_cast<unsigned int>(size));
    }
    void *func_117CAC(void *destination, int value, int size) {
        return std::memset(destination, value, static_cast<unsigned int>(size));
    }
    int func_003385C0(void *, void *, int, int) { return 0; }
}

static void reset() {
    compare_calls = 0;
    copy_calls = 0;
    send_calls = 0;
    send_result = 1;
    send_size = 0;
    send_buffer = 0;
}

int main() {
    unsigned char object[5000];
    unsigned char message[512];
    std::memset(object, 0, sizeof(object));
    std::memset(message, 0, sizeof(message));
    *reinterpret_cast<int *>(object + 1312) = 1;
    std::memcpy(message + 16, "SESSION", 8);
    for (int index = 0; index < 216; ++index) {
        object[1092 + index] = static_cast<unsigned char>(index);
    }

    reset();
    assert(func_003385C0(object, message, 492, 0) == 1);
    assert(compare_calls == 1);
    assert(copy_calls == 2);
    assert(send_calls == 1);
    assert(send_size == 224);
    assert(send_buffer == object + 3388);
    assert(std::memcmp(object + 3388, "SESSION", 8) == 0);
    assert(std::memcmp(object + 3396, object + 1092, 216) == 0);
    return 0;
}
