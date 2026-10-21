#include "network_send_checked_337840.h"

extern int g_sync_handle;
extern int g_socket_handle;

extern "C" {
    int func_00104d60(int handle);
    int func_00104d40(int handle);
    int func_00388d60(int handle, const void *buf, int len, int flags);
    int func_00118de0(const char *format, ...);
}

int func_00337840(void *self, int size) {
    if (size >= 493) {
        func_00118de0("send size rejected");
        return -1;
    }
    func_00104d60(g_sync_handle);
    int sent = func_00388d60(g_socket_handle, self, 492, 0);
    func_00104d40(g_sync_handle);
    return sent;
}
