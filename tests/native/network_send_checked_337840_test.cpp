#include <cassert>
#include <cstring>
#include "network_send_checked_337840.h"

enum { CALL_SYNC_ENTER = 68, CALL_SYNC_LEAVE = 66, CALL_SEND = 1000, CALL_LOG = 2000 };

int g_sync_handle = 11;
int g_socket_handle = 22;

static int call_log[8];
static int call_count;
static int send_result;
static int send_handle;
static const void *send_buf;
static int send_len;
static int send_flags;

extern "C" {
    int func_00104d60(int handle) { (void)handle; call_log[call_count++] = CALL_SYNC_ENTER; return 0; }
    int func_00104d40(int handle) { (void)handle; call_log[call_count++] = CALL_SYNC_LEAVE; return 0; }
    int func_00118de0(const char *format, ...) {
        (void)format;
        call_log[call_count++] = CALL_LOG;
        return 0;
    }
    int func_00388d60(int handle, const void *buf, int len, int flags) {
        call_log[call_count++] = CALL_SEND;
        send_handle = handle;
        send_buf = buf;
        send_len = len;
        send_flags = flags;
        return send_result;
    }
}

static void reset_calls() {
    call_count = 0;
    std::memset(call_log, 0, sizeof(call_log));
}

int main() {
    char payload[492];
    std::memset(payload, 0x5A, sizeof(payload));

    reset_calls();
    send_result = 492;
    assert(func_00337840(payload, 492) == 492);
    assert(call_count == 3);
    assert(call_log[0] == CALL_SYNC_ENTER);
    assert(call_log[1] == CALL_SEND);
    assert(call_log[2] == CALL_SYNC_LEAVE);
    assert(send_handle == g_socket_handle);
    assert(send_buf == payload);
    assert(send_len == 492);
    assert(send_flags == 0);

    reset_calls();
    send_result = -5;
    assert(func_00337840(payload, 100) == -5);
    assert(call_count == 3);

    reset_calls();
    assert(func_00337840(payload, 493) == -1);
    assert(call_count == 1);
    assert(call_log[0] == CALL_LOG);

    return 0;
}
