#include <cassert>
#include <cstring>
#include "network_receiver_337B30.h"

int D_004E3564;
int D_004E3570;
int D_004E3574;
int D_004E3578;
int D_004E357C;
int D_004E3580;
static int event_log[16];
static int events;
static int recv_calls;
static int recvfrom_calls;
static int dispatch_calls;
static int connect_calls;
static int packet_count;
static int socket_handle;
static void *receive_buffer;
static int receive_size;
static int receive_flags;
static int result_value;
static int peer_a;
static int peer_b;
static int sockaddr_a;
static int sockaddr_b;

extern "C" {
    int func_388E60(int socket, void *buffer, int size, int flags) {
        ++recv_calls; socket_handle = socket; receive_buffer = buffer;
        receive_size = size; receive_flags = flags; return result_value;
    }
    int func_388F90(int socket, void *buffer, int size, int flags, void *address, int *length) {
        ++recvfrom_calls; socket_handle = socket; receive_buffer = buffer;
        receive_size = size; receive_flags = flags; assert(*length == 16);
        std::memcpy(&sockaddr_a, address, 4); std::memcpy(&sockaddr_b, (char *)address + 4, 4);
        *length = 8; return result_value;
    }
    int func_003378D0(void *data) { ++dispatch_calls; return data != 0; }
    int func_388CC0(int socket, void *address, int length) {
        ++connect_calls; assert(socket == D_004E3574); assert(length == 16);
        std::memcpy(&peer_a, address, 4); std::memcpy(&peer_b, (char *)address + 4, 4); return 0;
    }
    int func_118de0(const char *format, ...) { ++events; event_log[events - 1] = format[0]; return 0; }
}

int main() {
    func_00337B30(0);
    assert(recv_calls == 1 || recvfrom_calls == 1);
    return 0;
}
