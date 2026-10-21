#include "network_buffer_enqueue_338470.h"

extern int D_004E3560[2];

extern "C" {
    extern const char D_004D2128[];
    extern const char D_004D2130[];
    extern const char D_004D2150[];
    int func_104D60(int semaphore);
    int func_104D40(int semaphore);
    int func_117af8(void *destination, const void *source, int size);
    int func_118de0(const char *format, ...);
}

void *func_00338470(void *state, const void *payload, int size) {
    int *fields = static_cast<int *>(state);
    func_104D60(D_004E3560[1]);
    char *buffer = reinterpret_cast<char *>(state) + 1324;
    if (fields[843] <= 0) {
        fields[844] = 0;
        fields[846] = 0;
        fields[845] = 0;
        fields[843] = 0;
    }
    if (fields[845] + size >= 2048) {
        int *flags = reinterpret_cast<int *>(buffer + fields[846] + 12);
        *flags |= static_cast<int>(0x80000000u);
        if (fields[844] < size) {
            func_118de0(D_004D2128);
            func_118de0(D_004D2130, size);
            func_118de0(D_004D2150, fields[844], fields[845], fields[846]);
            func_104D40(D_004E3560[1]);
            return 0;
        }
        if (fields[845] == fields[844]) {
            fields[844] = 0;
        }
        fields[845] = 0;
    }
    buffer += fields[845];
    func_117af8(buffer, payload, size);
    ++fields[843];
    fields[846] = fields[845];
    size = (size + 3) & -4;
    fields[845] += size;
    func_104D40(D_004E3560[1]);
    return buffer;
}
