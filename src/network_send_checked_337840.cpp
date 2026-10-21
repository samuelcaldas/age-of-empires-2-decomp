#include "network_send_checked_337840.h"

extern int D_004E3560;
extern int D_004E3538;

extern "C" {
    int func_00104d60(int handle);
    int func_00104d40(int handle);
    int func_00388d60(int handle, const void *buf, int len, int flags);
    int func_00118de0(const char *format, ...);
}

int func_00337840(const void *payload, int size) {
    if (size > 492) {
        func_00118de0("err! il_sendto()\n");
        return -1;
    }
    func_00104d60(D_004E3560);
    int sent = func_00388d60(D_004E3538, payload, 492, 0);
    func_00104d40(D_004E3560);
    if (sent != 492) {
        func_00118de0("err! sceILsockSend()\n");
        return -2;
    }
    return sent;
}
