#include <cassert>
#include <cstring>
#include "network_send_checked_337840.h"

enum { CALL_SYNC_ENTER = 68, CALL_SYNC_LEAVE = 66, CALL_SEND = 1000, CALL_LOG = 2000 };

int D_004E3560 = 11;
int D_004E3538 = 22;

static int call_log[8];
static int call_count;
static int send_result;
static int send_handle;
static const void *send_buf;
static int send_len;
static int send_flags;
static const char *log_format;

extern "C" {
    extern const char D_004D1EB0[] = "err! il_sendto()\n";
    extern const char D_004D1ED0[] = "err! sceILsockSend()\n";
    int func_104D60(int handle) { (void)handle; call_log[call_count++] = CALL_SYNC_ENTER; return 0; }
    int func_104D40(int handle) { (void)handle; call_log[call_count++] = CALL_SYNC_LEAVE; return 0; }
    int func_118de0(const char *format, ...) {
        log_format = format;
        call_log[call_count++] = CALL_LOG;
        return 0;
    }
    int func_388D60(int handle, const void *buf, int len, int flags) {
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
    assert(send_handle == D_004E3538);
    assert(send_buf == payload);
    assert(send_len == 492);
    assert(send_flags == 0);

    reset_calls();
    send_result = -5;
    assert(func_00337840(payload, 100) == -2);
    assert(call_count == 4);
    assert(call_log[3] == CALL_LOG);
    assert(std::strcmp(log_format, "err! sceILsockSend()\n") == 0);

    reset_calls();
    assert(func_00337840(payload, 493) == -1);
    assert(call_count == 1);
    assert(call_log[0] == CALL_LOG);
    assert(std::strcmp(log_format, "err! il_sendto()\n") == 0);

    return 0;
}
