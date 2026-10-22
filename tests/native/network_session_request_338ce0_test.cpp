#include <cassert>
#include <cstring>
#include "network_session_request_338ce0.h"

enum { OBJECT_SIZE = 5000, REQUEST_OFFSET = 3388, REQUEST_SIZE = 24 };
int D_004E352C = 1;
unsigned char D_0108AFA0[512];
extern "C" {
extern const char D_004D1F18[] = "SESSION";
extern const char D_004D1F10[] = "JOINED";
extern const float D_00492C60[4] = {0.0f, 0.0f, 0.0f, 0.0f};
}
static int send_calls;
static int timer_calls;
static int sleep_calls;
static int timer_values[2] = {100, 5101};
static int sent_length;
static const void *sent_buffer;
static int calls[8];
static int call_count;

extern "C" {
int func_117af8(void *destination, const void *source, int size) {
    std::memcpy(destination, source, size);
    return 0;
}
int func_117cac(void *destination, int value, int size) {
    std::memset(destination, value, size);
    return 0;
}
char *func_11abbc(char *destination, const char *source) {
    return std::strcpy(destination, source);
}
int func_11acd0(const char *text) { return static_cast<int>(std::strlen(text)); }
int func_11b170(void *destination, const void *source, int size) {
    std::memcpy(destination, source, size);
    return 0;
}
int func_337840(const void *buffer, int size) {
    calls[call_count++] = 1;
    ++send_calls;
    sent_length = size;
    sent_buffer = buffer;
    return size;
}
int func_103358(int) { calls[call_count++] = 3; ++sleep_calls; return 0; }
unsigned int func_2261C0() { calls[call_count++] = 2; return timer_values[timer_calls++]; }
}

int main() {
    unsigned char object[OBJECT_SIZE];
    unsigned char input[128];
    std::memset(object, 0xA5, sizeof(object));
    std::memset(input, 0, sizeof(input));
    std::memset(D_0108AFA0, 0, sizeof(D_0108AFA0));
    send_calls = timer_calls = sleep_calls = call_count = 0;

    assert(func_00338CE0(object, input, 1) == static_cast<int>(0x8877000A));
    assert(*reinterpret_cast<int *>(object + 1312) == 0);
    assert(*reinterpret_cast<int *>(object + REQUEST_OFFSET) == 0);
    assert(*reinterpret_cast<int *>(object + REQUEST_OFFSET + 4) == 0);
    assert(*reinterpret_cast<int *>(object + REQUEST_OFFSET + 8) == 0);
    assert(*reinterpret_cast<int *>(object + REQUEST_OFFSET + 12) == 0);
    assert(std::strcmp(reinterpret_cast<char *>(object + REQUEST_OFFSET + 16), "SESSION") == 0);
    assert(sent_buffer == object + REQUEST_OFFSET);
    assert(sent_length == REQUEST_SIZE);
    assert(send_calls == 1);
    assert(timer_calls == 2);
    assert(sleep_calls == 1);
    assert(call_count == 4);
    assert(calls[0] == 1 && calls[1] == 2 && calls[2] == 3 && calls[3] == 2);
    assert(*reinterpret_cast<int *>(object + 1308) == 0xA5A5A5A5);
    return 0;
}
