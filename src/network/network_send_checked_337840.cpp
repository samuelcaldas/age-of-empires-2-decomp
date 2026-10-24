#include "network_send_checked_337840.h"

extern int D_004E3560;
extern int D_004E3538;

extern "C" {
    extern const char D_004D1EB0[];
    extern const char D_004D1ED0[];
    int func_104D60(int semaphore);
    int func_104D40(int semaphore);
    int func_388D60(int socket, const void *buf, int len, int flags);
    int func_118de0(const char *format, ...);
}

int func_00337840(const void *payload, int size) {
    if (size > 492) {
        func_118de0(D_004D1EB0);
        return -1;
    }
    func_104D60(D_004E3560);
    int sent = func_388D60(D_004E3538, payload, 492, 0);
    func_104D40(D_004E3560);
    if (sent != 492) {
        func_118de0(D_004D1ED0);
        return -2;
    }
    return sent;
}
