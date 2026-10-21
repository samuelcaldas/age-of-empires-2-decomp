#include <cassert>
#include <cstring>
#include <csetjmp>
#include "network_receiver_337B30.h"

int D_004E356C;
int D_004E3578;
int D_004E357C;
int D_004E3580;
int D_004E3584;
int D_004E3590;
int D_004E3594;
int D_004E3598;
int D_004E359C;
static jmp_buf finish_thread;
static int recv_calls, recvfrom_calls, dispatch_calls, connect_calls;
static int socket_handle, receive_size, receive_flags, connect_length;
static void *receive_buffer;
static int recvfrom_result = 492;
static int peer_words[2];

extern "C" {
    extern const char D_004D1F20[] = "receiver start";
    extern const char D_004D1F38[] = "new peer";
    extern const char D_004D1F40[] = "connected";
    int func_388E60(int socket, void *buffer, int size, int flags) {
        ++recv_calls;
        if (recv_calls > 1) longjmp(finish_thread, 1);
        socket_handle = socket; receive_buffer = buffer;
        receive_size = size; receive_flags = flags;
        return 492;
    }
    int func_388F90(int socket, void *buffer, int size, int flags, void *address, int *length) {
        ++recvfrom_calls; socket_handle = socket; receive_buffer = buffer;
        receive_size = size; receive_flags = flags; connect_length = *length;
        peer_words[0] = 0x01020304; peer_words[1] = 0x05060708;
        std::memcpy(address, peer_words, 8); return recvfrom_result;
    }
    int func_003378D0(void *data) { ++dispatch_calls; assert(data == receive_buffer); return 0; }
    int func_388CC0(int socket, void *address, int length) { (void)socket; (void)address; (void)length; return -1; }
    int func_118de0(const char *format, ...) { (void)format; return 0; }
}

int main() {
    D_004E356C = 1; D_004E357C = 7; D_004E3578 = 9;
    D_004E3598 = 3; D_004E359C = 4;
    if (setjmp(finish_thread) == 0) func_00337B30();
    assert(recv_calls == 2);
    assert(recvfrom_calls == 0);
    assert(dispatch_calls == 1);
    assert(socket_handle == 7);
    assert(receive_size == 492 && receive_flags == 0);
    assert(receive_buffer == (void *)(0x010890E0 + 3 * 492));
    assert(D_004E3598 == 4 && D_004E359C == 5);
    return 0;
}
