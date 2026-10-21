#include <cassert>
#include <cstring>
#include "network_send_data_3383b0.h"

static int send_result;
static const void *sent_buffer;
static int sent_size;
extern "C" int func_00337840(const void *buffer, int size) {
    sent_buffer = buffer;
    sent_size = size;
    return send_result;
}
extern "C" int func_118de0(const char *, ...) { return 0; }
extern "C" const char D_004D2110[] = "error\n";

int main() {
    unsigned char object[5000] = {};
    unsigned char payload[4] = {1, 2, 255, 4};
    int header = 7;
    send_result = 492;
    assert(func_003383B0(object, &header, 9, payload, 4) == 492);
    unsigned char *buffer = object + 3388;
    assert(sent_buffer == buffer && sent_size == 20);
    assert(*(int *)(buffer + 0) == 7 && *(int *)(buffer + 4) == 9);
    assert(*(int *)(buffer + 8) == 262 && *(int *)(buffer + 12) == 4);
    assert(std::memcmp(buffer + 16, payload, 4) == 0);
    send_result = -1;
    assert(func_003383B0(object, &header, 9, payload, 4) == -1);
    assert(func_003383B0(object, &header, 9, payload, 1009) == 0);
}
