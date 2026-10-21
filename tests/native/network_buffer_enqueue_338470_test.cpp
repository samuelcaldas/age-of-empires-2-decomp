#include <cassert>
#include <cstdarg>
#include <cstring>
#include "network_buffer_enqueue_338470.h"

enum { CALL_WAIT = 1, CALL_COPY = 2, CALL_SIGNAL = 3, CALL_LOG = 4 };

int D_004E3560 = 23;
static int calls[16];
static int call_count;
static int logged_count;
static int logged_size;
static int copy_length;
static void *copy_destination;
static const void *copy_source;

extern "C" {
    extern const char D_004D2128[] = "dplay:\n";
    extern const char D_004D2130[] = "receive buffer full/size:%d\n";
    extern const char D_004D2150[] = "cur:%d,sav:%d,prev:%d\n";
    int func_104D60(int semaphore) {
        assert(semaphore == D_004E3560);
        calls[call_count++] = CALL_WAIT;
        return 0;
    }
    int func_104D40(int semaphore) {
        assert(semaphore == D_004E3560);
        calls[call_count++] = CALL_SIGNAL;
        return 0;
    }
    int func_117af8(void *destination, const void *source, int size) {
        copy_destination = destination;
        copy_source = source;
        copy_length = size;
        calls[call_count++] = CALL_COPY;
        return 0;
    }
    int func_118de0(const char *format, ...) {
        va_list args;
        va_start(args, format);
        if (std::strcmp(format, D_004D2130) == 0) {
            logged_size = va_arg(args, int);
        } else if (std::strcmp(format, D_004D2150) == 0) {
            logged_count = 3;
            (void)va_arg(args, int);
            (void)va_arg(args, int);
            (void)va_arg(args, int);
        }
        va_end(args);
        calls[call_count++] = CALL_LOG;
        return 0;
    }
}

static void reset_calls() {
    std::memset(calls, 0, sizeof(calls));
    call_count = 0;
    copy_length = 0;
    copy_destination = 0;
    copy_source = 0;
}

int main() {
    unsigned char state[3400];
    unsigned char payload[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    std::memset(state, 0xA5, sizeof(state));
    *reinterpret_cast<int *>(state + 3372) = 0;
    *reinterpret_cast<int *>(state + 3376) = 0;
    *reinterpret_cast<int *>(state + 3380) = 0;
    *reinterpret_cast<int *>(state + 3384) = 0;

    reset_calls();
    void *result = func_00338470(state, payload, 5);
    assert(result == state + 1324);
    assert(call_count == 3);
    assert(calls[0] == CALL_WAIT);
    assert(calls[1] == CALL_COPY);
    assert(calls[2] == CALL_SIGNAL);
    assert(copy_destination == state + 1324);
    assert(copy_source == payload);
    assert(copy_length == 5);
    assert(*reinterpret_cast<int *>(state + 3372) == 1);
    assert(*reinterpret_cast<int *>(state + 3384) == 0);
    assert(*reinterpret_cast<int *>(state + 3380) == 8);
    assert(*reinterpret_cast<int *>(state + 3376) == 0);
    assert(logged_count == 0);

    return 0;
}
