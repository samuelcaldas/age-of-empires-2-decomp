#include <cassert>
#include <cstring>
#include <csetjmp>
#include <cstdarg>
#include "network_receiver_337B30.h"

int D_010890E0[16][123];
int D_010890C0[4] = {0x55, 0, 0, 0x66};
int D_004E352C;
int D_004E3538;
int D_004E353C;
int D_004E3540;
int D_004E3544;
int D_004E3550;
int D_004E3554;
int D_004E3558;
int D_004E355C;
static jmp_buf finish_thread;
static char events[256];
static int event_count;
static void event(char value) { events[event_count++] = value; events[event_count] = 0; }
static int recv_calls, recvfrom_calls, dispatch_calls, connect_calls;
static int count_before_receive;
static int socket_handle, receive_size, receive_flags, connect_length;
static void *receive_buffer;
static int recv_result = 492;
static int recv_limit = 1, recvfrom_limit = 1;
static int recvfrom_result = 492;
static int connect_result = -1;
static int peer_words[4];
static unsigned connected_words[2];

extern "C" {
    extern const char D_004D1F20[] = "receiver start";
    extern const char D_004D1F38[] = "new peer";
    extern const char D_004D1F40[] = "connected";
    int func_388E60(int socket, void *buffer, int size, int flags) {
        assert(socket == D_004E353C && size == 492 && flags == 0);
        assert(buffer == D_010890E0[D_004E3558]);
        count_before_receive = D_004E355C;
        event('R'); ++recv_calls;
        if (recv_calls > recv_limit) longjmp(finish_thread, 1);
        socket_handle = socket; receive_buffer = buffer;
        receive_size = size; receive_flags = flags;
        return recv_result;
    }
    int func_388F90(int socket, void *buffer, int size, int flags, void *address, int *length) {
        assert(socket == D_004E353C && size == 492 && flags == 0);
        assert(buffer == D_010890E0[D_004E3558] && *length == 16);
        event('U'); ++recvfrom_calls;
        if (recvfrom_calls > recvfrom_limit) longjmp(finish_thread, 1);
        socket_handle = socket; receive_buffer = buffer;
        receive_size = size; receive_flags = flags; connect_length = *length;
        std::memcpy(address, peer_words, 16); return recvfrom_result;
    }
    int func_003378D0(void *data) {
        assert(D_004E3558 == (int)(((unsigned long)data - (unsigned long)D_010890E0) / 492));
        assert(D_004E355C == count_before_receive);
        event('D'); ++dispatch_calls; assert(data == receive_buffer); return 0;
    }
    int func_388CC0(int socket, void *address, int length) {
        event('C'); ++connect_calls;
        assert(socket == D_004E3538 && length == 16);
        assert(address == D_010890C0);
        assert(D_010890C0[0] == 0x55 && D_010890C0[3] == 0x66);
        assert(D_010890C0[1] == peer_words[1]);
        assert(D_010890C0[2] == peer_words[2]);
        assert((unsigned)D_004E3550 == 0x01000080u);
        assert((unsigned)D_004E3554 == 0x08070605u);
        std::memcpy(connected_words, (int *)address + 1, sizeof(connected_words));
        return connect_result;
    }
    int func_118de0(const char *format, ...) {
        if (format == D_004D1F20) event('S');
        if (format == D_004D1F38) event('N');
        if (format == D_004D1F40) {
            event('L');
            va_list args; va_start(args, format);
            assert((unsigned)va_arg(args, int) == 0x01000080u);
            assert((unsigned)va_arg(args, int) == 0x08070605u);
            va_end(args);
            assert(D_004E352C == 1 && D_004E3558 == 0 && D_004E355C == 8);
        }
        return 0;
    }
}

