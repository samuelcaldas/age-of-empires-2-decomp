#include "network_send_data_3383b0.h"

extern "C" {
int func_00337840(const void *payload, int size);
int func_118de0(const char *format, ...);
extern const char D_004D2110[];
}

int func_003383B0(void *object, const void *header, int header_size,
                  const void *payload, int size) {
    if (size + 16 > 1024) {
        return 0;
    }
    unsigned char *buffer = (unsigned char *)object + 3388;
    *(int *)(buffer + 0) = *(const int *)header;
    *(int *)(buffer + 4) = header_size;
    *(int *)(buffer + 8) = 0;
    *(int *)(buffer + 12) = size;
    const unsigned char *bytes = (const unsigned char *)payload;
    for (int index = 0; index < size; ++index) {
        *(int *)(buffer + 8) += bytes[index];
    }
    for (int index = 0; index < size; ++index) {
        buffer[16 + index] = bytes[index];
    }
    int result = func_00337840(buffer, size + 16);
    if (result < 0) {
        func_118de0(D_004D2110, result);
    }
    return result;
}