int main() {
    D_004E352C = 1; D_004E353C = 7; D_004E3538 = 9;
    D_004E3558 = 3; D_004E355C = 4;
    if (setjmp(finish_thread) == 0) func_00337B30();
    assert(recv_calls == 2);
    assert(std::strcmp(events, "SRDR") == 0);
    assert(recvfrom_calls == 0);
    assert(dispatch_calls == 1);
    assert(socket_handle == 7);
    assert(receive_size == 492 && receive_flags == 0);
    assert(receive_buffer == (void *)D_010890E0[3]);
    assert(D_004E3558 == 4 && D_004E355C == 5);

    recv_calls = recvfrom_calls = dispatch_calls = connect_calls = 0;
    event_count = 0;
    connect_result = 0;
    peer_words[0] = 0x1234;
    peer_words[1] = (int)0x80000001u;
    peer_words[2] = 0x05060708;
    D_004E352C = 0;
    D_004E3540 = D_004E3544 = 0;
    D_004E3558 = 15;
    D_004E355C = 7;
    if (setjmp(finish_thread) == 0) func_00337B30();
    assert(recvfrom_calls == 1);
    assert(std::strcmp(events, "SUNCLRDR") == 0);
    assert(connect_calls == 1);
    assert(connected_words[0] == 0x80000001u);
    assert(connected_words[1] == 0x05060708u);
    assert(D_004E352C == 1);
    assert(D_004E3558 == 1 && D_004E355C == 9);

    recv_calls = recvfrom_calls = dispatch_calls = connect_calls = 0;
    event_count = 0;
    connect_result = -1;
    D_004E352C = 0;
    D_004E3550 = D_004E3554 = 99;
    D_004E3558 = 6;
    D_004E355C = 3;
    if (setjmp(finish_thread) == 0) func_00337B30();
    assert(recvfrom_calls == 2 && connect_calls == 1);
    assert(std::strcmp(events, "SUNCU") == 0);
    assert(dispatch_calls == 0 && D_004E352C == 0);
    assert(D_004E3550 == 0 && D_004E3554 == 0);
    assert(D_004E3558 == 6 && D_004E355C == 3);
    recv_calls = recvfrom_calls = dispatch_calls = connect_calls = 0;
    event_count = 0;
    D_004E352C = 0;
    D_004E3540 = peer_words[1]; D_004E3544 = peer_words[2];
    if (setjmp(finish_thread) == 0) func_00337B30();
    assert(connect_calls == 0);
    assert(std::strcmp(events, "SUU") == 0);
    // Complete receives: zero, one, and many; callback precedes counter updates.
    for (int count = 0; count <= 20; ++count) {
        recv_calls = recvfrom_calls = dispatch_calls = connect_calls = 0;
        event_count = 0;
        recv_limit = count;
        D_004E352C = 1; D_004E3558 = 15; D_004E355C = 3;
        if (setjmp(finish_thread) == 0) func_00337B30();
        assert(dispatch_calls == count && connect_calls == 0 && recvfrom_calls == 0);
        assert(D_004E3558 == ((15 + count) & 15) && D_004E355C == 3 + count);
    }
    // Incomplete and failed receives never dispatch or change ring state.
    int lengths[] = {-1, 0, 491, 493};
    for (int i = 0; i < 4; ++i) {
        for (int connected = 0; connected <= 1; ++connected) {
            recv_calls = recvfrom_calls = dispatch_calls = connect_calls = 0;
            event_count = 0;
            recv_limit = recvfrom_limit = 3;
            recv_result = recvfrom_result = lengths[i];
            D_004E352C = connected; D_004E3558 = 6; D_004E355C = 3;
            if (setjmp(finish_thread) == 0) func_00337B30();
            assert(dispatch_calls == 0 && connect_calls == 0);
            assert(D_004E3558 == 6 && D_004E355C == 3);
        }
    }
    // Matching the first word alone must still discover a distinct peer.
    recv_calls = recvfrom_calls = dispatch_calls = connect_calls = 0;
    event_count = 0;
    recvfrom_limit = 3; recvfrom_result = 492;
    D_004E352C = 0; D_004E3544 = 0;
    if (setjmp(finish_thread) == 0) func_00337B30();
    assert(connect_calls == 3 && dispatch_calls == 0);
    return 0;
}
